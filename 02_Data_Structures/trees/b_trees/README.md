# B-Trees: Overview

## 1. Introduction

A **B-Tree** is a self-balancing, multi-way search tree optimized for systems that read/write large blocks of data (databases, filesystems). Unlike binary trees, a B-tree node can contain **many keys and children**, reducing height and minimizing disk I/O.

B-trees guarantee:

* `O(log n)` search
* `O(log n)` insertion
* `O(log n)` deletion
* All leaves lie at the same depth (perfectly balanced)
* Good cache locality; minimal disk accesses

## 2. Structure of a B-Tree Node

Each node contains:

* Up to `2t - 1` keys (t = minimum degree)
* Up to `2t` child pointers
* Keys stored **sorted**
* Children pointers divide key ranges

For example, a node with keys `[10, 20, 30]` has 4 children:

```
child0 | 10 | child1 | 20 | child2 | 30 | child3
```

## 3. Properties

A B-Tree of minimum degree `t` satisfies:

| Property         | Meaning                          |
| ---------------- | -------------------------------- |
| Node key range   | `[t−1, 2t−1]` keys (except root) |
| Node child range | `[t, 2t]` children (except root) |
| Root             | may have fewer keys (≥1)         |
| All leaves       | are at the same depth            |
| Keys             | stored in sorted order           |

## 4. Why B-Trees?

Because minimizing height reduces disk/SSD seeks:

Height of a B-Tree:

```
h = O(log_t n)
```

For large `t`, height becomes extremely small.

Typical use cases:

* Databases (MySQL, PostgreSQL)
* Filesystems (NTFS, ext4, HFS+)
* Indexing systems
* Large-scale storage engines

## 5. Operations Summary

### Searching

Search inside each node (linear or binary search), then move to the appropriate child.

### Insertion

Uses **top-down splitting**:

1. If the child you're about to descend into is full → **split first**
2. Insert into a guaranteed non-full node
3. Height increases only when root becomes full

### Deletion (high-level)

Multiple cases:

1. Key in leaf → remove directly
2. Key in internal node → replace with predecessor/successor
3. Borrow/merge siblings if underflow occurs

Deletion is more complex than insertion.

## 6. Traversal

Traverse like an in-order traversal of multi-way tree:

```
for each i:
   traverse child[i]
   output key[i]
traverse last child
```

This produces **sorted order**.

## 7. Complexity Analysis

| Operation | Time     | Notes                           |
| --------- | -------- | ------------------------------- |
| Search    | O(log n) | node-local operations + descent |
| Insert    | O(log n) | may split nodes                 |
| Delete    | O(log n) | several balancing cases         |
| Space     | O(n)     | stored in nodes across levels   |

## 8. Visual Diagram

```
               [10 | 20]
             /      |      \
        [2 5 7]  [12 15]  [22 27 30]
```

Traversing outputs:

```
2 5 7 10 12 15 20 22 27 30
```

## 9. Interview Tips

1. Understand **why B-Trees exist** — disk access optimization.
2. Be able to explain:

   * Node capacity limits
   * Search mechanics
   * Insertion split strategy
   * Why deletion is tricky
3. Know the differences between:

   * B-Tree vs BST
   * B-Tree vs B+ Tree (very common interview question)
4. B+ Tree specifics (not covered here):

   * All keys repeated in leaves
   * Leaves linked for range queries
   * Used in almost all databases

Common FAANG-style questions include:

* Implement search
* Implement insertion
* Explain deletion cases
* Compare with AVL/red-black tree

## 10. Typical Practice Problems

| Problem                    | Source |
| -------------------------- | ------ |
| Implement B-Tree search    | Custom |
| Implement B-Tree insertion | Custom |
| Compare B-Tree vs B+ Tree  | Theory |
| Range queries in B+ tree   | DBMS   |
| Height of a B-Tree         | GFG    |
| B-Tree deletion edge cases | GFG    |

## 11. Key Differences from Other Trees

| Structure          | Height   | Balance | Use Case      |
| ------------------ | -------- | ------- | ------------- |
| Binary Search Tree | O(n)     | None    | Basic         |
| AVL Tree           | O(log n) | Strong  | CPU-oriented  |
| Red-Black Tree     | O(log n) | Medium  | Maps, sets    |
| B-Tree             | O(log n) | Strong  | Disk-oriented |
| B+ Tree            | O(log n) | Strong  | Databases     |

## 12. Summary

A B-tree is:

* Balanced
* Wide (high branching factor)
* Disk-friendly
* Ideal for database indexing

It trades having **many keys per node** to reduce height and speed up search.

This concludes the B-Trees README.

