# Maximum Subarray Sum (Kadane’s Algorithm)

Location: `02_Data_Structures/arrays/problems/max_subarray_sum_kadane.md`

---

## Problem Description

Given an integer array `nums`, find the **maximum possible sum** of a **non-empty contiguous subarray**.

Example:

```
Input:  [-2,1,-3,4,-1,2,1,-5,4]
Output: 6

The subarray [4,-1,2,1] has the largest sum = 6
```

---

## Why This Problem Is Important

* One of the most frequently asked array DP questions
* Very efficient O(n) solution
* Demonstrates dynamic programming intuition:
  “extend or restart the current subarray?”

---

## Core Insight Behind Kadane’s Algorithm

At each position `i`, decide one of two choices:

1. Continue the previous subarray
   (`current_sum + nums[i]`)

2. Start a new subarray at index `i`
   (`nums[i]`)

We choose whichever gives the larger sum.

Mathematically:

```
current_sum = max(nums[i], current_sum + nums[i])
```

Then update global maximum:

```
max_sum = max(max_sum, current_sum)
```

---

## Step-by-Step Reasoning

Take array:

```
[-2, 1, -3, 4, -1, 2, 1, -5, 4]
```

Iterating:

```
i  nums[i]  current_sum  max_sum
--------------------------------
0   -2       -2          -2
1    1        1           1
2   -3       -2           1
3    4        4           4
4   -1        3           4
5    2        5           5
6    1        6           6
7   -5        1           6
8    4        5           6
```

Final result: **6**

---

## Pseudocode

```
function max_subarray(nums):
    current_sum = nums[0]
    max_sum = nums[0]

    for i from 1 to n-1:
        current_sum = max(nums[i], current_sum + nums[i])
        max_sum = max(max_sum, current_sum)

    return max_sum
```

---

## Time & Space Complexity

| Operation | Complexity |
| --------- | ---------- |
| Time      | O(n)       |
| Space     | O(1)       |

---

## Visual Aid

```
Decision at each index:
nums[i]   current_sum + nums[i]
   |                 |
   v                 v
Take the larger → new current_sum
```

---

## Variations and Extensions

1. **Return the actual subarray**
   Track start and end indices.

2. **Maximum subarray in circular array**
   Use Kadane twice (wrap + non-wrap case).

3. **Maximum product subarray**
   Different problem (requires tracking min/max products).

---

## Edge Cases

* All negative numbers (still pick the max negative)

  * Kadane handles correctly

Example: `[-5, -3, -1, -7] → -1`

* Array of size 1

* Very large sums (use 64-bit integer types)

---

## Interview Tips

* Explain DP intuition: local vs global maxima
* Emphasize O(n) time and O(1) space
* Mention edge case: all negatives
* If they ask for subarray indices: track start/end
* If asked circular version: mention “Kadane twice” trick

---

## Practice Problems

1. LeetCode 53 – Maximum Subarray
2. Maximum Circular Subarray – LeetCode 918
3. Maximum sum increasing subsequence (different type)
4. Maximum product subarray – LeetCode 152
5. Largest sum contiguous subarray (GFG classic)

---
