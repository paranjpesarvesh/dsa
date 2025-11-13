# Longest Increasing Subsequence (LIS) — Dynamic Programming

The **Longest Increasing Subsequence (LIS)** problem is a **classic dynamic programming problem** that tests your ability to identify and optimize over **ordered subsequences**.
It serves as a foundation for many problems involving sequence comparisons, sorting, and optimization.

---

## 1. Problem Definition

Given an array `arr[]` of length `n`, find the **length** of the **Longest Increasing Subsequence** (LIS) —
a subsequence where elements are **strictly increasing** and **not necessarily contiguous**.

---

### Example

```
Input: arr = [10, 9, 2, 5, 3, 7, 101, 18]
Output: 4
Explanation: The LIS is [2, 3, 7, 101]
```

---

## 2. Intuition

At every index `i`, we can:

1. **Include** the current element `arr[i]` if it is greater than a previously included element.
2. **Exclude** it and move on.

We maximize the subsequence length based on this choice, leading to overlapping subproblems → **Dynamic Programming**.

---

## 3. Recursive Formulation

Let `LIS(i)` denote the length of LIS **ending at index `i`**.

Then,

```
LIS(i) = 1 + max( LIS(j) ) for all j < i where arr[j] < arr[i]
```

If no such `j` exists → `LIS(i) = 1` (itself only).

Overall LIS = `max(LIS(i))` for all i.

---

## 4. Recursive Implementation (Top-Down)

```
function lis(i, arr):
    if i == 0:
        return 1
    best = 1
    for j in range(0, i):
        if arr[j] < arr[i]:
            best = max(best, 1 + lis(j, arr))
    return best
```

**Time Complexity:** O(2ⁿ) → exponential
**Space Complexity:** O(n) (recursion stack)

---

## 5. Memoization (Top-Down DP)

We cache results for each index to avoid recomputation.

```
function lis(i, arr, dp):
    if dp[i] != -1:
        return dp[i]
    dp[i] = 1
    for j in range(0, i):
        if arr[j] < arr[i]:
            dp[i] = max(dp[i], 1 + lis(j, arr, dp))
    return dp[i]
```

Result = `max(dp[i])` for all i.

**Time Complexity:** O(n²)
**Space Complexity:** O(n)

---

## 6. Tabulation (Bottom-Up DP)

**Pseudocode:**

```
function LIS(arr):
    n = len(arr)
    dp = [1] * n
    for i in range(1, n):
        for j in range(0, i):
            if arr[j] < arr[i]:
                dp[i] = max(dp[i], dp[j] + 1)
    return max(dp)
```

**Time Complexity:** O(n²)
**Space Complexity:** O(n)

---

### Step-by-Step Example

Input: `[10, 9, 2, 5, 3, 7, 101, 18]`

| i | arr[i] | dp[i] | Reason              |
| - | ------ | ----- | ------------------- |
| 0 | 10     | 1     | Start with 1        |
| 1 | 9      | 1     | No smaller previous |
| 2 | 2      | 1     | No smaller previous |
| 3 | 5      | 2     | 2 < 5               |
| 4 | 3      | 2     | 2 < 3               |
| 5 | 7      | 3     | 2 < 5 < 7           |
| 6 | 101    | 4     | 2 < 5 < 7 < 101     |
| 7 | 18     | 4     | 2 < 5 < 7 < 18      |

Answer: **4**

---

## 7. Space Optimization using Binary Search (O(n log n))

We can compute LIS length efficiently using a **sorted tail array** and **binary search**.

**Algorithm (Patience Sorting Intuition):**

1. Maintain an array `tails[]`, where `tails[i]` = smallest possible tail of an LIS of length `i+1`.
2. For each `num` in `arr`:

   * Use binary search to find its position `pos` in `tails`.
   * Replace `tails[pos] = num`.
3. The final size of `tails` = LIS length.

**Pseudocode:**

```
function LIS(arr):
    tails = []
    for num in arr:
        pos = lower_bound(tails, num)
        if pos == len(tails):
            tails.append(num)
        else:
            tails[pos] = num
    return len(tails)
```

**Time Complexity:** O(n log n)
**Space Complexity:** O(n)

---

### Visualization (Patience Sorting Analogy)

```
Input: [10, 9, 2, 5, 3, 7, 101, 18]

tails progression:
[10]
[9]
[2]
[2, 5]
[2, 3]
[2, 3, 7]
[2, 3, 7, 101]
[2, 3, 7, 18]

Final LIS length = 4
```

---

## 8. Printing the LIS (Reconstruction)

To print the actual LIS, track **predecessor indices**.

```
dp = [1]*n
prev = [-1]*n
lastIndex = 0

for i in range(1, n):
    for j in range(0, i):
        if arr[j] < arr[i] and dp[j]+1 > dp[i]:
            dp[i] = dp[j] + 1
            prev[i] = j
            if dp[i] > dp[lastIndex]:
                lastIndex = i

# reconstruct sequence
lis_seq = []
while lastIndex != -1:
    lis_seq.append(arr[lastIndex])
    lastIndex = prev[lastIndex]
lis_seq.reverse()
```

---

## 9. Variations of LIS

| Variant                                | Description                                   |
| -------------------------------------- | --------------------------------------------- |
| **Longest Decreasing Subsequence**     | Reverse comparison (`arr[j] > arr[i]`)        |
| **Bitonic Subsequence**                | Combine LIS (increasing) + LDS (decreasing)   |
| **Minimum Deletions to Sort**          | `n - LIS(arr)`                                |
| **Box Stacking / Envelopes**           | 2D LIS (sort + apply LIS on second dimension) |
| **Maximum Sum Increasing Subsequence** | Replace count with sum aggregation            |

---

## 10. Interview Tips

* **Naive vs O(n log n)**: Be able to explain both.
* Emphasize **state definition** — `dp[i]` = LIS ending at `i`.
* Discuss **real-world analogy**: patience sorting.
* Asked in: **Amazon, Google, Adobe, Microsoft, Uber**.
* Trick question: “Can you print LIS sequence?” → requires predecessor tracking.

---

## 11. Practice Problems

| Platform | Problem                                                                                              | Type         |
| -------- | ---------------------------------------------------------------------------------------------------- | ------------ |
| LeetCode | [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | Core LIS     |
| LeetCode | [673. Number of LIS](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)        | Count LIS    |
| GFG      | Maximum Sum Increasing Subsequence                                                                   | Weighted LIS |
| LeetCode | [354. Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/)                 | 2D LIS       |

---

## 12. Summary

| Approach      | Time       | Space | Notes                   |
| ------------- | ---------- | ----- | ----------------------- |
| Recursive     | O(2ⁿ)      | O(n)  | Exponential             |
| Memoization   | O(n²)      | O(n)  | Avoids recomputation    |
| Tabulation    | O(n²)      | O(n)  | Common interview method |
| Binary Search | O(n log n) | O(n)  | Optimal                 |

---

**Key Takeaway:**
The **Longest Increasing Subsequence** problem exemplifies how brute-force recursion evolves into elegant **O(n log n)** DP solutions.
Mastering it builds intuition for sequence-based optimization problems in dynamic programming and competitive programming.

