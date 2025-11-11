# Binary Tree Traversals — Theory and Patterns

Binary tree traversal is one of the most fundamental topics in DSA and is central to recursion mastery, tree algorithms, and many interview problems. Traversals define the order in which nodes of a binary tree are visited.

This document covers all core traversals, their intuition, pseudocode, iterative/recursive variations, usage patterns, and practice problems.

---

## 1) Visual Model

Consider the tree:

```
            A
          /   \
         B     C
        / \   / \
       D   E F   G
```

Different traversals visit nodes in different orders:

| Traversal   | Order         |
| ----------- | ------------- |
| Preorder    | A B D E C F G |
| Inorder     | D B E A F C G |
| Postorder   | D E B F G C A |
| Level-order | A B C D E F G |

---

## 2) Depth-First Traversals (DFS)

### A) Preorder (Root, Left, Right)

**Use cases**

* Clone/copy tree
* Convert tree to prefix notation
* Serialize tree

**Recursive pseudocode**

```
PREORDER(u):
    if u == null: return
    visit(u)
    PREORDER(u.left)
    PREORDER(u.right)
```

**Iterative (using stack)**

```
PREORDER_ITER(root):
    if root == null: return
    stack = [root]
    while stack not empty:
        u = stack.pop()
        visit(u)
        if u.right: stack.push(u.right)
        if u.left:  stack.push(u.left)
```

---

### B) Inorder (Left, Root, Right)

**Use cases**

* Sorted output for BSTs
* Tree reconstruction problems (inorder is crucial)

**Recursive pseudocode**

```
INORDER(u):
    if u == null: return
    INORDER(u.left)
    visit(u)
    INORDER(u.right)
```

**Iterative (stack)**

```
INORDER_ITER(root):
    stack = []
    cur = root
    while cur != null or stack not empty:
        while cur != null:
            stack.push(cur)
            cur = cur.left
        cur = stack.pop()
        visit(cur)
        cur = cur.right
```

---

### C) Postorder (Left, Right, Root)

**Use cases**

* Free/delete tree
* Evaluate expression tree
* Many DP on trees (compute bottom-up)

**Recursive pseudocode**

```
POSTORDER(u):
    if u == null: return
    POSTORDER(u.left)
    POSTORDER(u.right)
    visit(u)
```

**Iterative (2 stacks)**

```
POSTORDER_ITER(root):
    if root == null: return
    s1 = [root]
    s2 = []
    while s1 not empty:
        u = s1.pop()
        s2.push(u)
        if u.left:  s1.push(u.left)
        if u.right: s1.push(u.right)
    while s2 not empty:
        visit(s2.pop())
```

---

## 3) Breadth-First Traversal (Level Order)

**Use cases**

* BFS-based algorithms
* Zigzag level order
* Shortest path in tree
* Print tree level-wise

**Pseudocode**

```
LEVEL_ORDER(root):
    if root == null: return
    q = queue([root])
    while q not empty:
        u = q.pop()
        visit(u)
        if u.left:  q.push(u.left)
        if u.right: q.push(u.right)
```

---

## 4) Special Traversal Variants

### Zigzag / Spiral Level Order

Alternate between left→right and right→left each level.

```
ZIGZAG(root):
    dir = leftToRight
    q = queue([root])
    while q not empty:
        level = deque()
        k = q.size()
        repeat k times:
            u = q.pop()
            if dir: level.append(u.val)
            else:   level.appendleft(u.val)
            if u.left: q.push(u.left)
            if u.right: q.push(u.right)
        print(level)
        dir = not dir
```

---

### Boundary Traversal

Visit:

1. Left boundary (excluding leaves)
2. All leaves (left→right)
3. Right boundary (bottom→top)

Used in many interview problems.

### Vertical Order Traversal

Use column index (`col -1` left, `col +1` right), BFS + hashmap.

---

## 5) Traversal Orders Summary Table

```
PREORDER:   ROOT  LEFT  RIGHT
INORDER:    LEFT  ROOT  RIGHT
POSTORDER:  LEFT  RIGHT ROOT
LEVEL-ORDER: BFS by levels
```

---

## 6) Complexity

| Traversal             | Time | Space |
| --------------------- | ---- | ----- |
| Pre/In/Post recursive | O(n) | O(h)  |
| Pre/In/Post iterative | O(n) | O(h)  |
| Level-order           | O(n) | O(w)  |
| Zigzag                | O(n) | O(w)  |

Where:

* `n` = nodes
* `h` = height (worst `n`, best `log n`)
* `w` = max width

---

## 7) Pitfalls and Edge Cases

* Null tree
* Single-node tree
* Very skewed tree
* Iterative inorder mistakes (forget to move right)
* Duplicate values (traversal-based reconstruction requires unique values)
* Deep recursion (especially in Python)

---

## 8) Interview Tips

* Interviewers frequently ask:

  * “Write inorder traversal iteratively.”
  * “Reconstruct from inorder + preorder.”
  * “Level order but return each level as list.”
  * “Postorder iterative” (hardest of the three).
* Know stack-based templates cold.
* Understand BFS variations (zigzag, grouped levels).
* Practice writing recursive AND iterative versions.
* Mention time/space clearly and early.

---

## 9) Practice Problems

### Easy

* Binary Tree Preorder/Inorder/Postorder Traversal — LeetCode
* Level Order Traversal — LeetCode
* Right/Left view of binary tree — GFG

### Medium

* Zigzag Level Order — LeetCode
* Vertical Order Traversal — LeetCode
* Construct Tree from Inorder + Preorder — LeetCode
* Bottom-up level order — LeetCode

### Hard

* Morris Traversal (Inorder without stack/recursion)
* Boundary Traversal — GFG
* Serialize and Deserialize — LeetCode
* Vertical traversal with sorting rules — LeetCode
* Maximum Path Sum — LeetCode (complex DFS variant)

---

## 10) Quick Templates Reference

### All DFS in one snippet

```
def preorder(u):
    if not u: return
    print(u.val)
    preorder(u.left)
    preorder(u.right)

def inorder(u):
    if not u: return
    inorder(u.left)
    print(u.val)
    inorder(u.right)

def postorder(u):
    if not u: return
    postorder(u.left)
    postorder(u.right)
    print(u.val)
```

### Level-order

```
def levelorder(root):
    if not root: return
    q = [root]
    while q:
        node = q.pop(0)
        print(node.val)
        if node.left:  q.append(node.left)
        if node.right: q.append(node.right)
```

---

