# Graphs – Theory, Intuition, and Interview Guide

Graphs are one of the most important data structures in computer science.
They represent relationships between entities, making them ideal for modeling:

* networks (social networks, roads)
* dependency structures (tasks, courses)
* trees (special type of graph)
* grids (matrix-based problems)

This file gives a **complete overview** needed for interview preparation.

---

# 1. What is a Graph?

A **graph** is a collection of:

* nodes (vertices)
* edges (connections between nodes)

Represented mathematically as:

G = (V, E)

Where:

* V = set of vertices
* E = set of edges (ordered or unordered)

---

# 2. Types of Graphs

### By Edge Direction

* Directed graph (u → v)
* Undirected graph (u — v)

### By Weights

* Weighted (edge has cost/weight)
* Unweighted

### By Cycles

* Cyclic graphs
* Acyclic graphs

### Special graphs

* Tree (connected + acyclic + n−1 edges)
* DAG (Directed Acyclic Graph)
* Bipartite graph
* Complete graph

---

# 3. How Graphs Are Represented

Three main approaches:

### 1. Adjacency List (most used)

Space: O(V + E)

Example (undirected):

0: 1 2
1: 0
2: 0 3
3: 2

### 2. Adjacency Matrix

Space: O(V²)

Matrix M where:

M[i][j] = 1 if edge exists, else 0

Useful for dense graphs.

### 3. Edge List

Space: O(E)

Simply store pairs (u, v)

Used in algorithms like Kruskal.

---

# 4. Core Graph Traversals

## Breadth-First Search (BFS)

* Layer-by-layer traversal
* Uses queue
* Good for shortest paths in unweighted graphs

Time: O(V + E)

## Depth-First Search (DFS)

* Goes deep first
* Uses recursion or stack
* Good for components, cycle detection

Time: O(V + E)

---

# 5. Important Graph Concepts

### Connected Components

Using DFS/BFS to group connected nodes.

### Cycle Detection

* Directed → DFS + recursion stack
* Undirected → DFS + parent tracking

### Bipartite Check

Color graph with two colors; conflict means not bipartite.

### Topological Sorting

For DAGs only.

Two approaches:

* Kahn's algorithm (BFS + in-degree)
* DFS + stack

### Shortest Paths

| Case                        | Algorithm      | Complexity |
| --------------------------- | -------------- | ---------- |
| Unweighted                  | BFS            | O(V+E)     |
| Weighted (positive)         | Dijkstra       | O(E log V) |
| Weighted (negative allowed) | Bellman-Ford   | O(VE)      |
| All-pairs                   | Floyd-Warshall | O(V³)      |

### Minimum Spanning Tree

* Kruskal (sort edges + DSU)
* Prim (priority queue)

Both O(E log V)

---

# 6. Graph Use Cases in Interviews

### Most common patterns asked:

* Traversals
* Is graph cyclic?
* Count components
* Words and transformation problems
* Grid BFS/DFS (matrix)
* Topological sort
* Dijkstra’s algorithm
* MST problems
* Tree problems (LCA, Diameter)
* SCC in directed graphs (advanced)

---

# 7. Visual Representations

### Simple undirected graph

```
0 --- 1
|     |
2 --- 3
```

### BFS Levels Example

```
Start = 0

Level 0: 0
Level 1: 1, 2
Level 2: 3
```

### Directed Cycle

```
1 → 2 → 3
    ↑    ↓
    ←-----
```

### Tree (special graph)

```
5
├── 3
└── 8
```

---

# 8. Common Pitfalls

1. Forgetting to mark visited nodes
2. Using DFS for shortest path (BFS needed)
3. Wrong direction handling in directed graphs
4. Mixing 0-indexed and 1-indexed nodes
5. Infinite loops due to missing visited set
6. Not rebuilding in-degree array in topo sort

---

# 9. Interview Tips

* BFS is almost always used for shortest paths in unweighted graphs.
* In grid problems, treat each cell as a node with up to 4 neighbors.
* Learn DFS both recursively and iteratively.
* For DAG problems, ALWAYS check for cycles.
* Dijkstra fails with negative weights; use Bellman-Ford.
* MST problems often require DSU.
* Practice explaining adjacency list vs matrix and time complexities.

---

# 10. Practice Problems

### Must Do (High-frequency)

* BFS Traversal
* DFS Traversal
* Number of Islands (grid)
* Detect Cycle (directed + undirected)
* Topological Sort (Kahn)
* Dijkstra
* Kruskal MST
* Clone Graph

### Recommended

* Bipartite Check
* Word Ladder
* Rotten Oranges
* Alien Dictionary
* All-Pairs Shortest Path

### Advanced

* Articulation Points
* Bridges
* Tarjan SCC
* Kosaraju SCC

---

# 11. How to Study Graphs Efficiently

1. Start with BFS, DFS
2. Practice simplest implementations
3. Move to applications (cycle detection, components)
4. Study shortest paths and MST
5. Tackle grid problems
6. Then graph theory: LCA, SCC, bridges, articulation points

---
