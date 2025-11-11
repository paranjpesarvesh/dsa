# Trie (Prefix Tree) — Overview

## 1. Introduction

A **Trie** (pronounced "try") is a powerful tree-based data structure used for storing and querying strings efficiently.
It is especially useful when handling large sets of strings with shared prefixes.

Typical use cases:

* autocomplete systems
* spell checkers
* dictionary implementations
* prefix matching
* efficient string search
* IP routing (compressed trie)

## 2. Structure of a Trie

A Trie node consists of:

* **children** (mapping character → next node)
* **end marker** marking end of a valid word

### ASCII Structure Example

Suppose we insert:
`"app"`, `"apple"`, `"bat"`

```
(root)
  ├── a
  │    └── p
  │         └── p*
  │               └── l
  │                    └── e*
  └── b
       └── a
            └── t*
```

`*` indicates end of a word.

## 3. Why Tries Work (Intuition)

String operations become proportional to **length of the string**, not number of stored strings.

For example:

* Searching a word `"apple"` takes O(5)
* Regardless of storing 10 words or 10 million words

This is why autocomplete search engines rely heavily on tries.

## 4. Core Operations

### 4.1 Insertion

Process:

* traverse characters one by one
* create missing child nodes
* mark last node as terminal

Time: O(L)
Space: O(L)

### 4.2 Search (Exact Match)

Follow the path using characters;
if at any point missing → word not present.

Time: O(L)

### 4.3 StartsWith / Prefix Match

Same as search but end marker not required.

Time: O(L)

### 4.4 Delete (Advanced)

More complex because:

* deleting a word must not remove shared prefixes
* nodes should be deleted only if not shared

## 5. Pseudocode Summary

### Insert

```
function insert(word):
    node = root
    for ch in word:
        if ch not in node.children:
            node.children[ch] = new Node()
        node = node.children[ch]
    node.end = true
```

### Search

```
function search(word):
    node = root
    for ch in word:
        if ch not in node.children:
            return false
        node = node.children[ch]
    return node.end
```

### Prefix

```
function startsWith(prefix):
    node = root
    for ch in prefix:
        if ch not in node.children:
            return false
        node = node.children[ch]
    return true
```

## 6. Complexity Analysis

| Operation  | Time | Space               |
| ---------- | ---- | ------------------- |
| Insert     | O(L) | O(L) per new word   |
| Search     | O(L) | —                   |
| StartsWith | O(L) | —                   |
| Delete     | O(L) | —                   |
| Memory use | —    | O(N * AlphabetSize) |

For lowercase English letters, alphabet size = 26.

## 7. Variants of Trie

### 1. Compressed Trie / Radix Tree / Patricia Trie

Stores entire substrings → reduces memory.

### 2. Suffix Trie

Stores all suffixes of a string.
Used for substring search.

### 3. Ternary Search Tree

Each node stores a single character but has:

* left
* middle
* right

Space optimized, supports sorted traversal.

## 8. Edge Cases

* inserting empty string
* searching for nonexistent prefixes
* case sensitivity
* unicode characters
* deleting shared words

## 9. Interview Tips

* Know how to implement basic insert/search/prefix
* Understand how to delete safely
* Know memory drawbacks
* Explain tries vs hash maps:

  * Hash map search = O(L) average but no sorted order, no prefix support
  * Trie supports lexicographic traversal, prefix search, autocomplete
* Sometimes interviewer will ask to compress trie
* Practice writing node class and recursion

## 10. Practice Problems

### LeetCode

* Implement Trie (208)
* Design Add and Search Words Data Structure (211)
* Replace Words (648)
* Word Search II (212)
* Lexicographical Numbers (386)

### GFG

* Trie | Insert and Search
* Longest Prefix Matching
* Word Break Problem

### Codeforces

* Many prefix-based problems use tries + bitwise tries
  e.g., maximum XOR pair, prefix substring matching

## 11. Summary Table

| Feature          | Supported?            |
| ---------------- | --------------------- |
| Prefix search    | Yes                   |
| Delete           | Yes (with care)       |
| Autocomplete     | Yes                   |
| Sorting          | Yes                   |
| Substring search | Only with suffix trie |
| Memory heavy     | Yes                   |

---
