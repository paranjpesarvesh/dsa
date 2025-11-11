# Fenwick Tree (Binary Indexed Tree) – Complete Guide

This file belongs under:
02_Data_Structures → advanced_structures → fenwick_tree → README.md

Therefore, this document serves as the main introductory guide to Fenwick Trees, covering definition, intuition, operations, implementation concepts, complexity analysis, applications, and links to subtopics.

---

# 1. Introduction

A **Fenwick Tree**, also known as a **Binary Indexed Tree (BIT)**, is a data structure designed to efficiently support:

* prefix sum queries
* point updates
* dynamic frequency/counting
* binary lifting for order statistics

It provides a very efficient replacement for prefix arrays when frequent updates are needed.

---

# 2. Motivation

For an array A:

* Prefix array gives O(1) prefix queries but O(n) updates
* Segment tree gives O(log n) for both but uses O(4n) memory
* Fenwick Tree gives O(log n) for both with O(n) memory and simpler code

Thus it sits at an ideal midpoint between ease-of-implementation and functionality.

---

# 3. Core Idea

Fenwick Tree stores **partial sums** in a clever way using binary representation.

Key concept:

LSB(i) = i & -i
(Least Significant Bit)

A Fenwick Tree essentially decomposes the prefix sum into overlapping segments determined by the LSB.

For index i, Fenwick stores the sum of elements:

(i - LSB(i) + 1) to i

---

# 4. Visual Intuition

Consider indices from 1 to 8:

Index:          1  2  3  4  5  6  7  8
Binary:        001 010 011 100 101 110 111 1000
LSB:            1   2   1   4   1   2   1   8

Fenwick node coverage:

i=1 → [1]
i=2 → [1..2]
i=3 → [3]
i=4 → [1..4]
i=5 → [5]
i=6 → [5..6]
i=7 → [7]
i=8 → [1..8]

Prefix queries move:

i = 8 → 0
i = 7 → 6 → 4 → 0
i = 6 → 4 → 0

This recursive structure is what makes BIT extremely fast.

---

# 5. Supported Operations

## Point Update

A[i] += delta
Updates Fenwick nodes upward:

i += LSB(i)

## Prefix Sum Query

Sum of elements A[1..i]
Moves downward:

i -= LSB(i)

## Range Sum Query

sum(l..r) = prefix(r) − prefix(l−1)

---

# 6. Time Complexity

| Operation                | Complexity |
| ------------------------ | ---------- |
| Point Update             | O(log n)   |
| Prefix Sum Query         | O(log n)   |
| Range Sum Query          | O(log n)   |
| Construction (naive)     | O(n log n) |
| Construction (optimized) | O(n)       |
| Memory                   | O(n)       |

---

# 7. Key Applications

Fenwick Tree is widely used in:

## Frequency-Based Problems

* Counting smaller elements on the right
* Counting inversions
* Dynamic frequency counting
* K-th smallest value queries (order statistics)

## Range Query Problems

* sum queries
* difference array technique
* partial sum reconstruction

## Competitive Programming

* sweep line algorithms
* counting events
* offline processing

## 2D and multi-dimensional Fenwick Trees

* submatrix sum queries
* grid-based simulations

---

# 8. Variants of Fenwick Tree

| BIT Variant         | Supports                     |
| ------------------- | ---------------------------- |
| Standard BIT        | point update + prefix query  |
| Range Update BIT    | range update + point query   |
| Dual BIT            | range update + range query   |
| 2D BIT              | point update + submatrix sum |
| Order Statistic BIT | find-by-prefix               |

---

# 9. Structure of This Folder

The following folders exist under this directory:

| Subfolder       | Content Description                                                         |
| --------------- | --------------------------------------------------------------------------- |
| implementation/ | Python/C++ Fenwick Tree implementations (basic, advanced, variants)         |
| analysis/       | Time-space tradeoff, comparisons, edge cases, mathematical insights         |
| problems/       | Inversion count, range sum, counting smaller elements, curated problem list |

---

# 10. Pseudocode Template

Fenwick Tree structure:

function add(i, delta):
while i <= n:
fenw[i] += delta
i += LSB(i)

function prefix_sum(i):
result = 0
while i > 0:
result += fenw[i]
i -= LSB(i)
return result

function range_sum(l, r):
return prefix_sum(r) - prefix_sum(l-1)

---

# 11. Common Mistakes

1. Using 0-based indexing incorrectly
   BIT typically uses 1-based indexing internally.

2. Forgetting coordinate compression
   Required when values are large, negative, or non-contiguous.

3. Thinking BIT supports min/max queries
   It does not (without heavy modification).

4. Overlooking integer overflow
   Use long long for large sums (C++).

5. Confusing BIT with Segment Tree
   Fenwick Tree is simpler but supports fewer operations.

---

# 12. Interview Tips

Interviewers often ask:

1. Explain LSB logic and bit decomposition
2. Show how update/query reduce index by powers of two
3. Compare BIT and Segment Tree
4. Provide applications: inversion counting, K-th smallest
5. Explain why BIT is efficient
6. What operations are impossible with BIT?

Summaries to emphasize:

* BIT is optimal for prefix sums under dynamic updates
* BIT uses elegant binary arithmetic
* Construction can be optimized to O(n)
* BIT supports order statistics via binary lifting

---

# 13. Practice Problems

Beginner:

* LeetCode 307 – Range Sum Query Mutable

Intermediate:

* LeetCode 315 – Count Smaller Numbers After Self
* GFG – Fenwick Tree practice tasks

Advanced:

* LeetCode 493 – Reverse Pairs
* Codeforces BIT-heavy problems
* AtCoder advanced BIT tasks

---

# 14. Summary Table

| Concept              | Explanation                |
| -------------------- | -------------------------- |
| Binary decomposition | drives update/query        |
| Operations           | O(log n)                   |
| Memory               | O(n)                       |
| Variants             | standard, range-update, 2D |
| Use cases            | frequency, counts, queries |

---

