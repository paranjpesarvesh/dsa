# **Miller–Rabin Primality Test**

---

## **1. What Is the Miller–Rabin Test?**

Miller–Rabin is a **probabilistic primality test** that determines if a number **n** is prime in **O(k · log³ n)** time.

It is widely used because:

* Extremely fast for large numbers (64-bit, 128-bit)
* Deterministic for 64-bit integers with a small base set
* Used in cryptography, RSA key generation

---

## **2. Mathematical Foundation (Intuition)**

For an odd number **n > 2**, write:

n − 1 = 2ˢ · d
with d odd.

Miller–Rabin checks whether a randomly chosen base **a** is a **witness** to n being composite.

The test relies on properties of **modular exponentiation** and **Fermat’s Little Theorem**:

If n is prime →
a^(n−1) ≡ 1 (mod n)

But MR strengthens this by checking **square chains**:

aᵈ, a^(2d), a^(4d), ..., a^(2ˢd)

If values don’t hit 1 or n−1 at the right places → n is composite.

---

## **3. Algorithm Overview**

Given n and base a:

1. Compute n−1 = 2ˢ · d
2. Compute x = aᵈ mod n
3. If x == 1 or x == n−1 → **probably prime**
4. Repeat s−1 times:

   * x = x² mod n
   * If x == n−1 → **probably prime**
5. Otherwise → **composite**

Repeating with multiple bases reduces error probability exponentially.

---

## **4. Visual Flow (ASCII)**

Check n:

n−1 = 2ˢ × d
↓
Compute aᵈ mod n
↓
x = aᵈ
↓
If x = 1 or n−1 → pass
Else
Loop s−1 times:
x = x² mod n
If x = n−1 → pass
Else continue
If none hit → composite

---

## **5. Deterministic Base Sets**

For 32-bit integers → test bases: {2, 7, 61}

For 64-bit integers → test:

{2, 325, 9375, 28178, 450775, 9780504, 1795265022}

This makes MR **perfectly accurate** for all 64-bit numbers.

---

## **6. Pseudocode (No Code Block)**

function miller_rabin(n):
if n < 4: return n == 2 or n == 3
write n−1 = 2ˢ * d
for each base a in test_bases:
x = pow(a, d, n)
if x == 1 or x == n−1: continue
repeat s−1 times:
x = (x * x) mod n
if x == n−1: break
else:
return composite
return probably_prime

---

## **7. Complexity**

| Task                | Time        |
| ------------------- | ----------- |
| Fast exponentiation | O(log n)    |
| One base test       | O(log³ n)   |
| k rounds            | O(k log³ n) |

For deterministic 64-bit → k = 7 (constant).

---

## **8. Edge Cases**

* n = 1, 0 → composite
* n = 2, 3 → prime
* Even numbers > 2 → composite
* Avoid overflow (use 128-bit intermediate or modular multiply)

---

## **9. Applications**

* Cryptography (RSA key generation)
* Competitive programming (handling large n)
* Prime testing when n > 10¹²
* Pollard Rho factorization (combined with MR)

---

## **10. Interview Tips**

Interviewers expect:

* Knowledge of FLT: a^(p−1) ≡ 1 mod p
* Why deterministic bases exist
* Why MR is much faster than trial division
* Understanding of witness vs strong liar

FAANG may combine questions:

* Large prime checking
* Modular exponentiation
* Randomized algorithms

---

## **11. Practice Problems**

**LeetCode:**

* None directly; appears in large-number math problems

**Codeforces:**

* Prime checking for n up to 10¹⁸
* Combined with Pollard Rho for factorization

**GFG:**

* Primality test for large numbers
* Modular exponentiation tasks

---
