# Edit Distance — Dynamic Programming (Levenshtein Distance)

The **Edit Distance** (also called **Levenshtein Distance**) problem is a classic **Dynamic Programming** problem that measures how dissimilar two strings are by counting the **minimum number of operations** required to transform one string into the other.

---

## 1. Problem Definition

Given two strings `A` and `B`, determine the **minimum number of operations** required to convert `A` into `B`.

Allowed operations:

1. **Insert** a character
2. **Delete** a character
3. **Replace** a character

---

### Example

```
A = "horse"
B = "ros"
```

Operations:

1. Replace 'h' → 'r' → "rorse"
2. Delete 'r' → "orse"
3. Delete 'e' → "ros"

Total operations = **3**

Hence, `editDistance("horse", "ros") = 3`.

---

## 2. Intuition

If two strings are equal → distance = 0.
Otherwise, at each mismatch, we can:

* Insert a character → move in one string
* Delete a character → move in the other string
* Replace a character → move in both strings

We minimize the total cost by exploring all possibilities using **recursion + memoization** or **DP tabulation**.

---

## 3. Mathematical Recurrence

Let:

```
A[0..i-1], B[0..j-1]
dp[i][j] = minimum operations to convert A[0..i-1] → B[0..j-1]
```

### Recurrence relation:

```
if A[i-1] == B[j-1]:
    dp[i][j] = dp[i-1][j-1]
else:
    dp[i][j] = 1 + min(
        dp[i-1][j],     # Delete from A
        dp[i][j-1],     # Insert into A
        dp[i-1][j-1]    # Replace A[i-1] with B[j-1]
    )
```

### Base Cases:

```
dp[0][j] = j   # A is empty → need j insertions
dp[i][0] = i   # B is empty → need i deletions
```

---

## 4. Pseudocode (Tabulation)

```
function editDistance(A, B):
    n = len(A)
    m = len(B)
    dp = 2D array of size (n+1) x (m+1)

    for i in range(0, n+1):
        dp[i][0] = i
    for j in range(0, m+1):
        dp[0][j] = j

    for i in range(1, n+1):
        for j in range(1, m+1):
            if A[i-1] == B[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])

    return dp[n][m]
```

---

## 5. Example Walkthrough

```
A = "intention"
B = "execution"
```

| i/j | "" | e | x | e | c | u | t | i | o | n |
| --- | -- | - | - | - | - | - | - | - | - | - |
| ""  | 0  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| i   | 1  | 1 | 2 | 3 | 4 | 5 | 6 | 6 | 7 | 8 |
| n   | 2  | 2 | 2 | 3 | 4 | 5 | 6 | 7 | 7 | 7 |
| t   | 3  | 3 | 3 | 3 | 4 | 5 | 5 | 6 | 7 | 8 |
| e   | 4  | 3 | 4 | 3 | 4 | 5 | 6 | 6 | 7 | 8 |
| n   | 5  | 4 | 4 | 4 | 4 | 5 | 6 | 7 | 7 | 7 |
| t   | 6  | 5 | 5 | 5 | 5 | 5 | 5 | 6 | 7 | 8 |
| i   | 7  | 6 | 6 | 6 | 6 | 6 | 6 | 5 | 6 | 7 |
| o   | 8  | 7 | 7 | 7 | 7 | 7 | 7 | 6 | 5 | 6 |
| n   | 9  | 8 | 8 | 8 | 8 | 8 | 8 | 7 | 6 | 5 |

Result: **5**

---

## 6. Complexity Analysis

| Type  | Complexity |
| ----- | ---------- |
| Time  | O(n × m)   |
| Space | O(n × m)   |

### Space Optimization

We can reduce space to O(min(n, m)) using two rolling arrays:

```
prev[j], curr[j]
```

---

## 7. Recursive + Memoized Approach (Top-Down)

```
function solve(i, j, A, B, dp):
    if i == 0: return j
    if j == 0: return i
    if dp[i][j] != -1: return dp[i][j]

    if A[i-1] == B[j-1]:
        dp[i][j] = solve(i-1, j-1)
    else:
        dp[i][j] = 1 + min(
            solve(i-1, j),   # delete
            solve(i, j-1),   # insert
            solve(i-1, j-1)  # replace
        )
    return dp[i][j]
```

---

## 8. Variations

1. **Transform with cost-weighted operations**
   → Each operation (insert/delete/replace) has different cost.
   Modify recurrence accordingly.

2. **Longest Common Subsequence (LCS) relation**
   When only insertions/deletions are allowed:

   ```
   edit_distance = n + m - 2 * LCS(A, B)
   ```

3. **Restricted Edit Distance**
   e.g., transpositions (used in spell check algorithms like Damerau-Levenshtein).

---

## 9. Visual Aid (State Transition)

```
        ┌──────────────┐
        │A[i-1]==B[j-1]│
        └───────┬──────┘
                │
        ┌───────┴────────┐
        │ dp[i-1][j-1]    │  ← no cost
        └─────────────────┘
                │
                ▼
    ┌────────────────────────────┐
    │ else → 1 + min(            │
    │   dp[i-1][j],     # delete │
    │   dp[i][j-1],     # insert │
    │   dp[i-1][j-1] )  # replace│
    └────────────────────────────┘
```

---

## 10. Interview Tips

* Always clarify **which operations** are allowed.
* Mention **DP table dimensions** and **base initialization** explicitly.
* Emphasize **relation to LCS** for conceptual understanding.
* Discuss **space optimization** if asked.
* Common follow-ups:

  * Reconstruct actual edit sequence.
  * Apply to spell-check or DNA sequence alignment.

---

## 11. Practice Problems

| Platform   | Problem                                                           | Type               |
| ---------- | ----------------------------------------------------------------- | ------------------ |
| LeetCode   | [72. Edit Distance](https://leetcode.com/problems/edit-distance/) | Minimum operations |
| GFG        | Edit Distance                                                     | Classic DP         |
| Codeforces | String Transformations                                            | Variants           |
| AtCoder    | DP O - Matching                                                   | Similar structure  |

---

## 12. Summary

| Concept          | Description                                                       |
| ---------------- | ----------------------------------------------------------------- |
| Problem Type     | Dynamic Programming                                               |
| State            | dp[i][j] → min ops to convert A[0..i-1] → B[0..j-1]               |
| Transitions      | Match → `dp[i-1][j-1]`, Else → `1 + min(Insert, Delete, Replace)` |
| Base Cases       | `dp[0][j] = j`, `dp[i][0] = i`                                    |
| Time Complexity  | O(n × m)                                                          |
| Space Complexity | O(n × m) or O(min(n, m))                                          |
| Relation         | Generalization of LCS                                             |

---

**Key takeaway:**
Edit Distance is a foundational DP concept illustrating optimal substructure and overlapping subproblems — crucial for string transformation, text similarity, and bioinformatics applications.

