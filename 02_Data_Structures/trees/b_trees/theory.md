# B-Trees: Theory

## 1. Introduction

A **B-Tree** is a self-balancing multi-way search tree optimized for systems where data is read/written in large blocks (disk, SSD, database storage engines). It reduces disk access by increasing branching factor, resulting in a very shallow height.

It generalizes BSTs by allowing **multiple keys per node** and **multiple children**.

---

## 2. Structure of a B-Tree Node

A B-tree node contains:

* `keys[]` → sorted keys
* `children[]` → pointers/subtrees
* `n` → number of keys currently stored
* `leaf` → boolean (is leaf or not)

### Example Node Layout (t = minimum degree):

For a node with 3 keys `[10, 20, 30]`:

```
child0 | 10 | child1 | 20 | child2 | 30 | child3
```

Maximum keys = `2t - 1`
Minimum keys (except root) = `t - 1`

---

## 3. Properties of a B-Tree

A B-tree of minimum degree `t` satisfies:

1. Every node has at most `2t` children.
2. Every node except root has at least `t` children.
3. Root has at least 1 key.
4. All leaves appear at the same depth.
5. Keys in each node are sorted.
6. Each child subtree is bounded by keys.

---

## 4. Height of a B-Tree

Height grows very slowly due to high branching factor.

Height formula:

```
h = O(log_t n)
```

This means even with millions of keys, height is often ≤ 3–4 levels.

---

## 5. Searching in a B-Tree

Search operation steps:

1. Perform binary search (or linear search) inside the node.
2. If key found → return success.
3. Else follow appropriate child pointer.
4. Repeat until leaf is reached or found.

Pseudo:

```
Search(node, k):
    i = first index where key[i] >= k
    if key[i] == k: return true
    if leaf: return false
    return Search(child[i], k)
```

Time complexity:

```
O(log n) overall
```

---

## 6. Insertion in a B-Tree

Insertion is performed **top-down** to avoid backtracking.

High-level algorithm:

1. If root is full → split root → increase height by 1.
2. Descend to correct child.
3. Before descending, if child is full → split.
4. Insert key in a guaranteed non-full node.

### Node splitting (key idea)

Split full node:

```
[ k0 k1 k2 k3 k4 ]   (5 keys, full for t=3)

middle key = k2
left = [k0 k1]
right = [k3 k4]
```

Middle key moves up to parent.

---

## 7. Deletion Overview

Deletion is more complex. Cases:

1. Key in leaf → remove directly.
2. Key in internal node:

   * Replace with predecessor OR successor.
3. Borrow from sibling if underflow occurs.
4. Merge siblings if needed.

Goal: maintain node capacity between `[t-1, 2t-1]`.

---

## 8. Traversal (In-order)

For a node with keys `[k1, k2, k3]`:

```
Traverse(child0)
Visit k1
Traverse(child1)
Visit k2
Traverse(child2)
Visit k3
Traverse(child3)
```

Produces sorted order of keys.

---

## 9. Complexity Analysis

| Operation | Time Complexity | Notes              |
| --------- | --------------- | ------------------ |
| Search    | O(log n)        | shallow tree       |
| Insert    | O(log n)        | may involve splits |
| Delete    | O(log n)        | borrow/merge cases |
| Space     | O(n)            | stores all keys    |

---

## 10. Comparison with Other Trees

### B-Tree vs AVL / Red-Black Tree

| Feature       | AVL/RBT | B-Tree                          |
| ------------- | ------- | ------------------------------- |
| Keys per node | 1       | several                         |
| Children      | 2       | multiple                        |
| Height        | medium  | small                           |
| Used for      | RAM     | Disk                            |
| Range queries | OK      | Excellent (especially B+ trees) |

### B-Tree vs B+ Tree

| Aspect                 | B-Tree    | B+ Tree         |
| ---------------------- | --------- | --------------- |
| Keys in internal nodes | All keys  | Only separators |
| Leaves                 | hold data | hold all data   |
| Leaf linking           | optional  | always linked   |
| Range queries          | slower    | fast            |
| DB usage               | rare      | dominant        |

---

## 11. Visual Example

```
              [10 | 20]
            /      |      \
        [2 5 7]  [12 15]  [22 27 30]
```

In-order output:

```
2 5 7 10 12 15 20 22 27 30
```

---

## 12. Interview Tips

1. Know why B-trees matter: I/O reduction.
2. Always mention minimum degree `t`.
3. Understand split logic.
4. Be ready to compare with B+ trees.
5. For deletion:

   * Be able to list all cases (borrowing, merging).

Typical interview questions:

* Implement search in a B-tree.
* Explain the split procedure.
* Give worst-case height formula.
* Compare B-tree with binary trees and AVL/RBT.
* When would you use a B+ tree instead?

---

## 13. Practice Problems

| Problem                               | Source |
| ------------------------------------- | ------ |
| Implement B-Tree insertion            | Custom |
| Implement B-Tree search               | Custom |
| Minimum height of B-tree              | GFG    |
| Deletion case handling                | GFG    |
| Difference between B-tree and B+ tree | Theory |
| Range queries in B+ trees             | DBMS   |

---

## 14. Summary

A B-tree provides:

* Multi-way branching
* Balanced structure
* Logarithmic operations
* Excellent disk locality
* Ideal structure for indexing large datasets

This completes the theory section for B-Trees.

