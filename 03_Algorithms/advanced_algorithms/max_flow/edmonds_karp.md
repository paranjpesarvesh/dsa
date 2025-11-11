# Edmonds–Karp Algorithm — Maximum Flow

## 1. Introduction

The **Edmonds–Karp algorithm** is an implementation of the **Ford–Fulkerson method** that uses **BFS** (Breadth-First Search) to always find the **shortest augmenting path** in terms of number of edges.

This guarantees a polynomial time complexity:

* O(V * E²)

It is simpler, easier to implement, and used in teaching/interviews to build intuition for max flow and residual graphs.

---

## 2. Key Ideas

### 2.1 Augmenting Path

A path from source `s` to sink `t` in the **residual graph** where all edges have **positive residual capacity**.

### 2.2 Residual Graph

Residual capacity:
`res(u, v) = cap(u, v) - flow(u, v)`

Reverse edges appear automatically:

* represent ability to undo flow

### 2.3 BFS for Shortest Path

Edmonds–Karp always chooses the path with the fewest edges.

This avoids worst-case exponential behavior of naive Ford–Fulkerson.

---

## 3. Algorithm Intuition

### Why BFS?

Because shortest augmenting paths reduce unnecessary rework and ensure that saturation levels progress efficiently.

### Why residual edges?

* If a bad choice was made (e.g., too much flow pushed), reverse edges let us fix it later.

---

## 4. Algorithm Steps

### Step 1: Initialize flow = 0

```
flow(u, v) = 0 for all edges
```

### Step 2: Build residual graph

Residual capacity = capacity - flow

### Step 3: BFS to find augmenting path

```
parent = array initialized to -1
parent[s] = s
queue = [s]

while queue not empty:
    u = queue.pop()
    for each v neighbor:
        if parent[v] == -1 and residual(u, v) > 0:
            parent[v] = u
            queue.push(v)
            if v == t: break
```

If BFS cannot reach t → maximum flow achieved.

### Step 4: Augment the path

* Find the minimum residual capacity along the path
* Push this amount of flow
* Update residual capacities and reverse edges

### Step 5: Repeat BFS until no augmenting path exists

---

## 5. Pseudocode

```
max_flow = 0

while BFS(s, t) finds path:
    path_flow = INF
    v = t
    while v != s:
        u = parent[v]
        path_flow = min(path_flow, residual(u, v))
        v = u

    v = t
    while v != s:
        u = parent[v]
        flow(u, v) += path_flow
        flow(v, u) -= path_flow
        update residuals
        v = u

    max_flow += path_flow

return max_flow
```

---

## 6. Complexity Analysis

### Time complexity

| Structure               | Complexity    |
| ----------------------- | ------------- |
| BFS per augmentation    | O(E)          |
| Number of augmentations | O(VE)         |
| **Total**               | **O(V * E²)** |

### Space complexity

* O(V + E)

---

## 7. Example Walkthrough

Graph:

```
     3         2
  s ----> a -----> t
   \       ^
    \      |
     2     3
      \    |
       ---> b --->
```

### Steps:

1. BFS finds shortest path:
   s → a → t

2. Path flow = min(3, 2) = 2

3. Update residuals

4. BFS finds next path:
   s → b → a → t

5. Path flow = min(2, 3, 1) = 1

6. No more augmenting path → max flow = 3

---

## 8. Variations and Improvements

1. **Dinic’s algorithm**
   Much faster, uses level graph + blocking flow.

2. **Scaling algorithms**
   Use capacities' bit-length to speed up.

3. **Push-relabel algorithm**
   The fastest in practice for large graphs.

---

## 9. Interview Tips

Important concepts to explain clearly:

* difference between Ford–Fulkerson and Edmonds–Karp
* what residual graphs represent
* role of reverse edges
* BFS vs DFS for augmenting path
* why Edmonds–Karp guarantees polynomial time
* max flow–min cut theorem

Common interview questions:

1. Explain why residual graph includes reverse edges
   → allows undoing flow

2. How to find the minimum cut after max flow?
   → BFS from source in final residual graph

3. How to handle multiple sources/sinks?
   → Add super-source / super-sink

---

## 10. Edge Cases

* No path exists: flow = 0
* Graph with cycles
* Graph with very large capacities
* Multiple parallel edges
* Directed vs undirected edges
  (undirected edges are modeled as two directed edges)

---

## 11. Practice Problems

### LeetCode

* 892. Maximum Flow Problems (conceptual)
* 1334. Find City with Smallest Neighbors (graph BFS)

### Codeforces

* Classic max flow templates appear frequently
* Matching and bipartite problems reduce to max flow

### GFG

* Max Flow (Edmonds–Karp implementation)
* Min Cut problems

---

## 12. Summary Table

| Concept         | Explanation                     |
| --------------- | ------------------------------- |
| Residual graph  | tracks possible additional flow |
| Reverse edges   | enable undoing flow             |
| BFS             | finds shortest augmenting path  |
| Augmenting path | path with remaining capacity    |
| Complexity      | O(V * E²)                       |

---
