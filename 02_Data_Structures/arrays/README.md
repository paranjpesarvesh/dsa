# Arrays – Theory

## 1. Introduction

An **array** is a **linear data structure** that stores elements in a **contiguous block of memory**. Each element can be accessed directly using its **index**, making arrays **indexable and efficient** for many operations.

### Key Characteristics

* **Fixed-size (static)** in languages like C/C++ or **dynamic** in Python (`list`).
* **Elements of the same type** (for low-level languages like C/C++).
* **Random access**: Accessing an element at index `i` takes **O(1)** time.
* Memory is allocated **contiguously**.

---

## 2. Mathematical Intuition

* If `arr` is an array starting at memory address `base`, and each element occupies `sizeof(element)` bytes:

$$
\text{Address of } arr[i] = base + i \times \text{sizeof(element)}
$$

* This explains **constant-time access** for arrays.

---

## 3. Basic Operations

| Operation       | Description                       | Complexity     |
| --------------- | --------------------------------- | -------------- |
| Access by index | `arr[i]`                          | O(1)           |
| Search (linear) | Traverse array to find an element | O(n)           |
| Insert at end   | Append element                    | O(1) amortized |
| Insert at index | Shift elements to make space      | O(n)           |
| Delete at index | Shift elements to fill gap        | O(n)           |
| Traverse        | Visit all elements                | O(n)           |

---

### 3.1 Accessing Elements

```text
arr = [10, 20, 30, 40, 50]
arr[2] → 30
```

* **Time complexity**: O(1)

---

### 3.2 Insertion

* **At end (append)**:

  * Add element directly at `arr[size]`.
  * **O(1) amortized**.

* **At index**:

  * Shift elements to the right.
  * Insert element.
  * **O(n) worst case**.

```text
Before: [10, 20, 40, 50]
Insert 30 at index 2
After:  [10, 20, 30, 40, 50]
```

---

### 3.3 Deletion

* Remove element at index.
* Shift all subsequent elements to fill the gap.

```text
Before: [10, 20, 30, 40, 50]
Delete index 2
After:  [10, 20, 40, 50]
```

* **Time complexity**: O(n) worst case

---

### 3.4 Searching

* **Linear search**:

  * Check each element sequentially.
  * Complexity: O(n)

* **Binary search** (for sorted arrays):

  * Divide and conquer approach.
  * Complexity: O(log n)

---

## 4. Variations of Arrays

1. **Dynamic arrays**: Resize automatically when capacity is exceeded (Python `list`, C++ `vector`).
2. **Multidimensional arrays**: Store data in 2D, 3D, or higher dimensions.
3. **Sparse arrays**: Efficient storage for arrays with many default values.
4. **Circular arrays**: Used in queues to save memory and improve efficiency.

---

## 5. Visual Representation

```text
Index: 0   1   2   3   4
Array: 10  20  30  40  50
Memory: contiguous block
```

---

## 6. Edge Cases

* Accessing index out of bounds → Runtime error.
* Insertion beyond capacity (for static arrays) → Memory overflow.
* Deletion in empty array → Error / no operation.

---

## 7. Interview Tips

* Arrays are frequently used in **coding interviews** (FAANG/GATE):

  * Sliding window problems
  * Prefix sums
  * Two-pointer technique
  * Subarray/subsequence problems
* Always clarify:

  * Array size
  * Indexing (0-based or 1-based)
  * Mutable vs immutable

---

## 8. Practice Problems

| Problem              | Platform      |
| -------------------- | ------------- |
| Maximum Subarray Sum | LeetCode #53  |
| 2-Sum Problem        | LeetCode #1   |
| Rotate Array         | LeetCode #189 |
| Trapping Rain Water  | LeetCode #42  |
| Merge Intervals      | LeetCode #56  |

---

## 9. Summary

* Arrays provide **O(1) random access**.
* Insertion/deletion in the middle may require **shifting elements**.
* Understanding arrays is foundational for **more advanced data structures** like **linked lists, stacks, queues, and hash tables**.

---
