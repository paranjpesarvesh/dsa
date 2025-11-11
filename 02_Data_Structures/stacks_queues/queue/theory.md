# Queue — Theory

A **queue** is a linear data structure that follows the **FIFO (First In First Out)** principle.
The first element inserted is the first element removed. Queues are foundational in algorithm design and system-level programming.

---

## 1. What is a Queue?

A queue models real-world lines:

```
front --> [A] → [B] → [C] → [D] --> rear
```

* **Insertions** happen at the rear
* **Deletions** happen at the front

---

## 2. Queue Operations

| Operation  | Description               | Complexity |
| ---------- | ------------------------- | ---------- |
| enqueue(x) | Insert element at rear    | O(1)       |
| dequeue()  | Remove element from front | O(1)       |
| front()    | Return front element      | O(1)       |
| isEmpty()  | Check if queue is empty   | O(1)       |
| size()     | Return number of elements | O(1)       |

---

## 3. Queue Using Array (Linear & Circular)

### Linear Array Queue

Inefficient due to wasted front space after multiple dequeues.

```
Index: 0   1   2   3   4
Queue: [ ] [ ] [5] [6] [7]
```

### Circular Queue

Solves overflow by wrapping indices.

Formula:

```
rear = (rear + 1) % capacity
front = (front + 1) % capacity
```

ASCII view:

```
      circular wrap
        ↓
[7] [8] [ ] [ ] [5] [6]
      ↑ front     ↑ rear
```

---

## 4. Queue Using Linked List

A more flexible and common interview implementation.

```
front → [10] → [20] → [30] → NULL
rear ----------------------------^
```

### Advantages

* Dynamic size
* No wasted space
* No overflow (except memory exhaustion)

---

## 5. Mathematical Intuition

Queues behave like a **stream with constant-time access** at boundaries.

For fixed-size queues:

* Size always ≤ capacity
* Index movement is modular arithmetic

For linked-list queues:

* Every insertion allocates new node
* Queue grows in O(n) memory where n is size

---

## 6. Queue Variants

### 1. Circular Queue

Efficient array-based queue.

### 2. Deque (Double-ended queue)

Push/pop from both ends.

### 3. Priority Queue (Heap)

Removes highest priority element.

### 4. Monotonic Queue

Used in sliding window maximum.

---

## 7. Pseudocode Templates

### Enqueue (Linked List)

```
function enqueue(x):
    newNode = Node(x)
    if rear == null:
        front = rear = newNode
        return
    rear.next = newNode
    rear = newNode
```

### Dequeue (Linked List)

```
function dequeue():
    if front == null:
        return error
    temp = front
    front = front.next
    if front == null:
        rear = null
    delete temp
```

---

## 8. Time & Space Complexity

| Operation  | Time | Space              |
| ---------- | ---- | ------------------ |
| enqueue    | O(1) | O(1) per insertion |
| dequeue    | O(1) | O(1) per deletion  |
| peek/front | O(1) | —                  |
| isEmpty    | O(1) | —                  |

Total space = O(n) for n elements.

---

## 9. Edge Cases & Pitfalls

* Overflow in fixed arrays
* Underflow (dequeue on empty queue)
* Forgetting to reset rear when queue becomes empty
* In circular queue, front == rear does not necessarily mean empty; need separate size logic or sentinel flags

---

## 10. Interview Tips

* Know array vs linked-list queue differences
* Be able to code circular queue from scratch
* Understand queue’s role in BFS and topological sort
* Know how to simulate queue using two stacks
* Know how to simulate stack using queues

Companies frequently test:

* BFS-based problems
* Sliding window problems
* Scheduling/processing simulations

---

## 11. Common Queue Based Problems

### Easy

* Implement Queue using Stacks (LeetCode 232)
* Implement circular queue (LeetCode 622)
* Moving Average (sliding window)

### Medium

* Number of islands (BFS approach)
* Rotten oranges
* Course schedule (topological sort)

### Hard

* Task scheduler
* Sliding window maximum

---

## 12. Visual Flowcharts

### Enqueue

```
    [rear] → new node
       |
front → [10] → [20] → [30] → NULL
```

### Dequeue

```
remove [10]
front → [20]
```

---

## 13. Summary

Queues are:

* simple
* powerful
* widely used
* essential for interviews

Master operations and variations, and practice BFS-heavy problems to strengthen your understanding.

---
