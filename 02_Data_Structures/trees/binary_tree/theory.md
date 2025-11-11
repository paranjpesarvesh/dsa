# Binary Tree — Theory

A **binary tree** is a hierarchical data structure where each node has at most two children: **left** and **right**. It underpins many advanced structures (BST, heaps, segment trees, tries in binary form) and appears frequently in interviews to assess recursion, traversal mastery, and tree DP.

---

## 1) Core Definitions

* **Node**: `(value, left, right)`
* **Root**: Top-most node (no parent).
* **Leaf**: Node with no children.
* **Height**: Number of nodes on the longest path from node to a leaf.
* **Depth**: Distance from root to the node (#edges).
* **Subtree**: Tree formed by a node and its descendants.

### Common Binary Tree Families

| Type                           | Property                                                             |
| ------------------------------ | -------------------------------------------------------------------- |
| **Full**                       | Every node has 0 or 2 children.                                      |
| **Complete**                   | All levels filled except possibly last; last filled left→right.      |
| **Perfect**                    | All internal nodes have 2 children and all leaves at the same depth. |
| **Balanced (height-balanced)** | Height `= O(log n)` (e.g., AVL/RB trees).                            |
| **Degenerate**                 | Every node has 1 child (like a linked list).                         |

---

## 2) Mathematical Intuition & Identities

* **Perfect tree with height `h` (1-indexed)**:
  `#nodes = 2^h - 1`, `#leaves = 2^(h-1)`.
* **Lower bound on height** for `n` nodes: `h_min = ⌈log2(n+1)⌉`.
* **Upper bound on height**: `n` (degenerate).
* **Edges** in any tree with `n` nodes: `n - 1`.

---

## 3) Visual Aid

Example tree and traversals:

```
            1
          /   \
         2     3
        / \     \
       4   5     6
```

* **Preorder (Root, Left, Right)**: 1 2 4 5 3 6
* **Inorder (Left, Root, Right)**: 4 2 5 1 3 6
* **Postorder (Left, Right, Root)**: 4 5 2 6 3 1
* **Level-order (BFS)**: 1 2 3 4 5 6

---

## 4) Traversal Templates (Pseudocode)

### Recursive DFS

```
INORDER(u):
    if u == null: return
    INORDER(u.left)
    visit(u)
    INORDER(u.right)

PREORDER(u):
    if u == null: return
    visit(u)
    PREORDER(u.left)
    PREORDER(u.right)

POSTORDER(u):
    if u == null: return
    POSTORDER(u.left)
    POSTORDER(u.right)
    visit(u)
```

### Iterative Inorder (Stack)

```
INORDER_ITERATIVE(root):
    stack = empty
    cur = root
    while cur != null or stack not empty:
        while cur != null:
            push(stack, cur)
            cur = cur.left
        cur = pop(stack)
        visit(cur)
        cur = cur.right
```

### Level-order (BFS with Queue)

```
LEVEL_ORDER(root):
    if root == null: return
    q = queue([root])
    while q not empty:
        u = q.pop()
        visit(u)
        if u.left  != null: q.push(u.left)
        if u.right != null: q.push(u.right)
```

---

## 5) Construction from Traversals

* **Preorder + Inorder** uniquely reconstructs a binary tree (no duplicates).
* **Postorder + Inorder** also uniquely reconstructs.
* **Preorder + Postorder** is not unique unless the tree is full.

High-level idea (Pre+In):

1. `pre[0]` is root.
2. Find root in `in` to split left/right subtrees.
3. Recurse on segments.

---

## 6) Classic Binary-Tree Tasks (Patterns + Pseudocode)

### A) Height / Depth

```
HEIGHT(u):
    if u == null: return 0
    return 1 + max(HEIGHT(u.left), HEIGHT(u.right))
```

* **Time**: `O(n)`, **Space**: `O(h)` recursion.

### B) Check Balanced (height-balanced)

```
BALANCED_HEIGHT(u):
    if u == null: return (true, 0)
    (okL, hL) = BALANCED_HEIGHT(u.left)
    (okR, hR) = BALANCED_HEIGHT(u.right)
    ok = okL and okR and (abs(hL - hR) <= 1)
    return (ok, 1 + max(hL, hR))
```

* **Time**: `O(n)`.

### C) Diameter (longest path in nodes or edges)

```
DIAMETER(u):
    ans = 0
    DFS(u):
        if u == null: return 0
        L = DFS(u.left)
        R = DFS(u.right)
        ans = max(ans, L + R)      # edges diameter; use L+R+1 for nodes
        return 1 + max(L, R)
    DFS(u)
    return ans
```

* **Time**: `O(n)`.

### D) Lowest Common Ancestor (General Binary Tree)

```
LCA(u, p, q):
    if u == null or u == p or u == q: return u
    L = LCA(u.left, p, q)
    R = LCA(u.right, p, q)
    if L != null and R != null: return u
    return L != null ? L : R
```

* **Time**: `O(n)` worst case.

### E) Root-to-Leaf Path Sum (e.g., target sum)

```
HAS_PATH_SUM(u, target):
    if u == null: return false
    if u.left==null and u.right==null:
        return (u.val == target)
    return HAS_PATH_SUM(u.left, target - u.val) or
           HAS_PATH_SUM(u.right, target - u.val)
```

### F) Maximum Path Sum (may start/end anywhere)

```
MAX_PATH_SUM(u):
    best = -∞
    GAIN(u):
        if u == null: return 0
        L = max(0, GAIN(u.left))
        R = max(0, GAIN(u.right))
        best = max(best, u.val + L + R)
        return u.val + max(L, R)
    GAIN(u)
    return best
```

### G) Serialize / Deserialize (Preorder with null markers)

```
SERIALIZE(u):
    if u == null: output "#"
    else:
        output u.val
        SERIALIZE(u.left)
        SERIALIZE(u.right)

DESERIALIZE(stream):
    x = next(stream)
    if x == "#": return null
    u = new Node(x)
    u.left  = DESERIALIZE(stream)
    u.right = DESERIALIZE(stream)
    return u
```

### H) Zigzag Level Order (BFS + deque)

```
ZIGZAG_LEVEL_ORDER(root):
    res = []
    if root == null: return res
    q = queue([root])
    dirLeftToRight = true
    while q not empty:
        k = q.size()
        level = deque()
        repeat k times:
            u = q.pop()
            if dirLeftToRight: push_back(level, u.val)
            else:              push_front(level, u.val)
            if u.left:  q.push(u.left)
            if u.right: q.push(u.right)
        res.append(list(level))
        dirLeftToRight = not dirLeftToRight
    return res
```

---

## 7) Edge Cases Checklist

* Empty tree (`root = null`).
* Single-node tree.
* Skewed tree (all left or all right) → recursion depth equals `n`.
* Duplicate values → traversal reconstruction needs care.
* Negative values for max path sum (don’t discard node completely; use `max(0, child)`).
* Very deep trees → consider iterative traversals to avoid stack overflow.

---

## 8) Complexity Summary

| Operation / Task                | Time                   | Space                                    |
| ------------------------------- | ---------------------- | ---------------------------------------- |
| Any full traversal (DFS/BFS)    | `O(n)`                 | `O(h)` recursion or `O(w)` queue (width) |
| Height / Balanced / Diameter    | `O(n)`                 | `O(h)`                                   |
| LCA (without parent pointers)   | `O(n)`                 | `O(h)`                                   |
| Build from Pre+In / Post+In     | `O(n)` (with hash map) | `O(n)`                                   |
| Serialization / Deserialization | `O(n)`                 | `O(h)`                                   |

`h` = height (worst `n`, best `log n` if balanced), `w` = max width.

---

## 9) Interview Tips

* State traversal orders clearly and **why** you need a specific traversal.
* For many problems, **return multiple pieces of info** in recursion (e.g., `(isBalanced, height)` or `(diameter, height)`).
* Use a **global/reference variable** when optimizing (e.g., max path sum, diameter).
* Always consider **null / single-node / skewed** cases.
* For construction problems, **precompute an index map** for inorder to get `O(1)` splits.
* Watch for **overflow** in sum-related problems and use wider types if needed.
* Prefer **iterative** solutions for very deep trees or languages with small recursion limits.

---

## 10) Practice Problems

**Warm-up**

* Maximum Depth of Binary Tree (LeetCode)
* Binary Tree Traversal (pre/in/post) iter & rec
* Level Order Traversal (LeetCode/GFG)

**Intermediate**

* Diameter of Binary Tree (LeetCode)
* Balanced Binary Tree (LeetCode)
* Symmetric Tree (LeetCode)
* Path Sum I/II (LeetCode)
* Right/Left View (GFG)

**Advanced**

* Serialize and Deserialize Binary Tree (LeetCode)
* Construct Binary Tree from Preorder & Inorder (LeetCode)
* Binary Tree Maximum Path Sum (LeetCode)
* Lowest Common Ancestor of a Binary Tree (LeetCode)
* Flatten Binary Tree to Linked List (LeetCode)

---

## 11) Quick Reference Templates

### Node (language-agnostic)

```
class Node:
    val
    left
    right
```

### DFS Pattern

```
SOLVE(u):
    if u == null: return base
    A = SOLVE(u.left)
    B = SOLVE(u.right)
    return COMBINE(A, B, u)
```

### BFS Pattern

```
LEVEL_ORDER(root):
    q = queue([root])
    while q not empty:
        k = q.size()
        // process nodes of current level
        repeat k times:
            u = q.pop()
            // handle u
            if u.left:  q.push(u.left)
            if u.right: q.push(u.right)
```

---

## 12) What to Master (Checklist)

* [ ] Inorder/Preorder/Postorder (recursive + iterative)
* [ ] Level-order and its variants (zigzag, bottom-up, level sums)
* [ ] Height, diameter, balance checks in one pass
* [ ] LCA in general binary tree
* [ ] Root-to-leaf paths & sums
* [ ] Construct from traversals (Pre+In, Post+In)
* [ ] Max path sum
* [ ] Serialization/Deserialization

---

