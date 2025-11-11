# AVL Trees — Theory

## 1. Introduction

An AVL Tree is a **self-balancing binary search tree** named after its inventors (Adelson-Velsky and Landis). It maintains a tight balance constraint ensuring the tree height remains **O(log n)** at all times.

Balance is enforced automatically during insertion and deletion using **rotations**.

```
BST + Self-Balancing → AVL Tree
```

---

## 2. Node Structure

An AVL Tree node typically contains:

```
key
left child pointer
right child pointer
height
```

The `height` is needed to calculate balance factors.

---

## 3. Balance Factor (BF)

```
BF(node) = height(left subtree) – height(right subtree)
```

AVL allows:

```
BF ∈ { -1, 0, +1 }
```

ALWAYS enforce this balance after every insert/delete.

ASCII Illustration:

```
         A
        / \
       B   C
      / \
     D   E

BF(A) = 2 - 1 = 1
BF(B) = 1 - 1 = 0
```

---

## 4. Height Calculation

Height of a node:

```
height(node) = 1 + max(height(left), height(right))
```

Base case:

```
height(NULL) = 0
```

---

## 5. Rotations: Core Concept

When BF goes outside allowed range, we perform rotations.

There are FOUR imbalance types:

### 1. LL (Left-Left)

Right rotation needed.

```
        z
       /
      y
     /
    x
```

### 2. RR (Right-Right)

Left rotation needed.

```
    z
     \
      y
       \
        x
```

### 3. LR (Left-Right)

Left rotate on left child, then right rotate.

```
      z
     /
    y
     \
      x
```

### 4. RL (Right-Left)

Right rotate on right child, then left rotate.

```
    z
     \
      y
     /
    x
```

---

## 6. Rotation Mechanics (ASCII)

### Right Rotation (for LL)

```
        y
       / \
      x   T3            x
     / \               / \
    T1  T2     →      T1  y
                       / \
                      T2  T3
```

### Left Rotation (for RR)

```
    x                         y
     \                       / \
      y          →          x   T3
       \                   / \
        T3               T1  T2
```

---

## 7. Insertion Logic

Insertion follows:

1. Insert like a BST
2. Update height of all ancestors
3. Compute balance factor
4. Detect imbalance case
5. Apply needed rotation(s)

Pseudo-Template:

```
insert(node, key):
    if node is null:
        return new node

    if key < node.key:
        node.left = insert(node.left, key)
    else if key > node.key:
        node.right = insert(node.right, key)
    else:
        return node   // duplicates policy

    update height(node)

    bf = balance_factor(node)

    if bf > 1 and key < node.left.key: return rightRotate(node)
    if bf < -1 and key > node.right.key: return leftRotate(node)
    if bf > 1 and key > node.left.key:
         node.left = leftRotate(node.left)
         return rightRotate(node)
    if bf < -1 and key < node.right.key:
         node.right = rightRotate(node.right)
         return leftRotate(node)

    return node
```

---

## 8. Deletion Logic

Steps:

1. Delete like a BST
2. Update height
3. Check imbalance
4. Apply rotations based on BF of node and child

Pseudo-Template:

```
delete(node, key):
    if node is null: return node

    if key < node.key:
        node.left = delete(node.left, key)
    else if key > node.key:
        node.right = delete(node.right, key)
    else:
        if node has at most 1 child:
            replace node with child
        else:
            successor = min(node.right)
            node.key = successor.key
            node.right = delete(node.right, successor.key)

    update height(node)

    bf = balance_factor(node)

    if bf > 1 and balance_factor(node.left) >= 0: return rightRotate(node)
    if bf > 1 and balance_factor(node.left) < 0:
         node.left = leftRotate(node.left)
         return rightRotate(node)
    if bf < -1 and balance_factor(node.right) <= 0: return leftRotate(node)
    if bf < -1 and balance_factor(node.right) > 0:
         node.right = rightRotate(node.right)
         return leftRotate(node)

    return node
```

---

## 9. Time and Space Complexity

| Operation  | Time     | Space              |
| ---------- | -------- | ------------------ |
| Search     | O(log n) | O(log n) recursion |
| Insert     | O(log n) | O(log n)           |
| Delete     | O(log n) | O(log n)           |
| Traversals | O(n)     | O(h)               |

Space complexity depends on recursion depth.

---

## 10. Variations & Edge Cases

### Duplicate keys

Options:

* Disallow duplicates
* Store frequency count
* Insert duplicates in a specific subtree (common)

### Very skewed insert sequences

AVL still maintains balance automatically.

### Deletion from leaf

Handled naturally with no rotations most of the time.

### Chain updates

Multiple ancestors may require rotations (but at most one per insertion).

---

## 11. Visual Flowchart

```
Insert Key
   |
   v
Insert in BST
   |
   v
Update heights
   |
   v
Compute BF
   |
   +--- Balanced? YES → done
   |
   NO
   |
   v
Determine case (LL/LR/RR/RL)
   |
   v
Perform rotation
   |
   v
Tree balanced
```

---

## 12. Interview Tips

### What interviewers expect

* Strong understanding of balancing
* Ability to identify rotation type
* Perform one insertion manually
* Explain time complexity
* Compare with Red-Black Trees

### Frequently asked questions

1. Why is height balancing needed?
2. Show imbalance after inserting sequence A, B, C, …
3. Difference between LL and LR cases?
4. Which is stricter: AVL or Red-Black Tree?
5. Why store height in node?

### Things candidates forget

* Updating heights after rotation
* Identifying LR/RL case correctly
* Handling deletion corner cases

---

## 13. Practice Problems

### Basic

1. Insert nodes and print inorder
2. Compute height of AVL tree

### Intermediate

1. Implement deletion in AVL
2. Given tree snapshots, identify rotation needed

### Advanced

1. Implement map/set using AVL
2. Add functionality for predecessor/successor queries

### Suggested links

* LeetCode: BST Insertion, BST Deletion
* GFG: AVL insertion/deletion
* CP platforms: required tree balancing tasks

---
