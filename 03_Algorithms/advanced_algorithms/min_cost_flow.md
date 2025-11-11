# Min-Cost Flow Algorithm — Complete Theory Guide

## 1. Introduction

The **Min-Cost Flow (MCF)** problem asks:

> What is the cheapest way to send `K` units of flow from source `s` to sink `t`
> given capacities and edge costs?

This generalizes:

* maximum flow
* shortest paths
* assignment problems
* transportation problems

---

## 2. Problem Definition

Given:

* Directed graph `G(V, E)`
* Each edge `e` has:

  * capacity `cap[e]`
  * cost `cost[e]` per unit flow

Goal:

Send **exactly K units of flow** from `s` to `t`
such that **total cost** is minimized.

---

## 3. Flow Representation

Total cost:

```
sum(flow[e] * cost[e] for all edges e)
```

Subject to:

1. Capacity constraints

   ```
   0 ≤ flow[e] ≤ cap[e]
   ```

2. Flow conservation for all nodes except s, t

   ```
   inflow(v) = outflow(v)
   ```

---

## 4. Core Algorithmic Idea

Min-Cost Flow uses the concept of **augmenting paths**, but instead of shortest-length paths (like BFS), it finds **shortest-cost paths**.

Strategy:

1. Construct a residual graph
2. Use **shortest path algorithm** (Bellman–Ford or Dijkstra with potentials)
   to find a path from `s → t`
3. Augment flow along that path
4. Update residual graph
5. Repeat until K units of flow are sent

---

## 5. Residual Graph Structure

Residual graph stores:

* forward edges with remaining capacity
* backward edges with negative cost

Example:

```
u ----(cap=3, cost=5)----> v

Residual edges:
u → v (remaining cap)
v → u (rev edge, negative cost)
```

Backward edge allows reducing flow for optimization.

---

## 6. Mathematical Insight — Potentials

Negative edges break Dijkstra.

Solution: assign node potentials `pi[v]`.

Reduced cost:

```
cost'[u][v] = cost[u][v] + pi[u] - pi[v]
```

Reduced cost edges remain **non-negative** → enabling Dijkstra.

After each augmentation:

```
pi[v] += dist[v]
```

This stabilizes reduced edge weights.

---

## 7. Pseudocode (Successive Shortest Path Algorithm)

```
Initialize flow = 0
Initialize potential pi[v] = 0 for all nodes

while flow < K:
    Run Dijkstra with reduced costs to find min-cost path s→t
    if no path exists: break

    Compute max augmentation along path
    Add flow and update residual edges

    Update potentials:
        pi[v] += distance[v]

return total_cost
```

---

## 8. Complexity Analysis

Let:

* V = number of nodes
* E = number of edges
* K = required flow

### Time Complexity

Using Dijkstra with potentials:

```
O(K * E * log V)
```

If Bellman–Ford is used:

```
O(K * V * E)
```

### Space Complexity

```
O(V + E)
```

---

## 9. Min-Cost Max-Flow vs Min-Cost K-Flow

Two variants:

| Variant           | Description                                               |
| ----------------- | --------------------------------------------------------- |
| Min-Cost Max-Flow | find flow with **minimum cost for maximum possible flow** |
| Min-Cost K-Flow   | find minimum cost for **exactly** K units                 |

This document covers **K-flow**, a more general formulation.

---

## 10. Common Enhancements

### 1. Capacity scaling

Speeds up augmentation for high-capacity edges.

### 2. Cost scaling

Focuses on improving cost gradients.

### 3. Cycle canceling (rare)

Detect negative cycles and remove them.

---

## 11. Visual Explanation

### Example Layering

```
Source ---> A ---> B ---> Sink
   \                  /
     ------> C ------
```

Costs guide shortest path selection.

Residual adjustments create new options.

---

## 12. Edge Cases

1. Graph has no path from s to t
   → zero flow or partial flow
2. Negative-cost cycles
   → handled by potentials or Bellman–Ford
3. Large K but small paths
   → augment full remaining capacity at once

---

## 13. Interview Tips

* Explain **reduced cost** and its role in enabling Dijkstra.
* Mention residual graph with negative edges.
* Demonstrate knowledge of Bellman–Ford vs Dijkstra approach.
* Stress complexity improvement.
* Common interview modeling examples:

  * airline scheduling
  * supply chain optimization
  * assignment/transportation problems
* Be ready to derive total cost formula.

Typical interview question:

> Why do we need potentials in Min-Cost Flow?

Expected answer:

> Potentials ensure all reduced edge costs are non-negative so Dijkstra can be used efficiently.

---

## 14. Practice Problems

### LeetCode

* 1168. Optimize Water Distribution
* 2050. Parallel Courses III (flow-inspired)
* 2392. Build Matrix With Conditions

### Codeforces

* Problems tagged `flows`, `1705G`, `1494E`
* Matching & assignment tasks

### GFG

* Min cost max flow in directed graph
* Shortest augmenting path problems

---

## 15. Summary

Min-Cost Flow combines:

* residual graphs
* shortest path algorithms
* cost potentials

to efficiently compute cheapest possible flow from s to t.

Provides a powerful abstraction for many optimization problems.

---
