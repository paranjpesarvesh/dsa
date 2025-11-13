# **Suffix Tree — Theory & Implementation Guide**

---

## **1. What is a Suffix Tree?**

A **Suffix Tree** is a compressed trie of all suffixes of a string.
It allows many string operations to be performed in **O(n)** time.

Example string:
`S = banana$`

Suffixes:

```
banana$
anana$
nana$
ana$
na$
a$
$
```

After compression (merging chains of single-child nodes), we get a compact representation storing entire substrings on edges.

---

## **2. Why add ‘$’?**

We append a **unique terminal character** (`$`) to ensure:

* Every suffix ends at a leaf
* No suffix is a prefix of another
* Tree becomes explicit & simplified

---

## **3. Key Properties**

* Contains **all suffixes** of S
* Exactly **n leaves** (each representing one suffix)
* Total number of nodes: **≤ 2n**
* Edge labels represent substrings of S via indices: `(start, end)`

---

## **4. Visualization (ASCII)**

For `S = banana$`, a simplified structure:

```
(root)
 ├── b → "banana$"
 ├── a →
 │      ├── "na$"
 │      └── "na$" (overlap handles by indexing)
 ├── n →
 │      ├── "ana$"
 │      └── "a$"
 └── $ → "$"
```

Real suffix tree compresses paths like:

```
ana$
anana$
```

into shared prefixes:

```
a → na → ...
```

---

## **5. Construction Algorithms**

### **A. Naive (O(n²))**

Insert each suffix into a trie, then compress.

### **B. Ukkonen’s Algorithm (O(n)) — Industry Standard**

* Online construction
* Uses:

  * **Suffix links**
  * **Active point** (active node, edge, length)
  * **Implicit & explicit trees**

This is advanced but crucial for deep understanding.

---

## **6. Intuition Behind Ukkonen’s Algorithm**

Goal:
Build suffix tree incrementally for S[0..i].

Key ideas:

1. Extend the tree for each new character.
2. When a mismatch occurs:

   * Split an edge
   * Create a new leaf
   * Use **suffix links** to jump to the next state efficiently.
3. Ensures linear complexity.

ASCII mini-flowchart:

```
For each char:
    ↓
 Add char to all pending suffixes
    ↓
 Handle mismatch
    ↓
 Create leaf / split edge
    ↓
 Follow suffix links
```

---

## **7. Pseudocode (High-Level)**

```
build_suffix_tree(S):
    append '$'
    create root
    active = (node=root, edge=none, length=0)
    remainder = 0

    for i in range(n):
        remainder += 1
        last_created_internal = None

        while remainder > 0:
            if active.length == 0:
                active.edge = S[i]

            if active.node has no child starting with active.edge:
                create leaf
                if last_created_internal:
                    last_created_internal.suffix_link = active.node
                last_created_internal = None

            else:
                next_edge = active.node.child[active.edge]
                if active.length >= next_edge.length:
                    move active point down
                    continue

                if S[next_edge.start + active.length] == S[i]:
                    active.length += 1
                    if last_created_internal:
                        last_created_internal.suffix_link = active.node
                    break

                split edge
                create leaf
                link internal nodes

            remainder -= 1
            move active via suffix links

    return root
```

This mirrors Ukkonen’s algorithm without low-level details.

---

## **8. Complexity**

| Component           | Time     |
| ------------------- | -------- |
| Ukkonen's Algorithm | **O(n)** |
| Space               | **O(n)** |

Suffix Trees are one of the only structures allowing **linear-time** substring operations.

---

## **9. Applications**

Suffix Trees can solve in **O(n)**:

* Check if pattern exists
* Longest Repeated Substring
* Longest Palindromic Substring
* LCS (Longest Common Substring) of two strings
* Distinct substrings count
* All pattern occurrences
* String compression techniques (LZ)

---

## **10. Edge Cases**

* Large alphabets
* Repeated characters
* Patterns with `$` (rare)
* Unicode strings require mapping to integer alphabets

---

## **11. Interview Tips**

FAANG rarely asks direct suffix tree implementation due to complexity.
But knowing its **applications** and **relationship with suffix array** is essential:

Suffix Tree → Compressed Trie
Suffix Array → Sorted list of suffixes
LCP Array → Adjacent LCP lengths

Relation:

```
Suffix Array + LCP Array  ==  Suffix Tree (in array form)
```

Companies ask LCP/SA problems derived from suffix tree concepts.

---

## **12. Practice Problems**

### **LeetCode**

* 1044. Longest Duplicate Substring (use suffix array/tree concept)
* 1163. Last Substring in Lexicographical Order

### **GFG**

* Construct Suffix Tree (naive)
* Pattern searching using suffix tree/trie

### **Codeforces**

* Problems under “string suffix structures”
* Distinct substrings tasks (LCP-based)

---
