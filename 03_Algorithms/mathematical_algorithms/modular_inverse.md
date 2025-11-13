# **Modular Inverse**
---

## **1. What Is a Modular Inverse?**

For integers **a** and **m**, the **modular inverse** of **a mod m** is a number **x** such that:

a · x ≡ 1 (mod m)

It exists **iff gcd(a, m) = 1**.

Example:
a = 3, m = 11
3 × 4 = 12 ≡ 1 (mod 11) → inverse = 4

---

## **2. When Do We Need Modular Inverses?**

Essential in:

* nCr computation modulo prime
* Modular division
* Fermat’s Little Theorem
* Hashing
* Cryptography
* Matrix exponentiation mod M
* Solving linear congruences
* Chinese Remainder Theorem

In competitive programming, modular inverse is used constantly.

---

## **3. Methods to Compute Modular Inverse**

---

## **✔ Method 1: Extended Euclidean Algorithm (General Case)**

Works when gcd(a, m) = 1, even if m is **not prime**.

Solves:
a·x + m·y = gcd(a, m) = 1

Then x is the inverse.

### Pseudocode (no code block)

function egcd(a, b):
if b == 0: return (a, 1, 0)
g, x1, y1 = egcd(b, a % b)
x = y1
y = x1 - (a // b) * y1
return (g, x, y)

function modInverse(a, m):
g, x, _ = egcd(a, m)
if g != 1: return "No inverse"
return (x % m)

---

## **✔ Method 2: Fermat’s Little Theorem (Prime Modulus Only!)**

If m is prime:

a^(m−1) ≡ 1 (mod m)

Multiply both sides by a^(−1):

a^(m−2) ≡ a^(−1) (mod m)

Thus:

inverse = a^(m−2) mod m
(compute using fast exponentiation)

---

## **✔ Method 3: Precomputation Using Prefix Inverses**

For all inverses from 1..n under prime modulus:

inv[1] = 1
inv[i] = (m − m/i) * inv[m % i] mod m

Works in O(n) time.

Used in modular combinatorics.

---

## **4. Visual Intuition (Diagram)**

Suppose modulus m = 7:

Numbers:     1 2 3 4 5 6
Products:    a×1 a×2 a×3 a×4 a×5 a×6
Goal: find product ≡ 1 mod 7

If a = 3:

3×1 = 3
3×2 = 6
3×3 = 9 ≡ 2
3×4 = 12 ≡ 5
3×5 = 15 ≡ 1  ← found inverse
3×6 = 18 ≡ 4

Inverse is value whose multiplication cycles back to 1.

---

## **5. Complexity Analysis**

| Method              | Time     | Space |
| ------------------- | -------- | ----- |
| Extended Euclid     | O(log m) | O(1)  |
| Fermat (pow)        | O(log m) | O(1)  |
| Precompute inverses | O(n)     | O(n)  |

---

## **6. Edge Cases**

* If gcd(a, m) ≠ 1 → inverse does NOT exist
* a = 0 → no inverse
* Negative a → use (a % m + m) % m first

---

## **7. Applications in Problems**

* nCr mod prime
* Modular division (x / y mod M = x·inv(y) mod M)
* Solving linear congruence equations
* Matrix inverse in modulo arithmetic
* Polynomial multiplications
* Hashing, rolling hash updates

---

## **8. Interview Tips**

Expect questions like:

* “Find modular inverse of a under mod 1e9+7”
* “Implement extended Euclid + mod inverse”
* “When does modular inverse not exist?”
* “Why Fermat’s theorem only works for prime modulus?”

FAANG checks if you:

* Understand gcd requirement
* Know Fermat-based inverse pattern
* Apply fast exponentiation confidently
* Handle large modulo arithmetic

---

## **9. Practice Problems**

**LeetCode:**

* Uses modular inverses in mathematical problems indirectly

**GFG:**

* Modular inverse
* Using Fermat to compute nCr

**Codeforces:**

* Heavy use in combinatorics
* nCr modulo prime
* Modular division tasks

---
