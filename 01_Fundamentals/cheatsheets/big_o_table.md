#  Big-O Complexity Cheatsheet

Big-O notation describes the **growth rate of an algorithm’s running time or memory usage** as the input size increases. This table acts as a quick reference for choosing or analyzing algorithms in interviews, contests, and exams (like **FAANG** or **GATE**).

---

##  Common Complexity Classes

| Complexity     | Name              | Typical Examples                               |
| -------------- | ----------------- | ---------------------------------------------- |
| **O(1)**       | Constant time     | Array index access, hash table lookup          |
| **O(log n)**   | Logarithmic time  | Binary search, tree operations (balanced BST)  |
| **O(n)**       | Linear time       | Linear search, traversing array/linked list    |
| **O(n log n)** | Linearithmic time | Merge sort, Quick sort (average), Heap sort    |
| **O(n²)**      | Quadratic time    | Bubble sort, Selection sort, Insertion sort    |
| **O(n³)**      | Cubic time        | Floyd–Warshall, naive matrix multiplication    |
| **O(2ⁿ)**      | Exponential time  | Subset generation, naive recursion (Fibonacci) |
| **O(n!)**      | Factorial time    | Traveling Salesman brute force, permutations   |

---

##  Array Operations

| Operation                   | Average Case | Worst Case |
| --------------------------- | ------------ | ---------- |
| Access by index             | O(1)         | O(1)       |
| Search (unsorted)           | O(n)         | O(n)       |
| Search (sorted, binary)     | O(log n)     | O(log n)   |
| Insert (end, dynamic array) | O(1)\*       | O(n)       |
| Delete (by value)           | O(n)         | O(n)       |

 *Amortized O(1) for dynamic arrays when resizing occasionally.*

---

##  Linked List Operations

| Operation      | Singly LL | Doubly LL |
| -------------- | --------- | --------- |
| Access (index) | O(n)      | O(n)      |
| Insert (head)  | O(1)      | O(1)      |
| Insert (tail)  | O(n)      | O(1)      |
| Delete (head)  | O(1)      | O(1)      |
| Delete (tail)  | O(n)      | O(1)      |
| Search         | O(n)      | O(n)      |

---

##  Stack & Queue

| Operation       | Complexity |
| --------------- | ---------- |
| Push/Enqueue    | O(1)       |
| Pop/Dequeue     | O(1)       |
| Peek/Front/Rear | O(1)       |
| Search          | O(n)       |

---

##  Trees

| Operation    | Balanced BST (AVL, Red-Black) | Unbalanced BST | Heap            |
| ------------ | ----------------------------- | -------------- | --------------- |
| Search       | O(log n)                      | O(n)           | N/A             |
| Insert       | O(log n)                      | O(n)           | O(log n)        |
| Delete       | O(log n)                      | O(n)           | O(log n)        |
| Find Min/Max | O(log n)                      | O(n)           | O(1) (heap top) |

---

##  Hash Tables

| Operation | Average Case | Worst Case |
| --------- | ------------ | ---------- |
| Insert    | O(1)         | O(n)       |
| Search    | O(1)         | O(n)       |
| Delete    | O(1)         | O(n)       |

 Worst case happens due to poor hash function or extreme collisions.

---

##  Graph Algorithms

| Algorithm               | Complexity |
| ----------------------- | ---------- |
| BFS / DFS (adj. list)   | O(V + E)   |
| BFS / DFS (adj. matrix) | O(V²)      |
| Dijkstra (Min-Heap)     | O(E log V) |
| Bellman–Ford            | O(VE)      |
| Floyd–Warshall          | O(V³)      |
| Kruskal (MST)           | O(E log V) |
| Prim (MST, heap)        | O(E log V) |
| Topological Sort        | O(V + E)   |

---

##  Sorting Algorithms

| Algorithm      | Best       | Average    | Worst      | Space    | Stable |
| -------------- | ---------- | ---------- | ---------- | -------- | ------ |
| Bubble Sort    | O(n)       | O(n²)      | O(n²)      | O(1)     | Yes    |
| Insertion Sort | O(n)       | O(n²)      | O(n²)      | O(1)     | Yes    |
| Selection Sort | O(n²)      | O(n²)      | O(n²)      | O(1)     | No     |
| Merge Sort     | O(n log n) | O(n log n) | O(n log n) | O(n)     | Yes    |
| Quick Sort     | O(n log n) | O(n log n) | O(n²)      | O(log n) | No     |
| Heap Sort      | O(n log n) | O(n log n) | O(n log n) | O(1)     | No     |
| Counting Sort  | O(n + k)   | O(n + k)   | O(n + k)   | O(k)     | Yes    |
| Radix Sort     | O(nk)      | O(nk)      | O(nk)      | O(n + k) | Yes    |

---

##  Interview Tips

*  **FAANG style**: Often ask complexity trade-offs (e.g., why use HashMap vs BST?). Be ready to justify choices.
*  **GATE exams**: Expect recurrence relations, Master Theorem questions, and complexity derivations.
*  Always mention both **average** and **worst-case** complexities in interviews.
*  Practical tip: When asked to “optimize,” think **hashing (O(1))**, **sorting + binary search (O(n log n))**, or **sliding window/two pointers (O(n))**.

---

##  Practice Problems

* [Big-O Practice (Khan Academy)](https://www.khanacademy.org/computing/computer-science/algorithms)
* [GFG: Time Complexity Set 1–4](https://www.geeksforgeeks.org/analysis-of-algorithms-set-1-asymptotic-analysis/)
* [LeetCode Discuss: Algorithm Complexity Patterns](https://leetcode.com/discuss/)
* GATE PYQs (1990–2025): Complexity & Recurrence questions

---

