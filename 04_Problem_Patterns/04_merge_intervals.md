# Merge Intervals Problem Pattern

The **Merge Intervals** problem pattern is a **common technique** in competitive programming and interviews for handling **interval-based problems**. It involves **sorting intervals and merging overlapping ones** efficiently.

---

## 1. Definition

Given a list of intervals represented as `[start, end]`, the goal is often to:

- Merge overlapping intervals.
- Insert a new interval and merge if necessary.
- Count overlapping intervals.
- Find gaps or free time intervals.

**Core idea:** Sorting intervals by **start time** makes merging straightforward by comparing **current interval** with the **previous merged interval**.

---

## 2. When to Use

- **Overlapping interval problems**: merge, insert, intersect, or subtract intervals.
- **Scheduling problems**: meetings, reservations, or timeline conflicts.
- **Range queries**: covering ranges efficiently.

**Common problems:**

- Merge overlapping intervals.
- Insert interval.
- Meeting rooms / scheduling conflicts.
- Maximum number of overlapping intervals.

---

## 3. Template Approach

### Step-by-step reasoning

1. **Sort intervals** by start time.
2. Initialize an empty `merged` list.
3. Iterate through each interval:
   - If the `merged` list is empty or current interval does not overlap with last merged interval, **append it**.
   - Else, **merge** with the last interval by updating the `end`.
4. Return `merged` intervals.

---

### 3.1 Pseudocode

```

function mergeIntervals(intervals):
if intervals is empty:
return \[]

```
sort intervals by start time
merged = [intervals[0]]

for i in 1 to len(intervals)-1:
    current = intervals[i]
    last = merged[-1]

    if current.start > last.end:
        merged.append(current)
    else:
        last.end = max(last.end, current.end)

return merged
```

```

---

### 3.2 Python Implementation

```python
def merge_intervals(intervals):
    """
    Merge overlapping intervals.

    Args:
        intervals: List of intervals [start, end]

    Returns:
        List of merged intervals
    """
    if not intervals:
        return []

    # Sort by start time
    intervals.sort(key=lambda x: x[0])
    merged = [intervals[0]]

    for current in intervals[1:]:
        last = merged[-1]
        if current[0] > last[1]:
            merged.append(current)  # No overlap
        else:
            last[1] = max(last[1], current[1])  # Merge intervals

    return merged
```

---

## 4. Complexity Analysis

| Operation         | Time Complexity | Space Complexity |
| ----------------- | --------------- | ---------------- |
| Sorting intervals | O(n log n)      | O(1) or O(n)     |
| Merging           | O(n)            | O(n)             |

* **Overall:** O(n log n) due to sorting.
* **Auxiliary space:** O(n) for storing merged intervals.

---

## 5. Variations & Edge Cases

* **Empty input list** → return `[]`.
* **Single interval** → return interval itself.
* **Intervals already sorted** → skip sorting step for optimization.
* **Completely overlapping intervals** → merge into one.
* **Touching intervals** (e.g., `[1,2]` and `[2,3]`) → decide if inclusive merging is required.

---

## 6. Visual Aid

```text
Input Intervals:   [1,3], [2,6], [8,10], [15,18]

Step 1: Sort by start
    [1,3], [2,6], [8,10], [15,18]

Step 2: Merge overlapping
    Compare [1,3] and [2,6] → merge → [1,6]
    Compare [1,6] and [8,10] → no overlap → append [8,10]
    Compare [8,10] and [15,18] → no overlap → append [15,18]

Output: [1,6], [8,10], [15,18]
```

---

## 7. Interview Tips

* Always **sort intervals** first to simplify merging.
* Clarify if intervals **include end points**.
* Consider **edge cases**:

  * Empty list
  * One interval
  * Fully overlapping intervals
  * Touching intervals
* Use **lambda functions** or key functions for sorting in coding interviews.
* Be ready to extend to **2D intervals or intervals with additional data**.

---

## 8. Practice Problems

| Problem                   | Source                                                                   | Type                    |
| ------------------------- | ------------------------------------------------------------------------ | ----------------------- |
| Merge Intervals           | [LeetCode 56](https://leetcode.com/problems/merge-intervals/)            | Merge overlapping       |
| Insert Interval           | [LeetCode 57](https://leetcode.com/problems/insert-interval/)            | Merge with new interval |
| Non-overlapping Intervals | [LeetCode 435](https://leetcode.com/problems/non-overlapping-intervals/) | Count removals          |
| Meeting Rooms II          | [LeetCode 253](https://leetcode.com/problems/meeting-rooms-ii/)          | Interval overlap        |
| Employee Free Time        | [LeetCode 759](https://leetcode.com/problems/employee-free-time/)        | Find gaps               |

---

## 9. Key Takeaways

* Sort → Compare → Merge.
* Fast and efficient with **O(n log n)** time.
* Essential pattern for **scheduling and interval problems**.
* Basis for many **advanced interval-based algorithms**.

---

## References

* [LeetCode Patterns](https://leetcode.com/explore/learn/card/intervals/)
* [GeeksforGeeks - Merge Intervals](https://www.geeksforgeeks.org/merging-intervals/)
* [Competitive Programming Handbook - Interval Problems](https://cp-algorithms.com/)

