# Data Structures Applications Cheat Sheet

## Overview

This cheat sheet provides a **concise yet comprehensive reference** for common data structures and their real-world and algorithmic applications. It is designed to help **interview preparation**, **competitive programming**, and quick review before exams like **GATE**, **FAANG interviews**, or coding contests.

---

## 1. Arrays

### Key Applications

* **Searching & Sorting**

  * Binary Search, Two Pointers, Sliding Window
  * Example: Find duplicates, subarrays with sum k

* **Prefix/Suffix Problems**

  * Prefix sum, difference arrays, cumulative products

* **Matrix Operations**

  * Rotations, spiral traversals, submatrix sum queries

### Notes

* Arrays provide **O(1) access**, but **insertion/deletion** in the middle is O(n)
* Often combined with **hashing** for faster search problems

### Example Problems

| Problem              | Platform |
| -------------------- | -------- |
| Two Sum              | LeetCode |
| Maximum Subarray Sum | LeetCode |
| Rotate Array         | GFG      |

---

## 2. Linked Lists

### Key Applications

* **Dynamic Memory Management**

  * Efficient insertion/deletion at arbitrary positions

* **Stacks/Queues Implementation**

  * Linked lists are used to implement these when size is dynamic

* **Complex Operations**

  * Detect cycle (Floyd’s Algorithm), Merge k-sorted lists, Reverse sublist

### Example Problems

| Problem              | Platform |
| -------------------- | -------- |
| Reverse Linked List  | LeetCode |
| Detect Cycle         | GFG      |
| Merge K Sorted Lists | LeetCode |

---

## 3. Stacks & Queues

### Stack Applications

* Expression parsing: **Infix → Postfix**, evaluate postfix
* Undo/Redo functionality in editors
* DFS traversal in graphs

### Queue Applications

* **BFS traversal in graphs**
* CPU scheduling, task scheduling
* Sliding window problems using **deque**

### Notes

* Stacks: LIFO
* Queues: FIFO
* Priority Queue (Heap): Retrieval of max/min efficiently

---

## 4. Hash Tables (Maps & Sets)

### Key Applications

* Count frequency of elements
* Remove duplicates
* Detect cycles or repeated patterns
* Implement caches (LRU cache)
* Quick lookup problems

### Notes

* Average O(1) lookup/insertion/deletion
* Collisions can affect worst-case performance

### Example Problems

| Problem                      | Platform |
| ---------------------------- | -------- |
| Two Sum                      | LeetCode |
| Subarray Sum Equals K        | LeetCode |
| Longest Consecutive Sequence | LeetCode |

---

## 5. Trees

### Binary Search Trees (BST)

* Fast search, insert, delete (O(log n) on balanced BST)
* Range queries (min, max, kth smallest)

### Heap

* Priority queue implementation
* Top-k problems
* Interval merging, scheduling

### Trie

* Auto-completion, spell check, prefix search
* Efficient string set representation

### Segment Tree / Fenwick Tree

* Range sum, min/max queries in O(log n)
* Efficient updates

### Example Problems

| Problem         | Platform |
| --------------- | -------- |
| LCA of BST      | LeetCode |
| Range Sum Query | LeetCode |
| Word Search II  | LeetCode |

---

## 6. Graphs

### Key Applications

* **Path finding**: BFS, DFS, Dijkstra, Bellman-Ford
* **Connectivity**: Connected components, Union-Find (Disjoint Set)
* **MST (Minimum Spanning Tree)**: Kruskal, Prim
* **Cycle detection**, Topological sorting

### Notes

* Represented as adjacency list or matrix
* DFS/BFS complexity: O(V + E)

### Example Problems

| Problem                     | Platform |
| --------------------------- | -------- |
| Number of Islands           | LeetCode |
| Kruskal MST                 | GFG      |
| Course Schedule (Topo Sort) | LeetCode |

---

## 7. Disjoint Set (Union-Find)

### Key Applications

* Network connectivity
* Cycle detection in undirected graphs
* Kruskal’s algorithm for MST
* Accounts merge problems

### Notes

* Optimize with **union by rank** and **path compression**
* Nearly O(1) amortized operations

---

## 8. Heaps / Priority Queues

### Key Applications

* Top-k elements
* Event simulation
* Median finding using two heaps
* Dijkstra's shortest path algorithm

---

## 9. Advanced Structures Cheat

| Structure    | Key Application                    |
| ------------ | ---------------------------------- |
| Fenwick Tree | Prefix sums, range queries         |
| Segment Tree | Range sum/min/max with updates     |
| Trie         | Prefix search, auto-completion     |
| Disjoint Set | Connectivity, MST, cycle detection |
| Heap         | Priority queues, median tracking   |

---

## 10. Tips for Interviews

* **Know strengths of each DS**
* **Ask clarifying questions** before choosing a DS
* **Think in terms of operations complexity**: search, insert, delete
* **Use problem patterns**: sliding window, two pointers, prefix sums
* **Edge cases**: empty structures, duplicates, large input sizes

---

## 11. Practice Problems (Curated)

* Arrays: Two Sum, Maximum Subarray, Rotate Array (LeetCode)
* Linked Lists: Reverse List, Detect Cycle, Merge K Lists
* Trees: LCA, Range Sum Queries, Word Search II
* Graphs: Course Schedule, Kruskal MST, Number of Islands
* Disjoint Set: Accounts Merge, Redundant Connection (LeetCode)

---

## 12. References

* [LeetCode](https://leetcode.com/)
* [GeeksforGeeks](https://www.geeksforgeeks.org/)
* [Codeforces](https://codeforces.com/)
* CLRS – Introduction to Algorithms

---

This **cheatsheet** is meant for quick revision and cross-referencing when deciding which data structure fits a problem.

---
