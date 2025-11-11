# Max Heap — Overview

A **Max Heap** is a complete binary tree stored usually in an array where:

* Every parent node is **greater than or equal** to its children.
* The **maximum** element is always at the **root**.
* The structure is **complete**, meaning all levels are filled except possibly the last, filled from left to right.

A max heap supports efficient priority-based operations such as insert and extract-max.

---

## 1. Structure

A max heap uses an **implicit binary tree** backed by an array (0-indexed):

```
             a[0]
           /       \
        a[1]       a[2]
       /   \       /   \
    a[3]  a[4]   a[5]  a[6]
```

Index relations:

```
parent(i) = (i - 1) // 2
left(i)   = 2*i + 1
right(i)  = 2*i + 2
```

---

## 2. Operations

### Insert / Push

1. Insert element at the end.
2. Perform **sift up** until heap property holds.

Time: O(log n)

---

### Peek (Get Max)

Return `a[0]`.

Time: O(1)

---

### Extract Max / Pop

1. Swap root with last element.
2. Remove the last (max).
3. Perform **sift down** from root.

Time: O(log n)

---

### Build Heap

Given an unsorted array, construct a valid heap in O(n):

```
for i from n/2 to 0:
    sift_down(i)
```

Reason: Half of the nodes are leaves, requiring no work.

---

## 3. Heapify Logic

### Sift Up

```
while i > 0 and parent(i) < a[i]:
    swap(i, parent(i))
    i = parent(i)
```

### Sift Down

```
while i has a child:
    largest = max(i, left(i), right(i))
    if largest == i: break
    swap(i, largest)
    i = largest
```

---

## 4. Use Cases

* Priority queue
* Scheduling jobs/tasks
* Selecting k largest elements
* Heap sort (descending order)
* Dijkstra/Prim when implemented with max-heap variants

---

## 5. Heap Sort Using Max Heap

1. Build a max heap.
2. Repeatedly extract the maximum and append to result.

Time complexity: O(n log n)

Space complexity:

* In-place (array version): O(1)
* Non-destructive: O(n)

---

## 6. Complexity Summary

| Operation   | Time Complexity | Space     |
| ----------- | --------------- | --------- |
| Insert      | O(log n)        | O(1)      |
| Extract Max | O(log n)        | O(1)      |
| Peek        | O(1)            | O(1)      |
| Build Heap  | O(n)            | O(1)      |
| Heap Sort   | O(n log n)      | O(1)/O(n) |

---

## 7. Edge Cases

* Extracting from an empty heap → error
* Increasing key vs decreasing key: decreasing requires sift down
* Duplicate values: valid, ordering unchanged
* Large datasets: array resizing cost amortized constant

---

## 8. Interview Tips

* Must know why **build heap is O(n)**.
* Understand difference between:

  * binary heap
  * binomial heap
  * Fibonacci heap
* In coding interviews:

  * Usually asked to design priority queue
  * Might be implemented in array or using STL priority_queue
* Recursion is rarely preferred for heapify due to stack depth
* Heap is not sorted; only partial order is maintained

---

## 9. ASCII Visual Examples

### Insertion Example

Insert 40:

```
Initial:          Insert: 40 → sift up
     20               20
    /  \             /  \
   15  18           15  18
  / \               / \
 10  12            10  12

After swap: 40 rises to root

       40
      /  \
    20    18
   / \
  15  12
```

---

## 10. Practice Problems

### Core

* Implement Max Heap (all operations)
* Heap sort
* Priority queue

### Interview-level

* Kth largest element

  * LeetCode 215
* Top K frequent elements

  * LeetCode 347
* Merge K sorted lists

  * LeetCode 23 (min-heap variant)
* Find median from data stream

  * LeetCode 295 (two heaps)

### Hard/Advanced

* Sliding window maximum

  * LeetCode 239
* Reorganize string

  * LeetCode 767

---
