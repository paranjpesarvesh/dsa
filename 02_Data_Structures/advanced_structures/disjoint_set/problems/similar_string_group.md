# 🔗 Similar String Groups using Disjoint Set (Union-Find)

---

## 📌 Introduction

The **Similar String Groups** problem is a classic **graph-connected-components** problem, efficiently solved using **Disjoint Set (Union-Find, DSU)**.

**Problem Statement:**
You are given an array of strings. Two strings are **similar** if:

1. They are equal, or
2. They differ by **exactly two letters** in the same positions.

The task is to **group all similar strings** into connected components and return the **number of such groups**.

**Example:**

```
Input: ["tars","rats","arts","star"]
Output: 2
Explanation:
Group 1: ["tars","rats","arts"]
Group 2: ["star"]
```

---

## 📌 Mathematical Intuition

1. Treat each string as a **node** in a graph.
2. An **edge exists** between two nodes if the strings are similar.
3. The problem reduces to finding **connected components** in this graph.

**DSU (Union-Find)** is optimal for maintaining and merging these components.

---

## 📌 Step-by-Step Reasoning

1. Initialize DSU for all strings (`0` to `N-1`).
2. Compare every pair of strings:

   * If **similar**, union their indices.
3. Count the number of **distinct parents** in DSU → number of groups.

**Similarity Check Function:**

* Two strings `s1` and `s2` are similar if exactly **0 or 2 positions differ**.

---

## 📌 Pseudocode

```
function numSimilarGroups(strs):
    n = length of strs
    dsu = DSU(n)

    # Step 1: Merge similar strings
    for i = 0 to n-1:
        for j = i+1 to n-1:
            if areSimilar(strs[i], strs[j]):
                dsu.union(i, j)

    # Step 2: Count distinct groups
    return number of unique parents in dsu

function areSimilar(s1, s2):
    count = 0
    for k = 0 to length(s1)-1:
        if s1[k] != s2[k]:
            count += 1
            if count > 2:
                return False
    return True
```

---

## 📌 Complexity Analysis

| Operation            | Complexity                       |
| -------------------- | -------------------------------- |
| Similarity check     | O(L) per pair, L = string length |
| Pairwise comparisons | O(N² × L)                        |
| DSU operations       | O(α(N)) amortized                |
| **Overall**          | O(N² × L)                        |
| Space                | O(N) for DSU parent/rank arrays  |

> α(N) is inverse Ackermann function, nearly constant.

---

## 📌 ASCII Visualization

```
Strings: ["tars","rats","arts","star"]

Step 1: Check pairwise similarity
tars ~ rats -> similar -> union(0,1)
tars ~ arts -> similar -> union(0,2)
rats ~ arts -> similar -> union(1,2)
star ~ others -> no similarity

Step 2: Count distinct parents
Parent array might look like: [0,0,0,3]
Number of groups = 2
```

---

## 📌 Variations & Edge Cases

* **All strings identical:** 1 group.
* **All strings completely different:** N groups.
* **Strings of different lengths:** Problem usually assumes **same length strings**.
* **Large N:** Optimizations like **early union during similarity checks** reduce redundant operations.

---

## 📌 Interview Tips

* Use **DSU** for connected components problems.
* Pairwise comparison is acceptable for small N (≤ 300).
* For large N, consider **graph adjacency optimizations**.
* Emphasize **path compression** in DSU to avoid TLE in interview coding rounds.
* Often asked in **LeetCode Medium**/GFG graph problems.

---

## 📌 Practice Problems

* [LeetCode 839 – Similar String Groups](https://leetcode.com/problems/similar-string-groups/)
* [GFG – Number of Similar Groups](https://www.geeksforgeeks.org/similar-string-groups/)
* [Codeforces – Connected Components Problems](https://codeforces.com/problemset)

---

✅ **Summary:**
The Similar String Groups problem showcases **DSU for dynamic connectivity** in string graphs. Key ideas:

1. Represent strings as nodes.
2. Union similar strings.
3. Count distinct components.

DSU simplifies **merging equivalent elements** and efficiently computes **connected groups**.

