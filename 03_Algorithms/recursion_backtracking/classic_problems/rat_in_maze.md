# **Rat in a Maze — Backtracking Approach**

---

## **1. Problem Definition**

You are given an `N x N` maze where:

* `1` → open cell
* `0` → blocked cell

A rat starts at `(0,0)` and wants to reach `(N-1,N-1)`.

You must **find all possible paths**, moving only through valid `1` cells.

Allowed moves (classic version):
**D = Down, L = Left, R = Right, U = Up**

---

## **2. Intuition**

This is a **search problem** over a grid.

At every cell `(r,c)`:

* Try all legal moves
* Recurse into safe cells
* Mark the cell as visited
* Backtrack after exploring

The recursion tree tries all possibilities and removes invalid ones (blocked or visited).

---

## **3. Visual Understanding**

Maze:

```
1 0 0
1 1 0
0 1 1
```

Paths:

```
Start → Down → Right → Down → Right → End
```

Recursion tree (D,R,U,L choices):

```
(0,0)
  |
  D
 (1,0)
  |
  R
 (1,1)
  |
  D
 (2,1)
  |
  R
 (2,2)
```

---

## **4. Safety Check**

A cell `(r,c)` is safe if:

* `0 ≤ r < N` and `0 ≤ c < N`
* `maze[r][c] == 1`
* `visited[r][c] == false`

---

## **5. Pseudocode (Standard Backtracking)**

```
solve(r, c, path):
    if (r,c) == destination:
        add path to result
        return

    mark visited[r][c] = true

    for (move, dr, dc) in [(D,1,0), (L,0,-1), (R,0,1), (U,-1,0)]:
        nr = r + dr
        nc = c + dc
        if safe(nr, nc):
            solve(nr, nc, path + move)

    mark visited[r][c] = false
```

---

## **6. Complexity Analysis**

| Metric    | Value                | Reason                     |
| --------- | -------------------- | -------------------------- |
| **Time**  | O(4^(N²)) worst-case | each cell explores 4 paths |
| **Space** | O(N²)                | visited matrix + recursion |

---

## **7. Variations**

* Find **one path**, not all
* Count number of paths
* Maze with **weighted** cells
* Maze allowing movement in **only two directions** (R, D)
* Maze with **portals** or **traps** (advanced CF problems)

---

## **8. Edge Cases**

* Start or end is blocked → no paths
* All zeros → no solution
* Single cell (N=1) → answer depends on value (0 or 1)

---

## **9. Interview Tips**

* Avoid revisiting cells → always maintain `visited`
* Order of moves matters (for lexicographic output)
* Be ready to follow-up:

  * “What if diagonal moves were allowed?”
  * “Can you return shortest path?”
* In GATE, recursion tree & complexity questions are common.

---

## **10. Practice Problems**

| Platform      | Problem                       |
| ------------- | ----------------------------- |
| GFG           | Rat in a Maze                 |
| LeetCode      | Word Search (similar style)   |
| Coding Ninjas | All Paths in Matrix           |
| Codeforces    | Grid path counting variations |

---
