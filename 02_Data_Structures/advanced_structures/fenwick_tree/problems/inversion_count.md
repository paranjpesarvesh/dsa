# Inversion Count using Fenwick Tree (Binary Indexed Tree)

This file belongs under:
02_Data_Structures → advanced_structures → fenwick_tree → problems → inversion_count.md

Hence the focus is the classical application of Fenwick Tree to count inversions efficiently.

---

# 1. Problem Definition

Given an array `A[]` of size `n`, an **inversion** is a pair `(i, j)` such that:

* `i < j`
* `A[i] > A[j]`

The task is to count how many such pairs exist.

Example:
A = [3, 1, 2]

Inversions:
(3,1), (3,2)

Answer = 2

---

# 2. Why Fenwick Tree Works for Inversion Count

Definition restated:
An element A[i] forms inversions with all elements to its right that are **smaller** than it.

The trick:

* Process array from right to left
* For each A[i], count how many elements smaller than A[i] have already been seen (to the right)
* Use Fenwick Tree for fast prefix counts

This requires **coordinate compression**, because values may be large or negative.

---

# 3. Mathematical Insight

Fenwick Tree stores frequencies of elements seen so far.

Let compressed(A[i]) = position of value in sorted unique list.

At each step (processing from right to left):

inversions += query(compressed(A[i]) - 1)

Because query(k) gives count of elements ≤ k.

Then update(compressed(A[i])) increments frequency.

---

# 4. Step-by-Step Reasoning

1. Coordinate compress A[] to range [1..M]
2. Initialize Fenwick Tree of size M
3. Initialize inversion_count = 0
4. Loop i from n-1 down to 0:

   * Let x = compressed(A[i])
   * Query count of smaller elements: prefix_sum(x - 1)
   * Add this to inversion_count
   * Add Fenwick update at x (marking A[i] as seen)
5. Return inversion_count

---

# 5. Pseudocode

compress array A to C

FenwickTree FT(size = max(C))

inversion_count = 0

for i from n-1 down to 0:
x = C[i]
inversion_count += FT.prefix_sum(x - 1)
FT.add(x, 1)

return inversion_count

---

# 6. ASCII Visualization

Array: [8, 4, 2, 1]

Compressed form: [4, 3, 2, 1]

Processing from right:

Step 1: at 1
No smaller elements → add freq(1)

Step 2: at 2
prefix_sum(1) = 1 inversion

Step 3: at 3
prefix_sum(2) = 2 inversions

Step 4: at 4
prefix_sum(3) = 3 inversions

Total = 1 + 2 + 3 = 6

Tree evolution example:

Index positions (compressed):
1  2  3  4
----------

1  1  1  1  ← frequencies accumulate as elements added

---

# 7. Time and Space Complexity

Complexity analysis:

| Operation              | Cost       |
| ---------------------- | ---------- |
| Coordinate Compression | O(n log n) |
| Fenwick Updates        | O(n log n) |
| Fenwick Queries        | O(n log n) |
| Total                  | O(n log n) |
| Space                  | O(n)       |

---

# 8. Variations

1. Count inversions modulo M
2. Count inversions in linked list using merge-sort or BIT
3. Count inversions in dynamic stream (Fenwick Tree + ordered map required)
4. Count inversions per index or per element

---

# 9. Edge Cases

1. Already sorted array → inversions = 0
2. Reverse sorted array → inversions = n(n-1)/2
3. All elements equal → inversions = 0
4. Negative numbers → requires compression
5. Very large values → requires compression
6. Duplicate values → must allow equal values in compression

---

# 10. Interview Tips

Interviewers often test:

* Inversion count using merge sort vs Fenwick Tree
* Understanding of prefix sums
* Need for coordinate compression
* Binary index decomposition (LSB trick)
* Why processing right-to-left is needed
* Comparison: BIT vs Segment Tree for frequency queries

Good points to mention:

* Fenwick Tree allows O(log n) dynamic prefix queries
* Very useful for counting smaller elements to the right

---

# 11. Practice Problems

LeetCode:

* 315. Count of Smaller Numbers After Self
* 493. Reverse Pairs
* 1649. Create Sorted Array through Instructions

Codeforces:

* EDU BIT section
* Problemsets involving inversion counting
* Typical Div2 C/D problems

GFG:

* Count inversions in an array
* Fenwick Tree problems

---

# 12. Summary Table

| Concept               | Insight                |
| --------------------- | ---------------------- |
| What is an inversion? | A[i] > A[j], i < j     |
| Why Fenwick Tree?     | Fast prefix counts     |
| Time complexity       | O(n log n)             |
| Space complexity      | O(n)                   |
| Key prerequisite      | Coordinate compression |

---
