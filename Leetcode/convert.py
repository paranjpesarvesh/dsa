import requests
import json
import os
from threading import Thread
import queue

# ---------------- Configuration ----------------
PROBLEMS_FILE = "temp.json"
OUTPUT_DIR = "leetcode"
MODEL = "ollama:latest"
NUM_WORKERS = 6
BATCH_SIZE = 2
FENCE = "```"

# List of Ollama instances running on different ports
OLLAMA_PORTS = [11434, 11435, 11436]

# Separator to split problems safely
SEPARATOR = "---PROBLEM-END---"

# Prompt template for each problem
BATCH_PROMPT_TEMPLATE = """
You are a DSA tutor. For each of the following LeetCode problems, generate a markdown file with these sections:
# Problem {problem_number}: {title}
## Description
Recreate the problem statement faithfully.
## Explanation
Explain the problem in detail and elaboratively, including inputs, outputs, constraints, and edge cases.
## Approaches
List multiple solution approaches with pros and cons elaboratively.
## Solutions
### Python
{fence}python
# Python solution here
{fence}
### C++
{fence}cpp
// C++ solution here
{fence}
## Analysis
- Time complexity
- Space complexity
- Edge cases handled
## Metadata
- Difficulty: guess based on problem
- Topics: common tags
- Companies: common companies
{separator}
"""

# ---------------- Helper Functions ----------------

def load_problems():
    with open(PROBLEMS_FILE) as f:
        return json.load(f)

def call_ollama_stream(prompt, worker_id):
    """Call Ollama API on a specific port using streaming."""
    port = OLLAMA_PORTS[worker_id % len(OLLAMA_PORTS)]
    url = f"http://127.0.0.1:{port}/api/generate"

    resp = requests.post(url, json={"model": MODEL, "prompt": prompt, "stream": True}, stream=True)
    text_chunks = []
    for line in resp.iter_lines():
        if not line:
            continue
        data = json.loads(line)
        if "response" in data:
            text_chunks.append(data["response"])
        if data.get("done"):
            break
    return "".join(text_chunks)

def generate_batch_markdown(batch, worker_id):
    batch_to_generate = [p for p in batch if not os.path.exists(os.path.join(OUTPUT_DIR, f"question_{p['id']}.md"))]
    if not batch_to_generate:
        print(f"Skipping batch, all files exist")
        return

    # Build the batch prompt with separators
    batch_prompt = ""
    for p in batch_to_generate:
        batch_prompt += BATCH_PROMPT_TEMPLATE.format(
            problem_number=p["id"],
            title=p["title"],
            fence=FENCE,
            separator=SEPARATOR
        )

    try:
        output = call_ollama_stream(batch_prompt, worker_id)
        problem_outputs = [o.strip() for o in output.split(SEPARATOR) if o.strip()]

        for i, p in enumerate(batch_to_generate):
            if i < len(problem_outputs):
                os.makedirs(OUTPUT_DIR, exist_ok=True)
                out_path = os.path.join(OUTPUT_DIR, f"question_{p['id']}.md")
                with open(out_path, "w") as f:
                    f.write(problem_outputs[i])
                print(f"Generated {out_path}")
            else:
                print(f"Missing output for problem {p['id']}")
    except Exception as e:
        print(f"Error generating batch starting with problem {batch[0]['id']}: {e}")

# ---------------- Worker ----------------
def worker(q: queue.Queue, worker_id: int):
    while True:
        batch = q.get()
        if batch is None:
            break
        generate_batch_markdown(batch, worker_id)
        q.task_done()

# ---------------- Main ----------------
def main():
    problems = load_problems()
    print(f"Loaded {len(problems)} problems")

    problem_queue = queue.Queue()
    for i in range(0, len(problems), BATCH_SIZE):
        batch = problems[i:i+BATCH_SIZE]
        problem_queue.put(batch)

    threads = []
    for worker_id in range(NUM_WORKERS):
        t = Thread(target=worker, args=(problem_queue, worker_id))
        t.start()
        threads.append(t)

    problem_queue.join()
    for _ in threads:
        problem_queue.put(None)
    for t in threads:
        t.join()

    print("All problems processed.")

if __name__ == "__main__":
    main()

