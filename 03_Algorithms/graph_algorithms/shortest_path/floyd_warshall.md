# **Floyd–Warshall Algorithm – All-Pairs Shortest Path (APSP)**

---

## **1. What Is Floyd–Warshall?**

The **Floyd–Warshall algorithm** computes the **shortest distances between every pair of vertices** in a weighted graph.

Works for:

* Directed / Undirected graphs
* Positive and **negative** edge weights (but **no negative cycles**)

Result: distance matrix dist[i][j] gives shortest path from i → j.

---

## **2. Core Intuition**

Dynamic Programming over **intermediate nodes**.

For any pair (i, j), the shortest path may or may not pass through a node k.

Transition:

dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

We try all nodes k as intermediates → ensures all possible route combinations are tested.

---

## **3. How It Works**

Three nested loops:

for k in vertices:
for i in vertices:
for j in vertices:
dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

Order of loops ensures DP captures all paths using only first k nodes as intermediates.

---

## **4. Visual Intuition (Matrix)**

Initial adjacency matrix:

```
  A   B   C
```

A   [ 0   5  INF ]
B   [INF  0   2  ]
C   [ 3  INF  0  ]

After k = A, B, C, distances shrink progressively as new shorter indirect paths appear.

---

## **5. Step-by-Step Description**

1. Initialize dist with adjacency matrix
2. Set dist[i][i] = 0
3. For each node k:

   * Try using k as intermediate
   * Relax every dist[i][j]
4. After all k processed → result matrix ready
5. Detect negative cycle:

   * If dist[i][i] < 0 for any i → negative cycle exists

---

## **6. Pseudocode (No Code Block)**

for i in 1..n:
for j in 1..n:
if i == j: dist[i][j] = 0
else if edge(i,j): dist[i][j] = weight(i,j)
else: dist[i][j] = INF

for k in 1..n:
for i in 1..n:
for j in 1..n:
if dist[i][k] + dist[k][j] < dist[i][j]:
dist[i][j] = dist[i][k] + dist[k][j]

if any dist[i][i] < 0:
negative cycle detected

---

## **7. Time & Space Complexity**

| Metric | Complexity |
| ------ | ---------- |
| Time   | **O(n³)**  |
| Space  | **O(n²)**  |

Good for small/medium graphs (n ≤ 400).

---

## **8. When to Use Floyd–Warshall?**

* Need shortest path between **all** pairs
* Graph has negative edges (but no negative cycles)
* Preprocessing for:

  * Routing
  * Dynamic queries
  * Graph closure problems

---

## **9. Variations**

* Path reconstruction with parent matrix
* Detecting negative cycles
* Transitive closure (replace min with OR)
* APSP in dense graphs

---

## **10. Edge Cases**

* Unreachable paths → remain INF
* Negative edges allowed
* Negative cycles break correctness
* Very large n → O(n³) too slow

---

## **11. Interview Tips**

Interviewers expect you to know:

* Why 3 nested loops?
* Order of loops (k outermost)
* Works with negative edges
* Compare with Dijkstra / Bellman-Ford
* Negative cycle check using dist[i][i]
* Matrix initialization pitfalls

Common question:
“When is Floyd–Warshall preferred over repeated Dijkstra?”
→ When graph is dense OR when many shortest-path queries are needed.

---

## **12. Practice Problems**

**LeetCode:**

* 1334 — Find the City With the Smallest Neighbors
* 1462 — Course Schedule IV (reachability via Floyd–Warshall)

**GFG:**

* Floyd–Warshall Algorithm
* Detect Negative Cycles

**Codeforces:**

* 295B — Greg and Graph
* 70E — subsequent shortest-path transforms

---
