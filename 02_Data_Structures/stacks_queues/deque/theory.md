# Deque (Double-Ended Queue) — Theory

A **Deque** (Double-Ended Queue) is a linear data structure that allows **insertion and deletion from both ends** in constant time. It combines the strengths of both stack and queue, making it a versatile structure for many algorithmic problems.

---

## 1. Definition

A **deque** supports these core operations in O(1):

* push_front(x)
* push_back(x)
* pop_front()
* pop_back()
* front()
* back()
* is_empty()

Deque generalizes both stacks and queues:

* Stack = restrict pops/pushes to one end
* Queue = restrict push at back & pop at front
* Deque = fully flexible

---

## 2. Visual Representation

```
Front                             Back
  |                                 |
 [4] <-> [7] <-> [13] <-> [20] <-> [25]
```

Operations:

```
push_front(2) → [2] <-> [4] <-> [7] ...
push_back(30) → ... <-> [25] <-> [30]
pop_front()  → removes [2]
pop_back()   → removes [30]
```

---

## 3. Internal Implementations

### A. Doubly Linked List

* Most natural implementation
* True O(1) operations at both ends
* No fixed capacity

### B. Circular Array

* Requires tracking head, tail, wrap-around
* Efficient cache locality
* Dynamically resizing required

---

## 4. Step-by-Step Working Example

Consider performing operations:

```
push_back(10)
push_back(20)
push_front(5)
pop_back()
push_front(3)
```

State transitions:

```
[]
[10]
[10,20]
[5,10,20]
[5,10]
[3,5,10]
```

---

## 5. Pseudocode for Linked List-Based Deque

```
struct Node:
    data
    next
    prev

push_front(x):
    node = new Node(x)
    if head == null:
        head = tail = node
    else:
        node.next = head
        head.prev = node
        head = node

push_back(x):
    node = new Node(x)
    if tail == null:
        head = tail = node
    else:
        tail.next = node
        node.prev = tail
        tail = node

pop_front():
    if empty(): return error
    val = head.data
    head = head.next
    if head != null:
        head.prev = null
    else:
        tail = null
    return val

pop_back():
    if empty(): return error
    val = tail.data
    tail = tail.prev
    if tail != null:
        tail.next = null
    else:
        head = null
    return val
```

---

## 6. Complexity Analysis

| Operation         | Time | Space |
| ----------------- | ---- | ----- |
| push_front        | O(1) | O(1)  |
| push_back         | O(1) | O(1)  |
| pop_front         | O(1) | O(1)  |
| pop_back          | O(1) | O(1)  |
| Access front/back | O(1) | O(1)  |

Space is proportional to number of elements stored.

---

## 7. Variations of Deque

### Input-Restricted Deque

* Inserts allowed only at one end
* Deletes allowed at both ends

### Output-Restricted Deque

* Deletes allowed only at one end
* Inserts allowed at both ends

---

## 8. Common Applications

Deque is used heavily in:

### A. Sliding Window Algorithms

Monotonic deque helps maintain max/min in O(n).

### B. BFS (0-1 BFS)

Edges with weight 0 are pushed front; weight 1 are pushed back.

### C. Palindrome Checking

Deque allows character comparison from both ends.

### D. Queue/Stack Simulation

Can simulate both efficiently.

### E. Undo/Redo Systems

Deque can represent multi-level command history.

---

## 9. Edge Cases

* Pop from empty deque
* Handling head/tail null transitions
* Overflows in circular array implementation
* Checking single-element behavior (head == tail)

---

## 10. Interview Tips

Deque may appear directly or indirectly.

**Direct:**

* Implement deque
* Explain circular array implementation
* Compare complexity with queue/stack

**Indirect (common in FAANG):**

* Sliding Window Maximum
* Shortest subarray with sum >= K
* First negative number in each window
* Rotting oranges (grid BFS)
* Max of all subarrays of size k

When asked why deque is chosen:

* It allows efficient front/back operations
* Maintains monotonic order when required

---

## 11. Practice Problems

### Easy

* Design Circular Deque (LeetCode 641)
* Implement Deque (GFG)

### Medium

* Sliding Window Maximum (LeetCode 239)
* First Negative Number in Every Window

### Hard

* Shortest Subarray with Sum >= K (LeetCode 862)
* 0-1 BFS problems on Codeforces

---

## 12. Summary

Deque generalizes linear data structures by providing O(1) operations on both ends and enabling efficient solutions for window-based and monotonic sequences.

```
Stack: push/pop on one end
Queue: push back, pop front
Deque: push/pop both ends — full power
```

This concludes the detailed theory of **Deque**.

