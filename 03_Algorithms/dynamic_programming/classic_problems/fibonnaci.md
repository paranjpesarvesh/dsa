# Fibonacci Sequence — Dynamic Programming Approaches

The **Fibonacci Sequence** is one of the most classic examples used to illustrate **recursion**, **overlapping subproblems**, and **dynamic programming**.
It forms the foundation for understanding how to optimize recursive relations using **memoization** and **tabulation**.

---

## 1. Definition

The Fibonacci sequence is defined as:

```
F(0) = 0
F(1) = 1
F(n) = F(n - 1) + F(n - 2)  for n ≥ 2
```

So, the sequence begins:

```
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
```

---

## 2. Intuition

Every Fibonacci number depends on the previous two.
Thus, we have **overlapping subproblems** and **optimal substructure**, making it an ideal candidate for **dynamic programming**.

Naive recursion repeatedly recalculates the same results (e.g., `F(3)` computed multiple times).
DP eliminates this redundancy.

---

## 3. Recursive Approach (Brute Force)

```
function fib(n):
    if n <= 1:
        return n
    return fib(n-1) + fib(n-2)
```

**Time Complexity:** O(2ⁿ)
**Space Complexity:** O(n) (recursion stack)

### Drawback:

Massive recomputation — inefficient for large `n`.

---

## 4. Dynamic Programming — Memoization (Top-Down)

We store intermediate results in a cache (array or dictionary).

**Pseudocode:**

```
function fib(n, dp):
    if n <= 1:
        return n
    if dp[n] != -1:
        return dp[n]
    dp[n] = fib(n-1, dp) + fib(n-2, dp)
    return dp[n]
```

**Time Complexity:** O(n)
**Space Complexity:** O(n) (dp array + recursion stack)

---

## 5. Dynamic Programming — Tabulation (Bottom-Up)

We iteratively compute values starting from base cases.

**Pseudocode:**

```
function fib(n):
    dp = array of size (n+1)
    dp[0] = 0
    dp[1] = 1
    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]
    return dp[n]
```

**Time Complexity:** O(n)
**Space Complexity:** O(n)

---

## 6. Space Optimization

Since each state depends only on the last two,
we can maintain just two variables.

**Pseudocode:**

```
function fib(n):
    if n <= 1:
        return n
    prev2 = 0
    prev1 = 1
    for i in range(2, n+1):
        curr = prev1 + prev2
        prev2 = prev1
        prev1 = curr
    return prev1
```

**Time Complexity:** O(n)
**Space Complexity:** O(1)

---

## 7. Mathematical Derivation (Closed Form)

Using **Binet’s Formula**:

```
F(n) = [ φⁿ - (1 - φ)ⁿ ] / √5
where φ = (1 + √5) / 2
```

This formula provides **O(1)** time but involves floating-point precision errors for large `n`.

---

## 8. Visualization

### Recursive Tree for F(5)

```
             F(5)
           /     \
        F(4)     F(3)
       /   \     /   \
    F(3)  F(2) F(2) F(1)
   /   \   / \   / \
 F(2) F(1)F(1)F(0)
```

Notice that `F(3)` and `F(2)` are computed multiple times → redundancy solved by DP.

---

## 9. Step-by-Step Tabulation Example

For n = 6:

| i | dp[i-2] | dp[i-1] | dp[i] = sum |
| - | ------- | ------- | ----------- |
| 0 | -       | -       | 0           |
| 1 | -       | -       | 1           |
| 2 | 0       | 1       | 1           |
| 3 | 1       | 1       | 2           |
| 4 | 1       | 2       | 3           |
| 5 | 2       | 3       | 5           |
| 6 | 3       | 5       | 8           |

Answer: F(6) = 8

---

## 10. Variations

1. **Nth Fibonacci Mod M**
   Compute `F(n) % M` efficiently using modular arithmetic.

2. **Matrix Exponentiation**
   Use matrix power to compute Fibonacci in O(log n).

   ```
   | F(n+1) |   =   | 1 1 |^n  * | F(1) |
   | F(n)   |       | 1 0 |     | F(0) |
   ```

3. **Fast Doubling Method**
   Recursive formula in O(log n):

   ```
   F(2k) = F(k) * [2F(k+1) - F(k)]
   F(2k+1) = F(k+1)² + F(k)²
   ```

---

## 11. Interview Tips

* Know all three methods: recursion, memoization, tabulation.
* Explain **overlapping subproblems** clearly.
* Discuss **space optimization** and **matrix exponentiation**.
* Be ready to handle **large n (10⁹)** using fast doubling or matrix power.
* Common variants: Fibonacci sum, modified Fibonacci, Tribonacci.

Asked by: **Amazon, Google, Adobe, Microsoft, Flipkart**

---

## 12. Practice Problems

| Platform   | Problem                                                                  | Concept               |
| ---------- | ------------------------------------------------------------------------ | --------------------- |
| LeetCode   | [509. Fibonacci Number](https://leetcode.com/problems/fibonacci-number/) | Basic DP              |
| LeetCode   | [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)    | Fibonacci variant     |
| GFG        | Nth Fibonacci                                                            | DP and Recursion      |
| Codeforces | Fibonacci Mod M                                                          | Matrix exponentiation |

---

## 13. Summary

| Approach               | Time     | Space | Description         |
| ---------------------- | -------- | ----- | ------------------- |
| Recursive              | O(2ⁿ)    | O(n)  | Naive, exponential  |
| Memoization            | O(n)     | O(n)  | Top-down caching    |
| Tabulation             | O(n)     | O(n)  | Bottom-up iterative |
| Space Optimized        | O(n)     | O(1)  | Best practical      |
| Matrix / Fast Doubling | O(log n) | O(1)  | For very large n    |

---

**Key Takeaway:**
Fibonacci is the perfect gateway to understanding **Dynamic Programming** — how recursion transforms into efficient iterative solutions by storing intermediate results.

