# Graph Representations – Theory

Graphs are versatile structures used to represent relationships between entities. Choosing the **right representation** is crucial for efficient graph algorithms.

---

## 1. Definition Recap

A **graph** $G$ consists of:

* **Vertices (V)** – nodes
* **Edges (E)** – connections between vertices

Formally:

$$
G = (V, E)
$$

---

## 2. Why Graph Representation Matters

* Determines **time and space efficiency**
* Affects **algorithm choice**
* Impacts **edge and neighbor access operations**

---

## 3. Common Graph Representations

### 3.1 Adjacency Matrix

**Definition:**

A 2D $V \times V$ matrix where:

* `matrix[i][j] = 1` if there is an edge from vertex `i` to `j`
* For weighted graphs, `matrix[i][j] = weight`

**Example (Undirected Graph):**

```
Vertices: 0,1,2
Edges: 0-1, 1-2

Adjacency Matrix:
    0 1 2
0 [ 0 1 0 ]
1 [ 1 0 1 ]
2 [ 0 1 0 ]
```

**Pros:**

* Fast O(1) edge lookup
* Simple to implement

**Cons:**

* O(V^2) space → inefficient for sparse graphs
* Iterating neighbors takes O(V)

**Complexity Summary:**

| Operation            | Complexity |
| -------------------- | ---------- |
| Check edge existence | O(1)       |
| Add/Delete edge      | O(1)       |
| Iterate neighbors    | O(V)       |
| Space                | O(V^2)     |

---

### 3.2 Adjacency List

**Definition:**

An array or list of size `V`, where each index stores a list of neighbors.

**Example (Undirected Graph):**

```
Adjacency List:
0 -> 1
1 -> 0, 2
2 -> 1
```

**Pros:**

* Space efficient for sparse graphs (O(V + E))
* Iterating neighbors is fast (O(degree))

**Cons:**

* Checking edge existence can take O(degree)

**Complexity Summary:**

| Operation            | Complexity          |
| -------------------- | ------------------- |
| Check edge existence | O(degree of vertex) |
| Add edge             | O(1)                |
| Iterate neighbors    | O(degree)           |
| Space                | O(V + E)            |

---

### 3.3 Edge List

**Definition:**

A simple list of edges represented as `(u, v)` pairs (or `(u, v, w)` for weighted graphs).

**Example:**

```
Edge List:
(0,1)
(1,2)
```

**Pros:**

* Extremely simple
* Useful for algorithms that process edges sequentially (e.g., Kruskal's MST)

**Cons:**

* Slow neighbor lookup
* Slow edge existence check

**Complexity Summary:**

| Operation            | Complexity |
| -------------------- | ---------- |
| Check edge existence | O(E)       |
| Iterate neighbors    | O(E)       |
| Space                | O(E)       |

---

## 4. Comparison Table

| Feature                | Adjacency Matrix | Adjacency List | Edge List |
| ---------------------- | ---------------- | -------------- | --------- |
| Space                  | O(V^2)           | O(V + E)       | O(E)      |
| Edge lookup            | O(1)             | O(degree)      | O(E)      |
| Iterate neighbors      | O(V)             | O(degree)      | O(E)      |
| Good for dense graphs  |                 |               |          |
| Good for sparse graphs |                 |               |          |

---

## 5. Special Considerations

* **Directed vs Undirected:** Representation changes for direction
* **Weighted vs Unweighted:** Matrix or lists store weights
* **Sparse vs Dense:** Matrix for dense, list for sparse

---

## 6. Interview Tips

1. **Clarify the graph type** before implementing:

   * Directed or undirected
   * Weighted or unweighted
2. **Select representation** based on operations required:

   * Frequent edge checks → matrix
   * Traversals → adjacency list
   * Edge-centric algorithms (Kruskal) → edge list
3. **Edge Cases**:

   * Self-loops
   * Multiple edges (multi-graph)
   * Disconnected vertices

---

## 7. Practice Problems

| Platform   | Problem                                     |
| ---------- | ------------------------------------------- |
| LeetCode   | Number of Islands (Adjacency List/BFS)      |
| LeetCode   | Course Schedule (DAG, Topological Sort)     |
| GFG        | Kruskal's Minimum Spanning Tree (Edge List) |
| Codeforces | Graph Connectivity                          |

---

## 8. Visual Summary

```
Graph Representation:
  - Adjacency Matrix: Fast edge lookup, O(V^2) space
  - Adjacency List: Space efficient, O(V+E), fast neighbor iteration
  - Edge List: Simple, useful for edge-based algorithms
Choose based on:
  - Graph density
  - Frequent operations
  - Edge weights
```

---

This document serves as a **quick reference** for graph representations and helps make **implementation decisions** efficiently during interviews and competitive programming.

---
