# Segment Tree — Theory

## 1. Introduction

A **Segment Tree** is a balanced binary tree used to answer **range queries** and perform **updates** efficiently on arrays.

It is designed for scenarios where:

* The array changes frequently
* Queries on ranges must be fast

Segment Trees guarantee:

* O(n) build time
* O(log n) per query
* O(log n) per update

---

## 2. Why Segment Trees?

### Problem

Given an array, answer multiple queries like:

* Range sum [l, r]
* Range minimum / maximum
* Range gcd
* Range XOR

Also handle updates:

* Change value at index i
* Update a range (lazy propagation)

### Naive Approach

Each query costs O(n).

### Segment Tree Approach

Each query/update becomes O(log n).

---

## 3. Structural Intuition

A segment tree divides the array recursively:

```
Array A: [1, 3, 5, 7, 9, 11]

                                [0,5]
                             /         \
                         [0,2]         [3,5]
                       /      \       /     \
                   [0,1]      [2,2] [3,4]   [5,5]
```

* Leaf nodes represent a single element.
* Internal nodes represent merged results.

---

## 4. How Is It Represented?

Typically stored as a 1-indexed array `tree[]` of size up to `4 * n`.

Index mapping:

```
tree[1]      -> root
tree[2*i]    -> left child
tree[2*i+1]  -> right child
```

---

## 5. Building a Segment Tree

### Idea

* Recursively split the segment
* Combine child results

### Pseudocode

```
build(idx, l, r):
    if l == r:
        tree[idx] = arr[l]
        return
    mid = (l+r)/2
    build(2*idx, l, mid)
    build(2*idx+1, mid+1, r)
    tree[idx] = combine(tree[2*idx], tree[2*idx+1])
```

### Time Complexity

* O(n)

---

## 6. Query Operation

### Goal

Return result of query `[ql, qr]`.

### Key Cases

1. Segment completely outside → return identity
2. Segment fully inside → return stored value
3. Partial overlap → recurse into both children

### Pseudocode

```
query(idx, l, r, ql, qr):
    if r < ql or l > qr:
        return identity
    if ql <= l and r <= qr:
        return tree[idx]
    mid = (l+r)/2
    left = query(2*idx, l, mid, ql, qr)
    right = query(2*idx+1, mid+1, r, ql, qr)
    return combine(left, right)
```

### Time Complexity

* O(log n)

---

## 7. Update Operation

Two types:

1. **Point update**
2. **Range update** (handled via lazy propagation)

### Pseudocode (Point Update)

```
update(idx, l, r, pos, val):
    if l == r:
        tree[idx] = val
        return
    mid = (l+r)/2
    if pos <= mid:
        update(2*idx, l, mid, pos, val)
    else:
        update(2*idx+1, mid+1, r, pos, val)
    tree[idx] = combine(tree[2*idx], tree[2*idx+1])
```

### Time Complexity

* O(log n)

---

## 8. Lazy Propagation (Range Updates)

For heavy update operations such as:

* Add value to all elements in segment
* Set all elements in segment

We avoid recursively updating every node by using a `lazy[]` array.

### High-Level Intuition

* Store pending update in lazy array
* Push update when needed
* Maintain O(log n) time per operation

---

## 9. Common Types of Segment Trees

| Type            | Operation                   |
| --------------- | --------------------------- |
| Sum tree        | sum over range              |
| Min tree        | minimum over range          |
| Max tree        | maximum over range          |
| GCD tree        | gcd over range              |
| XOR tree        | xor over range              |
| Lazy tree       | range updates               |
| Persistent tree | immutable versions          |
| Dynamic tree    | for large coordinate ranges |

---

## 10. Pitfalls & Edge Cases

* Identity value must match operation:

  * Sum: 0
  * Min: +∞
  * Max: -∞
  * GCD: 0
* Off-by-one errors in l, r boundary
* Forgetting to propagate lazy values
* Using integer overflow for sum queries

---

## 11. Segment Tree vs Fenwick Tree

| Feature          | Fenwick Tree | Segment Tree             |
| ---------------- | ------------ | ------------------------ |
| Space            | O(n)         | O(4n)                    |
| Range queries    | Yes          | Yes                      |
| Range updates    | Limited      | Fully supported          |
| Types of queries | Prefix-based | Any associative function |
| Flexibility      | Medium       | High                     |

Segment Trees are more powerful but heavier.

---

## 12. Interview Tips

* Know sum/min/max tree implementations
* Understand lazy propagation conceptually
* Be able to write build/query/update
* Practice boundary cases
* Understand when NOT to use segment tree (small array, few queries)

Asked at:

* Google (range queries)
* Amazon (range sum queries mutable)
* Codeforces (frequently used in contests)
* Meta (advanced problems with lazy propagation)

---

## 13. Practice Problems

### Beginner

* GFG: Range Sum Query
* LeetCode 303 (prefix sum version first, then mutable variant)

### Intermediate

* LeetCode 307. Range Sum Query — Mutable
* SPOJ – GSS1, GSS3

### Advanced

* Codeforces problems involving:

  * dynamic ranges
  * segment trees with lazy propagation
  * segment tree beats

---

## 14. Summary

Segment Trees provide:

* Fast range queries
* Fast updates
* Strong flexibility for different operations

