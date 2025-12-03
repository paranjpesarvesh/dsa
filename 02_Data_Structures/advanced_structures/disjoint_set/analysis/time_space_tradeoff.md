# ⏱ Time-Space Tradeoff in Disjoint Set (Union-Find)

---

##  Introduction

The **Disjoint Set Union (DSU)**, also known as **Union-Find**, is one of the most efficient data structures for solving **dynamic connectivity problems**.
Its efficiency comes from a clever balance between **time and space** optimizations.

This document explores how different DSU implementations trade off **time complexity** against **space usage** and why these tradeoffs matter in practice.

---

##  The Core Operations

A **DSU** supports two main operations:

1. **Find(x):** Determine the representative (root) of the set containing element `x`.
2. **Union(x, y):** Merge the sets containing `x` and `y`.

---

##  Naive DSU vs Optimized DSU

### 1. **Naive DSU (No Optimizations)**

* **Find:** Traverse parent pointers until reaching the root.
* **Union:** Arbitrarily attach one tree under the other.

| Operation | Time Complexity | Space Complexity |
| --------- | --------------- | ---------------- |
| Find      | `O(N)`          | `O(N)`           |
| Union     | `O(N)`          | `O(N)`           |

 Extremely inefficient for large datasets, since trees can become skewed.

---

### 2. **Union by Rank / Size**

* Always attach the **smaller tree** under the **larger tree**.
* Keeps trees balanced.

| Operation | Time Complexity | Space Complexity |
| --------- | --------------- | ---------------- |
| Find      | `O(log N)`      | `O(N)`           |
| Union     | `O(log N)`      | `O(N)`           |

 Space usage remains linear, but time improves significantly.

---

### 3. **Path Compression**

* During `Find(x)`, reattach nodes directly to the root.
* Trees become **almost flat** after a few operations.

| Operation | Amortized Time | Space Complexity |
| --------- | -------------- | ---------------- |
| Find      | `O(α(N))`      | `O(N)`           |
| Union     | `O(α(N))`      | `O(N)`           |

 `α(N)` = inverse Ackermann function (≤ 4 for all real-world inputs).

 Near-constant time operations with only `O(N)` space.

---

### 4. **Union by Rank + Path Compression (Optimal DSU)**

This is the **most widely used version**:

* Balanced unions → prevents tall trees.
* Path compression → keeps trees flat.

| Operation | Amortized Time | Space Complexity |
| --------- | -------------- | ---------------- |
| Find      | `O(α(N))`      | `O(N)`           |
| Union     | `O(α(N))`      | `O(N)`           |

 Best tradeoff between **time efficiency** and **space usage**.

---

##  Visualizing the Tradeoff

### Without Path Compression

```
Find(7):
7 → 6 → 5 → 4 → 3 → 2 → 1
Height = O(N)
```

---

### With Path Compression

```
After Find(7):
7 → 1
6 → 1
5 → 1
4 → 1
3 → 1
2 → 1
Height = O(1)
```

---

##  Space vs Time: What We Trade

* **Space Cost:**

  * Extra arrays like `rank[]` or `size[]` need `O(N)` additional space.
* **Time Savings:**

  * Reduces query cost from `O(N)` → `O(α(N))`.
  * For `10^6` queries, this difference is massive.

---

##  Mathematical Intuition

* **Rank-based union:** Height `≤ log N`.
* **Path compression:** Almost flattens the tree → `α(N)` bound.
* **Inverse Ackermann Function:**

  * `α(N)` grows so slowly that it is ≤ 4 for all practical inputs (`N < 10^80`).

So in practice, **DSU behaves like O(1) per operation**.

---

##  Interview Tips

* Always **mention both optimizations** (Rank + Path Compression).
* Be prepared to explain **why `α(N)` is “constant enough”**.
* Common FAANG questions:

  * *“Why does path compression improve efficiency?”*
  * *“Compare DSU with naive union-find.”*
  * *“What is the time complexity of DSU in Kruskal’s algorithm?”*

---

##  Practice Problems

* [LeetCode 128 – Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)
* [LeetCode 547 – Number of Provinces](https://leetcode.com/problems/number-of-provinces/)
* [GFG – Union-Find Algorithm](https://www.geeksforgeeks.org/union-find/)
* [Codeforces 25D – Roads not only in Berland](https://codeforces.com/problemset/problem/25/D)

---
