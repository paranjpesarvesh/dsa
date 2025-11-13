# **Number Theory Basics**

---

## **1. Introduction**

Number theory deals with properties of integers.
In competitive programming, it includes:

* Divisibility
* Prime numbers
* Modular arithmetic
* GCD/LCM
* Inverses
* Factorization
* Euler’s Totient
* Modular exponentiation
* CRT

These form the foundation of most advanced math algorithms.

---

## **2. Divisibility**

**a divides b (a | b)** if:
b = a·k for some integer k

### Properties:

* If a | b and b | c → a | c
* If a | b and a | c → a | (bx + cy)

---

## **3. Prime & Composite Numbers**

**Prime**: divisible only by 1 and itself
**Composite**: has more than two divisors

Prime checking methods:

* Trial division (O(√n))
* Sieve of Eratosthenes (O(n log log n))
* Miller–Rabin (probabilistic but fast)

---

## **4. GCD & LCM**

* gcd(a, b) = largest common divisor
* lcm(a, b) = smallest multiple of both

Key relation:
lcm(a, b) = (a·b)/gcd(a, b)

Euclid algorithm: O(log n)

---

## **5. Modular Arithmetic**

For modulus m:

a ≡ b (mod m) if m divides (a − b)

### Important rules:

Addition:
(a + b) mod m
Multiplication:
(a × b) mod m
Exponentiation:
aᵇ mod m (use fast power)

---

## **6. Modular Inverse**

Solve:
a·x ≡ 1 (mod m)

Exists only when gcd(a, m) = 1

Methods:

* Extended Euclid → general
* Fermat’s theorem → prime modulus: x = a^(m−2) mod m

---

## **7. Euler’s Totient Function φ(n)**

Counts numbers ≤ n that are coprime to n.

For prime p:
φ(p) = p − 1

For general n with prime factorization:
n = p₁ᵉ¹ p₂ᵉ² …
φ(n) = n Π (1 − 1/pᵢ)

Used in:

* Euler’s generalization of Fermat
* RSA
* Counting co-primes

---

## **8. Fermat’s Little Theorem**

If p is prime and gcd(a, p)=1:

a^(p−1) ≡ 1 (mod p)

Used for modular inverse and exponentiation.

---

## **9. Chinese Remainder Theorem (CRT)**

Solves system:

x ≡ a₁ (mod m₁)
x ≡ a₂ (mod m₂)
…

If moduli are pairwise coprime → unique solution modulo M = m₁m₂…

Applications:

* Reconstructing large numbers
* Combining modular computations
* Factorization algorithms

---

## **10. Factorization Methods**

* Trial division → O(√n)
* Pollard Rho → fast for 64-bit numbers
* Sieve precomputation

Used for:

* Prime decomposition
* Divisor enumeration

---

## **11. Fast Exponentiation**

Binary exponentiation computes:
aᵇ mod m in O(log b)

Essential for all number theory operations.

---

## **12. Pseudocode Summary (No Code Blocks)**

# GCD

while b != 0: a, b = b, a % b

# Fast exponentiation

while b > 0:
if b odd: res = res * a % m
a = a * a % m
b //= 2

# Modular inverse (Fermat)

pow(a, m-2, m)

# Euler Totient with factorization

phi = n
for p|n: phi -= phi/p

---

## **13. Visual Aid: Relationships**

GCD → Modular inverse exists when gcd(a, m)=1
↓
Modular inverse → Needed for modular division
↓
Modular exponentiation → Used in primality + inverse
↓
Primality tests → Needed in factorization
↓
CRT → Uses inverses + modular arithmetic

Everything is interconnected.

---

## **14. Interview Tips**

FAANG commonly tests:

* Modular arithmetic
* Fast pow
* GCD / inverse
* Totient function basics
* CRT in advanced rounds

Be ready to:

* Handle very large numbers
* Avoid overflow
* Use mod efficiently
* Combine Euclid + fast power + inverse

---

## **15. Practice Problems**

**LeetCode:**

* 204 — Count Primes
* 50 — Pow(x, n)
* 372 — Super Pow

**GFG:**

* Number theory basics
* Euler totient
* Modular inverse
* CRT

**Codeforces:**

* Factorization
* Modular equations
* Primality testing
* Large arithmetic

---
