# Doubly Linked List — Theory

---

## 1. Introduction

A **Doubly Linked List (DLL)** is a linear data structure consisting of nodes where each node contains:

* `data`
* pointer to `next` node
* pointer to `prev` node

This extra pointer allows bidirectional traversal, making some operations faster and more flexible compared to a Singly Linked List.

---

## 2. Node Structure

Typical representation:

```
+------+-------+------+
| prev | data  | next |
+------+-------+------+
```

Connections:

```
NULL <- A <-> B <-> C <-> D -> NULL
```

---

## 3. Advantages Over Singly Linked Lists

| Feature                     | Singly Linked List | Doubly Linked List |
| --------------------------- | ------------------ | ------------------ |
| Direction                   | forward only       | forward + backward |
| Insert/Delete at known node | O(n)               | O(1)               |
| Reverse traversal           | complex            | easy               |
| Extra memory required       | low                | high               |

---

## 4. Core Operations (Step-by-Step)

### 4.1 Insert at Head (O(1))

Procedure:

```
newNode->prev = NULL
newNode->next = head
head->prev = newNode
head = newNode
```

### 4.2 Insert at Tail (O(1))

```
newNode->next = NULL
newNode->prev = tail
tail->next = newNode
tail = newNode
```

### 4.3 Delete a Node (O(1) if pointer given)

```
if node.prev != NULL:
    node.prev.next = node.next
if node.next != NULL:
    node.next.prev = node.prev
```

Special handling when node is head or tail.

### 4.4 Search (O(n))

```
curr = head
while curr:
    if curr.data == x:
        return curr
    curr = curr.next
```

---

## 5. Traversal

### Forward Traversal

```
curr = head
while curr:
    print curr.data
    curr = curr.next
```

### Backward Traversal

```
curr = tail
while curr:
    print curr.data
    curr = curr.prev
```

---

## 6. Complexity Analysis

| Operation                   | Time | Space |
| --------------------------- | ---- | ----- |
| Insert head                 | O(1) | O(1)  |
| Insert tail                 | O(1) | O(1)  |
| Delete node (given pointer) | O(1) | O(1)  |
| Delete by value             | O(n) | O(1)  |
| Search                      | O(n) | O(1)  |
| Traversal                   | O(n) | O(1)  |

Space overhead: one extra pointer per node.

---

## 7. Visual Example

```
NULL <- [10]<->[20]<->[30]<->[40] -> NULL
```

Delete 20:

```
NULL <- [10]<->[30]<->[40] -> NULL
```

Insert 25 after 20 (if known pointer):

```
NULL <- [10]<->[20]<->[25]<->[30]<->[40] -> NULL
```

---

## 8. Edge Cases

* Inserting into empty list (`head == NULL`)
* Deleting the only node:

  ```
  head = tail = NULL
  ```
* Not updating prev/next pointers correctly
* Memory leaks (in C++ implementations)
* Handling NULL pointers gracefully

---

## 9. Interview Tips

* DLL is often used as a foundation for:

  * **LRU Cache** (DLL + HashMap)
  * **Big integers (add/remove digits)**
  * **Deque implementation**
* Common mistakes:

  * forgetting to update `prev` pointer on insert/delete
  * mishandling head/tail updates
* Many interviewers test pointer manipulation skills using DLL problems.

---

## 10. Practice Problems

### Easy

* Implement DLL with all operations
* Reverse a DLL
* Convert DLL to array

### Medium

* Flatten multilevel DLL (LeetCode 430)
* Delete all occurrences of a value
* Merge two DLLs

### Hard

* Implement LRU Cache (LeetCode 146)
* Implement Deque using DLL
* Insert in sorted DLL

---

## 11. Summary

Doubly Linked Lists offer flexibility with quick local updates and bidirectional traversal. They are useful in real-world systems and a common stepping stone to more advanced structures.

This section focuses on clear understanding and system-level intuition so that interviews involving pointer-heavy code become straightforward.

