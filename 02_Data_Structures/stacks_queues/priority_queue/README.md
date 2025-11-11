# Priority Queue (Heap) — Overview

A **Priority Queue** is an abstract data structure where each element has a priority, and the element with the **highest (or lowest) priority** is always processed first.

Usually implemented using a **binary heap** because it gives an efficient balance of operations.

---

## Key Properties

1. Access highest/lowest priority element in **O(1)**
2. Insert element in **O(log n)**
3. Remove highest/lowest priority in **O(log n)**
4. Can be implemented as:

   * Max-heap (default)
   * Min-heap
   * Double-ended priority queue
   * Pairing heaps / Fibonacci heaps (theoretical)

---

## Why Binary Heap?

Binary heap ensures:

* Structure property: complete binary tree
* Heap property: parent ≥ children (max-heap), or parent ≤ children (min-heap)

This keeps operations logarithmic.

---

## Visual Representation

### Max-Heap Example:

Array representation:

```
[50, 30, 40, 10, 20, 35]
```

Tree form:

```
        50
      /    \
    30      40
   /  \     /
 10   20   35
```

Heap always stored as a **contiguous array**.

---

## Core Operations

### 1. Insert (push)

* Place new element at end
* Heapify-up until heap property restored

### 2. Remove-max/min (pop)

* Replace root with last element
* Remove the last
* Heapify-down until heap property restored

### 3. Peek/Top

* Return root element (min or max depending on type)

---

## Priority Queue Use-Cases

1. Dijkstra’s shortest path algorithm
2. Prim’s MST
3. A* search
4. Scheduling systems
5. Median-finding (using two heaps)
6. Event simulation
7. Huffman coding
8. Merge k sorted arrays/lists

---

## Time Complexity

| Operation  | Binary Heap |
| ---------- | ----------- |
| push       | O(log n)    |
| pop        | O(log n)    |
| top        | O(1)        |
| search     | O(n)        |
| build-heap | O(n)        |

---

## Priority Queue Variants

### 1. Max Heap

Root always holds maximum value.

### 2. Min Heap

Root always holds minimum value.

### 3. Double-Ended PQ

Supports both min and max efficiently.

### 4. Indexed Priority Queue

Used in algorithms like Dijkstra for dynamic key updates.

### 5. Fibonacci Heap

Theoretical structure used for reducing amortized complexity.

---

## Interview Tips

1. Understand how **heapify up/down** works
2. Know array index relationships:

   * left child: `2*i + 1`
   * right child: `2*i + 2`
   * parent: `(i-1)//2`
3. Be able to implement **push/pop** from scratch
4. Understand use of priority queues in graph algorithms
5. Be able to solve problems requiring:

   * Top-k elements
   * Merge k sorted lists
   * Kth largest/smallest element
   * Task scheduling
6. Remember that built-in PQ structure is often **min-heap**, not max-heap

---

## Practice Problems

### LeetCode

1. Kth Largest Element in Array
2. Merge k Sorted Lists
3. Top K Frequent Elements
4. Find Median from Data Stream
5. Last Stone Weight
6. Sliding Window Maximum

### Codeforces

1. Tasks with deadlines scheduling
2. Greedy + PQ based event simulations

### GFG

1. Huffman Encoding
2. Median in a stream
3. Sort nearly sorted array

---

## Pseudocode (Max Heap)

```
push(x):
    insert x at end
    i = index of x
    while i > 0 and parent(i) < h[i]:
        swap parent and i
        i = parent(i)

pop():
    swap h[0] and h[last]
    remove last
    heapify_down(0)

heapify_down(i):
    while true:
        largest = i
        if left(i) < n and h[left(i)] > h[largest]:
            largest = left(i)
        if right(i) < n and h[right(i)] > h[largest]:
            largest = right(i)
        if largest == i:
            break
        swap h[i] and h[largest]
        i = largest
```

---

## Edge Cases

1. Empty priority queue
2. Duplicate priorities
3. Large numbers
4. Custom comparator
5. Frequent updates (requires indexed PQ)

---

## Summary

A priority queue is a must-know data structure built on heaps and used widely in interview problems, especially graph algorithms and greedy problems. Understanding its heap-based implementation makes debugging and optimization easier.
