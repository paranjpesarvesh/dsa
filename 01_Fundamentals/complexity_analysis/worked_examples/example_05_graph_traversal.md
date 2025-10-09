# 🌉 Worked Example 05 – Graph Traversal (BFS & DFS)

In this worked example, we study the **time complexity analysis of graph traversal algorithms**:

* **Breadth-First Search (BFS)**
* **Depth-First Search (DFS)**

These are **fundamental building blocks** for solving graph-related problems such as shortest paths, connectivity, and cycle detection.

---

## 🔹 Problem Statement

Given a graph $G = (V, E)$, where $V$ is the set of vertices and $E$ is the set of edges, we want to **visit every vertex** that is reachable from a given starting vertex.

Two main traversal strategies:

1. **DFS (Depth-First Search)** → Explore deeply before backtracking.
2. **BFS (Breadth-First Search)** → Explore level by level.

---

## 🔹 Graph Representation

Graphs are commonly stored as:

1. **Adjacency Matrix**: $O(V^2)$ space.
2. **Adjacency List**: $O(V + E)$ space (preferred for sparse graphs).

Example Graph (Adjacency List):

```
0 → [1, 2]
1 → [0, 3, 4]
2 → [0, 5]
3 → [1]
4 → [1, 5]
5 → [2, 4]
```

ASCII Visualization:

```
     0
    / \
   1   2
  / \   \
 3   4 - 5
```

---

## 🔹 BFS – Pseudocode

```text
BFS(Graph, start):
    create a queue Q
    mark start as visited
    enqueue start

    while Q is not empty:
        vertex = dequeue Q
        for neighbor in Graph[vertex]:
            if neighbor not visited:
                mark neighbor visited
                enqueue neighbor
```

### Example Execution (Start = 0)

Order of visit: **0 → 1 → 2 → 3 → 4 → 5**

---

## 🔹 DFS – Pseudocode

**Recursive DFS:**

```text
DFS(vertex):
    mark vertex as visited
    for neighbor in Graph[vertex]:
        if neighbor not visited:
            DFS(neighbor)
```

**Iterative DFS (stack):**

```text
DFS(Graph, start):
    create stack S
    push start
    while S is not empty:
        vertex = pop S
        if vertex not visited:
            mark vertex visited
            push all unvisited neighbors of vertex
```

### Example Execution (Start = 0)

One possible order: **0 → 1 → 3 → 4 → 5 → 2**

---

## 🔹 Complexity Analysis

Let:

* $V = |vertices|$
* $E = |edges|$

| Algorithm | Time Complexity (Adj. List) | Time Complexity (Adj. Matrix) | Space Complexity                   |
| --------- | --------------------------- | ----------------------------- | ---------------------------------- |
| BFS       | $O(V + E)$                  | $O(V^2)$                      | $O(V)$ (queue + visited)           |
| DFS       | $O(V + E)$                  | $O(V^2)$                      | $O(V)$ (stack/recursion + visited) |

* **DFS recursion depth** can go up to $O(V)$.
* BFS uses a **queue** → good for shortest path in **unweighted graphs**.

---

## 🔹 Edge Cases

1. **Disconnected Graph**: Run BFS/DFS from all unvisited nodes to cover all components.
2. **Directed Graphs**: Traversal direction matters (follow edges only one way).
3. **Cyclic Graphs**: Always use a visited set to avoid infinite loops.
4. **Dense vs Sparse**: Matrix vs List representation affects efficiency.

---

## 🔹 C++ Implementation (BFS & DFS)

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    void bfs(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front(); q.pop();
            cout << node << " ";
            for (int nbr : adj[node]) {
                if (!visited[nbr]) {
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }

    void dfsUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        for (int nbr : adj[node]) {
            if (!visited[nbr]) {
                dfsUtil(nbr, visited);
            }
        }
    }

    void dfs(int start) {
        vector<bool> visited(V, false);
        dfsUtil(start, visited);
    }
};
```

---

## 🔹 Python Implementation (BFS & DFS)

```python
from collections import deque

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.adj = [[] for _ in range(vertices)]

    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)  # undirected

    def bfs(self, start):
        visited = [False] * self.V
        q = deque([start])
        visited[start] = True

        while q:
            node = q.popleft()
            print(node, end=" ")
            for nbr in self.adj[node]:
                if not visited[nbr]:
                    visited[nbr] = True
                    q.append(nbr)

    def dfs(self, start):
        visited = [False] * self.V
        self._dfs_util(start, visited)

    def _dfs_util(self, node, visited):
        visited[node] = True
        print(node, end=" ")
        for nbr in self.adj[node]:
            if not visited[nbr]:
                self._dfs_util(nbr, visited)
```

---

## 🔹 Interview Tips

* **FAANG**: BFS for shortest path, DFS for backtracking (mazes, word search).
* **GATE**: Focus on complexity proofs $O(V + E)$.
* **Common traps**:

  * Forgetting visited check → infinite loop.
  * Recursive DFS stack overflow on very deep graphs (convert to iterative).

---

## 🔹 Practice Problems

* [LeetCode 200 – Number of Islands (DFS/BFS)](https://leetcode.com/problems/number-of-islands/)
* [LeetCode 133 – Clone Graph](https://leetcode.com/problems/clone-graph/)
* [LeetCode 695 – Max Area of Island](https://leetcode.com/problems/max-area-of-island/)
* [GFG – BFS & DFS Traversal](https://www.geeksforgeeks.org/graph-and-its-representations/)

---

✅ This worked example shows how **BFS & DFS** work, why their complexity is $O(V + E)$, and how they are tested in **interviews & exams**.

---
