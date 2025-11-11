# Pattern 16: Topological Sort

Topological Sorting is a fundamental graph algorithm used to order nodes in a **Directed Acyclic Graph (DAG)** so that every directed edge `u → v` places `u` before `v` in the ordering.

This pattern is especially useful for problems involving:

* prerequisites
* dependency resolution
* ordering tasks
* course scheduling
* build systems
* scheduling pipelines

---

# 1. Definition

A **topological ordering** of a directed graph is a linear ordering of its vertices such that:

```
For every directed edge u → v, u appears before v.
```

Only valid for **DAGs** (Directed Acyclic Graphs).
If a cycle exists, topological sorting is impossible.

---

# 2. Why It Works (Intuition)

If there are no cycles:

* Some node in the graph has **no incoming edges** (in-degree = 0)
* That node can safely appear first (nothing depends on it)
* Remove it, and repeat the process until all nodes are processed

This forms the basis of **Kahn’s Algorithm**.

Alternatively, through **DFS**, each node finishes processing after all its children; a reverse postorder gives a valid topological order.

---

# 3. ASCII Diagram (Example DAG)

```
   A → C → D
    \       \
     → B ----→ E
```

Possible topological orderings:

```
A, B, C, D, E
A, C, B, D, E
...
```

---

# 4. Approaches

## Approach 1: Kahn's Algorithm (BFS using in-degree)

Steps:

1. Compute in-degree for all nodes
2. Push all nodes with in-degree 0 into a queue
3. Pop from queue, append to output
4. Reduce in-degree of neighbors
5. If neighbor’s in-degree becomes 0, push it
6. Continue until queue is empty

If not all nodes are processed → cycle exists.

### Pseudocode

```
topo_order = []
compute in_degree[v] for all v

queue = all v where in_degree[v] == 0

while queue not empty:
    node = queue.pop()
    topo_order.append(node)

    for nei in adjacency_list[node]:
        in_degree[nei] -= 1
        if in_degree[nei] == 0:
            queue.push(nei)

if len(topo_order) != n:
    return "Graph has a cycle"

return topo_order
```

---

## Approach 2: DFS-based topological sort

Steps:

1. Visit unvisited node
2. Recursively visit neighbors
3. After exploring neighbors, push node onto stack
4. Reverse stack to get ordering

This is reverse postorder of DFS.

---

# 5. Complexity Analysis

Let:

* `n` = number of nodes
* `m` = number of edges

Time:

```
O(n + m)
```

Space:

```
O(n + m) for adjacency list
O(n) for in-degree or recursion stack
```

---

# 6. Variations and Extensions

1. **Detect Cycle in Directed Graph**

   * If topological sort is impossible, cycle exists
   * Kahn’s algorithm detects this automatically
   * DFS detects via back edges

2. **Lexicographically Smallest Topological Order**

   * Use a **min-heap** instead of queue

3. **Counting number of valid topological orders**

   * Hard (NP-complete)

4. **Topological Sorting with Constraints**

   * Weighted edges
   * Partial ordering

---

# 7. Edge Cases

* Graph has no edges
* Multiple valid orderings exist
* Graph contains cycle → no ordering
* Disconnected components → handle all nodes

---

# 8. Interview Tips

* Always mention graph must be a **DAG**
* Show in-degree array and queue logic
* Explain cycle detection
* For DFS, emphasize reverse-postorder
* Draw small graph and demonstrate
* Companies love:

  * Course schedule
  * Task dependencies
  * Build ordering
* Never forget complexity O(n + m)
* Be ready to explain multiple valid solutions

---

# 9. Practice Problems

### LeetCode

* 207 Course Schedule
* 210 Course Schedule II
* 802 Find Eventual Safe States
* 1203 Sort Items by Groups

### GFG

* Topological Sort
* Detect Cycle in Directed Graph

### Codeforces

* Scheduling tasks
* DAG DP problems (longest path in DAG)

---

# Summary

Topological sorting provides a systematic way to order tasks with dependencies, foundational for many graph-based interview problems. Both BFS-based Kahn’s Algorithm and DFS-based reverse postorder are essential techniques every interview candidate should master.

