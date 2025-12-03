# Two Pointers Pattern

The **Two Pointers** technique is a widely used **array/string problem-solving pattern**. It allows you to traverse a data structure efficiently using **two indices moving in tandem**.

---

## 1. Definition

**Two pointers** is a technique where we use **two indices (pointers)** to traverse the array/string to solve problems related to:

- Pairs or triplets satisfying certain conditions.
- Subarrays or substrings with constraints.
- Partitioning or rearranging elements.

**Typical movement:**

- **Left pointer (i):** Starts at the beginning.
- **Right pointer (j):** Starts at the end or next to `i`.
- Move pointers based on a condition to reduce time complexity.

---

## 2. When to Use

Use **Two Pointers** when:

- You need to **find pairs or triplets** that satisfy a condition.
- The array or string is **sorted** (most common scenario).
- You want **O(n)** or **O(n log n)** solutions instead of brute-force O(n²).

**Common problems:**

- Two sum in a sorted array.
- Remove duplicates from sorted array.
- Container with most water.
- Partitioning problems (Dutch national flag).

---

## 3. Types of Two Pointers

### 3.1 Opposite-direction Pointers

- Start **one pointer at the beginning** and **one at the end**.
- Move inward based on condition.

**Example:** Find two numbers whose sum = target in a sorted array.

```

Array: \[1,2,3,4,6], target = 6
Pointers:
i=0, j=4 → 1+6=7 → j--
i=0, j=3 → 1+4=5 → i++
i=1, j=3 → 2+4=6 → found

```

### 3.2 Same-direction Pointers / Sliding Window

- Both pointers move **forward**, often used for substrings/subarrays.
- Essentially a **dynamic sliding window**.

**Example:** Longest substring without repeating characters.

---

## 4. Mathematical Intuition

- **Sorted array:** Using two pointers eliminates the need for nested loops.
- For **subarray/subsequence problems**, two pointers allow **incremental updates** (like sliding window).

**Time complexity improvement:**

- Brute-force: O(n²)
- Two pointers: O(n)

---

## 5. Template Approach

### Opposite-direction pointers (sorted array)

```python
def two_sum_sorted(arr, target):
    left, right = 0, len(arr)-1
    while left < right:
        curr_sum = arr[left] + arr[right]
        if curr_sum == target:
            return (left, right)
        elif curr_sum < target:
            left += 1
        else:
            right -= 1
    return None
```

### Same-direction pointers (variable-length window)

```python
def longest_unique_substring(s):
    seen = set()
    left = 0
    max_len = 0
    for right in range(len(s)):
        while s[right] in seen:
            seen.remove(s[left])
            left += 1
        seen.add(s[right])
        max_len = max(max_len, right - left + 1)
    return max_len
```

---

## 6. Complexity Analysis

| Type                     | Time Complexity | Space Complexity |
| ------------------------ | --------------- | ---------------- |
| Opposite-direction       | O(n)            | O(1)             |
| Same-direction / sliding | O(n)            | O(n) (hash set)  |

* **Each element is visited at most twice.**

---

## 7. Variations & Edge Cases

* **Duplicates:** Ensure correct pointer movement.
* **Empty arrays/strings:** Handle properly.
* **Circular arrays:** Special handling may be required.
* **Negative numbers:** For sum problems, ensure conditions are correctly applied.

---

## 8. Visual Aid

**Opposite-direction pointers:**

```text
Array: [1,2,3,4,6], target = 6
Index: 0 1 2 3 4

Step 1: i=0, j=4 → sum=7 → j--
Step 2: i=0, j=3 → sum=5 → i++
Step 3: i=1, j=3 → sum=6 → found
```

**Same-direction pointers (sliding window):**

```text
String: "abcabcbb"
i=0, j=0 → 'a' add
i=0, j=1 → 'b' add
i=0, j=2 → 'c' add
i=0, j=3 → 'a' repeat → remove s[i], i++
...
```

---

## 9. Interview Tips

* Identify if the **array/string is sorted**.
* Determine **pointer movement logic** based on problem constraints.
* For sliding window type problems, maintain **hashmap/set for counts**.
* Clarify edge cases and constraints before coding.

---

## 10. Practice Problems

| Problem                                        | Source                                                                                      | Type               |
| ---------------------------------------------- | ------------------------------------------------------------------------------------------- | ------------------ |
| Two sum (sorted)                               | [LeetCode 167](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)             | Opposite-direction |
| Container with most water                      | [LeetCode 11](https://leetcode.com/problems/container-with-most-water/)                     | Opposite-direction |
| Longest substring without repeating characters | [LeetCode 3](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | Sliding window     |
| Remove duplicates from sorted array            | [LeetCode 26](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)           | In-place           |

---

## References

* [LeetCode Patterns](https://leetcode.com/explore/learn/card/array-and-string/)
* [GeeksforGeeks Two Pointers](https://www.geeksforgeeks.org/two-pointers-technique/)

