# Heapify (Down-Heapify & Up-Heapify)

This document explains the **Heapify** process used to build, maintain, and restore heap properties in both **Min Heaps** and **Max Heaps**. It includes intuition, diagrams, algorithms, pseudocode, complexities, and interview tips.

---

## 1. What is Heapify?

Heapify is the process of restoring the heap property after structural changes.

A heap is a **complete binary tree** with the following property:

* **Min Heap**: parent ≤ children
* **Max Heap**: parent ≥ children

Heapify ensures that this property is maintained.

There are two main forms:

1. **Down-Heapify** (a.k.a. heapify, sift-down, bubble-down)
2. **Up-Heapify** (a.k.a. sift-up, bubble-up)

---

## 2. When Do We Use Heapify?

### Down-Heapify is used after:

* Removing the root
* Replacing root with last element
* Building heap from array

### Up-Heapify is used after:

* Inserting a new element at the bottom
* Increasing/decreasing a key
* Updating priorities

---

## 3. Intuition Behind Heapify

### Down-Heapify visual:

```
        10
      /    \
     3      8
```

If 10 is at the root (in Min Heap), the property is violated:

We compare with children:

* Find smaller child (3)
* Swap 10 ↔ 3
* Continue recursively until heap property restored

---

## 4. Down-Heapify Algorithm (Min Heap)

### Pseudocode

```
heapify(i):
    smallest = i
    left = 2*i + 1
    right = 2*i + 2

    if left < n and a[left] < a[smallest]:
        smallest = left

    if right < n and a[right] < a[smallest]:
        smallest = right

    if smallest != i:
        swap(a[i], a[smallest])
        heapify(smallest)
```

Key idea:
At each step, push the violated element down to its correct position.

---

## 5. Up-Heapify Algorithm (Min Heap)

### Pseudocode

```
up_heapify(i):
    while i > 0:
        parent = (i - 1) // 2
        if a[parent] > a[i]:
            swap(a[parent], a[i])
            i = parent
        else:
            break
```

Key idea:
Push the new inserted element upward until it reaches correct position.

---

## 6. Building a Heap Using Heapify

Technique: **bottom-up heap construction**
Start from the last internal node and apply down-heapify.

Pseudocode:

```
for i = n/2 - 1 down to 0:
    heapify(i)
```

This builds the heap in **O(n)** time.

---

## 7. Why Is Heapify O(log n)?

At each level:

* A node might move down/up one level.
* Heap height is O(log n).

Thus:

* Down-heapify → O(log n)
* Up-heapify → O(log n)

Building heap (bottom-up technique) takes **O(n)**, not O(n log n).

Reason: lower levels have many nodes with very short heapify paths.

---

## 8. ASCII Diagram of Heapify (Min Heap Example)

Initial min-heap violation:

```
         15
       /    \
     5       8
    / \
   3   4
```

Heapify step:

```
Compare 15 with children 5 and 8 → smallest is 5
Swap 15 ↔ 5
```

After swap:

```
         5
       /    \
     15      8
    / \
   3   4
```

Next step:

```
Compare 15 with children 3 and 4 → smallest is 3
Swap 15 ↔ 3
```

Final heap:

```
         5
       /    \
     3       8
    / \
   15  4
```

---

## 9. Variations

### 1. Max Heapify

Replace comparisons:

* Use `>` instead of `<`

### 2. D-ary Heapify

Children indexes become:

```
children: d*i + 1 ... d*i + d
```

Used in priority queues with high branching factor.

### 3. Heapify with key updates

Special operations include:

* Increase-key
* Decrease-key

Apply appropriate heapify version (up or down) depending on adjusted key.

---

## 10. Edge Cases

* Heap with one element → no work
* Updating a leaf → no heapify required
* Duplicate values → stable structure not guaranteed
* Overflows in index arithmetic → careful with large arrays

---

## 11. Interview Tips

These are commonly asked in FAANG/GATE:

1. Why heapify is O(log n)?
   (Explain height-based reasoning)

2. Why building heap is O(n)?
   (Emphasize bottom-up approach)

3. What if we use up-heapify for building heap?
   Complexity becomes O(n log n)

4. What is the array representation rule?

   * left child = 2*i + 1
   * right child = 2*i + 2

5. Is inorder traversal of heap sorted?
   No.

6. How to get sorted array from heap?
   Apply extract-min repeatedly → Heap Sort.

---

## 12. Practice Problems

### LeetCode

* 215. Kth Largest Element in an Array
* 973. K Closest Points to Origin
* 703. Kth Largest Element in a Stream
* 1471. The K Strongest Values in an Array

### GFG

* Build Heap
* Heapify
* Heap Sort

### Codeforces

* Priority queue simulation tasks

---

## 13. Summary

* Heapify restores heap property.
* Two types: down-heapify and up-heapify.
* Down-heapify is crucial for heap-building and extract operations.
* Up-heapify maintains heap after insertions.
* Combined, they form the foundation of heaps and priority queues.

