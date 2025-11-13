# Egg Dropping Puzzle — Dynamic Programming Approach

The **Egg Dropping Problem** is a classic **Dynamic Programming** problem that explores optimal substructure and minimization under uncertainty.
It demonstrates the balance between **worst-case minimization** and **recursion optimization**.

---

## 1. Problem Definition

You are given:

* **`n` floors**
* **`k` eggs**

You need to find the **minimum number of attempts** required in the **worst case** to determine the **highest floor** from which an egg can be dropped without breaking.

---

### Example

```
Input: k = 2 eggs, n = 10 floors
Output: 4
```

Explanation:

* Drop from 4th floor:

  * If it breaks → test floors 1–3
  * If it survives → test floors 5–10 (next drop 7th, then 9th, then 10th)
    Total = 4 trials in the worst case.

---

## 2. Intuition

At each drop, there are **two outcomes**:

1. Egg **breaks** → we search **below**.
2. Egg **does not break** → we search **above**.

We need to minimize the **maximum number of trials** among these outcomes.

---

### Recursive Thought Process

Let:

```
dp[k][n] = minimum trials needed for k eggs and n floors
```

At any floor `x` (1 ≤ x ≤ n):

* If egg breaks → we have `dp[k-1][x-1]` trials left (below x)
* If egg doesn’t break → we have `dp[k][n-x]` trials left (above x)

Hence:

```
dp[k][n] = 1 + min( max(dp[k-1][x-1], dp[k][n-x]) ) for all x in [1, n]
```

We take the **minimum** among all floor choices `x` because we want the **best** (least worst-case) decision.

---

## 3. Base Cases

| Case           | Meaning                                          |
| -------------- | ------------------------------------------------ |
| `dp[1][n] = n` | With 1 egg → must check every floor sequentially |
| `dp[k][0] = 0` | 0 floors → 0 attempts                            |
| `dp[k][1] = 1` | 1 floor → 1 attempt                              |

---

## 4. Pseudocode (Bottom-Up DP)

```
function eggDrop(k, n):
    dp = 2D array of size (k+1) x (n+1)

    for i from 1 to k:
        dp[i][0] = 0
        dp[i][1] = 1

    for j from 1 to n:
        dp[1][j] = j

    for i from 2 to k:
        for j from 2 to n:
            dp[i][j] = ∞
            for x from 1 to j:
                cost = 1 + max(dp[i-1][x-1], dp[i][j-x])
                dp[i][j] = min(dp[i][j], cost)

    return dp[k][n]
```

---

## 5. Complexity Analysis

| Type  | Complexity |
| ----- | ---------- |
| Time  | O(k × n²)  |
| Space | O(k × n)   |

This is acceptable for small constraints (e.g., up to 100 floors).

---

## 6. Optimized Approach (Using Binary Search)

The inner loop (`x` from 1 to n) can be optimized using **binary search**, because
`dp[k-1][x-1]` increases and `dp[k][n-x]` decreases with `x`.

So we can find the point where both become nearly equal.

Optimized recurrence:

```
dp[k][n] = 1 + min_over_x ( max(dp[k-1][x-1], dp[k][n-x]) )
```

with binary search on `x`.

**Time Complexity:** O(k × n log n)

---

## 7. Mathematical Approach (Alternative DP)

Another elegant approach focuses on the **number of moves (attempts)** rather than floors:

Let `dp[k][m]` = maximum number of floors we can check with `k` eggs and `m` moves.

Then:

```
dp[k][m] = dp[k-1][m-1] + dp[k][m-1] + 1
```

Meaning:

* One move used now,
* If egg breaks → `dp[k-1][m-1]` floors below
* If not → `dp[k][m-1]` floors above

We keep increasing `m` until `dp[k][m] ≥ n`.

**Time Complexity:** O(k × log n)

---

## 8. Example Visualization

### Example: 2 Eggs, 10 Floors

| Move | Floors Covered | Cumulative |
| ---- | -------------- | ---------- |
| 1    | 1              | 1          |
| 2    | 2              | 3          |
| 3    | 3              | 6          |
| 4    | 4              | 10         |

→ `4 moves` sufficient for 10 floors.

---

## 9. Flow of Recurrence

```
          Drop from floor x
         /                \
  Egg breaks         Egg survives
   ↓                      ↓
 dp[k-1][x-1]         dp[k][n-x]

      dp[k][n] = 1 + min( max(break, survive) )
```

---

## 10. Edge Cases

1. **k = 1** → must test all floors sequentially.
2. **n = 0 or 1** → result = n.
3. **k >= n** → only log(n) moves (since extra eggs don't add more power beyond floors).

---

## 11. Interview Tips

* **State clearly**: “Minimize the worst-case attempts.”
* **Derive the recurrence** — this shows strong DP reasoning.
* **Mention both DP formulations** (floors-based and moves-based).
* **Explain optimization** using monotonicity or binary search.
* **Common follow-up:** “Can you find which floors to drop from?”

Asked by: **Amazon, Microsoft, Adobe, Google**

---

## 12. Practice Problems

| Platform   | Problem                                                              | Variant               |
| ---------- | -------------------------------------------------------------------- | --------------------- |
| LeetCode   | [887. Super Egg Drop](https://leetcode.com/problems/super-egg-drop/) | Optimized DP          |
| GFG        | Egg Dropping Puzzle                                                  | Standard DP           |
| Codeforces | Egg Testing                                                          | Combinatorial variant |

---

## 13. Summary

| Concept          | Description                                            |
| ---------------- | ------------------------------------------------------ |
| State            | `dp[k][n]` = min drops with k eggs and n floors        |
| Recurrence       | `1 + min_x(max(dp[k-1][x-1], dp[k][n-x]))`             |
| Base Case        | `dp[1][n] = n`, `dp[k][0] = 0`, `dp[k][1] = 1`         |
| Time Complexity  | O(k × n²) → O(k × n log n) optimized                   |
| Alternative Form | `dp[k][m] = dp[k-1][m-1] + dp[k][m-1] + 1`             |
| Used For         | Minimizing worst-case attempts in uncertain conditions |

---

**Key Takeaway:**
The Egg Dropping problem embodies the essence of **Dynamic Programming trade-offs** — balancing between exploration (trying floors) and conservation (saving eggs) to minimize worst-case attempts.

