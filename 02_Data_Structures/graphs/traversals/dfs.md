# Depth-First Search (DFS) – Graph Traversal

Depth-First Search (DFS) is a fundamental **graph traversal algorithm**. It explores a graph **deeply**, visiting vertices along a path before backtracking.

---

## 1. Definition

**DFS** is a graph traversal method that:

* Starts from a **source vertex**
* Explores as far as possible along **each branch**
* Uses a **stack** (explicit or via recursion) to manage backtracking

Formally:
Given a graph $G = (V, E)$, DFS visits every vertex reachable from a source vertex $s \in V$, traversing **deep into each branch before visiting siblings**.

---

## 2. DFS Intuition

* Think of DFS like **exploring a maze**:

  * Take a path until you hit a dead end
  * Backtrack to the last junction and try another path
* DFS is ideal for:

  * Detecting cycles
  * Topological sorting
  * Solving puzzles like **mazes** and **Sudoku**

---

## 3. DFS Algorithm – Step by Step

**Input:** Graph $G$ and source vertex $s$
**Output:** Order of traversal or discovery times

### Recursive DFS

1. Mark the current node as visited
2. Process the node (optional)
3. Recur for all **unvisited neighbors**
4. Backtrack automatically

**Pseudocode:**

```
DFS(Graph G, Vertex u, visited):
    mark u as visited
    process(u)          # optional

    for each neighbor v of u:
        if v not visited:
            DFS(G, v, visited)
```

### Iterative DFS (using stack)

1. Initialize a **stack** `S` and push source vertex
2. While `S` is not empty:

   * Pop vertex `u`
   * If `u` is not visited:

     * Mark as visited
     * Push all neighbors onto the stack

**Pseudocode:**

```
DFS_iterative(Graph G, Vertex s):
    create stack S
    visited = set()
    S.push(s)

    while S is not empty:
        u = S.pop()
        if u not in visited:
            process(u)
            visited.add(u)
            for neighbor v of u:
                S.push(v)
```

---

## 4. DFS Example

Graph:

```
   0
  / \
 1   2
 |   |
 3   4
```

**DFS starting from vertex 0 (recursive):**

1. Visit 0 → mark visited
2. Go to neighbor 1 → mark visited
3. Go to neighbor 3 → mark visited
4. Backtrack to 0 → go to neighbor 2 → mark visited
5. Go to neighbor 4 → mark visited

**Traversal order:** 0 → 1 → 3 → 2 → 4

---

## 5. DFS Implementation (Python)

```python
# Recursive DFS
def dfs_recursive(graph, node, visited=None):
    if visited is None:
        visited = set()

    visited.add(node)
    print(node, end=' ')  # process the node

    for neighbor in graph[node]:
        if neighbor not in visited:
            dfs_recursive(graph, neighbor, visited)

# Iterative DFS
def dfs_iterative(graph, start):
    visited = set()
    stack = [start]

    while stack:
```markdown
        node = stack.pop()
        if node not in visited:
            print(node, end=' ')  # process the node
            visited.add(node)
            # Push neighbors in reverse to mimic recursion order
            stack.extend(reversed(graph[node]))

# Example Graph
graph = {
    0: [1,2],
    1: [0,3],
    2: [0,4],
    3: [1],
    4: [2]
}

print("Recursive DFS:")
dfs_recursive(graph, 0)  # Output: 0 1 3 2 4

print("\nIterative DFS:")
dfs_iterative(graph, 0)  # Output: 0 1 3 2 4
```

---

## 6. Complexity Analysis

| Aspect | Complexity                                 |
| ------ | ------------------------------------------ |
| Time   | O(V + E) – visit each vertex and edge once |
| Space  | O(V) – for recursion stack or visited set  |

* `V` = number of vertices
* `E` = number of edges

**Notes:**

* Recursive DFS uses the **call stack** (may cause stack overflow in deep graphs)
* Iterative DFS avoids recursion but requires manual **stack management**

---

## 7. Variations & Edge Cases

* **Disconnected Graph:** Run DFS on each unvisited vertex
* **Directed Graph:** Works the same, but respects edge directions
* **Cycle Detection:** If DFS revisits a vertex in the current recursion path → cycle exists
* **Topological Sort:** DFS post-order traversal is used

---

## 8. DFS Applications

1. Topological sorting of DAGs
2. Cycle detection in graphs
3. Connected components in undirected graphs
4. Solving puzzles: mazes, sudoku, backtracking problems
5. Strongly Connected Components (Kosaraju’s Algorithm)

---

## 9. Interview Tips

* DFS is preferred when **deep traversal** is needed
* Watch for **stack overflow** in recursive implementations
* Use DFS for **backtracking problems**
* Understand the **difference with BFS**:

  * BFS → level-order, shortest path in unweighted graph
  * DFS → depth-first, backtracking, topological ordering

---

## 10. Practice Problems

| Platform   | Problem                   |
| ---------- | ------------------------- |
| LeetCode   | 200. Number of Islands    |
| LeetCode   | 130. Surrounded Regions   |
| GFG        | DFS of Graph              |
| Codeforces | DFS on grid/maze problems |

---

This markdown provides a **complete reference for DFS**, including **recursive & iterative implementations, complexity, applications, and interview tips**.

---
