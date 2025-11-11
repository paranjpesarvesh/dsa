# Merge Sort — Theory, Intuition, and Implementation

Merge Sort is a classic **divide-and-conquer** sorting algorithm that recursively splits the array into halves, sorts them, and merges the sorted halves.

It is stable, predictable, and has guaranteed O(n log n) performance.

---

# 1. Definition

Merge sort sorts an array by applying three main steps:

1. **Divide:** Split the array into two halves.
2. **Conquer:** Recursively sort the left and right halves.
3. **Combine:** Merge the two sorted halves into one sorted array.

---

# 2. Intuition (Why It Works)

The key idea is that merging two sorted arrays can be done in linear time.

Example merge:

```
Left:  [1, 4, 7]
Right: [2, 3, 6]

→ 1 2 3 4 6 7
```

By recursively ensuring each half is sorted, the final merge produces a globally sorted array.

---

# 3. Algorithm Structure

At each recursion level:

* Array of size n is split into 2 subarrays of size n/2.
* Each subarray is recursively sorted.
* Merging takes O(n).

Total depth of recursion: log₂n
Work per level: O(n)

→ Total time: O(n log n)

---

# 4. Step-by-Step Breakdown

### 1. Base Case

If array size ≤ 1, it is already sorted.

### 2. Recursive Division

Split at mid:

```
mid = (l + r) // 2
```

### 3. Conquer

Recursively sort the left and right halves.

### 4. Combine

Merge the sorted halves using pointers.

---

# 5. Pseudocode

```
function mergeSort(arr, l, r):
    if l >= r:
        return

    mid = (l + r) // 2
    mergeSort(arr, l, mid)
    mergeSort(arr, mid+1, r)

    merge(arr, l, mid, r)

function merge(arr, l, mid, r):
    create temp array
    i = l, j = mid+1

    while i <= mid and j <= r:
        if arr[i] <= arr[j]:
            temp.push(arr[i])
            i++
        else:
            temp.push(arr[j])
            j++

    append remaining elements

    copy temp back to arr[l..r]
```

---

# 6. ASCII Merge Visualization

```
Original: [5 3 8 4 2 7 1 6]

         /                  \
 [5 3 8 4]                 [2 7 1 6]
     /    \                  /     \
 [5 3]   [8 4]            [2 7]   [1 6]
  / \     / \             / \      / \
[5] [3] [8] [4]         [2] [7]  [1] [6]

After merging bottom up:

[3 5]     [4 8]        [2 7]     [1 6]
   \       /             \         /
   [3 5 4 8]             [2 7 1 6]
           \            /
       [1 2 3 4 5 6 7 8]
```

---

# 7. Complexity Analysis

### Time

* Best: O(n log n)
* Average: O(n log n)
* Worst: O(n log n)

### Space

* O(n) extra (temp array for merging)
* Tail recursion depths are O(log n)

### Stability

* Merge sort is **stable** (relative order preserved).

---

# 8. Edge Cases

* Empty array: return as is
* Array of size 1: already sorted
* All elements identical: no change
* Negative values: merge works normally
* Large n: recursion depth may cause stack issues in some languages

---

# 9. Variations

* **Bottom-up merge sort** (iterative)
* **In-place merge sort** (complex, rarely used)
* **Parallel merge sort** (splits work across threads)
* External merge sort (used in databases for huge datasets)

---

# 10. Interview Tips

1. Be prepared to explain **why merging is O(n)**.
2. Show recursion tree to justify O(n log n).
3. Discuss stability & space overhead.
4. Often asked in:

   * Amazon
   * Google
   * Meta
   * Microsoft

Common follow-up problems:

* Count inversions (uses merge step)
* Find small K numbers (related merging logic)
* Merge k sorted lists

---

# 11. Practice Problems

### LeetCode

* Sort List
* Merge K Sorted Lists
* Count of Smaller Numbers After Self (modified merge)

### GFG

* Merge Sort
* Count Inversions

### Codeforces

* Problems requiring stable sorting or inversion counting

---
