# Priority Queue — Theory

## 1. What is a Priority Queue?

A **priority queue** is a data structure where every element has a *priority*, and the element with the highest (or lowest) priority is always removed first.

Unlike a normal queue (FIFO), a priority queue serves elements based on priority, not order of insertion.

---

## 2. Typical Implementations

1. **Binary Heap** (most common)
2. Balanced BST (like Red-Black Tree)
3. Fibonacci Heap (theoretical use in Dijkstra)
4. Pairing Heap
5. Binomial Heap

In interviews and competitive programming, priority queues are almost always implemented using **binary heaps**.

---

## 3. Max Heap vs Min Heap

| Type     | Property                      | Use-Case                           |
| -------- | ----------------------------- | ---------------------------------- |
| Max Heap | Extract maximum element first | Task scheduling, heapsort          |
| Min Heap | Extract minimum element first | Dijkstra, Prim, streaming problems |

---

## 4. Binary Heap Structure

A binary heap is a **complete binary tree**, stored as an **array**.

### Index Mapping

* parent(i) = (i – 1) / 2
* left child(i) = 2*i + 1
* right child(i) = 2*i + 2

Visual example (max-heap):

```
         40
       /    \
     30      35
    /  \    /
   10  20  25
```

Array representation:

```
[40, 30, 35, 10, 20, 25]
```

---

## 5. Core Operations

### 1. Insert (push)

Steps:

1. Add new element at the end.
2. "Heapify up" to restore heap property.

### 2. Extract (pop)

Steps:

1. Replace root with last element.
2. Remove last element.
3. "Heapify down" to restore heap property.

### 3. Peek (top)

Return the root element in O(1).

---

## 6. Algorithmic Intuition

### Heapify Up

Continue swapping a child with its parent until the heap property is satisfied.

### Heapify Down

Swap the parent with the largest (for max-heap) or smallest (for min-heap) child and continue.

---

## 7. Pseudocode

### Insert

```
insert(x):
    heap.append(x)
    i = heap.size - 1
    while i > 0 and heap[parent(i)] < heap[i]:
        swap heap[i] and heap[parent(i)]
        i = parent(i)
```

### Extract-max

```
extract_max():
    max_val = heap[0]
    heap[0] = heap[last]
    heap.pop()
    heapify_down(0)
    return max_val
```

### Heapify-down

```
heapify_down(i):
    while true:
        largest = i
        if left(i) < n and heap[left(i)] > heap[largest]:
            largest = left(i)
        if right(i) < n and heap[right(i)] > heap[largest]:
            largest = right(i)
        if largest == i:
            break
        swap heap[i], heap[largest]
        i = largest
```

---

## 8. Time Complexity

| Operation  | Time Complexity |
| ---------- | --------------- |
| Insert     | O(log n)        |
| Extract    | O(log n)        |
| Peek/Top   | O(1)            |
| Build Heap | O(n)            |
| Search     | O(n)            |

---

## 9. Important Variants

1. **Indexed Priority Queue**

   Supports fast priority updates (used in advanced Dijkstra optimizations).

2. **K-way merge priority queue**

   Used in:

   * Merge k sorted arrays
   * External sorting

3. **Double-ended PQ**

   Supports both min and max in O(log n).

---

## 10. Common Interview Questions

1. Kth largest element
2. Merge k sorted lists
3. Find median from data stream
4. Top-k frequent elements
5. Sliding window maximum
6. Huffman coding
7. Dijkstra's algorithm
8. Prim's algorithm

---

## 11. Edge Cases

* Empty heap extraction
* Duplicate priorities
* Custom comparator handling
* Large input sizes
* Stability (priority queues are not stable)

---

## 12. Visual Flowchart (Insert Operation)

```
Insert x →
Place x at end →
Compare with parent →
Swap if needed →
Repeat until root or heap property satisfied
```

---

## 13. Flowchart (Delete-max)

```
Delete root →
Move last element to root →
Heapify-down →
Swap with larger child →
Repeat until leaf or heap property satisfied
```

---

## 14. Practice Problems

### LeetCode

* 215. Kth Largest Element in Array
* 23. Merge k Sorted Lists
* 347. Top K Frequent Elements
* 295. Find Median from Data Stream
* 703. Kth Largest Element in Stream
* 1046. Last Stone Weight

### GFG

* Min cost of ropes
* Huffman Encoding

### Codeforces

* Scheduling tasks
* Event-driven simulations

---

## 15. Summary

A priority queue is a high-utility data structure built on heaps, ideal for greedy algorithms and problems requiring fast access to extreme values. Understanding the underlying heap mechanics is crucial for outperforming in interviews and competitive programming.

---
