# BST Traversals

This document explains all important traversal methods specifically within the context of **Binary Search Trees (BSTs)**. Traversal is fundamental for understanding how BST nodes are processed and how they reflect the sorted order property.

---

## 1. Why Traversals Matter in BSTs

Traversals allow us to:

* Visit every node exactly once.
* Access structural and logical relationships between nodes.
* Extract sorted order (via inorder traversal).
* Perform common operations such as find-min, find-max, get k-th smallest, etc.

---

## 2. Types of Traversals

### Depth-First Traversals (DFS)

1. **Inorder (Left, Node, Right)**

   * Produces sorted order in BST
   * Most important traversal for BST-specific operations

2. **Preorder (Node, Left, Right)**

   * Used to clone the tree
   * Helpful in generating prefix expression form

3. **Postorder (Left, Right, Node)**

   * Used to delete the tree safely
   * Produces postfix notation

### Breadth-First Traversal (BFS)

4. **Level Order Traversal**

   * Visits nodes level by level
   * Implemented using a queue

---

## 3. Visual Example

Given BST:

```
        8
       / \
      3  10
     / \   \
    1  6    14
      / \   /
     4   7 13
```

Traversal outputs:

| Traversal Type | Output               |
| -------------- | -------------------- |
| Inorder        | 1 3 4 6 7 8 10 13 14 |
| Preorder       | 8 3 1 6 4 7 10 14 13 |
| Postorder      | 1 4 7 6 3 13 14 10 8 |
| Level Order    | 8 3 10 1 6 14 4 7 13 |

---

## 4. Traversal Pseudocode

### Inorder Traversal (Recursive)

```
inorder(node):
    if node is null: return
    inorder(node.left)
    visit(node)
    inorder(node.right)
```

### Preorder Traversal (Recursive)

```
preorder(node):
    if node is null: return
    visit(node)
    preorder(node.left)
    preorder(node.right)
```

### Postorder Traversal (Recursive)

```
postorder(node):
    if node is null: return
    postorder(node.left)
    postorder(node.right)
    visit(node)
```

### Level Order Traversal (BFS)

```
levelorder(root):
    queue = [root]
    while queue not empty:
        node = queue.pop_front()
        visit(node)
        if node.left: queue.push(node.left)
        if node.right: queue.push(node.right)
```

---

## 5. Iterative Approaches

### Inorder (Using Stack)

```
stack = []
curr = root
while curr not null or stack not empty:
    while curr not null:
        stack.push(curr)
        curr = curr.left
    curr = stack.pop()
    visit(curr)
    curr = curr.right
```

### Preorder (Using Stack)

```
stack = [root]
while stack not empty:
    node = stack.pop()
    visit(node)
    if node.right: stack.push(node.right)
    if node.left: stack.push(node.left)
```

### Postorder (Using Two Stacks OR Modified Preorder)

Approach using two stacks:

```
s1 = [root]
s2 = []
while s1 not empty:
    node = s1.pop()
    s2.push(node)
    if node.left: s1.push(node.left)
    if node.right: s1.push(node.right)
while s2 not empty:
    visit(s2.pop())
```

---

## 6. Important BST-Specific Notes

### Sorted Property in Inorder

Because of BST ordering:

```
left < node < right
```

**Inorder traversal always yields a sorted list of keys.**

This enables:

* Finding kth smallest element
* Computing floor/ceil
* Range queries
* Validating BST structure

---

## 7. Complexity Summary

| Traversal  | Time | Space (Worst-case) |
| ---------- | ---- | ------------------ |
| Inorder    | O(n) | O(h)               |
| Preorder   | O(n) | O(h)               |
| Postorder  | O(n) | O(h)               |
| Levelorder | O(n) | O(n)               |

`h = height of tree`

---

## 8. Variations & Edge Cases

1. **Iterative vs Recursive**

   * Recursion simpler
   * Iteration avoids stack overflow on skewed tree

2. **Empty Tree**

   * Handle null root cleanly

3. **Skewed Tree**
   Complexity goes from O(log n) → O(n) for space as well

4. **Morris Traversal**

   * Inorder without extra space
   * Good for interview edge-case questions

---

## 9. Morris Traversal (Bonus)

Inorder without recursion or stack:

Idea:

* Use empty right pointers of predecessor nodes to thread the tree temporarily.

Properties:

* Time: O(n)
* Space: O(1)

Used mainly in interview discussions to show deep understanding.

---

## 10. Interview Tips

1. Always differentiate BST traversal from generic tree traversal (specifically inorder).
2. Emphasize sorted-order property.
3. Know both recursive & iterative approaches.
4. Be comfortable writing stack-based inorder traversal.
5. BST-specific problems often rely on traversal patterns:

   * Validate BST
   * Range queries
   * kth smallest element
   * Floor/Ceil operations

---

## 11. Practice Problems

### Easy

* Binary Tree Inorder Traversal (LC 94)
* Binary Tree Preorder Traversal (LC 144)
* Binary Tree Postorder Traversal (LC 145)
* Level Order Traversal (LC 102)

### Medium

* Kth smallest element in BST (LC 230)
* Validate BST (LC 98)
* BST Iterator (LC 173)

### Hard

* Recover BST (LC 99)
* Vertical Order / Boundary Traversal variants

---

## Summary

Traversal is the key to unlocking BST’s structural and logical properties.
Mastering recursive and iterative traversal techniques forms the foundation for solving most tree-related interview problems.

---
