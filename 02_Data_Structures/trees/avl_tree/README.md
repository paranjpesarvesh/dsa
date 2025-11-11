# AVL Trees — README

## Overview

AVL Trees are **self-balancing binary search trees** that guarantee **O(log n)** time for insertion, deletion, and search. They maintain strict height balance using rotations, ensuring no branch becomes more than one level taller than another.

This makes AVL Trees ideal for applications requiring:

* Fast lookup
* Ordered data storage
* Balance guarantees
* Deterministic performance

---

## Key Properties

### 1. Height-Balanced

Every node satisfies:

```
balance_factor = height(left subtree) - height(right subtree)
```

where the valid range is:

```
-1, 0, +1
```

If the balance factor goes outside this range, rotations are applied.

---

### 2. Strict Balance Guarantees

Maximum height = `O(log n)`.

In contrast, plain BST height may degenerate to `O(n)` in worst cases.

---

### 3. Self-Balancing via Rotations

Four rotation cases:

```
LL rotation  → Right Rotate
RR rotation  → Left Rotate
LR rotation  → Left then Right
RL rotation  → Right then Left
```

ASCII illustration:

```
LL Case:
        y                         x
       / \                       / \
      x   T3        →           T1  y
     / \                           / \
    T1 T2                         T2 T3
```

---

## Operations Summary

| Operation | Time Complexity |
| --------- | --------------- |
| Search    | O(log n)        |
| Insert    | O(log n)        |
| Delete    | O(log n)        |
| Traversal | O(n)            |

---

## Why Use AVL Trees?

1. **Very fast lookups** — more strictly balanced than Red-Black Trees.
2. **Guaranteed log-time performance** for all operations.
3. **Predictable behavior**—important in real-time systems.

---

## When NOT to use AVL Trees?

* When *writes* (insertions/deletions) dominate over reads.
* When performance consistency matters less than throughput.
* When simpler tree structures suffice (e.g., random BST or unbalanced).

In those cases, a Red-Black Tree may be preferable due to fewer rotations.

---

## Rotations

### Balance factor logic

```
If bf > 1:
    if left.bf >= 0: LL
    else:            LR

If bf < -1:
    if right.bf <= 0: RR
    else:             RL
```

---

## AVL Tree Applications

1. Language compilers
2. Symbol table implementations
3. Database indexing systems
4. Real-time systems
5. Memory/allocator management
6. Ordered maps/sets (balanced tree-backed)

---

## Comparison with Other BST Variants

| Feature        | AVL Tree | Red-Black Tree | Splay Tree |
| -------------- | -------- | -------------- | ---------- |
| Balance strict | High     | Medium         | Amortized  |
| Lookup speed   | Fastest  | Fast           | Average    |
| Insert/Delete  | Medium   | Faster         | Amortized  |
| Rotations freq | High     | Low            | Depends    |
| Predictable    | Yes      | Yes            | No         |

---

## Implementation Checklist

A correct AVL implementation must:

* Recompute heights after modifications
* Recalculate balance factor
* Detect all four imbalance scenarios
* Apply rotations correctly
* Maintain BST property
* Handle duplicates based on policy
* Update node heights after rotation

---

## Interview Tips

### What companies test

1. **Tree balancing intuition**
   Understand why balance is needed and how AVL ensures it.

2. **Rotation mechanics**
   LL, RR, LR, RL — must describe clearly.

3. **Balance factor calculation**
   Usually they ask to compute BF on a small tree.

4. **Insertion example**
   Given nodes inserted in sequence, identify where imbalance occurs and which rotation fixes it.

5. **Order of operations**
   Height update → BF calculation → Rotation → Final height update.

---

### Common pitfalls in interviews

1. Forgetting to update heights after insertion/deletion
2. Misclassifying LR/RL cases
3. Incorrect successor/predecessor selection during delete
4. Rotations implemented without updating child pointers
5. Confusion between AVL and Red-Black Tree properties

---

## Practice Problems

### Beginner

1. Insert nodes into AVL Tree and output inorder traversal.
2. Implement search in AVL Tree.

### Intermediate

1. Delete a node from an AVL Tree.
2. Given rotation types, restructure a tree.

### Advanced

1. Implement predecessor/successor operations.
2. Implement AVL-based priority map/dictionary.

### Online sources

* LeetCode:

  * Insert into a BST
  * Delete Node in BST
* GFG: AVL Tree insertion & deletion problems
* Codeforces: Occasional problems involving balanced BST-like structures through policy-based data structures

---

