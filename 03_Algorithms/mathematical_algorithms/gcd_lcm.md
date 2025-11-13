# **GCD & LCM (Greatest Common Divisor & Least Common Multiple)**

---

## **1. What Is GCD?**

**GCD(a, b)** is the largest integer that divides both **a** and **b**.

Examples:
gcd(12, 18) = 6
gcd(7, 13) = 1 (coprime)

---

## **2. Euclidean Algorithm (Core Idea)**

The key identity:

gcd(a, b) = gcd(b, a mod b)

This works because:

a = bq + r → any divisor of (a, b) must also divide r.

### **Termination condition**

gcd(a, 0) = a

This gives a very fast algorithm.

---

## **3. Euclidean Algorithm – Step-by-Step**

To compute gcd(48, 18):

48 % 18 = 12
18 % 12 = 6
12 % 6 = 0
→ gcd = 6

---

## **4. Pseudocode (No Code Block)**

function gcd(a, b):
while b != 0:
temp = a % b
a = b
b = temp
return a

---

## **5. Extended Euclidean Algorithm**

Solves the equation:

ax + by = gcd(a, b)

Returns (gcd, x, y)

Used in:

* Modular inverse
* CRT
* Solving Diophantine equations

---

## **6. Mathematical Identities**

### **Properties of GCD**

* gcd(a, b) = gcd(b, a mod b)
* gcd(a, 0) = |a|
* gcd(a, b) = gcd(|a|, |b|)
* gcd(a, b, c) = gcd(gcd(a, b), c)

### **GCD and LCM Relationship**

LCM(a, b) = |a · b| / gcd(a, b)

Used very frequently in CP.

---

## **7. What Is LCM?**

**LCM(a, b)** is the smallest positive integer divisible by both:

Example:
lcm(4, 6) = 12
lcm(5, 7) = 35

---

## **8. LCM Pseudocode**

(No code block)

function lcm(a, b):
return a / gcd(a, b) * b

Always divide before multiply to avoid overflow.

---

## **9. Complexity**

| Algorithm    | Complexity                 |
| ------------ | -------------------------- |
| Euclid GCD   | **O(log min(a,b))**        |
| Extended GCD | **O(log n)**               |
| LCM          | uses gcd → same complexity |

Space: O(1)

---

## **10. Edge Cases**

* gcd(0, 0) → undefined
* gcd(a, 0) → |a|
* Negative numbers → gcd always positive
* Very large numbers → use long long / Python big ints

---

## **11. Applications**

* Modular arithmetic
* Number theory
* Cryptography (RSA)
* Reducing fractions
* Cycle problems
* Periodic tasks scheduling (LCM)
* CRT + modular inverse

---

## **12. Interview Tips**

Expect questions:

* Implement gcd & lcm
* Find gcd of array (reduce technique)
* Use gcd for simplifying ratios
* Use gcd to detect cycle periods
* Modular inverse using extended gcd

FAANG may combine GCD with:

* Math + DP
* CRT
* LCM scheduling
* Graph problems with gcd-weighted edges

---

## **13. Practice Problems**

**LeetCode:**

* 365 — Water and Jug Problem
* 1979 — Find Greatest Common Divisor of Array

**GFG:**

* GCD of two numbers
* LCM & GCD of arrays

**Codeforces:**

* Problems involving modular arithmetic
* GCD-sum problems
* LCM cycle detection

---
