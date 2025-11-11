# DP Pattern: 0/1 Knapsack

The **0/1 Knapsack** pattern is one of the most important foundational patterns in Dynamic Programming. It teaches how to make optimal decisions when each item can be:

* included
* excluded

but not partially included.

This pattern generalizes into many classic interview problems including:

* subset sum
* equal partition
* count subsets
* target sum
* bounded knapsack
* unbounded knapsack (variation)
* scheduling with constraints
* resource allocation problems

---

# 1. Problem Definition

Given:

* A set of `n` items
* Each item has a `weight[i]` and `value[i]`
* A knapsack capacity `W`

Goal:

**Maximize total value without exceeding capacity.**

You can either:

* take item `i`
* skip item `i`

Binary decision → hence the name **0/1**.

---

# 2. Mathematical Recurrence

Let `dp[i][w]` = max value using items up to index `i` with capacity `w`.

Transition:

```
if weight[i] > w:
    dp[i][w] = dp[i-1][w]
else:
    dp[i][w] = max(dp[i-1][w], value[i] + dp[i-1][w - weight[i]])
```

Key idea:

* Case 1: Skip item `i`
* Case 2: Include item `i`

---

# 3. Visualization (DP Table)

```
         capacity →
        0  1  2  3  4  5  6
items ↓
0      0  0  4  4  4  4  4
1      0  0  4  4  5  5  9
2      0  0  4  4  5  6  9
```

Each entry means:

* Best value possible using items up to that row
* Within given capacity

---

# 4. Bottom-Up DP Algorithm

Pseudocode:

```
dp = 2D array (n+1) x (W+1)

for i in 0..n:
    dp[i][0] = 0

for i in 1..n:
    for w in 1..W:
        if weight[i-1] > w:
            dp[i][w] = dp[i-1][w]
        else:
            dp[i][w] = max(
                dp[i-1][w],
                value[i-1] + dp[i-1][w - weight[i-1]]
            )

return dp[n][W]
```

---

# 5. Space-Optimized Version (1D DP)

Since `dp[i][w]` only depends on the previous row `dp[i-1][...]`, we can compress space:

```
dp = array of size W+1

for i in 0..n-1:
    for w from W down to weight[i]:
        dp[w] = max(dp[w], value[i] + dp[w-weight[i]])

return dp[W]
```

Iterate backward in capacity to avoid overwriting necessary previous-state values.

---

# 6. Complexity Analysis

### Time Complexity

```
O(nW)
```

### Space Complexity

* Bottom-up DP: `O(nW)`
* Optimized DP: `O(W)`

W is capacity; n is number of items.

---

# 7. Edge Cases

* weights contain zeros
* capacity is zero → result is zero
* values contain zeros
* identical items
* extremely high W → might require greedy approximations (not for interviews)
* negative weights/values not allowed

---

# 8. Interview Tips

* Emphasize binary choice: include or exclude
* Explain DP table and recurrence clearly
* Mention space optimization
* Show understanding of subset-sum pattern
* Discuss which problems reduce to knapsack
* Mention that greedy does not work for 0/1 knapsack
* Clarify difference between 0/1 and unbounded knapsack

Common follow-up:

* Reconstruct selected items
* Count number of ways
* Print maximum value and selected items
* Solve subset sum using the same DP logic

---

# 9. Variations of 0/1 Knapsack

1. Subset Sum
2. Equal Partition
3. Count subsets
4. Target Sum (LeetCode 494)
5. Min difference subset partition
6. Knapsack with constraints (deadline, grouping)
7. Multi-dimensional knapsack (DP with more states)

---

# 10. Practice Problems

### LeetCode

* 416 Partition Equal Subset Sum
* 494 Target Sum
* 474 Ones and Zeroes
* 879 Profitable Schemes

### GFG

* 0/1 Knapsack
* Subset Sum
* Count Subsets

### Codeforces

* DP with item constraints
* Bounded knapsack problems

---

# Summary

The **0/1 Knapsack** pattern is the backbone of many classical DP problems. Once you understand:

* include / exclude choice
* DP table recurrence
* capacity-based transitions
