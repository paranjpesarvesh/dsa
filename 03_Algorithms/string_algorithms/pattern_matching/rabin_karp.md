# **Rabin–Karp Pattern Matching Algorithm**

---

## **1. Introduction**

**Rabin–Karp** is a string-searching algorithm that uses **hashing** to find a pattern in a text.
Instead of comparing the pattern with every window directly, it compares **hash values**, making it efficient in practice.

---

## **2. Core Idea (Mathematical Intuition)**

Use a **rolling hash function** to compute hash values of:

* the pattern `P`
* every substring (window) of text `T` of the same length

If the hash values match → verify with a direct comparison.

Rolling hash lets us update the hash in **O(1)** when sliding the window.

### Rolling hash formula (base `d`, modulo `M`):

```
hash = (sum(P[i] * d^(m-1-i))) % M
```

When sliding:

```
new_hash = (d * (old_hash - old_char * d^(m-1)) + new_char) % M
```

---

## **3. Step-by-Step Explanation**

1. Precompute hash of pattern `P`.
2. Compute hash of first window of text.
3. For each position:

   * If hashes match → verify characters.
   * Slide window using rolling hash.
4. Continue until end of text.

ASCII visualization:

```
Text:    A B A A B A A B
Pattern:     B A A

Window moves → hash updated → compare
```

---

## **4. Pseudocode**

```
rabinKarp(text, pattern):
    n = length(text)
    m = length(pattern)
    d = 256
    M = 1e9+7

    compute hash_p
    compute hash_t (first window)

    for i from 0 to n-m:
        if hash_p == hash_t:
            compare characters to confirm match
        if i < n-m:
            update rolling hash for next window
```

---

## **5. Time & Space Complexity**

| Case    | Time                            |
| ------- | ------------------------------- |
| Worst   | O(n·m) (due to hash collisions) |
| Average | O(n + m)                        |
| Best    | O(n + m)                        |

Space Complexity: **O(1)**

---

## **6. Hashing & Collisions**

* Rabin–Karp is efficient because collisions are rare using:

  * large modulus (`1e9+7`)
  * good base (`256`, `131`, etc.)
* If collision occurs → fallback to character comparison.

---

## **7. Variations**

* Multiple pattern search (very efficient!)
* Works well for plagiarism detection
* Polynomial rolling hash with double hashing
* 2D pattern matching (matrix pattern search)

---

## **8. Edge Cases**

* Empty pattern → match at index 0
* Pattern longer than text → no match
* High collision rate if poor modulus/base chosen
* Unicode characters need normalized hashing

---

## **9. Interview Tips**

* Often asked to compare with **KMP**:

  * KMP is worst-case linear
  * Rabin–Karp is great when hashing multiple patterns
* Common follow-up:

  * How rolling hash works?
  * How to avoid overflow?
  * Why verify after hash match?

Companies that ask this → **Google, Amazon, Microsoft**.

---

## **10. Practice Problems**

### **LeetCode**

* 28. Implement strStr() (Rabin–Karp version)
* 187. Repeated DNA Sequences

### **GFG**

* Rabin–Karp Algorithm
* Pattern Searching using Hashing

### **Codeforces**

* Many hashing-based problems (strings, prefix-hashes, collisions)

---
