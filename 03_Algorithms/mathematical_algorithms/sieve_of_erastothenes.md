# **Sieve of Eratosthenes**

---

## **1. What Is the Sieve of Eratosthenes?**

The **Sieve of Eratosthenes** is an algorithm to find all prime numbers up to **N** in **O(N log log N)** time.

It is one of the most fundamental number theory algorithms in CP.

---

## **2. Core Intuition**

Every composite number **n** has a **prime factor ≤ √n**.

So we:

1. Assume all numbers are prime
2. Start from the first prime (2)
3. Eliminate all multiples of 2
4. Move to the next unmarked number
5. Repeat until √N

---

## **3. Step-by-Step Explanation**

Let N = 20:

Start: all unmarked
2 → remove 4, 6, 8, 10, …
3 → remove 6, 9, 12, 15, 18
4 → already composite (skip)
5 → remove 10, 15, 20
… continue until √20 ≈ 4.47

Remaining unmarked = primes.

---

## **4. ASCII Diagram (N = 30)**

Numbers:
2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30

Strike out multiples:

2 → _  _  ✗  _  ✗  _  ✗  _  ✗  _ ...
3 → _  _  ✗  _  ✗  _  ✗  _  ✗  _ ...

Left:
2, 3, 5, 7, 11, 13, 17, 19, 23, 29

---

## **5. Pseudocode (No Code Block)**

function sieve(N):
prime = array of boolean size N+1, initialized true
prime[0] = prime[1] = false
for p = 2 to sqrt(N):
if prime[p] == true:
for i = p*p to N step p:
prime[i] = false
return prime

---

## **6. Complexity**

| Operation | Complexity         |
| --------- | ------------------ |
| Time      | **O(N log log N)** |
| Space     | **O(N)**           |

This is extremely efficient for N up to 10⁷–10⁸ in contests.

---

## **7. Optimizations**

### **1. Start from p²**

Multiples < p² already marked by smaller primes.

### **2. Bitset for memory reduction**

Useful for N up to 10⁸.

### **3. Segmented Sieve**

For ranges like:
10⁹ … 10⁹ + 10⁶
Memory-efficient.

### **4. Linear Sieve (O(N))**

Finds primes and smallest prime factors (SPF).

---

## **8. Applications**

* Prime number generation
* Precompute smallest prime factor (SPF)
* Prime factorization in O(log n)
* Totient function
* Count primes
* Building prefix arrays for range queries
* Used in number-theory heavy CF problems

---

## **9. Common Variants**

### **Linear Sieve (Euler Sieve)**

Produces:

* list of primes
* spf[i] → smallest prime factor

Time: O(N)

### **Segmented Sieve**

Find primes in a huge range [L, R].
Useful when R > 10⁷.

---

## **10. Interview Tips**

You might be asked:

* Implement sieve up to N = 10⁷
* Modify sieve to store spf[]
* Count primes ≤ N
* Print all primes in a given range
* Explain time complexity (why N log log N?)

FAANG rarely asks implementation but tests your intuition about primality and factorization.

---

## **11. Practice Problems**

**LeetCode:**

* 204 — Count Primes
* 263 — Ugly Number (factorization insight)

**GFG:**

* Sieve of Eratosthenes
* Segmented sieve problems

**Codeforces:**

* Range prime queries
* SPF-based factorization tasks
* Number-theory rounds (Div 2, Div 1)

---
