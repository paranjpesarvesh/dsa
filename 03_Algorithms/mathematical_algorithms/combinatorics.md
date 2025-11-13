# **Combinatorics – Core Concepts for Competitive Programming & DSA**

---

## **1. What Is Combinatorics?**

Combinatorics is the math of **counting**, **arrangements**, and **selections**.

In DSA, combinatorics appears in:

* Counting paths
* DP on grids
* Permutations & combinations
* Probability
* Modular arithmetic (mod 1e9+7)
* Binomial coefficients
* Catalan numbers
* Inclusion–exclusion
* Pigeonhole principle

---

## **2. Fundamental Counting Principles**

### **Rule of Product**

If event A has **m** ways and event B has **n** ways:
Total ways = m × n

### **Rule of Sum**

If either event A OR B happens (disjoint):
Total ways = m + n

### **Inclusion–Exclusion Principle (IEP)**

For overlapping sets:
|A ∪ B| = |A| + |B| – |A ∩ B|

---

## **3. Factorial and Permutations**

### **Factorial**

n! = n × (n–1) × ... × 1

### **Permutations**

Order matters.

P(n, r) = n! / (n – r)!

Examples in CP:

* Arranging people in seats
* Unique orderings
* Generating permutations via backtracking

---

## **4. Combinations (nCr)**

Order does not matter.

nCr = n! / (r! (n–r)!)

Key uses:

* Counting subsets
* DP on combinatorial structures
* Probability
* Binomial theorem

### **Efficient Computation**

In CP:

* Precompute factorials & inverse factorials modulo M
* Use Fermat’s Little Theorem for inverses

nCr % M = fact[n] × invfact[r] × invfact[n-r] % M

---

## **5. Pascal’s Triangle**

Each entry = sum of two above it.
Represents nCr values.

Level-by-level build:

```
  1
1   1
```

1   2   1
1   3   3   1

Recurrence:

C(n, r) = C(n–1, r–1) + C(n–1, r)

Used in DP formulations.

---

## **6. Binomial Theorem**

(a + b)^n = Σ (nCr * a^(n-r) * b^r)

Important for:

* Polynomial expansion
* Counting distributions
* Modular arithmetic

---

## **7. Catalan Numbers**

Catalan(n) = (1/(n+1)) (2n choose n)

Count:

* Valid parentheses sequences
* BST shapes
* Triangulations of polygon
* Number of full binary trees

First few:
1, 1, 2, 5, 14, 42, 132…

---

## **8. Stars and Bars**

Counting distributions of identical items into distinct bins:

Number of ways = C(n + k - 1, k - 1)
(where n = items, k = bins)

Used for:

* Integer partitions with constraints
* Counting non-negative solutions to equations

---

## **9. Inclusion–Exclusion Principle (IEP)**

For 2 sets:
|A ∪ B| = |A| + |B| – |A ∩ B|

General form for k sets:
Use alternating + and −.

Used in:

* Derangements
* Counting with forbidden positions
* Probability of union of events

---

## **10. Pigeonhole Principle**

If n items go into k boxes and n > k → at least one box has ≥ 2 items.

Used in:

* Hash collisions
* Birthday paradox
* DP constraints reasoning

---

## **11. Recurrence Relations**

Many combinatorial functions follow recurrence:

Examples:

* Fibonacci
* nCr
* Catalan numbers
* Bell numbers
* Stirling numbers

DP often used to compute them efficiently.

---

## **12. Pseudocode Template (No Code Block)**

# Precompute factorials

fact[0] = 1
for i in 1..N:
fact[i] = fact[i-1] * i % MOD

# Precompute inverses

invfact[N] = inverse(fact[N])
for i in N-1..0:
invfact[i] = invfact[i+1] * (i+1) % MOD

# Compute nCr fast

nCr = fact[n] * invfact[r] % MOD * invfact[n-r] % MOD

---

## **13. Complexity**

* Factorial preprocessing: O(N)
* Each nCr query: O(1)
* Large powers via fast exponentiation: O(log M)

---

## **14. Applications in Interviews**

FAANG almost always tests:

* Counting paths on grid → DP + combinatorics
* Valid parentheses → Catalan
* Unique BSTs → Catalan
* Permutation-based backtracking
* Probability computations

You may be asked to:

* Compute nCr mod MOD
* Use Pigeonhole or IEP in reasoning
* Expand using binomial theorem
* Recognize Catalan-type recurrence

---

## **15. Practice Problems**

**LeetCode:**

* 62 — Unique Paths
* 96 — Unique Binary Search Trees
* 1641 — Count Sorted Vowel Strings
* 119 — Pascal’s Triangle II

**GFG:**

* nCr mod M
* Catalan numbers
* Coin distribution problems

**Codeforces:**

* Combinatorics-heavy contest problems
* Large nCr modulo prime
* Derangements, subsets counting

---
