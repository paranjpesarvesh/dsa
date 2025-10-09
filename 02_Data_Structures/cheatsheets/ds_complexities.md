# Data Structures – Time & Space Complexities Cheatsheet

This cheatsheet summarizes **time and space complexities** of commonly used **data structures**. It’s designed as a quick reference for interviews, competitive programming, and implementation decisions.

---

## 1. Arrays

| Operation                 | Static Array | Dynamic Array  | Notes                                                 |
| ------------------------- | ------------ | -------------- | ----------------------------------------------------- |
| Access                    | O(1)         | O(1)           | Direct indexing                                       |
| Search (linear)           | O(n)         | O(n)           | Scan all elements                                     |
| Search (binary, sorted)   | O(log n)     | O(log n)       | Requires sorted array                                 |
| Insert at end             | O(n)         | Amortized O(1) | Dynamic array may resize                              |
| Insert at beginning/index | O(n)         | O(n)           | Requires shifting elements                            |
| Delete at end             | O(1)         | O(1)           | Simple truncation                                     |
| Delete at beginning/index | O(n)         | O(n)           | Requires shifting elements                            |
| Space                     | O(n)         | O(n)           | Extra space in dynamic arrays may be used temporarily |

**Key Notes**:

* Dynamic arrays **double capacity when full**, leading to amortized O(1) insert at the end.
* Use arrays for **random access** and **small, fixed-size datasets**.

---

## 2. Linked Lists

| Operation       | Singly Linked List | Doubly Linked List | Notes                                         |
| --------------- | ------------------ | ------------------ | --------------------------------------------- |
| Access by index | O(n)               | O(n)               | Sequential traversal required                 |
| Search          | O(n)               | O(n)               | Linear scan                                   |
| Insert at head  | O(1)               | O(1)               | Constant time insertion                       |
| Insert at tail  | O(n)               | O(1)               | Doubly linked lists can maintain tail pointer |
| Insert at index | O(n)               | O(n)               | Need to traverse to index                     |
| Delete head     | O(1)               | O(1)               | Constant time                                 |
| Delete tail     | O(n)               | O(1)               | Doubly linked lists can access prev pointer   |
| Space           | O(n)               | O(n)               | Extra pointer for doubly linked list          |

**Key Notes**:

* Prefer linked lists for **frequent insertions/deletions** in middle positions.
* Not suitable for random access.

---

## 3. Stack & Queue

| Operation      | Array-based | Linked List-based | Notes                         |
| -------------- | ----------- | ----------------- | ----------------------------- |
| Push / Enqueue | O(1)        | O(1)              | Constant time                 |
| Pop / Dequeue  | O(1)        | O(1)              | Constant time                 |
| Peek / Front   | O(1)        | O(1)              | Constant time                 |
| Space          | O(n)        | O(n)              | Depends on number of elements |

**Key Notes**:

* Stacks and queues are **linear data structures with restricted access**.
* Use linked list implementation when **dynamic sizing** is needed.

---

## 4. Hash Tables

| Operation | Average Case | Worst Case | Notes                                              |
| --------- | ------------ | ---------- | -------------------------------------------------- |
| Search    | O(1)         | O(n)       | Depends on collisions                              |
| Insert    | O(1)         | O(n)       | Collisions handled via chaining or open addressing |
| Delete    | O(1)         | O(n)       | Same as above                                      |
| Space     | O(n)         | O(n)       | Stores keys + values                               |

**Key Notes**:

* Use hash tables for **fast search, insert, delete**.
* Avoid in scenarios needing **ordered traversal** (use trees instead).

---

## 5. Trees

| Operation | Binary Search Tree (BST) | Balanced BST (AVL, Red-Black) | Notes                            |
| --------- | ------------------------ | ----------------------------- | -------------------------------- |
| Search    | O(h)                     | O(log n)                      | h = tree height                  |
| Insert    | O(h)                     | O(log n)                      | Maintain balanced property       |
| Delete    | O(h)                     | O(log n)                      | Requires rotations for balancing |
| Space     | O(n)                     | O(n)                          | Each node stores pointers        |

**Special Trees**:

* Segment Trees, Fenwick Trees (BIT), Trie, etc.
* Useful for **range queries, string manipulation, prefix sums**.

---

## 6. Graphs

| Representation   | Access Edge | Insert Edge | Space    |
| ---------------- | ----------- | ----------- | -------- |
| Adjacency Matrix | O(1)        | O(1)        | O(V²)    |
| Adjacency List   | O(V)        | O(1)        | O(V + E) |

**Notes**:

* Matrix is better for **dense graphs**.
* List is better for **sparse graphs**.

---

## 7. Cheat Table – Quick Summary

| DS          | Access        | Search        | Insert              | Delete        | Space |
| ----------- | ------------- | ------------- | ------------------- | ------------- | ----- |
| Array       | O(1)          | O(n)/O(log n) | O(n)/O(1 amortized) | O(n)/O(1)     | O(n)  |
| Linked List | O(n)          | O(n)          | O(1)                | O(1)          | O(n)  |
| Stack/Queue | O(1)          | O(n)          | O(1)                | O(1)          | O(n)  |
| Hash Table  | –             | O(1)/O(n)     | O(1)/O(n)           | O(1)/O(n)     | O(n)  |
| BST         | O(log n)/O(n) | O(log n)/O(n) | O(log n)/O(n)       | O(log n)/O(n) | O(n)  |

---

## 8. Interview Tips

* Always **clarify assumptions**: array size, dynamic vs static, sorted vs unsorted.
* Mention **amortized analysis** for dynamic arrays.
* For **hash tables**, discuss collision handling.
* Use **BSTs** for ordered data and range queries.
* Explain **trade-offs** between arrays and linked lists.

---

## 9. Practice Problems

| Problem               | Platform | Concept                         |
| --------------------- | -------- | ------------------------------- |
| Two Sum               | LeetCode | Arrays + Hash Map               |
| Merge Intervals       | GFG      | Arrays + Sorting                |
| Implement Stack/Queue | LeetCode | Array vs Linked List            |
| LRU Cache             | LeetCode | Hash Table + Doubly Linked List |
| Maximum Subarray      | LeetCode | Kadane's Algorithm              |

---

## 10. References

* CLRS – *Introduction to Algorithms*
* GeeksforGeeks – [Data Structure Time Complexity](https://www.geeksforgeeks.org/complexity-analysis-data-structures/)
* LeetCode Explore – [DSA Practice](https://leetcode.com/explore/learn/)

---

This cheatsheet is ideal for **fast review** before interviews and for **choosing the right data structure** for a given problem.

---
