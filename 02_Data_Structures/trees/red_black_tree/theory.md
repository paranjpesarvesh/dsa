# Red-Black Trees — Theory

A **Red-Black Tree** (RBT) is a type of **self-balancing Binary Search Tree (BST)** that guarantees worst-case ( O(\log n) ) complexity for search, insertion, and deletion. It achieves balance via **color constraints** and **rotations**.

This file explains the theory, structure, invariants, intuition, and balancing logic essential for implementing or understanding Red-Black Trees.

---

## 1. Motivation

Standard BSTs can become skewed:

```
1
 \
  2
   \
    3
```

Worst-case height: ( O(n) )

Red-Black Trees maintain approximate balance automatically using:

* Colors
* Recoloring
* Rotations

This ensures the upper bound on height is always:

[
h \le 2 \log_2(n+1)
]

---

## 2. Red-Black Tree Properties (Invariants)

Every valid RBT satisfies:

1. **Node color is either red or black**
2. **Root is black**
3. **All leaves (NULL pointers) are black**
4. **No two consecutive red nodes (no red parent-child pair)**
5. **Black-height property**
   Every path from a node to a descendant NULL leaf has the **same number of black nodes**.

These invariants guarantee balance.

---

## 3. Structural Intuition

Red nodes allow temporary imbalance to improve insertion efficiency.
Black nodes enforce height boundaries.

The balancing philosophy:

```
Let red nodes be flexible
Let black nodes maintain strict balance
```

---

## 4. Black Height (BH)

Black height of a node is defined as:

```
Number of black nodes on any path to a leaf (excluding the node itself)
```

All root-to-leaf paths must have equal BH.

### Why does this matter?

If some path had fewer black nodes, the tree would be skewed.
Consistency ensures height remains logarithmic.

---

## 5. Representation

Typical node structure:

```
struct Node {
    int key;
    char color; // 'R' or 'B'
    Node *left, *right, *parent;
};
```

---

## 6. Rotations (Core Balancing Mechanism)

Rotations maintain BST structure while adjusting height relationships.

### Left Rotation

```
    x
     \
      y
     /
    T2
```

Becomes:

```
      y
     /
    x
     \
      T2
```

### Right Rotation

Mirror of left rotation.

Rotations are ( O(1) ) and are minimal operations required for balance.

---

## 7. Insertion Algorithm (Step-by-Step)

Insertion follows clear phases:

1. Insert node as in BST (color new node red)
2. Fix violations:

   * Case 1: Parent red & uncle red → recolor
   * Case 2: Parent red & uncle black → rotation(s)

### Insertion Fix Cases

Assume new node = N, parent = P, grandparent = G, uncle = U.

#### Case 1 — Red Uncle

```
P = red
U = red
```

Fix:

* Recolor P and U → black
* Recolor G → red
* Move N to G and repeat

#### Case 2 — Black Uncle

Depending on configuration:

* Left-Left → Right rotation
* Left-Right → Left rotation on P then Right rotation on G
* Right-Right → Left rotation
* Right-Left → Right rotation on P then Left rotation on G

Finally, ensure root is black.

---

## 8. Deletion Algorithm (Overview)

Deletion is more complex because removing a black node may cause a **double-black** problem.

General steps:

1. Standard BST delete
2. Fix double-black issues:

   * If sibling red → rotate + recolor
   * If sibling black with black children → recolor sibling
   * If sibling black with red child → rotate + recolor depending on shape

Deletion rules are deterministic but lengthy.

---

## 9. Time and Space Complexity

| Operation | Time Complexity | Space |
| --------- | --------------- | ----- |
| Search    | O(log n)        | O(1)  |
| Insert    | O(log n)        | O(1)  |
| Delete    | O(log n)        | O(1)  |

Space complexity refers to auxiliary space; memory use is ( O(n) ).

---

## 10. Variations and Edge Cases

* Duplicate keys:
  Usually handled by:

  * Rejecting duplicates
  * Storing count
  * Using subtree vectors
* NIL leaves must be black
* Root recoloring mandatory
* Rotations may cascade

Edge cases worth testing:

1. Insert into empty tree
2. Insert causing chain corrections
3. Delete root
4. Delete leaf vs internal node
5. Delete black node (double-black case)

---

## 11. ASCII Diagram: Balancing Example

Insert sequence:

```
10, 5, 1
```

Unbalanced:

```
    10(B)
    /
  5(R)
  /
1(R)
```

Fix via rotation → Right rotation on 10:

```
    5(B)
   /   \
  1(R) 10(R)
```

---

## 12. Interview Tips

* Always start by describing invariants.
* Stating that “root must always be black” is important.
* Be able to draw rotation diagrams.
* For insertion, remember:

  * Insert as red
  * Recolor or rotate depending on uncle
* Deletion handling is what differentiates good candidates.
* Red-Black Trees vs AVL is a popular theoretical comparison.

---

## 13. Practice Problems

### Implementation

* Implement insertion in red-black tree
* Implement leftRotate() and rightRotate()
* Write deleteFix() function

### Conceptual

* Validate whether a given tree is a red-black tree
* Compute black height of nodes
* Explain each case in insertion fixing

### External Sources

* LeetCode: Design data structure problems
* GeeksForGeeks: RBT insertion and deletion
* Codeforces: Balanced tree simulation problems

---

## 14. Summary Table

| Concept      | Description              |
| ------------ | ------------------------ |
| Red Node     | Temporary flexibility    |
| Black Node   | Structural stability     |
| No red-red   | Avoids long red chains   |
| Black height | Controls balanced height |
| Rotations    | Maintain BST + balance   |

---
