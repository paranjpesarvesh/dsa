# **Bridges in a Graph (Cut Edges)**
---

## **1. Definition**

A **bridge** (or **cut edge**) in an undirected graph is an edge whose removal **increases the number of connected components**.

Meaning: removing that edge disconnects some part of the graph → it is a "critical connection".

---

## **2. Why Bridges Matter**

* Network design → identify weak links
* Communication systems → ensure redundancy
* Detect vulnerable roads/pipes/connections
* Foundation for:

  * Biconnected components
  * Bridge-tree construction
  * 2-edge-connected components

---

## **3. Key Idea (DFS + Discovery Time + Low Link Values)**

Use DFS and track:

* disc[u] = time of visiting u
* low[u] = earliest reachable ancestor from u using back-edges

An edge (u, v) is a **bridge** if:

low[v] > disc[u]

Meaning: v and its subtree cannot reach any ancestor of u → removing (u, v) isolates v-subtree.

---

## **4. ASCII Illustration**

Graph:

A — B — C
|
D — E

DFS tree (starting from A):

A
└── B
├── C
└── D
└── E

Bridges:

* (B, C)
* (D, E)

Removing these edges disconnects parts of the graph.

---

## **5. Step-by-Step Algorithm**

1. Initialize arrays: disc[], low[], visited[]
2. Run DFS from any unvisited node
3. For each neighbor v of u:

   * If v is unvisited:
     → DFS(v), update low[u]
     → Check condition for bridge
   * If visited and v ≠ parent[u]:
     → Update low[u] using disc[v]
4. Collect all edges where low[v] > disc[u]

---

## **6. Pseudocode (No Code Block)**

function dfs(u):
mark u visited
disc[u] = low[u] = timer++
for v in adj[u]:
if v not visited:
parent[v] = u
dfs(v)
low[u] = min(low[u], low[v])
if low[v] > disc[u]:
mark (u, v) as a bridge
else if v != parent[u]:
low[u] = min(low[u], disc[v])

---

## **7. Complexity**

| Measure | Value    |
| ------- | -------- |
| Time    | O(V + E) |
| Space   | O(V)     |

DFS is linear; low-link computation is constant per edge.

---

## **8. Edge Cases**

* Tree graph → every edge is a bridge
* Fully connected graph → no bridges
* Multiple connected components → run DFS from each
* Parallel edges → usually no bridges

---

## **9. Interview Tips**

FAANG often asks:

* Difference between **articulation points vs bridges**
* Why low[v] > disc[u]?
* Trace DFS with timestamps
* Implement Tarjan’s bridge-finding algorithm
* Often appears with:

  * critical connections
  * biconnected components
  * network reliability

Common pitfalls:

* Forgetting parent check
* Forgetting to run DFS for disconnected graphs
* Confusing discovery time with low value

---

## **10. Practice Problems**

**LeetCode:**

* 1192 — Critical Connections in a Network

**GFG:**

* Bridges in a Graph
* Tarjan’s Algorithm

**Codeforces:**

* 500A — New Year Transportation (graph basics)
* 732E — Sockets (bridge intuition in tree-like structures)

---
