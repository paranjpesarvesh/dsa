# Kruskal’s Algorithm using Disjoint Set (Union–Find)

Kruskal’s algorithm is a **greedy** technique used to compute the **Minimum Spanning Tree (MST)** of a connected, undirected, weighted graph.
It relies heavily on the **Disjoint Set (Union–Find)** data structure to efficiently detect cycles during edge selection.

This file belongs to:
02_Data_Structures → advanced_structures → disjoint_set → applications
Hence the focus is on explaining how DSU powers Kruskal’s algorithm.

---

# 1. Problem Definition

Given an undirected weighted graph `G(V, E)`, the task is to find a subset of edges forming a **Minimum Spanning Tree**, such that:

* All vertices are connected
* There is no cycle
* Total weight is minimum

---

# 2. Intuition

Kruskal’s logic:

1. Sort all edges by weight (ascending)
2. Pick the lowest-cost edge that does not form a cycle
3. Use DSU (Union-Find) to check if adding the edge forms a cycle
4. Continue until MST has (V-1) edges

Cycle detection by DSU is the key.

ASCII intuition:

Edges sorted:
(2) ---- (4) ---- (5) ---- (8) ---- (10)

Try to add smallest edges first.

---

# 3. Why Disjoint Set?

In step 3, we need to check if two vertices `u` and `v` already belong to the same connected component.

DSU provides:

* find(u) → retrieves component leader
* union(u, v) → merges sets

Cycle check:
If find(u) == find(v), adding the edge forms a cycle → skip it.

---

# 4. Algorithm Breakdown (Step-by-Step)

1. Initialize MST = empty
2. Sort edges by weight
3. Initialize DSU for all vertices
4. For each edge (u, v, w):

   * If find(u) != find(v):

     * Add edge to MST
     * union(u, v)
5. Stop when MST contains (V - 1) edges

---

# 5. Pseudocode

parent[] and rank[] maintained by DSU.

Input: list of edges E = (u, v, w)

function KRUSKAL(E, n):
sort edges by weight
initialize DSU for n nodes
MST = empty list

```
for each (u, v, w) in sorted E:
    if find(u) != find(v):
        MST.add((u, v, w))
        union(u, v)

    if size(MST) == n-1:
        break

return MST
```

---

# 6. Complexity Analysis

Sorting edges:
O(E log E)

Union-Find operations:
Amortized O(α(n)) ~ constant

Total complexity:
O(E log E)

Space:
O(V)

---

# 7. Visual Example

Graph edges:
(0,1,4)
(0,2,3)
(1,2,2)
(1,3,5)
(2,3,7)

Sorted:
(1,2,2)
(0,2,3)
(0,1,4)
(1,3,5)
(2,3,7)

Processing:

Pick (1,2) → OK
Pick (0,2) → OK
Pick (0,1) → cycle → skip
Pick (1,3) → OK

MST edges:
(1,2)
(0,2)
(1,3)

ASCII MST:

1
|
2  0
|
3

Total cost = 2 + 3 + 5 = 10

---

# 8. Variations of Kruskal's Algorithm

1. Kruskal with edge filtering
2. Kruskal with priority queue
3. Online Kruskal (edges come in streaming form)
4. Kruskal for forests

---

# 9. Edge Cases

1. Graph not connected → returns a forest
2. Parallel edges → lowest weight chosen
3. Self-loops → always ignored
4. Negative edges → handled without modification

---

# 10. Interview Tips

Companies commonly test:

* DSU with path compression
* Union by rank
* Cycle detection
* How Kruskal compares to Prim
* Time complexity derivation
* Implementation correctness under constraints of up to 10^5 nodes/edges

Comparison table:

| Algorithm | Works Well For | Data Structure        |
| --------- | -------------- | --------------------- |
| Kruskal   | Sparse graphs  | DSU                   |
| Prim      | Dense graphs   | Heap / adjacency list |

Most interviewers ask why DSU is ideal:
Because cycle detection becomes O(1) amortized.

---

# 11. Practice Problems

LeetCode:

* 1584. Min Cost to Connect All Points
* 1135. Connecting Cities With Minimum Cost
* 261. Graph Valid Tree

GFG:

* Minimum Spanning Tree
* Kruskal’s Algorithm

Codeforces:

* Problems tagged "dsu" or "graphs"
* Educational CF round problems with MST focus

---

# 12. Summary Table

| Concept     | Meaning            |
| ----------- | ------------------ |
| Greedy      | pick smallest edge |
| Cycle check | find(u) == find(v) |
| DSU purpose | efficient merging  |
| MST edges   | count = V − 1      |
| Runtime     | O(E log E)         |

---
