# Binary Search — Theory, Intuition, and Patterns

Binary search is one of the most fundamental **divide-and-conquer** algorithms.
Its power lies not only in searching sorted arrays but also in optimizing answers over a *monotonic search space*.

---

## 1. Definition

Binary Search is an algorithm that repeatedly divides the search interval into two halves until the target/answer is found or the interval becomes invalid.

Classic binary search requires:

1. Array/list is **sorted**.
2. You can decide which side to discard on each comparison.

---

## 2. Mathematical Intuition

Binary Search reduces the search space by half every iteration.

If the initial size = n
After 1 step: n/2
After 2 steps: n/4
After k steps: n / 2^k

Stop when size becomes 1:

n / 2^k = 1
=> 2^k = n
=> k = log₂(n)

Thus **time complexity = O(log n)**.

---

## 3. Standard Algorithm (Classic Array Search)

### Pseudocode

```
function binary_search(arr, target):
    low = 0
    high = n-1
    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] == target:
            return mid
        else if arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1
```

---

## 4. Binary Search Variants

Binary Search is rarely used directly for plain element search in interviews.
Most questions rely on **variants**.

### 4.1 Lower Bound (first index >= target)

```
while low < high:
    mid = (low + high) // 2
    if arr[mid] < target:
        low = mid + 1
    else:
        high = mid
return low
```

### 4.2 Upper Bound (first index > target)

Same structure as lower bound but comparison flips.

---

## 5. Binary Search on Answer (Advanced Interview Pattern)

In modern interview questions, binary search is often used on an **answer space**, not an array.

Triggers:

* “minimize the maximum”
* “maximize the minimum”
* “find the smallest x such that condition(x) is true”
* search space is monotonic

Examples:

* Allocate books (minimize max pages)
* Aggressive cows
* Minimum eating speed (Koko eating bananas)
* Capacity to ship packages

### Algorithm Pattern

```
low = min_possible_answer
high = max_possible_answer

while low < high:
    mid = (low + high) // 2
    if check(mid) == true:
        high = mid
    else:
        low = mid + 1

return low
```

The `check(x)` is a **feasibility function**.

---

## 6. Binary Search on Rotated Array

Problem pattern:

* array was sorted and then rotated
* find an element or minimum

Key Insight:
One half is always sorted.

---

## 7. Binary Search on Real Numbers

Used when:

* precision needed
* function is monotonic

Example:

* find sqrt(n) with precision 1e-6

---

## 8. Complexity

| Operation | Complexity |
| --------- | ---------- |
| Time      | O(log n)   |
| Space     | O(1)       |

---

## 9. Common Pitfalls

1. Overflow in `(l+r)/2`
   Fix: use `l + (r - l) / 2`

2. Infinite loops
   Ensure `low < high` or `low <= high` based on variant.

3. Wrong update logic
   Most errors come from misplacing +1 or -1.

4. Incorrect boundary return
   `low` vs `high` depends on loop invariant.

---

## 10. Interview Tips

* Always clarify sortedness.
* Ask if duplicates allowed.
* Always confirm the required variant:

  * find ANY occurrence?
  * first occurrence?
  * last occurrence?
* For “minimize/maximize” problems:
  Build a feasibility function `f(x)`, then apply binary search on x.

---

## 11. ASCII Diagram

### Classic Working Visualization

```
Initial:     low ---------------------- high
Step 1:      low -------- mid -------- high
Step 2:      low --- mid --- high
Step 3:      low mid high
Final:         target found
```

---

## 12. Practice Problems

### Easy

* Binary search (LeetCode 704)
* Search insert position (LC 35)
* First bad version (LC 278)

### Medium

* Search rotated sorted array (LC 33)
* Find min in rotated sorted array (LC 153)
* Peak element (LC 162)

### Hard

* Divide chocolates / Allocate books
* Aggressive cows (SPOJ)
* Koko eating bananas (LC 875)
* Median of two sorted arrays (LC 4)

---
