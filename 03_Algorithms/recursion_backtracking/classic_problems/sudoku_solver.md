# **Sudoku Solver — Backtracking Algorithm**

---

## **1. Problem Definition**

Given a **9×9 Sudoku grid** containing digits `1–9` and empty cells (`.` or `0`), fill the grid so that:

* Each row contains digits 1–9 exactly once
* Each column contains digits 1–9 exactly once
* Each 3×3 subgrid contains digits 1–9 exactly once

This is a **constraint satisfaction problem** solved elegantly using **backtracking**.

---

## **2. Core Intuition**

Sudoku solving is:

1. **Pick an empty cell**
2. Try placing digits `1–9`
3. For each digit:

   * Check if valid (row, column, box constraints)
   * If valid → recurse to next cell
   * If recursion fails → undo and try next digit
4. If all digits fail → backtrack

This is DFS over the solution space.

---

## **3. Board Representation**

Example grid:

```
5 3 . | . 7 . | . . .
6 . . | 1 9 5 | . . .
. 9 8 | . . . | . 6 .

8 . . | . 6 . | . . 3
4 . . | 8 . 3 | . . 1
7 . . | . 2 . | . . 6

. 6 . | . . . | 2 8 .
. . . | 4 1 9 | . . 5
. . . | . 8 . | . 7 9
```

---

## **4. Validity Check**

A digit `d` can be placed at `(r,c)` iff:

* Row `r` has no `d`
* Column `c` has no `d`
* The 3×3 box `(r/3, c/3)` has no `d`

---

## **5. Pseudocode**

```
solve():
    for r in 0..8:
        for c in 0..8:
            if board[r][c] is empty:
                for d in '1' to '9':
                    if valid(r, c, d):
                        board[r][c] = d
                        if solve():
                            return true
                        board[r][c] = empty
                return false
    return true
```

**valid(r,c,d):**

```
for i in 0..8:
    if board[r][i] == d: return false
    if board[i][c] == d: return false

boxR = (r / 3) * 3
boxC = (c / 3) * 3
for i in 0..2:
    for j in 0..2:
        if board[boxR+i][boxC+j] == d:
            return false

return true
```

---

## **6. Complexity Analysis**

| Metric    | Value                                              |
| --------- | -------------------------------------------------- |
| **Time**  | Worst-case O(9^(81)) but heavily pruned → feasible |
| **Space** | O(81) recursion depth                              |

---

## **7. Key Backtracking Principles**

* Always **undo the assignment** when backtracking
* Try digits in numeric order for deterministic output
* Stop immediately after finding one valid solution
* Use `valid()` checks to prune early

---

## **8. Variations**

* Solve multiple Sudoku grids
* Count the number of valid solutions
* Check if a Sudoku is solvable / ambiguous
* Optimize using:

  * **Hash sets** for rows/cols/boxes
  * **Least-empty-cell heuristic**
  * **Bitmasks** (very fast)

---

## **9. Edge Cases**

* Already solved grid
* Multiple solutions
* No solution
* Invalid starting configuration

---

## **10. Interview Tips**

* Backtracking is essential — emphasize **try → recurse → undo**
* They may ask optimizations:

  * Using row/col/box sets
  * Using bitmask & picking the cell with minimal candidates
* GATE tends to ask complexity + recursion tree style questions
* FAANG may ask generating puzzles or verifying Sudoku validity

---

## **11. Practice Problems**

| Platform   | Problem                          |
| ---------- | -------------------------------- |
| LeetCode   | Sudoku Solver (#37)              |
| GFG        | Solve Sudoku                     |
| Codeforces | Grid-based backtracking problems |
| HackerRank | CSP variations                   |

---
