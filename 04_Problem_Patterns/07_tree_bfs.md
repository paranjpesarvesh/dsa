# Tree BFS (Breadth-First Search)

Problem Pattern Guide

BFS on trees is a core interview pattern that helps solve level-order traversal, shortest path on unweighted graphs, tree serialization, etc. This document explains the intuition, templates, diagrams, and problem sets.

---

# 1. What is BFS on Trees?

BFS is a level-by-level traversal using a queue.
In a tree, BFS ensures that we visit nodes in increasing order of depth.

General order:

```
Root → Level 1 → Level 2 → Level 3 → ...
```

---

# 2. Intuition

BFS answers questions like:

* What is the depth/height of the tree?
* What is the average/maximum value per level?
* Is the tree symmetric?
* Right/left view of tree?
* Zigzag/spiral traversal?

Because BFS naturally moves level by level, many per-level calculations become trivial.

---

# 3. Visual Flow Diagram

```
             1
           /   \
         2       3
       /  \     /  \
      4    5   6    7

Queue operations:
Start: [1]
Visit 1 → push children 2,3 → [2,3]
Visit 2 → push children 4,5 → [3,4,5]
Visit 3 → push children 6,7 → [4,5,6,7]
...
```

Traversal order:
1, 2, 3, 4, 5, 6, 7

---

# 4. Core Template

Pseudocode:

```
function bfs(root):
    if root == null: return
    q = queue()
    q.push(root)
    while q not empty:
        node = q.pop()
        process(node)
        if node.left:  q.push(node.left)
        if node.right: q.push(node.right)
```

Time: O(n)
Space: O(n) in worst case

---

# 5. Level-order Template (Most Useful)

Useful when computing something per level.

```
function level_order(root):
    if root == null: return []
    q = queue()
    q.push(root)
    result = []
    while q not empty:
        size = q.size()
        level = []
        repeat size times:
            node = q.pop()
            level.append(node.val)
            if node.left: q.push(node.left)
            if node.right: q.push(node.right)
        result.append(level)
    return result
```

---

# 6. Key Variations (Frequently Asked in Interviews)

### 1. Level Order Traversal (simple)

Standard BFS.

### 2. Zigzag Level Order Traversal

At even levels traverse left→right
At odd levels traverse right→left.

### 3. Right View / Left View of Binary Tree

For each level: pick first/last node.

### 4. Average of Levels

Sum level values / count nodes.

### 5. Maximum Width of Binary Tree

Track indices per level.

### 6. Min depth / max depth

Minimum depth can be found by stopping BFS at first leaf.

### 7. Connect Nodes at Same Level (Next Pointers)

Use BFS to link nodes horizontally.

### 8. Serialize / Deserialize Tree

Level order representation supports null markers.

---

# 7. Edge Cases

* Empty tree
* Single node
* Skewed trees (degenerate trees)
* Complete trees
* Perfect trees

Space complexity changes based on tree shape.

---

# 8. Important Observations

1. BFS ensures shortest path on unweighted trees.
2. Queue is mandatory.
3. Each node is visited exactly once.
4. Complexity always O(n) where n = number of nodes.
5. For binary tree, at most 2 child pushes per pop.

---

# 9. Interview Tips

* Mention queue explicitly when explaining BFS.
* Highlight per-level processing.
* If asked to compute something per level → BFS is usually the answer.
* DFS can also do level calculations but BFS is more intuitive.
* For min depth → use BFS, not DFS.
* Know how to handle null nodes for serialization (LeetCode-style).

---

# 10. Common Problems

### LeetCode

* 102 Binary Tree Level Order Traversal
* 107 Bottom-Up Level Order Traversal
* 199 Binary Tree Right Side View
* 429 N-ary Tree Level Order Traversal
* 515 Find Largest Value in Each Tree Row
* 637 Average of Levels in Binary Tree
* 116 Populating Next Right Pointers in Each Node
* 117 Populating Next Right Pointers II
* 111 Minimum Depth of Binary Tree

### GFG

* Level order traversal of binary tree
* Left view of binary tree
* Maximum width of binary tree

### Codeforces / General

* BFS on general graphs (trees are special case)
* Problems requiring shortest path computations

---

# 11. Summary

* BFS = level-by-level traversal using a queue.
* Ideal for problems requiring per-level insights.
* Core pattern widely used in interviews.
* Time complexity O(n), space O(n).
* Variations appear frequently: zigzag, views, averages, min depth, width, next-pointers.

---
