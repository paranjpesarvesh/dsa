# **Merge Sort — Complete Notes (Clear, Concise & Interview-Ready)**

---

## **1. What is Merge Sort?**

Merge Sort is a **divide-and-conquer**, **stable**, **comparison-based** sorting algorithm.

It works by:

1. Dividing the array into halves
2. Sorting each half recursively
3. Merging the two sorted halves

---

## **2. Intuition**

Think of merge sort as repeatedly splitting a list until you have single-element lists (always sorted), then repeatedly merging them in sorted order.

ASCII visualization:

```
[5 2 4 7 1 3]

Split:
[5 2 4]        [7 1 3]
[5] [2 4]      [7] [1 3]
[5] [2] [4]    [7] [1] [3]

Merge up:
[2 4 5]        [1 3 7]

Final merge:
[1 2 3 4 5 7]
```

---

## **3. Algorithm Steps**

1. **Divide**: Recursively split array into left and right halves
2. **Conquer**: Recursively sort both halves
3. **Merge**: Combine sorted halves into a new sorted array

---

## **4. Pseudocode**

```
mergeSort(arr, l, r):
    if l >= r: return
    mid = (l + r) // 2
    mergeSort(arr, l, mid)
    mergeSort(arr, mid+1, r)
    merge(arr, l, mid, r)

merge(arr, l, m, r):
    create temp array
    i = l, j = m+1
    while i <= m and j <= r:
        if arr[i] <= arr[j]:
            push arr[i]
            i++
        else:
            push arr[j]
            j++
    append remaining elements
    copy back to arr[l...r]
```

---

## **5. Complexity Analysis**

| Operation      | Complexity |
| -------------- | ---------- |
| Time (Best)    | O(n log n) |
| Time (Average) | O(n log n) |
| Time (Worst)   | O(n log n) |
| Space          | O(n) extra |
| Stable?        | **Yes**    |
| In-place?      | **No**     |

---

## **6. Why O(n log n)?**

* Tree height of recursion = log n
* Each level merges a total of n elements

Total = n × log n

---

## **7. Variants**

* **In-place merge sort** → reduces space but complex
* **Bottom-up merge sort** → iterative, no recursion
* **TimSort** → hybrid using insertion + merge sort (used in Python/Java)

---

## **8. Edge Cases**

* Empty array
* Single element
* Large data requiring external sorting (merge sort works great!)
* Nearly sorted → still O(n log n)

---

## **9. Flowchart-Style Summary**

```
                ┌──────────────┐
                │  mergeSort() │
                └──────┬───────┘
                       │
               l >= r? ──▶ return
                       │
               mid = (l+r)/2
                 /           \
                ▼             ▼
        mergeSort(left)   mergeSort(right)
                \             /
                 ▼           ▼
                ───── merge ─────
                       │
                       ▼
                Sorted segment
```

---

## **10. Interview Tips**

* Emphasize stability.
* Highlight predictable O(n log n).
* Explain external sorting use-case (files larger than RAM).
* Prepare to contrast with quicksort:

  * QuickSort = in-place, but unstable & worst-case O(n²)
  * MergeSort = stable, guaranteed O(n log n)

---

## **11. Practice Problems**

### LeetCode

* Sort List
* Merge k Sorted Lists (merge technique)
* Count Inversions (via merge sort)

### GFG

* Merge Sort
* Inversion Count using Merge Sort

### Codeforces

* Problems involving counting inversions or merging sequences

---
