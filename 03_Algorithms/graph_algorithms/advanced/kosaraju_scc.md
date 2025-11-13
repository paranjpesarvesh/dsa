# **Kosaraju’s Algorithm – Strongly Connected Components (SCCs)**
---

## **1. What Are Strongly Connected Components (SCCs)?**

In a **directed graph**, a **Strongly Connected Component (SCC)** is a maximal group of vertices such that:

* Every vertex is reachable from every other vertex inside the group.

Example:

A → B → C → A
This cycle is one SCC.

---

## **2. Why SCCs Matter**

* Deadlock detection
* Program analysis (control-flow graphs)
* Optimizing compilers
* Condensation graph (DAG of SCCs)
* Finding cycles and strongly connected substructures
* Used inside algorithms like 2-SAT

---

## **3. Kosaraju’s Algorithm – Core Idea**

Kosaraju’s algorithm uses **two DFS passes**:

### **Step 1: DFS on original graph**

* Perform DFS and push nodes into a stack by **finish time** (postorder).
* Nodes that finish later are processed earlier in Step 2.

### **Step 2: Reverse the graph**

Reverse all edges → build the **transpose graph**.

### **Step 3: DFS on reversed graph in stack order**

Each DFS gives exactly **one SCC**.

---

## **4. Intuition and Why It Works**

* Original DFS orders vertices by their "exit times".
* Reversing edges means if a component was reachable internally, DFS stays inside it.
* Once we process nodes in decreasing finish time, each DFS in the reversed graph **cannot escape** its SCC.

---

## **5. ASCII Diagram**

Original graph:

A → B → C
↑     ↓
F ← E ← D

SCCs:
(A, B, C)
(D, E)
(F)

Graph reversed:

A ← B ← C
↓     ↑
F → E → D

Order of finishing (example): F, A, B, C, D, E
Process reversed graph using this order → identify SCCs.

---

## **6. Pseudocode (No Code Block)**

function dfs1(u):
mark u visited
for v in adj[u]:
if not visited[v]:
dfs1(v)
push u on stack

function dfs2(u):
mark u visited
output u as part of current SCC
for v in rev_adj[u]:
if not visited[v]:
dfs2(v)

main:
run dfs1 on all unvisited nodes
reverse the graph
clear visited
while stack not empty:
u = pop from stack
if not visited[u]:
start new SCC
dfs2(u)

---

## **7. Complexity Analysis**

| Step          | Complexity   |
| ------------- | ------------ |
| DFS 1         | O(V + E)     |
| Reverse graph | O(V + E)     |
| DFS 2         | O(V + E)     |
| Total         | **O(V + E)** |

Space: O(V) for stack + visited + recursion.

---

## **8. Edge Cases**

* Completely disconnected graph → each node is its own SCC
* Single cycle → whole graph is one SCC
* Multiple edges or self-loops (self-loops count as SCCs of size 1)
* Large graphs require iterative DFS to avoid recursion limits

---

## **9. Interview Tips**

* Kosaraju vs Tarjan → both O(V+E), Tarjan is one-pass
* Be ready to explain:

  * Why finishing-time stack is needed
  * Why reversing edges helps
  * Why each DFS in Step 3 finds exactly one SCC
* Common mistake: forgetting to clear visited[] before second pass
* Frequently appears in:

  * Google, Meta, Amazon graph rounds
  * GATE theoretical questions on DFS and transpose graph

---

## **10. Practice Problems**

**LeetCode:**

* 1192 (related concepts)
* 2360 — Longest Cycle in a Graph (SCC idea helps)

**GFG:**

* Strongly Connected Components (Kosaraju's Algo)
* SCC and DAG condensation problems

**Codeforces:**

* 427C — Checkposts
* 1689C — Infected Tree (cycle intuition)

---
