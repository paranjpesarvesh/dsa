# Strings — Overview

Strings are one of the most fundamental data structures in computer science. They represent sequences of characters and are widely used in text processing, pattern matching, hashing, dynamic programming, and various interview problems.

This section will give you a conceptual and practical roadmap for mastering string operations, algorithms, and problem patterns frequently asked in interviews.

---

## 1. What Are Strings?

A **string** is an ordered sequence of characters stored contiguously in memory.
Common operations include:

* accessing characters
* slicing substrings
* searching substrings
* comparing strings
* transforming (lowercase/uppercase/trim)
* pattern matching
* hashing

---

## 2. Why Strings Matter in Interviews?

String problems test:

* logical thinking
* two-pointer manipulation
* efficient pattern matching
* frequency counting
* memory-efficient approaches
* sliding window techniques
* hashing principles
* prefix/suffix logic
* dynamic programming

**Common Interview Themes:**

* palindrome-related problems
* anagrams / frequency-matching
* substring search
* prefix-sum-like prefix/DP-table building
* lexicographical ordering
* string compression
* pattern validation and parsing

---

## 3. How Strings Are Stored (Intuition)

Strings internally behave like arrays of characters.

### ASCII vs Unicode

* ASCII: 1 byte per character
* Unicode (UTF-8): variable-length encoding
* Python strings are Unicode
* C++ `std::string` uses bytes but can hold arbitrary encodings

### Immutability

* Python strings are **immutable**
* C++ strings are **mutable**

This impacts performance:

| Language | Mutability | Concatenation  | Substring | Notes                                    |
| -------- | ---------- | -------------- | --------- | ---------------------------------------- |
| Python   | Immutable  | O(n)           | O(n)      | Use list join for repeated concatenation |
| C++      | Mutable    | Amortized O(1) | O(k)      | More memory control                      |

---

## 4. Important String Topics Covered in This Directory

### A. Basic Operations

Found in `implementations/operations.cpp` and `.py`

Includes:

* reverse string
* palindrome check
* substring search (naive)
* frequency counting
* normalization (case, trim)

---

### B. Pattern Matching Algorithms

You should create dedicated files for the following:

1. **KMP Algorithm (Knuth–Morris–Pratt)**
2. **Rabin–Karp**
3. **Z Algorithm**
4. **Prefix Function / LPS Array**
5. **Suffix Array**
6. **Suffix Tree**
7. **Aho-Corasick Automaton** (for multiple pattern search)

These algorithms provide efficient solutions for substring search, with complexities ranging from O(n+m) to O(n log n).

---

## 5. Problem-Solving Approaches

### 1. Sliding Window

Used for:

* longest substring without repeating characters
* minimum window substring
* string compression
* anagram matching

### 2. Two Pointers

Used for:

* palindrome transformations
* reversing order of words
* partial scans and substring extraction
* partitioning operations

### 3. Hashing/Maps

Used for:

* anagrams
* frequency-based checks
* distinct window-based questions

### 4. Dynamic Programming

Used for:

* longest common subsequence
* longest palindromic subsequence
* edit distance
* regular expression matching

### 5. Sorting/Ordering

Used for:

* lexicographical comparisons
* largest number (arranged numerically)
* string permutations

---

## 6. Visual Intuition (Examples)

### Sliding Window Example

```
[left ......... right]
```

Window expands and shrinks depending on constraints.

### KMP Prefix Table Example

```
pattern: a b a c a b a
LPS:     0 0 1 0 1 2 3
```

---

## 7. Complexity Summary Table

| Operation                | Python | C++            | Notes                      |
| ------------------------ | ------ | -------------- | -------------------------- |
| Access char              | O(1)   | O(1)           | Indexing                   |
| Concatenation            | O(n)   | Amortized O(1) | Python reallocates         |
| Substring search (naive) | O(n*m) | O(n*m)         | Brute-force                |
| KMP                      | O(n+m) | O(n+m)         | Efficient pattern matching |
| Hash computation         | O(n)   | O(n)           | Useful for Rabin-Karp      |
| Compare strings          | O(n)   | O(n)           | Scan until mismatch        |

---

## 8. Frequently Asked Interview Problems

### Must-Solve:

1. Longest substring without repeating characters
2. Valid parenthesis
3. Longest palindromic substring
4. Minimum window substring
5. Group anagrams
6. String compression (in-place)
7. Remove adjacent duplicates
8. Reverse words in a string
9. Multiply large numbers (string-based big integers)

---

## 9. Best Practices

### Always clarify:

* Case-sensitivity
* ASCII or Unicode
* Can you modify the original string?
* What constraints? (n up to 10^5 or 10^6 changes the approach)

### Avoid:

* excessive concatenation inside a loop
* naive substring search for large inputs
* maintaining huge frequency maps carelessly

---

## 10. Recommended Study Order

1. Basic string operations
2. Sliding window pattern
3. Hash maps & frequency tables
4. Two-pointer operations
5. KMP and prefix table
6. Rabin–Karp
7. Suffix array / tree
8. Aho-Corasick

---

## 11. Practice Sources

### LeetCode

* 3. Longest Substring Without Repeating Characters
* 76. Minimum Window Substring
* 5. Longest Palindromic Substring
* 49. Group Anagrams
* 242. Valid Anagram
* 151. Reverse Words in a String

### Codeforces

* String hashing tasks
* Substring lexicographical ordering
* Periodicity and prefix-function problems

### GFG

* Palindrome transformations
* Edit distance
* Trie-based string problems

---

## 12. Summary

Mastering strings requires:

* strong fundamentals
* comfort with sliding window
* strong understanding of prefix/suffix preprocessing
* hashing intuition
* DP thinking where needed

This directory provides both **conceptual depth** and **implementation readiness** to help you crack string-related interview problems efficiently.

---
