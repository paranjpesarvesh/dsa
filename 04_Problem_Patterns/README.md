# Problem Patterns Overview

This section of your repository presents the **most important problem-solving patterns** that help you solve interview questions efficiently.
Patterns allow you to recognize the optimal approach **before** writing code.

This README provides:

* Purpose of problem patterns
* List of patterns with brief descriptions
* How to use patterns during interviews
* Links to pattern-specific markdowns

---

# Why Problem Patterns?

Most interview questions are not unique; they belong to well-known **patterns**.
Recognizing the pattern helps you:

* avoid brute-force thinking
* reduce solution time
* improve clarity and confidence
* know which data structure/algorithm fits
* communicate effectively with interviewers

---

# List of Problem-Solving Patterns

Below is the curated list (each covered in a separate file):

| Pattern # | Pattern Name                  | Core Idea                                        |
| --------- | ----------------------------- | ------------------------------------------------ |
| 01        | Sliding Window                | Maintain dynamic window over contiguous elements |
| 02        | Two Pointers                  | Move pointers strategically for optimization     |
| 03        | Fast & Slow Pointers          | Detect cycles or midpoints efficiently           |
| 04        | Merge Intervals               | Sort intervals and merge overlaps                |
| 05        | Cyclic Sort                   | Place elements in correct indexes                |
| 06        | In-Place Linked List Reversal | Reverse nodes or sublists efficiently            |
| 07        | Tree BFS                      | Level-wise traversal of trees/graphs             |
| 08        | Tree DFS                      | Recursive exploration of tree/graph paths        |
| 09        | Two Heaps                     | Maintain median or two balanced sets             |
| 10        | Subsets Pattern               | Generate combinations/backtracking               |
| 11        | Modified Binary Search        | Search in special arrays or constraints          |
| 12        | Bitwise XOR                   | Use XOR properties to solve bit problems         |
| 13        | Top-K Elements                | Use heaps or quickselect                         |
| 14        | K-Way Merge                   | Merge sorted lists with min-heap                 |
| 15        | DP (0/1 Knapsack style)       | Solve subset/knapsack variants                   |
| 16        | Topological Sort              | Order tasks with dependencies                    |

---

# How to Use These Patterns Effectively

## Step 1: Identify the Pattern

Look for keywords in the problem statement:

* “subarray / substring” → Sliding Window
* “sorted” → Two Pointers / Binary Search
* “dependencies” → Topological Sort
* “k largest / frequent” → Heap / Priority Queue
* “all combinations / subsets” → Backtracking
* “cycle detection” → Fast & Slow pointers
* “graph shortest path (unweighted)” → BFS
* “range queries” → Prefix Sum
* “dp” keywords → Recurrence + memoization

## Step 2: Outline the Template

Each pattern file contains:

* general strategy
* template pseudocode
* visualization
* complexity
* edge cases

## Step 3: Practice with Pattern-Aligned Problems

Each section contains recommended problems. Practice them to internalize the pattern.

---

# Visual Overview of Patterns

```
               ┌────────────────┐
               │ Identify Input │
               │ Pattern Hints  │
               └───────┬────────┘
                       │
       ┌───────────────┼────────────────┬────────────────┐
       │               │                │                │
Sliding Window   Two Pointers     Graph/Tree      Backtracking/DP
Continuous       Sorted/Input     BFS/DFS/Topo    Subsets/Knapsack
structures       optimization     dependencies    exponential search
```

---

# Interview Tips

### 1. State the Pattern Early

Interviewers like structured thinking.
Start with:
“Based on the problem constraints, this follows the sliding-window pattern.”

### 2. Justify the Pattern Choice

Explain **why** the pattern fits.

### 3. Mention Time and Space Complexity

Include worst-case analysis.

### 4. Write Clean Code Using the Recognized Pattern

Most FAANG interviews expect:

* linear or log-linear solutions
* minimal extra memory
* clarity

### 5. Practice Variants

For each pattern, problems evolve. Example:
Sliding Window → smallest window, longest window, fixed size, variable size, counting windows, checking constraints.

---

# Recommended Practice Sets

### LeetCode

* Top 100 Liked
* Blind 75
* Pattern-based curated lists

### GFG

* Must do DSA list (important for conceptual grounding)

### Codeforces

* Div 2 A/B pattern-based practice

---

# Structure of This Folder

Each file contains:

* a deep explanation of the pattern
* template pseudocode
* multiple variations
* edge cases
* complexity breakdown
* curated problems

---

# Final Note

Patterns make the difference between struggling and solving confidently.
Use them to **reduce cognitive load**, identify optimal approaches faster, and become interview-ready.

Happy practicing!

