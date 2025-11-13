# **Binary Search — Theory, Intuition & Templates**

---

## **1. What is Binary Search?**

Binary Search is a **divide-and-conquer** algorithm used to efficiently find an element in a **sorted array** (or monotonic function domain).

At each step:

```
Check mid → decide left or right → discard half of the search space
```

Time complexity becomes logarithmic.

---

## **2. When Can You Use Binary Search?**

Binary search works when:

1. Data is **sorted**
2. Search space is **monotonic** (increasing/decreasing or true/false pattern)
3. You can determine which half to discard

Examples beyond arrays:

* Searching on **answer** (Binary Search on Results)
* Monotonic functions
* Finding first/last occurrence
* Peak element in bitonic array

---

## **3. Visual Intuition**

Array (sorted):

```
Index: 0 1 2 3 4 5 6
Value: 2 4 7 9 13 18 21
              ↑
            mid=3
```

Compare:

```
target < arr[mid] → search left
target > arr[mid] → search right
```

---

## **4. Classic Binary Search (Iterative)**

```
function binarySearch(a, x):
    low = 0
    high = n-1

    while low ≤ high:
        mid = low + (high - low) // 2

        if a[mid] == x:
            return mid
        else if a[mid] < x:
            low = mid + 1
        else:
            high = mid - 1

    return -1
```

---

## **5. Variants (Must-Know for Interviews)**

### **A. First Occurrence**

```
function firstOcc(a, x):
    low = 0, high = n-1, ans = -1
    while low ≤ high:
        mid = (low + high) // 2
        if a[mid] ≥ x:
            if a[mid] == x:
                ans = mid
            high = mid - 1
        else:
            low = mid + 1
    return ans
```

### **B. Last Occurrence**

Similar to above but move `low = mid + 1`.

### **C. Lower Bound**

First index `i` where `a[i] ≥ x`.

### **D. Upper Bound**

First index `i` where `a[i] > x`.

---

## **6. Binary Search on Answers (BSOA)**

Used when the **answer lies in a numeric range**, and your function is monotonic (true → false or false → true).

Examples:

* Minimum time to complete tasks
* Minimum capacity to ship packages
* Allocate pages problem
* Koko eating bananas

Template:

```
low = min_possible
high = max_possible
while low < high:
    mid = (low + high) // 2
    if check(mid):          # monotonic condition
        high = mid
    else:
        low = mid + 1
return low
```

---

## **7. Complexity**

| Operation | Complexity                                 |
| --------- | ------------------------------------------ |
| Time      | **O(log n)**                               |
| Space     | **O(1)** iterative, **O(log n)** recursive |

---

## **8. Common Pitfalls**

* **Overflow:** use `mid = low + (high - low) // 2`
* Incorrect boundaries (exclusive vs inclusive)
* Infinite loop due to wrong update
* Not resolving tie conditions (example: first/last occurrence)
* Using array not fully sorted

---

## **9. Interview Tips**

* Binary Search is the **most tested algorithm** in FAANG.
* Be ready for:

  * First/last occurrence
  * Search in rotated sorted array
  * Find peak element
  * Binary search on answer problems
* Clearly explain monotonic behaviour
* Always justify termination condition

---

## **10. Practice Problems**

### **LeetCode**

* 704 — Binary Search
* 34 — First & Last Position
* 33 — Search in Rotated Sorted Array
* 153 — Minimum in Rotated Sorted Array
* 852 — Peak Index in Mountain Array
* 410 — Split Array Largest Sum (BS on answer)

### **GFG**

* Number of occurrences
* Allocate minimum number of pages

### **Codeforces**

* Binary search on answer in greedy problems
* Monotonic decision problems

---
