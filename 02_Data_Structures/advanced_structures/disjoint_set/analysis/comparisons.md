#  Comparisons of Disjoint Set (Union-Find) Approaches

---

##  Introduction

The **Disjoint Set Union (DSU)** or **Union-Find** data structure is widely used for efficiently handling **dynamic connectivity problems**.
However, different variations of **Find** and **Union** operations affect its performance significantly.

This document compares various DSU strategies in terms of **time complexity**, **implementation ease**, and **practical efficiency**.

---

##  Variants of Union-Find

### 1. **Naive Union-Find**

* **Find**: Traverse parent pointers until the root.
* **Union**: Simply make one root the parent of the other.

 Issue: Trees can become skewed (like linked lists).
Example:

```
Union(1,2), Union(2,3), Union(3,4), ...
Resulting tree height ≈ N
```

* **Time Complexity:** `O(N)` in worst case for `Find`.

---

### 2. **Union by Rank / Size**

* Always attach the **smaller tree** under the **larger tree**.
* Ensures that tree height remains `O(log N)` in the worst case.

 Prevents extremely unbalanced trees.

---

### 3. **Path Compression**

* During `Find(x)`, directly link all traversed nodes to the root.
* Flattens the tree, making subsequent queries faster.

Example before compression:

```
x → p → root
```

After compression:

```
x → root
p → root
```

---

### 4. **Union by Rank + Path Compression (Optimized DSU)**

* Combines both techniques.
* Ensures amortized **near-constant time** per operation.
* Time complexity per operation = `O(α(N))`, where `α(N)` is the **inverse Ackermann function** (practically ≤ 4 for all real-world inputs).

---

##  Comparison Table

| Technique                            | Worst-Case Find | Amortized Find | Union Complexity | Notes                                  |
| ------------------------------------ | --------------- | -------------- | ---------------- | -------------------------------------- |
| **Naive Union-Find**                 | `O(N)`          | `O(N)`         | `O(1)`           | Very inefficient for large inputs      |
| **Union by Rank/Size**               | `O(log N)`      | `O(log N)`     | `O(1)`           | Balanced trees                         |
| **Path Compression only**            | `O(N)`          | `O(α(N))`      | `O(1)`           | Effective alone, but still can degrade |
| **Union by Rank + Path Compression** | `O(log N)`      | `O(α(N))`      | `O(1)`           | Best practical approach                |

---

##  Visual Comparison

### Without Optimizations

```
Find(6) in chain:
6 → 5 → 4 → 3 → 2 → 1
```

Height = `O(N)`

---

### With Path Compression

```
After one Find(6):
6 → 1
5 → 1
4 → 1
3 → 1
2 → 1
```

Height = `O(1)`

---

##  Complexity Analysis

* **Union by Rank/Size:** Ensures trees remain balanced → `O(log N)`.
* **Path Compression:** Flattens trees → nearly constant time.
* **Union by Rank + Path Compression:**

  * Each operation runs in **amortized O(α(N))**,
  * where `α(N)` grows slower than log\*.

 For all practical purposes, **DSU operations are constant time**.

---

##  Interview Tips

* **FAANG interviews** often ask:

  * “Implement Union-Find with optimizations.”
  * “Explain why DSU is almost constant time.”
  * “Where is DSU used?” (e.g., Kruskal’s MST, cycle detection, connectivity queries).
*  Common trick: If you forget path compression, performance may degrade badly in large test cases.

---

##  Practice Problems

* [LeetCode 1319 – Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)
* [LeetCode 684 – Redundant Connection](https://leetcode.com/problems/redundant-connection/)
* [GeeksforGeeks – Union-Find (Detect Cycle in Graph)](https://www.geeksforgeeks.org/union-find/)
* [Codeforces DSU Tag Problems](https://codeforces.com/problemset?tags=dsu)

---
