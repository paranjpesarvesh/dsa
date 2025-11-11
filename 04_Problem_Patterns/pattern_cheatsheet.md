# Problem-Solving Patterns Cheat Sheet

This document provides a **structured overview of the most important problem-solving patterns** used in coding interviews.
Patterns help identify the underlying technique needed to solve a problem efficiently and avoid brute force thinking.

Each pattern includes:

* When to use
* Core idea
* Typical data structures
* Complexity
* Sample problems

---

# 1. Sliding Window

**Use when:**
The problem asks for subarrays, substrings, or sequences with constraints such as size, sum, uniqueness, or max/min metrics.

**Core idea:**
Maintain a window (contiguous range) and expand/shrink based on conditions.

**Time Complexity:** O(n)

**Common Applications:**

* fixed window (size k)
* variable window (expand/shrink)
* longest/shortest substring
* at most / at least constraints

**Example Problems:**

* Longest Substring Without Repeating Characters (LeetCode 3)
* Minimum Window Substring (LeetCode 76)

---

# 2. Two Pointers

**Use when:**
You work with sorted arrays or need to minimize/maximize distances or sums.

**Core idea:**
Place two pointers at strategic positions and move them intelligently.

**Applications:**

* sorted arrays
* linked lists (fast/slow pointers)
* partitioning
* merging

**Time Complexity:** O(n)

**Example Problems:**

* 3Sum (LeetCode 15)
* Remove Duplicates from Sorted Array (LeetCode 26)

---

# 3. Fast & Slow Pointers (Cycle Detection)

**Use when:**
You need to detect loops or find midpoints in linked lists.

**Core idea:**
Two pointers moving at different speeds eventually meet if a cycle exists.

**Time Complexity:** O(n)

**Examples:**

* Linked List Cycle (LeetCode 141)

---

# 4. Merge Intervals

**Use when:**
Intervals overlap or need merging/processing in order.

**Core idea:**
Sort intervals by start time, merge overlaps.

**Time Complexity:** O(n log n)

**Examples:**

* Merge Intervals (LeetCode 56)
* Insert Interval (LeetCode 57)

---

# 5. Cyclic Sort

**Use when:**
Array elements lie in range 1..n or 0..n and you need missing/duplicate values.

**Core idea:**
Place elements at correct index via swapping.

**Time Complexity:** O(n)

**Examples:**

* Find All Missing Numbers (LeetCode 448)
* Find Duplicate Number (LeetCode 287)

---

# 6. In-Place Linked List Reversal

**Use when:**
You must reverse portions of a linked list or entire list.

**Core idea:**
Iteratively reverse next pointers.

**Time Complexity:** O(n)

**Example Problems:**

* Reverse Linked List (LeetCode 206)
* Reverse Nodes in k-Group (LeetCode 25)

---

# 7. Tree BFS

**Use when:**
Processing trees level-by-level, shortest path on unweighted graph.

**Core idea:**
Use queue to traverse levels.

**Applications:**

* level order
* zigzag traversal
* BFS on general graphs

---

# 8. Tree DFS

**Use when:**
You need to explore all paths, subtree values, recursive insights.

**Core idea:**
Depth-first traversal via recursion or stack.

**Applications:**

* preorder, inorder, postorder
* path problems
* tree diameter

---

# 9. Two Heaps Pattern

**Use when:**
Maintain median or two balanced groups of values.

**Core idea:**
Use max-heap + min-heap to split lower and upper halves.

**Examples:**

* Median from Data Stream (LeetCode 295)

---

# 10. Subsets / Backtracking

**Use when:**
Searching all combinations, subsets, permutations.

**Core idea:**
Build state recursively, explore choices and backtrack.

**Complexity:** exponential

**Examples:**

* Subsets (LeetCode 78)
* Permutations (LeetCode 46)

---

# 11. Modified Binary Search

**Use when:**
Searching rotated arrays, peaks, boundaries.

**Core idea:**
Binary search with custom conditions.

**Examples:**

* Search Rotated Sorted Array (LeetCode 33)
* Find Peak Element (LeetCode 162)

---

# 12. Bitwise XOR

**Use when:**
Bit manipulation problems, finding missing/unique numbers.

**Core idea:**
XOR cancels identical bits, ideal for pairing.

---

# 13. Top-K Elements

**Use when:**
Find top K smallest/largest or most frequent items.

**Core idea:**
Use heaps, quickselect, or bucket sorting.

---

# 14. K-Way Merge

**Use when:**
Merging sorted lists/arrays or processing streams.

**Core idea:**
Use min-heap to extract smallest next element.

---

# 15. Dynamic Programming Patterns

**Subpatterns include:**

* 0/1 knapsack
* unbounded knapsack
* longest increasing subsequence
* matrix DP
* dp on trees
* dp on bitmasks

---

# 16. Topological Sort

**Use when:**
Ordering tasks with dependencies on DAGs.

**Core idea:**
Use in-degree + queue (Kahn's algorithm) or DFS finishing order.

---

# 17. Greedy Algorithms

**Use when:**
Local optimal decisions lead to global optimal (validate correctly).

**Examples:**

* Activity selection
* Coin change (when canonical)

---

# 18. Graph Traversal (BFS/DFS)

**Use when:**
Shortest path, connectivity, counting components.

---

# 19. Union-Find (Disjoint Set Union)

**Use when:**
Finding components, cycle detection, connectedness under unions.

---

# 20. Trie Pattern

**Use when:**
Prefix matching, autocomplete, string dictionary problems.

---

# 21. Priority Queue Pattern

**Use when:**
Any problem requiring selection of best/worst element repeatedly.

---

# 22. Hashing Pattern

**Use when:**
Lookup, frequency counting, grouping, finding complements.

---

# 23. Matrix Traversal

**Use when:**
Grid-based BFS/DFS, boundary scanning, DP on grids.

---

# 24. Divide & Conquer

**Use when:**
Break problem into subproblems, solve recursively, combine results.

---

# 25. Prefix Sum

**Use when:**
Range queries, cumulative sums, subarray properties.

---

# Interview Tips Summary

* Always identify the correct pattern first
* Look for keywords:

  * "subarray" → sliding window
  * "sorted" → two pointers or binary search
  * "dependency" → topological sort
  * "k largest" → heap
  * "all combinations" → backtracking
  * "range queries" → prefix sums
* Write brute force first, then optimize
* Communicate tradeoffs
* Mention time/space complexity

---

# Suggested Practice Sets

### LeetCode

* Top 100 Liked
* Blind 75
* NeetCode patterns

### GFG

* Must-do DSA problems
* Graph + DP special sets

### Codeforces

* Div 2 A/B for speed
* Special graph + DP contests

---

This cheat sheet gives you a high-level map of problem-solving patterns.
Use it as a quick reference before jumping into solutions.

