# When to Use Which Technique — Practical Cheat Guide

A decision-making reference for identifying the correct algorithmic approach during interviews. Focuses on patterns, triggers, and quick heuristics.

---

## 1. Arrays

### When to use Two Pointers

Use when:

* Array is sorted OR can be sorted
* You need pairs/triples satisfying a condition
* You want to shrink/expand a window from ends

Examples:

* Two sum (sorted)
* 3Sum
* Remove duplicates

### When to use Sliding Window

Use for:

* Subarrays
* Longest/shortest window meeting criteria
* Contiguous segment problems

Key triggers:

* “subarray”
* “longest/maximum/minimum window”
* “distinct characters”

---

## 2. Searching

### When to use Binary Search

Use when:

* Search space is monotonic
* You can check feasibility at mid
* You seek smallest/largest satisfying value

Common in:

* Minimize max load
* Search rotated array
* Check thresholds

### When to use Ternary Search

Use when:

* The function is unimodal (first increases then decreases or vice-versa)

---

## 3. Sorting

### When to sort

Use when:

* Order matters
* intervals, meetings, merging tasks
* Greedy choices become clear after sorting

Examples:

* Merge intervals
* Meeting rooms
* Activity selection

---

## 4. Hashing / Maps

Use when:

* Need frequency count
* Need fast lookup
* Detect duplicates/anagrams
* Track prefix-sums

Typical problems:

* Longest substring without repeating
* Subarray sum equals k
* Group anagrams

---

## 5. Recursion / Backtracking

Use when:

* Explore all combinations/permutations/subsets
* Choices depend on state
* Need to enumerate structured solutions

Key triggers:

* “generate all”
* “list all sequences”
* “constraints are small” (n ≤ 15 or so)

---

## 6. Dynamic Programming

Triggers:

* Optimal substructure exists
* Overlapping subproblems
* You can define dp(i) in terms of previous states
* Constraints hint polynomial but not exponential brute-force

Recognize questions like:

* Longest increasing subsequence
* Edit distance
* Partition equal subset
* Coin change variants

---

## 7. Greedy

Use greedy when:

* Choices can be made locally and still give global optimum
* Sorting solves most of the difficulty
* Structure looks like intervals or priority scheduling

Common problems:

* Job sequencing
* Minimum platforms
* Huffman coding
* Activity selection

---

## 8. Graph Techniques

### BFS

Use when:

* Shortest path in unweighted graph
* Need level order
* Need minimum number of steps

Typical:

* Word ladder
* Rotten oranges
* Minimum jumps

### DFS

Use when:

* Explore regions deeply
* Detect cycles
* Compute connected components
* Tree-like structures

### Dijkstra

Use when:

* Weighted graph, non-negative edges
* Need shortest paths

### Topological Sort

Use when:

* Directed acyclic graph
* Course scheduling
* Dependency resolution

---

## 9. Trees

### When to use recursion

Trees are naturally recursive:

* subtree problems
* path sums
* height/balance checks

### When to use iterative traversal

Use stack/queue when:

* Avoid recursion limit
* You want controlled traversal

---

## 10. Tries

Use when:

* Prefix search
* Word dictionary
* Autocomplete
* Efficient string search

Patterns:

* Query many prefixes
* Store dictionary for fast lookup

---

## 11. Heaps

Use when:

* Need top-k largest / smallest
* Continuous merging
* Priority scheduling
* Running median

Triggers:

* "k-th largest"
* "merge k sorted lists"
* “at any time return smallest/largest”

---

## 12. Segment Trees / Fenwick Trees

Use when:

* Range queries + point updates
* Update and query both frequent
* Brute force too slow

Use Segment Tree if:

* Range min/max/sum, lazy propagation

Use Fenwick Tree if:

* Simpler: prefix-sum focused

---

## 13. Combinatorics / Math

Use math when:

* Formula deducible
* Patterns are numeric/regular
* Recurrence can be simplified

Examples:

* Pascal triangle properties
* Counting paths
* Catalan numbers

---

## 14. Bitwise Tricks

Use when:

* Constraints small (n ≤ 20)
* Masking solves state representation
* Need fast subset enumeration
* XOR behavior helps (uniqueness)

---

## 15. Frequency of Techniques in Interviews

| Technique                | Frequency  |
| ------------------------ | ---------- |
| Two pointers             | Very high  |
| Sliding window           | Very high  |
| Hash maps                | Very high  |
| Recursion + backtracking | High       |
| Trees                    | High       |
| Graphs                   | High       |
| DP                       | High       |
| Greedy                   | Medium     |
| Binary Search            | Very high  |
| Heaps                    | High       |
| Segment Trees            | Low/Medium |
| Tries                    | Medium     |
| Bitmask DP               | Low        |
| Advanced Graphs (Flow)   | Very low   |

---

## 16. Quick Decision Flowchart (ASCII)

```
               Read Problem
                    |
          ------------------------
          |                      |
    Is problem about         Graph?
    subarray/window?            |
          |                     |
     Sliding window       BFS/DFS/Dijkstra
          |
Does sorting simplify?
          |
       Greedy
```

---

## 17. Practice Problems

### Easy

* Two sum
* Valid parentheses
* BFS traversal
* Frequency-based problems

### Medium

* Longest substring without repeat
* Coin change
* Merge intervals
* Course schedule

### Hard

* Edit distance
* LIS
* Dijkstra variants
* N-Queens
* Trie-based dictionary problems

---
