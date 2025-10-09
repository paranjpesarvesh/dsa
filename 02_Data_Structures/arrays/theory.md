# Arrays – Theory

## 1. Introduction

An **array** is a **linear data structure** that stores elements in **contiguous memory locations**. Arrays are one of the most fundamental and widely used data structures in computer science due to their simplicity and efficiency.

### Key Features

* **Fixed-size or dynamic**: Static in languages like C/C++ and dynamic in Python (`list`) or Java (`ArrayList`).
* **Homogeneous elements**: All elements typically have the same data type.
* **Random access**: Accessing any element by its index takes **O(1)** time.
* **Contiguous memory allocation**: Makes it memory-efficient but resizing requires copying.

---

## 2. Mathematical Intuition

The memory address of an element in a 1D array can be calculated as:

$$
\text{Address}(arr[i]) = \text{base\_address} + i \times \text{sizeof(element)}
$$

This formula explains why **array indexing is O(1)**. The element can be directly accessed without traversing preceding elements.

---

## 3. Basic Operations

| Operation       | Description                | Time Complexity | Space Complexity |
| --------------- | -------------------------- | --------------- | ---------------- |
| Access by index | `arr[i]`                   | O(1)            | O(1)             |
| Search (linear) | Traverse to find element   | O(n)            | O(1)             |
| Insert at end   | Append element             | O(1) amortized  | O(1)             |
| Insert at index | Shift elements and insert  | O(n)            | O(1)             |
| Delete at index | Shift elements to fill gap | O(n)            | O(1)             |
| Traverse        | Visit all elements         | O(n)            | O(1)             |

---

### 3.1 Accessing Elements

```text
arr = [10, 20, 30, 40, 50]
arr[2] → 30
```

* **Time Complexity**: O(1)

---

### 3.2 Insertion

* **At the end (append)**:

  * Directly add element.
  * O(1) amortized in dynamic arrays.

* **At a specific index**:

  * Shift elements to the right.
  * Insert element.
  * O(n) worst-case.

```text
Before: [10, 20, 40, 50]
Insert 30 at index 2
After:  [10, 20, 30, 40, 50]
```

---

### 3.3 Deletion

* Remove element at a specific index.
* Shift subsequent elements left.

```text
Before: [10, 20, 30, 40, 50]
Delete index 2
After:  [10, 20, 40, 50]
```

* **Time Complexity**: O(n) worst-case

---

### 3.4 Searching

* **Linear search**: Traverse sequentially, O(n)
* **Binary search**: For sorted arrays, O(log n)

---

## 4. Array Variations

1. **Dynamic arrays**: Auto-resizing arrays (Python `list`, C++ `vector`).
2. **Multidimensional arrays**: 2D, 3D arrays.
3. **Sparse arrays**: Efficient storage for arrays with mostly default values.
4. **Circular arrays**: Useful for implementing queues efficiently.

---

## 5. Memory Layout Visualization

```text
Index: 0    1    2    3    4
Array: 10   20   30   40   50
Memory: contiguous block
```

---

## 6. Edge Cases

* Accessing index out-of-bounds → Runtime error.
* Insertion beyond capacity (static arrays) → Memory overflow.
* Deleting from an empty array → Error or no-op.

---

## 7. Interview Tips

* Common patterns using arrays:

  * Sliding window
  * Prefix sums
  * Two-pointer technique
  * Subarray/subsequence problems
* Clarify:

  * Indexing (0-based vs 1-based)
  * Array size constraints
  * Mutable vs immutable

---

## 8. Practice Problems

| Problem              | Platform      |
| -------------------- | ------------- |
| Maximum Subarray Sum | LeetCode #53  |
| Two Sum              | LeetCode #1   |
| Rotate Array         | LeetCode #189 |
| Trapping Rain Water  | LeetCode #42  |
| Merge Intervals      | LeetCode #56  |

---

## 9. Summary

* Arrays allow **O(1) random access**.
* Insertion/deletion in the middle may require **O(n) shifting**.
* Foundation for **stacks, queues, heaps, hash tables**, and many algorithmic techniques.

---

### Visual Aid – Shifting Operation

```text
Insert 15 at index 2:
Before: [10, 20, 30, 40, 50]
Shift:  [10, 20, _, 30, 40, 50]
After:  [10, 20, 15, 30, 40, 50]
```

---

This covers **array theory, operations, edge cases, and interview perspective** comprehensively.

