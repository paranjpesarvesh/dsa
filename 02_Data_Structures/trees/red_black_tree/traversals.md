# Red-Black Tree Traversals

This document focuses on **traversals** for Red-Black Trees (RBTs): classic DFS/BFS orders, **color-aware traversals**, computing **black height**, **validation passes** that check RBT invariants, and idiomatic iterative/recursive templates.

RBTs are BSTs with extra color and height invariants. Traversals respect BST ordering and may additionally consult **color** and **black-height** metadata.

---

## 1) What stays the same vs. what changes?

* **Same as BSTs:**

  * **Inorder** yields keys in **sorted order**.
  * **Preorder/Postorder/Level order** definitions and complexities are unchanged: (O(n)) time, (O(h)) stack/queue where (h=O(\log n)).
* **RBT-specific:**

  * You may traverse **NIL leaves** (conceptual black nulls) for validation.
  * You may compute **black height** during DFS.
  * You can create **color-stable** traversals (e.g., “visit all red nodes first by level”).

---

## 2) Classic Traversals

### 2.1 Inorder (L, Root, R) — Sorted Output

* **Use:** Range queries, verifying BST ordering.
* **Time/Space:** (O(n)) / (O(h))

Pseudocode (recursive):

```
INORDER(u):
  if u == NIL: return
  INORDER(u.left)
  visit(u.key)             // also available: u.color
  INORDER(u.right)
```

Iterative (stack):

```
INORDER_ITER(root):
  S ← empty stack
  u ← root
  while S not empty or u ≠ NIL:
    while u ≠ NIL:
      push(S, u)
      u ← u.left
    u ← pop(S)
    visit(u.key)
    u ← u.right
```

### 2.2 Preorder (Root, L, R)

* **Use:** Make copies/serializations, building structure-first views.

```
PREORDER(u):
  if u == NIL: return
  visit(u.key)
  PREORDER(u.left)
  PREORDER(u.right)
```

### 2.3 Postorder (L, R, Root)

* **Use:** Destruction/freeing, bottom-up computations (e.g., sizes).

```
POSTORDER(u):
  if u == NIL: return
  POSTORDER(u.left)
  POSTORDER(u.right)
  visit(u.key)
```

### 2.4 Level Order (BFS)

* **Use:** Layer-wise inspection; useful for seeing **color distribution** by depth.

```
LEVEL_ORDER(root):
  if root == NIL: return
  Q ← empty queue
  enqueue(Q, root)
  while Q not empty:
    u ← dequeue(Q)
    visit(u.key)
    if u.left  ≠ NIL: enqueue(Q, u.left)
    if u.right ≠ NIL: enqueue(Q, u.right)
```

---

## 3) Color-Aware Traversals

Sometimes you need traversal logic that **uses colors** (e.g., debugging violations).

### 3.1 Level Order with Colors (pretty-print)

```
LEVEL_ORDER_COLOR(root):
  if root == NIL: return
  Q ← queue of (node, depth)
  enqueue(Q, (root, 0))
  currDepth ← 0
  while Q not empty:
    (u, d) ← dequeue(Q)
    if d ≠ currDepth: print newline; currDepth ← d
    print u.key, "[", u.color, "]  "   // e.g., 10 [B]
    if u.left  ≠ NIL: enqueue(Q, (u.left, d+1))
    if u.right ≠ NIL: enqueue(Q, (u.right, d+1))
```

### 3.2 Collect Nodes by Color (DFS)

```
COLLECT_BY_COLOR(u, reds, blacks):
  if u == NIL: return
  if u.color == RED: add u.key to reds else add u.key to blacks
  COLLECT_BY_COLOR(u.left, reds, blacks)
  COLLECT_BY_COLOR(u.right, reds, blacks)
```

---

## 4) Computing Black Height (BH)

**Black height** of a node = number of black nodes on any path from that node down to (and including) NIL leaves, **excluding the node itself** (common convention). All root-to-NIL paths must share equal BH.

### 4.1 Verify Black Height Uniformity

We compute BH bottom-up and ensure left/right child paths match.

```
CHECK_BH(u):
  // returns (isValid, blackHeight)
  if u == NIL: return (true, 1)  // NIL is black and counts as 1

  (okL, bhL) ← CHECK_BH(u.left)
  (okR, bhR) ← CHECK_BH(u.right)
  if not okL or not okR or bhL ≠ bhR: return (false, 0)

  add ← (u.color == BLACK ? 1 : 0)
  return (true, bhL + add)
```

* Call `CHECK_BH(root)`; validity requires the boolean to be true.

---

## 5) Full Red-Black Validation Traversal

A proper RBT must satisfy:

1. Root is black
2. No red-red parent-child
3. Equal black height across all root-to-NIL paths

Single DFS can check 2) and 3); check 1) on entry.

```
VALIDATE_RBT(root):
  if root ≠ NIL and root.color ≠ BLACK: return false
  (ok, _) ← VALIDATE_NODE(root, PARENT_IS_RED=false)
  return ok

VALIDATE_NODE(u, PARENT_IS_RED):
  // returns (isValid, blackHeight)
  if u == NIL: return (true, 1)

  // (a) red-red check
  if PARENT_IS_RED and u.color == RED: return (false, 0)

  (okL, bhL) ← VALIDATE_NODE(u.left,  u.color == RED)
  (okR, bhR) ← VALIDATE_NODE(u.right, u.color == RED)
  if not okL or not okR or bhL ≠ bhR: return (false, 0)

  add ← (u.color == BLACK ? 1 : 0)
  return (true, bhL + add)
```

**Complexity:** (O(n)) time, (O(h)) stack.

---

## 6) ASCII Flow: Inorder with Color

```
        7[B]
       /     \
    3[R]     11[B]
    /  \      /   \
  2[B] 5[B]  9[R] 13[B]

Inorder (key[color]):
2[B], 3[R], 5[B], 7[B], 9[R], 11[B], 13[B]
```

---

## 7) Edge Cases & Variations

* **Empty tree / single node**: Inorder should print nothing / the root; root must be black.
* **Explicit NIL traversal**: For validation, treat NIL as black and **visit** conceptual leaves. For normal output, **skip** NILs.
* **Range queries** with Inorder:

  ```
  INORDER_RANGE(u, L, R):
    if u == NIL: return
    if u.key > L: INORDER_RANGE(u.left, L, R)
    if L ≤ u.key ≤ R: visit(u.key)
    if u.key < R: INORDER_RANGE(u.right, L, R)
  ```
* **Iterative traversals** preferred in systems code to avoid recursion limits.

---

## 8) Interview Tips

* State that **inorder of an RBT is sorted** because RBT is a BST underneath.
* For **validations**, mention the **three checks** and show a concise DFS.
* If asked to **print black height at each node**, do a bottom-up pass (postorder).
* For debugging insert/delete, use **level-order with colors** to spot red-red or black-height anomalies quickly.
* Be comfortable with **iterative inorder** using a stack.

---

## 9) Practice Problems

* Implement:

  1. Inorder/Preorder/Postorder/Level-order traversals for RBT nodes.
  2. `validateRBT(root)` that checks red-red and black-height properties.
  3. `blackHeight(u)` per node; print `(key, BH[key])` pairs in inorder.
* LeetCode/GFG/CF (related):

  * Validate Binary Tree / Validate BST (adapt with color rules)
  * Binary Tree Level Order Traversal
  * Binary Tree Inorder Traversal (iterative)
  * Custom: “Validate Red-Black Tree” (implementation exercise)
* Stretch:

  * Range sum via inorder with early stopping.
  * BFS grouped by color per level.

---

## 10) Complexity Summary

| Traversal / Check    | Time | Aux Space |
| -------------------- | ---- | --------- |
| Inorder/Pre/Post DFS | O(n) | O(h)      |
| Level Order (BFS)    | O(n) | O(w)      |
| Black-Height Check   | O(n) | O(h)      |
| Full RBT Validate    | O(n) | O(h)      |

(h = O(\log n)) for a valid RBT; (w) is max width of a level.

---

## 11) Minimal Templates (Copy-Paste)

### Inorder + Color

```
INORDER_COLOR(u):
  if u == NIL: return
  INORDER_COLOR(u.left)
  visit(u.key, u.color)
  INORDER_COLOR(u.right)
```

### Level Order + Color Per Level

```
LEVEL_ORDER_LINES(root):
  if root == NIL: return
  Q ← queue
  enqueue(Q, root)
  while Q not empty:
    k ← size(Q)
    for i in 1..k:
      u ← dequeue(Q)
      print u.key, "[", u.color, "]  "
      if u.left ≠ NIL:  enqueue(Q, u.left)
      if u.right ≠ NIL: enqueue(Q, u.right)
    print newline
```

### Validate Red-Black Invariants

```
VALIDATE_RBT(root):
  if root ≠ NIL and root.color ≠ BLACK: return false
  (ok, _) ← VALIDATE_NODE(root, false)
  return ok
```

Use these as building blocks for debugging and correctness checks of your Red-Black Tree implementation.

