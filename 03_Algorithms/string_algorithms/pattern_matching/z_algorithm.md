# **Z-Algorithm (Pattern Matching)**

---

## **1. Introduction**

The **Z-Algorithm** is a linear-time string pattern matching technique.
It computes an auxiliary array **Z[]** where:

```
Z[i] = length of longest substring starting at i
       that matches prefix of the string
```

By building the string `P + $ + T`, we can detect pattern matches in text using Z-values.

---

## **2. Why Z-Algorithm Works (Intuition)**

Given string:

```
S = P$T
```

If at position `i`:

```
Z[i] == length(P)
```

→ Pattern `P` occurs in `T` at position `i - len(P) - 1`.

Z-array helps skip repeated comparisons using a **sliding window [L, R]** that stores the rightmost matched prefix segment.

ASCII intuition:

```
Prefix: a b a a b
Index : 0 1 2 3 4

Z[i] tells: how many characters match S[0...]
```

---

## **3. How Z-Array Is Computed**

We maintain a window `[L, R]` such that:

```
S[L ... R] is a prefix of S
```

For each index `i`:

1. If `i > R` → start fresh matching.
2. Else → reuse values from Z[i-L] if possible.
3. Extend match beyond R if characters allow.

This reduces comparisons and ensures **O(n)** runtime.

---

## **4. Pseudocode**

```
computeZ(S):
    n = len(S)
    Z = array of size n
    L = R = 0

    for i from 1 to n-1:
        if i > R:
            L = R = i
            while R<n and S[R-L] == S[R]:
                R++
            Z[i] = R-L
            R--
        else:
            k = i - L
            if Z[k] < R-i+1:
                Z[i] = Z[k]
            else:
                L = i
                while R<n and S[R-L] == S[R]:
                    R++
                Z[i] = R-L
                R--

    return Z
```

Pattern matching:

```
Z on string P + '$' + T
If any Z[i] == len(P), match found.
```

---

## **5. Complexity Analysis**

| Type  | Complexity |
| ----- | ---------- |
| Time  | O(n + m)   |
| Space | O(n + m)   |

* n = text length
* m = pattern length

---

## **6. Edge Cases**

* Empty pattern → match at index 0.
* Repeated patterns → Z handles efficiently.
* Unique separator `$` must not appear in input.

---

## **7. Variations / Uses**

* Fast pattern matching
* Finding longest repeated substring
* Computing prefix-function-like behavior
* String compression
* DNA sequence analysis

---

## **8. Z-Algorithm vs. KMP**

| Feature  | Z-Algorithm                | KMP               |
| -------- | -------------------------- | ----------------- |
| Approach | Prefix match lengths       | Failure function  |
| Ease     | More intuitive             | More mathematical |
| Use-case | String analysis & matching | Pure matching     |

---

## **9. Interview Tips**

* Frequently asked in **Google, Amazon, Adobe, Codeforces**.
* They ask:

  * Build Z-array manually for a given string.
  * Compare Z with prefix-function (π array).
  * Implement pattern matching using Z.
  * Identify corner cases (separator, indexing).

---

## **10. Practice Problems**

### **LeetCode**

* Implement strStr() (Z version)
* Longest Happy Prefix

### **GFG**

* Z-Algorithm for Pattern Searching
* Z-array construction

### **Codeforces**

* Many Div2C/Div2D problems use Z/KMP
  (string borders, repetitions, periodicity)

---
