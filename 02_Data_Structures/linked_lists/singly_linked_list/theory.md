# Singly Linked List — Theory

A **singly linked list (SLL)** is a dynamic, pointer-based linear data structure where each node contains:

* **data**
* **pointer/reference to the next node**

Unlike arrays, elements are **not stored contiguously** in memory.

---

## 1. Structure & Definition

A singly linked list node:

```
+------+------+
| data | next |
+------+------+
```

A complete list:

```
head
 |
 v
+-----+    +-----+    +-----+
| 10  | -> | 20  | -> | 30  | -> None
+-----+    +-----+    +-----+
```

---

## 2. Why Use Singly Linked Lists?

### Advantages

* dynamic size
* O(1) insert/delete at head
* no shifting elements (unlike arrays)

### Disadvantages

* O(n) search
* cannot traverse backward
* extra memory for pointer/reference
* less cache-friendly than arrays

---

## 3. Core Operations

### Traversal

```
curr = head
while curr != None:
    visit(curr.data)
    curr = curr.next
```

### Insert at head (O(1))

```
node.next = head
head = node
```

### Insert at tail (O(n) unless you maintain tail pointer)

```
curr = head
while curr.next != None:
    curr = curr.next
curr.next = node
```

### Delete by value (O(n))

```
if head.data == value:
    head = head.next
else:
    find previous node and skip
```

---

## 4. Complexity Table

| Operation           | Time | Space | Notes                  |
| ------------------- | ---- | ----- | ---------------------- |
| Insert head         | O(1) | O(1)  | efficient              |
| Insert tail         | O(n) | O(1)  | O(1) with tail pointer |
| Search              | O(n) | O(1)  | linear                 |
| Delete head         | O(1) | O(1)  | trivial                |
| Delete value        | O(n) | O(1)  | must scan              |
| Access (i-th index) | O(n) | O(1)  | no random access       |

---

## 5. Variations

1. **SLL with tail pointer** (for O(1) tail insert)
2. **Sorted linked list**
3. **Circular linked list**
4. **Linked list with dummy head**
5. **Linked list with random pointer** (advanced)

---

## 6. Important Interview Concepts

### 6.1 Fast & Slow Pointer (Tortoise-Hare)

Used for:

* cycle detection
* finding middle node
* checking palindrome

Pattern:

```
slow = head
fast = head
while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
```

### 6.2 Cycle Detection (Floyd’s Algorithm)

Detects if a loop exists.

### 6.3 Reverse Linked List

Iterative approach:

```
prev = None
curr = head
while curr:
    nxt = curr.next
    curr.next = prev
    prev = curr
    curr = nxt
return prev
```

Recursive version also popular.

---

## 7. Common Pitfalls (Interview-Focused)

* forgetting to update `head` on deletion/insertion
* failing to handle empty list
* pointer overwrites causing memory leaks
* infinite loops due to not updating the pointer
* mixing up `.next.next` in fast pointer logic

---

## 8. Visual Diagrams

### Insert at Head

```
Before:
head → 10 → 20 → None

Insert 5:
node(5) → 10 → 20 → None
head = 5
```

### Delete at Head

```
Before:
head → 5 → 10 → 20

After deleting head:
head → 10 → 20
```

### Reverse Operation Animation

```
None ← 10 ← 20 ← 30 ← head
```

---

## 9. Practice Problems

### Easy

* Print linked list
* Insert/delete at head
* Count nodes
* Search element

### Medium

* Reverse linked list
* Detect cycle
* Remove Nth node from end
* Merge two sorted lists

### Hard

* Copy list with random pointer
* Reorder list (L0 → Ln → L1 → Ln-1)
* Flatten multilevel linked list

---

## 10. References & Suggested Questions

### LeetCode

* Reverse Linked List
* Merge Two Sorted Lists
* Linked List Cycle
* Remove Nth Node From End
* Palindrome Linked List

### Codeforces

* Linked list pointer manipulation tasks

### GFG

* Full linked list practice series

---
