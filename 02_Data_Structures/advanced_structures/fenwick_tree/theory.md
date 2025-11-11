# Fenwick Tree (Binary Indexed Tree) – Theory and Fundamentals

This file belongs under:
02_Data_Structures → advanced_structures → fenwick_tree → theory.md

This document explains Fenwick Trees from first principles, covering intuition, math, operations, pseudocode, complexity, variations, diagrams, and interview insights.

---

# 1. What is a Fenwick Tree?

A **Fenwick Tree**, also called a **Binary Indexed Tree (BIT)**, is a data structure that stores cumulative information in a compact and efficient way.

Main capabilities:

* point updates
* prefix sum queries
* range sum queries (via prefix sums)
* frequency and order-statistic queries (advanced usage)

Fenwick Tree is widely used in competitive programming and interview problems.

---

# 2. The Motivation Behind Fenwick Tree

Let A be an array of size n.

You want to support:

1. Update A[i] += delta
2. Query prefix sum sum(1..i)

Possible solutions:

| Approach     | Query    | Update   | Notes           |
| ------------ | -------- | -------- | --------------- |
| Prefix array | O(1)     | O(n)     | slow updates    |
| Segment tree | O(log n) | O(log n) | heavy memory    |
| Fenwick Tree | O(log n) | O(log n) | simple, compact |

Fenwick Tree is the sweet spot when both dynamic updates and fast queries are required.

---

# 3. Mathematical Intuition

Fenwick Tree relies on binary decomposition of indices.

For index i, define:

LSB(i) = i & -i
(Least Significant Bit)

This gives the smallest power of two dividing i.

Fenwick Tree uses LSB(i) to determine:

* how many elements each node covers
* how to traverse nodes during queries and updates

### Example

i = 12
Binary: 1100
LSB(12) = 100 (4)
Fenwick node 12 stores the sum from index 9 to 12.

General rule:
Node i stores sum in range
(i - LSB(i) + 1) .. i

---

# 4. Structure of the Fenwick Tree

Let fenw[] be an array where:

fenw[i] = sum over (i - LSB(i) + 1) .. i

ASCII representation:

Index:  1 2 3 4 5 6 7 8
LSB:    1 2 1 4 1 2 1 8

Fenwick coverage:

i=1 → covers [1]
i=2 → covers [1..2]
i=3 → covers [3]
i=4 → covers [1..4]
i=5 → covers [5]
i=6 → covers [5..6]
i=7 → covers [7]
i=8 → covers [1..8]

---

# 5. Query Operation (Prefix Sum)

To compute prefix_sum(i):

Initialize result = 0

while i > 0:
result += fenw[i]
i -= LSB(i)

This jumps upward in the decomposition tree.

Example path for i = 13:

13 → 12 → 8 → 0

At most log2(n) steps.

---

# 6. Update Operation (Point Update)

To update A[i] += delta:

while i <= n:
fenw[i] += delta
i += LSB(i)

This walks upward to nodes that cover index i.

Example path for i = 5:

5 → 6 → 8 → 16 → ...

At most log2(n) steps.

---

# 7. Range Sum Query

Since BIT supports prefix sums:

sum(l..r) = prefix_sum(r) − prefix_sum(l − 1)

This allows range queries efficiently with no extra structure.

---

# 8. Pseudocode (Template)

function add(i, delta):
while i <= n:
fenw[i] += delta
i += LSB(i)

function prefix_sum(i):
total = 0
while i > 0:
total += fenw[i]
i -= LSB(i)
return total

function range_sum(l, r):
return prefix_sum(r) - prefix_sum(l - 1)

---

# 9. Complexity Analysis

| Operation         | Time       | Space |
| ----------------- | ---------- | ----- |
| Point update      | O(log n)   | O(n)  |
| Prefix query      | O(log n)   | O(n)  |
| Range sum         | O(log n)   | O(n)  |
| Build (naive)     | O(n log n) | O(n)  |
| Build (optimized) | O(n)       | O(n)  |

Fenwick Tree is extremely efficient in space and time.

---

# 10. Visual Diagram of Update and Query Paths

Prefix Query Path (i → i - LSB(i)):

13
↓
12
↓
8
↓
0

Point Update Path (i → i + LSB(i)):

5
↓
6
↓
8
↓
16

---

# 11. Variations of Fenwick Tree

Fenwick Tree has powerful variants:

| Variant                        | Purpose                                 |
| ------------------------------ | --------------------------------------- |
| Range Update BIT               | Add delta to [l..r]                     |
| Range Query BIT using two BITs | Full range update + range query         |
| Order Statistic BIT            | Find k-th smallest using binary lifting |
| 2D Fenwick Tree                | Submatrix queries                       |
| 3D Fenwick Tree                | Advanced spatial problems               |

---

# 12. Edge Cases and Pitfalls

1. Must use 1-based indexing internally
2. Negative values work fine
3. Large index values require coordinate compression
4. BIT does not support min/max queries natively
5. 2D BIT uses O(n^2) memory (large)

---

# 13. Interview Tips

Expected discussion topics:

* Why use BIT over segment tree?
* LSB = i & -i (binary trick)
* Explain update/query paths
* When BIT is insufficient
* Complexity comparison
* BIT vs prefix array

Important facts to mention:

* BIT is simpler and faster to implement
* Perfect for frequency counting
* Perfect for inversion counting
* Construction can be O(n)

---

# 14. Practice Problems

Beginner:

* GFG: Fenwick Tree Construction
* Codeforces EDU: Fenwick Tree basics

Intermediate:

* LeetCode 307: Range Sum Query Mutable
* LeetCode 315: Count Smaller Numbers After Self

Advanced:

* LeetCode 493: Reverse Pairs
* Codeforces: problems with tag "fenwick" or "bit"
* AtCoder typical tasks

---

# 15. Comparison with Segment Tree

| Feature                | Fenwick Tree | Segment Tree              |
| ---------------------- | ------------ | ------------------------- |
| Space                  | O(n)         | O(4n)                     |
| Update                 | O(log n)     | O(log n)                  |
| Query                  | O(log n)     | O(log n)                  |
| Operations Supported   | sum          | sum/min/max/gcd/etc       |
| Range update           | needs tricks | easy via lazy propagation |
| Ease of implementation | very easy    | moderate/complex          |

---

# 16. Summary

Fenwick Tree is:

* efficient
* elegant
* space-optimal
* suitable for many competitive programming tasks
* ideal when operations are prefix sums + point updates
* extendable for advanced use cases

This completes the theoretical overview for the Fenwick Tree module.

