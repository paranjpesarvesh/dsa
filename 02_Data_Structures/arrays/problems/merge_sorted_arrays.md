# Merge Sorted Arrays

Location: `02_Data_Structures/arrays/problems/merge_sorted_arrays.md`

---

## Problem Description

You are given two **sorted** arrays and must merge them into a single **sorted** array.

Examples:

```
Input:
A = [1,3,5]
B = [2,4,6]

Output:
[1,2,3,4,5,6]
```

---

## Why This Problem Matters

* Teaches two-pointer technique
* Foundation for merge sort
* Very common subroutine in interviews
* Used in merging K sorted arrays, merging intervals, merging linked lists

---

## Core Idea: Two Pointers

Use two pointers:

```
i → array A
j → array B
```

At each step, pick the smaller of the two elements and append to the result.

---

## Step-by-Step Walkthrough

Let:

```
A = [1,3,5]
B = [2,4,6]
```

Pointers:

```
i=0, j=0 → compare A[i]=1, B[j]=2  → pick 1
i=1, j=0 → compare 3 and 2        → pick 2
i=1, j=1 → pick 3
i=2, j=1 → pick 4
i=2, j=2 → pick 5
i=3, j=2 → A exhausted → append leftover from B
```

Result:

```
[1,2,3,4,5,6]
```

---

## Pseudocode

```
function merge_sorted(A, B):
    i = 0
    j = 0
    result = []

    while i < len(A) and j < len(B):
        if A[i] <= B[j]:
            result.append(A[i])
            i += 1
        else:
            result.append(B[j])
            j += 1

    append remaining elements of A (if any)
    append remaining elements of B (if any)

    return result
```

---

## Time & Space Complexity

| Algorithm                     | Time   | Space  |
| ----------------------------- | ------ | ------ |
| Merge with extra array        | O(n+m) | O(n+m) |
| Merge in-place (special case) | O(n+m) | O(1)   |

---

## In-Place Merge Variants

### Case 1: A has extra space at the end (LeetCode 88)

Example:

```
A = [1,2,3,_,_,_]
B = [2,5,6]
```

Use **three pointers from the back**:

```
i = last valid in A
j = last in B
k = last index in A (overall)
```

This avoids overwriting elements not yet processed.

Pseudocode:

```
while i>=0 and j>=0:
    if A[i] > B[j]:
        A[k] = A[i]
        i -= 1
    else:
        A[k] = B[j]
        j -= 1
    k -= 1
```

---

## Visual Aid: Two Pointer Movement

```
A: 1 3 5
      ^
B: 2 4 6
    ^

Result: [1,2,3,4,5,6]
```

---

## Edge Cases

* One array empty

  * return the other directly
* All elements of one array smaller

  * append entire array
* Duplicate values

  * stable: elements from A come before equal elements from B
* Different sizes
* Negative numbers / mixed signed values
* Very large arrays (memory constraints matter)

---

## Variations

1. Merge K sorted arrays

   * Use min-heap or divide-and-conquer
2. Merge sorted linked lists

   * Similar two-pointer idea
3. Merge intervals

   * Similar pattern but comparing ranges
4. In-place merging without extra memory for both arrays

   * Advanced problem

---

## Interview Tips

* Emphasize O(n+m) time
* Explain pointer movement clearly
* If asked about in-place:

  * mention the “merge from back” trick
* Show understanding of stable merging
* If arrays extremely large:

  * consider memory trade-offs

---

## Practice Problems

1. LeetCode 88 – Merge Sorted Array
2. Merge K Sorted Lists – LeetCode 23
3. Merge Sorted Linked Lists – GFG
4. Merge Two 2D intervals lists (custom extension)

---
