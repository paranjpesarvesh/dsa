# **Kruskal’s Algorithm – Minimum Spanning Tree (MST)**
---

## **1. What Is an MST?**

Given a **connected, undirected, weighted graph**, a **Minimum Spanning Tree (MST)** is:

* A subset of edges
* Connecting all vertices
* With **no cycles**
* And **minimum total weight**

---

## **2. Why Kruskal’s Algorithm?**

Kruskal’s algorithm is a **greedy algorithm** ideal when:

* Graph is sparse (few edges)
* We want easy cycle detection
* We require a clean, modular solution based on DSU

Core idea:
**Pick the smallest possible edge that doesn’t form a cycle.**

---

## **3. Intuition (Greedy Choice)**

Sort edges from lightest → heaviest.

Process edges one-by-one.
If adding an edge does **not** create a cycle → accept.
Else → skip.

Cycle detection is done using **Union-Find (DSU)**.

---

## **4. High-Level Steps**

1. Sort all edges by weight
2. Initialize DSU with all nodes separate
3. For each edge (u, v, w) in sorted order:

   * If find(u) != find(v):

     * Add edge to MST
     * union(u, v)
4. Stop after selecting **N – 1 edges**

---

## **5. Visual Example (ASCII)**

Graph:

(1)
A ------ B
| \      \
|  \5     \2
|   \      \
4    C ----- D
\3

Edges sorted:
(A,C,1)
(B,D,2)
(C,D,3)
(A,D,5)
(A,C,4)

MST picks:
A–C (1)
B–D (2)
C–D (3)

Total weight = **6**

---

## **6. Pseudocode (No Code Block)**

sort edges by weight
mst = empty list

for each edge (u, v, w):
if find(u) != find(v):
add (u, v, w) to mst
union(u, v)

return mst

---

## **7. Time & Space Complexity**

| Step           | Complexity     |
| -------------- | -------------- |
| Sorting edges  | O(E log E)     |
| DSU operations | O(E α(N))      |
| **Total**      | **O(E log E)** |
| Space          | O(V)           |

Sorting dominates.

---

## **8. Edge Cases**

* Graph must be connected → otherwise MST becomes Minimum Spanning Forest
* Duplicate edges
* Self-loops → ignore
* Multiple components → DSU handles naturally

---

## **9. Variations**

* Kruskal with DSU rollback
* Minimum Spanning Forest (for disconnected graphs)
* Maximum Spanning Tree (sort edges descending)

---

## **10. Interview Tips**

FAANG expectations:

* Be able to implement DSU cleanly
* Explain why greedy choice is correct
* Show how cycle detection works through DSU
* Compare Kruskal vs Prim:

  * Kruskal → edge-based, good for sparse graphs
  * Prim → vertex-based, good for dense graphs
* Understand MST properties:

  * Cut property
  * Safe edge selection

Common mistakes:

* Forgeting to sort edges
* Not compressing DSU paths
* Handling disconnected graphs incorrectly

---

## **11. Practice Problems**

**LeetCode:**

* 1584 — Min Cost to Connect All Points
* 1168 — Optimize Water Distribution
* 1135 — Connecting Cities With Minimum Cost

**GFG:**

* Minimum Spanning Tree (Kruskal)
* DSU + MST problems

**Codeforces:**

* 25A — Roads not only in Berland
* 888E — Maximum spanning tree variant

---
