# Suffix Tree — Theory and Practical Guide

A **Suffix Tree** is a powerful compressed trie of all suffixes of a string. It supports substring and pattern-related operations in optimal time and is foundational in advanced string algorithms.

---

## 1. What is a Suffix Tree?

Given a string `S` of length `n`, a suffix tree is a **rooted, directed tree** such that:

* Each edge is labeled with a non-empty substring of `S`
* No two edges from the same node start with the same character
* Every suffix of `S` appears as a path from root to a leaf
* The complete structure stores all suffixes compressed

### Example (uncompressed trie)

For `S = "banana"`:

```
b a n a n a $
a n a n a $
n a n a $
a n a $
n a $
a $
```

### Compressed suffix tree

The suffix tree merges chains of single edges into longer substrings:

```
          root
        /   |    \
      a     b     n
     / \    |     |
   na$ ana$ nana$
```

(Note: actual suffix trees are deeper but follow this idea.)

---

## 2. Why Suffix Trees?

Operations become extremely fast:

| Problem Type                   | Time             |
| ------------------------------ | ---------------- |
| Pattern search                 | O(m)             |
| LCS (Longest Common Substring) | O(n)             |
| LRS (Longest Repeated String)  | O(n)             |
| Count distinct substrings      | O(n)             |
| Find all occurrences           | O(m + occ_count) |

Suffix trees are used in:

* Full-text indexing
* Bioinformatics (DNA sequence search)
* Compression (LZ algorithms)
* String similarity/plagiarism detection
* Multi-string comparison

---

## 3. Mathematical Intuition

A suffix tree compactly represents all substrings.

Facts:

* Total substrings of a string = O(n²)
* Total nodes in suffix tree = O(n)
* Every substring corresponds to a prefix of some suffix
* That’s why suffix tree gives huge compression

### Key idea of compression:

Instead of storing:

```
a → n → a → n → a → $
```

Store:

```
a nana$
```

This reduces edge count dramatically.

---

## 4. Ukkonen’s Algorithm (High-Level)

Ukkonen’s algorithm builds the suffix tree in O(n) by maintaining:

### Active Point

Representation of the current build position:

```
(active_node, active_edge, active_length)
```

### Rules

1. **Extend existing edges if character matches**
2. **Create new leaf**
3. **Split an edge and insert**

### Suffix Links

* Connect internal nodes
* Used to jump quickly during construction
* Ensures amortized O(1) updates

### Online nature

* Processes input characters one by one
* Tree is always a valid implicit suffix tree of prefix processed so far

---

## 5. Key Components in a Suffix Tree

### Node

* Has edges to children
* Has either many children or exactly one (like a compressed trie)
* Internal nodes → represent repeated substrings
* Leaves → represent suffixes

### Edges

Represent substring `S[start…end]` using indices, not actual copied strings.

Memory saving:

* No string slicing
* Direct referencing into original input

---

## 6. Pseudocode (Simplified Ukkonen)

```
function buildSuffixTree(S):
    append '$' to S
    initialize root
    active_node = root
    active_edge = -1
    active_length = 0
    remaining = 0

    for i in 0 to n-1:
        extend(i)
```

High-level `extend(i)`:

```
remaining++
last_created = null

while remaining > 0:
    if active_length == 0:
        active_edge = i

    if active_edge character not in active_node children:
        create leaf
        link last_created → active_node
    else:
        child = active_node[active_edge]
        if active_length ≥ edge_length(child):
            walk down child
            continue
        if S[child.start + active_length] == S[i]:
            active_length++
            link last_created → active_node
            break
        else:
            split edge
            create new leaf
            adjust pointers
            link last_created → split_node

    remaining--
    adjust active point using suffix links
```

---

## 7. Complexity Analysis

| Operation | Complexity |
| --------- | ---------- |
| Build     | O(n)       |
| Search    | O(m)       |
| Space     | O(n)       |

Suffix trees achieve optimal runtime for many substring problems.

---

## 8. Variations & Alternatives

### A) Generalized Suffix Tree

For multiple strings:

* Concatenate strings with unique separators
* Build tree once
* Used for LCS across multiple strings

### B) Suffix Automaton

More memory-efficient alternative:

* Linear time, smaller constant factor
* Supports substring queries
* Does not store tree shape, only states

### C) Suffix Array + LCP

Space-efficient alternative:

* O(n log n) to build (or O(n) with advanced algorithms)
* LCP supports many tree-like operations
* Preferred in interviews

---

## 9. Interview Tips

### Expectations:

* Understand what suffix tree represents
* Know compressed trie properties
* Explain Ukkonen’s algorithm conceptually
* Know difference from suffix array
* Know typical use cases

### Not expected:

* Full Ukkonen code from memory
* Advanced optimizations
* Handling Unicode
* Practical memory tuning

### Frequently Asked:

1. What is a suffix tree?
2. How is it different from a suffix array?
3. What is suffix link and why needed?
4. What is LCS/LRS/LCP?
5. How to find longest repeated substring using suffix tree?

---

## 10. Practice Problems

### LeetCode

* Longest Duplicate Substring
* Longest Repeating Substring (hard)
* Distinct Substrings (conceptual)

### Codeforces

* Frequent substring queries
* Problems tagged with "suffix structures"

### GFG

* Implement Ukkonen’s Algorithm
* Build a suffix array + LCP
* Find Longest Repeating Substring

---

## 11. Summary

Suffix Tree is:

* A compressed, efficient representation of all suffixes
* Built in O(n)
* Supports many powerful string operations quickly
* More theoretical than practical, but crucial concept in DSA

For interviews:

* Focus on concepts
* Understand Ukkonen’s phases
* Know tradeoffs vs suffix array

---
