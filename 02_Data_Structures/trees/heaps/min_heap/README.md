# Min Heap — Overview

A **Min Heap** is a complete binary tree where every node is **smaller than or equal to its children**. This structure guarantees fast access to the minimum element, stored at the root.

It is typically implemented using an array, making operations efficient and predictable.

---

## 1. Characteristics

### Complete Binary Tree Property

A Min Heap must always be complete:

```
      1
    /   \
   3     5
  / \   /
 7  9  11
```

Every level is filled except possibly the last, and nodes fill from **left to right**.

### Heap Property

For every node `i`:

```
heap[i] <= heap[left child]
heap[i] <= heap[right child]
```

Thus:

```
root = minimum element
```

---

## 2. Array Representation

A Min Heap can be represented in an array `A` as follows:

| Node | Index | Left Child | Right Child | Parent  |
| ---- | ----- | ---------- | ----------- | ------- |
| i    | i     | 2i+1       | 2i+2        | (i-1)/2 |

Example:

```
A = [1, 3, 5, 7, 9, 11]
```

ASCII visualization:

```
index:  0   1   2   3   4   5
value:  1   3   5   7   9  11
```

---

## 3. Core Operations

### Insert(x)

1. Add element to end of array.
2. Bubble up (heapify-up):

   * Swap with parent until heap property holds.

### Extract Min()

1. Replace root with last element.
2. Remove last element.
3. Heapify-down from root.

### Get Min()

Return element at index 0 (O(1)).

---

## 4. Pseudocode

### Insert

```
insert(x):
    heap.append(x)
    i = size - 1
    while i > 0 and heap[parent(i)] > heap[i]:
        swap(heap[parent(i)], heap[i])
        i = parent(i)
```

### Extract Min

```
extract_min():
    if heap is empty:
        error
    min_val = heap[0]
    heap[0] = heap[last]
    remove last
    heapify_down(0)
    return min_val
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

| Operation   | Time Complexity |
| ----------- | --------------- |
| Insert      | O(log n)        |
| Extract Min | O(log n)        |
| Get Min     | O(1)            |
| Heapify     | O(log n)        |
| Build Heap  | O(n)            |

Space Complexity: O(n)

---

## 6. Variations

### Max Heap

Same structure but root is maximum.

### D-ary Heap

Generalizes to **k children** per node.

### Binary Heap vs Fibonacci Heap

Binary heap is faster for extract-min operations in practice.

---

## 7. Edge Cases

* Extract/min on empty heap → error
* Duplicate keys allowed
* Integer overflow when calculating indices
* Recursion vs iteration in heapify implementations

---

## 8. Interview Tips

* Always mention **complete binary tree** property.
* Practice converting between tree and array representation.
* Common question: “Why is build-heap O(n) and not O(n log n)?”

  * Because lower levels have many nodes with shallow heapify cost.
* Know real-world applications:

  * Dijkstra’s algorithm
  * Prim’s MST
  * Priority queues
  * Scheduling systems

---

## 9. Practice Problems

### LeetCode

* 215. Kth Largest Element in an Array
* 871. Minimum Number of Refueling Stops
* 1046. Last Stone Standing
* 703. Kth Largest Element in a Stream

### GeeksForGeeks

* Min Heap operations
* K sorted arrays merge

### Codeforces

* Tasks involving priority queues in greedy algorithms

---

## 10. Summary Table

| Feature        | Min Heap                               |
| -------------- | -------------------------------------- |
| Type           | Complete Binary Tree                   |
| Implementation | Array-based                            |
| Root           | Minimum element                        |
| Primary use    | Priority queue                         |
| Complexity     | Insert/Extract: O(log n), GetMin: O(1) |

---
