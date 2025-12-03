#  Kruskal's Minimum Spanning Tree (MST) using Disjoint Set Union (DSU)

---

##  Introduction

Kruskal's algorithm is a **greedy method** to find the **Minimum Spanning Tree (MST)** of a connected, weighted, undirected graph.

* MST: A **subset of edges** connecting all vertices with **minimum total weight** and **no cycles**.
* **DSU** is used to efficiently **check for cycles** when adding edges.

---

##  Intuition

1. Sort all edges by **weight in ascending order**.
2. Iterate through edges and attempt to **add them to MST**.
3. Before adding an edge `(u,v)`:

   * If `find(u) != find(v)` → safe to add (no cycle).
   * Else → discard edge (would create cycle).
4. Union the sets after adding an edge.

This ensures MST is **cycle-free** and of **minimal total weight**.

---

##  Step-by-Step Example

Graph with edges:

| Edge  | Weight |
| ----- | ------ |
| (0,1) | 1      |
| (1,2) | 3      |
| (0,2) | 2      |
| (2,3) | 4      |

**Step 1: Sort edges**

```
(0,1) -> 1
(0,2) -> 2
(1,2) -> 3
(2,3) -> 4
```

**Step 2: Process edges with DSU**

1. `(0,1)` → add to MST, union(0,1)
2. `(0,2)` → add to MST, union(0,2)
3. `(1,2)` → find(1)==find(2) → cycle, skip
4. `(2,3)` → add to MST, union(2,3)

 MST edges: `(0,1), (0,2), (2,3)`
 Total weight = 1 + 2 + 4 = 7

---

##  Pseudocode

```
function KruskalMST(edges, n):
    sort edges by weight ascending
    DSU dsu(n)
    MST_weight = 0
    MST_edges = []

    for edge (u, v, w) in edges:
        if dsu.find(u) != dsu.find(v):
            dsu.union(u, v)
            MST_edges.append((u,v))
            MST_weight += w

    return MST_weight, MST_edges
```

---

##  Complexity Analysis

| Operation      | Complexity                                |
| -------------- | ----------------------------------------- |
| Sorting edges  | O(E log E)                                |
| DSU operations | O(E α(V)) (almost constant per operation) |
| Total          | **O(E log E + E α(V))** ≈ O(E log E)      |
| Space          | O(V) for DSU arrays                       |

---

##  ASCII Visualization

```
Vertices: 0  1  2  3
Edges:  (0-1,1)  (0-2,2)  (1-2,3)  (2-3,4)

Step 1: Add (0-1)
0--1   2   3

Step 2: Add (0-2)
  0
 / \
1   2
3

Step 3: Skip (1-2) due to cycle
Step 4: Add (2-3)
    0
   / \
  1   2
       \
        3
```

---

##  Variations & Edge Cases

* **Disconnected Graph** → Kruskal builds **Minimum Spanning Forest**.
* **Multiple edges with same weight** → can result in multiple valid MSTs.
* **Directed graphs** → Kruskal cannot be applied directly.

---

##  Interview Tips

* FAANG and competitive programming often test **Kruskal MST + DSU**.
* Remember **DSU optimizations**: path compression + union by rank.
* Compare Kruskal with **Prim's algorithm**:

  * Kruskal → better for **sparse graphs**
  * Prim → better for **dense graphs**

---

##  Practice Problems

* [GFG – Kruskal's Minimum Spanning Tree](https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/)
* [LeetCode 1135 – Connecting Cities With Minimum Cost](https://leetcode.com/problems/connecting-cities-with-minimum-cost/)
* [Codeforces – MST & DSU problems](https://codeforces.com/problemset?tags=dsu)

---
