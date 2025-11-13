# **Radix Sort — Complete Notes (Clear & Interview-Ready)**

---

## **1. What is Radix Sort?**

Radix Sort is a **non-comparative**, **linear-time** sorting algorithm that sorts numbers digit by digit (or characters by character position).

It uses a **stable subroutine**, commonly **Counting Sort**, on each digit.

---

## **2. Intuition**

Instead of comparing elements (like merge/quick sort), radix sort groups elements by digits.

Two common approaches:

1. **LSD (Least Significant Digit) → Most common**
   Sort from rightmost digit to leftmost.

2. **MSD (Most Significant Digit)**
   Sort from leftmost digit to rightmost.

ASCII intuition (LSD):

```
Numbers: 170 45 75 90 802 24 2 66

Step 1: sort by 1's place
  170 90 802 2 24 45 75 66

Step 2: sort by 10's place
  802 2 24 45 66 170 75 90

Step 3: sort by 100's place
  2 24 45 66 75 90 170 802
```

---

## **3. How It Works (LSD Version)**

1. Determine max number of digits
2. For digit `d` from least → most significant:

   * Use **stable counting sort** on digit `d`.

---

## **4. Pseudocode**

```
radixSort(arr):
    maxVal = max(arr)
    exp = 1

    while maxVal / exp > 0:
        countingSortByDigit(arr, exp)
        exp *= 10

countingSortByDigit(arr, exp):
    count[0..9] = 0
    output[n]

    for each element:
        digit = (element/exp)%10
        count[digit]++

    prefix sum on count

    for i from n-1 downto 0:    // stable
        digit = (arr[i]/exp)%10
        place arr[i] in output

    copy output to arr
```

---

## **5. Complexity**

| Case    | Time           |
| ------- | -------------- |
| Best    | O((n + k) * d) |
| Average | O((n + k) * d) |
| Worst   | O((n + k) * d) |

Where:

* `d` = number of digits
* `k` = base (10 for decimal)

Space = O(n + k)

**Works best when:**

* Numbers have limited digit length
* Integers in a fixed range
* Strings of fixed length

---

## **6. Why Is It Linear?**

Radix sort does not compare values; it processes a constant number of digits.

For fixed digit count (like 32-bit integers), `d` is constant → **O(n)**.

---

## **7. Variants**

* **LSD Radix Sort** (most used)
* **MSD Radix Sort** (useful for strings)
* Radix sort with base 2⁸ or 2¹⁶ for faster processing

---

## **8. Edge Cases**

* Negative numbers → special handling needed
* Very large digit count → reduces efficiency
* Must use a *stable* sort at each digit step

---

## **9. Flowchart-Style ASCII**

```
           ┌───────────────┐
           │  radixSort()  │
           └───────┬───────┘
                   │
            find max digits
                   │
            for each digit d:
                   ▼
          countingSort(arr, d)
                   │
                   ▼
               Sorted array
```

---

## **10. Interview Tips**

* Always mention: **Radix sort is non-comparative**
* Explain need for **stable** sort at each phase
* Mention: **Used in systems where keys have fixed width (e.g., integers, IPs, strings)**
* Compare with counting sort:

  * Counting sort works for small range
  * Radix sort breaks large numbers into small digits → efficient

---

## **11. Practice Problems**

### LeetCode

* Sort Characters By Frequency
* Maximum Gap (solvable using radix)

### GFG

* Radix Sort

### Codeforces

* Problems involving digit bucketing / non-comparative sorting techniques

---
