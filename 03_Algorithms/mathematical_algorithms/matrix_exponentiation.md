# **Matrix Exponentiation**

---

## **1. What Is Matrix Exponentiation?**

Matrix exponentiation is a technique to compute certain recurrences **in O(log n)** using matrix powers.

Typical recurrence:

F(n) = a·F(n−1) + b·F(n−2) + …

If we express the recurrence as:

V(n) = M · V(n−1)

Then:

V(n) = Mⁿ · V(0)

Thus computing F(n) reduces to computing Mⁿ efficiently.

---

## **2. Why Matrix Exponentiation Works (Intuition)**

Take Fibonacci:

F(n) = F(n−1) + F(n−2)

Represent as matrix:

| F(n)   |   =  | 1 1 | · | F(n−1) |
| F(n-1) |      | 1 0 |   | F(n−2) |

Thus:

M = |1 1|
|1 0|

Then:

|F(n) F(n−1)|ᵀ = Mⁿ⁻¹ · |F(1) F(0)|ᵀ

So computing F(n) is just computing M^(n−1).

This generalizes to any **linear recurrence**.

---

## **3. Binary Exponentiation for Matrices**

We use fast power:

If n is even:
Mⁿ = (M^(n/2))²

If n is odd:
Mⁿ = M × Mⁿ⁻¹

This reduces time from **O(n × k³)** to **O(log n × k³)**
(k = matrix dimension)

---

## **4. Visual Aid (Flow)**

Compute M⁸:

Level 0: M
↓ square
Level 1: M²
↓ square
Level 2: M⁴
↓ square
Level 3: M⁸

log₂(8) = 3 multiplications only.

---

## **5. Generic Process for Matrix Expo**

1. Convert recurrence into a transformation matrix
2. Build initial vector
3. Use fast exponentiation to compute Mⁿ
4. Multiply Mⁿ with initial vector
5. Extract answer

---

## **6. Pseudocode (No Code Block)**

function multiply(A, B):
create result matrix R
for i in rows of A:
for j in cols of B:
R[i][j] = Σ A[i][k] * B[k][j]
return R

function power(M, n):
if n == 1: return M
if n % 2 == 0:
half = power(M, n/2)
return multiply(half, half)
else:
return multiply(M, power(M, n-1))

---

## **7. Complexity**

| Operation                   | Time        |
| --------------------------- | ----------- |
| Matrix multiplication (k×k) | O(k³)       |
| Matrix exponentiation       | O(k³ log n) |
| Space                       | O(k²)       |

For Fibonacci: k = 2 → very fast.

---

## **8. Applications**

* Fibonacci / Tribonacci / k-nacci
* Counting paths of length n in graphs
* DP transitions (state machine DP)
* Linear recurrence problems in CP
* Modular recurrence problems

---

## **9. Common Recurrences Solvable via Matrix Expo**

| Recurrence          | Matrix Size |
| ------------------- | ----------- |
| Fibonacci           | 2×2         |
| Tribonacci          | 3×3         |
| General k-term      | k×k         |
| DP with k states    | k×k         |
| Graph walk counting | n×n         |

---

## **10. Interview Tips**

Expect questions like:

* “Compute F(n) for n up to 10¹⁸”
  → matrix exponentiation
* Convert recurrence into matrix
* Fast exponentiation logic
* When to use vs when DP is enough

FAANG loves mixing:

* DP + recurrence + matrix expo
* Very large n constraints

---

## **11. Practice Problems**

**LeetCode:**

* 70 — Climbing Stairs (can be solved with matrix expo)
* 509 — Fibonacci Number (large constraints version appears in contests)

**Codeforces:**

* DP with matrix transitions
* k-nacci variants
* Huge exponent recurrence problems

**GFG:**

* Matrix exponentiation basics
* Fibonacci in log(n)

---
