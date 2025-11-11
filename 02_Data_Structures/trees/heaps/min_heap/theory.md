# Min Heap — Theory

A **Min Heap** is a complete binary tree-based data structure where each node is **less than or equal to** its children. It guarantees **fast retrieval of the minimum element**, which always resides at the root.

This file explains everything needed for interviews: definition, intuition, diagrams, operations, pseudocode, complexity, variations, and practice problems.

---

## 1. Definition

A Min Heap satisfies two core properties:

### 1. Complete Binary Tree

All levels are completely filled except possibly the last, and nodes fill left to right.

### 2. Heap Order Property

For every node `i`:

```
heap[i] <= heap[left child]
heap[i] <= heap[right child]
```

Thus, the minimum element is always the root.

---

## 2. Visual Representation

### Tree View

```
        2
     /     \
    4       5
   / \     / \
  7   9   6  13
```

### Array View

A Min Heap is usually stored in an array:

```
index: 0  1  2  3  4  5  6
value: 2  4  5  7  9  6 13
```

### Index Formulas

For a node at index `i`:

| Relation    | Index Formula |
| ----------- | ------------- |
| Left child  | 2i + 1        |
| Right child | 2i + 2        |
| Parent      | (i - 1) // 2  |

---

## 3. Operations Explained Step-by-Step

### 1. insert(x)

Steps:

1. Append at the end.
2. Bubble up (heapify-up) until the heap order holds.

### 2. extractMin()

Steps:

1. Save root element as answer.
2. Replace root with last element.
3. Remove last element.
4. Heapify-down from root.

### 3. getMin()

Return value at index 0; O(1).

---

## 4. Pseudocode

### Insert

```
insert(x):
    add x to end
    i = index of x
    while i > 0 and heap[parent(i)] > heap[i]:
        swap(heap[i], heap[parent(i)])
        i = parent(i)
```

### Extract Min

```
extract_min():
    if empty:
        error
    root = heap[0]
    heap[0] = heap[last]
    remove last
    heapify_down(0)
    return root
```

### Heapify Down

```
heapify_down(i):
    while True:
        left = 2*i + 1
        right = 2*i + 2
        smallest = i
        if left < n and heap[left] < heap[smallest]:
            smallest = left
        if right < n and heap[right] < heap[smallest]:
            smallest = right
        if smallest == i:
            break
        swap(heap[i], heap[smallest])
        i = smallest
```

---

## 5. Complexity Analysis

| Operation    | Time     |
| ------------ | -------- |
| Insert       | O(log n) |
| Extract Min  | O(log n) |
| Get Min      | O(1)     |
| Heapify-down | O(log n) |
| Build Heap   | O(n)     |

Space: O(n)

---

## 6. Mathematical Intuition (Why Build-Heap is O(n)?)

Levels near the bottom have many nodes but each requires little work; higher levels have few nodes but large work.

Total work:

```
n/2 * 1 + n/4 * 2 + ... + 1 * log n  = O(n)
```

---

## 7. Variations and Edge Cases

### Variants

* Max Heap
* d-ary Heaps
* Fibonacci Heaps
* Lazy heaps

### Edge Cases

* Heap underflow (extract from empty)
* Overflow in array index computations
* Duplicate values allowed
* Need to update keys? → decreaseKey operation

---

## 8. Interview Tips

Important talking points:

* Mention **complete tree property** first.
* Know how to map between tree structure and array.
* Understand build-heap complexity.
* Know use cases:

  * Dijkstra’s shortest path
  * Prim’s MST
  * Scheduling and priority queues
  * Merge k sorted lists

Common interview follow-up questions:

* How do you implement decreaseKey?
* How do you merge two heaps? (Binary heap: O(n), Fibonacci heap: O(1))
* Why is priority queue often implemented using heap?

---

## 9. Visual Flowcharts

### Insert Operation

```
Add x at end → Compare with parent → Swap if smaller → Repeat till done
```

### Extract Min

```
Take root → Move last element to root → Heapify down → Return old root
```

---

## 10. Practice Problems

### LeetCode

* 215. Kth Largest Element in an Array
* 621. Task Scheduler
* 1046. Last Stone Weight
* 373. Find K Pairs with Smallest Sums
* 703. Kth Largest in a Stream

### GFG

* Min Heap operations
* Merge k sorted arrays

### Codeforces

* Many greedy problems use heaps implicitly

---

## 11. Summary

* Min Heap maintains smallest element at top.
* Tree is complete and follows heap order.
* Operations rely on heapify-up/down.
* Efficient structure for priority queues.

---
