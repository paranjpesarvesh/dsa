# Ford–Fulkerson Algorithm — Maximum Flow

## 1. Introduction

The **Ford–Fulkerson method** is a foundational algorithm for computing **maximum flow** in a flow network. It works by repeatedly finding **augmenting paths** from source `s` to sink `t` and pushing flow until no more positive-capacity paths exist.

Ford–Fulkerson is a *method*, not a specific algorithm. Its behavior depends on **how augmenting paths are chosen**.

---

## 2. Core Concepts

### 2.1 Flow Network

A directed graph with:

* **capacities** `cap(u, v)`
* **flow values** `flow(u, v)`
* **source node** `s`
* **sink node** `t`

### 2.2 Residual Graph

Residual capacity:

```
res(u, v) = cap(u, v) - flow(u, v)
```

Reverse edges exist automatically:

```
res(v, u) = flow(u, v)
```

The residual graph allows increasing or undoing flow.

### 2.3 Augmenting Path

A valid path `s → t` in the residual graph where **all residual edges > 0**.

Flow can be increased by:

```
delta = minimum residual capacity along the path
```

---

## 3. Intuition Behind the Method

1. Start with flow = 0 everywhere
2. Find any augmenting path from s to t
3. Push as much flow as possible along that path
4. Update residual graph
5. Repeat until no augmenting path exists

The max-flow min-cut theorem guarantees correctness.

---

## 4. Algorithm Steps

### Step 1: Initialize flow = 0

```
for each edge (u, v):
    flow(u, v) = 0
```

### Step 2: While augmenting paths exist

Use DFS or BFS to find a path:

```
path = find_path(s, t)
if no path:
    break
```

### Step 3: Compute bottleneck capacity

```
delta = min(res(u, v) along path)
```

### Step 4: Augment flow

For each edge (u → v) in path:

```
flow(u, v) += delta
flow(v, u) -= delta
```

### Step 5: Return sum of flows leaving source

---

## 5. Pseudocode

```
max_flow = 0

while augmenting path exists:
    delta = bottleneck(path)
    for edge (u, v) in path:
        flow(u, v) += delta
        flow(v, u) -= delta
    max_flow += delta

return max_flow
```

---

## 6. Path-finding Method Variants

Ford–Fulkerson does **not** specify how to find paths. Choice affects performance:

### DFS version

* Simple to implement
* Worst-case **exponential**

### BFS version (Edmonds–Karp)

* Guarantees polynomial bound
* Complexity: O(V * E²)

---

## 7. Complexity Analysis

### Time Complexity

General Ford–Fulkerson:

```
O(max_flow * E)
```

Worst-case exponential if capacities are irrational or chosen poorly.

But if all capacities are integers:

* Flow increases by ≥ 1 each augmentation
* At most `max_flow` augmentations
* Total complexity: O(max_flow * E)

### Space Complexity

```
O(V + E)
```

---

## 8. Example Walkthrough

Consider:

```
   10      5
s ----> a ----> t
 \        ^
  \       |
   10     15
    \     |
     ----> b ---->
```

### Iteration 1

* Path: `s → a → t`
* Bottleneck: min(10, 5) = 5
* Push 5 flow

### Iteration 2

* Path: `s → b → a → t`
* Bottleneck: min(10, 15, 0) = 0 → no valid path

### Iteration 3

Try other paths as residual graph updates.

---

## 9. Variations and Extensions

1. **Edmonds–Karp**
   Uses BFS → guarantees polynomial time

2. **Dinic’s algorithm**
   Faster, with blocking flow and level graph

3. **Capacity scaling technique**
   Improves complexity by focusing on large-capacity paths first

---

## 10. Pitfalls and Interview Notes

### Common Questions

1. Why does Ford–Fulkerson fail to terminate sometimes?
   → If path selection oscillates due to **irrational capacities**

2. Why do we need reverse edges?
   → To undo earlier flow if needed

3. How to extract the minimum cut?
   → After final BFS, nodes reachable from `s` form the S side

### Practical Issues

* DFS often leads to deep recursion
* Graph representation matters (adjacency list preferred)
* Tracking residuals carefully is essential

---

## 11. Visual Diagram

```
Residual Graph Example

       3
   u ------> v
    <------
       2

Forward residual: 3
Reverse residual: 2
```

---

## 12. Practice Problems

### LeetCode

* 1334. Find City With Smallest Neighbors (flow concepts)
* 2076. Process Restricted Friend Requests (flow reduction)

### Codeforces

* Many bipartite matching problems reduce to flow

### GFG

* Ford–Fulkerson Algorithm
* Construct Minimum Cut

---

## 13. Summary Table

| Concept            | Explanation                        |
| ------------------ | ---------------------------------- |
| Augmenting path    | usable flow path in residual graph |
| Bottleneck         | minimum residual edge on path      |
| Reverse edges      | allow undoing flow                 |
| DFS path choice    | possibly exponential time          |
| Integer capacities | guarantee termination              |
| Min-cut relation   | final reachable set after flow     |

---
