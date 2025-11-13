# **Dijkstra’s Algorithm – Single Source Shortest Path (SSSP)**

---

## **1. What Is Dijkstra’s Algorithm?**

Dijkstra’s algorithm finds the **shortest distance** from a **single source node** to all other nodes in a **non-negative weighted graph**.

Works for:

* Directed / Undirected graphs
* Weighted graphs (weights ≥ 0)

Does NOT work with **negative edge weights**.

---

## **2. Core Intuition**

Dijkstra’s is a **greedy algorithm**:

1. Always pick the unvisited node with the **minimum known distance**
2. “Relax” all its outgoing edges
3. Repeat until all nodes are processed

Priority queue ensures efficiency.

---

## **3. Why Does It Work?**

Because all edge weights are non-negative:

* The first time we settle (visit permanently) a node,
  we are guaranteed that its shortest distance is finalized.

---

## **4. Visual Intuition (ASCII Graph)**

Graph:

A --1-- B --2-- C
|       |
4       3
|       |
D --5-- E

Start at A:

Distances update in waves outward from A, guided by weights.

---

## **5. Algorithm – Step-by-Step**

1. Initialize dist[] = INF
2. dist[source] = 0
3. Push (0, source) into min-heap
4. While heap not empty:

   * Pop node u with smallest dist
   * If popped distance > current dist[u], ignore
   * For each neighbor v:

     * If dist[u] + weight < dist[v]:

       * Update dist[v]
       * Push new value in heap
5. Return dist[]

---

## **6. Pseudocode (No Code Block)**

dist[] = INF
dist[src] = 0
pq.push( (0, src) )

while pq not empty:
(d, u) = pop smallest d
if d != dist[u]: continue

```
for each (v, w) in adj[u]:
    if dist[u] + w < dist[v]:
        dist[v] = dist[u] + w
        pq.push( (dist[v], v) )
```

return dist

---

## **7. Time Complexity**

| Graph Representation | Complexity     |
| -------------------- | -------------- |
| Adj list + Min-heap  | **O(E log V)** |
| Adj matrix           | **O(V²)**      |

Space: O(V)

---

## **8. Limitations**

* Cannot handle negative weights
* Cannot detect negative cycles
* For large sparse graphs, min-heap version preferred
* For dense graphs, matrix version okay

---

## **9. Variations**

* **0–1 BFS** for edges with weight 0 or 1
* **Dial’s Algorithm** for small integer weights
* **Multi-source Dijkstra**
* **Dijkstra on grids** (common in pathfinding)

---

## **10. Edge Cases**

* Disconnected graph → dist[] remains INF for unreachable nodes
* Parallel edges → pick smaller weight
* Large weights → use long long

---

## **11. Interview Tips**

FAANG tends to ask:

* What if weights were negative? (→ Bellman-Ford)
* Difference between BFS and Dijkstra
* Why recheck (d != dist[u]) after popping?
* Apply Dijkstra on grid with obstacles
* Use parent[] to reconstruct path

Be ready to:

* Trace the algorithm step-by-step
* Compare with A* and Bellman-Ford
* Show how priority queue improves performance

---

## **12. Practice Problems**

**LeetCode:**

* 743 — Network Delay Time
* 1514 — Path with Maximum Probability
* 1631 — Minimum Effort Path

**GFG:**

* Dijkstra’s Algorithm
* Shortest path in weighted graphs

**Codeforces:**

* 20C — Dijkstra?
* 25E — Word Transformation (graph with weights)

---
