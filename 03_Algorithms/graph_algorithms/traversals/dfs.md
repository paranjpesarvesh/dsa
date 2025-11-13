# **Depth-First Search (DFS)**

---

## **1. What Is DFS?**

**DFS (Depth-First Search)** is a graph traversal algorithm that explores as far as possible along each branch before backtracking.

It uses either:

* **Recursion**
* **Explicit stack**

DFS is ideal for:

* Pathfinding
* Cycle detection
* Topological sorting
* Connected components
* Articulation points & bridges
* SCC (Tarjan/Kosaraju)

---

## **2. Core Intuition**

DFS dives “deep”:

1. Visit a node
2. Explore first neighbor fully
3. Backtrack
4. Explore next neighbor

This depth-first approach naturally forms a **DFS tree**.

---

## **3. Visual Intuition (ASCII)**

Graph:

1 — 2 — 3
|     \
4 — 5 — 6

DFS from 1 (one possible order):

1
↓
2
↓
3
↓
6
(backtrack)
5
(backtrack)
4

Different valid DFS orders exist depending on adjacency order.

---

## **4. DFS Algorithm – Step-by-Step**

### **Recursive Version**

1. Mark node visited
2. Process node
3. Explore all unvisited neighbors recursively

### **Iterative Version**

1. Push source onto stack
2. Pop top, process
3. Push all unvisited neighbors
4. Repeat

---

## **5. DFS Pseudocode (Recursive)**

visited[] = false

dfs(u):
visited[u] = true
process(u)
for v in adj[u]:
if not visited[v]:
dfs(v)

---

## **6. DFS Pseudocode (Iterative, No Code Block)**

stack.push(src)

while stack not empty:
u = stack.pop()
if not visited[u]:
visited[u] = true
process(u)
for v in adj[u]:
if not visited[v]:
stack.push(v)

---

## **7. Applications of DFS**

### **A. Connected Components**

Run DFS on every unvisited node.

### **B. Cycle Detection**

* Undirected → detect back-edges
* Directed → detect nodes already in recursion stack

### **C. Topological Sort**

Add node to list after exploring neighbors.

### **D. Bridges & Articulation Points**

Use disc[] and low[] arrays.

### **E. SCC Algorithms**

Tarjan and Kosaraju rely on DFS orderings.

---

## **8. DFS on Grids**

Use 4-direction or 8-direction movements.

dirs = [(1,0),(-1,0),(0,1),(0,-1)]

Used in:

* Counting islands
* Flood fill
* Maze solving

---

## **9. Complexity**

| Metric | Value                                |
| ------ | ------------------------------------ |
| Time   | **O(V + E)**                         |
| Space  | **O(V)** (visited + recursion stack) |

---

## **10. Edge Cases**

* Disconnected graph
* Deep recursion → stack overflow risk
* Self-loops → ignore or treat depending on problem
* Directed edges → recursion stack needed for cycle detection

---

## **11. Interview Tips**

FAANG frequently tests DFS for:

* Graph traversal
* Cycle detection
* Island problems
* Topological sort
* SCC
* Backtracking search problems

Be ready to:

* Show recursive vs iterative
* Explain recursion stack behavior
* Trace DFS tree
* Handle disconnected graphs gracefully

---

## **12. Practice Problems**

**LeetCode:**

* 200 — Number of Islands
* 695 — Max Area of Island
* 547 — Number of Provinces
* 417 — Pacific Atlantic Water Flow

**GFG:**

* DFS Traversal
* Detect Cycle in Directed/Undirected Graph

**Codeforces:**

* 510B — Fox and Two Dots
* 580C — Kefa and Park

---
