# Tree DFS (Depth-First Search)

Problem Pattern Guide

DFS is the second core traversal pattern after BFS. Unlike BFS, it explores a subtree deeply before backtracking. Most recursive tree problems—structure-based, path-based, property-checking—use DFS.

---

# 1. What is DFS on Trees?

DFS explores:

1. root
2. entire left subtree
3. entire right subtree

Three classical DFS orders:

```
Preorder:  root → left → right
Inorder:   left → root → right
Postorder: left → right → root
```

---

# 2. Why DFS?

DFS unlocks:

* subtree recursion
* parent-to-child propagation
* computing global or local properties
* path-based logic
* identifying structural validity
* detecting height, diameters, imbalance, etc.

---

# 3. Visual Overview

```
             1
           /   \
         2       3
       /  \
      4    5

DFS Preorder: 1, 2, 4, 5, 3
DFS Inorder:  4, 2, 5, 1, 3
DFS Post:     4, 5, 2, 3, 1
```

---

# 4. DFS Template (Recursive)

```
function dfs(node):
    if node == null:
        return
    process(node)     // preorder
    dfs(node.left)
    dfs(node.right)
```

To get inorder or postorder, adjust processing position.

---

# 5. DFS Template (Stack / Iterative)

Preorder:

```
stack = [root]
while stack:
    node = stack.pop()
    process(node)
    if node.right: stack.push(node.right)
    if node.left:  stack.push(node.left)
```

---

# 6. Complexity

* Time: O(n)
* Space:
  Best: O(log n) for balanced trees
  Worst: O(n) for skewed trees
  (due to recursion stack)

---

# 7. When to Use DFS

DFS is best when problems involve:

### 1. Path-based questions

* Root → leaf path sum
* Maximum path
* Print all root-to-leaf paths

### 2. Tree structural questions

* Is tree symmetric?
* Is it a BST?
* Validate a binary tree

### 3. Compute global properties

* Height
* Diameter
* Lowest common ancestor
* Balance check

### 4. Serialization/Deserialization via preorder

Especially for LeetCode-style representation.

---

# 8. Recursion Pattern

For tree problems, this is the **most general** DFS recursion scheme:

```
function dfs(node):
    if node == null:
        return base_value

    left  = dfs(node.left)
    right = dfs(node.right)

    // combine left & right result
    return something_based_on(left, right, node)
```

This is the backbone for many problems like:

* diameter
* height
* max path sum
* balanced tree
* count subtrees with property X

---

# 9. Common Variations

### A. Preorder

Used for building structure or printing.

### B. Inorder

Used for BST-related problems:

* kth smallest
* validate BST

### C. Postorder

Used for calculations that depend on children:

* height
* diameter
* path sums
* balancing

---

# 10. Special DFS Patterns

### 1. Two-recursion-return-values

Sometimes we need two values:

```
return (height, is_balanced)
```

### 2. Passing state down

When path properties depend on ancestors:

```
dfs(node, current_sum)
```

### 3. Global variable pattern

Useful for max path sum / diameter:

```
global best
update best
```

---

# 11. Pitfalls and Edge Cases

* stack overflow on skewed trees (convert to iterative for safety)
* forgetting to handle null nodes
* duplicating work if not returning values properly
* global state incorrectly handled between test cases

---

# 12. Interview Tips

1. State which order you are using (pre/in/post).
2. If subtree property depends on children → use postorder.
3. For BST queries → inorder is natural.
4. For reconstruction tasks → preorder is helpful.
5. Use diagrams when explaining recursion.
6. Mention space complexity including recursion stack.
7. If interviewer mentions very deep trees → suggest iterative DFS.

---

# 13. Practice Problems

### LeetCode

* 94 Inorder Traversal
* 144 Preorder Traversal
* 145 Postorder Traversal
* 104 Maximum Depth
* 110 Balanced Binary Tree
* 124 Binary Tree Maximum Path Sum
* 257 Print Root-to-Leaf Paths
* 653 Two Sum in BST
* 236 Lowest Common Ancestor

### GFG

* Height of tree
* Diameter of tree
* Level order / DFS relation
* Check if tree is balanced

### Codeforces

* Many tree-dp problems use DFS
* Subtree-size, subtree-sum, edge-count problems

---

# 14. Summary

* DFS explores deeply before backtracking.
* Three orders: preorder, inorder, postorder.
* Useful for structural, path-based, and subtree-based problems.
* Complexity O(n) time; recursion stack O(h).
* Master the generic recursion template.

---
