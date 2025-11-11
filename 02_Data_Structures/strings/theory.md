# Strings — Theory

Strings are one of the most important and frequently tested data structures in technical interviews. mastery over string manipulation techniques, pattern matching algorithms, hashing, and dynamic programming helps solve a large class of problems efficiently.

This document provides conceptual depth, practical intuition, and interview-oriented guidance.

---

## 1. What Is a String?

A **string** is an ordered sequence of characters stored contiguously in memory.

Examples:

* "hello"
* "abc123"
* "racecar"

Internally, a string behaves like an array of characters:

```
Index: 0 1 2 3 4
Value: h e l l o
```

---

## 2. Core Characteristics

### 2.1 Mutability

| Language | Mutability | Behavior                       |
| -------- | ---------- | ------------------------------ |
| Python   | Immutable  | Any change creates a new copy  |
| C++      | Mutable    | In-place modifications allowed |

### 2.2 Encoding

* ASCII → 1 byte/character
* UTF-8 → variable-length encoding
* Python strings are Unicode
* C++ `std::string` stores bytes but is agnostic to encoding

---

## 3. Basic Operations on Strings

### Accessing characters

O(1)

### Concatenation

* Python: O(n)
* C++: amortized O(1)

### Substring extraction

O(k) where k is substring size

### Comparing strings

O(n)

---

## 4. Important Concepts and Techniques

### 4.1 Two-Pointer Technique

Used for:

* reversing strings
* palindrome checks
* merging or splitting string segments

Diagram:

```
i ---> h e l l o <--- j
```

### 4.2 Sliding Window Technique

Used for:

* longest substring without repeating characters
* minimum window substring
* substring frequency-based matching

Window expands and shrinks intelligently.

```
[ left .......... right ]
```

### 4.3 Hashing

Key applications:

* Rabin–Karp
* string comparison
* checking anagrams
* frequency matching
* rolling hash

Rolling hash intuition:

```
hash = Σ (s[i] * base^i) mod M
```

### 4.4 Prefix/Failure Array (KMP)

Helps preprocess pattern in O(n) and avoid re-checking characters.

Example for pattern "abacab":

```
chars:  a b a c a b
lps  :  0 0 1 0 1 2
```

### 4.5 Tries

Useful for:

* dictionary search
* autocomplete
* prefix search
* multi-pattern matches (Aho-Corasick)

---

## 5. Advanced String Structures

### 5.1 Suffix Array

An array of indexes representing sorted suffixes.

Example string: “banana”

Suffixes in lexicographic order:

```
a
ana
anana
banana
na
nana
```

Suffix array: [5, 3, 1, 0, 4, 2]

### 5.2 Suffix Tree

A compressed trie of all suffixes.
Allows substring search in O(m).

### 5.3 Z-Array

Z[i] = length of longest prefix starting at i.

Useful for:

* pattern matching
* periodic string detection

---

## 6. Common Interview Problems

### Palindrome Problems

* longest palindromic substring
* valid palindrome with one removal
* expand-around-center technique

### Anagram Problems

* group anagrams
* check if anagram
* sliding window frequency tracking

### Substring Problems

* minimum window substring
* longest substring without repeating characters
* count distinct substrings

### Pattern Matching

* string search (KMP)
* Rabin-Karp
* Z-algorithm

### DP-Based Problems

* edit distance
* longest palindromic subsequence
* wildcard/regex matching

---

## 7. Pseudocode Templates

### Palindrome Check

```
function isPalindrome(s):
    left = 0
    right = len(s)-1
    while left < right:
        if s[left] != s[right]:
            return false
        left++, right--
    return true
```

### KMP Prefix Array

```
lps = array of size n
len = 0
for i from 1 to n-1:
    while len > 0 and s[i] != s[len]:
        len = lps[len-1]
    if s[i] == s[len]:
        len++
    lps[i] = len
```

---

## 8. Complexity Overview

| Task                     | Complexity                      |
| ------------------------ | ------------------------------- |
| Access character         | O(1)                            |
| Concatenate              | Python O(n), C++ amortized O(1) |
| Substring search (naive) | O(n*m)                          |
| KMP                      | O(n+m)                          |
| Rabin-Karp               | O(n+m) expected                 |
| Z algorithm              | O(n)                            |
| Prefix function          | O(n)                            |
| Build suffix array       | O(n log n)                      |
| Build suffix tree        | O(n)                            |

---

## 9. Edge Cases to Consider

* empty string
* very long strings (10^5 to 10^6)
* case sensitivity
* Unicode-specific characters
* leading/trailing spaces
* special characters
* repeated characters
* multiple spaces between words

---

## 10. Interview Tips

* Know sliding window well
* Understand KMP deeply (prefix table logic)
* Understand frequency tables
* Avoid brute force unless input is small
* Explain time/memory trade-offs
* Practice edge case thinking
* Mention Unicode considerations if applicable

---

## 11. Practice Problems

### Easy

* Valid Anagram
* Reverse String
* First Unique Character
* Implement strStr

### Medium

* Longest Substring Without Repeating Characters
* Longest Palindromic Substring
* Minimum Window Substring
* Group Anagrams

### Hard

* Edit Distance
* Regular Expression Matching
* Distinct Subsequences
* Count Different Substrings
* Suffix Array Construction Problems

---

## 12. Summary

String problems rely on:

* strong intuition
* efficient pattern matching
* clever window techniques
* hashing
* dynamic programming
* prefix/suffix manipulations
* memory-conscious approaches

This section establishes strong theoretical foundations for mastering string-related problem-solving.

