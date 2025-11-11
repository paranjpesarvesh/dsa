# Binary Search Tree (BST) — Theory

## 1. Definition

A **Binary Search Tree (BST)** is a binary tree with the following ordering property:

```
For every node:
    all nodes in left subtree  <  node.value
    all nodes in right subtree >  node.value
```

BSTs provide efficient searching, insertion, and deletion when balanced.

---

## 2. BST Structure (Illustration)

```
            8
          /   \
        3       10
      /  \        \
     1    6        14
         / \       /
        4   7     13
```

---

## 3. Key Properties

1. Inorder traversal produces sorted order.
2. Height determines performance:

   * Best-case: O(log n)
   * Worst-case: O(n) → skewed tree.
3. No fixed balancing (unlike AVL/Red-Black Trees).

---

## 4. Operations Explained

### 1. Search

Logic:

* If key == current node → found
* If key < current node → go left
* If key > current node → go right

Flow example:

```
Search 6:
8 → left → 3 → right → 6 found
```

---

### 2. Insertion

Basic idea:

* Navigate the tree using BST property
* Insert new node at leaf position

Example:

```
Insert 5:
8 → 3 → 6 → insert left of 6
```

---

### 3. Deletion

Three cases:

#### Case A: Node has no children

Remove directly.

#### Case B: Node has one child

Replace node with its child.

#### Case C: Node has two children

Steps:

1. Find the inorder successor (smallest in right subtree)
2. Replace node value with successor’s value
3. Delete successor node

---

## 5. Traversals

Visual summary:

```
Inorder   → Left  Node Right  → Sorted
Preorder  → Node Left  Right  → Tree construction help
Postorder → Left Right Node   → Safe deletion order
Levelorder → BFS-style
```

Traversal table:

| Type        | Output Purpose                 |
| ----------- | ------------------------------ |
| Inorder     | Sorted order                   |
| Preorder    | Copy tree / prefix notation    |
| Postorder   | Delete tree / postfix notation |
| Level Order | BFS traversal                  |

---

## 6. Complexity Analysis

| Operation | Time (Average) | Time (Worst) | Space |
| --------- | -------------- | ------------ | ----- |
| Search    | O(log n)       | O(n)         | O(h)  |
| Insert    | O(log n)       | O(n)         | O(h)  |
| Delete    | O(log n)       | O(n)         | O(h)  |
| Traversal | O(n)           | O(n)         | O(h)  |

where `h` = height of tree.

---

## 7. Edge Cases

1. **Duplicates**

   * Common policies:

     * store duplicates in left subtree
     * or maintain a count at node

2. **Skewed Tree**
   Example for sorted insert:

```
1
 \
  2
   \
    3
     \
      4
```

3. **Empty Tree**
   All ops must handle null root gracefully.

---

## 8. Pseudocode Templates

### Insert

```
function insert(root, key):
    if root is null: return new Node(key)
    if key < root.val:
         root.left = insert(root.left, key)
    else:
         root.right = insert(root.right, key)
    return root
```

### Search

```
function search(root, key):
    if root is null: return false
    if key == root.val: return true
    if key < root.val:
         return search(root.left, key)
    return search(root.right, key)
```

### Delete

```
function delete(root, key):
    if root is null: return null
    if key < root.val:
         root.left = delete(root.left, key)
    else if key > root.val:
         root.right = delete(root.right, key)
    else:
         if root has no children:
             return null
         if root has one child:
             return child
         succ = minNode(root.right)
         root.val = succ.val
         root.right = delete(root.right, succ.val)
    return root
```

---

## 9. Interview Patterns & Tips

1. Always mention:

   * BST worst-case degeneration
   * balancing solves this (leads to AVL/Red-Black discussion)

2. Common interview tasks:

   * validate BST (LC 98)
   * find LCA in BST (very trivial due to ordering)
   * iterative inorder traversal using stack
   * delete node in BST

3. Show understanding of deletion case-handling.

4. Write clean and structured code with recursion.

---

## 10. Practice Problems

### Easy

* Search in BST — LeetCode 700
* Insert into BST — LeetCode 701
* Range Sum of BST — LC 938

### Medium

* Trim BST — LC 669
* Validate BST — LC 98
* BST Iterator — LC 173

### Hard

* Recover Binary Search Tree — LC 99
* Serialize/Deserialize BST variants

---

## 11. Summary

A BST offers:

* ordered data storage
* efficient search/insert/delete on balanced trees
* sorted-order traversal
* useful building block for advanced trees (AVL, RB-tree)

Understanding BST deeply sets the foundation for mastering tree-based algorithms.

---
