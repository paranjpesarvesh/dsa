# Algorithmic Complexities — Comprehensive Cheatsheet

This cheatsheet summarizes **time and space complexities** of core algorithms and data structures across categories.
Organized for quick recall during interviews and competitive programming.

---

## 1. Algorithm Growth Rates (Big-O Hierarchy)

From fastest to slowest:

```
O(1)
O(log n)
O(√n)
O(n)
O(n log n)
O(n^2)
O(n^3)
O(2^n)
O(n!)
```

---

## 2. Searching Algorithms

| Algorithm     | Time Avg | Time Worst | Space |
| ------------- | -------- | ---------- | ----- |
| Linear search | O(n)     | O(n)       | O(1)  |
| Binary search | O(log n) | O(log n)   | O(1)  |

Binary search requires sorted data.

---

## 3. Sorting Algorithms

| Algorithm      | Best       | Avg        | Worst      | Space    | Notes                           |
| -------------- | ---------- | ---------- | ---------- | -------- | ------------------------------- |
| Bubble Sort    | O(n)       | O(n^2)     | O(n^2)     | O(1)     | Rarely used                     |
| Selection Sort | O(n^2)     | O(n^2)     | O(n^2)     | O(1)     | Small memory                    |
| Insertion Sort | O(n)       | O(n^2)     | O(n^2)     | O(1)     | Good for small/partially sorted |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) | O(n)     | Stable                          |
| Quick Sort     | O(n log n) | O(n log n) | O(n^2)     | O(log n) | Cache friendly                  |
| Heap Sort      | O(n log n) | O(n log n) | O(n log n) | O(1)     | In-place                        |
| Counting Sort  | O(n+k)     | O(n+k)     | O(n+k)     | O(k)     | k = range                       |
| Radix Sort     | O(nk)      | O(nk)      | O(nk)      | O(n+k)   | digit-wise                      |

---

## 4. Data Structure Operations

### Arrays

| Operation       | Complexity     |
| --------------- | -------------- |
| Access          | O(1)           |
| Insert (middle) | O(n)           |
| Delete (middle) | O(n)           |
| Push/Pop end    | O(1) amortized |

### Linked List

| Operation | Complexity |
| --------- | ---------- |
| Insert    | O(1)       |
| Delete    | O(1)       |
| Search    | O(n)       |

### Stack & Queue

| Operation | Complexity |
| --------- | ---------- |
| Push      | O(1)       |
| Pop       | O(1)       |
| Front/Top | O(1)       |

### Hash Table

| Operation | Avg  | Worst |
| --------- | ---- | ----- |
| Insert    | O(1) | O(n)  |
| Search    | O(1) | O(n)  |
| Delete    | O(1) | O(n)  |

Worst case occurs under collisions (bad hashing).

---

## 5. Tree Algorithms

### Binary Trees

| Operation | Avg      | Worst |
| --------- | -------- | ----- |
| Insert    | O(log n) | O(n)  |
| Search    | O(log n) | O(n)  |
| Delete    | O(log n) | O(n)  |

Worst case: skewed tree.

### Balanced BST (AVL, Red-Black Trees)

| Operation | Guaranteed |
| --------- | ---------- |
| Insert    | O(log n)   |
| Search    | O(log n)   |
| Delete    | O(log n)   |

### Heap

| Operation      | Complexity |
| -------------- | ---------- |
| Insert         | O(log n)   |
| Delete Max/Min | O(log n)   |
| Heapify        | O(n)       |
| Build heap     | O(n)       |

---

## 6. Graph Algorithms

### BFS / DFS

| Operation | Complexity |
| --------- | ---------- |
| Traversal | O(V + E)   |

### Shortest Paths

| Algorithm              | Complexity | Graph Type               |
| ---------------------- | ---------- | ------------------------ |
| Dijkstra (binary heap) | O(E log V) | Weighted non-negative    |
| Dijkstra (adj matrix)  | O(V^2)     | Dense graph              |
| Bellman-Ford           | O(VE)      | Negative weights allowed |
| Floyd-Warshall         | O(V^3)     | All-pairs shortest path  |

### Minimum Spanning Tree

| Algorithm   | Complexity |
| ----------- | ---------- |
| Prim (heap) | O(E log V) |
| Kruskal     | O(E log V) |

### Topological Sort

| Method           | Complexity |
| ---------------- | ---------- |
| Kahn’s BFS / DFS | O(V + E)   |

---

## 7. Dynamic Programming

### Common DP Patterns

| Problem Type        | Complexity |
| ------------------- | ---------- |
| 1D DP (linear)      | O(n)       |
| 2D DP               | O(n*m)     |
| Knapsack DP         | O(n*W)     |
| LIS (DP)            | O(n^2)     |
| LIS (binary search) | O(n log n) |
| Edit Distance       | O(n*m)     |

---

## 8. String Algorithms

| Algorithm                 | Time       | Notes           |
| ------------------------- | ---------- | --------------- |
| KMP                       | O(n + m)   | Pattern search  |
| Z-Algorithm               | O(n + m)   | Pattern search  |
| Rabin-Karp                | O(n+m) avg | O(nm) worst     |
| Suffix Array (sort-based) | O(n log n) |                 |
| LCP (Kasai)               | O(n)       |                 |
| Trie Insert/Search        | O(L)       | L = word length |

---

## 9. Advanced Algorithms

### Max Flow

| Algorithm      | Complexity                             |
| -------------- | -------------------------------------- |
| Ford-Fulkerson | O(E * maxflow)                         |
| Edmonds-Karp   | O(VE^2)                                |
| Dinic          | O(E√V) or O(min(V^(2/3), E^(1/2)) * E) |

### Minimum Cost Flow

| Algorithm                | Complexity          |
| ------------------------ | ------------------- |
| Successive Shortest Path | O(flow * (E log V)) |
| Cycle Canceling          | O(VE^2)             |
| Primal-Dual              | O(V^2 E log V)      |

### Matching

| Algorithm                | Complexity |
| ------------------------ | ---------- |
| Bipartite Matching (DFS) | O(VE)      |
| Hopcroft-Karp            | O(√V * E)  |
| Hungarian (assignment)   | O(n^3)     |

---

## 10. Geometry

| Method                     | Complexity |
| -------------------------- | ---------- |
| Convex Hull (Graham)       | O(n log n) |
| Convex Hull (Jarvis March) | O(nh)      |
| Line Sweep                 | O(n log n) |

---

## 11. Bit Manipulation

| Task         | Complexity |
| ------------ | ---------- |
| Count bits   | O(log n)   |
| Most bit ops | O(1)       |

---

## 12. NP-Complete Problems

Examples:

* Traveling Salesman
* Knapsack variant (0/1)
* Partition
* SAT
* Independent set

General complexities:

```
Brute force: O(2^n)
DP with bitmask: O(n * 2^n)
```

---

## 13. Space Complexities Summary

| Structure   | Space    |
| ----------- | -------- |
| Array       | O(n)     |
| Linked list | O(n)     |
| Tree        | O(n)     |
| Graph       | O(V + E) |
| DP table    | O(n*m)   |

---

## 14. Cheat Diagram — Asymptotic Curves (ASCII)

```
Time
 |
 |           n^2       n^3
 |         n log n
 |      n
 |    √n
 |  log n
 |_
 |
 +----------------------------------> n
```

---

## 15. Interview Tips

* Always mention average vs worst case.
* Highlight space optimizations (e.g., DP → 1D).
* For graph problems, always recall:

  * adjacency list preferred for sparse graphs
  * adjacency matrix for dense graphs
* For sorting:

  * Merge sort stable, Quick sort cache-friendly
* Show tradeoffs, not just complexities.

---

## 16. Practice Problems

### LeetCode

* 322. Coin Change
* 72. Edit Distance
* 207. Course Schedule
* 200. Number of Islands
* 242. Valid Anagram
* 128. Longest Consecutive Sequence

### Codeforces

* Topics: math, dp, graphs
* Regular Div 2 → practice complexity estimations

### GFG

* DS and Algo complexity quizzes

---

## 17. Summary Table (All-in-One)

| Category        | Typical Complexity          |
| --------------- | --------------------------- |
| Search          | O(log n)                    |
| Sorting         | O(n log n)                  |
| Tree Ops        | O(log n)                    |
| Graph Traversal | O(V+E)                      |
| DP              | O(n*m)                      |
| String Matching | O(n+m)                      |
| Greedy          | Depends, usually O(n log n) |

---
