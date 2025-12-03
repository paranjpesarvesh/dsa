# Cycle Detection in Graphs using Disjoint Set (Union-Find)

##  Introduction

Cycle detection is a fundamental problem in graph theory.
For **undirected graphs**, the **Disjoint Set Union (DSU)**, also known as **Union-Find**, provides an efficient way to detect cycles.

---

##  Key Idea

* Each vertex belongs to a **set** representing its connected component.
* When processing an edge `(u, v)`:

  * If `u` and `v` belong to the **same set**, adding this edge creates a **cycle**.
  * Otherwise, we **union** their sets.

---

##  Mathematical Intuition

We maintain equivalence classes of vertices:

* `find(x)` → returns the representative (root) of vertex `x`.
* `union(x, y)` → merges the sets of `x` and `y`.

A cycle is detected if:

$$
find(u) = find(v) \quad \text{before union}
$$

---

##  Algorithm (Step-by-Step)

1. Initialize DSU with all vertices as their own parent.
2. For each edge `(u, v)`:

   * Check roots of `u` and `v`.
   * If roots are same → **cycle exists**.
   * Else, union their sets.
3. If no edge creates conflict → **no cycle**.

---

##  Pseudocode

```
function detectCycle(edges, n):
    parent = [0..n-1]  # DSU init
    rank = [0..n-1]

    for each (u, v) in edges:
        if find(u) == find(v):
            return True   # cycle found
        union(u, v)

    return False   # no cycle
```

---

##  Complexity Analysis

* **Find / Union** (with path compression + union by rank): `O(α(n))` ≈ constant.
* **Overall** for `E` edges and `V` vertices:

  $$
  O(E \cdot α(V)) \approx O(E)
  $$

---

##  Visual Example

Graph edges: `(0-1), (1-2), (2-0)`

```
0 -- 1
 \  /
   2
```

* Add (0–1) → union sets.
* Add (1–2) → union sets.
* Add (2–0) → find(2) = find(0) ⇒ **Cycle detected**.

---

##  Variations & Edge Cases

* **Directed graphs** → use DFS or Kahn’s Algorithm instead.
* **Multiple edges** → self-loops or parallel edges may directly form cycles.
* **Dynamic graphs** → DSU can track cycles incrementally.

---

##  Interview Tips

* Commonly asked in **FAANG** interviews with Kruskal’s MST.
* Be ready to discuss optimizations: **path compression** and **union by rank/size**.
* In GATE, cycle detection often appears as a step in MST or connectivity problems.

---

##  Practice Problems

* [GFG: Detect cycle in an undirected graph](https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)
* [LeetCode 684: Redundant Connection](https://leetcode.com/problems/redundant-connection/)
* [HackerRank: Detect Cycle](https://www.hackerrank.com/challenges/detect-whether-a-graph-contains-a-cycle/problem)

---
