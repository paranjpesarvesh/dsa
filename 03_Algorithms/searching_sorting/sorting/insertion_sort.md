# **Insertion Sort — Complete Notes (Clear & Interview-Oriented)**

---

## **1. What is Insertion Sort?**

Insertion Sort is a simple, intuitive, comparison-based sorting algorithm that builds the final sorted array **one element at a time**, similar to how you sort cards in your hand.

It is ideal for:

* Small arrays
* Nearly sorted arrays
* Online sorting (input arrives gradually)

---

## **2. Intuition**

You maintain a **sorted left portion** of the array.

At each step:

1. Take the next element (`key`)
2. Shift all larger elements in the sorted portion to the right
3. Insert `key` in its correct position

---

## **3. Example & Visualization**

### Array:

```
[5, 2, 4, 6, 1]
```

### Steps:

```
i=1 → key=2
[5, 2, 4, 6, 1] → compare 2 with 5 → shift
[2, 5, 4, 6, 1]

i=2 → key=4
[2, 5, 4, 6, 1] → shift 5
[2, 4, 5, 6, 1]

i=3 → key=6
[2, 4, 5, 6, 1] → already correct

i=4 → key=1
Shift 6,5,4,2
[1, 2, 4, 5, 6]
```

Final output:

```
[1, 2, 4, 5, 6]
```

---

## **4. Pseudocode**

```
insertionSort(arr):
    n = length(arr)
    for i from 1 to n-1:
        key = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > key:
            arr[j+1] = arr[j]
            j = j - 1

        arr[j+1] = key
```

---

## **5. Complexity Analysis**

| Case                  | Time      |
| --------------------- | --------- |
| Best (already sorted) | **O(n)**  |
| Average               | **O(n²)** |
| Worst                 | **O(n²)** |
| Space                 | **O(1)**  |
| Stable?               | **Yes**   |
| In-place?             | **Yes**   |

### Why is best case O(n)?

Only one comparison per element; no shifting.

---

## **6. Edge Cases**

* Already sorted → fastest
* Reverse sorted → worst
* Many duplicates → efficient (stable)
* Large arrays → not ideal

---

## **7. Variations**

* **Binary Insertion Sort** → uses binary search to find position (still O(n²))
* **Shell Sort** → generalization of insertion sort using gaps

---

## **8. Interview Tips**

* Emphasize practicality for small/n early sorted arrays.
* Mention that it is **stable** → preserves equal element order.
* Used in:

  * TimSort (Python’s sort)
  * Hybrid algorithms switching to insertion sort for small segments
* Show that you understand shifting vs swapping (shifting reduces operations).

---

## **9. Practice Problems**

### **LeetCode**

* Sort Colors (in-place stable reasoning)
* Insertion Sort List

### **GFG**

* Insertion Sort
* Binary Insertion Sort

### **Codeforces**

* Problems that require maintaining sorted sequences dynamically

---
