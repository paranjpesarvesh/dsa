# **Bubble Sort — Theory, Intuition & Implementation**

---

## **1. What is Bubble Sort?**

Bubble Sort is a simple comparison-based sorting algorithm that repeatedly scans the array, **swapping adjacent elements** if they are in the wrong order.
It gets its name because **larger elements “bubble up”** to the end of the array with each pass.

---

## **2. Intuition**

Imagine bubbles in water: the biggest bubble naturally rises to the top.
Similarly, in each pass of bubble sort, the largest unsorted element moves to its correct final position.

```
[5 3 1 4 2]
 pass 1 → largest moves to end
 pass 2 → second largest moves to end
 ...
```

---

## **3. How Bubble Sort Works (Step-by-step)**

1. Start from the beginning of the array.
2. Compare adjacent elements.
3. Swap if they are out of order.
4. After one full pass, the largest element is placed at the end.
5. Continue passes, ignoring already sorted end segment.

---

## **4. Visual Diagram**

### Example: Sort `[4 3 1 2]`

```
Pass 1:
4 3 1 2 → compare 4,3 swap
3 4 1 2 → compare 4,1 swap
3 1 4 2 → compare 4,2 swap
3 1 2 4   largest (4) fixed

Pass 2:
3 1 2 4 → compare 3,1 swap
1 3 2 4 → compare 3,2 swap
1 2 3 4   second largest fixed
```

---

## **5. Optimized Version (Early Exit)**

If no swaps happen in a pass → array already sorted → break early.

---

## **6. Pseudocode**

```
function bubbleSort(arr):
    n = length(arr)

    repeat n-1 times:
        swapped = false

        for i in 0 to n-2:
            if arr[i] > arr[i+1]:
                swap(arr[i], arr[i+1])
                swapped = true

        if swapped == false:
            break
```

---

## **7. Time & Space Complexity**

| Case                                  | Complexity      |
| ------------------------------------- | --------------- |
| **Worst**                             | O(n²)           |
| **Average**                           | O(n²)           |
| **Best** (already sorted + optimized) | O(n)            |
| **Space**                             | O(1) — in-place |

---

## **8. Variations**

* **Cocktail Shaker Sort** (bidirectional bubble sort)
* **Recursive Bubble Sort**
* **Optimized bubble sort with shrinking range**

---

## **9. Edge Cases**

* Already sorted array → O(n)
* Reverse sorted array → O(n²)
* Works on any data type supporting comparisons

---

## **10. Interview Tips**

* Rarely used in real systems; used to test **basic sorting understanding**.
* FAANG rarely asks for bubble sort directly but may ask:

  * “Explain why bubble sort is inefficient.”
  * “Compare bubble sort with insertion sort.”

---

## **11. Practice Problems**

### **LeetCode**

* Sort Colors (conceptually similar to bubble passes)

### **GFG**

* Bubble Sort implementation problem
* Count swaps using bubble sort logic

### **Codeforces**

* Problems involving adjacent swaps

---
