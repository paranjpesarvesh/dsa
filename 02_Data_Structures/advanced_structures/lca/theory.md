# Lowest Common Ancestor (LCA) — Theory

This file belongs under:
02_Data_Structures → advanced_structures → lca → theory.md

This document explains the concept, implementation approaches, intuition, and interview-oriented reasoning for the Lowest Common Ancestor problem.

---

# 1. What is LCA?

Given a **rooted tree**, the **Lowest Common Ancestor** of two nodes `u` and `v` is:

> The deepest node that is an ancestor of both `u` and `v`.

Example tree:

```
   1
  / \
 2   3
/ \  / \
```

4  5 6  7

LCA(4, 5) = 2
LCA(4, 6) = 1
LCA(6, 7) = 3

---

# 2. Why LCA Matters

LCA is a fundamental operation in tree-based algorithms.

Used in:

* distance queries
* tree diameter computations
* dynamic tree operations
* binary lifting
* RMQ problems
* heavy-light decomposition
* Tarjan’s offline LCA algorithm
* Euler tour segmentation

Common in interviews: Amazon, Google, Meta, Microsoft, etc.

---

# 3. Naive Approach (O(N) per query)

To find LCA(u, v):

1. Move the deeper node upward one step at a time
2. When both are at same depth, move them together until they meet

Works but slow when many queries.

---

# 4. Efficient Approaches

## Summary Table

| Method                    | Preprocessing | Query    | Space      | Notes                |
| ------------------------- | ------------- | -------- | ---------- | -------------------- |
| Naive                     | O(1)          | O(N)     | O(1)       | simplest             |
| Binary Lifting            | O(N log N)    | O(log N) | O(N log N) | common in interviews |
| Euler Tour + RMQ          | O(N log N)    | O(1)     | O(N log N) | fast queries         |
| Euler Tour + Sparse Table | O(N log N)    | O(1)     | O(N log N) | static tree only     |
| Euler Tour + Segment Tree | O(N)          | O(log N) | O(N)       | dynamic RMQ          |
| Tarjan Offline            | O(N + Q)      | O(α(N))  | O(N)       | offline queries      |

Binary lifting is the most practical and widely used for interviews.

---

# 5. Binary Lifting — Intuition

Idea:

1. Store ancestor jumps of size 2^k for every node.
2. Use binary representation of depth differences to lift nodes quickly.
3. Jump both nodes upward until their ancestors diverge.

Binary representation example:

If we need to lift by 13 levels:

13 = 8 + 4 + 1
Use jumps: 2^3, 2^2, 2^0

Tree can be navigated in O(log N) time.

---

# 6. Binary Lifting — Detailed Explanation

### Preprocessing

Store:

parent[k][v] = 2^k-th ancestor of v

Base case:
parent[0][v] = immediate parent

Recurrence:
parent[k][v] = parent[k−1][ parent[k−1][v] ]

### Depth Array

Store depth[v] = distance from root.

---

### Steps to Find LCA(u, v)

1. If depths differ → lift deeper node
2. Lift both nodes upward from largest jump downwards
3. When they diverge → their parent is the LCA

---

# 7. Algorithm Flowchart (ASCII)

Lift deeper node to same depth:

u deeper ?

if depth[u] < depth[v]:
swap(u, v)

Lift operation:

dist = depth[u] - depth[v]

for k from LOG-1 down to 0:
if dist has bit k:
u = parent[k][u]

Both now at equal depth:

if u == v:
return u

Lift both simultaneously:

for k from LOG-1 down to 0:
if parent[k][u] != parent[k][v]:
u = parent[k][u]
v = parent[k][v]

Return parent[0][u]

---

# 8. Pseudocode (Binary Lifting)

function preprocess():
dfs(root)
for k in 1..LOG:
for v in 1..n:
parent[k][v] = parent[k-1][ parent[k-1][v] ]

function lca(u, v):
if depth[u] < depth[v]:
swap(u, v)

```
// lift u
diff = depth[u] - depth[v]
for k in LOG down to 0:
    if diff & (1 << k):
        u = parent[k][u]

if u == v:
    return u

// lift both
for k in LOG down to 0:
    if parent[k][u] != parent[k][v]:
        u = parent[k][u]
        v = parent[k][v]

return parent[0][u]
```

---

# 9. Complexity Analysis

| Operation     | Cost       |
| ------------- | ---------- |
| Preprocessing | O(N log N) |
| Query         | O(log N)   |
| Space         | O(N log N) |

---

# 10. Variations

1. **Euler Tour + RMQ**
   Convert tree to array using tour, store depth sequence, reduce LCA to RMQ.

2. **Heavy-Light Decomposition (HLD)**
   Used for path queries and segment tree integrations.

3. **Tarjan Offline LCA**
   Useful when queries are offline.

4. **Binary lifting with additional attributes**

   * track max edge weight on path
   * track min edge weight
   * track xor sum

---

# 11. Edge Cases

1. u == v → answer is u
2. One node is ancestor of the other
3. Disconnected graph → invalid input
4. Root selection affects depth but not LCA correctness
5. Large values → ensure recursion limits are safe (Python)

---

# 12. Interview Tips

Common questions:

* What preprocessing is needed?
* How does binary lifting work?
* When would you choose RMQ method over binary lifting?
* Time complexity?
* How to compute the distance between u and v using LCA?
  dist = depth[u] + depth[v] - 2 * depth[lca]

Often interview variations:

* Find k-th ancestor
* Find min/max edge weight between nodes
* Find number of edges between nodes
* Check if u is ancestor of v
* Preprocess tree for quick path-sum queries

---

# 13. Practice Problems

### LeetCode

* 236. Lowest Common Ancestor of a Binary Tree
* 1644. LCA of Binary Tree II
* 235. LCA of BST

### GFG

* LCA in Binary Tree
* LCA in Binary Lifting (competitive version)

### Codeforces

* Tree queries involving LCA
* Problem tags: `lca`, `tree`, `binary lifting`

---

# 14. Summary Table

| Concept                 | Explanation                          |
| ----------------------- | ------------------------------------ |
| Definition              | Deepest common ancestor of two nodes |
| Best interview approach | Binary lifting                       |
| Preprocessing           | O(N log N)                           |
| Query time              | O(log N)                             |
| Extra utilities         | k-th ancestor, node distance         |
| Alternative method      | Euler Tour + RMQ                     |

---
