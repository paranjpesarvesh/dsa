# Binary Tree

A complete and foundational data structure used in almost every area of algorithms: recursion, traversal, tree-based problems, divide-and-conquer, dynamic programming on trees, etc.

This folder contains the **theory**, **implementations**, and **problems** related to binary trees, focusing on building strong core understanding for interview preparation.

---

## 1. What is a Binary Tree?

A **binary tree** is a hierarchical, non-linear data structure where each node has at most two children:

* left child
* right child

General structure:

```
        root
       /    \
    left    right
```

Binary trees are not necessarily:

* sorted (unlike BST)
* complete
* full
* balanced

They only guarantee at most 2 children per node.

---

## 2. Why are Binary Trees Important?

Binary trees form the basis of many advanced structures:

* Binary Search Trees (BST)
* AVL Trees
* Red-Black Trees
* Segment Trees
* Heaps
* Huffman Trees
* Expression Trees

They are heavily used in recursion-based interview problems.

---

## 3. Types of Binary Trees

| Type                       | Definition                                                 |
| -------------------------- | ---------------------------------------------------------- |
| **Full Binary Tree**       | Every node has 0 or 2 children                             |
| **Complete Binary Tree**   | Every level fully filled except last; filled left-to-right |
| **Perfect Binary Tree**    | All leaves at same depth + full                            |
| **Balanced Binary Tree**   | Height = O(log n)                                          |
| **Degenerate Binary Tree** | Every node has only one child (like a linked list)         |

---

## 4. Tree Node Definition

Conceptually:

```
class Node:
    value
    left child
    right child
```

---

## 5. Core Operations

Binary trees support:

* Insertion (usually level-wise)
* Searching (DFS or BFS)
* Traversals:

  * Inorder
  * Preorder
  * Postorder
  * Level-order

---

## 6. Traversal Patterns

### Depth-First Traversals

#### Inorder

```
Left → Root → Right
```

#### Preorder

```
Root → Left → Right
```

#### Postorder

```
Left → Right → Root
```

### Breadth-First Traversal (Level-order)

```
Visit all nodes level by level using queue
```

ASCII example:

```
          1
        /   \
       2     3
     /  \
    4    5

Level order: 1 2 3 4 5
```

---

## 7. Mathematical Intuitions

### Height of Tree

```
height(root) = 1 + max(height(left), height(right))
```

### Max nodes in perfect binary tree:

```
Max nodes = 2^(h) - 1
```

### Min height for n nodes:

```
h = ceil(log2(n+1))
```

---

## 8. Interview Tips

Binary tree questions typically test:

1. **Recursive thinking**
2. **DFS/BFS traversal patterns**
3. **Tree depth/height manipulation**
4. **Understanding of node relationships**
5. **Divide and conquer**

Common interview categories:

* Diameter of binary tree
* Lowest Common Ancestor
* Symmetry check
* Maximum path sum
* Flatten binary tree to linked list
* Right/left view of tree
* Level order variations (zigzag, reverse)

Large companies (FAANG, etc.) frequently use binary tree problems to evaluate problem-solving using recursion.

---

## 9. Common Patterns on Binary Trees

| Pattern                         | Used For               |
| ------------------------------- | ---------------------- |
| DFS recursion                   | subtree-based problems |
| BFS + queue                     | level-based problems   |
| Using height                    | balance, diameter      |
| Using global variables          | max path sum           |
| Stack-based iterative traversal | optimized DFS          |
| Hashing parent pointers         | LCA variations         |

---

## 10. Practice Problems

### Beginner Level

* Maximum depth of binary tree — LeetCode
* Count nodes — GFG
* Level order traversal — LeetCode
* Preorder/inorder/postorder print — basic

### Intermediate Level

* Diameter of binary tree — LeetCode
* Check if balanced — LeetCode
* Symmetric tree — LeetCode
* Path sum problems — LeetCode

### Advanced Level

* Serialize/Deserialize Binary Tree — LeetCode
* Flatten binary tree — LeetCode
* Construct tree from preorder + inorder — LeetCode
* LCA (general binary tree) — LeetCode

---

## Summary

Binary trees form the **core foundation** of understanding recursion, hierarchical data, and efficient algorithm design. Mastering operations and traversal patterns makes solving complex tree problems much easier.
