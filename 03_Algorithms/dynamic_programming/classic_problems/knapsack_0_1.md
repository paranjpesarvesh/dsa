# 0/1 Knapsack Problem — Dynamic Programming

The **0/1 Knapsack problem** is one of the most important and foundational problems in **Dynamic Programming (DP)**.
It represents a class of **optimization problems** where we decide whether to include or exclude each item based on given constraints.

---

## 1. Problem Definition

You are given:

* `n` items, each with a **weight** `w[i]` and **value** `v[i]`
* A **knapsack (bag)** with **capacity** `W`

**Goal:**
Maximize the total value of selected items such that
the total weight ≤ `W`, and each item can be chosen **at most once** (0 or 1).

---

### Example

```
Input:
n = 3
weights = [10, 20, 30]
values =  [60, 100, 120]
W = 50

Output: 220
Explanation:
Take items 2 and 3 → total weight = 20+30 = 50, total value = 100+120 = 220
```

---

## 2. Intuition

At every item, we have **two choices**:

1. **Include it** (if it fits):
   Add its value and reduce the capacity by its weight.
2. **Exclude it**:
   Skip it and move to the next item.

We want to maximize the result between these two options.

---

## 3. Mathematical Recurrence

Let:

```
dp[i][W] = maximum value using first i items with capacity W
```

Then:

```
dp[i][W] = max(
    value[i-1] + dp[i-1][W - weight[i-1]],   // include
    dp[i-1][W]                               // exclude
)
```

**Condition:**
If `weight[i-1] > W`, we can’t include the item, so:

```
dp[i][W] = dp[i-1][W]
```

### Base Case:

```
dp[0][W] = 0  → No items → 0 value
dp[i][0] = 0  → 0 capacity → 0 value
```

---

## 4. Recursive Approach (Top-Down)

```
function knapsack(i, W):
    if i == 0 or W == 0:
        return 0
    if weight[i-1] <= W:
        include = value[i-1] + knapsack(i-1, W - weight[i-1])
        exclude = knapsack(i-1, W)
        return max(include, exclude)
    else:
        return knapsack(i-1, W)
```

**Time Complexity:** O(2ⁿ)
Exponential → due to exploring all subsets.

---

## 5. Memoization (Top-Down DP)

```
function knapsack(i, W, dp):
    if i == 0 or W == 0:
        return 0
    if dp[i][W] != -1:
        return dp[i][W]
    if weight[i-1] <= W:
        dp[i][W] = max(
            value[i-1] + knapsack(i-1, W - weight[i-1], dp),
            knapsack(i-1, W, dp)
        )
    else:
        dp[i][W] = knapsack(i-1, W, dp)
    return dp[i][W]
```

**Time Complexity:** O(n × W)
**Space Complexity:** O(n × W) (for dp + recursion stack)

---

## 6. Tabulation (Bottom-Up DP)

**Pseudocode:**

```
function knapsack(n, W, weight[], value[]):
    dp = 2D array of size (n+1) x (W+1)

    for i in range(0, n+1):
        for w in range(0, W+1):
            if i == 0 or w == 0:
                dp[i][w] = 0
            else if weight[i-1] <= w:
                dp[i][w] = max(
                    value[i-1] + dp[i-1][w - weight[i-1]],
                    dp[i-1][w]
                )
            else:
                dp[i][w] = dp[i-1][w]

    return dp[n][W]
```

**Time Complexity:** O(n × W)
**Space Complexity:** O(n × W)

---

## 7. Space Optimized DP

Each `dp[i][*]` depends only on the previous row (`dp[i-1][*]`).
We can reduce the space to a **1D array**.

**Pseudocode:**

```
function knapsack(W, weight[], value[], n):
    dp = array of size (W+1)

    for i in range(0, n):
        for w in range(W, weight[i]-1, -1):
            dp[w] = max(dp[w], value[i] + dp[w - weight[i]])

    return dp[W]
```

**Time Complexity:** O(n × W)
**Space Complexity:** O(W)

---

## 8. Example Walkthrough

### Input:

```
weights = [1, 3, 4, 5]
values  = [1, 4, 5, 7]
W = 7
```

| i | w | Choices             | dp[i][w] |
| - | - | ------------------- | -------- |
| 1 | 1 | include             | 1        |
| 2 | 3 | include             | 4        |
| 3 | 4 | include             | 5        |
| 4 | 7 | include items 2 + 4 | 11       |

Final Answer: **11**

---

## 9. Visual Representation

```
               Item(i)
              /       \
       Include         Exclude
   (reduce W)           (same W)
```

Recursive Tree Example (for n=3, W=4):

```
                (3,4)
               /     \
          (2,1)     (2,4)
          /   \     /   \
      (1,0) (1,1) (1,3) (1,4)
```

---

## 10. Variations of 0/1 Knapsack

| Variant                       | Description                                         |
| ----------------------------- | --------------------------------------------------- |
| **Subset Sum**                | Value == Weight; check if a subset sums to target   |
| **Count of Subsets**          | Count subsets with a given sum                      |
| **Equal Partition**           | Can array be partitioned into two equal-sum subsets |
| **Minimum Subset Difference** | Minimize abs(sum(S1) - sum(S2))                     |
| **Target Sum (LeetCode)**     | Convert signs to form target value                  |

---

## 11. Edge Cases

1. **All weights > W** → return 0
2. **Empty items list** → return 0
3. **Multiple items with same weight/value** → doesn’t affect logic
4. **Large W (up to 10⁵)** → use space-optimized DP

---

## 12. Interview Tips

* Always state recurrence clearly before coding.
* If asked for **space optimization**, explain 1D DP logic (reverse loop).
* Be ready to derive **Subset Sum** and **Target Sum** as special cases.
* Discuss **greedy vs DP** — greedy fails because items cannot be split.
* Asked in: **Amazon, Flipkart, Microsoft, Adobe, Google**

---

## 13. Practice Problems

| Platform   | Problem                                                                                      | Variant               |
| ---------- | -------------------------------------------------------------------------------------------- | --------------------- |
| LeetCode   | [416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) | Subset-based          |
| LeetCode   | [494. Target Sum](https://leetcode.com/problems/target-sum/)                                 | Sign conversion       |
| GFG        | 0/1 Knapsack Problem                                                                         | Classic               |
| Codeforces | Knapsack Problem                                                                             | Weighted Optimization |

---

## 14. Summary

| Concept          | Description                                              |
| ---------------- | -------------------------------------------------------- |
| Problem Type     | Optimization                                             |
| State            | `dp[i][W]` → max value with first i items, capacity W    |
| Transition       | `max(value[i-1] + dp[i-1][W - weight[i-1]], dp[i-1][W])` |
| Base Case        | `dp[0][W] = 0`, `dp[i][0] = 0`                           |
| Time Complexity  | O(n × W)                                                 |
| Space Complexity | O(W) optimized                                           |
| Key Idea         | Include vs Exclude                                       |

---

**Key Takeaway:**
The **0/1 Knapsack** is the foundation of DP — it teaches how to choose optimally between alternatives while respecting a constraint. Understanding it helps solve dozens of related subset and optimization problems efficiently.

