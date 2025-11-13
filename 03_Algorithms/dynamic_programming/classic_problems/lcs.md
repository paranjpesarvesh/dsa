# Longest Common Subsequence (LCS) — Dynamic Programming

The **Longest Common Subsequence (LCS)** problem is a **classic example of Dynamic Programming**, where we aim to find the **longest subsequence common to two given strings** while preserving the order of characters (but not necessarily contiguous).

---

## 1. Problem Definition

Given two strings `A` and `B`, find the **length** (and optionally, the sequence) of their **Longest Common Subsequence**.

---

### Example

```
A = "abcde"
B = "ace"
Output: 3
Explanation: The LCS is "ace" (length 3)
```

---

## 2. Intuition

* A **subsequence** is formed by deleting zero or more characters **without changing the order**.
* To find the **longest** such subsequence common to both strings, we check each character combination recursively.

At each step:

1. If the current characters match → include it in LCS and move diagonally.
2. If not → try skipping one character from either string and take the maximum result.

---

## 3. Recursive Relation

Let `dp[i][j]` represent the **LCS length** of the first `i` characters of `A` and the first `j` characters of `B`.

Then:

```
if A[i-1] == B[j-1]:
    dp[i][j] = 1 + dp[i-1][j-1]
else:
    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
```

### Base Case:

```
dp[0][*] = dp[*][0] = 0
```

(If one string is empty → LCS = 0)

---

## 4. Recursive Approach (Top-Down)

```
function lcs(i, j):
    if i == 0 or j == 0:
        return 0
    if A[i-1] == B[j-1]:
        return 1 + lcs(i-1, j-1)
    else:
        return max(lcs(i-1, j), lcs(i, j-1))
```

**Time Complexity:** O(2^(m+n))
→ Exponential (overlapping subproblems)

---

## 5. Memoization (Top-Down DP)

```
function lcs(i, j, dp):
    if i == 0 or j == 0:
        return 0
    if dp[i][j] != -1:
        return dp[i][j]
    if A[i-1] == B[j-1]:
        dp[i][j] = 1 + lcs(i-1, j-1, dp)
    else:
        dp[i][j] = max(lcs(i-1, j, dp), lcs(i, j-1, dp))
    return dp[i][j]
```

**Time Complexity:** O(m × n)
**Space Complexity:** O(m × n)

---

## 6. Tabulation (Bottom-Up DP)

**Pseudocode:**

```
function lcs(A, B):
    m = len(A)
    n = len(B)
    dp = array of size (m+1) x (n+1)

    for i from 0 to m:
        for j from 0 to n:
            if i == 0 or j == 0:
                dp[i][j] = 0
            else if A[i-1] == B[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])

    return dp[m][n]
```

**Time Complexity:** O(m × n)
**Space Complexity:** O(m × n)

---

## 7. Space Optimization

We only need the **previous row** to compute the current one.

**Pseudocode:**

```
function lcs(A, B):
    prev = [0] * (len(B)+1)
    curr = [0] * (len(B)+1)

    for i in range(1, len(A)+1):
        for j in range(1, len(B)+1):
            if A[i-1] == B[j-1]:
                curr[j] = 1 + prev[j-1]
            else:
                curr[j] = max(prev[j], curr[j-1])
        prev = curr.copy()

    return prev[len(B)]
```

**Space Complexity:** O(n)

---

## 8. Visual Example

```
A = "abcde"
B = "ace"

DP Table (m+1 x n+1):

      ""  a  c  e
   ""  0  0  0  0
   a   0  1  1  1
   b   0  1  1  1
   c   0  1  2  2
   d   0  1  2  2
   e   0  1  2  3
```

Result: LCS length = 3

---

## 9. Reconstructing the LCS String

To get the **actual LCS string**, backtrack from `dp[m][n]`.

**Pseudocode:**

```
i = m, j = n
ans = ""

while i > 0 and j > 0:
    if A[i-1] == B[j-1]:
        ans += A[i-1]
        i -= 1
        j -= 1
    else if dp[i-1][j] > dp[i][j-1]:
        i -= 1
    else:
        j -= 1

return reverse(ans)
```

---

## 10. Variations

| Variant                                     | Description                                               |
| ------------------------------------------- | --------------------------------------------------------- |
| **Longest Common Substring**                | Continuous segment → `dp[i][j] = 1 + dp[i-1][j-1]` else 0 |
| **Shortest Common Supersequence (SCS)**     | `len(SCS) = m + n - LCS(A, B)`                            |
| **Minimum Deletions to Make Strings Equal** | `= m + n - 2 × LCS(A, B)`                                 |
| **Print All LCS**                           | Modify backtracking to handle ties                        |
| **Diff Utility (File Comparison)**          | LCS helps identify common text lines                      |

---

## 11. Interview Tips

* Start with **recursion**, derive **DP recurrence** clearly.
* Always mention **base cases** (`i == 0 or j == 0 → 0`).
* Be comfortable explaining **space optimization**.
* Common trick question: “What changes for *Longest Common Substring*?”
* Common FAANG test variants:

  * "Minimum Insertions/Deletions to Convert A → B"
  * "Print one LCS string"

---

## 12. Practice Problems

| Platform   | Problem                                                                                                                  | Type                 |
| ---------- | ------------------------------------------------------------------------------------------------------------------------ | -------------------- |
| LeetCode   | [1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)                            | Basic LCS            |
| GFG        | Longest Common Subsequence                                                                                               | Classic              |
| LeetCode   | [712. Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/) | LCS variant          |
| Codeforces | Common Subsequence                                                                                                       | Simple check variant |

---

## 13. Summary

| Concept              | Explanation                                                       |
| -------------------- | ----------------------------------------------------------------- |
| **State**            | `dp[i][j]` → LCS of A[0..i-1], B[0..j-1]                          |
| **Transition**       | If match → `1 + dp[i-1][j-1]`, else `max(dp[i-1][j], dp[i][j-1])` |
| **Base Case**        | Any string empty → 0                                              |
| **Time Complexity**  | O(m × n)                                                          |
| **Space Complexity** | O(n) optimized                                                    |
| **Common Variants**  | Substring, SCS, Min Deletions, Print LCS                          |

---

**Key Takeaway:**
The **LCS problem** captures the essence of Dynamic Programming — optimal substructure and overlapping subproblems.
It serves as a foundation for many **string alignment**, **diff**, and **sequence comparison** algorithms in real-world systems like Git, compilers, and bioinformatics.

