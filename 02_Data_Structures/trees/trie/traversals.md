# Trie Traversals

## 1. Introduction

A **Trie traversal** refers to any method that visits nodes in a trie systematically.
Unlike binary trees, tries are multi-way trees where each node may have up to `Σ` children (where `Σ` is the alphabet size).

Traversals are essential for:

* printing all words
* implementing autocomplete
* prefix listing
* dictionary enumeration
* serialization of trie
* lexicographically sorted output

## 2. Types of Trie Traversals

Since Trie nodes represent characters and must follow child ordering, traversal types differ slightly from binary trees but remain conceptually similar.

### Main traversal methods:

1. **DFS (Depth-First Search)**
2. **BFS (Breadth-First Search)**
3. **Lexicographical Traversal**
4. **Prefix-based traversal**

In tries, traversal order is determined by:

* alphabet ordering
* children array/map order
* visited path (characters form prefixes)

---

## 3. Depth-First Search (DFS)

### Use cases

* Print all stored words
* Backtracking search (e.g., wildcard patterns)
* Autocomplete generation
* Explore dictionary recursively

### Intuition

DFS follows this idea:

* go deep along one child chain
* backtrack
* continue with next child

### Example ASCII

```
        (root)
        /    \
       a      b
      / \      \
     p   t      y
    /            \
   p*             e*
```

DFS order:
`app`, `apt`, `bye`

### DFS Pseudocode

```
function dfs(node, path):
    if node.is_end:
        print(path)

    for ch in sorted(node.children.keys()):
        dfs(node.children[ch], path + ch)
```

Key points:

* maintain `path` representing current word
* print only when `is_end == true`
* sort children for lexicographical order

Time Complexity:
O(N * L) where N = number of words, L = average length

---

## 4. BFS (Level-order traversal)

### Use cases

* Serialize/deserialize tries
* Structure-level analysis
* Level-wise dictionary view

### Intuition

Like normal BFS:

* queue-based traversal
* visit nodes level by level

### BFS Pseudocode

```
function bfs(root):
    queue = [(root, "")]
    while queue not empty:
        node, path = queue.pop()
        if node.is_end:
            print(path)
        for ch, child in node.children:
            queue.push((child, path + ch))
```

### BFS vs DFS

| Feature         | BFS             | DFS              |
| --------------- | --------------- | ---------------- |
| Memory          | High            | Low              |
| Good for        | level-order ops | deep exploration |
| Autocomplete    | Not ideal       | Best             |
| Wildcard search | Limited         | Great            |

---

## 5. Lexicographical Traversal

### Goal

Output all words in sorted order.

### Method

DFS + sorted children → lexicographical output.

This is very lightweight and efficient since Trie structure already supports ordering naturally.

### Pseudocode

```
function lexicographical_traversal(root):
    dfs(root, "")
```

(where DFS sorts children)

---

## 6. Prefix-Based Traversal

Given a prefix `"app"`, list all words starting with prefix.

### Steps:

1. Navigate to prefix node
2. Run DFS from that node

### Pseudocode

```
function autocomplete(prefix):
    node = find(prefix)
    if node == null:
        return []
    results = []
    dfs(node, prefix)
    return results
```

### Complexity

* Finding prefix: O(P)
* DFS of subtree: O(K)
  K = number of words under prefix

---

## 7. How Tries Support Efficient Traversals

The trie inherently groups words by common prefixes.
Traversals exploit this structure:

* DFS stays localized
* lex-order traversal requires no sorting of full word list
* prefix traversal requires no full scan

---

## 8. Edge Cases

* empty trie → traversal prints nothing
* words sharing prefixes
* nodes storing markers but having children (`"app"` and `"apple"`)
* very large alphabet (unicode)
* memory-heavy scenarios → optimize with TST or compressed trie

---

## 9. Interview Tips

* Know DFS for printing words
* Understand prefix scanning
* Be able to implement autocomplete
* Practice wildcard matching queries:

  * `"a.e"` — must explore multiple children
* Know how to handle lexicographical output

Common follow-ups:

* modify traversal to handle wildcards
* find shortest/longest word
* serialize/deserialize trie
* count nodes/words

---

## 10. Practice Problems

### LeetCode

* 208. Implement Trie
* 211. Design Add and Search Words Data Structure
* 212. Word Search II (heavy DFS)
* 648. Replace Words
* 472. Concatenated Words

### GFG

* Trie Traversal
* Longest prefix matching
* Auto-suggestion feature

### Codeforces

* building dictionary tries
* max XOR subtree traversal with bitwise trie

---

## 11. Summary

| Traversal Type | Purpose                            | Notes                  |
| -------------- | ---------------------------------- | ---------------------- |
| DFS            | list words, autocomplete, wildcard | most common            |
| BFS            | serialization, structure view      | memory heavy           |
| Lexicographic  | sorted output                      | sorted children needed |
| Prefix-based   | autocomplete                       | efficient lookup       |

---
