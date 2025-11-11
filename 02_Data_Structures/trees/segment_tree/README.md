# Segment Tree — Overview

This document provides a clear and structured introduction to **Segment Trees**, a powerful data structure used for handling range queries and updates efficiently.

---

## 1. What Is a Segment Tree?

A **Segment Tree** is a binary tree data structure built over an array to support:

* Fast **range queries** (sum, min, max, gcd, etc.)
* Fast **updates** (point update or range update)
* Efficient memory usage

### Key Idea

Divide array into segments recursively until each segment represents a single element.

Each internal node stores aggregated information for its segment.

---

## 2. When to Use Segment Trees?

Use them when you need:

| Operation | Naive Time | Segment Tree Time |
| --------- | ---------- | ----------------- |
| Range Sum | O(n)       | O(log n)          |
| Range Min | O(n)       | O(log n)          |
| Update    | O(1)       | O(log n)          |

---

## 3. Structure and Representation

A segment tree represents recursively:

```
               [0, n-1]
              /        \
        [0, mid]      [mid+1, n-1]
```

For an array of size `n`, segment tree size ≤ `4n`.

Stored typically in a **1-indexed array**.

---

## 4. Visual Representation

Given array:

`A = [1, 3, 5, 7]`

Tree:

```
                     (1+3+5+7)=16
                   /               \
              (1+3)=4             (5+7)=12
             /      \             /       \
           1        3           5         7
```

---

## 5. Supported Operations

### 5.1 Build

Build tree in `O(n)`.

### 5.2 Query

Query range `[l, r]` in `O(log n)` by:

* completely inside range
* partially overlapping
* completely outside

### 5.3 Update

Update using:

* point update (O(log n))
* lazy propagation updates (O(log n)) for range updates

---

## 6. Pseudocode Templates

### Build

```
build(idx, l, r):
    if l == r:
        tree[idx] = arr[l]
        return
    mid = (l + r) / 2
    build(2*idx, l, mid)
    build(2*idx+1, mid+1, r)
    tree[idx] = combine(tree[2*idx], tree[2*idx+1])
```

### Query

```
query(idx, l, r, ql, qr):
    if out of range:
        return identity
    if fully in range:
        return tree[idx]
    mid = (l + r) / 2
    left = query(2*idx, l, mid, ql, qr)
    right = query(2*idx+1, mid+1, r, ql, qr)
    return combine(left, right)
```

### Update

```
update(idx, l, r, pos, val):
    if l == r:
        tree[idx] = val
        return
    mid = (l + r) / 2
    if pos <= mid:
        update(2*idx, l, mid, pos, val)
    else:
        update(2*idx+1, mid+1, r, pos, val)
    tree[idx] = combine(tree[2*idx], tree[2*idx+1])
```

---

## 7. Lazy Propagation (Brief Idea)

Useful for **range updates**:

* Add value to entire segment `[l, r]`
* Push updates lazily to children

Lazy array stores pending updates.

Time remains `O(log n)`.

---

## 8. Complexity Analysis

| Operation        | Complexity |
| ---------------- | ---------- |
| Build            | O(n)       |
| Query            | O(log n)   |
| Update           | O(log n)   |
| Range Update     | O(log n)   |
| Space complexity | O(4n)      |

---

## 9. Variations

* Min Segment Tree
* Max Segment Tree
* Sum Segment Tree
* GCD Segment Tree
* XOR Segment Tree
* Range Add / Range Query
* Range Update / Range Query (lazy propagation)
* Persistent Segment Tree
* Dynamic Segment Tree (for large coordinate space)

---

## 10. Common Interview Traps

* Forgetting 1-indexed tree array indexing
* Handling partial overlaps incorrectly
* Returning wrong identity value (0 for sum, +inf for min)
* Misusing lazy propagation
* Off-by-one errors in recursion

---

## 11. Practice Problems

### Easy

* Range Sum Query (LeetCode)
* Range Minimum Query (GFG)

### Medium

* LeetCode 307 — Range Sum Query (Mutable)
* SPOJ – KGSS
* GFG – Inversion Count

### Hard

* Codeforces problems involving:

  * range modifications
  * updates + queries
* Persistent segment tree questions

---

## 12. Summary

A segment tree is ideal when:

* Large array
* Frequent range queries
* Frequent updates

Time complexity stays logarithmic for both operations.

---
