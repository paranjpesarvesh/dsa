# **Bellman–Ford Algorithm – Single Source Shortest Path (with Negative Weights)**

---

## **1. What Is Bellman–Ford?**

Bellman–Ford computes the **shortest distance from a single source** to all nodes in a graph that may contain **negative edge weights**.

Unlike Dijkstra:

* Works with **negative edges**
* Detects **negative weight cycles**
* Simpler but slower (O(V × E))

---

## **2. Core Intuition**

The longest possible shortest path (without cycles) can use **at most (V–1) edges**.

Therefore, we relax all edges exactly **V–1 times**.

Relax operation:

If dist[u] + w < dist[v]:
→ Update dist[v]

After V–1 iterations, distances are optimal **if no negative cycle exists**.

---

## **3. Detecting Negative Cycles**

After the relaxation loop:

For each edge (u, v, w):
If dist[u] + w < dist[v]:
→ Negative cycle exists (reachable from the source)

This is a major advantage over Dijkstra.

---

## **4. Visual Intuition (ASCII Graph)**

Graph:

A → B (5)
A → C (2)
C → B (-4)

Shortest path A → C → B has weight 2 + (-4) = -2.

Bellman–Ford detects this because it revisits edges multiple times.

---

## **5. Step-by-Step Algorithm**

1. Initialize dist[] = INF

2. dist[src] = 0

3. Repeat (V–1) times:

   * For every edge (u, v, w):

     * Relax:
       if dist[u] + w < dist[v]: update

4. Run one more pass over edges:

   * If any distance still decreases → negative cycle detected

---

## **6. Pseudocode (No Code Block)**

dist[] = INF
dist[src] = 0

for i = 1 to V-1:
for each edge (u, v, w):
if dist[u] + w < dist[v]:
dist[v] = dist[u] + w

for each edge (u, v, w):
if dist[u] + w < dist[v]:
negative cycle exists

return dist

---

## **7. Complexity**

| Metric | Value        |
| ------ | ------------ |
| Time   | **O(V × E)** |
| Space  | O(V)         |

Slower than Dijkstra/Floyd, but necessary for negative weights.

---

## **8. When to Use Bellman–Ford?**

* Graph contains **negative edge weights**
* Need to **detect negative cycles**
* Graph is sparse
* Weighted DAG? → Use DP instead (faster)
* All pairs shortest path? → Use Floyd–Warshall

---

## **9. Variations**

* SPFA (queue optimized version)
* Multi-source → add super-source with edges of weight 0
* Reachability with negative cycle marking
* Path reconstruction via parent[] array

---

## **10. Edge Cases**

* Unreachable nodes → remain INF
* Negative cycles → distances undefined (keep flag)
* Graph with self-loops → handle normally
* Overflow risk → use long long

---

## **11. Interview Tips**

Interviewers expect you to know:

* Why relax edges V–1 times?
* How negative cycle detection works
* When to use Dijkstra vs Bellman–Ford
* How SPFA improves performance

FAANG sometimes asks:

* Find shortest path with negative edges
* Detect whether graph has negative cycle
* Apply Bellman–Ford on weighted DAG

---

## **12. Practice Problems**

**LeetCode:**

* 787 — Cheapest Flights Within K Stops (conceptually similar relaxation)
* 743 — Network Delay Time (can use Dijkstra/BF)
* 399 — Evaluate Division (graph DP variant)

**GFG:**

* Bellman–Ford Algorithm
* Detect Negative Cycle

**Codeforces:**

* 20C — variations using BF
* 510E — distinct relaxation tasks

---
