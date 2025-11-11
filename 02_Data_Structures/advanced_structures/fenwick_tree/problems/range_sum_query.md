# Range Sum Query using Fenwick Tree (Binary Indexed Tree)

This file belongs under:
02_Data_Structures → advanced_structures → fenwick_tree → problems → range_sum_query.md
Therefore, we focus on how Fenwick Tree efficiently supports range sum queries under updates.

---

# 1. Problem Definition

Maintain an array `A[1..n]` supporting the following operations:

1. Update: `A[i] += delta`
2. Query: `sum(l..r)` = sum of elements from index `l` to `r`

We need to handle multiple operations efficiently.

---

# 2. Why Fenwick Tree?

A Fenwick Tree supports:

* Prefix sum query in O(log n)
* Point update in O(log n)

Thus range sum query can be computed using:

sum(l..r) = prefix_sum(r) − prefix_sum(l − 1)

---

# 3. Mathematical Intuition

Fenwick Tree stores partial sums and uses binary representation of indices.

Key identity:

Each index `i` covers a segment of length equal to the least significant bit (LSB) of `i`.

LSB(i) = i & -i

Fenwick Tree moves through binary decomposition of indices, making both update and query operations logarithmic.

---

# 4. Step-by-Step Reasoning

Operation 1: Update `A[i] += delta`

* Update all Fenwick nodes covering index `i`

Operation 2: Query `sum(l..r)`

* Compute prefix_sum(r)
* Compute prefix_sum(l − 1)
* Subtract to get desired range

---

# 5. Pseudocode

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

# 6. ASCII Visualization

Array index coverage example:

Index: 1  2  3  4  5  6  7  8

LSB values:
1  2  1  4  1  2  1  8

Fenwick nodes store:

i=1 covers [1]
i=2 covers [1..2]
i=3 covers [3]
i=4 covers [1..4]
i=5 covers [5]
i=6 covers [5..6]
i=7 covers [7]
i=8 covers [1..8]

Range sum query example:

sum(3..7) = prefix(7) − prefix(2)

prefix(7) path:
7 → 6 → 4 → 0

prefix(2) path:
2 → 0

---

# 7. Time and Space Complexity

| Operation    | Complexity |
| ------------ | ---------- |
| Point update | O(log n)   |
| Prefix sum   | O(log n)   |
| Range sum    | O(log n)   |
| Memory       | O(n)       |

---

# 8. Variations

1. Range update + point query (requires difference array trick)
2. Range update + range query (requires two Fenwick Trees)
3. Static array version (no updates, simple prefix array enough)
4. 2D Fenwick Tree extension for submatrix sum queries

---

# 9. Edge Cases

1. Query range fully out of bounds → return 0
2. l > r → return 0
3. Negative numbers → works fine
4. Value updates can be negative/positive
5. Must use 1-based indexing internally

---

# 10. Interview Tips

Common interview tests involve:

* Understanding binary lifting via LSB
* Showing how prefix sums produce range sums
* Updating nodes efficiently
* Comparing with Segment Tree
* Knowing when Fenwick Tree is preferable:

  * simpler
  * lower memory
  * only point update + range sum needed

Frequent follow-up questions:

* Can Fenwick Tree handle range updates? (Yes, with modifications)
* Can Fenwick Tree handle range min/max queries? (No)
* How to handle large values? (Use long long or Python int)

---

# 11. Practice Problems

LeetCode:

* 307. Range Sum Query – Mutable

Codeforces:

* EDU section on Fenwick Tree
* Many Div2 C/D problems

GFG:

* Fenwick Tree problems
* Range sum problems with update support

---

# 12. Summary Table

| Feature              | Description                   |
| -------------------- | ----------------------------- |
| Supports update      | O(log n)                      |
| Supports range query | O(log n)                      |
| Memory footprint     | O(n)                          |
| Use-case             | Dynamic arrays                |
| Does not support     | Range updates (basic version) |

---
