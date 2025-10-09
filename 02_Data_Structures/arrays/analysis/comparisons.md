# 📄 Comparisons of Array Implementations and Alternatives

**Path Context:** `dsa/02_Data_Structures/arrays/analysis/comparisons.md`
This document focuses on **analyzing arrays**, their **variations**, **alternatives**, and **practical trade-offs** in different scenarios.

---

## 1. Introduction

Arrays are one of the **fundamental data structures** in computer science. They store elements **contiguously in memory**, allowing **O(1) access by index**. However, arrays come in multiple flavors, and their efficiency depends on the **operations we perform**.

**Goal of this document:**
Compare arrays with other data structures such as **linked lists, dynamic arrays, hash tables, and trees**, focusing on **time-space trade-offs** and **use cases**.

---

## 2. Static vs Dynamic Arrays

| Feature            | Static Array                   | Dynamic Array (e.g., Python `list`, C++ `vector`) |
| ------------------ | ------------------------------ | ------------------------------------------------- |
| Memory Allocation  | Fixed at compile/runtime start | Resizable at runtime                              |
| Access             | O(1)                           | O(1)                                              |
| Insertion/Deletion | O(n)                           | Amortized O(1) at the end, O(n) at middle/start   |
| Memory Overhead    | Minimal                        | Extra memory for resizing                         |
| Example            | `int arr[100]`                 | `vector<int> v;` or `list.append()`               |

**Intuition:**
Dynamic arrays trade extra space for **flexibility**. They **double in size** when capacity is exceeded, giving amortized O(1) insertion at the end.

---

## 3. Arrays vs Linked Lists

| Operation          | Array      | Singly Linked List | Doubly Linked List |
| ------------------ | ---------- | ------------------ | ------------------ |
| Access by Index    | O(1)       | O(n)               | O(n)               |
| Insertion at Head  | O(n)       | O(1)               | O(1)               |
| Insertion at Tail  | O(1)\*     | O(n)               | O(1)               |
| Deletion from Head | O(n)       | O(1)               | O(1)               |
| Deletion from Tail | O(1)\*     | O(n)               | O(1)               |
| Memory Usage       | Contiguous | Extra pointers     | Extra pointers     |

\*Assuming dynamic array amortization for append.

**Key Takeaway:** Arrays excel in **random access**, linked lists excel in **insertions/deletions**.

---

## 4. Arrays vs Hash Tables

| Operation       | Array       | Hash Table       |
| --------------- | ----------- | ---------------- |
| Lookup by Value | O(n)        | O(1) avg         |
| Insertion       | O(1) at end | O(1) avg         |
| Deletion        | O(n)        | O(1) avg         |
| Memory Usage    | Compact     | Larger (buckets) |

**Intuition:**
Arrays are great for **ordered storage**, hash tables are for **fast lookup and uniqueness checks**.

---

## 5. Arrays vs Trees

| Operation         | Array | Binary Search Tree | Balanced BST (AVL/Red-Black) |
| ----------------- | ----- | ------------------ | ---------------------------- |
| Search            | O(n)  | O(log n) avg       | O(log n)                     |
| Insertion         | O(n)  | O(log n) avg       | O(log n)                     |
| Deletion          | O(n)  | O(log n) avg       | O(log n)                     |
| Ordered Iteration | O(n)  | O(n)               | O(n)                         |

**Use case:**
Arrays are suitable when **indices matter** and data is **static or mostly static**. Trees are better for **dynamic sorted data**.

---

## 6. Variations of Arrays

1. **Multidimensional Arrays**

   * E.g., matrices: `int matrix[n][m]`
   * Memory: contiguous for row-major order
   * Random access still O(1)
2. **Sparse Arrays**

   * Use **hash maps** or **coordinate lists** to save space
3. **Circular Arrays**

   * Efficient **queue implementation** without shifting
4. **Bit Arrays**

   * Space-efficient boolean storage

---

## 7. Practical Considerations

* **Cache-friendliness:** Arrays are **contiguous**, benefiting from **CPU caching**.
* **Resizing cost:** Dynamic arrays may incur **copying overhead**.
* **Insert/Delete frequency:** Linked lists outperform arrays in **frequent modifications**.
* **Memory constraints:** Arrays require **contiguous memory**, which may be limiting for large datasets.

---

## 8. ASCII Illustration

**Dynamic Array Doubling Example:**

```
Capacity: 4
Array: [1, 2, 3, 4]

Insert 5:
Allocate new array of size 8
Copy old elements: [1, 2, 3, 4, 5, _, _, _]
```

**Array vs Linked List Memory Layout:**

```
Array (contiguous):
+----+----+----+----+
| 1  | 2  | 3  | 4  |
+----+----+----+----+

Linked List (pointers):
[1|*] -> [2|*] -> [3|*] -> [4|NULL]
```

---

## 9. Interview Tips

* Arrays are frequently used for **sliding window**, **prefix sums**, **matrix manipulation**.
* Know when to **switch to linked list or hash table** for efficiency.
* Be able to analyze **amortized cost** of dynamic arrays.
* Multidimensional arrays often appear in **DP** and **graph adjacency matrices**.

---

## 10. Practice Problems

| Problem          | Source        | Type                         |
| ---------------- | ------------- | ---------------------------- |
| Two Sum          | LeetCode #1   | Array lookup                 |
| Maximum Subarray | LeetCode #53  | Prefix sum / Kadane          |
| Rotate Array     | LeetCode #189 | In-place rotation            |
| Merge Intervals  | LeetCode #56  | Sorting + array manipulation |
| 2D Matrix Search | LeetCode #74  | Multidimensional array       |

---

## 11. Summary Table of Time Complexities

| Operation        | Array      | Linked List | Hash Table | BST      |
| ---------------- | ---------- | ----------- | ---------- | -------- |
| Access by Index  | O(1)       | O(n)        | N/A        | O(log n) |
| Search by Value  | O(n)       | O(n)        | O(1) avg   | O(log n) |
| Insert at End    | O(1) amort | O(n)        | O(1) avg   | O(log n) |
| Insert at Middle | O(n)       | O(1)        | N/A        | O(log n) |
| Delete at Middle | O(n)       | O(1)        | N/A        | O(log n) |

---
