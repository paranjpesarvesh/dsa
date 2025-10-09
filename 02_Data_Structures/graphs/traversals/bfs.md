# Breadth-First Search (BFS) – Graph Traversal

Breadth-First Search (BFS) is one of the fundamental **graph traversal algorithms**. It explores vertices **level by level**, making it ideal for shortest path calculations in **unweighted graphs**.

---

## 1. Definition

**BFS** is a graph traversal algorithm that:

* Starts from a **source vertex**
* Explores all **neighbors** before moving to the next level
* Uses a **queue** to track vertices to visit

Formally:
Given a graph $G = (V, E)$, BFS visits every vertex reachable from a source vertex $s \in V$ in increasing order of **distance from $s$**.

---

## 2. BFS Intuition

* Imagine a ripple in water: it spreads **level by level**.
* Vertices at distance 1 are visited before distance 2, and so on.
* This property makes BFS ideal for problems like:

  * Shortest path in unweighted graphs
  * Level-order traversal in trees
  * Connected component detection

---

## 3. BFS Algorithm – Step by Step

**Input:** Graph $G$ and source vertex $s$
**Output:** Order of traversal or distances from $s$

**Steps:**

1. Initialize a **queue** `Q`
2. Mark the source `s` as **visited** and enqueue it: `Q.push(s)`
3. While `Q` is not empty:

   * Dequeue vertex `u = Q.front()`
   * For each **neighbor** `v` of `u`:

     * If `v` is not visited:

       * Mark `v` as visited
       * Enqueue `v`
4. Continue until all reachable vertices are visited

**Pseudocode:**

```
BFS(Graph G, Vertex s):
    create a queue Q
    mark s as visited
    Q.enqueue(s)

    while Q is not empty:
        u = Q.dequeue()
        process(u)       # optional: print or store
        for each neighbor v of u:
            if v not visited:
                mark v as visited
                Q.enqueue(v)
```

---

## 4. BFS Example

Graph:

```
   0
  / \
 1   2
 |   |
 3   4
```

**BFS starting from vertex 0:**

1. Queue: \[0] → visit 0
2. Queue: \[1,2] → visit 1 → enqueue 3
3. Queue: \[2,3] → visit 2 → enqueue 4
4. Queue: \[3,4] → visit 3
5. Queue: \[4] → visit 4

**Traversal order:** 0 → 1 → 2 → 3 → 4

---

## 5. BFS Implementation (Python)

```python
from collections import deque

def bfs(graph, start):
    visited = set()
    queue = deque([start])
    visited.add(start)

    traversal_order = []

    while queue:
        node = queue.popleft()
        traversal_order.append(node)

        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

    return traversal_order

# Example usage
graph = {
    0: [1,2],
    1: [0,3],
    2: [0,4],
    3: [1],
    4: [2]
}

print(bfs(graph, 0))  # Output: [0, 1, 2, 3, 4]
```

---

## 6. Complexity Analysis

| Aspect | Complexity                                 |
| ------ | ------------------------------------------ |
| Time   | O(V + E) – visit each vertex and edge once |
| Space  | O(V) – for `visited` set + queue           |

* `V` = number of vertices
* `E` = number of edges

---

## 7. Variations & Edge Cases

* **Disconnected Graph:** Run BFS on each unvisited vertex
* **Weighted Graph:** BFS is only suitable for **unweighted** graphs; use Dijkstra for weighted graphs
* **Directed Graph:** BFS works on both directed and undirected graphs
* **Tree Traversal:** BFS in trees is called **level-order traversal**

---

## 8. BFS Applications

1. Shortest path in unweighted graphs
2. Detecting bipartite graphs
3. Network broadcast simulation
4. Finding connected components
5. Solving puzzles like **sliding tiles** or **word ladders**

---

## 9. Interview Tips

* Clarify **graph type**: directed, undirected, weighted
* BFS is ideal for **shortest distance problems** in unweighted graphs
* Understand **queue mechanics** vs DFS stack recursion
* Remember **visited set** to prevent cycles

---

## 10. Practice Problems

| Platform   | Problem                                |
| ---------- | -------------------------------------- |
| LeetCode   | 102. Binary Tree Level Order Traversal |
| LeetCode   | 127. Word Ladder                       |
| GFG        | Shortest Path in Unweighted Graph      |
| Codeforces | BFS on grid/maze problems              |

---

This markdown can serve as a **solid reference for BFS**, including **intuition, pseudocode, implementation, and real-world applications**.

---
