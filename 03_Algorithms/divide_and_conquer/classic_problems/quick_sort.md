# Quick Sort — Theory, Intuition, and Implementation

Quick Sort is a cornerstone of divide-and-conquer algorithms.
It is typically the fastest comparison-based sorting algorithm in practice due to excellent cache locality and average-case performance of O(n log n).

---

# 1. Definition

Quick Sort sorts an array by:

1. Picking a **pivot**.
2. **Partitioning** the array into elements < pivot and >= pivot.
3. Recursively sorting the left and right partitions.

---

# 2. Intuition (Why Quick Sort Works)

The idea is to place the pivot in its correct final position by partitioning the array.

Example partition:

```
Array: [7, 2, 9, 4, 3]
Pivot = 3

Less:  [2]
Pivot: [3]
Greater: [7, 9, 4]
```

After partitioning, pivot is fixed.
Repeat for left and right partitions until sorted.

---

# 3. Algorithm Structure

Divide: Choose a pivot and partition.

Conquer: Recursively sort left and right partitions.

Combine: Trivial, partitions form final sorted array.

---

# 4. Partitioning Methods

### 1. Lomuto Partition

* Single pointer
* Simplest to implement
* Usually slower

### 2. Hoare Partition

* Two pointers
* Faster in practice
* Swaps fewer elements

---

# 5. Pseudocode

### QuickSort using Lomuto Partition

```
function quickSort(arr, l, r):
    if l >= r:
        return

    p = partition(arr, l, r)
    quickSort(arr, l, p-1)
    quickSort(arr, p+1, r)

function partition(arr, l, r):
    pivot = arr[r]
    i = l

    for j from l to r-1:
        if arr[j] <= pivot:
            swap(arr[i], arr[j])
            i++

    swap(arr[i], arr[r])
    return i
```

---

# 6. ASCII Visualization

```
Array: [8 5 2 9 7]

Pivot = 7
Scan from left:

8 5 2 9 7
    ^
Elements <= pivot move to front:

[5 2 7 9 8]
       ↑ pivot placed here
```

Recursively apply to left and right parts until sorted.

---

# 7. Complexity Analysis

### Time Complexity

| Case    | Complexity | Explanation                                |
| ------- | ---------- | ------------------------------------------ |
| Best    | O(n log n) | balanced partition                         |
| Average | O(n log n) | pivot reasonably splits subarrays          |
| Worst   | O(n²)      | pivot always smallest/largest (unbalanced) |

### Space Complexity

* Worst: O(n) recursion depth
* Average: O(log n)

### Stable?

No. Quick Sort is not stable unless specifically modified.

---

# 8. Choosing the Pivot

Different pivot strategies:

* Last element (simple)
* Middle element
* Random element
* Median-of-three (improves performance)

Random or median-of-three pivot improves worst-case behavior in practice.

---

# 9. Variations

* 3-way Quick Sort (for arrays with many duplicates)
* Iterative Quick Sort (using a stack)
* In-place Quick Sort (standard)
* Parallel Quick Sort

### 3-way partition pseudocode

```
function quicksort3(arr, l, r):
    if l >= r: return

    pivot = arr[l]
    lt = l
    gt = r
    i = l

    while i <= gt:
        if arr[i] < pivot:
            swap(arr[i], arr[lt])
            i++
            lt++
        else if arr[i] > pivot:
            swap(arr[i], arr[gt])
            gt--
        else:
            i++

    quicksort3(arr, l, lt-1)
    quicksort3(arr, gt+1, r)
```

---

# 10. Edge Cases

* Already sorted array → worst-case O(n²) for simple pivot choice
* All elements equal → 3-way partition handles efficiently
* Very large n → tail-recursion optimization useful
* Negative numbers handled normally

---

# 11. Interview Tips

What they often ask:

1. Why Quick Sort is faster than Merge Sort in practice?
2. Explain partitioning approach.
3. What causes the worst case?
4. How to avoid worst case? (Random pivot)
5. Demonstrate partition manually.

Common follow-ups:

* Implement the 3-way Quick Sort
* Find kth smallest element (Quickselect)
* Sort colors (Dutch National Flag)

---

# 12. Practice Problems

### LeetCode

* Sort an Array
* Kth Largest Element in an Array (Quickselect based)
* Wiggle Sort II

### GFG

* Quick Sort Algorithm
* Quickselect variations

### Codeforces

* Tasks with custom partitioning
* Tasks requiring in-place ordering with constraints

---
