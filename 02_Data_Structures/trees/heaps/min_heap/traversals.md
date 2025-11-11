# Min Heap Traversals

A **Min Heap** is a complete binary tree with the property that every node is smaller than or equal to its children. While heaps are primarily used for efficient priority operations (insert, extract-min), traditional tree traversals (inorder, preorder, postorder) also apply — though they have limited practical use for heaps.

This file covers traversal techniques, properties, complexity, diagrams, and interview insights.

---

## 1. Why Traversals Are Different for Heaps

Unlike BSTs, heaps do **not** enforce an order among siblings or subtrees beyond the min-at-top rule. Therefore:

* **Inorder traversal does not produce a sorted list**
* **Traversal order is not meaningful for search**
* **Traversals are mainly for debugging or visualization**

To get sorted output, we must repeatedly extract-min (heap sort).

---

## 2. Visual Heap Structure

Example Min Heap:

```
        2
      /   \
     7     3
    / \   / \
   9  11 5   12
```

Array representation:

```
[2, 7, 3, 9, 11, 5, 12]
```

---

## 3. Types of Traversals

### 1. Preorder (Root → Left → Right)

Pseudocode:

```
preorder(i):
    if i >= n: return
    visit(i)
    preorder(2*i + 1)
    preorder(2*i + 2)
```

Output example:

```
2 7 9 11 3 5 12
```

### 2. Inorder (Left → Root → Right)

Pseudocode:

```
inorder(i):
    if i >= n: return
    inorder(2*i + 1)
    visit(i)
    inorder(2*i + 2)
```

Output example:

```
9 7 11 2 5 3 12
```

Note: Not sorted.

### 3. Postorder (Left → Right → Root)

Pseudocode:

```
postorder(i):
    if i >= n: return
    postorder(2*i + 1)
    postorder(2*i + 2)
    visit(i)
```

Output example:

```
9 11 7 5 12 3 2
```

### 4. Level Order (Breadth-first)

This is the most relevant traversal for heaps.

Since heaps are stored in arrays:

```
for i in 0..n-1:
    visit(i)
```

Output example:

```
2 7 3 9 11 5 12
```

---

## 4. Traversal Complexity

All recursive tree traversals cover each node exactly once.

| Traversal Type | Time Complexity | Space Complexity       |
| -------------- | --------------- | ---------------------- |
| Preorder       | O(n)            | O(h) = O(log n)        |
| Inorder        | O(n)            | O(h)                   |
| Postorder      | O(n)            | O(h)                   |
| Level Order    | O(n)            | O(1) or O(n) for queue |

Heap height: O(log n)

---

## 5. When Traversals Are Used

Primarily:

* Debugging internal heap structure
* Visualizing heap structure for learning
* Validating heap property after operations

Not used for:

* Searching (not efficient)
* Sorting (needs extract-min loop)
* Path queries like BST

---

## 6. ASCII Flowchart

### Preorder

```
Visit root
   |
left subtree
   |
right subtree
```

### Level Order

```
Queue ← root
while queue not empty:
    pop node
    push children
```

---

## 7. Interview Notes

What you should remember:

* Traversals exist, but don't provide meaningful sorted order.
* Heaps are designed for priority access, not search or traversal-based algorithms.
* Many interviewers ask:

  * "Does inorder traversal give sorted output?" (Answer: No)
  * "How do you get sorted list from heap?" (Use heap sort)
  * "Why array representation is more efficient?" (Implicit tree)

Important detail:
Heap property only ensures order between parent and children, not between siblings.

---

## 8. Practice Problems

These emphasize traversal-related concepts or visualization:

### LeetCode

* 295. Find Median from Data Stream
* 373. Find K Pairs with Smallest Sums
* 871. Minimum Refueling Stops
* 703. Kth Largest Element in a Stream

### GFG

* Heap traversals
* Print heap tree level-wise

### Codeforces

* Greedy + heap simulation problems

---

## 9. Summary

* Traversals exist but are not central to heap operations.
* Preorder, inorder, postorder work but lack semantic meaning.
* Level-order traversal best reflects heap structure.
* For sorted output, use extract-min repeatedly.

---
