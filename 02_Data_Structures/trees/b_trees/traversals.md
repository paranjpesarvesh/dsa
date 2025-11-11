# B-Trees — Traversals

This note lives under `trees/b_trees/traversal.md`, so we focus specifically on **how to traverse a B-Tree** (and how it differs from BST/AVL/RBT). We cover inorder (sorted), preorder, postorder, level-order (BFS), range scans, and practical iterators. We also point out B+-tree specifics since interviews often conflate the two.

---

## Recap: B-Tree Node Shape

Each node stores up to `2t−1` keys and up to `2t` children:

```
child0 | k0 | child1 | k1 | child2 | ... | k(m-1) | childm
```

Keys are sorted: `k0 < k1 < ... < k(m-1)`.
All leaves are at the same depth.

---

## 1) Inorder Traversal (Sorted Order)

In a B-Tree, **inorder** generalizes BST inorder:

For a node with keys `[k0, k1, ..., k(m−1)]` and children `[c0, c1, ..., cm]`:

```
inorder(c0), visit k0,
inorder(c1), visit k1,
...
inorder(c(m−1)), visit k(m−1),
inorder(cm)
```

### Why it’s sorted

Each `ci` contains keys strictly between `k(i−1)` and `ki`, so visiting `ci` before `ki` preserves order.

### Recursive Pseudocode

```
INORDER(node):
    if node is null: return
    for i in [0..node.keys_count):
        INORDER(node.child[i])
        VISIT(node.key[i])
    INORDER(node.child[node.keys_count])
```

### Iterative (Explicit Stack)

Store (node, index), where `index` indicates the next child/key to process:

```
ITER_INORDER(root):
    st = empty stack
    push (root, 0)
    while st not empty:
        (u, i) = top(st)
        if u is leaf:
            # visit all remaining keys in order, then pop
            while i < u.keys_count:
                VISIT(u.key[i]); i++
            pop st
        else:
            if i < u.keys_count:
                # descend to child i first
                push (u.child[i], 0)
                top(st-1).index = i+1   # next time, visit key i
            else:
                # all children before last key are done; do last child
                push (u.child[u.keys_count], 0)
                pop st (when finished)
```

**Complexity:** `O(n)` total visits, height `h = O(log n)`.
For external-memory (disk) analysis, an inorder scan costs `O(n/B + h)` block I/Os (B = block size).

---

## 2) Preorder Traversal

Order: visit keys in the node first (left-to-right), then children (left-to-right).

```
PREORDER(node):
    if node is null: return
    for i in [0..node.keys_count):
        VISIT(node.key[i])   # visit key before its right child
    for i in [0..node.keys_count]:
        PREORDER(node.child[i])
```

**Use cases:** dumping structure for debugging / serialization (not sorted).

**Complexity:** `O(n)`.

---

## 3) Postorder Traversal

Order: visit all children, then the node’s keys.

```
POSTORDER(node):
    if node is null: return
    for i in [0..node.keys_count]:
        POSTORDER(node.child[i])
    for i in [0..node.keys_count):
        VISIT(node.key[i])
```

**Use cases:** safe deletion/freeing nodes bottom-up.
**Complexity:** `O(n)`.

---

## 4) Level-Order (BFS)

Visit nodes by levels. For each node, **emit keys left-to-right**.

```
LEVEL_ORDER(root):
    if root is null: return
    q = queue(); q.push(root)
    while q not empty:
        u = q.pop()
        for i in [0..u.keys_count):
            VISIT(u.key[i])
        for i in [0..u.keys_count]:
            if u is not leaf:
                q.push(u.child[i])
```

**Use cases:** visualizing balance/shape; breadth-wise diagnostics.
**Complexity:** `O(n)` time, `O(width)` space (width = max nodes on a level).

---

## 5) Range Queries (a..b)

**Goal:** output all keys `k` with `a ≤ k ≤ b` in sorted order efficiently.

Key idea: inorder with **pruning**—only descend into subtrees that can contain values in range.

```
RANGE(node, a, b):
    if node is null: return
    for i in [0..node.keys_count):
        # left child segment: keys < node.key[i]
        if a <= node.key[i]:
            RANGE(node.child[i], a, b)
        if a <= node.key[i] <= b:
            VISIT(node.key[i])
        # continue only if b >= node.key[i]; else we can stop early
        if b < node.key[i]:
            return  # no larger keys in this node or to its right are in range
    # rightmost child: keys > last key
    RANGE(node.child[node.keys_count], a, b)
```

**Cost:** `O(h + k)` time where `k` = number of reported keys; in I/O model: `O(h + k/B)` block reads.

---

## 6) Successor / Predecessor

* **Successor(x):** smallest key strictly greater than `x`.

  1. During search, remember the last key `≥ x`.
  2. If `x` found in an internal node, go to its right child, then repeatedly go to the leftmost child and return the first key encountered.
  3. Else return the remembered candidate.
* **Predecessor(x):** symmetric (largest key strictly less than `x`).

**Time:** `O(h)`.

---

## 7) K-th Smallest (Order Statistics)

If nodes store **subtree sizes**, do an order-statistics traversal:

```
KTH(node, k):
    # assume child_size(i) returns size of subtree rooted at child i
    for i in [0..node.keys_count):
        s = child_size(i)
        if k <= s: return KTH(node.child[i], k)
        if k == s + 1: return node.key[i]
        k -= (s + 1)
    return KTH(node.child[node.keys_count], k)
```

**Time:** `O(h)` if subtree sizes maintained; else `O(n)` in general.

---

## 8) Iterators (Practical Traversal in Code)

### Inorder Iterator (next in sorted order)

Maintain a stack of `(node, pos)` that points at the **next key to yield**:

Initialization (descend to the leftmost key):

```
INIT(root):
    st = empty stack
    u = root
    while u:
        push (u, 0)
        if u is leaf: break
        u = u.child[0]
    ADVANCE_TO_FIRST_KEY_ON_TOP()
```

`next()`:

```
NEXT():
    (u, i) = top(st)
    output = u.key[i]
    i++
    if u is leaf:
        while st not empty and i == top.u.keys_count:
            pop st; (u, i) = top(st) if any
        if st not empty:
            # next key in ancestor
            set top index = i   # already at next key
        else:
            # exhausted
            mark end
    else:
        # move to leftmost key in right child of the emitted key
        v = u.child[i]
        while v:
            push (v, 0)
            if v is leaf: break
            v = v.child[0]
    return output
```

**Space:** `O(h)` stack. **Amortized time per key:** `O(1)` pointer work (ignoring I/O).

---

## 9) B-Tree vs B+-Tree Traversals

* **B-Tree:** data (records) can live in **any node** (internal or leaf).

  * Inorder must visit **every node** to output in sorted order.
* **B+-Tree:** data lives **only at leaves**, internal nodes hold separators.

  * **Leaf nodes are linked** (right-sibling pointers).
  * **Sorted scan / range queries:** jump to first leaf in range, then follow leaf links → very cache/I/O friendly.

### B+-Tree Range Scan (a..b)

```
# 1) Descend from root to first leaf whose key >= a
u = LEAF_FOR(a)
# 2) Scan keys in u; continue to next leaf via right-link
while u and smallest_key(u) <= b:
    for key in u.keys:
        if key > b: return
        if key >= a: VISIT(key)
    u = u.right_sibling
```

**I/O cost:** `O(h + k/B)` — near optimal.

---

## 10) Edge Cases & Pitfalls

* **Empty tree/root:** handle null root gracefully in all traversals.
* **Leaf vs internal:** leaf has `children_count = 0`; don’t dereference missing children.
* **Duplicate keys:** define a policy (store counts, or duplicates in specific child). Inorder must respect that policy to be stable.
* **Huge fan-out:** prefer **iterative** traversals (avoid deep recursion limits).
* **External memory:** batch node loads, avoid random child probes when possible; B+ linked leaves shine here.

---

## 11) Complexity Summary

| Traversal         | Time   | Extra Space               |
| ----------------- | ------ | ------------------------- |
| Inorder           | O(n)   | O(h) (stack if iterative) |
| Preorder          | O(n)   | O(h)                      |
| Postorder         | O(n)   | O(h)                      |
| Level-order       | O(n)   | O(width)                  |
| Range (a..b)      | O(h+k) | O(h)                      |
| K-th (with sizes) | O(h)   | O(1)                      |

`h = O(log_t n)` is very small in practice due to high branching factor.

---

## 12) ASCII Aids

Example node (m = 3 keys):

```
         [10 | 20 | 35]
       /       |       |       \
   c0        c1       c2        c3
```

Inorder sequence shape:

```
INORDER(c0), 10, INORDER(c1), 20, INORDER(c2), 35, INORDER(c3)
```

Level-order (BFS) queue evolution (conceptually):

```
q: [root]
visit [10 20 35]
enqueue [c0 c1 c2 c3]
...
```

---

## 13) Interview Tips

* When asked for “sorted traversal” → **inorder** with the generalized pattern (child, key, child…).
* Mention **B+-tree leaf links** for **fast range queries** and why DBs prefer B+ over B.
* If asked to “print all in [L, R]”: explain **pruning** and cost `O(h + k)`.
* For **iterators**, bring up stack-based inorder with `O(h)` memory and amortized O(1) per `next()`.
* Clarify handling of **duplicates** and **empty tree** behavior.

---

## 14) Practice Problems

* Implement inorder, preorder, postorder traversals for a B-Tree node structure.
* Design an **inorder iterator** with `next()` and `hasNext()`.
* Range query: print all keys in `[a, b]` with pruning.
* K-th smallest in a B-Tree (assume nodes store subtree sizes).
* For a **B+-Tree**, implement an efficient `[a, b]` scan using leaf links.

Suggested sources:

* GeeksforGeeks — B-Tree traversals & range queries.
* CLRS (Chapter on B-Trees) — conceptual correctness & invariants.
* Any DB textbook (e.g., “Database System Concepts”) — B+-tree scans.

---
