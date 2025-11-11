# Singly Linked List

A **singly linked list (SLL)** is a linear data structure where each element (node) holds:

* **data**
* **pointer/reference to the next node**

It forms a chain-like structure:

```
head → [data|next] → [data|next] → [data|next] → None
```

---

## Why Singly Linked Lists?

Arrays have limitations:

* fixed size
* costly insertions/deletions in the middle (O(n))

Linked lists provide:

* dynamic resizing
* efficient insertions and deletions at head (O(1))
* easy memory allocation

---

## Structure of a Node

```
Node:
    data
    next pointer
```

In C++:

```
struct Node {
    int data;
    Node* next;
};
```

In Python:

```
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
```

---

## Strengths & Weaknesses

### Strengths

* O(1) insertion at head
* No size limitation
* No shifting of elements

### Weaknesses

* O(n) access time (no random access)
* Takes more memory due to pointers
* Reverse traversing impossible (unlike doubly linked list)

---

## Diagrams & Intuition

### Basic Linked List

```
head
 |
 v
+-----+     +-----+     +-----+
| 10  | --> | 20  | --> | 30  | --> None
+-----+     +-----+     +-----+
```

### Insert at Head (O(1))

```
New node → head → old list
```

```
Before:
head → 10 → 20

Insert 5 at head:
5 → 10 → 20
```

---

## Common Operations

| Operation          | Time | Notes                         |
| ------------------ | ---- | ----------------------------- |
| Insert at head     | O(1) | best use-case                 |
| Insert at tail     | O(n) | can be O(1) with tail pointer |
| Insert at position | O(n) | must traverse                 |
| Delete head        | O(1) | easy                          |
| Delete by value    | O(n) | must search                   |
| Search             | O(n) | linear                        |
| Print/Traverse     | O(n) | linear                        |

---

## Pseudocode for Essential Operations

### Insert at Head

```
insertHead(value):
    node = new Node(value)
    node.next = head
    head = node
```

### Search

```
search(value):
    curr = head
    while curr != None:
        if curr.data == value:
            return True
        curr = curr.next
    return False
```

### Delete by Value

```
deleteValue(value):
    if head == None: return
    if head.data == value:
        head = head.next
        return

    curr = head
    while curr.next != None and curr.next.data != value:
        curr = curr.next

    if curr.next != None:
        curr.next = curr.next.next
```

---

## Interview Insights

Singly Linked Lists are tested heavily for:

1. pointer manipulation
2. recursion understanding
3. reasoning about memory
4. edge cases

Typical questions:

* reverse a linked list
* detect cycle (Floyd’s algorithm)
* find middle of list (fast/slow pointers)
* remove Nth node from end
* merge two sorted linked lists

Interviewers often test edge-case clarity:

* empty list
* single element list
* deletion at head
* insertion at position 0
* multiple consecutive deletions

---

## When Not to Use Linked Lists

* when random access is required (arrays better)
* when memory is tight (pointer overhead)
* when majority of operations are lookups (O(n) bad)

---

## Practice Problems

### Beginner

* Implement all basic operations
* Search for an element
* Count nodes in a list

### Intermediate

* Reverse linked list (iterative + recursive)
* Detect cycle in linked list
* Merge two sorted linked lists

### Advanced

* Clone a linked list with random pointers
* Add two numbers represented as linked lists
* Reorder list (L0 → Ln → L1 → Ln-1)

---

## External Problem Sources

### LeetCode

* Reverse Linked List
* Merge Two Sorted Lists
* Remove Nth Node from End
* Linked List Cycle
* Add Two Numbers

### Codeforces

* Various pointer manipulation problems

### GFG

* All classic linked list operations

---
