# **Mathematical Algorithms – Overview & Guide**

Mathematical algorithms form the backbone of many competitive-programming and interview problems. They are essential whenever you deal with:

* Large numbers
* Prime-related computations
* Modular arithmetic
* Fast exponentiation
* Combinatorics
* Number theory
* Polynomials
* Recurrences

This directory collects the most important mathematical tools you will ever use in DSA.

---

# **1. Topics Covered**

### **✓ Number Theory Fundamentals**

* Divisibility
* Primes & composite numbers
* Modular arithmetic
* GCD & LCM
* Modular inverse
* Totient function
* CRT (Chinese Remainder Theorem)

### **✓ Fast Arithmetic**

* Modular exponentiation
* Fast power (binary exponentiation)
* Fast multiplication (FFT)
* Big integer tricks

### **✓ Prime-Testing & Factorization**

* Sieve of Eratosthenes
* Segmented sieve
* Miller–Rabin primality
* Pollard Rho (advanced)

### **✓ Recurrences & Matrices**

* Matrix exponentiation
* Linear recurrence solutions
* Fibonacci in log(n)

### **✓ Combinatorics**

* nCr modulo prime
* Factorial precomputation
* Modular inverse + combinatorics
* Catalan numbers
* Stars & bars

---

# **2. How to Use These Files**

Each file in this folder follows a consistent structure:

* Definitions & intuition
* Step-by-step derivations
* Clean pseudocode
* CP-friendly templates
* Complexity analysis
* Variations & caveats
* Interview guidance
* Practice problems

This ensures you **learn the concept**, **understand the math**, and **apply it quickly** during contests or interviews.

---

# **3. Quick Visual Map**

```
Number Theory
 ├── gcd_lcm
 ├── modular_exponentiation
 ├── modular_inverse
 ├── number_theory_basics
 ├── chinese_remainder_theorem (future)
 │
Primes
 ├── sieve_of_erastothenes
 ├── miller_rabin_primality
 ├── pollard_rho (future)
 │
Combinatorics
 ├── combinatorics
 ├── factorials + nCr (future)
 │
Recurrences
 ├── matrix_exponentiation
 │
Polynomials
 ├── fast_fourier_transform
```

This structure gives you a high-level roadmap.

---

# **4. Frequently Used Techniques**

### **Binary Exponentiation**

Essential for modular inverse, primality tests, DP transitions.

### **Sieve + SPF**

Precompute primes + smallest prime factors → fast factorization.

### **Extended Euclid**

General modular inverse. Works for any modulus.

### **Fermat’s Little Theorem**

Used for mod inverse in prime modulus (like 1e9+7).

### **FFT**

Fast polynomial multiplication in O(n log n).

### **Matrix Exponentiation**

Compute the k-th term of a recurrence in O(log n).

---

# **5. Interview Tips**

* Most FAANG math problems reduce to:

  * fast exponentiation
  * modular arithmetic
  * combinatorics
  * GCD + Euclid
* Google/Amazon often embed number theory inside DP/graph problems.
* Matrix exponentiation is common for “large n” recurrence questions.
* Understanding prime generation & factorization helps with memory/time-bound problems.

---

# **6. Practice Recommendations**

### **Start here**

* modular_exponentiation
* gcd_lcm
* sieve_of_erastothenes

### **Then learn**

* modular_inverse
* number_theory_basics
* combinatorics

### **Finally master**

* miller_rabin_primality
* fast_fourier_transform
* matrix_exponentiation

These form the complete toolkit needed for Codeforces 1200–2000 level and most interviews.

---
