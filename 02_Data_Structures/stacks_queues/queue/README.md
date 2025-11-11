# Queue — Overview

A **queue** is a linear data structure that follows the **FIFO (First In First Out)** principle.
The element inserted first is removed first, similar to people standing in a line.

Queue is one of the most fundamental data structures used in:

* BFS (Breadth-First Search)
* Scheduling (OS process scheduler)
* Streaming and buffering
* Producer-consumer scenarios
* Level-order tree traversals
* Sliding window algorithms

---

## Concept & Structure

A queue has two main ends:

* **Front**: where deletion happens (dequeue)
* **Rear**: where insertion happens (enqueue)

Representation:

```
  FRONT                       REAR
    |                           |
    v                           v
  [10] -> [20] -> [30] -> [40] -> NULL
```

---

## Core Operations

| Operation  | Meaning                    | Time Complexity |
| ---------- | -------------------------- | --------------- |
| enqueue(x) | Insert element at rear     | O(1)            |
| dequeue()  | Remove element from front  | O(1)            |
| front()    | Get element at front       | O(1)            |
| isEmpty()  | Check if queue is empty    | O(1)            |
| size()     | Returns number of elements | O(1)            |

---

## Queue Variants

The queue folder integrates different flavours:

### 1. Simple Queue

Basic FIFO implementation using array or linked list.

### 2. Circular Queue

Efficient fixed-size queue avoiding wasted space.

### 3. Deque (Double-ended Queue)

Allows push/pop from both ends.

### 4. Priority Queue

Removes the element with highest priority instead of FIFO order.

---

## Implementations You Will Find in This Folder

* **operations.cpp** → Queue using Linked List
* **operations.py** → Queue using Python list / deque
* **theory.md** → Explanation, diagrams, approaches

---

## Implementation Choices

### Using Array

* Fast but fixed size
* Easy index handling
* Good for implementation-heavy exams

### Using Linked List

* Dynamic size
* Suitable for interviews
* No overflow unless memory is full

---

## Common Queue Interview Questions

### 1. Implement queue using stacks

* Trick: use two stacks (input & output)
* Amortized O(1)

### 2. Implement stack using queues

* Two variants:

  * Push O(1) / Pop O(n)
  * Push O(n) / Pop O(1)

### 3. Sliding window maximum (uses deque)

* Important pattern
* Used in system design & coding interviews

### 4. BFS traversal

* Fundamental graph algorithm

---

## ASCII Operation Flow

### Enqueue

```
Before:
FRONT → [10] → [20] → NULL
REAR ----------------^

After enqueue(30):
FRONT → [10] → [20] → [30] → NULL
REAR ---------------------------^
```

### Dequeue

```
Before:
FRONT → [10] → [20] → [30]
REAR --------------------^

After dequeue():
FRONT → [20] → [30]
REAR ------------------^
```

---

## Usage in Algorithms

| Algorithm/Concept     | Why Queue is used               |
| --------------------- | ------------------------------- |
| BFS                   | Process nodes level-by-level    |
| Topological sorting   | Kahn’s algorithm uses queue     |
| Scheduling            | Jobs processed in arrival order |
| Cache eviction (FIFO) | FIFO replacement strategy       |

---

## Interview Tips

* Be able to write queue using an array with wrap-around
* Know time complexities cold
* Understand queue usage in BFS and sliding window
* Know when to choose deque vs queue

---

## Practice Problems

### Easy

* Implement queue using stacks (LeetCode 232)
* Circular queue (LeetCode 622)

### Medium

* Sliding window maximum (LeetCode 239)
* Number of islands (uses BFS)
* Rotten oranges BFS (LeetCode 994)

### Advanced

* Task scheduler (LeetCode 621)
* Shortest path in grid using BFS

---
