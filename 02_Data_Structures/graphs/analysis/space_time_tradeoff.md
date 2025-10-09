# Graphs: Space-Time Trade-offs

## Introduction

Graphs are widely used in computer science, from social networks to routing algorithms.
Choosing the right **representation** and **algorithm** often involves trade-offs between **space** and **time** complexity.

This guide explains:

- How different graph representations affect performance.
- Trade-offs in common graph algorithms.
- Practical considerations for sparse vs dense graphs.

---

## 1. Graph Representations

### 1.1 Adjacency List

- Stores a list of neighbors for each vertex.
- **Efficient for sparse graphs**.

```

Example: Undirected Graph
0 -- 1
\|    |
2 -- 3

Adjacency List:
0: 1,2
1: 0,3
2: 0,3
3: 1,2

```

**Trade-offs:**

| Operation           | Time Complexity | Space Complexity |
|--------------------|----------------|----------------|
| Edge lookup         | O(degree(u))   | O(V + E)       |
| Add edge            | O(1)           | O(V + E)       |
| Iterate neighbors   | O(degree(u))   | O(V + E)       |

> ✅ Space-efficient for sparse graphs
> ❌ Edge lookup is slower for dense graphs

---

### 1.2 Adjacency Matrix

- Uses a VxV matrix to store edge presence.
- **Ideal for dense graphs**.

```

Adjacency Matrix:
0 1 2 3
0 0 1 1 0
1 1 0 0 1
2 1 0 0 1
3 0 1 1 0

```

**Trade-offs:**

| Operation           | Time Complexity | Space Complexity |
|--------------------|----------------|----------------|
| Edge lookup         | O(1)           | O(V^2)         |
| Add/remove edge     | O(1)           | O(V^2)         |
| Iterate neighbors   | O(V)           | O(V^2)         |

> ✅ Fast edge lookup
> ❌ Space-heavy for sparse graphs

---

### 1.3 Hybrid Representations

- **Edge List**: store all edges as tuples `(u, v)`
  - O(E) space, slow lookups
- **Compressed Sparse Row (CSR)**: used in scientific computing
  - Optimized for **space and neighbor iteration**

---

## 2. Algorithmic Trade-offs

### 2.1 BFS / DFS

| Graph Type        | Representation    | Time Complexity           | Space Complexity         |
|------------------|-----------------|--------------------------|-------------------------|
| Sparse           | List             | O(V + E)                | O(V) (visited + queue) |
| Dense            | Matrix           | O(V^2)                  | O(V)                   |

- **Trade-off:**
  - List → less memory, O(V + E) traversal
  - Matrix → simple edge check, more memory

---

### 2.2 Shortest Path

| Algorithm        | Representation   | Trade-offs                                  |
|-----------------|----------------|---------------------------------------------|
| Dijkstra (Min-Heap) | Adjacency List | Faster on sparse graphs (O(E log V))       |
| Dijkstra          | Adjacency Matrix | Dense graphs only; O(V^2) acceptable      |
| Floyd-Warshall    | Matrix           | O(V^3) time, O(V^2) space; works for all pairs |

---

### 2.3 Minimum Spanning Tree

| Algorithm       | Representation   | Trade-offs                                  |
|-----------------|----------------|---------------------------------------------|
| Prim (Heap)      | List             | Sparse → O(E log V)                        |
| Prim             | Matrix           | Dense → O(V^2)                             |
| Kruskal          | Edge List        | O(E log E) for sorting edges               |

---

## 3. General Guidelines

- **Sparse graphs (E << V²)** → Adjacency list + heap-based algorithms
- **Dense graphs (E ≈ V²)** → Adjacency matrix + simpler array-based algorithms
- **Memory-sensitive applications** → prefer adjacency list
- **Frequent edge lookups** → matrix is advantageous

---

## 4. Visual Summary

Sparse Graphs:
Adjacency List  ✅  | Adjacency Matrix ❌

Dense Graphs:
Adjacency Matrix ✅  | Adjacency List ❌

Edge Lookup:
Matrix O(1) ✅ | List O(degree(u)) ❌

Neighbor Iteration:
List O(degree(u)) ✅ | Matrix O(V) ❌

---

## 5. Interview Tips

- Always **analyze graph density** before choosing representation.
- Be ready to **justify time-space trade-offs** during FAANG interviews.
- Common pitfalls:
  - Using a matrix for sparse graphs → wasted memory
  - Using list for dense graphs with frequent edge checks → slow
- Practice converting **list ↔ matrix** in O(V²) time.

---

## 6. Practice Problems

| Problem                                     | Source          |
|--------------------------------------------|----------------|
| Shortest Path in Unweighted Graph          | LeetCode 787   |
| Detect Cycle in Graph                       | GFG            |
| Minimum Spanning Tree                       | LeetCode 1135  |
| Connected Components in Graph               | GFG            |
| Graph Representation Conversion             | Codeforces     |

---

## 7. Summary

- **Representation choice** directly affects space and runtime.
- **Adjacency List:** Sparse graphs, memory-efficient, slower edge lookup
- **Adjacency Matrix:** Dense graphs, fast edge lookup, higher memory
- **Algorithm choice** must align with representation and graph density
- Understanding **space-time trade-offs** is crucial for **efficient real-world graph implementations**.

---
