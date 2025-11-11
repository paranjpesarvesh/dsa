# Binary Search Tree (BST)

## 1. Introduction

A **Binary Search Tree (BST)** is a special type of binary tree where every node follows the ordering rule:

```
left subtree  <  node  <  right subtree
```

This invariant ensures efficient operations for searching, inserting, and deleting elements.

BSTs are foundational in DSA and widely used in:

* Databases (indexing)
* Compiler symbol tables
* Range queries
* Priority structures
* Ordered data operations

---

## 2. BST Structure

```
        50
       /  \
     30    70
    / \    / \
  20  40  60  80
```

Each node contains:

* value
* pointer to left child
* pointer to right child

---

## 3. BST Operations Overview

| Operation | Average Time | Worst Time | Notes                          |
| --------- | ------------ | ---------- | ------------------------------ |
| Search    | O(log n)     | O(n)       | Worst when tree becomes skewed |
| Insert    | O(log n)     | O(n)       | Skewness due to sorted input   |
| Delete    | O(log n)     | O(n)       | Most complex operation         |
| Traversal | O(n)         | O(n)       | Inorder gives sorted order     |

---

## 4. Searching in BST

### Logic

* If key == node → found
* If key < node → search left
* If key > node → search right

### ASCII visualization

```
Search for 40:
Start at 50 → go left → 30 → go right → 40 (found)
```

---

## 5. Insertion

### Logic

* Traverse to correct position following BST rules
* Insert new node at leaf position

### Flow

```
Insert 25:
50 → 30 → 20 → insert right of 20
```

---

## 6. Deletion

Deletion has 3 cases:

### Case 1: Node is a leaf

```
   40
  /  \
nil nil
```

Simply remove.

### Case 2: Node has one child

Replace node with its child.

### Case 3: Node has two children

Steps:

1. Find inorder successor (min in right subtree)
2. Replace node value with successor
3. Delete successor

---

## 7. BST Traversals

### 1. Inorder (LNR) → sorted output

```
Left → Node → Right
```

### 2. Preorder (NLR)

```
Node → Left → Right
```

### 3. Postorder (LRN)

```
Left → Right → Node
```

---

## 8. Balanced vs. Unbalanced BST

### Worst case (skewed tree)

```
10
  \
   20
     \
      30
        \
         40
```

Time complexity degrades to **O(n)**.

### Balanced BST

Examples: AVL, Red-Black Tree

Height ≈ log n
Operations always O(log n)

---

## 9. Implementation Templates (Pseudocode)

### Search

```
function search(root, key):
    if root is null: return false
    if key == root.val: return true
    if key < root.val: return search(root.left, key)
    return search(root.right, key)
```

---

### Insert

```
function insert(root, key):
    if root is null: return new Node(key)
    if key < root.val: root.left = insert(root.left, key)
    else: root.right = insert(root.right, key)
    return root
```

---

### Delete

```
function delete(root, key):
    if root is null: return null
    if key < root.val: root.left = delete(root.left, key)
    else if key > root.val: root.right = delete(root.right, key)
    else:
        if no children: return null
        if one child: return child
        successor = findMin(root.right)
        root.val = successor.val
        root.right = delete(root.right, successor.val)
    return root
```

---

## 10. Applications

* Implementing `set`, `multiset`, `map` (C++ STL)
* Data indexing
* Interval management
* Dictionary lookup
* Autocomplete backends

---

## 11. Interview Tips

* Always mention worst-case O(n) due to skewness
* Discuss self-balancing trees (AVL/Red-Black) as improvements
* Be ready to explain deletion cases
* Sketch diagrams to show understanding
* Many interviews ask you to implement BST operations from memory
* Expected coding tasks:

  * Implement insert + search
  * Validate BST
  * LCA in BST
  * Iterative inorder traversal

---

## 12. Common Pitfalls

* Forgetting to handle duplicates
* Mishandling deletion of node with two children
* Incorrect base cases
* Returning wrong root after modifications
* Confusing BST with binary tree (not the same)

---

## 13. Practice Problems

### Easy

* Search in a BST — LeetCode 700
* Insert into BST — LeetCode 701
* Minimum Depth of Binary Tree — LC 111

### Medium

* Delete Node in BST — LC 450
* Validate BST — LC 98
* Trim BST — LC 669
* LCA in BST — LC 235

### Hard

* Recover BST — LC 99
* Convert Sorted Array to BST — LC 108
* Serialize/Deserialize BST variants

---

## 14. Summary Table

| Topic      | Key Insight                         |
| ---------- | ----------------------------------- |
| Search     | Move left/right based on comparison |
| Insert     | Always insert at leaf               |
| Delete     | Handle 3 distinct cases             |
| Traversals | Inorder = sorted order              |
| Complexity | O(h) where h = tree height          |
| Pitfalls   | Skewed trees → O(n)                 |

---

