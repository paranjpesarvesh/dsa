# Circular Linked List – Theory

A **Circular Linked List (CLL)** is a linked structure in which the **last node points back to the first node**, forming a closed loop.
Unlike a singly linked list, there is **no NULL at the end**.

---

## 1. What is a Circular Linked List?

A circular linked list is a linear data structure with two main characteristics:

1. Each node contains data and a pointer to the next node.
2. The next pointer of the last node points to the head.

### Singly Circular Linked List Structure

```
 head
  |
  v
+------+     +------+     +------+
|  10  | --> |  20  | --> |  30  |
+------+     +------+     +------+
     ^                        |
     |------------------------+
```

---

## 2. When to Use Circular Linked Lists

Suitable when:

* You need to **loop through items repeatedly**.
* You want **constant-time rotation** (head moves easily).
* Implementing **queue**, **round-robin scheduling**, **multi-player games**, etc.
* Applications where wrap-around behaviour is natural.

---

## 3. Types

| Type                        | Description                       |
| --------------------------- | --------------------------------- |
| Singly Circular Linked List | Only next pointer exists          |
| Doubly Circular Linked List | Both next and prev pointers exist |

---

## 4. Core Operations

### 4.1 Traversal

Because there is no NULL terminator, traversal uses:

```
temp = head
do:
    process temp
    temp = temp.next
while temp != head
```

### 4.2 Insertion

Supported at:

* beginning
* end
* after a node
* before a node (via traversal)

### 4.3 Deletion

You can delete:

* head
* tail
* a specific value/node

---

## 5. Pseudocode Templates

### Insert at head

```
function insert_head(value):
    new = Node(value)

    if head == null:
        head = new
        new.next = new
        return

    temp = head
    while temp.next != head:
        temp = temp.next

    new.next = head
    temp.next = new
    head = new
```

### Delete a node with value

```
function delete_value(val):
    if head is null:
        return

    curr = head
    prev = null

    while curr.value != val:
        prev = curr
        curr = curr.next
        if curr == head:
            return   // not found

    if curr == head:
        tail = head
        while tail.next != head:
            tail = tail.next
        tail.next = head.next
        head = head.next
        return

    prev.next = curr.next
```

---

## 6. Complexity Analysis

| Operation         | Time | Space |
| ----------------- | ---- | ----- |
| Insertion at head | O(n) | O(1)  |
| Insertion at end  | O(n) | O(1)  |
| Deletion          | O(n) | O(1)  |
| Traversal         | O(n) | O(1)  |
| Search            | O(n) | O(1)  |

To optimize insertions at head/end, maintain a **tail pointer**.

---

## 7. Advantages

* Can represent data in cyclic fashion
* No need to check for NULL while traversing
* Efficient round-robin traversal
* Useful in scheduling algorithms

---

## 8. Disadvantages

* More complex insertion/deletion logic
* No natural end point (careful loop control needed)
* Harder debugging
* Risk of infinite loops

---

## 9. Common Edge Cases

1. Empty list
2. Single node list
3. Deleting head
4. Multiple nodes with same value
5. Updating pointers incorrectly causing cycles or loss of nodes

---

## 10. Interview Tips

* Be clear about how traversal stops.
* Understand why insertion at head requires finding the last node.
* Be ready to compare CLL vs singly-linked list.
* Understand time complexities and how tail pointer improves them.
* Circular queue implementation often comes up (array vs linked-list based).

---

## 11. Practice Problems

| Problem                                    | Platform     |
| ------------------------------------------ | ------------ |
| Insert/Delete operations in CLL            | GFG          |
| Split circular linked list into two halves | GFG          |
| Josephus Problem                           | LeetCode/GFG |
| Detect cycle in a linked list              | LeetCode     |
| Implement Circular Queue                   | LeetCode     |

---

## 12. Summary

Circular linked lists extend basic linked lists by providing looping behavior without NULL termination.
They are conceptually easy but pointer manipulation requires special attention.

This theory file gives a complete conceptual foundation for understanding and implementing circular linked lists.

