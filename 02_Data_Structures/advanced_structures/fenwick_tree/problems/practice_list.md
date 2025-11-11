# Fenwick Tree (Binary Indexed Tree) – Problem List

This file belongs under:
02_Data_Structures → advanced_structures → fenwick_tree → problems → problem_list.md
Hence this file should collect a categorized problem set involving Fenwick Trees, from beginner to advanced, including different BIT variants and applications.

---

# 1. Overview

Fenwick Tree is a versatile structure that helps solve problems requiring:

* prefix sums
* frequencies/counting smaller elements
* dynamic range queries
* order statistics
* inversion counting
* coordinate compression
* range updates
* range queries (with two BITs)

This list is divided by difficulty and Fenwick Tree technique used.

---

# 2. Beginner-Level Problems

These problems build foundational understanding of prefix sums and basic Fenwick operations.

### Counting / Frequency-based

1. Count occurrences in prefix
2. Maintain prefix sums under point updates
3. Dynamic array with update + query
4. Simple range sum queries

### Suggested online problems

* LeetCode 307 – Range Sum Query (Mutable)
* SPOJ: UPDATEIT
* GFG: Fenwick Tree introduction
* Codeforces EDU – Section on Fenwick Tree basics

---

# 3. Intermediate-Level Problems

These problems introduce practical applications with coordinate compression and event processing.

### Classic applications

1. Count inversions (Fenwick + compression)
2. Count smaller elements on the right
3. Count greater elements on the left
4. Track dynamic frequencies under updates

### 2D Fenwick Tree basics

1. Query sum of submatrix
2. Point update + 2D prefix sum

### Suggested online problems

* LeetCode 315 – Count of Smaller Numbers After Self
* LeetCode 493 – Reverse Pairs
* AtCoder: typical BIT problems
* Codeforces:

  * #1196F – K-th Not Divisible by N
  * #1579G – Hierarchy Queries

---

# 4. Advanced-Level Problems

These problems require deep understanding, combined structures, and optimizations.

### Advanced BIT use-cases

1. Range update + range query (using two BITs)
2. Multi-dimensional BIT (2D or 3D)
3. Order statistics using binary lifting
4. Process offline queries using Fenwick Tree
5. Sweeping algorithms (geometry)
6. Inversion count in permutations with updates
7. K-th smallest in prefix dynamically

### Advanced tasks

1. Track active segments dynamically
2. Maintain prefix maxima using BIT + coordinate compression
3. Counting number of increasing subsequences
4. Solve frequency-based queries offline (Mo’s + BIT variant)

### Suggested online problems

* Codeforces hard BIT problems
* LeetCode 1649 – Create Sorted Array through Instructions
* Hackerrank:

  * Median updates using BIT
* SPOJ:

  * Inversion counting tasks

---

# 5. Categorized Problem Types

Fenwick Tree problems can be categorized as follows:

## Category A: Prefix Sum Based

* Range sum queries
* Point updates
* Dynamic cumulative values

## Category B: Frequency-Based Queries

* Count smaller/larger elements
* Count elements in a range
* Frequency table reconstruction

## Category C: Order Statistics

* Find k-th smallest in prefix
* Maintain sorted structure efficiently

## Category D: Geometric Applications

* Sweep-line algorithms
* Counting intersections
* Rectangle queries (2D BIT)

## Category E: Offline Query Processing

* Sort queries/values
* Use BIT to progressively incorporate events

## Category F: Range Update Problems

* Add value to subarray
* Query value at point
* Range update + range query (using 2 BITs)

---

# 6. Important Fenwick Tree Techniques to Master

| Technique              | Explanation                       | Example Uses       |
| ---------------------- | --------------------------------- | ------------------ |
| Coordinate Compression | Map large values to small indices | inversion count    |
| Point Update           | Update single index               | dynamic array sums |
| Prefix Query           | sum(1..i)                         | cumulative sums    |
| Binary Lifting         | find-by-prefix                    | order statistics   |
| Difference Array Trick | for range updates                 | add delta to l..r  |
| 2 BIT Model            | range update + range query        | advanced problems  |
| Multidimensional BIT   | 2D/3D queries                     | geometry           |

---

# 7. Example Problems to Practice (Organized)

## Beginner

* Fenwick Tree construction
* Point update + prefix query
* Range sum queries

## Intermediate

* Inversion counting
* Find smaller elements to right
* Count number of elements <= k in subarray
* Offline event processing with BIT

## Advanced

* K-th smallest number queries
* 2D BIT queries
* Range update + range query (dual-BIT technique)
* Counting intersections in geometry
* Maintaining dynamic fenwick under inserts/deletes

---

# 8. Recommended Practice Progression

1. Learn the data structure
2. Solve prefix sum + point update problems
3. Solve frequency/count problems
4. Add coordinate compression
5. Solve inversion and smaller-elements problems
6. Practice BIT with binary lifting
7. Try 2D Fenwick Tree
8. Attempt range update + range query problems
9. Work through offline processing tasks
10. Explore competitive programming problems involving BIT

---

# 9. Additional Resources

| Resource                     | Description                        |
| ---------------------------- | ---------------------------------- |
| CP-Algorithms (Fenwick Tree) | Excellent guide with proofs        |
| Codeforces EDU BIT course    | Interactive learning with problems |
| TopCoder tutorials           | Covers BIT variants                |
| GeeksForGeeks                | Good beginner-level explanations   |
| AtCoder                      | High-quality BIT problems          |

---

# 10. Summary Table

| Difficulty   | Focus                         | Skills Learned                     |
| ------------ | ----------------------------- | ---------------------------------- |
| Beginner     | basic BIT operations          | prefix sums, point updates         |
| Intermediate | compression, order-statistics | counting, frequency manipulation   |
| Advanced     | 2D, dual-BIT, offline sweeps  | complex applications, optimization |

---
