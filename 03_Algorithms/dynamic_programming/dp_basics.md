# Dynamic Programming (DP) — Foundations and Core Concepts

Dynamic Programming (DP) is one of the most powerful algorithmic techniques for solving **optimization**, **counting**, and **decision problems** efficiently. It’s built upon two key ideas: **Overlapping Subproblems** and **Optimal Substructure**.

This document serves as a **complete foundation guide** to Dynamic Programming, explaining concepts, recurrence formulation, and practical implementation approaches.

---

## 1. What is Dynamic Programming?

**Dynamic Programming (DP)** is a technique to solve problems by **breaking them down into smaller overlapping subproblems**, solving each subproblem once, and **storing their results** to avoid redundant computation.

It’s typically used when:

1. The problem can be broken into subproblems (recursive structure).
2. The subproblems overlap (repeated computation of same subproblems).
3. The optimal solution can be built using results of smaller subproblems (optimal substructure).

---

### Example – Fibonacci Numbers

**Naive Recursive Solution:**

```
fib(n) = fib(n-1) + fib(n-2)
```

This recomputes many subproblems (e.g., fib(3) is computed multiple times).

**DP Solution:**
Store results in an array and reuse them.

---

## 2. Core Properties of a DP Problem

| Property                    | Description                                                                                     |
| --------------------------- | ----------------------------------------------------------------------------------------------- |
| **Optimal Substructure**    | The optimal solution of a problem can be constructed from optimal solutions of its subproblems. |
| **Overlapping Subproblems** | The same subproblems are solved multiple times during recursion.                                |
| **State Representation**    | The solution can be represented by parameters that define the subproblem uniquely.              |
| **Recurrence Relation**     | The relationship between the subproblem and its smaller subproblems.                            |

---

## 3. DP vs Other Paradigms

| Paradigm             | Key Idea                                     | Example          |
| -------------------- | -------------------------------------------- | ---------------- |
| **Divide & Conquer** | Divide into *independent* subproblems        | Merge Sort       |
| **Greedy**           | Make locally optimal choices                 | Kruskal, Huffman |
| **DP**               | Solve *dependent* subproblems, reuse results | Knapsack, LCS    |

---

## 4. Steps to Solve a DP Problem

| Step                            | Description                                           |
| ------------------------------- | ----------------------------------------------------- |
| 1. **Identify Subproblems**     | What is the smaller version of the problem?           |
| 2. **Define State Variables**   | Represent subproblem uniquely (e.g., i, j, sum).      |
| 3. **Form Recurrence Relation** | Express the solution in terms of smaller subproblems. |
| 4. **Decide DP Type**           | Memoization (Top-Down) or Tabulation (Bottom-Up).     |
| 5. **Base Cases**               | Handle smallest possible subproblems.                 |
| 6. **Compute and Store**        | Store results in `dp[]` or `dp[][]` array.            |
| 7. **Optimize (if possible)**   | Reduce dimensions or use rolling arrays.              |

---

## 5. Types of Dynamic Programming

### 5.1. Memoization (Top-Down)

* Recursive + caching results.
* Natural extension of recursion.

**Pseudocode:**

```
function f(i):
    if base case:
        return base_value
    if dp[i] != -1:
        return dp[i]
    dp[i] = compute using recursion
    return dp[i]
```

**Example:** Fibonacci

```
fib(n):
    if n <= 1: return n
    if dp[n] != -1: return dp[n]
    dp[n] = fib(n-1) + fib(n-2)
    return dp[n]
```

---

### 5.2. Tabulation (Bottom-Up)

* Iterative version of DP.
* Builds solution from base cases upward.

**Pseudocode:**

```
dp[0] = base_case
for i in range(1, n+1):
    dp[i] = dp[i-1] + dp[i-2]
return dp[n]
```

**Key Difference:**
Memoization uses recursion; tabulation uses iteration.

---

### 5.3. Space-Optimized DP

When the current state depends on only a few previous states, we can store only those instead of the full table.

**Example:** Fibonacci (using two variables)

```
prev2 = 0
prev1 = 1
for i in range(2, n+1):
    cur = prev1 + prev2
    prev2 = prev1
    prev1 = cur
return prev1
```

---

## 6. Common DP Problem Categories

| Category               | Examples                                              |
| ---------------------- | ----------------------------------------------------- |
| **1D DP**              | Fibonacci, Climbing Stairs, House Robber              |
| **2D DP (Grid-based)** | Unique Paths, Minimum Path Sum                        |
| **Knapsack Family**    | 0/1 Knapsack, Unbounded Knapsack, Subset Sum          |
| **String DP**          | LCS, Edit Distance, Palindrome Partitioning           |
| **Partition DP**       | Matrix Chain Multiplication, Boolean Parenthesization |
| **Counting DP**        | Coin Change, Number of Ways problems                  |
| **Optimization DP**    | Rod Cutting, Buy and Sell Stocks                      |
| **Bitmask DP**         | Traveling Salesman, Assignments Problems              |
| **State-based DP**     | Game Theory, Digit DP                                 |

---

## 7. Visualization Example — Fibonacci

### Recursive Tree (Without DP)

```
             f(5)
           /     \
        f(4)     f(3)
       /   \     /   \
    f(3)  f(2) f(2)  f(1)
```

### With DP (Memoization)

```
f(5)
├── f(4)
│   ├── f(3)
│   └── f(2)
└── f(3)  (reused)
```

### Tabulated Computation

| n | dp[n] |
| - | ----- |
| 0 | 0     |
| 1 | 1     |
| 2 | 1     |
| 3 | 2     |
| 4 | 3     |
| 5 | 5     |

---

## 8. Common Patterns (DP Templates)

| Pattern            | Formula                                                                 |
| ------------------ | ----------------------------------------------------------------------- |
| **Fibonacci-like** | `dp[i] = dp[i-1] + dp[i-2]`                                             |
| **Knapsack-type**  | `dp[i][w] = max(dp[i-1][w], val[i] + dp[i-1][w - wt[i]])`               |
| **Grid traversal** | `dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])`                   |
| **LCS-type**       | `dp[i][j] = 1 + dp[i-1][j-1] if match else max(dp[i-1][j], dp[i][j-1])` |
| **Partition DP**   | `dp[i][j] = min(dp[i][k] + dp[k+1][j] + cost)`                          |

---

## 9. Complexity Considerations

| Aspect           | Memoization         | Tabulation                    |
| ---------------- | ------------------- | ----------------------------- |
| Time Complexity  | O(N × M) typically  | O(N × M)                      |
| Space Complexity | O(N × M) + O(Stack) | O(N × M)                      |
| Optimization     | Can reduce space    | Direct, no recursion overhead |

---

## 10. Edge Cases in DP

1. **Empty input arrays** (handle base cases properly).
2. **Negative or zero values** (for weight/value-based problems).
3. **Overflow risk** in counting problems (use modulo arithmetic).
4. **Memory overflow** (use space optimization if constraints are large).
5. **Boundary conditions** in 2D DP (i = 0 or j = 0).

---

## 11. How DP Appears in Interviews

| Company       | Common Topics                                     |
| ------------- | ------------------------------------------------- |
| **Google**    | LCS, Edit Distance, Matrix Chain Multiplication   |
| **Amazon**    | Knapsack, Coin Change, House Robber               |
| **Microsoft** | Partition Equal Subset Sum, Unique Paths          |
| **Facebook**  | Stock Buy-Sell Problems, Decode Ways              |
| **Adobe**     | Rod Cutting, Subset Sum, Boolean Parenthesization |

**Tip:** Interviewers often test your understanding of **recurrence formulation** and **space optimization** more than raw memorization.

---

## 12. Practice Problems

| Platform | Problem                                                                                                                  | Pattern            |
| -------- | ------------------------------------------------------------------------------------------------------------------------ | ------------------ |
| LeetCode | [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)                                                    | Fibonacci DP       |
| LeetCode | [198. House Robber](https://leetcode.com/problems/house-robber/)                                                         | 1D DP              |
| LeetCode | [322. Coin Change](https://leetcode.com/problems/coin-change/)                                                           | Unbounded Knapsack |
| GFG      | 0/1 Knapsack                                                                                                             | Classic            |
| LeetCode | [1143. LCS](https://leetcode.com/problems/longest-common-subsequence/)                                                   | String DP          |
| LeetCode | [1312. Min Insertions to Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/) | String DP          |
| LeetCode | [221. Maximal Square](https://leetcode.com/problems/maximal-square/)                                                     | 2D Grid DP         |
| LeetCode | [312. Burst Balloons](https://leetcode.com/problems/burst-balloons/)                                                     | Partition DP       |

---

## 13. Summary

| Concept                     | Meaning                                         |
| --------------------------- | ----------------------------------------------- |
| **State**                   | Represents subproblem parameters                |
| **Transition**              | Defines relation to smaller subproblems         |
| **Base Case**               | Defines trivial solution                        |
| **Optimal Substructure**    | Combine optimal subproblems for global solution |
| **Overlapping Subproblems** | Reuse computed states to reduce complexity      |

---

**Key Takeaway:**
Dynamic Programming is **recursion with memory**.
The essence lies not in code but in the ability to define the right **state** and **recurrence relation**.
Mastering DP means mastering **problem reduction and dependency visualization** — the skill that transforms brute force into optimal solutions.

