# Sliding Window Pattern

The **Sliding Window** is one of the most widely used problem-solving patterns in arrays and strings. It allows us to efficiently solve problems involving **subarrays or substrings** by avoiding redundant calculations.

---

## 1. Definition

A **sliding window** is a **contiguous range of elements** in a data structure (usually an array or string) that moves (slides) over the data structure. It is used to compute results on a subset of elements efficiently.

- **Window size can be fixed or dynamic.**
- **Objective:** Reduce time complexity from brute-force `O(n*k)` to `O(n)` in many cases.

---

## 2. When to Use

Sliding window is useful when:

- You need **subarray/subsequence sums, averages, or products**.
- You need **longest/shortest substring** or **subarray** satisfying a condition.
- You can update results by **adding/removing one element at a time** instead of recomputing.

**Typical problems:**

- Maximum sum of subarray of size `k`.
- Longest substring with `k` distinct characters.
- Minimum size subarray with sum ≥ `target`.
- Count of anagrams or permutations in a string.

---

## 3. Types of Sliding Window

### 3.1 Fixed-size Window

- Window size `k` is known.
- Slide the window one element at a time.

**Example:** Maximum sum of subarray of size `k`.

```text
Array: [2, 1, 5, 1, 3, 2], k = 3
Window sums:
[2,1,5] = 8
[1,5,1] = 7
[5,1,3] = 9
[1,3,2] = 6
```

### 3.2 Dynamic-size Window

* Window size is **variable** depending on conditions.
* Expand window when condition not met, shrink when condition satisfied.

**Example:** Minimum length subarray with sum ≥ target.

---

## 4. Mathematical Intuition

* **Brute-force:** Check every subarray → O(n²)
* **Sliding Window:** Maintain sum/product/count incrementally:

  * Add new element to the window
  * Remove element leaving the window
* **Result:** O(n) instead of O(n²)

---

## 5. Template Approach

### Fixed-size window

```python
def fixed_size_window(arr, k):
    window_sum = sum(arr[:k])
    result = window_sum
    for i in range(k, len(arr)):
        window_sum += arr[i] - arr[i-k]  # slide window
        result = max(result, window_sum)  # or other operation
    return result
```

### Variable-size window

```python
def variable_size_window(arr, target):
    start = 0
    curr_sum = 0
    min_len = float('inf')

    for end in range(len(arr)):
        curr_sum += arr[end]

        while curr_sum >= target:
            min_len = min(min_len, end-start+1)
            curr_sum -= arr[start]
            start += 1

    return 0 if min_len == float('inf') else min_len
```

---

## 6. Complexity Analysis

| Type          | Time Complexity | Space Complexity |
| ------------- | --------------- | ---------------- |
| Fixed-size    | O(n)            | O(1)             |
| Variable-size | O(n)            | O(1)             |

* Each element is **added and removed at most once**.

---

## 7. Variations & Edge Cases

* **Empty array or string:** Handle edge cases.
* **All negative numbers:** Sliding window may need adjustment.
* **Strings:** Use a hashmap to track frequency for dynamic windows.
* **Circular arrays:** May need to simulate wrap-around.

---

## 8. Visual Aid

**Fixed-size window movement:**

```text
Array: [2,1,5,1,3,2], k = 3
Index: 0 1 2 3 4 5

Window 1: [2 1 5]
Window 2:   [1 5 1]
Window 3:     [5 1 3]
Window 4:       [1 3 2]
```

**Variable-size window:**

```text
Target sum = 7
Array: [2,1,5,2,8]
Start=0, End=0, sum=2 -> expand
End=1, sum=3 -> expand
End=2, sum=8 -> shrink from start -> sum=6, start=1
End=3, sum=8 -> shrink -> sum=7, start=2
...
```

---

## 9. Interview Tips

* Ask clarifying questions: fixed-size vs dynamic-size.
* Identify if the problem can be solved with **incremental updates**.
* Track **window start/end indexes** clearly.
* Use **hashmaps for counting problems in strings**.

---

## 10. Practice Problems

| Problem                                 | Source                                                                                              | Type          |
| --------------------------------------- | --------------------------------------------------------------------------------------------------- | ------------- |
| Maximum sum subarray of size k          | [LeetCode 209](https://leetcode.com/problems/minimum-size-subarray-sum/)                            | Fixed-size    |
| Minimum size subarray sum ≥ target      | [LeetCode 209](https://leetcode.com/problems/minimum-size-subarray-sum/)                            | Variable-size |
| Longest substring with K distinct chars | [LeetCode 340](https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/) | Variable-size |
| Count of anagrams in a string           | [GFG](https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1)               | Variable-size |

---

## References

* [LeetCode Patterns](https://leetcode.com/explore/learn/card/array-and-string/)
* [GFG Sliding Window](https://www.geeksforgeeks.org/window-sliding-technique/)

