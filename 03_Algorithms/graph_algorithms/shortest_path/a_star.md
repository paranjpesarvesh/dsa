# **A* Search Algorithm (A-Star)**

---

## **1. What Is A*?**

A* is a **best-first search algorithm** used to find the **shortest path** in weighted graphs, especially on grids or maps.

It combines:

* **g(n)** = actual cost from start to current node
* **h(n)** = heuristic estimate from current node to goal

Total priority score:
**f(n) = g(n) + h(n)**

A* picks the node with the **least f(n)**.

---

## **2. Why A*?**

Compared to Dijkstra:

* Much faster in practice
* Uses heuristics to guide the search
* Guarantees **optimal shortest path** if heuristic is admissible
* Perfect for:

  * Game pathfinding
  * Robot navigation
  * Maps (Google Maps uses variations)

---

## **3. Key Concept: Heuristic h(n)**

### **Admissible heuristic**

Never overestimates the actual remaining cost.
Ensures A* finds optimal shortest path.

Examples on grids:

* Manhattan distance (|dx| + |dy|)
* Euclidean distance
* Chebyshev distance

### **Consistent (monotonic) heuristic**

h(n) ≤ cost(n, n′) + h(n′)

Stronger condition → ensures no reprocessing.

---

## **4. Visual Intuition (ASCII Grid)**

S = Start
G = Goal

# = Obstacles

Grid:

S . . . #
. # . . .
. . . # G

A* explores nodes in direction of G guided by heuristics, unlike Dijkstra which expands in circles.

---

## **5. A* Algorithm – Step-by-Step**

1. Initialize:

   * g(start) = 0
   * h(start) = heuristic
   * f(start) = g + h
   * Use a **priority queue** for picking best node

2. While PQ not empty:

   * Pop node u with smallest f(u)
   * If u == goal → stop; reconstruct path
   * For each neighbor v:

     * temp = g(u) + weight(u,v)
     * If temp < g(v):

       * Update g(v), h(v), f(v)
       * Set parent[v] = u
       * Push into PQ

3. If goal reached → rebuild path using parent pointers.

---

## **6. Pseudocode (No Code Block)**

Initialize g[], h[], f[] to INF
g[start] = 0
h[start] = heuristic(start, goal)
f[start] = g[start] + h[start]

priorityQueue.push( (f[start], start) )

while queue not empty:
(f, u) = pop smallest f
if u == goal: break

```
for each neighbor v of u:
    temp = g[u] + w(u, v)
    if temp < g[v]:
        g[v] = temp
        h[v] = heuristic(v, goal)
        f[v] = g[v] + h[v]
        parent[v] = u
        push (f[v], v)
```

Reconstruct path from parent[]

---

## **7. Complexity**

Depends on the heuristic:

* Worst-case: **O(E log V)** (similar to Dijkstra)
* Best-case: **much faster** if heuristic guides well

Space: **O(V)**

---

## **8. Heuristic Choices (Grid)**

| Movement    | Heuristic                      |
| ----------- | ------------------------------ |
| 4-direction | Manhattan                      |
| 8-direction | Chebyshev                      |
| Euclidean   | For diagonal with varying cost |

---

## **9. Edge Cases**

* Heuristic too high → breaks optimality
* Heuristic = 0 → becomes Dijkstra
* Obstacles block path → no solution
* Negative weights → A* **cannot** handle

---

## **10. Interview Tips**

Common expectations:

* Explain f = g + h
* Admissible vs consistent heuristics
* Compare A* with BFS, Dijkstra
* Apply A* to grid with obstacles
* Show how heuristic influences expansion
* Draw visited/expanded nodes

FAANG often tests A* in:

* Pathfinding problems
* Game simulation
* Navigation/tracking interviews

---

## **11. Practice Problems**

**LeetCode:**

* 505 — The Maze II
* 499 — The Maze III
* 815 — Bus Routes (graph search + heuristics)

**GFG:**

* A* Search Implementation
* Shortest path on grid

**Codeforces:**

* 1760H — grid pathfinding variations
* 1775E1/E2 — heuristics + BFS hybrids

---
