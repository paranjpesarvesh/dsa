# Bipartite Matching — Theory and Algorithms

## 1. Introduction

A **bipartite graph** is a graph whose vertices can be divided into two disjoint sets `U` and `V`, such that **every edge connects one vertex from U to one from V**.

**Bipartite Matching** aims to find the **maximum number of pairings (edges)** such that:

* each vertex participates in at most one match
* edges connect vertices only across the partitions

---

## 2. Definitions

### Bipartite Graph

```
G = (U, V, E)
```

* U = left partition
* V = right partition
* E = edges connecting U to V

### Matching

A set of edges such that **no two share a vertex**.

### Maximum Matching

The largest matching possible.

### Perfect Matching

Every vertex of both sides is matched.

---

## 3. Why It Works: Mathematical Intuition

Matching problems reduce to flow problems by:

* creating a **source** connected to all nodes in U
* creating a **sink** connected to all nodes in V
* giving all edges capacity 1

Then the maximum flow corresponds to the maximum matching.

---

## 4. Standard Algorithms

### 4.1 DFS-based Kuh’s Algorithm (Hungarian DFS Method)

This method is used when:

* graph is static
* edges are unweighted
* you just need maximum matching

Idea:

* For each unmatched node in U:

  * run DFS to find an **augmenting path**
  * if found, flip edges along the path

Augmenting path alternates between non-matching and matching edges.

---

### 4.2 Hopcroft–Karp Algorithm (Efficient)

The fastest algorithm for maximum bipartite matching.

Key idea:

* Build layers using BFS (like level graph)
* Use DFS to find **multiple augmenting paths in one phase**

Time complexity:

```
O(E * sqrt(V))
```

This is extremely efficient for competitive programming.

---

### 4.3 Max-flow reduction

Build a flow network:

```
source -> U nodes -> V nodes -> sink
```

All capacities = 1.

Run max-flow (Dinic/Edmonds–Karp).

This is simpler to understand but slower:

```
O(V * E)
```

---

## 5. Augmenting Path Idea

ASCII diagram:

```
u1 -- v2
|      |
v1 -- u2
```

Current matching = {(u1,v2)}

Possible augmenting path:

```
u2 -> v1 -> u1 -> v2
```

Flip matched/unmatched edges → increase matching.

---

## 6. Pseudocode for Kuh’s Algorithm

```
matchR = array of size |V| initialized to -1

function bpm(u):
    for each v in adj[u]:
        if not seen[v]:
            seen[v] = true
            if matchR[v] == -1 or bpm(matchR[v]):
                matchR[v] = u
                return true
    return false

max_matching = 0
for each u in U:
    reset seen[]
    if bpm(u):
        max_matching++
```

---

## 7. Complexity Analysis

### Kuh’s Algorithm:

```
Worst-case time: O(V * E)
Space: O(V)
```

### Hopcroft–Karp:

```
Time: O(E * sqrt(V))
Space: O(V + E)
```

### Max-flow:

```
Depends on flow algorithm, usually slower
```

---

## 8. Variations

1. **Weighted Bipartite Matching**

   * Use **Hungarian Algorithm**
   * Time complexity: O(n³)

2. **Maximum Independent Set in Bipartite Graph**

   * Connected to König's theorem

3. **Minimum Vertex Cover**

   * Size equals maximum matching size (for bipartite graphs)

---

## 9. Interview Tips

* Know reduction to max-flow
* Understand augmenting paths
* Be clear: bipartite graph ≠ general graph
* Expect questions converting real-world problems to bipartite matching
* Practice DFS matching implementation

Typical interview question:

> Given workers and jobs, each worker can work on certain jobs. Assign maximum workers to jobs.

Follow-up:

> Can you modify it to assign minimum cost?
> → Yes: Hungarian algorithm.

---

## 10. Practice Problems

### LeetCode

* 1349. Maximum Students Taking Exam
* 2125. Number of Laser Beams
* 886. Possible Bipartition (bipartite check)

### Codeforces

* 100 Problem-set: Many matching-based problems
* Classic "Project selection" tasks

### GFG

* Maximum Bipartite Matching
* Find Minimum Vertex Cover

---

## 11. Summary Table

| Algorithm     | Use Case               | Time    |
| ------------- | ---------------------- | ------- |
| Kuh’s (DFS)   | Simple matching        | O(V*E)  |
| Hopcroft–Karp | Efficient max matching | O(E√V)  |
| Max-flow      | Conceptual clarity     | Depends |

---
