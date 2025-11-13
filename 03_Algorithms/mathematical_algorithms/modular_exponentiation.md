# **Modular Exponentiation (Fast Power / Binary Exponentiation)**

---

## **1. What Is Modular Exponentiation?**

Given integers **a**, **b**, **m**, compute:

aᵇ mod m

Naively → O(b) multiplications
Fast exponentiation → **O(log b)**

This is a fundamental operation used in:

* Cryptography (RSA, Diffie-Hellman)
* Primality tests (Miller–Rabin)
* Modular arithmetic DP
* Combinatorics (nCr mod M)
* Polynomial evaluation

---

## **2. Core Mathematical Idea**

Use the binary representation of exponent **b**:

b = (b₀ + 2b₁ + 4b₂ + …)

Then:

aᵇ = a^(2⁰)ᵇ⁰ · a^(2¹)ᵇ¹ · a^(2²)ᵇ² · …

Instead of multiplying **b** times, we repeatedly:

* square (a = a²)
* halve exponent (b = b/2)
* multiply when exponent bit is 1

---

## **3. Algorithm Flow (ASCII Visual)**

Compute a^13:

13 = 1101₂

Steps:

pow = 1
a = a
b = 1101

b LSB = 1 → pow *= a
b >>= 1, a = a²

b LSB = 0 → skip
b >>= 1, a = a⁴

b LSB = 1 → pow *= a⁴
b >>= 1, a = a⁸

b LSB = 1 → pow *= a⁸

Total operations = log₂(b)

---

## **4. Pseudocode (No Code Block)**

function modpow(a, b, m):
a = a % m
result = 1
while b > 0:
if b is odd:
result = (result * a) % m
a = (a * a) % m
b = b // 2
return result

---

## **5. Complexity Analysis**

| Operation   | Complexity |
| ----------- | ---------- |
| Each step   | O(1)       |
| Total steps | O(log b)   |
| Space       | O(1)       |

Excellent performance even for very large b (up to 10¹⁸+).

---

## **6. Variations**

### **1. Recursive Binary Exponentiation**

pow(a, b):
if b == 0: return 1
half = pow(a, b/2)
if b even: return half * half
else: return half * half * a

Add mod at each step.

### **2. Modular Inverse (when mod is prime)**

a^(m−2) mod m via Fermat’s Little Theorem.

### **3. Fast Power for Big Integers**

Works natively in Python.

---

## **7. Common Edge Cases**

* m = 1 → answer always 0
* b = 0 → return 1
* a ≥ m → reduce a first
* Negative a: convert to positive a mod m

---

## **8. Applications in DSA/CP**

* nCr computations using Fermat’s theorem
* Hashing (polynomial rolling hash)
* Modular multiplications in DP
* Large prime testing (Miller–Rabin)
* RSA encryption: c = mᵉ mod n
* Decryption: m = cᵈ mod n

---

## **9. Interview Tips**

Expect questions like:

* Compute aᵇ when b is very large
* Handle overflow with modular arithmetic
* Apply pow() in Miller–Rabin
* Explain binary exponentiation logic
* Use inverse = pow(a, m−2, m) for mod inverse

FAANG tests your ability to optimize brute-force exponential computation.

---

## **10. Practice Problems**

**LeetCode:**

* 50 — Pow(x, n)
* 372 — Super Pow

**GFG:**

* Modular exponentiation
* Modular inverse

**Codeforces:**

* Many number theory + modulo tasks
* nCr mod M problems

---
