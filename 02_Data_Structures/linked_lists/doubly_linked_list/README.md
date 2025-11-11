# Doubly Linked List

A guided introduction for interview-focused learning

---

## 1. What is a Doubly Linked List?

A **Doubly Linked List (DLL)** is a linear data structure where each node stores:

* data
* pointer/reference to the next node
* pointer/reference to the previous node

Structure:

```
NULL <- [prev | data | next] <-> [prev | data | next] <-> ... -> NULL
```

This allows:

* traversal in both directions
* quick insertion/deletion given a node reference

---

## 2. Why DLL instead of SLL?

Comparison:

| Feature                              | Singly Linked List | Doubly Linked List |
| ------------------------------------ | ------------------ | ------------------ |
| Traversal                            | Forward only       | Forward & backward |
| Delete a node when pointer given     | O(1)               | O(1)               |
| Extra memory per node                | 1 pointer          | 2 pointers         |
| Complexity for insert/delete at ends | O(1)               | O(1)               |
| Reverse traversal                    | Hard               | Easy               |

---

## 3. Use Cases

Real-world patterns where DLL dominates:

* Browser history (forward/backward navigation)
* LRU cache implementation
* Undo/redo operations in text editors
* Deque implementation
* Music playlists

---

## 4. Core Operations

### Insert Front (O(1))

```
new.prev = NULL
new.next = head
head.prev = new
head = new
```

### Insert End (O(1))

```
new.next = NULL
new.prev = tail
tail.next = new
tail = new
```

### Delete Node (O(1) if node known)

```
node.prev.next = node.next
node.next.prev = node.prev
```

### Delete by Value (O(n))

Linear search required.

---

## 5. Traversals

### Forward

```
curr = head
while curr:
    print curr.data
    curr = curr.next
```

### Backward

```
curr = tail
while curr:
    print curr.data
    curr = curr.prev
```

---

## 6. Time & Space Complexity

| Operation               | Time |
| ----------------------- | ---- |
| Insert head             | O(1) |
| Insert tail             | O(1) |
| Delete node (reference) | O(1) |
| Delete value            | O(n) |
| Search                  | O(n) |
| Traversal               | O(n) |

Space overhead: Two pointers per node.

---

## 7. Edge Cases

* Empty list operations
* Deleting the only node (head == tail)
* Inserting into empty list
* Ensuring pointers don't leak (prev and next update order)

---

## 8. Common Interview Traps

1. Forgetting to update both pointers (prev/next).
2. When deleting head or tail, forgetting to update head/tail references.
3. Mismanaging prev pointer causing segmentation faults or NoneType errors.
4. Circular vs doubly linked list confusion.

---

## 9. Practice Problems

### Easy

* Implement DLL from scratch
* Insert, delete, and traverse operations
* Reverse a DLL

### Medium

* Flatten a multilevel doubly linked list (LeetCode 430)
* Browser history design

### Hard

* LRU Cache (LeetCode 146: uses DLL + hashmap)
* Text editor undo-redo simulation

---

## 10. Summary

A Doubly Linked List combines flexibility with constant-time updates at both ends.
Mastering DLL is important for understanding:

* cache systems
* graph adjacency structures
* pointer-heavy data structures

This directory includes:

* theory.md → conceptual notes
* operations.cpp / operations.py → implementations and demos
* problems/ → practice questions and applications

You now have all building blocks to implement and extend DLL efficiently.

