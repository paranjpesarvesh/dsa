# Deque (Double-Ended Queue)

A **deque** is a linear data structure that allows insertion and deletion at **both ends** efficiently. It combines features of both **stack** and **queue**, making it extremely versatile for many algorithmic applications.

---

## 1. What is a Deque?

A **deque** (pronounced "deck") supports operations:

* Insert at front
* Insert at back
* Delete from front
* Delete from back
* Access front/back

All in **O(1)** time.

---

## 2. Visual Representation

```
Front                         Back
  |                            |
 [10] <-> [15] <-> [20] <-> [30]
```

Operations:

```
push_front(5) → [5] <-> [10] <-> [15] <-> ...
push_back(40) → ... <-> [30] <-> [40]
pop_front() → removes [5]
pop_back()  → removes [40]
```

---

## 3. Why is Deque Useful?

Key advantages:

* Constant-time double-end operations.
* Flexible structure enabling multiple algorithmic patterns.

Common use cases:

* **Sliding Window Maximum/Minimum** (Monotonic Queue)
* **Palindrome checking**
* **Undo/Redo operations** (browser history)
* **BFS** on implicit graphs
* **All O(1) Data Structure** variations

---

## 4. Underlying Implementations

Deque can be implemented using:

### Using Doubly Linked List

* True O(1) operations
* No resizing issues
* Efficient memory flexibility

### Using Circular Array

* Fast contiguous memory access
* Requires managing wrap-around
* Must handle array resizing

---

## 5. Core Operations (Pseudocode)

### Using Doubly Linked List

```
push_front(x):
    node = new Node(x)
    if empty:
        head = tail = node
    else:
        node.next = head
        head.prev = node
        head = node

push_back(x):
    node = new Node(x)
    if empty:
        head = tail = node
    else:
        tail.next = node
        node.prev = tail
        tail = node

pop_front():
    if empty: return error
    val = head.data
    head = head.next
    if head: head.prev = null
    else: tail = null
    return val

pop_back():
    if empty: return error
    val = tail.data
    tail = tail.prev
    if tail: tail.next = null
    else: head = null
    return val
```

---

## 6. Complexity Analysis

| Operation  | Time | Space |
| ---------- | ---- | ----- |
| push_front | O(1) | O(n)  |
| push_back  | O(1) | O(n)  |
| pop_front  | O(1) | O(n)  |
| pop_back   | O(1) | O(n)  |
| front/back | O(1) | O(1)  |

---

## 7. Variations

### Input-restricted deque

* Insertion allowed only at one end.

### Output-restricted deque

* Deletion allowed only at one end.

---

## 8. Edge Cases

* Pop from empty deque
* Resize when using array-based implementation
* Maintaining pointers in linked list version
* Handling single element (head == tail)

---

## 9. Interview Tips

Deques are often tested indirectly through problems requiring:

* **Sliding window technique**
* **Monotonic queue**
* **Two-pointer optimization**
* **Queue enhancements**

Be ready to explain:

* Why deque is chosen over stack/queue
* Which implementation is preferred and why
* How to maintain monotonicity

---

## 10. Practice Problems

### Beginner

* Implement Deque (GFG)
* Design Circular Deque (LeetCode 641)

### Intermediate

* Sliding Window Maximum (LeetCode 239)
* Moving Average from Data Stream

### Advanced

* First Negative Number in Every Window
* Shortest Subarray with Sum ≥ K (uses deque for monotonic prefix sums)

---

## 11. Summary Table

| Feature    | Stack | Queue | Deque |
| ---------- | ----- | ----- | ----- |
| Push front | No    | No    | Yes   |
| Push back  | Yes   | Yes   | Yes   |
| Pop front  | No    | Yes   | Yes   |
| Pop back   | Yes   | No    | Yes   |

Deque generalizes both stack and queue.

---

This completes the theory for **Deque**.

