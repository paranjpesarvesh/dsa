# Graph Representations: Comparisons

## Introduction

Graphs are one of the most versatile data structures in computer science.
Choosing the **right representation** for a graph is crucial for both **efficiency** and **clarity**.
The two most common representations are:

1. **Adjacency List**
2. **Adjacency Matrix**

This document compares these approaches in terms of **time complexity**, **space complexity**, and **practical use cases**.

---

## 1. Adjacency List

### Definition

An adjacency list represents a graph as an array (or list) of lists.
Each element corresponds to a vertex and contains a list of **neighboring vertices**.

**Example (Undirected Graph):**

```

Graph:
0 -- 1
\|    |
2 -- 3

Adjacency List:
0: 1, 2
1: 0, 3
2: 0, 3
3: 1, 2

```

### Properties

- **Space-efficient** for sparse graphs.
- Easy to traverse neighbors.

### Operations Complexity

| Operation               | Time Complexity |
|-------------------------|----------------|
| Check if edge (u,v) exists | O(degree(u))  |
| Add edge                | O(1)           |
| Remove edge             | O(degree(u))   |
| Iterate over neighbors  | O(degree(u))   |

> **Space Complexity:** O(V + E), where V = vertices, E = edges.

---

## 2. Adjacency Matrix

### Definition

An adjacency matrix is a **V x V matrix** where the entry `matrix[i][j]` indicates the presence of an edge from vertex `i` to `j`.

**Example (Undirected Graph):**

```

Graph:
0 -- 1
\|    |
2 -- 3

Adjacency Matrix:
0 1 2 3
0 \[ 0 1 1 0 ]
1 \[ 1 0 0 1 ]
2 \[ 1 0 0 1 ]
3 \[ 0 1 1 0 ]

```

### Properties

- Ideal for **dense graphs**.
- Constant-time edge look-up.

### Operations Complexity

| Operation               | Time Complexity |
|-------------------------|----------------|
| Check if edge (u,v) exists | O(1)        |
| Add edge                | O(1)           |
| Remove edge             | O(1)           |
| Iterate over neighbors  | O(V)           |

> **Space Complexity:** O(V²), regardless of the number of edges.

---

## 3. Comparison Table

| Feature                   | Adjacency List             | Adjacency Matrix          |
|---------------------------|---------------------------|--------------------------|
| Space Complexity          | O(V + E)                 | O(V²)                    |
| Edge Lookup               | O(degree(u))             | O(1)                     |
| Adding/Removing Edge      | O(1) / O(degree(u))      | O(1)                     |
| Traversing Neighbors      | O(degree(u))             | O(V)                     |
| Sparse Graphs             | ✅ Efficient              | ❌ Wasteful              |
| Dense Graphs              | ❌ Less efficient         | ✅ Efficient              |
| Memory Usage              | Low for sparse graphs    | High                     |

---

## 4. Practical Recommendations

- **Sparse Graphs:** Adjacency List
- **Dense Graphs:** Adjacency Matrix
- **Edge Queries:** Adjacency Matrix for O(1) lookups
- **Space Constraints:** Adjacency List

---

## 5. Variations & Extensions

1. **Weighted Graphs:**
   - List: store `(neighbor, weight)` pairs.
   - Matrix: store `weight` instead of 0/1; 0 or INF for no edge.

2. **Directed Graphs:** Both representations support direction. Only adjacency lists/matrix entries need to reflect the direction.

3. **Dynamic Graphs:** Adjacency list easier to expand dynamically; adjacency matrix resizing is expensive.

---

## 6. Interview Tips

- **Understand both representations** thoroughly.
- Practice **complexity comparisons** and **traversals**.
- **Edge-heavy vs vertex-heavy graphs**: discuss trade-offs.
- Be able to **convert between adjacency list and matrix**.
- Common interview problems: BFS, DFS, shortest path, cycle detection — implement using both representations.

---

## 7. Practice Problems

| Problem                                           | Source              |
|--------------------------------------------------|------------------|
| Graph Valid Tree                                  | LeetCode 261      |
| Number of Islands                                 | LeetCode 200      |
| Detect Cycle in a Graph                           | GFG               |
| Shortest Path in Unweighted Graph                 | GFG               |
| Graph Representation Conversion                   | Codeforces        |

---

## 8. Summary

- **Adjacency List:** Space-efficient, ideal for sparse graphs, O(degree) edge queries.
- **Adjacency Matrix:** Fast edge lookups, ideal for dense graphs, uses O(V²) space.
- **Choice depends on:** graph density, memory constraints, operation frequency.

---

**Visual Cheat Sheet:**

```

Sparse Graph -> Adjacency List ✅
Dense Graph  -> Adjacency Matrix ✅
Edge Lookup  -> Matrix O(1)
Neighbor Iterate -> List O(degree)

```

---

> By mastering these representations, you'll efficiently implement and analyze graph algorithms for **FAANG-level interviews**, coding contests, and real-world systems.

---

