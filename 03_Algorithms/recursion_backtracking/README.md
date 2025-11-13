# **Recursion & Backtracking — Overview & Study Guide**

---

## **1. What This Folder Contains**

This directory covers **core recursive patterns** and **classic backtracking problems** — essential for interviews, contests, and foundational algorithmic thinking.

You will find:

* Theory of **recursion**
* Theory of **backtracking**
* Classic problems:

  * N-Queens
  * Rat in a Maze
  * Word Search
  * Sudoku Solver
  * Subsets / Combinations / Permutations

Each file explains intuition + pseudocode + complexities + variations.

---

## **2. Recursion — Quick Summary**

Recursion = a function calling itself to solve subproblems.

Key components:

1. **Base Case**
2. **Recursive Case**
3. **Progress toward base case**

Used for:

* Divide & Conquer
* Tree traversals
* DP (top–down)
* Mathematical functions (factorial, Fibonacci)

---

## **3. Backtracking — Quick Summary**

Backtracking = recursion + **undoing choices**.

Approach:

1. Make a choice
2. Recurse
3. Undo the choice (backtrack)
4. Try next choice

Used for:

* Generating all configurations
* Constraint satisfaction
* Exploring search space trees

---

## **4. Core Problem Patterns**

### **A. Combination/Subset generation**

* Subsets
* Combinations
* Combination Sum
* Phone keypad combinations

### **B. Permutations & ordering**

* Permutations
* Unique permutations
* Next permutation

### **C. Grid/Path-based backtracking**

* Rat in a Maze
* Word Search
* Flood fill
* Solving puzzles

### **D. Constraint satisfaction**

* N-Queens
* Sudoku Solver
* Knight’s tour

---

## **5. Universal Backtracking Template**

```
backtrack(state):
    if goal reached:
        save state
        return

    for each valid choice c:
        apply c
        backtrack(next_state)
        undo c
```

This solves 90% of backtracking interview questions.

---

## **6. When to Use Recursion / Backtracking**

You should choose these techniques when:

* Problem asks to **generate all possibilities**
* Order of decisions matters
* You need to **explore paths** through a grid
* Constraints prune invalid paths
* DP is too rigid (multiple dimensions of changing state)

---

## **7. Complexity Overview**

Most backtracking problems are **exponential**:

| Problem      | Complexity         |
| ------------ | ------------------ |
| Subsets      | O(N · 2^N)         |
| Permutations | O(N · N!)          |
| N-Queens     | O(N!) approx       |
| Word Search  | O(NM · 4^L)        |
| Sudoku       | O(9^81) worst-case |

---

## **8. Must-Know Interview Problems**

| Topic             | Problem                |
| ----------------- | ---------------------- |
| Backtracking      | N-Queens               |
| Backtracking      | Sudoku                 |
| Backtracking      | Word Search            |
| Combinatorics     | Subsets & Permutations |
| Path Search       | Rat in a Maze          |
| DFS + Constraints | Combination Sum        |

FAANG relies heavily on these questions to test clarity of thought, recursion depth control, and pruning strategies.

---

## **9. Recommended Practice Set**

| Platform   | Problems                                |
| ---------- | --------------------------------------- |
| LeetCode   | 46, 47, 39, 40, 22, 79, 51, 52, 37      |
| GFG        | Rat Maze, Sudoku, N-Queens, Word Search |
| Codeforces | Bruteforce/bitmask generation sets      |
| AtCoder    | Recursion DFS problems                  |

---

## **10. Tips for Mastery**

* Understand “**try → recurse → undo**”
* Draw recursion trees for clarity
* Memorize key pruning ideas
* Always track **visited** states properly
* Start small (N=2/3) to debug logic
* Practice dry-runs before coding

---
