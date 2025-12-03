# **N-Queens Problem — Recursion & Backtracking**

---

## **1. Problem Definition**

The **N-Queens Problem** asks:

> Place **N queens** on an **N × N chessboard** such that **no two queens attack each other**.

Queens attack along:

* **same row**
* **same column**
* **same diagonal** (both major and minor)

Goal: return **all valid configurations**.

---

## **2. Mathematical / Logical Intuition**

A queen placed at position:
(row = r, col = c)

Attacks:

```
Major diagonal ID    = r - c
Minor diagonal ID    = r + c
```

Thus, to ensure safety:

* Each **column** must be unique.
* Each **r - c** must be unique.
* Each **r + c** must be unique.

This gives the backtracking state checks.

---

## **3. Visual Understanding (ASCII Board)**

Example for N = 4, one valid solution:

```
. Q . .
. . . Q
Q . . .
. . Q .
```

Represented as indexes:

```
Row 0 → Col 1
Row 1 → Col 3
Row 2 → Col 0
Row 3 → Col 2
```

---

## **4. Backtracking Strategy**

We build the solution **row by row**.

At each row:

1. Try placing queen at each column
2. Check if placement is safe using sets:

   * columns
   * diag1 (r - c)
   * diag2 (r + c)
3. If safe → place queen → recurse to next row
4. Else → skip
5. When row reaches N → store configuration

---

## **5. Pseudocode (Clear & CP-Friendly)**

```
solve(row):
    if row == n:
        add current board to answers
        return

    for col in [0..n-1]:
        if col not in usedCols
           and (row-col) not in usedDiag1
           and (row+col) not in usedDiag2:

            place queen at (row, col)
            mark col, diag1, diag2

            solve(row + 1)

            unplace queen
            unmark col, diag1, diag2
```

---

## **6. Time & Space Complexity**

| Metric    | Value | Reason                                                               |
| --------- | ----- | -------------------------------------------------------------------- |
| **Time**  | O(N!) | Each row chooses unique columns; pruning reduces but worst-case ~ N! |
| **Space** | O(N)  | Storing sets + recursion stack                                       |

Finding *all* solutions always requires exponential time.

---

## **7. Variations**

### ** Count Solutions Only (no board output)**

Track counter instead of storing configurations.

### ** Print Only First Configuration**

Break early when first valid board is found.

### ** Generalized N-Rooks / N-Bishops**

Remove diagonal constraints etc.

---

## **8. Common Mistakes & Edge Cases**

* Forgetting to unmark (backtracking failure).
* Miscomputing diagonals (`row - col` vs `row + col`).
* Storing board incorrectly (deep copying needed).
* N = 1 → 1 solution
* N = 2 or N = 3 → **0 solutions**

---

## **9. Interview Tips (FAANG / GATE)**

* Often asked as a test of **recursion depth**, **branch pruning**, and **mathematical constraints**.
* Typical follow-ups:

  * “Can you optimize with bitmasks?”
  * “Can you just return count?”
  * “How would you handle very large N?” (bitmask DP)
* GATE uses diagonal logic for theory MCQs.

---

## **10. Practice Problems**

| Platform    | Problem                          |
| ----------- | -------------------------------- |
| LeetCode    | N-Queens (#51)                   |
| LeetCode    | N-Queens II (#52)                |
| GFG         | Solve N-Queen                    |
| Codeforces  | Backtracking simulation problems |
| HackerEarth | Recursion-classic problems       |

---
