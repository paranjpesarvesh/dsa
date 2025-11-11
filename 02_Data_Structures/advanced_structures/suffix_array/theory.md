# Suffix Array — Complete Theory Guide

A **Suffix Array** is a powerful string data structure that stores the starting indices of all suffixes of a string in sorted (lexicographical) order.

It enables efficient solutions to problems involving substring search, pattern matching, repetitions, and string queries.

---

## 1. What is a Suffix Array?

Given a string:

```
s = "banana"
```

Its suffixes are:

| Index | Suffix |
| ----- | ------ |
| 0     | banana |
| 1     | anana  |
| 2     | nana   |
| 3     | ana    |
| 4     | na     |
| 5     | a      |

Sorted lexicographically:

| Rank | Suffix | Starting Index |
| ---- | ------ | -------------- |
| 0    | a      | 5              |
| 1    | ana    | 3              |
| 2    | anana  | 1              |
| 3    | banana | 0              |
| 4    | na     | 4              |
| 5    | nana   | 2              |

Thus the suffix array is:

```
SA = [5, 3, 1, 0, 4, 2]
```

---

## 2. Why Use Suffix Array?

**Key benefits:**

* Enables fast substring search
* Far less memory than suffix tree
* Easier to implement
* Works well with LCP array for many advanced queries

**Applications:**

* Fast pattern matching
* Longest repeated substring
* Number of distinct substrings
* Plagiarism detection
* Bioinformatics (DNA matching)
* Compression algorithms
* Full-text search engines

---

## 3. Mathematical Intuition

The suffix array is essentially a sorted permutation of numeric indices.

Core insight:

> Comparing two suffixes is same as comparing two substrings from positions i and j to the end.

Sorting suffixes lexicographically gives a global ordering of substrings.

### Why suffix array + LCP is powerful?

Because sorted suffixes cluster similar substrings together.

```
banana
a
ana
anana
banana
na
nana
```

Adjacent suffixes share long common prefixes → useful for many problems.

---

## 4. Construction Approaches

### A) Naive O(n^2 log n)

* Generate all suffixes
* Sort them
* Practical only for small strings

---

### B) Doubling Algorithm O(n log n)

Most commonly used in interviews.

Idea:

* Sort suffixes by first 1 char
* Sort by first 2 chars
* Sort by first 4 chars
* Sort by first 8 chars

At step k, compare suffixes (rank[i], rank[i + k]).

Stops when all ranks are unique.

Time: O(n log n)
Space: O(n)

---

### C) SA-IS / DC3 O(n)

Used in competitive programming and research.

Intuition:

* Classify characters into L-type and S-type
* Sort special LMS substrings
* Recursively construct SA

Time: O(n)
Space: O(n)

---

## 5. LCP Array (Kasai Algorithm)

LCP[i] = longest common prefix between suffix at SA[i] and SA[i−1].

Example for "banana":

Suffix array:

```
[5, 3, 1, 0, 4, 2]
```

LCP array:

```
[0, 1, 3, 0, 0, 2]
```

Explanation:

* LCP(“a”, “ana”) = 1
* LCP(“ana”, “anana”) = 3
* LCP(“anana”, “banana”) = 0
* LCP(“banana”, “na”) = 0
* LCP(“na”, “nana”) = 2

Kasai’s algorithm computes this in linear time O(n).

---

## 6. Pseudocode — Doubling Method

```
function buildSA(s):
    n = len(s)
    sa = [0..n-1]
    rank[i] = ord(s[i])

    k = 1
    while k < n:
        sort sa by (rank[i], rank[i+k] if exists else -1)
        tmp[sa[0]] = 0
        classes = 1
        for i in 1..n-1:
            if pair for sa[i] != pair for sa[i-1]:
                classes++
            tmp[sa[i]] = classes-1
        rank = tmp
        k *= 2

    return sa
```

---

## 7. Complexity Summary

| Operation           | Time Complexity |   |        |
| ------------------- | --------------- | - | ------ |
| Build SA (doubling) | O(n log n)      |   |        |
| Build LCP (Kasai)   | O(n)            |   |        |
| Search pattern P    | O(              | P | log n) |
| Distinct substrings | O(n) after SA   |   |        |

Space complexity: O(n)

---

## 8. Visual Representation

### Sorted suffixes flow:

```
Suffixes: banana
↓ sort
a
ana
anana
banana
na
nana
↓ extract indexes
[5,3,1,0,4,2]
```

### Adjacent comparison forms LCP:

```
         SA         LCP
-------------------------
 0:      a           0
 1:      ana         1
 2:      anana       3
 3:      banana      0
 4:      na          0
 5:      nana        2
```

---

## 9. Interview Tips

### What interviewers expect

* Understand concept
* Know how suffix array helps in substring search
* Able to explain LCP
* Know complexity of different approaches
* High-level intuition is more valuable than coding from memory

### What they DO NOT expect

* Ukkonen/SA-IS implementation
* Memory-optimized version
* Complete correctness proofs

---

## 10. Common Interview Questions

1. Construct a suffix array for a given string
2. Find number of distinct substrings
3. Find longest repeated substring
4. Check if a pattern exists in string
5. Count occurrences of a substring
6. Find longest common substring between two strings (via combined SA)

---

## 11. Practice Problems

### LeetCode

* Longest Duplicate Substring
* Repeated String Match (conceptual)
* Longest Palindromic Substring (knowledge helpful)

### Codeforces

* Suffix array problems in Div2 D/E
* Pattern matching problems

### GFG

* Suffix Array Construction
* LCP Array Construction
* Kasai Algorithm

---

## 12. Summary

* Suffix array provides sorted suffix indices
* LCP complements it to support powerful string queries
* Doubling method is interview-friendly
* Kasai algorithm builds LCP in linear time
* Together, SA + LCP unlock solutions to many advanced string problems

---
