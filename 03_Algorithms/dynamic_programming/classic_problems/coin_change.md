# Coin Change Problem — Dynamic Programming Approach

The **Coin Change** problem is one of the most fundamental problems in **Dynamic Programming (DP)**, illustrating concepts of **combinatorial counting**, **recursion + memoization**, and **state-space optimization**.

It comes in **two major variants**, each representing a different type of DP formulation.

---

## 1. Problem Variants

### **Variant 1: Coin Change (Count Ways)**

> Find the total number of ways to make a given amount using unlimited coins of given denominations.

Example:
Coins = [1, 2, 5], Amount = 5

Possible combinations:

* 1+1+1+1+1
* 1+1+1+2
* 1+2+2
* 5

Total ways = **4**

---

### **Variant 2: Coin Change (Minimum Coins)**

> Find the minimum number of coins needed to make the given amount.

Example:
Coins = [1, 2, 5], Amount = 11

* 5 + 5 + 1 → **3 coins**

---

## 2. Mathematical Intuition

The recursive structure is derived from **decision-making** at each coin:
either **include** it or **exclude** it.

### For Counting Ways (unbounded knapsack form)

Let `dp[i][j]` = number of ways to make sum `j` using first `i` coins.

Recurrence:

```
dp[i][j] = dp[i-1][j] + dp[i][j - coin[i-1]]
```

* `dp[i-1][j]`: Exclude current coin
* `dp[i][j - coin[i-1]]`: Include current coin (since unlimited use)

---

### For Minimum Coins

Let `dp[j]` = minimum coins needed for amount `j`.

Recurrence:

```
dp[j] = min(dp[j], dp[j - coin] + 1)
```

---

## 3. Pseudocode — Variant 1 (Count Ways)

```
function countWays(coins[], n, amount):
    dp = array of size (n+1) x (amount+1)

    for i from 0 to n:
        dp[i][0] = 1     # One way to make amount 0

    for i from 1 to n:
        for j from 1 to amount:
            if coins[i-1] <= j:
                dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]]
            else:
                dp[i][j] = dp[i-1][j]

    return dp[n][amount]
```

**Time Complexity:** O(n × amount)
**Space Complexity:** O(n × amount) (can be optimized to O(amount))

---

## 4. Pseudocode — Variant 2 (Minimum Coins)

```
function minCoins(coins[], amount):
    dp = array of size (amount+1), initialized with ∞
    dp[0] = 0

    for i from 1 to amount:
        for c in coins:
            if c <= i:
                dp[i] = min(dp[i], dp[i - c] + 1)

    if dp[amount] == ∞:
        return -1
    return dp[amount]
```

**Time Complexity:** O(n × amount)
**Space Complexity:** O(amount)

---

## 5. Visual Example (Count Ways)

Example: `coins = [1, 2, 5]`, `amount = 5`

| Amount ↓ / Coins → | 1 | 2 | 5 |
| ------------------ | - | - | - |
| 0                  | 1 | 1 | 1 |
| 1                  | 1 | 1 | 1 |
| 2                  | 1 | 2 | 2 |
| 3                  | 1 | 2 | 2 |
| 4                  | 1 | 3 | 3 |
| 5                  | 1 | 3 | 4 |

`dp[3][5] = 4`

---

## 6. Step-by-Step Reasoning (Recursive Intuition)

Let `f(n, S)` be the number of ways to make sum `S` with first `n` coins.
Then:

* If `coin[n-1] > S`, we skip it → `f(n, S) = f(n-1, S)`
* Otherwise → `f(n, S) = f(n-1, S) + f(n, S - coin[n-1])`

This recursion forms the base of our tabulation.

---

## 7. Edge Cases

* **No coins:** amount > 0 → return 0 (no way)
* **Amount = 0:** always 1 way (choose nothing)
* **Coins > amount:** still valid (skip those)
* **Impossible case:** handle by checking dp value after computation (∞ → -1)

---

## 8. Comparison Between Variants

| Feature      | Count Ways            | Min Coins            |
| ------------ | --------------------- | -------------------- |
| Problem Type | Counting combinations | Optimization         |
| Relation     | Add results           | Take minimum         |
| Base Case    | dp[0][0] = 1          | dp[0] = 0            |
| Result Type  | Integer count         | Integer min or -1    |
| Example      | “How many?”           | “What’s the fewest?” |

---

## 9. Optimizations

1. **1D DP Array:**
   Reuse same row (bottom-up approach).

2. **Space Optimization (Min Coins):**
   Single array `dp[j]` is enough, updated in forward order.

3. **Top-Down Memoization:**
   Reduces redundant recursion.

---

## 10. Interview Tips

* Clarify **variant type** first (“ways” vs “min coins”).
* Discuss **unbounded** nature — coins can be reused.
* Use **base cases** to justify DP initialization.
* Always mention **O(n × amount)** complexity.
* Practice converting recursive → tabulation.

Common companies testing this:

* Amazon, Google, Microsoft, Atlassian, Adobe

---

## 11. Practice Problems

| Platform   | Problem                                                              | Variant     |
| ---------- | -------------------------------------------------------------------- | ----------- |
| LeetCode   | [322. Coin Change](https://leetcode.com/problems/coin-change/)       | Min Coins   |
| LeetCode   | [518. Coin Change II](https://leetcode.com/problems/coin-change-ii/) | Count Ways  |
| GFG        | Coin Change Problem                                                  | Count Ways  |
| GFG        | Minimum number of coins                                              | Min Coins   |
| Codeforces | DP Coin combinations I, II                                           | Count & Min |

---

## 12. Summary Table

| Aspect     | Count Ways                                     | Min Coins                              |
| ---------- | ---------------------------------------------- | -------------------------------------- |
| Recurrence | `dp[i][j] = dp[i-1][j] + dp[i][j - coin[i-1]]` | `dp[j] = min(dp[j], dp[j - coin] + 1)` |
| Base       | `dp[0][0] = 1`                                 | `dp[0] = 0`                            |
| Complexity | O(n×amount)                                    | O(n×amount)                            |
| Nature     | Unbounded Knapsack                             | Unbounded Knapsack                     |
| Result     | Total ways                                     | Minimum coins or -1                    |

---

### Key Takeaway

The **Coin Change** problem is a cornerstone of Dynamic Programming that tests:

* clear distinction between *counting* and *optimization*,
* ability to build recurrence relations,
* and converting recursive thinking into iterative tabulation.

