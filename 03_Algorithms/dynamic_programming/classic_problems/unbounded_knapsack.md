# Unbounded Knapsack — Dynamic Programming

The **Unbounded Knapsack Problem** is a fundamental **Dynamic Programming** problem that extends the classic **0/1 Knapsack**, allowing **unlimited occurrences** of each item.

This problem models real-world optimization cases like coin change, rod cutting, and resource utilization where you can **reuse items multiple times**.

---

## 1. Problem Definition

Given `n` items, each with:

* `wt[i]` = weight of the ith item
* `val[i]` = value of the ith item

and a knapsack capacity `W`,
find the **maximum total value** that can be achieved such that you can take **any number of instances** of each item.

---

### Example

```
Input:
wt = [2, 3, 4, 5]
val = [5, 4, 8, 6]
W = 5

Output: 10

Explanation:
We can take two items of weight 2 (2 + 2 ≤ 5)
→ total value = 5 + 5 = 10
```

---

## 2. Key Difference — 0/1 vs Unbounded Knapsack

| Feature     | 0/1 Knapsack                                                               | Unbounded Knapsack                                                       |
| ----------- | -------------------------------------------------------------------------- | ------------------------------------------------------------------------ |
| Item Reuse  | Only once                                                                  | Unlimited                                                                |
| Transition  | `dp[i][w] = max(take, not_take)` with `take = val[i] + dp[i-1][w - wt[i]]` | `dp[i][w] = max(take, not_take)` with `take = val[i] + dp[i][w - wt[i]]` |
| Application | Resource allocation with constraints                                       | Resource reuse (coins, rods, recipes)                                    |

The only change is **reusing the same item** (`dp[i]` instead of `dp[i-1]` in recursion).

---

## 3. Recursive Formulation

Define a recursive function `f(i, W)` = maximum value using items `[0...i]` with capacity `W`.

```
f(i, W) = max(
    val[i] + f(i, W - wt[i]),  # Take the item again (unbounded)
    f(i-1, W)                  # Skip the item
)
```

**Base case:**

```
if i == 0:
    return (W // wt[0]) * val[0]  # multiple occurrences of first item
```

---

## 4. Recursive Solution (Exponential)

```
function unboundedKnapsack(i, W, wt, val):
    if i == 0:
        return (W // wt[0]) * val[0]

    not_take = unboundedKnapsack(i-1, W, wt, val)
    take = -inf
    if wt[i] <= W:
        take = val[i] + unboundedKnapsack(i, W - wt[i], wt, val)

    return max(take, not_take)
```

**Time Complexity:** O(2ⁿ)
**Space Complexity:** O(W)

---

## 5. Memoization (Top-Down DP)

```
function unboundedKnapsack(i, W, wt, val, dp):
    if i == 0:
        return (W // wt[0]) * val[0]
    if dp[i][W] != -1:
        return dp[i][W]

    not_take = unboundedKnapsack(i-1, W, wt, val, dp)
    take = -inf
    if wt[i] <= W:
        take = val[i] + unboundedKnapsack(i, W - wt[i], wt, val, dp)

    dp[i][W] = max(take, not_take)
    return dp[i][W]
```

**Time Complexity:** O(n × W)
**Space Complexity:** O(n × W)

---

## 6. Tabulation (Bottom-Up DP)

```
function unboundedKnapsack(n, W, wt, val):
    dp = [[0]*(W+1) for _ in range(n)]

    for w in range(W+1):
        dp[0][w] = (w // wt[0]) * val[0]

    for i in range(1, n):
        for w in range(0, W+1):
            not_take = dp[i-1][w]
            take = -inf
            if wt[i] <= w:
                take = val[i] + dp[i][w - wt[i]]
            dp[i][w] = max(take, not_take)

    return dp[n-1][W]
```

---

## 7. Space Optimization

We only need one 1D array since each state depends on `dp[i]` (current row) and not `dp[i-1]`.

```
function unboundedKnapsack(n, W, wt, val):
    dp = [0]*(W+1)
    for i in range(n):
        for w in range(wt[i], W+1):
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]])
    return dp[W]
```

**Time Complexity:** O(n × W)
**Space Complexity:** O(W)

---

## 8. Visual Example

**Input:**
`wt = [2, 3, 4, 5]`, `val = [5, 4, 8, 6]`, `W = 5`

**DP Table (n=4, W=5):**

| i (Item) | w=0 | 1 | 2 | 3 | 4  | 5  |
| -------- | --- | - | - | - | -- | -- |
| 0        | 0   | 0 | 5 | 5 | 10 | 10 |
| 1        | 0   | 0 | 5 | 5 | 9  | 9  |
| 2        | 0   | 0 | 5 | 5 | 9  | 10 |
| 3        | 0   | 0 | 5 | 5 | 9  | 10 |

Answer: **10**

---

## 9. Applications and Real-World Analogies

| Application                  | Description                                  |
| ---------------------------- | -------------------------------------------- |
| **Coin Change (Count Ways)** | Unbounded number of coins to make target sum |
| **Rod Cutting**              | Cut rod into smaller pieces for max profit   |
| **Ribbon Cutting**           | Similar to rod cutting with custom lengths   |
| **Word Formation Problems**  | Build strings using reusable fragments       |

---

## 10. Variations

| Variant                     | Description                              |
| --------------------------- | ---------------------------------------- |
| **0/1 Knapsack**            | Each item can be taken once              |
| **Fractional Knapsack**     | Items can be broken (Greedy)             |
| **Bounded Knapsack**        | Each item has limited copies             |
| **Coin Change (Min Coins)** | Minimize number of coins to reach target |
| **Rod Cutting Problem**     | Same DP structure with profit array      |

---

## 11. Interview Tips

* Emphasize difference between **0/1 and Unbounded** (use `dp[i]` instead of `dp[i-1]`).
* Common in **Amazon, Microsoft, Adobe, Flipkart**.
* Many problems are disguised forms:

  * Coin Change
  * Rod Cutting
  * Integer Break
* Explain space optimization clearly (from 2D → 1D).

---

## 12. Practice Problems

| Platform | Problem                                                              | Type               |
| -------- | -------------------------------------------------------------------- | ------------------ |
| GFG      | Unbounded Knapsack                                                   | Core Problem       |
| LeetCode | [322. Coin Change](https://leetcode.com/problems/coin-change/)       | Min Coins Variant  |
| LeetCode | [518. Coin Change II](https://leetcode.com/problems/coin-change-ii/) | Count Ways         |
| GFG      | Rod Cutting Problem                                                  | Equivalent Variant |
| GFG      | Maximum Ribbon Cut                                                   | Same pattern       |

---

## 13. Summary

| Concept              | Description                                             |
| -------------------- | ------------------------------------------------------- |
| **State**            | dp[i][W] → max value using items [0..i] and weight W    |
| **Transition**       | `dp[i][W] = max(dp[i-1][W], val[i] + dp[i][W - wt[i]])` |
| **Base Case**        | dp[0][W] = (W // wt[0]) * val[0]                        |
| **Time Complexity**  | O(n × W)                                                |
| **Space Complexity** | O(W) optimized                                          |

---

**Key Takeaway:**
The **Unbounded Knapsack** builds a foundation for a family of dynamic programming problems (coin change, rod cutting, integer break).
The insight that **you can reuse the same item** within the same iteration leads to a large class of efficient space-optimized solutions in DP.

