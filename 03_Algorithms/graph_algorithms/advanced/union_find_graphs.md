# **Union-Find in Graph Algorithms (Applications of DSU)**
---

## **1. Overview**

This file expands upon **Union-Find (DSU)** specifically in the context of **graph algorithms**.

While `union_find.md` explains how DSU works, this document focuses on **how DSU is applied to solve graph problems efficiently**.

---

## **2. Core DSU Operations Recap**

* **find(x)** → gets the representative of x
* **union(x, y)** → merges sets containing x and y
* Uses:

  * **Path compression** (makes structure flat)
  * **Union by rank/size** (keeps tree shallow)

Amortized time: **α(N)** ≈ constant.

---

## **3. Why DSU Works So Well for Graphs**

DSU is ideal for problems involving:

* Connectivity queries
* Dynamic merging of components
* Detecting cycles
* Building minimum spanning trees
* Grouping nodes with constraints
* Offline processing of edges or queries

---

## **4. DSU in Undirected Graph Cycle Detection**

### **Intuition**

If an edge u → v connects two nodes **already in the same component**, adding it creates a **cycle**.

### **Algorithm**

For every edge (u, v):

1. If find(u) == find(v):
   → cycle detected
2. Else:
   → union(u, v)

### **ASCII Example**

Graph:
1 — 2 — 3 — 4
↖───────

Process edges:
(1,2): ok
(2,3): ok
(3,4): ok
(4,2): find(4)=find(2) → cycle detected

---

## **5. DSU in Minimum Spanning Tree (Kruskal’s Algorithm)**

Kruskal sorts edges by weight and picks the lightest edges that do **not** form a cycle.

### **Key Steps**

1. Sort edges by weight
2. For each edge (u, v):

   * If find(u) != find(v) → select edge
   * union(u,v)
3. Stop when you have N - 1 edges

DSU ensures near O(1) connectivity checks → MST becomes O(E log E).

---

## **6. DSU for Connected Components**

Given an undirected graph:

* After processing all edges with union(),
* All nodes with same representative belong to the same component.

Example:

Edges: (1,2), (2,3), (4,5)

Components:
{1,2,3} and {4,5}

---

## **7. DSU in Offline Query Problems**

Many competitive programming problems give:

* Q queries like:

  * "Add edge"
  * "Are nodes u and v connected?"
  * "Remove edge"

DSU is perfect when queries can be processed **offline**, e.g.:

* Reverse-delete (answers backwards)
* Mo’s algorithm on trees
* DSU with rollback (undo operations)

---

## **8. DSU in Bipartite Checking**

For graph coloring/bipartite checks:

We can maintain **color parity** using DSU by storing extra info:

* Each node has a representative and parity relative to parent
* Useful for constraints like:

  * x and y must be same color
  * x and y must be opposite color

---

## **9. DSU Applications Table**

| Problem Type                 | DSU Use                                      |
| ---------------------------- | -------------------------------------------- |
| Cycle detection (undirected) | Check if two nodes belong to same set        |
| Kruskal MST                  | Select smallest edges without forming cycles |
| Connected components         | Group nodes with union operations            |
| Bipartite constraints        | Maintain parity information                  |
| Offline queries              | Reverse operations using rollback            |
| Graph clustering             | Combine nodes as clusters grow               |

---

## **10. Pseudocode Template (No Code Block)**

Cycle detection:

for (u, v) in edges:
if find(u) == find(v):
cycle found
else:
union(u, v)

Kruskal MST:

sort edges by weight
for each (u, v, w):
if find(u) != find(v):
add to MST
union(u, v)

Connected components:

for (u, v) in edges:
union(u, v)
groups form by same representative

---

## **11. Complexity**

Operation costs:
find → α(N)
union → α(N)

Overall for graph problems:

* Cycle detection: **O(E α(N))**
* Kruskal MST: **O(E log E)** (sorting dominates)
* Connected components: **O(E α(N))**

Space: O(N)

---

## **12. Edge Cases**

* Duplicate edges
* Self-loops (always cycle in undirected graph)
* Large graphs → consider iterative DSU
* DSU cannot detect cycles in **directed** graphs directly

---

## **13. Interview Tips**

FAANG frequently uses DSU in:

* Redundant connection problems
* Friend circles / Provinces
* MST questions
* Connectivity constraints

Expect to:

* Explain why DSU is nearly constant time
* Perform a manual union/find sequence
* Discuss DSU optimizations (rank + compression)
* Use DSU to detect cycles or build MST

---

## **14. Practice Problems**

**LeetCode:**

* 547 — Number of Provinces
* 684 — Redundant Connection
* 1319 — Make Network Connected
* 1584 — MST (Kruskal + DSU)

**GFG:**

* Detect cycle in an undirected graph
* Kruskal MST

**Codeforces:**

* 25A — Roads not only in Berland
* 652D — Nested Segments (offline DSU trick)

---
