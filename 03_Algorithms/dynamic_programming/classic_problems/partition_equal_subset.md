# Partition Equal Subset Sum — Dynamic Programming

The **Partition Equal Subset Sum** problem is a **classic subset-sum variant** that demonstrates how to use **Dynamic Programming** for subset partitioning and knapsack-like problems.

---

## 1. Problem Definition

Given an array `nums[]` of positive integers, determine whether it can be partitioned into **two subsets** such that the **sum of elements in both subsets is equal**.

Formally, check if there exists a subset of `nums` whose sum equals **`total_sum / 2`**.

---

### Example

```
Input: nums = [1, 5, 11, 5]
Output: true
Explanation: [1, 5, 5] and [11] both sum to 11.
```

```
Input: nums = [1, 2, 3, 5]
Output: false
Explanation: Cannot partition into equal sum subsets.
```

---

## 2. Mathematical Intuition

Let total sum = `S = sum(nums)`

If `S` is odd → impossible to split equally.
If `S` is even → target = `S / 2`.

The problem then reduces to:

> “Does there exist a subset of `nums` with sum equal to `target`?”

This is a **Subset Sum Problem**, a foundational problem in **Dynamic Programming** and **Knapsack theory**.

---

## 3. Recursive Relation

Let `f(i, target)` denote whether a subset of the first `i` elements can sum to `target`.

### Recurrence:

```
f(i, target) = f(i-1, target) OR f(i-1, target - nums[i])
```

**Base Cases:**

```
f(0, 0) = True
f(0, target) = (nums[0] == target)
```

We either:

1. **Include** nums[i] → reduce target.
2. **Exclude** nums[i] → move to previous index.

---

## 4. Recursive Solution (Exponential)

```
function canPartition(nums):
    total = sum(nums)
    if total % 2 != 0:
        return False
    target = total / 2

    def subset(i, t):
        if t == 0:
            return True
        if i == 0:
            return nums[0] == t
        not_take = subset(i-1, t)
        take = False
        if nums[i] <= t:
            take = subset(i-1, t-nums[i])
        return take or not_take

    return subset(len(nums)-1, target)
```

**Time Complexity:** O(2ⁿ)
**Space Complexity:** O(n)

---

## 5. Memoization (Top-Down DP)

```
function canPartition(nums):
    total = sum(nums)
    if total % 2 != 0:
        return False
    target = total // 2
    n = len(nums)
    dp = [[-1]*(target+1) for _ in range(n)]

    def subset(i, t):
        if t == 0:
            return True
        if i == 0:
            return nums[0] == t
        if dp[i][t] != -1:
            return dp[i][t]
        not_take = subset(i-1, t)
        take = False
        if nums[i] <= t:
            take = subset(i-1, t-nums[i])
        dp[i][t] = take or not_take
        return dp[i][t]

    return subset(n-1, target)
```

**Time Complexity:** O(n × target)
**Space Complexity:** O(n × target)

---

## 6. Tabulation (Bottom-Up DP)

```
function canPartition(nums):
    total = sum(nums)
    if total % 2 != 0:
        return False
    target = total // 2
    n = len(nums)
    dp = [[False]*(target+1) for _ in range(n)]

    for i in range(n):
        dp[i][0] = True
    if nums[0] <= target:
        dp[0][nums[0]] = True

    for i in range(1, n):
        for t in range(1, target+1):
            not_take = dp[i-1][t]
            take = False
            if nums[i] <= t:
                take = dp[i-1][t-nums[i]]
            dp[i][t] = take or not_take

    return dp[n-1][target]
```

---

## 7. Space Optimization

Since `dp[i][t]` depends only on `i-1`, we can use a **1D DP array**.

```
function canPartition(nums):
    total = sum(nums)
    if total % 2 != 0:
        return False
    target = total // 2
    dp = [False]*(target+1)
    dp[0] = True

    for num in nums:
        for t in range(target, num-1, -1):
            dp[t] = dp[t] or dp[t-num]

    return dp[target]
```

**Time Complexity:** O(n × target)
**Space Complexity:** O(target)

---

## 8. Visual Example

### Input:

```
nums = [1, 5, 11, 5]
```

Total = 22 → target = 11

### DP Table (n x target)

| i | num | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |
| - | --- | - | - | - | - | - | - | - | - | - | - | -- | -- |
| 0 | 1   | T | T | F | F | F | F | F | F | F | F | F  | F  |
| 1 | 5   | T | T | F | F | F | T | T | F | F | F | F  | F  |
| 2 | 11  | T | T | F | F | F | T | T | F | F | F | F  | T  |
| 3 | 5   | T | T | F | F | F | T | T | F | F | F | F  | T  |

Result: `True`

---

## 9. Variations

| Variant                                   | Description                                           |
| ----------------------------------------- | ----------------------------------------------------- |
| **Subset Sum Problem**                    | Check if any subset sums to a given `target`.         |
| **Count Subsets with Given Sum**          | Count how many subsets sum to `target`.               |
| **Minimum Subset Sum Difference**         | Find smallest difference between sums of two subsets. |
| **Target Sum (LeetCode 494)**             | Assign +/− signs to make target sum.                  |
| **Equal Subset Partition with k Subsets** | Generalized version (NP-hard).                        |

---

## 10. Interview Tips

* **Key insight:** reduce to Subset Sum Problem with `target = total_sum / 2`.
* Always check for **odd total sum** early (fast reject).
* Know both **O(n × target)** and **O(target)** implementations.
* Related to **0/1 Knapsack**, so emphasize state and transition clearly.
* Common in **Amazon, Google, Microsoft, Adobe, Facebook**.

---

## 11. Practice Problems

| Platform | Problem                                                                                      | Type            |
| -------- | -------------------------------------------------------------------------------------------- | --------------- |
| LeetCode | [416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) | Classic         |
| GFG      | Partition Equal Subset Sum                                                                   | DP standard     |
| LeetCode | [494. Target Sum](https://leetcode.com/problems/target-sum/)                                 | Variation       |
| GFG      | Minimum Subset Sum Difference                                                                | Related Problem |

---

## 12. Summary

| Concept              | Description                                             |
| -------------------- | ------------------------------------------------------- |
| **State**            | dp[i][t] → whether subset of first i elements sums to t |
| **Transition**       | dp[i][t] = dp[i-1][t] OR dp[i-1][t-nums[i]]             |
| **Base Case**        | dp[0][0] = True                                         |
| **Time Complexity**  | O(n × target)                                           |
| **Space Complexity** | O(target) optimized                                     |
| **Type**             | 0/1 Knapsack-based Boolean DP                           |

---

**Key Takeaway:**
The **Partition Equal Subset Sum** problem illustrates how **subset-sum reasoning** combined with **space-optimized DP** can solve real-world problems of partitioning and balancing — a foundational pattern in **dynamic programming optimization problems**.

