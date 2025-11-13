# Memoization vs Tabulation in Dynamic Programming

Dynamic Programming (DP) can be implemented in **two main ways** —
**Memoization (Top-Down)** and **Tabulation (Bottom-Up)**.

Both solve overlapping subproblems efficiently by storing results to avoid recomputation, but they differ in **approach, recursion usage, memory layout, and control flow**.

This document provides a deep yet practical comparison of both.

---

## 1. Core Idea

| Technique       | Approach  | Recursion                | Control Flow                            |
| --------------- | --------- | ------------------------ | --------------------------------------- |
| **Memoization** | Top-Down  | Uses recursion + caching | Recursive calls determine the flow      |
| **Tabulation**  | Bottom-Up | Iterative                | Follows predetermined order using loops |

---

### Example Problem: Fibonacci Number

#### Recursive Relation:

```
f(n) = f(n-1) + f(n-2)
Base: f(0) = 0, f(1) = 1
```

---

## 2. Memoization (Top-Down DP)

### Definition

Memoization stores the results of **recursive calls** in a table (usually an array or dictionary) so that the same subproblem is not computed more than once.

### Implementation

```
function fib(n, dp):
    if n <= 1:
        return n
    if dp[n] != -1:
        return dp[n]
    dp[n] = fib(n-1, dp) + fib(n-2, dp)
    return dp[n]
```

### Explanation

* Works recursively (Top → Down).
* Only computes subproblems that are actually required.
* Uses the **call stack** for recursion.

### Characteristics

| Aspect                 | Memoization                     |
| ---------------------- | ------------------------------- |
| Style                  | Recursive                       |
| Uses                   | Function stack + cache          |
| Space Usage            | DP array + recursion stack      |
| Ease of implementation | More intuitive for beginners    |
| Order of solving       | As required by recursion calls  |
| Example                | Fibonacci, Subset Sum, Knapsack |

---

## 3. Tabulation (Bottom-Up DP)

### Definition

Tabulation builds up a table iteratively by **solving all smaller subproblems first**, using their results to construct solutions for larger subproblems.

### Implementation

```
function fib(n):
    dp = [0]*(n+1)
    dp[0] = 0
    dp[1] = 1
    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]
```

### Explanation

* Iterative approach (Bottom → Up).
* Computes *all* subproblems in increasing order.
* No recursion (no stack overhead).

### Characteristics

| Aspect                 | Tabulation                               |
| ---------------------- | ---------------------------------------- |
| Style                  | Iterative                                |
| Uses                   | Iterative loops + table                  |
| Space Usage            | DP array only                            |
| Ease of implementation | Requires correct ordering of computation |
| Order of solving       | Always sequential                        |
| Example                | Fibonacci, LCS, Minimum Path Sum         |

---

## 4. Comparing Memoization vs Tabulation

| Feature                 | Memoization (Top-Down)            | Tabulation (Bottom-Up)             |
| ----------------------- | --------------------------------- | ---------------------------------- |
| **Approach**            | Recursive                         | Iterative                          |
| **Order of Execution**  | On-demand (as recursion expands)  | Fixed order (smallest → largest)   |
| **Storage**             | Partial (only needed subproblems) | Full (all subproblems)             |
| **Recursion Overhead**  | Yes                               | No                                 |
| **Base Case Handling**  | Natural in recursion              | Must be initialized manually       |
| **Stack Overflow Risk** | Possible (deep recursion)         | None                               |
| **Ease of Transition**  | Easier from recursive formula     | More systematic and efficient      |
| **Performance**         | Similar O(N)                      | Similar O(N)                       |
| **Space**               | O(N) (DP + Stack)                 | O(N) (DP only)                     |
| **Optimization Ready**  | Harder to reduce stack            | Easy to optimize space iteratively |

---

## 5. Space Optimization

For problems like Fibonacci, only the last two results are needed.
We can reduce O(N) → O(1) space:

```
function fib(n):
    prev2 = 0
    prev1 = 1
    for i in range(2, n+1):
        cur = prev1 + prev2
        prev2 = prev1
        prev1 = cur
    return prev1
```

**Time Complexity:** O(N)
**Space Complexity:** O(1)

---

## 6. Visual Comparison

### Memoization Flow (Top-Down)

```
f(5)
├── f(4)
│   ├── f(3)
│   │   ├── f(2)
│   │   │   ├── f(1)
│   │   │   └── f(0)
│   │   └── f(1)
│   └── f(2)
└── f(3) (reused)
```

Only computed subproblems appear as recursion unfolds.

---

### Tabulation Flow (Bottom-Up)

```
i = 0 → dp[0] = 0
i = 1 → dp[1] = 1
i = 2 → dp[2] = dp[1] + dp[0]
i = 3 → dp[3] = dp[2] + dp[1]
i = 4 → dp[4] = dp[3] + dp[2]
i = 5 → dp[5] = dp[4] + dp[3]
```

All subproblems solved systematically before final result.

---

## 7. When to Use Which?

| Use Case                                      | Recommended Technique | Reason                            |
| --------------------------------------------- | --------------------- | --------------------------------- |
| Recursive relation is easy to express         | Memoization           | More natural to code recursively  |
| Need to avoid recursion stack                 | Tabulation            | No function calls                 |
| Problem needs all subproblems (like counting) | Tabulation            | Simpler to compute all            |
| Only a few subproblems are required           | Memoization           | Avoids computing unnecessary ones |
| Need space optimization                       | Tabulation            | Easier to optimize iteratively    |

---

## 8. Real-World Analogy

| Concept         | Analogy                                                    |
| --------------- | ---------------------------------------------------------- |
| **Memoization** | Lazy evaluation — compute only when needed, cache results. |
| **Tabulation**  | Eager evaluation — precompute all results from base up.    |

---

## 9. Interview Tips

* **Start with memoization**: Easier to derive recurrence relations.
* Once recurrence is clear → **convert to tabulation** for space optimization.
* Always **write base cases first**.
* Be ready to explain both approaches and **transition** between them.
* Common questions in interviews:

  * Convert memoized code to tabulation.
  * Explain time and space differences.
  * Optimize tabulation space from O(N) to O(1).

---

## 10. Practice Problems

| Platform | Problem                                                                                  | Focus                                    |
| -------- | ---------------------------------------------------------------------------------------- | ---------------------------------------- |
| LeetCode | [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)                    | Transition from memoization → tabulation |
| LeetCode | [198. House Robber](https://leetcode.com/problems/house-robber/)                         | 1D DP, space optimization                |
| GFG      | Fibonacci using DP                                                                       | Basic                                    |
| GFG      | 0/1 Knapsack Problem                                                                     | Classic DP with both styles              |
| LeetCode | [746. Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/) | Space optimization                       |

---

## 11. Summary Table

| Feature               | Memoization                                       | Tabulation                 |
| --------------------- | ------------------------------------------------- | -------------------------- |
| **Approach**          | Top-Down                                          | Bottom-Up                  |
| **Implementation**    | Recursive                                         | Iterative                  |
| **Space (Auxiliary)** | DP + Stack                                        | DP only                    |
| **Best For**          | Recursive formula problems                        | Performance & optimization |
| **Conversion**        | Easy to derive tabulation from memoized recursion | Reverse harder             |
| **Optimization**      | Limited                                           | Easier                     |

---

### Key Takeaway

> Memoization is for **clarity**.
> Tabulation is for **control and optimization**.

They are **two sides of the same DP coin** —
choose **memoization** for intuition and **tabulation** for efficiency.

