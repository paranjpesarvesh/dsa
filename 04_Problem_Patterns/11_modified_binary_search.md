# Modified Binary Search Pattern

Binary Search is one of the most important problem-solving tools.
The **modified binary search pattern** extends classic binary search to handle more complex situations:

* rotated sorted arrays
* infinite arrays
* unknown size arrays
* searching for boundaries (first/last occurrence)
* square root / peak element search
* searching in bitonic arrays
* minimizing/maximizing under constraints

This makes binary search useful far beyond simple sorted arrays.

---

# 1. Core Idea

Binary search relies on one condition:

> You can eliminate half of the search space using a decision rule.

Modified versions still keep this property, but modify the rule.

---

# 2. Key Situations Where Modified Binary Search Applies

## A. Find First or Last Occurrence

Sorted array may have duplicates.
General template:

```
ans = -1
while l <= r:
    mid = (l+r)//2
    if arr[mid] == target:
        ans = mid
        r = mid-1   # for first
        # l = mid+1 for last
    elif arr[mid] < target:
        l = mid+1
    else:
        r = mid-1
```

---

## B. Rotated Sorted Array

Array is sorted but rotated at an unknown pivot.

Rule to decide side:

```
if left half is sorted:
    check if target in this half
else:
    right half must be sorted
```

---

## C. Searching in Infinite/Unknown-Sized Array

Expand window exponentially:

```
start = 0
end = 1
while arr[end] < target:
    start = end
    end = end*2
```

Then do binary search in [start, end].

---

## D. Binary Search on Answer

Used when:

* direct binary search impossible
* answer must satisfy monotonic property
* constraints force minimize/maximize

Examples:

* minimum capacity to ship packages
* minimum time to complete tasks
* longest feasible value
* minimizing max distance

Rule:

```
lo = min_possible
hi = max_possible

while lo < hi:
    mid = (lo+hi)//2
    if condition(mid):
        hi = mid
    else:
        lo = mid+1
```

---

## E. Peak Element / Local Maximum

Use slope comparison:

```
if nums[mid] > nums[mid+1]:
    go left (peak in left including mid)
else:
    go right
```

---

# 3. General Template for Modified Binary Search

```
l = start
r = end

while l <= r:
    mid = (l+r)//2

    if condition(mid):     # problem-specific
        return / move boundary
    elif rule_for_left(mid):
        r = mid-1
    else:
        l = mid+1
```

Main idea:
**Define a condition that lets you discard half the search space.**

---

# 4. Decision Tree Visualization

For any mid:

```
             mid
     /                  \
discard left      discard right
```

The rule changes depending on the problem.

---

# 5. Time & Space Complexity

| Case                    | Time     | Space |
| ----------------------- | -------- | ----- |
| Basic Binary Search     | O(log n) | O(1)  |
| First/last occurrence   | O(log n) | O(1)  |
| Rotated array           | O(log n) | O(1)  |
| Binary search on answer | O(log R) | O(1)  |
| Peak finding            | O(log n) | O(1)  |

Where R = range of search values.

---

# 6. Variations and Edge Cases

* duplicates can break logic in rotated arrays
* middle index overflow (use `mid = l + (r-l)//2`)
* infinite array access exceptions
* monotonic condition must be proven
* negative values (in sqrt problems, ensure non-negative domain)
* checking boundaries correctly (avoid mid+1 out of bounds)

---

# 7. Interview Tips

* Highlight monotonicity when applying binary search on answer
* For rotated array, mention "one side is always sorted"
* Check boundaries first
* Clarify duplicate handling
* Explain how decision reduces search space
* Always consider edge cases: empty array, one element
* Be comfortable rewriting templates quickly
* Practice with variations (FAANG often modifies the search rules)

---

# 8. Practice Problems

### LeetCode

* 33 Search in Rotated Sorted Array
* 81 Search in Rotated Sorted Array II
* 34 Find First and Last Position
* 69 Sqrt(x)
* 540 Single Element in Sorted Array
* 852 Peak Index in Mountain Array
* 410 Split Array Largest Sum
* 875 Koko Eating Bananas
* 1011 Ship Packages in D Days
* 744 Find Smallest Letter Greater Than Target

### GFG

* First and last occurrence
* Peak element
* Painters partition problem
* Allocate minimum number of pages

### Codeforces

* Binary search on answer for scheduling
* Finding maximum possible minimum distance
* Lower_bound/upper_bound applications

---

# 9. Summary

The modified binary search pattern is about recognizing when a problem has:

1. a monotonic condition
2. a property allowing elimination of half the space
3. boundaries to compute
4. structural hints (e.g., rotated, mountain, sorted blocks)

Once recognized, the solution becomes **clean, efficient**, and almost always O(log n).

---
