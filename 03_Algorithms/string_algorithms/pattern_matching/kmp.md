# **Knuth–Morris–Pratt (KMP) Pattern Matching Algorithm**

---

## **1. What is KMP? (Short Definition)**

KMP is a **linear-time string matching algorithm** that avoids redundant comparisons by preprocessing the pattern using a **LPS array** (Longest Prefix which is also Suffix).

It improves over naïve matching (O(n·m)) to **O(n + m)**.

---

## **2. Why KMP Works (Intuition)**

When characters mismatch, naïve approach restarts from the next index in the text.
KMP asks:

> “Instead of starting over, can I reuse what I already matched?”

Yes — using the **LPS array**, which tells how many characters we can safely skip.

ASCII intuition:

```
Pattern:  a b a b a c
LPS:      0 0 1 2 3 0

Meaning:
At index 4 (a), we know prefix "ababa" has suffix "aba" → we reuse work.
```

---

## **3. LPS Array (Core of KMP)**

### What is LPS?

For each index `i` in pattern:

```
LPS[i] = length of longest proper prefix which is also a suffix
```

Example:

| i | P[i] | Prefix-Suffix Match | LPS |
| - | ---- | ------------------- | --- |
| 0 | a    | –                   | 0   |
| 1 | b    | –                   | 0   |
| 2 | a    | a                   | 1   |
| 3 | b    | ab                  | 2   |
| 4 | a    | aba                 | 3   |
| 5 | c    | –                   | 0   |

---

## **4. Build LPS Array (Step-by-Step)**

```
buildLPS(pattern):
    lps = array of size m initialized to 0
    len = 0
    i = 1

    while i < m:
        if pattern[i] == pattern[len]:
            len++
            lps[i] = len
            i++
        else:
            if len != 0:
                len = lps[len-1]
            else:
                lps[i] = 0
                i++

    return lps
```

---

## **5. KMP Search Algorithm (Step-by-Step)**

```
kmp(text, pattern):
    build LPS
    i = 0 (text index)
    j = 0 (pattern index)

    while i < n:
        if text[i] == pattern[j]:
            i++, j++
            if j == m:
                match found → j = lps[j-1]
        else:
            if j != 0:
                j = lps[j-1]
            else:
                i++
```

---

## **6. Visual Flow of KMP**

```
          ┌────────────────────────┐
          │ Build LPS array (m)    │
          └─────────────┬──────────┘
                        │
                        ▼
        ┌───────────────────────────────────┐
        │ Match text & pattern using LPS    │
        │ Skip mismatched characters smartly│
        └────────────────────┬──────────────┘
                             │
                             ▼
                     Pattern found?
```

---

## **7. Time & Space Complexity**

| Phase     | Complexity   |
| --------- | ------------ |
| Build LPS | O(m)         |
| Match     | O(n)         |
| **Total** | **O(n + m)** |
| Space     | O(m)         |

---

## **8. Edge Cases**

* Empty pattern → match at index 0
* Pattern longer than text → no match
* Repetitive patterns (aaa…aaa) → KMP handles best
* Case-sensitive unless normalized

---

## **9. Interview Tips**

* Most asked pattern-matching algorithm in interviews.
* Be ready to explain:
   Why LPS avoids re-checking characters
   How mismatch handling works
   Build LPS manually for small pattern
* Frequently compared with Rabin-Karp.

---

## **10. Practice Problems**

### **LeetCode**

* 28. Implement strStr()
* 214. Shortest Palindrome (uses reverse + KMP)
* 1392. Longest Happy Prefix

### **GFG**

* Search Pattern (KMP Algorithm)

### **Codeforces**

* Many string problems use LPS for prefix/suffix relations.

---

If you want, I can generate a complete C++/Python implementation file too.

