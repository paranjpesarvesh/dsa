# Fenwick Tree (Binary Indexed Tree) Comparisons and Analysis

This file belongs under:
02_Data_Structures → advanced_structures → fenwick_tree → analysis → comparisons.md
Thus the focus is a detailed comparison of Fenwick Tree with similar data structures, including segment trees, prefix arrays, and other range query structures.

---

# 1. Overview

A **Fenwick Tree**, also known as a **Binary Indexed Tree (BIT)**, provides efficient support for:

* Prefix sum queries
* Point updates

Fenwick Trees are preferred when you need:

* Faster implementation than Segment Tree
* Lower memory footprint
* Logarithmic queries and updates

This document compares Fenwick Trees with:

* Prefix arrays
* Segment trees
* Difference arrays
* Balanced binary search trees (like ordered maps)
* Sparse tables

---

# 2. Mathematical Insight Behind Fenwick Tree

Fenwick Tree uses binary representation of indices.

Key principle:
Index `i` stores the sum of the range
`(i - LSB(i) + 1) to i`
where
`LSB(i)` = least significant bit of `i`.

Example:
For i = 12:

12 in binary = 1100
LSB(12) = 100 = 4
So node 12 contains the sum of elements:
[9, 10, 11, 12]

This property creates a compact hierarchical structure for fast merging.

---

# 3. Comparison with Prefix Sum Array

Prefix sum array supports:

* Query prefix sum in O(1)
* Update in O(n)

Fenwick Tree supports:

* Query prefix sum in O(log n)
* Update in O(log n)

Comparison table:

| Operation | Prefix Array | Fenwick Tree    |
| --------- | ------------ | --------------- |
| Query     | O(1)         | O(log n)        |
| Update    | O(n)         | O(log n)        |
| Memory    | O(n)         | O(n)            |
| Use-case  | Static array | Dynamic updates |

Conclusion: use Fenwick Tree when updates are frequent.

---

# 4. Comparison with Segment Tree

Segment tree supports:

* Range queries (sum, min, max, gcd)
* Range updates (lazy propagation)
* Custom merge operations

Fenwick Tree supports:

* Prefix sums
* Point updates

Comparison:

| Feature                      | Fenwick Tree  | Segment Tree     |
| ---------------------------- | ------------- | ---------------- |
| Point update                 | O(log n)      | O(log n)         |
| Prefix query                 | O(log n)      | O(log n)         |
| Range query (sum)            | O(log n)      | O(log n)         |
| Range update                 | Not supported | Supported        |
| Memory                       | O(n)          | O(4n)            |
| Implementation difficulty    | Easy          | Moderate/Complex |
| Supports multiple operations | Limited       | Yes              |

Conclusion: Fenwick Tree is simpler and lightweight but less powerful.

---

# 5. Comparison with Difference Array

Difference arrays allow:

* Efficient range updates
* Slow prefix queries

Comparison:

| Operation    | Difference Array | Fenwick Tree  |
| ------------ | ---------------- | ------------- |
| Range update | O(1)             | Not supported |
| Prefix query | O(n)             | O(log n)      |
| Point update | O(1)             | O(log n)      |

Difference array is useful when:

* Many updates
* Few queries

Fenwick Tree is better when there is a balance between updates and queries.

---

# 6. Comparison with Balanced BST (e.g., ordered maps)

Ordered maps (like C++ std::map):

* Insert/delete: O(log n)
* Query prefix (order statistics): O(log n) with augmentations

Fenwick Tree limitations:

* Cannot handle deletions dynamically (unless handled carefully)
* Uses fixed index ranges

Comparison:

| Feature                | Fenwick Tree | Balanced BST            |
| ---------------------- | ------------ | ----------------------- |
| Dynamic insert/delete  | No           | Yes                     |
| Fast updates           | Yes          | Yes                     |
| Prefix sums            | Yes          | Yes (with augmentation) |
| Memory                 | O(n)         | O(n)                    |
| Index-based operations | Yes          | Not direct              |

BSTs are more powerful but have higher implementation overhead for order statistics.

---

# 7. Comparison with Sparse Table

Sparse table supports:

* Static range queries
* O(1) query
* No updates

Fenwick Tree supports:

* Dynamic updates
* O(log n) queries

Comparison:

| Operation | Sparse Table  | Fenwick Tree |
| --------- | ------------- | ------------ |
| Query     | O(1)          | O(log n)     |
| Update    | Not supported | O(log n)     |
| Memory    | O(n log n)    | O(n)         |
| Use-case  | Static data   | Dynamic data |

---

# 8. Summary Tables

## Capability Matrix

| Feature       | Fenwick | Segment Tree | Prefix Array | Diff Array | BST  | Sparse Table |
| ------------- | ------- | ------------ | ------------ | ---------- | ---- | ------------ |
| Point Updates | Yes     | Yes          | No           | Yes        | Yes  | No           |
| Range Query   | Yes     | Yes          | Yes          | No         | Yes  | Yes          |
| Range Update  | No      | Yes          | No           | Yes        | No   | No           |
| Memory        | O(n)    | O(n)         | O(n)         | O(n)       | O(n) | O(n log n)   |
| Difficulty    | Medium  | Higher       | Low          | Low        | High | Medium       |

## When to Use Fenwick Tree

Use BIT when:

* You need prefix sums
* Data changes frequently
* Memory must be efficient
* Implementation time matters

---

# 9. Visual Comparison: Operations vs Features

Simple ASCII chart:

Fenwick Tree:
[Log Query]
[Log Update]
[Low Memory]
[Static range updates? No]

Segment Tree:
[Log Query]
[Log Update]
[Supports range updates]
[Higher memory]

Prefix Array:
[O(1) Query]
[O(n) Update]

---

# 10. Interview Tips

Common interview themes related to Fenwick Trees:

1. Implement BIT with 1-based indexing
2. Explain binary trick behind LSB computation
3. Derive complexities carefully
4. Know when Segment Tree is better
5. Be able to compute next index formula:
   i += LSB(i)
6. Be able to compute parent index formula:
   i -= LSB(i)

Common questions asked:

* Why does BIT work?
* How does binary representation determine ranges?
* Compare Fenwick and Segment Tree
* When BIT fails (range updates, range minima)

---

# 11. Practice Problems

LeetCode:

* 307. Range Sum Query – Mutable
* 315. Count of Smaller Numbers After Self
* 493. Reverse Pairs

Codeforces:

* EDU Fenwick Tree section
* Problems labeled "fenwick" or "bit"

GFG:

* Fenwick Tree implementation
* Range Sum queries

---

# 12. Final Notes

Fenwick Tree is the right choice when:

* Updates and queries both matter
* Range updates are not needed
* You want a compact, easy-to-code data structure
* Graph or RMQ operations are not required
