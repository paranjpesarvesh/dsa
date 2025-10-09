# DSA Interview 101 – Essential Guide

This cheatsheet is intended for **quick revision** before technical interviews. It focuses on **Data Structures & Algorithms (DSA)**, problem-solving patterns, and **interview tips**.

---

## 1. Core Interview Topics

**Data Structures:**

| Category               | Key Concepts                              | Typical Questions                                       |
| ---------------------- | ----------------------------------------- | ------------------------------------------------------- |
| Arrays & Strings       | Two pointers, sliding window, prefix sum  | Subarrays, anagrams, max/min sum, string manipulation   |
| Linked Lists           | Singly, Doubly, Cycle detection, Reversal | Merge lists, detect cycles, reorder, delete nodes       |
| Stack & Queue          | LIFO/FIFO, Monotonic stack, Deque         | Valid parentheses, min stack, sliding window max        |
| Hashing                | Hash tables, Sets, Maps                   | Two sum, frequency counts, anagrams                     |
| Trees                  | BST, Binary, N-ary, Tree traversal        | Lowest common ancestor, height, diameter, subtree check |
| Graphs                 | BFS, DFS, Topological Sort, Dijkstra      | Connected components, shortest paths, cycle detection   |
| Heaps / Priority Queue | Min/Max heap, custom comparator           | Kth largest/smallest, merge sorted arrays               |
| Dynamic Programming    | Memoization, Tabulation                   | Fibonacci, knapsack, LIS, DP on grids                   |

---

## 2. Problem-Solving Patterns

1. **Two Pointers**

   * Use: arrays, strings, sorted structures
   * Example: Find pairs with given sum

2. **Sliding Window**

   * Use: contiguous subarrays
   * Example: Max sum subarray of size k

3. **Fast & Slow Pointers**

   * Use: cycle detection in linked lists, arrays
   * Example: Detect cycle, find meeting point

4. **DFS/BFS**

   * Use: graphs, trees, grids
   * Example: Connected components, shortest path in unweighted graph

5. **Backtracking**

   * Use: permutations, combinations, subsets
   * Example: N-Queens, Word Search

6. **Divide & Conquer**

   * Use: sorted arrays, search, mergesort
   * Example: Binary search, merge sort

7. **Dynamic Programming**

   * Use: overlapping subproblems
   * Example: Fibonacci, knapsack, LIS

---

## 3. Common Interview Mistakes

* Not clarifying **constraints** and **input size**
* Ignoring **edge cases**: empty input, negative numbers, duplicates
* Overcomplicating **O(n^2) solutions** when O(n) exists
* Forgetting **data structure properties** (e.g., BST vs heap)
* Not **writing clean code** or explaining thought process

---

## 4. Big-O Complexity Reference

| Data Structure | Access   | Search   | Insert   | Delete   | Notes                       |
| -------------- | -------- | -------- | -------- | -------- | --------------------------- |
| Array          | O(1)     | O(n)     | O(n)     | O(n)     | Random access fast          |
| Linked List    | O(n)     | O(n)     | O(1)     | O(1)     | Sequential access           |
| Stack/Queue    | O(1)     | O(n)     | O(1)     | O(1)     | LIFO/FIFO                   |
| Hash Table     | –        | O(1)     | O(1)     | O(1)     | Average, collisions ignored |
| BST            | O(log n) | O(log n) | O(log n) | O(log n) | Balanced                    |
| Heap           | O(n)     | O(n)     | O(log n) | O(log n) | Priority queue              |

---

## 5. Key Interview Tips

* Always **ask clarifying questions**.
* Start with **brute force** → then optimize.
* Explain **your approach** clearly; don’t jump to code.
* Use **example walkthroughs** to validate logic.
* Mention **space-time trade-offs**.
* Be ready to **analyze complexity** for your solution.
* Practice **common patterns**, not only problems.

---

## 6. Quick Patterns Cheatsheet

| Pattern        | When to Use               | Example Problems                       |
| -------------- | ------------------------- | -------------------------------------- |
| Sliding Window | Subarrays, strings        | Max sum subarray, min window substring |
| Two Pointers   | Sorted arrays, strings    | Two sum, triplet sum                   |
| Hashing        | Lookups, frequency counts | Two sum, anagrams, subarray sum        |
| BFS/DFS        | Graphs, grids             | Number of islands, shortest path       |
| DP             | Overlapping subproblems   | Fibonacci, knapsack, LIS               |
| Heap           | Kth largest/smallest      | Merge k sorted lists, top K frequent   |

---

## 7. Practice Resources

* **LeetCode Patterns**: [https://leetcode.com/explore/learn/](https://leetcode.com/explore/learn/)
* **GeeksforGeeks**: [DSA Practice](https://www.geeksforgeeks.org/data-structures/)
* **Codeforces**: [Competitive programming](https://codeforces.com/)
* **Books**:

  * *Cracking the Coding Interview* – Gayle Laakmann McDowell
  * *Elements of Programming Interviews* – Aziz, Lee, Prakash

---

## 8. Quick Visual Guide

```
Problem Type        -> Recommended DS / Pattern
------------------------------------------------
Subarray / Substring -> Array + Sliding Window
Pairs / Triplets     -> Array + Two Pointers / Hashing
Sequence / LIS       -> DP / Binary Search
Graph Traversal      -> BFS / DFS
Priority-based       -> Heap / Greedy
Recursive / Combinations -> Backtracking
```

---

This guide provides a **compact, practical roadmap** for DSA interviews. Use it for **daily review** and to **identify weak areas** before facing coding rounds.

---
