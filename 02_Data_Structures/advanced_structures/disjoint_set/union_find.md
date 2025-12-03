# Union-Find (Disjoint Set Union - DSU)

---

## 1. Introduction

The **Union-Find** (also known as **Disjoint Set Union (DSU)**) is a data structure that keeps track of a collection of disjoint (non-overlapping) sets and supports two fundamental operations:

1. **Find(x):** Determine which set element `x` belongs to (i.e., find its root/representative).
2. **Union(x, y):** Merge the sets containing elements `x` and `y`.

This data structure is widely used in graph algorithms (e.g., **Kruskal’s MST**, **cycle detection**, **connected components**) and in solving dynamic connectivity problems.

---

## 2. Motivation

Imagine we have several groups of elements and we want to:

* Merge groups quickly.
* Check if two elements belong to the same group.

Naively maintaining sets via arrays or linked lists leads to inefficient merging and searching.
Union-Find provides **near constant-time operations** using **path compression** and **union by rank/size**.

---

## 3. Conceptual Visualization

```
Initially: Each element is its own set (parent points to itself)

1   2   3   4   5
|   |   |   |   |
1   2   3   4   5

Union(1, 2) → Merge sets of 1 and 2

    1
   /
  2    3   4   5

Union(3, 4) → Merge sets of 3 and 4

    1        3
   /        /
  2        4     5

Union(2, 3) → Merge sets of (1,2) and (3,4)

       1
     /   \
    2     3
          /
         4     5
```

---

## 4. Core Operations

### **Find (with Path Compression)**

* Traverses up the parent chain until it finds the root.
* Path compression flattens the tree for efficiency.

Pseudocode:

```
function find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])  // Path compression
    return parent[x]
```

---

### **Union (by Rank or Size)**

* Always attach the **smaller tree** under the **larger tree**.
* Keeps the height of the trees small → improves efficiency.

Pseudocode:

```
function union(x, y):
    rootX = find(x)
    rootY = find(y)

    if rootX == rootY:
        return

    if rank[rootX] < rank[rootY]:
        parent[rootX] = rootY
    else if rank[rootX] > rank[rootY]:
        parent[rootY] = rootX
    else:
        parent[rootY] = rootX
        rank[rootX] += 1
```

---

## 5. Complexity Analysis

| Operation | Naive DSU                       | With Path Compression + Union by Rank/Size |
| --------- | ------------------------------- | ------------------------------------------ |
| `find`    | O(log n) – tree height can grow | O(α(n)) – almost constant                  |
| `union`   | O(log n)                        | O(α(n))                                    |
| Space     | O(n)                            | O(n)                                       |

 **α(n)** = Inverse Ackermann function, which grows so slowly it’s practically constant for all real-world inputs.

---

## 6. Variations & Edge Cases

* **Union by Rank**: Track tree height.
* **Union by Size**: Track set sizes (attach smaller under larger).
* **Rollback DSU**: Supports undo operations (used in dynamic connectivity).
* **DSU with Metadata**: Store extra data (e.g., sum, min, max) in each set.
* **Edge Case**: Self-union (`union(x, x)`) should not change anything.

---

## 7. Interview Tips

* **FAANG**: Often appears in graph-related problems (e.g., Kruskal’s MST, dynamic connectivity, cycle detection).
* **GATE/CP**: Tested as a theoretical concept (complexity proofs of α(n)) and practical implementations.
* **Common Pitfall**: Forgetting to use **path compression** leads to TLE on large datasets.

---

## 8. Applications of DSU

* Detecting cycles in an undirected graph.
* Connected components in a graph.
* Kruskal’s Minimum Spanning Tree algorithm.
* Percolation problems.
* Network connectivity checks.
* Dynamic connectivity queries.

---

## 9. ASCII Flowchart

```
[Start]
   |
   v
[Find Root of x] ---> [Find Root of y]
   |                        |
   v                        v
If rootX == rootY ? -----> Yes --> [Already in Same Set]
   | No
   v
[Attach smaller tree under larger]
   |
   v
[Done]
```

---

## 10. Practice Problems

* **LeetCode 684** - Redundant Connection (Cycle Detection).
* **LeetCode 721** - Accounts Merge.
* **LeetCode 839** - Similar String Groups.
* **LeetCode 990** - Satisfiability of Equality Equations.
* **GFG** - Detect cycle in an undirected graph.
* **Codeforces 25D** - Roads not only in Berland.
* **AtCoder ABC 177 F** - Union Find with intervals.

---

 With these notes, you now understand **Union-Find (DSU)** thoroughly: from definitions, intuition, operations, and optimizations, to its role in real-world problems.

---
