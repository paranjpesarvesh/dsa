## 🔹 Introduction
The **Disjoint Set Union (DSU)**, also known as **Union-Find** or **Merge-Find Set**, is a powerful data structure that efficiently supports two main operations:
1. **Find** → Determine the set (or representative) to which an element belongs.
2. **Union** → Merge two sets together.

It is widely used in:
- **Graph algorithms** → Kruskal’s MST, cycle detection, connected components.
- **Networking** → Finding connected users or servers.
- **Clustering** → Grouping similar data points.
- **Competitive programming** → Many connectivity problems.

---

## 🔹 Core Idea
The data structure represents disjoint sets as **trees**:
- Each set has a **representative (parent)**.
- Initially, every element is its own parent.
- Union merges trees by linking one root to another.

```

Example:
Initially: {1}, {2}, {3}, {4}
Union(1,2): {1,2}, {3}, {4}
Union(2,3): {1,2,3}, {4}

```

---

## 🔹 Mathematical Intuition
Let there be `n` elements:
- A naive `find` and `union` takes **O(n)** in the worst case (if the tree degenerates into a chain).
- With **Union by Rank/Size** and **Path Compression**:
  - The amortized time per operation becomes **O(α(n))**,
    where `α` = Inverse Ackermann function.
  - For all practical `n` (up to 10^18 or more), `α(n) ≤ 4`.
  - Essentially, operations are **constant time**.

---

## 🔹 Operations

### 1️⃣ **Find(x)**
Determines the root (representative) of the set containing `x`.

```

if parent\[x] == x:
return x
else:
return Find(parent\[x])

```

---

### 2️⃣ **Union(x, y)**
Merges sets containing `x` and `y`.

```

rootX = Find(x)
rootY = Find(y)
if rootX != rootY:
parent\[rootX] = rootY

```

---

## 🔹 Optimizations

###  Union by Rank
- Each root stores a "rank" (approximate tree height).
- Always attach the smaller tree under the larger one.

###  Union by Size
- Attach the smaller set under the larger one.
- Ensures balance of tree structure.

###  Path Compression
- While performing `find(x)`, directly link `x` to its root.
- Flattens the tree.

```

Find(x):
if parent\[x] != x:
parent\[x] = Find(parent\[x])   # Path compression
return parent\[x]

```

---

## 🔹 Visual Illustration

### Without Path Compression
```

1 → 2 → 3 → 4 → 5
Find(5) traverses entire chain

```

### With Path Compression
```

1
│
├── 2
├── 3
├── 4
└── 5
Find(5) goes directly to 1

````

---

## 🔹 Pseudocode (Optimized DSU)

```text
function MakeSet(n):
    for i = 1 to n:
        parent[i] = i
        rank[i] = 0

function Find(x):
    if parent[x] != x:
        parent[x] = Find(parent[x])   # Path Compression
    return parent[x]

function Union(x, y):
    rootX = Find(x)
    rootY = Find(y)

    if rootX == rootY:
        return

    if rank[rootX] < rank[rootY]:
        parent[rootX] = rootY
    else if rank[rootX] > rank[rootY]:
        parent[rootY] = rootX
    else:
        parent[rootY] = rootX
        rank[rootX] += 1
````

---

## 🔹 Complexity Analysis

| Operation | Naive | With Rank | With Rank + Path Compression |
| --------- | ----- | --------- | ---------------------------- |
| **Find**  | O(n)  | O(log n)  | O(α(n)) ≈ O(1)               |
| **Union** | O(n)  | O(log n)  | O(α(n)) ≈ O(1)               |

---

## 🔹 Variations

* **Union by Size** (instead of rank).
* **DSU with Rollback** (for persistent data structures).
* **Dynamic DSU** (handling insertion/deletion of nodes).
* **DSU on Trees** (for subtree queries).
* **2D Grid DSU** (for matrix connectivity problems).

---

## 🔹 Interview Tips

* FAANG interviews often test DSU in **graph-based problems**:

  * Detecting cycles.
  * Number of connected components.
  * Minimum Spanning Tree (Kruskal).
* GATE exams emphasize **amortized complexity proofs** and optimizations.
* Be ready to code DSU **from scratch in under 5 minutes**.

---

## 🔹 Practice Problems

* [LeetCode 547: Number of Provinces](https://leetcode.com/problems/number-of-provinces/)
* [LeetCode 684: Redundant Connection](https://leetcode.com/problems/redundant-connection/)
* [LeetCode 721: Accounts Merge](https://leetcode.com/problems/accounts-merge/)
* [GFG: Detect Cycle in Undirected Graph](https://www.geeksforgeeks.org/detect-cycle-undirected-graph/)
* [Codeforces 25D: Roads not only in Berland](https://codeforces.com/problemset/problem/25/D)

---

✅ **Summary**:
Disjoint Set (Union-Find) is one of the **most efficient structures** for partitioning data into groups. With **Union by Rank** and **Path Compression**, it achieves near-constant-time operations, making it indispensable in graph theory and interview preparation.

---
