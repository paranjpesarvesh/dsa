# **Selection Sort — Complete Notes (Clear & Interview-Ready)**

---

## **1. What is Selection Sort?**

Selection Sort is a simple comparison-based sorting algorithm.

**Idea:**
Repeatedly select the **minimum** (or maximum) element from the unsorted part and place it at its correct position.

---

## **2. Intuition**

Imagine sorting cards by repeatedly picking the smallest one and placing it at the start.

ASCII intuition:

```
Unsorted: [7, 4, 1, 3]

Round 1: find min → 1 → swap with index 0
[1, 4, 7, 3]

Round 2: find min in remaining → 3 → swap with index 1
[1, 3, 7, 4]

Round 3: find min in remaining → 4 → swap with index 2
[1, 3, 4, 7]
```

---

## **3. Algorithm Steps**

1. For each index `i` from `0 → n-1`:

   * Find the minimum element in `i…n-1`.
   * Swap it with element at index `i`.

---

## **4. Pseudocode**

```
selectionSort(arr):
    n = length(arr)
    for i from 0 to n-2:
        minIndex = i
        for j from i+1 to n-1:
            if arr[j] < arr[minIndex]:
                minIndex = j
        swap arr[i] and arr[minIndex]
```

---

## **5. Time & Space Complexity**

| Case    | Time  |
| ------- | ----- |
| Best    | O(n²) |
| Average | O(n²) |
| Worst   | O(n²) |

Space = **O(1)** (in-place)

**Stable?**  No
Why?
Swapping can change the relative order of equal elements.

---

## **6. Visual Flowchart (ASCII)**

```
i = 0
│
▼
Find min in unsorted part
│
▼
Swap with position i
│
▼
i = i + 1
│
▼
Repeat until array sorted
```

---

## **7. Advantages & Disadvantages**

###  Advantages

* Simple to implement
* Performs well on small arrays
* Minimal number of swaps

###  Disadvantages

* Always O(n²) comparisons
* Not stable
* Not suitable for large datasets

---

## **8. Edge Cases**

* Single element → already sorted
* All equal elements → runs full O(n²)
* Already sorted array → still O(n²)

---

## **9. Interview Tips**

* Mention: **Selection sort minimizes swaps (only n swaps)**
* Compare with Bubble Sort:

  * Bubble sort has many swaps but stops early if sorted
  * Selection sort always scans full array
* Used in cases where **swaps are expensive but comparisons are cheap**

---

## **10. Practice Problems**

### LeetCode

(Not directly selection sort based, but good for practicing basic sorting)

* 912. Sort an Array
* 215. Kth Largest Element

### GFG

* Selection Sort
* Sort an array of 0s, 1s, and 2s (can be solved more optimally)

### Codeforces

* Beginner constructive problems requiring manual sorting logic

---
