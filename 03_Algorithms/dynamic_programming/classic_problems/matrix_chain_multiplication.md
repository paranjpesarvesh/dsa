# Matrix Chain Multiplication (MCM) — Dynamic Programming

The **Matrix Chain Multiplication (MCM)** problem is a **classic optimization problem** in **Dynamic Programming**, illustrating the concept of **optimal parenthesization** — i.e., finding the most efficient way to multiply a sequence of matrices.

---

## 1. Problem Definition

You are given a sequence of matrices:
`A1, A2, A3, ..., An`
where the dimensions of the `i-th` matrix are `p[i-1] × p[i]`.

**Goal:**
Determine the **minimum number of scalar multiplications** needed to multiply all the matrices together.

---

### Example

```
Input: p = [10, 20, 30, 40, 30]
Output: 30000
Explanation:
There are 4 matrices:
A1 = 10x20, A2 = 20x30, A3 = 30x40, A4 = 40x30

Optimal order: ((A1 * (A2 * A3)) * A4)
Cost = (20*30*40) + (10*30*30) = 24000 + 9000 = 33000
Another way gives higher cost, so minimum = 30000
```

---

## 2. Intuition

Matrix multiplication is **associative**, i.e.,

```
(A1 × A2) × A3 = A1 × (A2 × A3)
```

However, the number of **scalar multiplications** differs depending on how we parenthesize.
We must **find the order of multiplication** that **minimizes the total cost**.

---

## 3. Mathematical Formulation

Let `dp[i][j]` denote the **minimum number of multiplications** needed to compute the product of matrices from `A[i]` to `A[j]`.

Then,

```
dp[i][j] = 0  if i == j
dp[i][j] = min( dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j] )  for i ≤ k < j
```

Explanation:

* Split the chain between `A[k]` and `A[k+1]`.
* Compute the cost of both parts recursively.
* Add the cost of multiplying the two resulting matrices.

---

## 4. Recursive Approach

```
function MCM(i, j):
    if i == j:
        return 0
    min_cost = ∞
    for k in range(i, j):
        cost = MCM(i, k) + MCM(k+1, j) + p[i-1]*p[k]*p[j]
        min_cost = min(min_cost, cost)
    return min_cost
```

**Time Complexity:** O(2ⁿ) (exponential)
**Space Complexity:** O(n) (stack depth)

---

## 5. Memoization (Top-Down DP)

```
function MCM(i, j, dp, p):
    if i == j:
        return 0
    if dp[i][j] != -1:
        return dp[i][j]

    dp[i][j] = ∞
    for k in range(i, j):
        dp[i][j] = min(dp[i][j],
                       MCM(i, k, dp, p) + MCM(k+1, j, dp, p) + p[i-1]*p[k]*p[j])
    return dp[i][j]
```

**Time Complexity:** O(n³)
**Space Complexity:** O(n²)

---

## 6. Tabulation (Bottom-Up DP)

```
function matrixChainOrder(p):
    n = len(p)
    dp = [[0 for _ in range(n)] for _ in range(n)]

    for length in range(2, n):        # chain length
        for i in range(1, n - length + 1):
            j = i + length - 1
            dp[i][j] = float('inf')
            for k in range(i, j):
                dp[i][j] = min(dp[i][j],
                               dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j])
    return dp[1][n-1]
```

**Time Complexity:** O(n³)
**Space Complexity:** O(n²)

---

## 7. Example Calculation

For p = [10, 20, 30, 40]:

| i | j | Splits (k) | Cost Formula                      | Cost                 | dp[i][j] |
| - | - | ---------- | --------------------------------- | -------------------- | -------- |
| 1 | 2 | —          | —                                 | 0                    | 0        |
| 2 | 3 | —          | —                                 | 0                    | 0        |
| 1 | 3 | k=1,2      | (10*20*30)=6000, (10*30*40)=12000 | min(6000,12000)=6000 | 6000     |

Final Answer = 6000

---

## 8. Visual Representation

### Matrix Chain Split Example

```
           A1 A2 A3 A4
              |
           Split at k=2
        /               \
  (A1 * A2)        (A3 * A4)
```

### DP Table Layout

```
       j →
     1   2   3   4
i  -----------------
1 | 0  0  6000 18000
2 |    0   0   24000
3 |        0    0
4 |             0
```

---

## 9. Printing Optimal Parenthesization

To reconstruct the **order** of multiplication, maintain a `split[][]` table.

```
function printOrder(i, j, split):
    if i == j:
        print("A" + str(i))
    else:
        print("(")
        printOrder(i, split[i][j], split)
        printOrder(split[i][j] + 1, j, split)
        print(")")
```

---

## 10. Variations

| Variant                         | Description                                     |
| ------------------------------- | ----------------------------------------------- |
| **Boolean Parenthesization**    | Count ways to parenthesize boolean expressions. |
| **Evaluate Expression to True** | Similar to MCM but with logical operators.      |
| **Burst Balloons**              | MCM-like splitting problem on array.            |
| **Palindrome Partitioning**     | Find min cuts to make substrings palindromic.   |
| **Minimum Cost to Cut a Stick** | MCM variation using stick positions.            |

---

## 11. Edge Cases

1. Only one matrix → cost = 0
2. Two matrices → cost = direct multiplication
3. Non-square matrices must follow dimension rules (`p[i-1]*p[i]` must be valid)

---

## 12. Interview Tips

* **Focus on recurrence relation derivation.**
* **Common pitfall:** confusing cost formula (`p[i-1]*p[k]*p[j]`).
* Be prepared to derive **tabulation from recursion**.
* Practice related problems (Expression Evaluation, Palindrome Partition).
* Common in **Amazon**, **Google**, **Adobe**, **Microsoft** interviews.

---

## 13. Practice Problems

| Platform | Problem                                                              | Type                  |
| -------- | -------------------------------------------------------------------- | --------------------- |
| GFG      | Matrix Chain Multiplication                                          | Classic DP            |
| LeetCode | [312. Burst Balloons](https://leetcode.com/problems/burst-balloons/) | MCM variant           |
| GFG      | Boolean Parenthesization                                             | Expression evaluation |
| GFG      | Palindrome Partitioning                                              | String DP variant     |

---

## 14. Summary

| Concept              | Description                                                |
| -------------------- | ---------------------------------------------------------- |
| **State**            | `dp[i][j]` = min cost to multiply matrices from i to j     |
| **Transition**       | `dp[i][j] = min(dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j])` |
| **Base Case**        | `dp[i][i] = 0`                                             |
| **Time Complexity**  | O(n³)                                                      |
| **Space Complexity** | O(n²)                                                      |
| **Goal**             | Minimum scalar multiplications                             |

---

**Key Takeaway:**
The **Matrix Chain Multiplication** problem is a cornerstone of Dynamic Programming.
It teaches **optimal substructure**, **overlapping subproblems**, and **parenthesization strategy**, foundational to advanced problems like **Expression Evaluation**, **Burst Balloons**, and **Optimal BST**.

