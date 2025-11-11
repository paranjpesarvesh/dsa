# Red-Black Trees — Overview

This README provides a structured conceptual introduction to **Red-Black Trees**, their properties, motivations, and core operations. It is meant as a quick reference before diving into detailed theory, implementations, and traversal logic.

---

## What is a Red-Black Tree?

A **Red-Black Tree (RBT)** is a type of **self-balancing binary search tree** that guarantees:

* **O(log n)** search
* **O(log n)** insertion
* **O(log n)** deletion

It achieves balance using **coloring rules** and **rotations**.

RBTs are widely used in:

* STL `map`, `set` (C++)
* Java `TreeMap`
* Linux process scheduler
* Persistent data structures

---

## Properties of a Red-Black Tree

A valid RBT must satisfy:

1. Every node is either **red** or **black**.
2. The root is **black**.
3. All NIL/NULL leaves are considered **black**.
4. A red node cannot have a red parent (no consecutive reds).
5. Every path from a node to a descendant leaf must have the **same number of black nodes** (black height rule).

These constraints ensure the tree height stays in the range:

```
log2(n+1) ≤ height ≤ 2 * log2(n+1)
```

---

## Why red-black trees?

### Advantages

* Guaranteed worst-case **logarithmic height**
* Supports fast **ordered operations**
* Better worst-case balance than AVL rotations count but slightly less rigid

### Trade-offs vs AVL

| Feature           | AVL Tree | Red-Black Tree  |
| ----------------- | -------- | --------------- |
| Strict balance    | Yes      | No              |
| Insert faster     | No       | Yes             |
| Search faster     | Yes      | Slightly slower |
| Rotations needed  | More     | Fewer           |
| Used in libraries | Rare     | Yes (STL etc.)  |

---

## Key Operations

### 1. Insert

Steps:

1. Insert like a BST
2. Color new node **red**
3. Fix violations using:

   * Recoloring
   * Rotations (LL/LR/RL/RR)

### 2. Delete

More complex due to color balancing.
Techniques include:

* Fixing double-black situations
* Borrowing from sibling
* Recoloring
* Rotations

### 3. Rotations

Two fundamental operations:

```
Left Rotation
Right Rotation
```

ASCII view of left rotation:

```
     x                   y
      \                 /
       y      ->       x
      /                 \
     T2                 T2
```

Rotations are O(1).

---

## Black Height (Important Concept)

Black height (BH) is:

```
Number of black nodes on any path from a node to a leaf (excluding the node itself)
```

Ensuring equal BH for all root-to-leaf paths is what guarantees logarithmic height.

---

## Interview Importance

### Common questions:

* Explain balancing in RBT.
* How is RBT different from AVL?
* Why is root always black?
* What is black height?
* Write insertion implementation.
* How rotations help?
* Why no consecutive red nodes?

### Implementation-focused interviews:

Frequently asked to:

* Implement insertion
* Show rotation logic
* Prove height bound
* Show recoloring cases

RBT deletion is rarely required end-to-end, but understanding fix-up cases is useful.

---

## Visual Summary

```
Balanced
  |
  v
Color + Rotations
  |
  v
Fast lookups + inserts
```

---

## Practice Problems

1. Implement Red-Black Tree insertion (Coding)
2. Validate if a given binary tree is a RBT (GFG)
3. Count black-height of every node (Interview variation)
4. Build RBT with sequential inserts and analyze tree height
5. Implement deleteFix() logic (Advanced)

---

## Key Notes

* Insertions cause **at most two rotations**
* Red nodes act as relaxed balance placeholders
* Black nodes enforce height consistency
* Height is always O(log n)
* RBTs are preferred in industry over AVL due to fewer rotations

---
