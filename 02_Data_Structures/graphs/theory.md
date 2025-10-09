# Graphs – Theory

Graphs are **fundamental data structures** used to represent relationships between objects. They are widely used in algorithms, networking, and many real-world applications.

---

## 1. Definition

A **graph** $G$ is a collection of:

* **Vertices (Nodes)** $V$
* **Edges (Connections)** $E$ between vertices

Formally:

$$
G = (V, E)
$$

---

## 2. Types of Graphs

| Type                         | Description                                 | Example                     |
| ---------------------------- | ------------------------------------------- | --------------------------- |
| **Directed Graph (Digraph)** | Edges have a direction                      | Web page links              |
| **Undirected Graph**         | Edges have no direction                     | Facebook friends            |
| **Weighted Graph**           | Edges carry weights/costs                   | Road network with distances |
| **Unweighted Graph**         | All edges are equal                         | Simple connectivity         |
| **Cyclic / Acyclic**         | Contains cycles / does not contain cycles   | Task scheduling (DAG)       |
| **Connected / Disconnected** | All vertices reachable / not reachable      | Network connectivity        |
| **Sparse / Dense**           | Few edges / many edges relative to vertices | Social networks             |

---

## 3. Graph Representation

### 3.1 Adjacency Matrix

* A $V \times V$ matrix
* `matrix[i][j] = 1` if edge exists (or weight)
* **Space:** $O(V^2)$
* **Pros:** Fast edge lookup
* **Cons:** Wasteful for sparse graphs

```
Matrix Example (Undirected Graph):
Vertices: 0,1,2
Edges: 0-1, 1-2
Adjacency Matrix:
  0 1 2
0 0 1 0
1 1 0 1
2 0 1 0
```

### 3.2 Adjacency List

* List of neighbors for each vertex
* **Space:** $O(V + E)$
* **Pros:** Efficient for sparse graphs
* **Cons:** Edge lookup slower

```
Adjacency List Example:
0 -> 1
1 -> 0, 2
2 -> 1
```

---

## 4. Graph Terminology

* **Degree:** Number of edges incident on a vertex
* **In-degree / Out-degree:** For directed graphs
* **Path:** Sequence of vertices connected by edges
* **Cycle:** Path where first and last vertices are same
* **Connected Component:** Subset of vertices where all are reachable
* **Tree:** Connected acyclic graph

---

## 5. Graph Traversals

### 5.1 Breadth-First Search (BFS)

* Explores vertices **level by level**
* Uses **queue**
* Applications:

  * Shortest path in unweighted graphs
  * Connectivity check

**Pseudocode:**

```
BFS(Graph G, start):
    create a queue Q
    mark start as visited
    enqueue start into Q
    while Q is not empty:
        vertex = dequeue Q
        for neighbor in adjacency_list[vertex]:
            if neighbor not visited:
                mark neighbor visited
                enqueue neighbor
```

**Complexity:**

* Time: $O(V + E)$
* Space: $O(V)$

---

### 5.2 Depth-First Search (DFS)

* Explores as far as possible along a branch
* Uses **recursion / stack**
* Applications:

  * Cycle detection
  * Topological sorting
  * Connected components

**Pseudocode:**

```
DFS(Graph G, vertex, visited):
    mark vertex as visited
    for neighbor in adjacency_list[vertex]:
        if neighbor not visited:
            DFS(G, neighbor, visited)
```

**Complexity:**

* Time: $O(V + E)$
* Space: $O(V)$ recursion stack

---

## 6. Special Graph Types

### 6.1 Directed Acyclic Graph (DAG)

* No cycles
* Useful in **task scheduling**
* Can be **topologically sorted**

### 6.2 Weighted Graphs

* Edges have weights
* Used in **shortest path** or **minimum spanning tree** algorithms

---

## 7. Common Algorithms Overview

| Problem                            | Typical Algorithm      |
| ---------------------------------- | ---------------------- |
| Shortest Path (Unweighted)         | BFS                    |
| Shortest Path (Weighted, positive) | Dijkstra               |
| Shortest Path (Weighted, negative) | Bellman-Ford           |
| Minimum Spanning Tree              | Kruskal, Prim          |
| Detect Cycle                       | DFS / Union-Find       |
| Topological Sort                   | DFS / Kahn’s algorithm |

---

## 8. Interview Tips

* Always **clarify graph type**: directed/undirected, weighted/unweighted
* Check for **constraints**: sparse vs dense, input size
* Use **adjacency list** for sparse graphs, **matrix** for dense graphs
* Remember **edge cases**: disconnected graphs, self-loops
* Draw small **examples** to visualize before coding

---

## 9. Practice Problems

| Platform   | Problem                                                |
| ---------- | ------------------------------------------------------ |
| LeetCode   | Number of Islands, Course Schedule, Network Delay Time |
| GFG        | Detect Cycle in Graph, BFS/DFS traversal               |
| Codeforces | Graph Connectivity, Shortest Path variations           |

---

## 10. Visual Summary

```
Graph -> Undirected / Directed
      -> Weighted / Unweighted
      -> Cyclic / Acyclic
Representations:
  - Adjacency List
  - Adjacency Matrix
Traversals:
  - BFS (Queue)
  - DFS (Recursion/Stack)
Algorithms:
  - Shortest Path
  - MST
  - Topological Sort
Patterns:
  - Connected Components
  - Cycle Detection
  - Path Finding
```

---

This guide covers **graph theory essentials**, traversal techniques, and algorithmic patterns for interviews and competitive programming.

---
