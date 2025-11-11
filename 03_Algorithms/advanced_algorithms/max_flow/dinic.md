# Dinic’s Algorithm — Maximum Flow

## 1. Introduction

**Dinic’s Algorithm** (pronounced "DEE-nik") is a fast and widely used algorithm for computing **maximum flow** in a directed graph.
It improves upon the classical **Edmonds–Karp** algorithm by constructing a **level graph** and performing multiple blocking flow augmentations within a BFS layer structure.

Dinic’s algorithm is efficient and optimal for many competitive programming and interview settings.

---

## 2. Problem Definition

Given a directed graph **G(V, E)** with:

* source node `s`
* sink node `t`
* edge capacities `c(u, v) >= 0`

Find the **maximum possible flow** from `s` to `t` such that:

* flow respects capacity
* flow conservation holds at all nodes except s and t
* anti-symmetry property holds:
  `f(u, v) = -f(v, u)`

---

## 3. Core Concepts

### 3.1 Residual Graph

Represents how much more flow can be pushed.

Residual capacity:
`res(u, v) = cap(u, v) - flow(u, v)`

### 3.2 Level Graph

Constructed by BFS from source `s`.

* Each node is assigned a level = distance from source
* Only edges with positive residual capacity and level[v] = level[u] + 1 are kept

### 3.3 Blocking Flow

A flow that:

* saturates at least one edge on every s→t path in the level graph
* no more augmenting paths exist within current level graph

Dinic repeatedly computes blocking flow until no more augmenting path exists.

---

## 4. Algorithm Intuition

Dinic’s algorithm alternates between:

1. **Build level graph** using BFS.
2. **Send flows** (DFS) through only valid edges in this level graph.
3. When no more flow can be sent → rebuild level graph.

This reduces unnecessary exploration compared to Edmonds–Karp.

---

## 5. Algorithm Steps

### Step 1: BFS to build level graph

```
for all v: level[v] = -1
level[s] = 0
queue = [s]

while queue not empty:
    u = queue.pop()
    for each edge (u, v) with positive residual:
        if level[v] == -1:
            level[v] = level[u] + 1
            queue.push(v)
```

If `level[t] == -1`, no more flow possible.

---

### Step 2: DFS to find blocking flow

```
function send_flow(u, flow):
    if u == t:
        return flow
    for each next edge from u:
        v = edge.to
        if level[v] == level[u] + 1 and residual > 0:
            pushed = send_flow(v, min(flow, residual))
            if pushed > 0:
                update residuals
                return pushed
    return 0
```

---

### Step 3: Repeat until BFS fails

Pseudocode overview:

```
max_flow = 0
while BFS() builds valid level graph:
    while flow = send_flow(s, INF):
        max_flow += flow
return max_flow
```

---

## 6. Complexity Analysis

### Worst-case complexity

* O(E * V²) general graphs

### With unit capacities

* O(min(E^(1/2), V^(2/3)) * E)

### For bipartite graphs

* O(sqrt(V) * E)

Dinic is significantly faster than Edmonds–Karp in practice.

---

## 7. Variations and Optimizations

1. **Edge struct with reverse index**
   allows constant-time residual updates.

2. **Current edge pointer**
   avoid re-exploring edges during DFS.

3. **Scaling Dinic**
   for large capacities.

4. **Global relabel heuristic**
   improves performance on certain dense graphs.

---

## 8. Example Walkthrough

Consider this graph:

```
     10       10
  s ---> a --------> t
   \      ^      /
    \     |     /
     5    |    5
      \   |   /
       --> b -
```

Dinic steps:

1. BFS builds level graph: s(0), a(1), b(1), t(2)
2. DFS sends flows:

   * s → a → t (10)
   * s → b → t (5)
3. Final max flow = 15

---

## 9. Interview Notes

1. Dinic is popular because:

   * faster than Edmonds–Karp
   * clean implementation
   * fits competitive programming well

2. Make sure you understand:

   * residual graph concept
   * difference BFS (level graph) vs DFS (blocking flow)
   * why blocking flow speeds things up
   * how reverse edges work

3. Typical follow-up questions:

   * How to modify for multiple sources/sinks? → Add super-source/super-sink
   * How to detect min-cut after max-flow? → BFS residual graph from source
   * Difference between Dinic & Push-relabel?

---

## 10. Common Pitfalls

* forgetting reverse edges
* not resetting level graph correctly
* DFS not respecting level constraints
* integer overflow for INF
* inefficient adjacency representation

---

## 11. Practice Problems

### LeetCode

* 787. Cheapest Flights Within K Stops (flow-like DP)
* 329. Longest Increasing Path (graph DFS)
* Hard problems using max flow can appear unexpectedly

### Codeforces

* Classic max flow implementations
* Minimum vertex cover in bipartite graph via flow
* Edge-disjoint path problems

### GFG

* Max Flow (Dinic Implementation)
* Bipartite matching

---

## 12. Summary Table

| Concept        | Description                                    |
| -------------- | ---------------------------------------------- |
| Residual graph | tracks remaining capacity                      |
| Level graph    | BFS layers for speed                           |
| Blocking flow  | saturates all s→t paths in current level graph |
| DFS            | pushes flow                                    |
| BFS            | rebuilds levels                                |
| Complexity     | O(E * V²) worst-case                           |

---
