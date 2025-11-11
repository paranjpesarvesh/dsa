# Advanced String Edit Distance — Theory & Techniques

## 1. Introduction

Edit Distance measures how many operations are needed to transform one string into another.
The classical algorithm is **Levenshtein Distance**, allowing:

* Insert
* Delete
* Replace

This file covers **advanced edit distance variants**, optimizations, and enhanced models used in competitive programming and research-level problems.

---

## 2. Classical Edit Distance Recap

Given two strings A (length n) and B (length m), DP recurrence:

```
dp[i][j] = minimum operations to convert A[0..i-1] → B[0..j-1]
```

Transition:

```
dp[i][j] = min(
    dp[i-1][j] + 1,         # delete
    dp[i][j-1] + 1,         # insert
    dp[i-1][j-1] + cost     # replace or match
)
```

Where cost = 0 if characters match, else 1.

Time: O(n*m)
Space: O(n*m)

---

## 3. Advanced Variants of Edit Distance

### 3.1 Damerau–Levenshtein Distance

Allows **transposition** (swap of adjacent characters).

Extra rule:

```
if A[i-1] == B[j-2] and A[i-2] == B[j-1]:
    dp[i][j] = min(dp[i][j], dp[i-2][j-2] + 1)
```

Use cases:

* Typo correction
* Keyboard similarity

---

### 3.2 Weighted Edit Distance

Different costs for operations:

* cost_insert(x)
* cost_delete(x)
* cost_replace(x, y)

Application:

* Bioinformatics (DNA mutation penalties)
* OCR (optical character recognition)

DP becomes:

```
dp[i][j] = min(
    dp[i-1][j] + del_cost(A[i-1]),
    dp[i][j-1] + ins_cost(B[j-1]),
    dp[i-1][j-1] + rep_cost(A[i-1], B[j-1])
)
```

---

### 3.3 Edit Distance with Constraints

Examples:

1. Only insertions allowed
2. No replacements allowed
3. Limited number of operations
4. Edit distance modulo K

---

### 3.4 Edit Distance with Affine Gap Penalties

Useful in bioinformatics.

Cost model:

```
gap_open = large penalty
gap_extend = small penalty
```

Cost for consecutive deletions handled as:

```
dp[i][j] = min(
   match/mismatch cost,
   gap_open + gap_extend*(k),   # k is length of gap
)
```

Requires 3 matrices:

* M — match/mismatch
* I — insertion gap state
* D — deletion gap state

---

### 3.5 Edit Distance on Compressed Strings

Typical compression:

* Run-length encoding
* SLP / LZ77 compressed representation

Goal: reduce time from O(n*m) to O(r1 * r2), where r1,r2 are compressed lengths.

---

### 3.6 Edit Distance in Streaming Model

Compute distance using:

* Only O(min(n, m)) space
* Sliding windows
* Rolling DP

---

### 3.7 Edit Distance with Subsequence Constraints

Compute edit distance but also ensure B is a subsequence of A.

Used in dynamic search and predictive typing.

---

## 4. Optimizations for Edit Distance

### 4.1 Space Optimization

We need only two rows:

```
current[j] and previous[j]
```

Space reduces from O(n*m) → O(min(n, m))

---

### 4.2 Ukkonen’s Algorithm (Band DP)

If maximum edit distance allowed is <= K,
we only compute cells inside band:

```
|i - j| <= K
```

Time complexity:

```
O(K * min(n, m))
```

Useful in:

* Spell checkers
* Fuzzy searching

---

### 4.3 Myers Algorithm (Bitset Optimization)

If alphabet is small and strings up to length 10^5.

Time complexity:

```
O((n * m) / word_size)
```

Often extremely fast in practice.

---

### 4.4 Divide and Conquer Edit Distance (Hirschberg Algorithm)

Used when outputting actual alignment is needed but space must be minimized.

---

## 5. Pseudocode (Classic and Optimized)

### 5.1 Standard DP

```
for i in 0..n:
    dp[i][0] = i
for j in 0..m:
    dp[0][j] = j

for i in 1..n:
    for j in 1..m:
        if A[i-1] == B[j-1]:
            cost = 0
        else:
            cost = 1

        dp[i][j] = min(
            dp[i-1][j] + 1,
            dp[i][j-1] + 1,
            dp[i-1][j-1] + cost
        )
```

---

### 5.2 Ukkonen’s Bounded DP

```
for i in 0..n:
    for j in max(1, i-K) .. min(m, i+K):
        compute dp[i][j]
```

---

### 5.3 Bitset (Myers)

Represent mismatch operations as bit operations.

State transitions are bitwise:

```
VP, VN, D0, HP, HN
```

Advanced, but used in high-performance searchers (e.g. `grep` variants).

---

## 6. Complexity Summary

| Algorithm           | Time               | Space          |
| ------------------- | ------------------ | -------------- |
| Classic DP          | O(n*m)             | O(n*m)         |
| Space-optimized DP  | O(n*m)             | O(min(n, m))   |
| Ukkonen (banded)    | O(K * min(n, m))   | O(K)           |
| Myers bitset        | O((n*m)/word_size) | O(m/word_size) |
| Damerau-Levenshtein | O(n*m)             | O(n*m)         |

---

## 7. When to Use Which?

| Scenario                          | Best Algorithm      |
| --------------------------------- | ------------------- |
| Short strings                     | Classic DP          |
| Memory restricted                 | Space-optimized     |
| Approximate matching with bound K | Ukkonen             |
| Very large strings                | Bitset-based        |
| Typos with adjacent swaps         | Damerau-Levenshtein |
| Bioinformatics                    | Affine-gap models   |

---

## 8. Visual Explanation

### DP Table Structure

```
      B
    j0 j1 j2 j3 j4
A i0  0  1  2  3  4
  i1  1  x  x  x  x
  i2  2  x  x  x  x
  i3  3  x  x  x  x
```

Each cell depends on:

```
↖ diagonal (replace)
↑  delete
←  insert
```

---

## 9. Interview Tips

* Always start with classical DP formulation.
* Explain possible improvements:

  * Space optimization
  * Banded DP
  * Replace DP table with two rows
* If asked about real-world applications:

  * Text correction
  * DNA sequence alignment
  * Fuzzy search
* For advanced forms:

  * Mention Damerau-Levenshtein for adjacent swap handling
  * Mention affine penalties for gaps
* Be ready to explain Myers algorithm theoretically (bit-parallelism)

---

## 10. Practice Problems

### LeetCode

* 72. Edit Distance
* 583. Delete Operation for Two Strings
* 712. Minimum ASCII Delete Sum
* 161. One Edit Distance

### Codeforces

* Problems tagged: `dp`, `edit distance`
* Educational DP Rounds

### GFG

* Edit Distance
* Variants including weighted operations

---

## 11. Summary

Advanced string edit distance algorithms extend the classical DP by:

* adding more operation types
* reducing complexity
* adapting to constraints
* using bit optimizations
* enabling real-world error models

This topic sits at the intersection of DP, optimization, and advanced algorithm design.

---
