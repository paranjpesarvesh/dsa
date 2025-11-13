# **Aho–Corasick Algorithm (Multi-pattern String Matching)**

---

## **1. Introduction**

The **Aho–Corasick algorithm** is a powerful string-processing technique used to search for **multiple patterns simultaneously** within a text in **linear time**.

It builds:

1. A **Trie** of all patterns
2. **Failure links** (like KMP’s LPS but for a trie)
3. **Output links** to report matches

It is widely used in:

* Malware detection
* Spam filters
* DNA sequence scanning
* Competitive programming

---

## **2. Intuition**

Think of it as combining:

```
TRIE + KMP
```

Trie → stores all patterns
Failure links → allow fallback when mismatch happens
Output links → help detect patterns ending at nodes

ASCII view:

```
           root
          /   \
         a     b
        / \     \
       b   c     a
```

During traversal over text:

* Follow trie edges if matching
* On mismatch → jump via failure links
* Every time you reach a node → check output link for matches

---

## **3. Construction Steps**

### **Step 1: Build the Trie**

Insert each pattern.

### **Step 2: Build Failure Links**

Using BFS:

```
fail(child of root) = root
fail(node) = longest suffix of node's string that exists in trie
```

### **Step 3: Build Output Links**

If fail[x] is the end of a pattern, then x should also output that pattern.

---

## **4. Searching in Text**

For each character in text `T`:

1. Follow trie edges if possible
2. If mismatch → follow failure links
3. Record matches from output links

---

## **5. Pseudocode (Core Idea)**

```
buildTrie(patterns)

buildFailureLinks():
    queue = empty
    for each child of root:
        child.fail = root
        push child into queue

    while queue not empty:
        node = pop()
        for (char, nxt) in node.children:
            f = node.fail
            while f != root and char not in f.children:
                f = f.fail
            if char in f.children:
                nxt.fail = f.children[char]
            else:
                nxt.fail = root
            if nxt.fail is end of some pattern:
                nxt.output += nxt.fail.output
            push nxt

search(text):
    node = root
    for ch in text:
        while node != root and ch not in node.children:
            node = node.fail
        if ch in node.children:
            node = node.children[ch]
        if node.output has patterns:
            report all matches
```

---

## **6. Complexity Analysis**

| Stage               | Time                          | Space           |
| ------------------- | ----------------------------- | --------------- |
| Build Trie          | O(sum of lengths of patterns) | O(K * alphabet) |
| Build Failure Links | O(total nodes * alphabet)     | O(total nodes)  |
| Search Text         | O(text length)                | —               |
| **Total**           | **O(N + M + Z)**              | —               |

* N = total characters in text
* M = total characters in all patterns
* Z = number of matches found

---

## **7. Edge Cases**

* Overlapping patterns
* Patterns that are prefixes of other patterns
* Large alphabets (use hash map)
* Empty pattern → ignore
* Duplicate patterns → store IDs uniquely

---

## **8. Visual Flowchart**

```
Insert patterns → Build Trie
       ↓
Build failure links (BFS)
       ↓
Scan text
       ↓
When mismatch → failure link
       ↓
Match found → output link
```

---

## **9. Interview Tips**

* Aho–Corasick = “multi-pattern KMP on a Trie”.
* Frequently asked in:

  * Google
  * Meta
  * Amazon (string-heavy rounds)
  * Codeforces Div1
* Be ready to:

  * Draw failure links
  * Explain how BFS is used
  * Compare with KMP / Rabin-Karp
  * Handle overlapping patterns

---

## **10. Practice Problems**

### **LeetCode**

* 1032. Stream of Characters
* 1408. String Matching in Array

### **GFG**

* Aho-Corasick Algorithm for Pattern Searching
* Multi-pattern search

### **Codeforces**

* 963D – frequency queries using Aho–Corasick
* Standard AC automaton exercises

---

If you want, I can generate a C++ or Python implementation for competitive programming.

