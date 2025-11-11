# Trie (Prefix Tree) — Theory

## 1. Introduction

A **Trie** is a tree-based data structure optimized for storing and querying strings (typically words) based on their prefixes.
Unlike hash tables, tries maintain hierarchical character-level structure, enabling efficient prefix operations, lexicographical ordering, and autocomplete functionality.

Tries are widely used in:

* search engines
* text editors
* auto-completion systems
* spell-checkers
* dictionary databases
* IP routing (Radix/Patricia Trie variants)

## 2. Trie Node Structure

A typical Trie node contains:

* `children`: mapping from character → child node
* `is_end`: boolean flag marking end of a valid word

### ASCII Diagram Example

For ["app", "apple", "bat"]:

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

`*` denotes end of word.

## 3. Why Tries Work (Intuition)

Tries exploit shared prefixes.

If many words share prefixes, storage and query become efficient.
Operations depend only on **length of input**, not number of stored words.

For example:

* Searching `"apple"` takes O(5)
* Whether Trie contains 50 words or 5 million words

This prefix compression is key to its efficiency.

## 4. Core Operations

### 4.1 Insertion

Steps:

1. Start at root
2. For each character in word:

   * if child missing → create node
3. Mark last node as end-of-word

### 4.2 Search (Exact Match)

* Walk through nodes using characters
* If at any point child missing → word not present
* After last char, check `is_end == true`

### 4.3 StartsWith (Prefix Query)

* Exactly like search but no need to check `is_end`

### 4.4 Deletion

Deletion is tricky:

* Remove nodes only if they are not shared
* Requires backtracking or recursion

## 5. Pseudocode Templates

### Insert

```
function insert(word):
    node = root
    for ch in word:
        if ch not in node.children:
            node.children[ch] = new Node()
        node = node.children[ch]
    node.is_end = true
```

### Search

```
function search(word):
    node = root
    for ch in word:
        if ch not in node.children:
            return false
        node = node.children[ch]
    return node.is_end
```

### StartsWith

```
function startsWith(prefix):
    node = root
    for ch in prefix:
        if ch not in node.children:
            return false
        node = node.children[ch]
    return true
```

### Delete (recursive)

```
function delete(node, word, i):
    if i == len(word):
        node.is_end = false
        return node.children empty
    ch = word[i]
    if ch not in node.children:
        return false
    can_delete = delete(node.children[ch], word, i+1)
    if can_delete:
        remove node.children[ch]
    return node.children empty and node.is_end == false
```

## 6. Complexity Analysis

Let `L` = length of word, `N` = total words stored, `Σ` = alphabet size.

| Operation       | Time                           | Space              |
| --------------- | ------------------------------ | ------------------ |
| Insert          | O(L)                           | O(L) for new nodes |
| Search          | O(L)                           | —                  |
| StartsWith      | O(L)                           | —                  |
| Delete          | O(L)                           | —                  |
| Full Trie Space | O(N * average word length * Σ) |                    |

Memory is the main cost due to many pointers.

## 7. Variants of Trie

### 1. Compressed Trie (Radix Tree / Patricia Trie)

* Stores substrings instead of single characters
* Saves memory
* Used in routing tables

### 2. Suffix Trie

* Stores all suffixes of a string
* Useful for substring search
* Very memory heavy

### 3. Ternary Search Tree (TST)

Each node stores one character and three pointers:

* left
* mid
* right

Optimized for memory.

### 4. Bitwise Trie

Used for XOR problems:

* each node has 2 children (0 and 1)
* used in max-XOR pair, network routing

## 8. Edge Cases

* Empty string insertion
* Unicode/multilingual characters
* Case sensitivity (convert to lowercase?)
* Deleting shared nodes carefully
* Prefix equals a full word ("app" and "apple")

## 9. Interview Tips

* Know basic operations thoroughly
* Understand difference: Trie vs Hashmap
* Be able to code TrieNode class quickly
* Be able to handle:

  * insert
  * search
  * startsWith
  * delete (advanced)
* Follow-up questions often include:

  * max-XOR pair (bitwise trie)
  * autocomplete (DFS over prefix node)
  * word dictionary with wildcard (use DFS/backtracking)

### Common interview pitfalls

* forgetting to mark `is_end`
* not handling delete properly
* using recursion without understanding node cleanup
* storing too large alphabet (wasting memory)

## 10. Practice Problems

### LeetCode

* 208. Implement Trie
* 211. Design Add and Search Words Data Structure
* 212. Word Search II
* 648. Replace Words
* 676. Implement Magic Dictionary

### GFG

* Trie Insert and Search
* Longest Prefix Matching
* Word Break Problem

### Codeforces

* Max XOR of Pair
* Finding distinct substrings
* Substring queries using suffix trie variant

## 11. Summary

| Feature           | Trie    | HashMap      |
| ----------------- | ------- | ------------ |
| Prefix search     | Yes     | No           |
| Ordered traversal | Yes     | No           |
| Memory usage      | High    | Low          |
| Search time       | O(L)    | O(L) average |
| Autocomplete      | Natural | Extra logic  |

---
