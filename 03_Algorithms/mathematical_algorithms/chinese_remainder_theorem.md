# **Chinese Remainder Theorem (CRT)**

---

## **1. What Is CRT?**

The **Chinese Remainder Theorem** gives a way to solve systems of simultaneous congruences of the form:

x ≡ a₁ (mod m₁)
x ≡ a₂ (mod m₂)
...
x ≡ aₖ (mod mₖ)

CRT guarantees a **unique solution modulo M**, where:

M = m₁ × m₂ × ... × mₖ
(if all moduli are pairwise **coprime**)

---

## **2. Intuition Behind CRT**

Each congruence restricts x to a certain “pattern”.

Example:

x ≡ 2 (mod 3) → x ∈ {2,5,8,11…}
x ≡ 3 (mod 5) → x ∈ {3,8,13,18…}

The value **8** appears in both lists → solution.

CRT gives a fast constructive method to compute this WITHOUT enumerating values.

---

## **3. When Moduli Are Coprime**

If gcd(mᵢ, mⱼ) = 1:

Unique solution exists mod M.

General formula:

x = Σ [ aᵢ * Mᵢ * inv(Mᵢ mod mᵢ) ]
where:

M = product of all mᵢ
Mᵢ = M / mᵢ
inv() = modular inverse of Mᵢ under mᵢ

---

## **4. Step-by-Step Method**

System:
x ≡ a₁ (mod m₁)
x ≡ a₂ (mod m₂)
…
x ≡ aₖ (mod mₖ)

### **Step 1**

Compute M = m₁ m₂ … mₖ

### **Step 2**

For each congruence:

Mᵢ = M / mᵢ
Find inverse yᵢ = Mᵢ⁻¹ mod mᵢ
(this uses Extended Euclid)

### **Step 3**

Compute term:

Tᵢ = aᵢ * Mᵢ * yᵢ

### **Step 4**

Final answer:

x = (T₁ + T₂ + ... + Tₖ) mod M

---

## **5. ASCII Illustration**

Example:

x ≡ 1 (mod 2)
x ≡ 2 (mod 3)
x ≡ 3 (mod 5)

M = 30

M₁ = 15, inv(15 mod 2) = 1
M₂ = 10, inv(10 mod 3) = 1
M₃ = 6,  inv(6 mod 5)  = 1

x = 1*15*1 + 2*10*1 + 3*6*1
x = 15 + 20 + 18 = 53
x ≡ 23 (mod 30)

Solution: **23**

---

## **6. Pseudocode (No Code Block)**

M = product(moduli)

result = 0

for each i:
Mi = M / mi
yi = inverse(Mi mod mi)
result += ai * Mi * yi

return result % M

---

## **7. Modular Inverse**

For coprime m:

inverse(a mod m) = number y s.t. (a*y) % m = 1

Compute using:

* Extended Euclidean Algorithm
* Fermat’s little theorem (if m is prime)

---

## **8. Non-Coprime Case (General CRT)**

If moduli are **not pairwise coprime**:

System has solution **only if**:

aᵢ ≡ aⱼ (mod gcd(mᵢ, mⱼ))

Example:

x ≡ 2 (mod 4)
x ≡ 6 (mod 8)

Valid because 2 ≡ 6 (mod 2).
Solution exists.

General CRT uses reduction + EEA to merge congruences incrementally.

---

## **9. Complexity Analysis**

| Part                                  | Complexity     |
| ------------------------------------- | -------------- |
| Modular inverse using extended Euclid | O(log m)       |
| Loop for each congruence              | O(k log M)     |
| **Total**                             | **O(k log M)** |

Space: O(1) or O(k)

---

## **10. Applications of CRT**

* Competitive programming modulo arithmetic
* Multi-modulo computations (e.g., double hashing)
* Number theory problems
* RSA cryptography (speedup)
* Calendar problems
* Scheduling repeating events

---

## **11. Interview Tips**

Interviewers expect:

* Understanding of constructive CRT
* Knowing when CRT guarantees uniqueness
* Ability to compute modular inverses
* Handling non-coprime cases
* Applying CRT in modulus-splitting problems (e.g., mod 1e9+7 * mod 1e9+9)

FAANG rarely asks full CRT derivations, but expects:

* Ability to solve simple congruence systems
* Implement CRT template cleanly

---

## **12. Practice Problems**

**LeetCode:**

* 365 — Water and Jug Problem (number theory)
* 204 — Count Primes (not CRT but modular concepts helpful)

**GFG:**

* Chinese Remainder Theorem
* Modular inverse using EEA

**Codeforces:**

* Problems mixing modular arithmetic + CRT
* CRT applications in hashing / combinatorics

---
