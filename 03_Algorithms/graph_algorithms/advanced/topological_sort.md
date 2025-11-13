# **Topological Sort – Ordering of a Directed Acyclic Graph (DAG)**
---

## **1. What is Topological Sorting?**

A **topological sort** of a directed graph is a **linear ordering of vertices** such that:

For every directed edge u → v,
**u appears before v** in the ordering.

This is only possible for **DAGs (Directed Acyclic Graphs)**.

---

## **2. Real-World Examples**

* Task scheduling (task A must be finished before B)
* Build systems (compile dependencies)
* Course prerequisites
* Pipeline execution ordering

---

## **3. When Is Topological Sort Possible?**

A directed graph has a valid topological order **iff it has no cycles**.

Cycle example:

A → B → C → A
Topological sort is impossible.

---

## **4. Two Standard Approaches**

### **Approach 1: DFS-based (Postorder)**

Perform DFS → push nodes after exploring all children → reverse list.

### **Approach 2: Kahn’s Algorithm (BFS + In-degree)**

1. Compute in-degree of all vertices
2. Push all 0 in-degree nodes into queue
3. Repeatedly pop nodes and reduce in-degree of neighbors
4. If all nodes processed → valid; else → cycle exists

---

## **5. Visual Intuition (ASCII)**

Example DAG:

A → C
|     ↓
B → D → E

Topological sorts:
A B C D E
A C B D E
B A C D E
… (many valid orders)

---

## **6. DFS-Based Algorithm – Pseudocode**

dfs(u):
mark u visited
for v in adj[u]:
if not visited[v]:
dfs(v)
append u to order

main:
for each node u:
if not visited[u]:
dfs(u)
reverse(order)

---

## **7. Kahn’s Algorithm – Pseudocode**

compute indegree[]
queue = all nodes with indegree 0
while queue not empty:
u = pop queue
append u to order
for v in adj[u]:
indegree[v] -= 1
if indegree[v] == 0:
push v

If order contains all vertices → valid topological order
Else → graph contains a cycle.

---

## **8. Complexity**

| Method    | Time     | Space |
| --------- | -------- | ----- |
| DFS-based | O(V + E) | O(V)  |
| Kahn’s    | O(V + E) | O(V)  |

---

## **9. Edge Cases**

* Graph with multiple valid orders
* Disconnected graph → run DFS on all nodes
* Cycle present → no valid topo order
* Self-loop → invalid

---

## **10. Interview Tips**

* FAANG LOVES topological sort questions:

  * Task scheduling
  * Course prerequisites
  * Detecting cycles in directed graphs
* Explain difference between DFS-based and BFS(Kahn) approach
* Know how to detect cycle:

  * DFS: via recursion stack
  * Kahn: leftover nodes with nonzero in-degree
* Often used with DP on DAGs (longest path, shortest path)

---

## **11. Practice Problems**

**LeetCode:**

* 207 — Course Schedule
* 210 — Course Schedule II
* 1136 — Parallel Courses
* 269 — Alien Dictionary (hard!)

**GFG:**

* Topological Sort
* Detect Cycle in Directed Graph

**Codeforces:**

* 510C — Fox and Names
* 1490G — Old Floppy Drive (DAG logic)

---
