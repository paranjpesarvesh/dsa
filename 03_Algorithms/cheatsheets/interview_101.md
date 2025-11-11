# Interview 101 — High-Impact Algorithms & Patterns Cheatsheet

A compact-yet-complete revision guide focusing on the **most repeatedly asked concepts**, patterns, and tricks in interviews (FAANG, top startups, competitive programming).

---

## 1. Core Problem-Solving Patterns

These patterns cover ~80% of all interview problems.

### 1.1 Two-Pointer Technique

Use when:

* Sorted array
* Move inward/outward to shrink search area
* Find pairs/triples

Examples:

* Two Sum II
* 3Sum / 4Sum
* Container With Most Water

Template:

```
i = 0
j = n-1
while i < j:
    # compute
    if condition: i += 1
    else: j -= 1
```

### 1.2 Sliding Window

Use when solving:

* Subarray problems
* Longest/shortest window with property

Two types:

* Fixed window
* Dynamic window

Template:

```
i = 0
for j in range(n):
    # expand window
    while bad_condition:
        i += 1
    # update answer
```

---

## 2. Binary Search Patterns

Binary search is not only for searching numbers; it is for searching **answers**.

Common use cases:

* Min/Max threshold
* Feasibility check
* Monotonic property

Template:

```
l, r = low, high
while l <= r:
    mid = (l+r)//2
    if check(mid):
        ans = mid
        r = mid-1
    else:
        l = mid+1
```

Key problems:

* Allocate books / split array largest sum
* Koko eating bananas
* First bad version
* Peak element

---

## 3. Greedy Algorithms

Checklist when using greedy:

1. Greedy choice property?
2. Optimal substructure?
3. Can sorting help?

Examples:

* Activity selection
* Interval scheduling
* Huffman coding
* Fractional knapsack

---

## 4. Dynamic Programming Patterns

### 4.1 Top-down (memoization)

```
def dp(i):
    if base: return val
    if memo[i] exists: return memo[i]
    memo[i] = combine(dp(i-1), dp(i-2))
    return memo[i]
```

### 4.2 Bottom-up (tabulation)

```
dp = [0]*n
dp[0] = base
for i in range(1,n):
    dp[i] = combine(dp[i-1], dp[i-2])
```

Most common DP categories:

| Category       | Examples                       |
| -------------- | ------------------------------ |
| 1D DP          | Fibonacci, climb stairs        |
| 2D DP          | LCS, edit distance             |
| DP on trees    | diameter, subtree queries      |
| DP on bitmasks | TSP, assignment                |
| Unbounded DP   | coin change, knapsack infinite |
| Bounded DP     | 0/1 knapsack                   |

---

## 5. Graph Patterns

### 5.1 BFS

Use when required:

* Level order
* Shortest path in unweighted graph

### 5.2 DFS

Use for:

* Cycle detection
* Components
* Topological sort
* Path exploration

### 5.3 Dijkstra

For weighted shortest paths (non-negative).

### 5.4 Union-Find

Use for grouping / connectivity.

Optimization:

* Path compression
* Union by size/rank

Time complexity nearly constant.

---

## 6. Tree Patterns

### 6.1 Recursion Template

```
def solve(root):
    if not root: return something
    left = solve(root.left)
    right = solve(root.right)
    return combine(left, right)
```

### 6.2 Traversals

* Inorder: left-root-right
* Preorder: root-left-right
* Postorder: left-right-root

### 6.3 Binary Search Tree

Operations:

* Insert/search/delete: O(log n) avg
* Beware skewed tree: O(n)

---

## 7. String Patterns

### 7.1 Hashing

Rolling hash used for:

* Substring search
* Palindromes
* Duplicates

### 7.2 Trie

When to use:

* Prefix search
* Word dictionary
* Autocomplete

Time: O(word_length)

---

## 8. Recursion & Backtracking

Classic template:

```
def backtrack(path, options):
    if goal:
        store(path)
        return
    for option in options:
        choose(option)
        backtrack(path+option, options)
        unchoose(option)
```

Examples:

* N-Queens
* Subsets
* Permutations

---

## 9. Math Patterns

### Modular arithmetic

Properties:

* (a+b)%m
* (a*b)%m
* fast exponentiation: O(log n)

### GCD/LCM

Euclid:
gcd(a,b) = gcd(b, a%b)

Time: O(log n)

---

## 10. Complexity Quick Reference

### Time complexities

```
O(1) < O(log n) < O(n) < O(n log n) < O(n^2)
```

### Space

Always mention:

* extra arrays
* recursion depth

---

## 11. Most Common Interview Mistakes

* Ignoring edge cases
* Overcomplicating simple problems
* Missing monotonicity for binary search
* Incorrect overflow handling
* Not analyzing constraints properly

---

## 12. Quick Checklist Before Submitting

1. Does it handle empty inputs?
2. Are indices correct (off-by-one)?
3. Does it handle duplicates?
4. Does it handle negative/large numbers?
5. Is time complexity optimal?
6. Is space complexity minimal?

---

## 13. High-Frequency Problem List

### Arrays

* Two Sum
* Maximum subarray (Kadane)
* Merge intervals
* Minimum in rotated array

### Strings

* Longest substring without repeating characters
* Palindromic substrings
* Anagram group

### DP

* Climbing stairs
* Edit distance
* Coin change

### Trees

* Validate BST
* Lowest common ancestor
* Max path sum

### Graphs

* Number of islands
* Clone graph
* Course schedule

### Backtracking

* Subsets
* Permutations
* Combination sum

---

## 14. ASCII Decision Flowchart: Which Technique?

```
              Start Problem
                    |
          ----------------------
          |                    |
     Is data sorted?       Graph?
          |                    |
     Yes  |                    |--> BFS/DFS/Dijkstra
          v                    |
   Use two pointers            |
          |
          v
  Does problem need optimal?
          |
   Greedy or DP
```

---

## 15. Practice Sets

### Light

* Easy: arrays, strings, frequency maps

### Medium

* Sliding window
* Two pointer
* Trees recursion
* DP basic

### Hard

* Graphs (topo sort, cycles)
* DP optimization
* Segment trees
* Bitmasking DP
* Flow algorithms

---

## 16. Final Advice

* Learn patterns, not problems.
* Identify the category instantly.
* Master complexity reasoning.
* Always write clean and modular code.

---
