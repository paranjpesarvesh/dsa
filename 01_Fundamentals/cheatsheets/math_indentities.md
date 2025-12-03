# 🧮 Mathematical Identities & Formulas for DSA

This cheatsheet contains the most **commonly used mathematical formulas** in data structures and algorithms. They appear frequently in **interviews, coding contests, and GATE exams** for simplifying problems, optimizing algorithms, or analyzing complexities.

---

##  1. Summation Formulas

| Formula                          | Identity                                           | Usage in DSA                         |
| -------------------------------- | -------------------------------------------------- | ------------------------------------ |
| Sum of first `n` natural numbers | 1 + 2 + 3 + … + n = n(n+1)/2                       | Loop counts, triangular numbers      |
| Sum of squares                   | 1² + 2² + … + n² = n(n+1)(2n+1)/6                  | DP states, variance calculation      |
| Sum of cubes                     | 1³ + 2³ + … + n³ = (n(n+1)/2)²                     | Subarray sums, prefix sums           |
| Arithmetic series                | a + (a+d) + … + \[a+(n-1)d] = n/2 \* (2a + (n-1)d) | Recurrence simplification            |
| Geometric series                 | a(1-rⁿ)/(1-r), r ≠ 1                               | Master theorem, recurrence relations |

---

##  2. Logarithmic Identities

| Identity                                   | Notes                                  |
| ------------------------------------------ | -------------------------------------- |
| log(ab) = log a + log b                    | Splitting multiplication               |
| log(a/b) = log a – log b                   | Division handling                      |
| log(a^b) = b log a                         | Complexity proofs                      |
| log base change                            | logₐ b = log b / log a                 |
| log(n!) ≈ n log n – n (Stirling’s approx.) | Analyzing factorial-based complexities |

 **Interview relevance**: Many complexity reductions depend on rewriting `log` terms, e.g., `O(n log n)` vs `O(log(n!))`.

---

##  3. Modular Arithmetic

* **Modulo Properties**

  * (a + b) % m = (a % m + b % m) % m
  * (a – b) % m = (a % m – b % m + m) % m
  * (a × b) % m = (a % m × b % m) % m

* **Fast Exponentiation (Binary Exponentiation)**

  * aᵇ % m can be computed in **O(log b)** using divide & conquer.

* **Modular Inverse**

  * a⁻¹ mod m exists if gcd(a, m) = 1.
  * Find using **Extended Euclidean Algorithm** or **Fermat’s theorem** (if m is prime):
    a⁻¹ ≡ a^(m-2) mod m.

---

##  4. Combinatorics

* n! = n × (n–1) × … × 1
* Permutations: P(n, r) = n! / (n–r)!
* Combinations: C(n, r) = n! / (r!(n–r)!)
* Binomial Theorem:
  (x + y)ⁿ = Σ \[C(n, k) × xⁿ⁻ᵏ × yᵏ],  k=0..n

 **Tip**: Precompute factorials and inverses in **O(n)** for quick nCr calculations in contests.

---

##  5. Number Theory

* Euclidean GCD: gcd(a, b) = gcd(b, a % b) → O(log min(a, b))
* LCM: lcm(a, b) = (a × b) / gcd(a, b)
* Prime checking: up to √n in O(√n)
* Sieve of Eratosthenes: O(n log log n) for prime generation
* Euler’s Totient φ(n): Count of numbers < n that are coprime with n

---

##  6. Probability & Expected Value

* Expected value linearity:
  E\[X + Y] = E\[X] + E\[Y]
* For uniform distribution of n outcomes:
  P(event) = favorable / total
* Useful for randomized algorithms (e.g., QuickSort expected case).

---

##  7. Recurrence Relations & Master Theorem

### Master Theorem

T(n) = aT(n/b) + f(n)

* If f(n) = O(n^(log\_b a – ε)) → T(n) = Θ(n^(log\_b a))
* If f(n) = Θ(n^(log\_b a)) → T(n) = Θ(n^(log\_b a) log n)
* If f(n) = Ω(n^(log\_b a + ε)) and regularity holds → T(n) = Θ(f(n))

**Examples**:

* MergeSort: T(n) = 2T(n/2) + O(n) → Θ(n log n)
* Binary Search: T(n) = T(n/2) + O(1) → Θ(log n)

---

##  8. Common Summation Tricks

* Harmonic series: 1 + 1/2 + 1/3 + … + 1/n ≈ ln(n) + γ (Euler’s constant)
* Σ log i (i=1..n) ≈ n log n – n
* Useful in analysis of sorting and heap-building.

---

##  9. Visual Aid: Complexity Growth Rates

```
O(1) < O(log n) < O(n) < O(n log n) < O(n²) < O(2^n) < O(n!)
```

---

##  10. Interview Tips

*  **FAANG**: Expect modular arithmetic (subarray sum, combinatorics), number theory (GCD/LCM, primes), probability (randomized algorithms).
*  **GATE**: Heavy focus on recurrence solving, summations, logarithmic simplifications, combinatorics.
*  Always simplify expressions like `Σ log i` or `Σ n/2^i` → common in complexity proofs.

---

##  11. Practice Problems

* [LeetCode: Math Problems](https://leetcode.com/problemset/all/?topicSlugs=math)
* [GFG: Mathematical Algorithms](https://www.geeksforgeeks.org/mathematical-algorithms/)
* [Codeforces Math Tag](https://codeforces.com/problemset?tags=math)
* GATE PYQs (Complexity, Recurrences, Combinatorics)

---
