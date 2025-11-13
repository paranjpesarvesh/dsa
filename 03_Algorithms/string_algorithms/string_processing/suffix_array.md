# **Suffix Array — Complete Theory**

---

## **1. What is a Suffix Array?**

A **Suffix Array** is a sorted array of all suffixes of a string.

Example:
S = **banana**

Suffixes:

| Index | Suffix |
| ----- | ------ |
| 0     | banana |
| 1     | anana  |
| 2     | nana   |
| 3     | ana    |
| 4     | na     |
| 5     | a      |

Sorted lexicographically:

| Rank | Suffix | SA Value |
| ---- | ------ | -------- |
| 0    | a      | 5        |
| 1    | ana    | 3        |
| 2    | anana  | 1        |
| 3    | banana | 0        |
| 4    | na     | 4        |
| 5    | nana   | 2        |

Suffix Array = **[5, 3, 1, 0, 4, 2]**

---

## **2. Why is it useful?**

Suffix Arrays enable efficient solutions for:

* Pattern searching (**O(m log n)**)
* Longest Common Prefix (LCP)
* Longest Repeated Substring
* String comparisons
* Used in **bioinformatics**, **data compression**, **search engines**

Often paired with:

* **LCP Array**
* **Kasai’s Algorithm**
* **Binary search over suffixes**

---

## **3. Mathematical Intuition**

We want to sort all suffixes:

```
banana
anana
nana
ana
na
a
```

Sorting strings directly → costly.

So we sort by **rank pairs**:

For doubling K:

* First sort based on first K characters
* Then based on first 2K
* Then first 4K
* … until K ≥ n

This gives **O(n log n)** construction.

---

## **4. ASCII Visualization**

```
b a n a n a
0 1 2 3 4 5

Suffixes:
0: banana
1:  anana
2:   nana
3:    ana
4:     na
5:      a
```

Sorted view:

```
a (5)
ana (3)
anana (1)
banana (0)
na (4)
nana (2)
```

---

## **5. Construction Approaches**

### **A. Naive Sorting — O(n² log n)**

Sort suffix strings directly.

### **B. Doubling Algorithm — O(n log n)** (Most common)

Store ranks like:

```
suffix index | rank[i] | rank[i+k]
```

Then sort by these pairs repeatedly with k = 1, 2, 4, ...

### **C. SA-IS — O(n)**

Advanced, used in libraries (not needed for interviews).

---

## **6. Doubling Algorithm — Pseudocode**

```
build_suffix_array(s):
    n = len(s)
    SA = [0..n-1]
    rank[i] = s[i]  // initial rank by char

    k = 1
    while k < n:
        sort SA by (rank[i], rank[i+k] if i+k<n else -1)

        tmp = array of size n
        tmp[SA[0]] = 0

        for i in 1..n-1:
            if pair(SA[i]) == pair(SA[i-1]):
                tmp[SA[i]] = tmp[SA[i-1]]
            else:
                tmp[SA[i]] = tmp[SA[i-1]] + 1

        rank = tmp
        k = k * 2

    return SA
```

---

## **7. Complexity**

| Stage                             | Time           |
| --------------------------------- | -------------- |
| Ranking and sorting per iteration | O(n log n)     |
| Number of iterations              | O(log n)       |
| **Total**                         | **O(n log n)** |

Space: **O(n)**

---

## **8. Edge Cases**

* String of all identical chars: "aaaaa"
* Very large strings (efficient memory needed)
* Unicode / multi-byte characters

Suffix Array handles all well.

---

## **9. Interview Tips**

* You MUST know:

  * Sorting suffixes directly is too slow
  * Use rank-doubling approach
  * SA + LCP = powerful combination
* Typical questions:

  * Find longest repeated substring
  * Count distinct substrings
  * Pattern searching
  * Find lexicographically smallest rotation

FAANG usually tests LCP + Suffix Array usage.

---

## **10. Practice Problems**

### **LeetCode**

* Hard: **Suffix Array not asked directly**, but related:

  * 1163. Last Substring in Lexicographical Order
  * 1044. Longest Duplicate Substring (Suffix Array + LCP)

### **GFG**

* Construct Suffix Array
* Pattern Searching using SA
* LCP Array Construction

### **Codeforces**

* Many problems under "String" tag requiring SA/LCP
* Famous problems:

  * EDU segment on suffix structures
  * Distinct substrings tasks

---
