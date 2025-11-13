# **Breadth-First Search (BFS)**

---

## **1. What Is BFS?**

**BFS (Breadth-First Search)** is a graph traversal algorithm that explores nodes **level by level**.

It uses a **queue** and is ideal for:

* Unweighted shortest paths
* Level-order traversal
* Connected components
* Bipartite checking

Works for both **graphs** and **trees**.

---

## **2. Core Intuition**

BFS expands outward in **layers**:

1. Visit all nodes at distance 1
2. Then distance 2
3. Then distance 3
   … and so on

This ensures shortest paths in **unweighted** graphs.

---

## **3. Visual Intuition (ASCII)**

Graph:

1 — 2 — 3
|     \
4 — 5 — 6

BFS from node 1:

1
↓
2 4
↓
3 5
↓
6

Levels:
L0: 1
L1: 2,4
L2: 3,5
L3: 6

---

## **4. BFS Algorithm – Step-by-Step**

1. Initialize queue
2. Mark source node visited
3. Push source into queue
4. While queue not empty:

   * Pop front
   * Process it
   * Push all unvisited neighbors
5. Continue until traversal ends

---

## **5. Pseudocode (No Code Block)**

Initialize visited[] = false
queue.push(src)
visited[src] = true

while queue not empty:
u = queue.pop_front()
process(u)
for v in adj[u]:
if not visited[v]:
visited[v] = true
queue.push(v)

---

## **6. Applications of BFS**

### **A. Shortest Path in Unweighted Graph**

dist[src] = 0
dist[v] = dist[u] + 1

### **B. Check if Graph Is Bipartite**

Use BFS to color nodes alternately.

### **C. Find Connected Components**

Run BFS from every unvisited node.

### **D. Flood Fill / Multi-source BFS**

Used in grid-based problems (rot oranges, fire spread).

---

## **7. BFS on Grids**

Grid BFS uses (row, col) pairs.

Example directions:

dirs = [(1,0), (-1,0), (0,1), (0,-1)]

---

## **8. Complexity**

| Metric | Value        |
| ------ | ------------ |
| Time   | **O(V + E)** |
| Space  | **O(V)**     |

Queue + visited array dominate memory.

---

## **9. Edge Cases**

* Disconnected graph → run BFS multiple times
* Directed graph → follow directed edges
* Parallel edges → harmless
* Self-loops → ignore

---

## **10. Interview Tips**

FAANG often tests BFS in:

* Shortest path in unweighted grid
* Multi-source BFS
* Word ladder style problems
* Graph bipartiteness
* Maze navigation

Be ready to:

* Explain BFS level structure
* Modify BFS to store paths
* Use BFS for implicit graphs (e.g., number transformations)

---

## **11. Practice Problems**

**LeetCode:**

* 200 — Number of Islands
* 1218 — Shortest Path in Binary Matrix
* 994 — Rotting Oranges
* 286 — Walls and Gates

**GFG:**

* BFS Traversal
* Bipartite Graph Checking

**Codeforces:**

* 520B — Two Buttons
* 327A — Flipping Game (implicit BFS logic)

---
