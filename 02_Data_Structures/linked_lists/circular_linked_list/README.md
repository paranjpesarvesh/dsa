# Circular Linked List – Overview and Core Concepts

A **Circular Linked List (CLL)** is a variation of the linked list where the **last node points back to the first node**, forming a circle.
It maintains all linked-list flexibility while enabling efficient circular traversal.

---

## Why Circular Linked Lists Matter

* Useful in **round-robin scheduling**, **implementing queues**, **Floyd cycle detection**, **buffers**, **multi-player games**, etc.
* No explicit end (NULL), so traversal can loop infinitely unless handled carefully.
* Efficient for operations where wrap-around behaviour is required.

---

## Structure

```
 head
  |
  v
+----+    +----+    +----+
| 1  |--->| 2  |--->| 3  |
+----+    +----+    +----+
   ^                   |
   |-------------------+
```

---

## Key Properties

| Feature              | Circular Linked List                      |
| -------------------- | ----------------------------------------- |
| Last node points to  | Head node                                 |
| Supports wrap-around | Yes                                       |
| End of list          | Not NULL                                  |
| Traverse             | Must stop manually (e.g., return to head) |
| Variants             | Singly CLL, Doubly CLL                    |

---

## Operations

### 1. Insertion

You can insert:

* At head
* At end
* After a node
* Before a node (with traversal)

### 2. Deletion

You can delete:

* Head node
* End node
* Any node with given value

### 3. Traversal

Use a do-while style logic:

```
temp = head
do:
    visit temp
    temp = temp.next
while temp != head
```

### 4. Searching

Traverse until:

* value found
* you return to head

---

## Complexity Table

| Operation      | Time                     | Space |
| -------------- | ------------------------ | ----- |
| Insert at head | O(n) (finding last node) | O(1)  |
| Insert at end  | O(n)                     | O(1)  |
| Delete         | O(n)                     | O(1)  |
| Search         | O(n)                     | O(1)  |
| Traverse       | O(n)                     | O(1)  |

---

## Pseudocode Templates

### Insert at Head

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

### Delete Node by Value

```
function delete(val):
    if head == null:
        return

    if head.value == val and head.next == head:
        head = null
        return

    curr = head
    prev = null
    while curr.value != val:
        prev = curr
        curr = curr.next
        if curr == head:
            return

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

## Visual Explanation of Deletion

Deleting the head node:

```
Before:
 head
  |
  v
+----+    +----+    +----+
| 1  |--->| 2  |--->| 3  |
+----+    +----+    +----+
   ^                   |
   |-------------------+

After deleting head:

 head
  |
  v
+----+    +----+
| 2  |--->| 3  |
+----+    +----+
   ^        |
   |--------+
```

---

## Edge Cases

1. Empty list
2. Single node list
3. Deleting head
4. Searching beyond a full cycle
5. Infinite loops if traversal termination is incorrect
6. Insert-before-head logic for specific use cases

---

## Interview Tips

* Expect questions on:

  * Detecting cycles (Floyd/slow-fast pointers)
  * Designing circular queue using CLL
  * Insert/delete corner cases
  * Time complexity comparisons with array-based circular queues
* Be ready to draw the structure and explain traversal.
* Interviewers often test your ability to handle edge cases.

---

## Practice Problems

| Problem                                     | Source       |
| ------------------------------------------- | ------------ |
| Insert/Delete nodes in circular linked list | GFG          |
| Josephus Problem (CLL logic)                | LeetCode/GFG |
| Design Circular Queue                       | LeetCode     |
| Detect cycle in linked list                 | LeetCode     |
| Split circular linked list into two halves  | GFG          |

---
