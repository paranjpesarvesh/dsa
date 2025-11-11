# AVL Trees — Traversal

## 1. Introduction

Traversal of an AVL Tree is identical to traversal of a regular Binary Search Tree (BST).
Balancing does **not change** how we traverse; it only affects the tree structure (height reduction), not traversal order.

AVL supports all standard tree traversal techniques:

* Inorder (Left → Root → Right)
* Preorder (Root → Left → Right)
* Postorder (Left → Right → Root)
* Level-order (Breadth-first traversal)

---

## 2. Why traversal matters in AVL?

Although AVL maintains balance, the traversal algorithms remain the same. Balancing only ensures:

* Traversal operations always take **O(n)**
* Height is **O(log n)**, so stack depth (if recursion used) is minimized

---

## 3. Basic Traversal Types (ASCII)

### Inorder Traversal

```
     30
    /  \
   20   40
  / \
 10 25

Inorder: 10 → 20 → 25 → 30 → 40
```

### Preorder Traversal

```
Preorder: 30 → 20 → 10 → 25 → 40
```

### Postorder Traversal

```
Postorder: 10 → 25 → 20 → 40 → 30
```

### Level-order Traversal (BFS)

```
Level Order: 30 → 20 → 40 → 10 → 25
```

---

## 4. Traversal Templates (Pseudocode)

### Inorder

```
inorder(node):
    if node is null: return
    inorder(node.left)
    visit(node.key)
    inorder(node.right)
```

### Preorder

```
preorder(node):
    if node is null: return
    visit(node.key)
    preorder(node.left)
    preorder(node.right)
```

### Postorder

```
postorder(node):
    if node is null: return
    postorder(node.left)
    postorder(node.right)
    visit(node.key)
```

### Level-order using Queue

```
level_order(root):
    if root is null: return
    q = new queue
    enqueue root
    while q not empty:
        node = dequeue
        visit(node.key)
        if node.left: enqueue node.left
        if node.right: enqueue node.right
```

---

## 5. Traversal with Stack — Iterative Versions

AVL is height-balanced so stack depth ≤ O(log n).

### Inorder Iterative

```
stack = empty
curr = root
while curr or stack:
    while curr:
        push curr
        curr = curr.left
    curr = pop
    visit(curr.key)
    curr = curr.right
```

### Preorder Iterative

```
stack = [root]
while stack not empty:
    node = pop
    visit(node.key)
    if node.right: push node.right
    if node.left:  push node.left
```

### Level-order already uses queue (BFS)

---

## 6. Complexity Analysis

| Traversal Type | Time | Space                   |
| -------------- | ---- | ----------------------- |
| Inorder        | O(n) | O(h) recursion or stack |
| Preorder       | O(n) | O(h)                    |
| Postorder      | O(n) | O(h)                    |
| Level-order    | O(n) | O(n) queue              |

Since AVL is balanced, h = O(log n).

---

## 7. Variations and Edge Cases

### 1. Handling empty tree

Traversal returns nothing.

### 2. Non-recursive traversal

Useful when recursion is restricted or stack overflow risk exists.

### 3. Handling large trees

Level-order traversal is preferred when processing by layers.

### 4. Traversal with condition

Sometimes we only traverse until a condition is met (e.g., find kth smallest).

### 5. Augmented AVL

If storing subtree sizes, traversal helps to perform order statistics.

---

## 8. Traversal for K-th Smallest Element

Since AVL is a BST:

* Inorder gives sorted sequence
* K-th smallest = K-th visited node in inorder

Pseudo:

```
kth_smallest(node, k):
    use inorder traversal with counter
```

---

## 9. Visual Flowchart for Traversal

```
Start
 |
 v
Select traversal type
 |
 v
Is tree empty?
 |        \
NO         YES → Return
 |
 v
Traverse according to order rules
 |
 v
Visit nodes in sequence
 |
 v
End
```

---

## 10. Interview Tips

### What interviewers test

* Understanding of traversal order
* Ability to write iterative traversals
* Identifying traversal type from output sequence
* Applying traversal efficiently (sorted output, BFS layering)

### Common mistakes

* Misplacing visit() in preorder/postorder
* Forgetting iterative version for preorder/inorder
* Confusing BFS and DFS
* Overusing recursion without considering stack depth

### Good to know

* AVL keeps traversal efficient due to height balancing
* Traversal order remains identical to standard BST traversal
* Using inorder for sorted outputs

---

## 11. Practice Problems

### Beginner

* Print all nodes using inorder, preorder, and postorder
* Compute height using traversal

### Intermediate

* Print AVL tree level by level
* Find k-th smallest element using inorder

### Advanced

* Convert AVL to sorted array
* Print nodes at distance K
* Implement iterative postorder traversal

Suggested sources:

* LeetCode Tree Traversal Problems
* GFG: Tree DFS/BFS
* Codeforces: Tree structure tasks

---

## 12. Summary

* Traversals are unaffected by AVL balancing rules
* AVL guarantees traversal stack depth is small
* DFS → inorder, preorder, postorder
* BFS → level order
* Time complexity always O(n)

