# **Articulation Points (Cut Vertices)**

---

## **1. Definition**

An **articulation point** (or **cut vertex**) in an undirected graph is a vertex whose removal **increases the number of connected components**.

Intuition:
If removing a node disconnects the graph, that node is critical for connectivity.

---

## **2. Why They Matter**

* Network reliability (finding weak routers)
* Social networks (influencers holding communities together)
* Bridges in communication systems
* Used inside biconnected component algorithms

---

## **3. Core Idea (DFS + Discovery Time + Low Link Values)**

We use a DFS tree and compute two arrays:

* `disc[u]` → time when `u` was discovered
* `low[u]` → earliest reachable discovery time from `u` via back-edges

A node `u` is an articulation point if:

### **Case 1: Root of DFS tree**

Root has **≥ 2 children** in DFS tree.

### **Case 2: Non-root node**

There exists a child `v` such that:

low[v] > disc[u]

Meaning: v or its subtree cannot reach an ancestor of u
→ removing u disconnects that subtree.

---

## **4. ASCII Illustration**

Consider:

A — B — C
|
D — E

DFS tree (starting at A):

A
└── B
├── C
└── D
└── E

Articulation points: **B** and **D**

---

## **5. Step-by-Step Algorithm**

1. Run DFS; maintain:

   * time counter
   * disc[]
   * low[]
   * parent[]
   * articulation[]

2. For each neighbor v of u:

   * If v is unvisited:
     → DFS(v), low[u] = min(low[u], low[v])
     → Check articulation conditions
   * If v ≠ parent[u]:
     → Update low[u] = min(low[u], disc[v]) (back-edge)

3. Mark articulation points.

---

## **6. Pseudocode (No Code Block)**

function dfs(u):
mark u visited
disc[u] = low[u] = timer++
childCount = 0

```
for v in adj[u]:
    if v not visited:
        parent[v] = u
        childCount += 1
        dfs(v)
        low[u] = min(low[u], low[v])

        if parent[u] == -1 and childCount >= 2:
            articulation[u] = true

        if parent[u] != -1 and low[v] > disc[u]:
            articulation[u] = true

    else if v != parent[u]:
        low[u] = min(low[u], disc[v])
```

---

## **7. Complexity**

| Measure | Value                               |
| ------- | ----------------------------------- |
| Time    | O(V + E)                            |
| Space   | O(V) (for arrays + recursion stack) |

---

## **8. Edge Cases**

* Completely disconnected graph → no articulation points inside components
* Fully connected graph → none
* A tree → every non-leaf node is an articulation point
* Chains / Lines → all interior nodes are articulation

---

## **9. Interview Tips**

* Very common in FAANG graph rounds
* Usually paired with **bridges**, **SCC**, or **biconnected components**
* Be ready to explain **low-link** intuition
* They often test:

  * Why low[v] > disc[u]?
  * Why root needs 2+ children?
  * Trace one DFS step-by-step

---

## **10. Practice Problems**

**LeetCode:**

* Critical Connections in a Network (#1192)
* Network Delay Time (related DFS intuition)

**GFG:**

* Articulation Points in a Graph
* Biconnected Components

**Codeforces:**

* 118E - Bertown roads
* 600E - Lomsat gelral (tree DFS intuition)

---
