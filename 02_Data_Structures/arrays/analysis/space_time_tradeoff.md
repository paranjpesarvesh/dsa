# 📄 Space-Time Trade-offs in Arrays

**Path Context:** `dsa/02_Data_Structures/arrays/analysis/space_time_tradeoff.md`
This document explains the **trade-offs between time complexity and memory usage** in array implementations, including **static arrays, dynamic arrays, and array alternatives**.

---

## 1. Introduction

In computer science, **space-time trade-off** refers to the compromise between **memory usage (space)** and **execution speed (time)**. Arrays, being fundamental data structures, are a prime example of this concept.

**Key idea:**

* Using **more memory** can reduce **execution time** (e.g., pre-computation, caching).
* Using **less memory** can increase **execution time** (e.g., repeated calculations, dynamic resizing).

---

## 2. Static vs Dynamic Arrays

### Static Array

```text
int arr[100];  // fixed size
```

* **Memory:** Fixed and contiguous.
* **Access:** O(1) by index.
* **Insertion/Deletion:** O(n) if not at the end.
* **Pros:** Minimal overhead, cache-friendly.
* **Cons:** Cannot resize; waste if allocated size > required size.

### Dynamic Array

```python
arr = []  # Python list
```

* **Memory:** Resizable; may allocate extra space for amortized growth.
* **Insertion at End:** Amortized O(1).
* **Access:** O(1).
* **Insertion/Deletion at Middle:** O(n).
* **Trade-off:** Extra memory for occasional resizing to save time in insertions.

**ASCII Illustration of Dynamic Array Doubling:**

```
Capacity: 4
Array: [1, 2, 3, 4]

Insert 5:
Allocate new array of size 8
Copy old elements: [1, 2, 3, 4, 5, _, _, _]
```

> **Observation:** Extra memory reduces the frequency of resizing operations (time saved).

---

## 3. Pre-computation vs On-demand Computation

### Prefix Sum Example

Given an array `arr`, computing range sums:

**Option 1: On-demand sum**

```text
sum(arr[l:r])  # O(n) each query
```

* **Space:** O(n) for the array
* **Time:** O(r-l) per query

**Option 2: Precompute prefix sums**

```text
prefix[i] = arr[0] + arr[1] + ... + arr[i]
range_sum = prefix[r] - prefix[l-1]  # O(1)
```

* **Space:** O(n) extra
* **Time:** O(1) per query
* **Trade-off:** Uses extra memory to save query time.

---

## 4. Sparse Arrays

* **Use-case:** Most elements are zero or default value.
* **Implementation:** Dictionary/hash map instead of contiguous array.
* **Memory:** Saves space.
* **Access Time:** O(1) average.
* **Trade-off:** Slightly slower than direct indexing due to hashing.

**ASCII Representation:**

```
Full Array:      [0, 0, 5, 0, 0, 0, 7]
Sparse Storage:  {2: 5, 6: 7}
```

---

## 5. Multidimensional Arrays

| Type               | Memory Usage                   | Access Time          |
| ------------------ | ------------------------------ | -------------------- |
| Row-major array    | Contiguous, O(n\*m)            | O(1)                 |
| Pointer-to-pointer | Non-contiguous, extra pointers | O(1) + pointer deref |

> **Observation:** Non-contiguous storage saves memory in some cases but can hurt cache locality (time).

---

## 6. Circular Arrays

* **Purpose:** Efficient queue implementation.
* **Memory:** Fixed size, avoids shifting elements.
* **Time:** O(1) for enqueue/dequeue operations.
* **Trade-off:** Slightly complex indexing arithmetic.

---

## 7. Cache-friendliness

Arrays benefit from **CPU cache locality**:

```
Contiguous memory access → faster iteration
Non-contiguous (linked list) → slower due to cache misses
```

> **Trade-off:** Using extra memory for contiguous allocation speeds up iteration.

---

## 8. Summary Table

| Strategy                  | Extra Memory | Time Benefit             | Example                   |
| ------------------------- | ------------ | ------------------------ | ------------------------- |
| Dynamic Array Doubling    | Yes          | Amortized O(1) insertion | `vector`, `list.append()` |
| Prefix Sum Precomputation | Yes          | O(1) range sum           | `prefix_sum` array        |
| Sparse Array (hashing)    | Saves memory | O(1) average access      | Sparse matrices           |
| Circular Array            | Fixed size   | O(1) enqueue/dequeue     | Queue implementation      |
| Row-major contiguous      | Fixed size   | Cache-friendly iteration | 2D array / matrix         |

---

## 9. Interview Tips

* Understand **when extra space reduces time** (prefix sums, memoization, hash maps).
* Recognize **trade-offs between static and dynamic arrays**.
* Be prepared to **analyze memory consumption** in addition to runtime.
* Common interview problems:

  * Prefix sum problems
  * Sliding window problems
  * Sparse array problems
  * Dynamic array resizing and amortized analysis

---

## 10. Practice Problems

| Problem                      | Source        | Concept              |
| ---------------------------- | ------------- | -------------------- |
| Range Sum Query              | LeetCode #303 | Prefix sum           |
| Dynamic Array Resize         | GFG           | Amortized analysis   |
| Sparse Matrix Multiplication | LeetCode #311 | Sparse array         |
| Circular Queue               | LeetCode #622 | Circular array       |
| Sliding Window Maximum       | LeetCode #239 | Space-time trade-off |

---

This document explains the **core space-time trade-offs in arrays**, providing guidance for **efficient implementation** and **interview preparation**.

