# **Word Search — Backtracking on Grid**

---

## **1. Problem Definition**

Given a **2D grid of characters** and a **target word**, determine whether the word exists in the grid.

Rules:

* You may move **up, down, left, right**.
* You cannot reuse the same cell twice in the same path.
* Word must be formed **sequentially**.

Example:

Grid:

```
A B C E
S F C S
A D E E
```

Word: `"ABCCED"` → **True**

---

## **2. Intuition**

This is a **graph search** problem on a grid.

For each cell:

1. If its character matches the first letter:
2. Start DFS/backtracking
3. Move in all **four directions**
4. Track visited cells to avoid revisiting
5. If all characters match → word exists

This is structurally identical to Rat in Maze + pattern matching.

---

## **3. Visual Idea**

Searching for `"SEE"`:

```
S F C S
↑       ↓
E       E
↑
E
```

Backtracking explores all possible paths.

---

## **4. Core Conditions**

At each `(r,c,k)`:

* `k` = index in word
* `board[r][c] == word[k]`
* Cell not already visited
* Move to neighbors for `k+1`

---

## **5. Pseudocode**

```
exists(word):
    for each cell (r,c):
        if dfs(r, c, 0):
            return true
    return false
```

`dfs(r, c, k):`

```
if k == len(word):
    return true

if out of bounds OR visited OR board[r][c] != word[k]:
    return false

mark visited[r][c] = true

for (dr,dc) in [(1,0),(0,1),(-1,0),(0,-1)]:
    if dfs(r+dr, c+dc, k+1):
        return true

mark visited[r][c] = false
return false
```

---

## **6. Complexity Analysis**

| Metric    | Value                         |
| --------- | ----------------------------- |
| **Time**  | O(N × M × 4^L)                |
| **Space** | O(L) recursion + visited grid |

Where `L` = word length.

---

## **7. Variations**

* Count occurrences of a word
* Word Search II (Trie + Backtracking) — LeetCode Hard
* Search diagonally or in 8 directions
* Find all words from a dictionary

---

## **8. Edge Cases**

* Empty word → true
* Word length > grid cells → false
* Single cell grid
* Repeated characters require careful visited marking

---

## **9. Interview Tips**

* Make sure to **unmark visited** when backtracking
* Trie optimization is important for multiple-word search
* Explain pruning when mismatch occurs early
* FAANG often asks Word Search II — build Trie + DFS

---

## **10. Practice Problems**

| Platform   | Problem                              |
| ---------- | ------------------------------------ |
| LeetCode   | Word Search (#79)                    |
| LeetCode   | Word Search II (#212)                |
| GFG        | Search in Matrix                     |
| Codeforces | Grid walk / string matching problems |

---
