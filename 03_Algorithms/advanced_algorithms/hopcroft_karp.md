# Hopcroft–Karp Algorithm — Maximum Bipartite Matching

## 1. Introduction

The **Hopcroft–Karp algorithm** is the most efficient algorithm for finding **maximum matching in bipartite graphs**.

It improves upon the simpler DFS-based augmenting path method by finding **many augmenting paths simultaneously**, dramatically reducing complexity.

---

## 2. Bipartite Graph Model

A bipartite graph is:

```
G = (U, V, E)
```

where

* `U` and `V` are disjoint partitions
* `E` contains edges connecting nodes from `U` to nodes in `V`

Matching constraints:

* each node has degree ≤ 1 in the matching

Our goal: maximum matching (largest set of non-conflicting pairings).

---

## 3. Key Idea

Unlike DFS-based matching, which finds one augmenting path at a time, Hopcroft–Karp finds **all shortest augmenting paths in one phase**.

This is achieved using a **layered graph** created by BFS.

Structure:

1. BFS → find levels and shortest augmenting paths
2. DFS → traverse only along valid layers to find paths
3. Repeat until no augmenting path exists

---

## 4. Layered Graph Example

ASCII diagram:

```
Unmatched nodes in U
    |
    v
 Level 0 ---- Level 1 ---- Level 2 ---- ... ---- Level k
 BFS ensures edges respect levels
```

Shortest augmenting paths are found first.
Since all are shortest, they are vertex-disjoint, allowing multiple matches per phase.

---

## 5. BFS Phase

Purpose:

* Build level graph
* Identify reachable unmatched vertices in V
* Mark distance to guide DFS

Pseudo-steps:

```
queue = empty
for u in U:
    if u is unmatched:
        dist[u] = 0
        enqueue(u)
    else:
        dist[u] = INF

dist[NIL] = INF

while queue not empty:
    u = dequeue()
    if dist[u] < dist[NIL]:
        for v in adj[u]:
            if dist[match[v]] == INF:
                dist[match[v]] = dist[u] + 1
                enqueue(match[v])
```

---

## 6. DFS Phase

Purpose:

* Explore augmenting paths respecting BFS levels
* Try to match vertex `u` in U

Pseudo-steps:

```
function dfs(u):
    if u != NIL:
        for each v in adj[u]:
            if dist[match[v]] == dist[u] + 1:
                if dfs(match[v]):
                    match[u] = v
                    match[v] = u
                    return true
        dist[u] = INF
        return false
    return true
```

---

## 7. Full Pseudocode

```
matching = 0
while BFS():
    for u in U:
        if u is unmatched:
            if DFS(u):
                matching++
return matching
```

---

## 8. Complexity Analysis

### Time Complexity

```
O(E * sqrt(V))
```

This is asymptotically optimal for bipartite matching.

### Space Complexity

```
O(V + E)
```

---

## 9. Why It Is Faster

The algorithm reduces the number of augmenting iterations:

* DFS method → O(V) augmenting paths possible
* Hopcroft–Karp → O(sqrt(V)) phases

Each phase handles many augmenting paths → faster in large sparse graphs.

---

## 10. Edge Cases

* Graph disconnected → handled naturally
* Multiple components → BFS explores all reachable unmatched nodes
* If no augmenting path exists, BFS fails early

---

## 11. Interview Tips

* Be ready to explain **augmenting paths** concept
* Emphasize the two-phase approach: BFS layering + DFS augmentation
* Use matching array representation
* Complexity explanation is a must
* Expect scenario-based modeling questions:

  * job assignment
  * pairing systems
  * maximum students seating
  * scheduling tasks

Common question:

> Why is it faster than simple DFS matching?

Answer:

> Because it finds many shortest augmenting paths at once, reducing the number of phases from O(V) to O(sqrt(V)).

---

## 12. Practice Problems

### LeetCode

* 886. Possible Bipartition (conceptually related)
* 1349. Maximum Students Taking Exam
* 1905. Count Sub Islands (not matching but requires bipartite thinking)

### Codeforces

* Round problems tagged: flow, matching
* Classics:

  * “Police Stations”
  * “Bipartite Matching” tasks

### GFG

* Maximum Bipartite Matching
* Hopcroft–Karp implementation tasks

---

## 13. Comparison Table

| Algorithm          | Complexity | Notes               |
| ------------------ | ---------- | ------------------- |
| Kuh’s DFS          | O(VE)      | Easy to code, slow  |
| Hopcroft–Karp      | O(E√V)     | Best performance    |
| Max-flow reduction | ~O(VE)     | Conceptually simple |

---

## 14. Summary

Hopcroft–Karp improves bipartite matching via:

* BFS → shortest layered graph
* DFS → augment respecting levels
* Combined phases → optimal performance

---
