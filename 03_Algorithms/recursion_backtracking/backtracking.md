# **Backtracking — Complete Theory Guide**

---

## **1. What is Backtracking?**

Backtracking is a **systematic trial-and-error strategy** for solving problems where we:

1. Build the solution **step-by-step**
2. At any step, if the partial solution is invalid → **undo (backtrack)** and try another option

It is essentially **DFS with undoing of choices**.

Common use-cases:

* Combinatorics (subsets, permutations, combinations)
* Grid path problems (maze, word search, sudoku)
* Constraint satisfaction problems (N-Queens)
* Optimization problems (knapsack variants)

---

## **2. Core Intuition**

Backtracking explores a **state space tree**:

```
                         (root)
                /         |         \
           choice1     choice2     choice3
           /     \        ...
      valid?    backtrack
```

At each node:

1. Make a choice → recurse
2. If invalid → backtrack
3. If valid → continue exploring
4. If goal reached → record solution

---

## **3. Template Strategy**

Every backtracking solution follows these steps:

1. **Define the state** (what represents progress?)
2. **Define choices** at each step
3. **Check constraints**
4. **Recurse with the choice**
5. **Undo the choice**

---

## **4. Universal Backtracking Template (Pseudocode)**

```
backtrack(state):
    if state is complete:
        add state to result
        return

    for each valid choice c:
        apply choice c
        backtrack(next state)
        undo choice c
```

This template works for permutations, subsets, N-Queens, maze solving, word search, sudoku, all CF brute-force tasks, etc.

---

## **5. Visual Example (Subsets)**

```
Start: []
  |
  +-- include 1 → [1]
  |      |
  |      +-- include 2 → [1,2]
  |      +-- exclude 2 → [1]
  |
  +-- exclude 1 → []
         |
         +-- include 2 → [2]
         +-- exclude 2 → []
```

Each path from root to leaf is one possible subset.

---

## **6. When to Use Backtracking?**

Use it when:

* You must **generate all possibilities**
* You must **search through combinations** of decisions
* You need to **undo decisions** after recursive calls
* Constraints eliminate large portions of the search space

When **DP** is unsuitable because states depend on multiple moving parts.

---

## **7. Time & Space Complexity**

Backtracking usually has **exponential complexity**:

* Subsets → `O(N * 2^N)`
* Permutations → `O(N * N!)`
* N-Queens → approx `O(N!)`
* Sudoku → worst-case `O(9^81)` (but pruned dramatically)

**Space:** `O(depth)` = O(N) usually.

---

## **8. Variations / Patterns**

### **1. Choice-based backtracking**

Examples:

* Generate permutations
* Generate combinations
* Generate subsets

### **2. Path-based backtracking (grid)**

Examples:

* Rat in a maze
* Word search
* Counting paths

### **3. Constraint-based backtracking**

Examples:

* N-Queens
* Sudoku
* Knights Tour

### **4. Optimization with pruning**

Examples:

* Branch & Bound
* Minimum steps problems

---

## **9. Pruning Techniques**

Pruning improves efficiency:

* **Check constraints early**
* Sort choices (lexicographic subsets/permutations)
* Use sets/hash maps for fast membership checks
* Use boolean arrays for visited
* Stop recursion early when impossible to continue

Example:
In N-Queens, checking columns/diagonals avoids repeated conflicts.

---

## **10. Common Mistakes**

* Forgetting to **undo** the choice
* Using global shared state incorrectly
* Misplacing the base case
* Not copying when needed
* Infinite recursion due to missing constraints

---

## **11. Interview Strategy**

FAANG interviewers expect:

* Quick recognition of backtracking pattern
* Clear explanation of **choice → explore → undo**
* Good pruning ideas
* Writing the template cleanly
* Complexity estimation

Most common backtracking interview problems:

* Subsets & Permutations
* N-Queens
* Word Search
* Sudoku Solver
* Generate Parentheses
* Letter Combinations of Phone Number

---

## **12. Practice Problems**

| Platform    | Problems                                                                                  |
| ----------- | ----------------------------------------------------------------------------------------- |
| LeetCode    | Subsets (#78), Permutations (#46), N-Queens (#51), Word Search (#79), Sudoku Solver (#37) |
| GFG         | Rat in a Maze, Solve Sudoku, Power Set                                                    |
| Codeforces  | Grid brute force, bitmask search, combinatorial generation                                |
| HackerEarth | Classic backtracking contests                                                             |

---
