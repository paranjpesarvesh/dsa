# **Prim’s Algorithm – Minimum Spanning Tree (MST)**

---

## **1. What Is Prim’s Algorithm?**

Prim’s algorithm builds an MST by **growing a tree** one edge at a time.

Start from any node → repeatedly add the **minimum weight edge** that connects a visited vertex to an unvisited one.

This is a **greedy, vertex-based MST algorithm**, ideal for **dense graphs**.

---

## **2. Intuition**

Prim behaves like **Dijkstra for MST**:

* Maintain a set of visited nodes
* Always choose the lightest edge leaving this set
* Add its endpoint
* Repeat until all nodes are included

---

## **3. Approaches**

### **A. Using Min-Heap (Optimized Prim)**

Best for adjacency list representation.

### **B. Using Adjacency Matrix**

Simpler but O(V²). Good when V is small or graph is dense.

---

## **4. Visual Example (ASCII)**

Graph:

A —3— B
|     /
1   4
| /
C —2— D

Prim starting at A:

Pick edges:

1. A–C (1)
2. C–D (2)
3. A–B (3)

Total MST weight = 6.

---

## **5. Min-Heap Based Prim – Step-by-Step**

1. Choose any start node (say 0)
2. Push (0, weight=0) into min-heap
3. While heap not empty:

   * Pop smallest weight edge to an unvisited node
   * Add node to MST
   * For all neighbors v of this node:

     * If v not visited → push (edgeWeight, v)
4. Continue until all nodes are visited

---

## **6. Pseudocode (No Code Block)**

Initialize key[] = INF
Initialize visited[] = false
key[start] = 0
minHeap.push( (0, start) )

while heap not empty:
(w, u) = pop heap
if visited[u]: continue
visited[u] = true

```
for each edge (u, v, wt):
    if not visited[v] and wt < key[v]:
        key[v] = wt
        minHeap.push( (key[v], v) )
```

MST weight = sum(key)

---

## **7. Time Complexity**

| Representation            | Complexity     |
| ------------------------- | -------------- |
| Adjacency List + Min-Heap | **O(E log V)** |
| Adjacency Matrix          | **O(V²)**      |

Space: O(V)

---

## **8. Prim vs Kruskal**

| Feature      | Prim                   | Kruskal         |
| ------------ | ---------------------- | --------------- |
| Based on     | Growing tree from root | Selecting edges |
| Best for     | Dense graphs           | Sparse graphs   |
| Needs DSU?   | No                     | Yes             |
| Typical impl | Min-heap               | Sort edges      |

---

## **9. Edge Cases**

* Graph must be connected → otherwise Prim gives an MST for the reachable component only
* Multiple edges with same weight → valid, MST need not be unique
* Negative edge weights → allowed (since MST ≠ shortest path)

---

## **10. Interview Tips**

You are often asked:

* Compare Prim & Kruskal
* Write heap-based Prim
* How to detect graph disconnected (key[] stays INF)?
* Convert adjacency matrix → adjacency list
* Why MST allows negative edges but Dijkstra doesn’t

FAANG sometimes disguises Prim inside:

* “Connect all points with minimum cost”
* “Network cabling”
* “City road planning”

---

## **11. Practice Problems**

**LeetCode:**

* 1584 — Min Cost to Connect All Points (Prim version works too)
* 1135 — Connecting Cities With Minimum Cost

**GFG:**

* Prim’s MST
* MST variants

**Codeforces:**

* 888E — MST-like optimization
* 1579F — graph expansion tasks

---
