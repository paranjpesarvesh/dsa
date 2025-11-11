# Max Heap — Theory

A **Max Heap** is a complete binary tree where each node is **greater than or equal to** its children. This structure ensures that the **maximum** element is always at the **root**.

Heaps are fundamental in implementing priority queues and are used in many classic algorithms including heap sort, Dijkstra’s algorithm, and scheduling systems.

---

## 1. Definition and Properties

A Max Heap satisfies two essential properties:

### 1. Heap Order Property

For every node `i`:

```
value(parent(i)) >= value(i)
```

### 2. Structural Property

The heap is a **complete binary tree**:

* All levels except possibly the last are completely full.
* The last level is filled from **left to right**.

Heaps are most commonly stored in **arrays**, not pointers.

---

## 2. Array Representation

If the array is 0-indexed:

```
parent(i) = (i - 1) // 2
left(i)   = 2*i + 1
right(i)  = 2*i + 2
```

Example:

```
Heap in array: [50, 30, 40, 10, 5, 20]

             50
          /      \
        30        40
      /   \      /
    10     5    20
```

---

## 3. Core Operations (Detailed)

### Insert (Push)

Steps:

1. Insert element at last index.
2. Perform **sift up**:

   * compare with parent
   * swap if child > parent
   * continue till root OR no violations

### Extract Max (Pop)

Steps:

1. Replace root with last element.
2. Delete last element.
3. Perform **sift down**:

   * compare parent with children
   * swap parent with larger child
   * continue till heap property satisfied

### Peek / Get Max

Return the root value.

### Build Heap (Heapify)

Heapify from bottom-up:

```
for i = n/2 - 1 down to 0:
    sift_down(i)
```

This works because nodes in the second half are leaves.

---

## 4. Mathematical Intuition

* Height of heap = O(log n)
* Insert & extract-max bubble up/down at most "height" levels
* Build Heap is O(n) because:

  * lower nodes cost less work
  * cumulative total sums to linear time

---

## 5. Pseudocode

### Sift Up

```
function sift_up(i):
    while i > 0:
        p = parent(i)
        if A[p] >= A[i]:
            break
        swap(A[p], A[i])
        i = p
```

### Sift Down

```
function sift_down(i):
    while left(i) < n:
        j = left(i)
        if right(i) < n and A[right(i)] > A[j]:
            j = right(i)
        if A[i] >= A[j]:
            break
        swap(A[i], A[j])
        i = j
```

### Insert

```
append x to A
sift_up(last index)
```

### Extract Max

```
swap(A[0], A[last])
remove last element
sift_down(0)
```

---

## 6. Complexity Analysis

| Operation   | Time       | Space |
| ----------- | ---------- | ----- |
| Insert      | O(log n)   | O(1)  |
| Extract Max | O(log n)   | O(1)  |
| Peek        | O(1)       | O(1)  |
| Build Heap  | O(n)       | O(1)  |
| Heap Sort   | O(n log n) | O(1)  |

---

## 7. Variations and Edge Cases

### Variations

* Min Heap
* D-ary Heap (more than 2 children)
* Binary Heap on pointer-based trees (rare)
* Lazy-deletion heaps (using markers)
* Indexed heaps (with external mapping)

### Edge Cases

* Extract on empty heap
* Repeated elements allowed
* Resizing underlying array

---

## 8. Visual Aids

### Sift Up Demonstration

```
Insert 42 into heap: [50, 30, 40, 10, 5, 20]

Array becomes:
[50, 30, 40, 10, 5, 20, 42]

Sift up:

          50
       /       \
     30         40
    /  \       /  \
   10   5     20  42
              ↑
             swap

After swap:

          50
       /       \
     30         42
    /  \       /  \
   10   5     20  40
```

---

## 9. Interview Tips

* You must **know why build-heap is O(n)**.
* Expect to implement:

  * priority queue using heap
  * extract-max / insert logic
* Often asked in:

  * Google: heap-based scheduling
  * Amazon: k-lists merge, top K problems
  * Meta: real-time stream processing
* Practice writing sift-up/sift-down **iteratively**.

Common trick questions:

1. Why use heap over balanced BST?
2. How heaps differ from arrays priority queue?
3. Why heaps are unstable in sorting?

---

## 10. Practice Problems

### Easy

* Binary Heap Representation
* Build Max Heap

### Medium

* Kth Largest Element — LeetCode 215
* Top K Frequent Elements — LeetCode 347
* Merge K Sorted Lists (min-heap) — LeetCode 23

### Hard

* Sliding Window Maximum — LeetCode 239
* Find Median from Data Stream — LeetCode 295
* Reorganize String — LeetCode 767

---
