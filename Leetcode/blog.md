# V1

## Scaling Markdown Generation for LeetCode Problems with Ollama

### Introduction

In a recent project, we faced the challenge of **automatically generating detailed Markdown files** for thousands of LeetCode problems using a local Ollama model. Each Markdown file needed to contain the problem statement, explanations, multiple solution approaches, Python and C++ code solutions, complexity analysis, and metadata like difficulty, topics, and companies.

The challenge wasn’t just generating the content but doing it **efficiently at scale** while handling model constraints and maximizing throughput.

---

### The Problem

1. **Huge dataset**: \~3000 LeetCode problems.
2. **Model limitations**: Ollama has a **fixed context length**, so sending too many problems in one request could exceed the limit.
3. **Performance**: One API call per problem would be **too slow** for thousands of problems.
4. **Concurrency**: We needed a solution that could **parallelize generation** without overwhelming the model.

---

### Initial Approach

We started with a **single-threaded script** that:

* Iterated through the problem list.
* Sent a prompt to Ollama for each problem.
* Saved the response into `.md` files.

**Problems encountered:**

* Extremely slow for 3000 problems.
* Model context limitations made batching multiple problems tricky.
* Handling streaming responses required careful concatenation and splitting.

---

### Scaling with Worker Pools and Queues

To solve the performance bottleneck, we implemented a **threaded worker pool** using Python’s `queue` and `threading` modules:

1. **Problem Queue**: A queue stores batches of problems.
2. **Worker Threads**: Multiple threads pull batches from the queue and send prompts to Ollama.
3. **Batching**: We grouped **2 problems per batch** to stay within the model’s context limit.
4. **Streaming-safe handling**: The API streams responses in multiple JSON chunks, so we concatenated all chunks and split them using a unique separator.

**Benefits:**

* Parallel processing increased throughput dramatically.
* Batching reduced overhead without exceeding context limits.
* Skipping already-generated files made the process **resumable**.

---

### Dockerized Ollama Instances for Port Parallelization

We realized that using a **single Ollama server** on one port could become a bottleneck. To scale further:

1. **Dockerized Ollama**: Each container runs an independent Ollama instance.
2. **Port forwarding**: Each container exposes the internal port (`11434`) to a unique host port (`11434`, `11435`, `11436`).
3. **Worker distribution**: Workers are assigned to ports in a **round-robin fashion**, so no single server is overloaded.

**Benefits:**

* True parallelism across multiple model instances.
* High throughput without context clashes or port conflicts.
* Scalable approach: we can add more containers as needed.

---

### Key Learnings

1. **Worker pools + queues** are essential for handling large datasets efficiently.
2. **Batching** balances context length constraints with API efficiency.
3. **Streaming responses** must be concatenated and parsed carefully to avoid data loss.
4. **Docker containers** enable running multiple instances of a service that is normally bound to a single port, allowing port forwarding and parallelism.
5. Combining these techniques allows generating **thousands of Markdown files reliably and quickly**.

---

### Conclusion

This project illustrates a **beautiful scaling problem**: generating large volumes of structured output from an LLM locally. It touches on **worker pools, queues, batching, streaming APIs, and Docker-based port management**, making it a great example of combining **software engineering principles** with **ML deployment challenges**.

By carefully designing the workflow, we achieved:

* Efficient **parallel generation** of thousands of problem files.
* Safe handling of model **context limits**.
* Scalable architecture using **Dockerized Ollama instances**.

This approach can be generalized for other **large-scale content generation tasks** with local LLMs.

---

# Pull the Ollama image (example, replace with actual image if needed)
docker pull ollama/ollama:latest

# Run multiple containers on different ports
docker run -d --name ollama1 -p 11434:11434 ollama/ollama:latest serve llama3:latest
docker run -d --name ollama2 -p 11435:11434 ollama/ollama:latest serve llama3:latest
docker run -d --name ollama3 -p 11436:11434 ollama/ollama:latest serve llama3:latest


docker run -v ./models:/models -p 8000:8000 ghcr.io/ggml-org/llama.cpp:server -m /models/mistral-7b-instruct/mistral-7b-instruct-v0.2.Q4_K_M.gguf --port 8000 --host 0.0.0
.0 -n 512

---

# V2

Let’s define the symbols:

| Parameter                                    | Symbol | Value / Assumption                           |
| -------------------------------------------- | ------ | -------------------------------------------- |
| Total problems                               | $P$    | 3,600                                        |
| Avg time per problem (detailed DSA solution) | $T_p$  | 7 min                                        |
| Batch size per API call                      | $B$    | 2 problems                                   |
| Total instances/containers                   | $I$    | 3                                            |
| Max threads per instance                     | $C$    | 2 threads (1 problem per instance at a time) |

---

## **2️⃣ Serial execution (baseline)**

If we process problems **one by one, single-threaded, single instance**:

$$
T_\text{serial} = P \times T_p = 3600 \times 7 \, \text{min} = 25,200 \, \text{min} \approx 420 \, \text{hours} \approx 17.5 \, \text{days}
$$

> 😱 This is unacceptably long.

---

## **3️⃣ With batch processing (still single instance)**

* Batch size $B = 2$ → 2 problems per API call
* Time per batch = $T_b = B \times T_p = 2 \times 7 = 14 \, \text{min}$
* Total batches = $P / B = 3600 / 2 = 1,800$
* **Serial total time remains the same**: 1,800 × 14 min = 25,200 min (no speedup yet, just reduced calls)

---

## **4️⃣ Parallel execution with multiple instances**

We have **I = 3 instances**, each can handle **1 batch at a time**.

* **Parallel batches per round** = I = 3
* **Time per round** = time for 1 batch = 14 min (all 3 run simultaneously)
* **Total rounds** = total batches ÷ instances = 1,800 ÷ 3 = 600 rounds

$$
T_\text{parallel} = \text{rounds} \times T_b = 600 \times 14 = 8,400 \, \text{min} \approx 140 \, \text{hours} \approx 5.8 \, \text{days}
$$

> ✅ Parallelism reduces total time from **17.5 days → 5.8 days**

---

## **5️⃣ If we further increase instances**

Assume **4 instances**:

* Parallel batches = 4
* Total rounds = 1,800 ÷ 4 = 450
* Time per round = 14 min

$$
T_\text{parallel,4} = 450 \times 14 = 6,300 \, \text{min} \approx 105 \, \text{hours} \approx 4.4 \, \text{days}
$$

> More instances → less total time. CPU/RAM constraints limit how many we can safely run.

---

## **6️⃣ Considering smaller batches**

If batch size is **1** (1 problem per API call), with 3 instances:

* Time per batch = 7 min
* Total batches = 3,600
* Parallel batches = 3

$$
\text{rounds} = 3600 / 3 = 1,200
$$

$$
T_\text{parallel} = 1,200 \times 7 = 8,400 \, \text{min} \quad \text{(same as before)}
$$

> Batch size only affects **API calls**, not total compute time per problem in this simplified estimate.

---

## **7️⃣ Time saved**

* Serial: 25,200 min ≈ 17.5 days
* Parallel 3 instances: 8,400 min ≈ 5.8 days

$$
\text{Speedup factor} = \frac{T_\text{serial}}{T_\text{parallel}} = \frac{25,200}{8,400} = 3
$$

* Using 3 instances, we **saved 11.7 days** of compute time.

* Using 4 instances → speedup ≈ 4 → saved 13 days.

---

## **8️⃣ Observations**

1. **Linear speedup**: Adding instances roughly reduces time linearly until CPU/threads/RAM bottleneck.
2. **Batch size**: Must be balanced — too large → context overflow, too small → API overhead.
3. **Optimal instance count**: 3–4 for your i5-8265U (8 threads, 4 cores) without overclocking.
4. **Queueing + worker pool** ensures **even load distribution**.

---

✅ **Conclusion:**

By using **3 parallel containers**, **batch size 2**, and a **threaded worker pool**, you reduced the total processing time for 3,600 DSA problems from **17.5 days → 5.8 days**, saving roughly **two-thirds of the time**, without overloading your CPU.

---

## **1️⃣ Optimize batching intelligently**

* **Dynamic batch sizing**: Instead of a fixed batch of 2, profile the model with batch sizes of 2–5 problems. Sometimes, **larger batches amortize API overhead** and **streaming** efficiently fills the model context.
* **Adaptive batching**: If the model starts timing out due to context length, automatically reduce batch size.

---

## **2️⃣ Maximize parallelism within a container**

* You currently have **1 thread per batch per container**. Since you have **8 logical cores**:

  * Run **2–3 batches in parallel per container** using multithreading, making sure CPU usage is \~70–80% to avoid throttling.
  * This effectively multiplies throughput **without spinning up extra containers**.

---

## **3️⃣ Use streaming outputs**

* Instead of waiting for a full markdown, **stream partial results per problem**.
* This reduces **memory footprint** and **allows pipelining**:

  * Thread 1 generates description while Thread 2 generates solutions for the previous problem.

---

## **4️⃣ Offload heavy tasks asynchronously**

* **Split work**: Not all sections take equal time:

  * Description & explanation ≈ slow
  * Code implementation ≈ medium
  * Metadata ≈ fast

* Consider generating **descriptions/explanations** in one batch, then **solutions** in another, possibly on separate threads or containers. This allows **better CPU utilization**.

---

## **5️⃣ Efficient caching**

* Cache **common explanations, code patterns, and analysis templates**. Many LeetCode problems share patterns (sliding window, DP, DFS/BFS).
* If the model sees similar problems, **reuse partial outputs**, reducing generation time.

---

## **6️⃣ Reduce I/O overhead**

* **Local streaming API** instead of HTTP for intra-container communication:

  * For example, instead of calling `curl` for every batch, **run the model inside the Python process** using subprocess/FFI.
  * Avoids network latency entirely.

---

## **7️⃣ Hardware acceleration (if available)**

* CPU is the bottleneck. Consider:

  * Using **AVX2/FMA-optimized GGML models** (already supported).
  * If you can access a GPU, even a small one, it can reduce generation times **5–10x** for large batches.
  * Otherwise, ensure **n\_threads = total logical cores**, and **num\_parallel\_layers optimized** for CPU.

---

## **8️⃣ Prioritize work dynamically**

* **Problem difficulty-aware scheduling**:

  * Start with harder problems first (which take longer), so you avoid **stragglers delaying the final batch**.
  * Easy problems can be processed in larger batches later.

---

## **9️⃣ Monitor and auto-tune**

* Track **average tokens/sec per batch per instance**.
* Dynamically adjust:

  * Number of threads per container
  * Batch size
  * Which problems are batched together

This is basically **dynamic load balancing**.

---

## **Estimated gain**

* With these optimizations (multithreaded containers, adaptive batching, streaming, caching):

  * **Current time**: 5.8 days (3 containers, 1 batch per container, B=2)
  * **Optimized**: 2–3 days is realistic **without extra hardware**, depending on how effective streaming & caching are.

---

💡 **Senior-level insight:**

* Don’t just throw more containers at the problem. Instead, **optimize throughput per container**, **reduce latency and I/O**, and **leverage the model context intelligently**.
* Think **pipelines, batching, caching, and streaming** — essentially a **mini SRE-level high-throughput job scheduling system for LLM generation**.

---

# V3

---

## **DSA Problem Auto-Generation: Multi-Stage LLM Pipeline**

### **1️⃣ Overview**

We aim to generate detailed Markdown files for thousands of LeetCode problems, including:

* Problem description
* Detailed explanation
* Multiple approaches
* Python & C++ solutions
* Complexity analysis & metadata

Instead of a single large prompt (which hits context limits and is slow), we split the work into **stages** with caching and worker pools.

---

### **2️⃣ Architecture**

```text
          +--------------------+
          |   Problems List    |
          |  (JSON: id/title)  |
          +---------+----------+
                    |
                    v
           +-----------------+
           | Stage 1:        |
           | Description Gen |
           +-----------------+
                    |
       +------------+------------+
       | Cache descriptions here |
       v
   +--------------------------+
   | Stage 2: Topic/Tag Gen   |
   | Input: problem id, title,|
   | description              |
   +--------------------------+
       +------------+------------+
       | Cache topics/tags here |
       v
   +--------------------------+
   | Stage 3: Approaches Gen  |
   | Input: problem id, title,|
   | description, topics      |
   +--------------------------+
       +------------+------------+
       | Cache approaches here   |
       v
   +--------------------------+
   | Stage 4: Solution & Code |
   | Input: problem id, title,|
   | description, topics,     |
   | approaches               |
   +--------------------------+
       |
       v
   +--------------------------+
   | Output: question_x.md    |
   | Complete Markdown file   |
   +--------------------------+
```

---

### **3️⃣ Execution Flow**

1. **Queue-based Worker Pool**:

   * Divide problems into batches (e.g., 2–10 per batch).
   * Workers pick batches and process in parallel.
   * Each worker calls the model API or local container instance.

2. **Stage-wise Processing**:

   * Each stage is independent, smaller prompts → faster + less chance of hallucination.
   * Cache results at each stage → can resume or recompute selectively.

3. **Container Scaling**:

   * Multiple LLM containers (e.g., 3–4) on different ports.
   * Each worker picks a container round-robin → maximizes CPU utilization without overloading.

4. **Caching**:

   * Stage 1: Save generated descriptions.
   * Stage 2: Save topics/tags.
   * Stage 3: Save approaches.
   * Stage 4: Save final Markdown file.

---

### **4️⃣ Benefits**

| Aspect         | Traditional Single-Prompt                  | Multi-Stage Pipeline                          |
| -------------- | ------------------------------------------ | --------------------------------------------- |
| Context Limits | Risk of hitting max context                | Each stage fits in context easily             |
| Parallelism    | Hard to scale                              | Worker + container pools                      |
| Debugging      | Hard to fix mistakes                       | Stage-specific caches simplify debugging      |
| Quality        | Lower (hallucinations + inconsistent code) | Higher consistency, better code + explanation |
| Time           | Slow & retries expensive                   | Faster with batching & caching                |

---

### **5️⃣ Ideal Batch & Worker Sizing**

* **Batch size:** 2–10 problems per API call → balances speed & context length.
* **Workers:** Number of CPU threads / cores. For i5-8265U (8 threads, 4 cores):

  * **4–6 workers** is safe, leaves headroom for OS + I/O.
* **Containers:** 3–4 containers, one per worker or shared in round-robin.

---

### **6️⃣ Implementation Notes**

* Use **separators** (like `---PROBLEM-END---`) between problems when batching.
* Stream API output for **partial results** to reduce idle time.
* Always **cache intermediate stages**:

  * Can resume interrupted pipelines without recomputing.
  * Reduces wasted computation.

---

# Checkpoint

---

# Project Checkpoint: Efficient Generation of LeetCode Markdown Files

## **1. Project Overview**

**Goal:**
Generate `question_<id>.md` files for \~3600 LeetCode problems, containing:

* Problem description
* Explanation with constraints, edge cases
* Multiple approaches with pros & cons
* Python and C++ implementations
* Analysis: time & space complexity
* Metadata: difficulty, topics, companies

**Constraints:**

* Local machine: Intel i5-8265U, 8 threads (4 cores, 2 threads per core)
* Maximize CPU utilization without overclocking
* Memory: 16–32 GB RAM, CPU inference only (no GPU)
* Context window & API limits for LLM
* Model: Local containerized GGUF/LLM instances (like Mistral-7B, llama.cpp, or Ollama-based)

---

## **2. Initial Approach**

* **Linear, single-threaded generation:**

  * For each problem: pass full details to LLM, get Markdown.
  * Result: very slow (\~30–60 seconds per problem depending on content length).

* **Problems encountered:**

  * Streaming output handling
  * Context length exceeded when batching
  * Re-generating same content wastes compute
  * Limited API/container instances → CPU bottleneck

---

## **3. Optimizations Tried**

### **3.1. Worker Pool + Queue**

* Divided problems into **batches** (BATCH\_SIZE=2–10)
* Spawned **NUM\_WORKERS=6 threads** to process batches in parallel
* Each worker picks a batch from a queue, calls LLM container or API

**Benefits:**

* Parallelism increased throughput \~4–5×
* Skipped already generated files to save time

**Code reference:** `convert.py` with worker, queue, and batch prompt

---

### **3.2. Multi-Instance Containers**

* Attempted multiple Ollama instances on different ports (11434, 11435, 11436)
* Enabled round-robin usage across workers
* Problem: Ollama pull/network issues → switched to **direct container models using llama.cpp / Mistral GGUF**
* Achieved isolated inference containers → true parallelism

---

### **3.3. Stage-wise Generation**

**Pipeline idea:** (Inspired by RAG / progressive generation)

1. Stage 1: Generate **Description** using problem number + title
2. Stage 2: Generate **Topics / Tags** using cached description
3. Stage 3: Generate **Approaches** using description + topics
4. Stage 4: Generate **Solution** (Python + C++) using all previous data

**Benefits:**

* Each prompt smaller → fits context window
* Easier to debug and cache at each stage
* Reduced hallucination and inconsistent solutions

**Separator:** `---PROBLEM-END---` between problems to split batch outputs safely

---

### **3.4. Caching**

* Saved output for **each stage** in local files:

  * `cache/descriptions/<problem_id>.txt`
  * `cache/topics/<problem_id>.json`
  * `cache/approaches/<problem_id>.json`
  * Final Markdown: `leetcode/question_<problem_id>.md`
* Allows **resuming from any stage** without recomputation

---

### **3.5. Container-based Inference**

* Used **ggml / llama.cpp / GGUF models** locally
* Command template:

```bash
docker run -it -v /path/to/models:/models ghcr.io/ggml-org/llama.cpp:full --all-in-one "/models/" 7B
```

* API endpoint exposed (e.g., `0.0.0.0:8000`)
* Tested `/completion` endpoint using `curl` for local inference
* Multiple containers possible for parallel processing (port per container)

---

## **4. Performance Analysis**

**Assumptions:**

* Single problem generation: \~30–45 seconds per problem (full Markdown)
* 3600 problems → \~36–45 hours single-threaded
* Multi-threaded + 3 containers → \~8–10 hours (rough estimate)
* Stage-wise + caching reduces unnecessary recomputation → additional 20–30% time savings

**CPU Consideration:**

* i5-8265U, 8 threads → 4–6 inference threads safe without overclocking
* Each container can handle 1–2 threads for CPU inference efficiently

**Batching Considerations:**

* Ideal batch size: 2–10 problems
* Too large → context limit exceeded
* Too small → higher overhead per API call

---

## **5. Checkpoint for Continuation**

**Current state:**

1. `convert.py` implemented with:

   * Worker pool + queue
   * Batch processing with separators
   * Stage-wise prompt template (description → topics → approaches → solution)
2. Local GGUF container model running at `http://127.0.0.1:8000/completion`
3. Intermediate caching setup per stage
4. Docker containers tested for multiple instances (for true parallelism)

**Next steps:**

* Implement **stage-wise generation** in `convert.py` fully (currently linear batches)
* Launch **3–4 container instances** and assign workers round-robin
* Automate **checkpointing at each stage**
* Experiment with **larger batches** safely to maximize throughput
* Measure actual throughput and CPU usage to tune batch size / number of workers

---

### **6. LLM-understandable Summary**

> **Context for the LLM:**
>
> * Input: `problem_id`, `title` (LeetCode)
> * Output stages: `description`, `topics`, `approaches`, `solutions`, `markdown`
> * Constraints: CPU-bound, local containers, cache each stage, batch processing
> * Goal: Efficient generation for 3600 problems with minimal total runtime, stage caching, and multi-container parallelism

---
