# **Tarjan’s Algorithm – Strongly Connected Components (SCCs)**
---

## **1. What Are SCCs?**

In a **directed graph**, a **Strongly Connected Component (SCC)** is a maximal set of nodes where:

* Every node is reachable from every other node.

Example:
A → B → C → A is one SCC.

---

## **2. Why Tarjan’s Algorithm?**

Tarjan’s Algorithm finds SCCs in **one DFS pass**, unlike Kosaraju which requires two passes + graph reversal.

Advantages:

* Faster in practice
* No transpose graph required
* Elegant stack-based mechanism
* Maintains ordering using timestamps

---

## **3. Core Intuition**

During DFS, each node gets:

* **disc[u]** → discovery time
* **low[u]** → lowest discovery time reachable from u (including cross/back-edges)

A node is the **head of an SCC** when:

low[u] == disc[u]

Meaning:
"No ancestor can be reached from u’s subtree → SCC boundary found."

At that moment, pop nodes from stack until u appears → that entire set is one SCC.

---

## **4. Visual Intuition (ASCII)**

Graph:

A → B → C
↑     ↓
F ← E ← D

DFS stack sequence:

Push A
Push B
Push C
Push D
Push E
(low values propagate back…)

When reaching E:
low[E] == disc[D] → SCC = {D, E}

Later: low[B] == disc[A] → SCC = {A, B, C}

Remaining node: F → SCC of size 1

---

## **5. Step-by-Step Algorithm**

1. Initialize:

   * disc[], low[], inStack[]
   * stack S
   * timer = 0

2. DFS(u):

   * Assign disc[u] = low[u] = timer++
   * Push u to stack; mark inStack[u] = true
   * For each v in adj[u]:

     * If v not visited → DFS(v), update low[u]
     * Else if v is inStack → update low[u] using disc[v]
   * If low[u] == disc[u]:

     * Pop nodes from stack until u
     * All popped nodes form one SCC

---

## **6. Pseudocode (No Code Block)**

function dfs(u):
disc[u] = low[u] = timer++
push u on stack
inStack[u] = true

```
for v in adj[u]:
    if disc[v] == -1:
        dfs(v)
        low[u] = min(low[u], low[v])
    else if inStack[v]:
        low[u] = min(low[u], disc[v])

if low[u] == disc[u]:
    start new SCC
    while true:
        x = pop stack
        inStack[x] = false
        add x to SCC
        if x == u: break
```

main:
initialize disc[] = -1
run dfs(u) for all unvisited u

---

## **7. Complexity**

| Measure | Value    |
| ------- | -------- |
| Time    | O(V + E) |
| Space   | O(V)     |

Single DFS makes Tarjan optimal.

---

## **8. Edge Cases**

* Self-loops → SCC of size 1
* Directed acyclic graph → every node is its own SCC
* Multiple edges → no effect
* Deep recursion → may need iterative DFS

---

## **9. Tarjan vs Kosaraju**

| Feature                   | Tarjan | Kosaraju |
| ------------------------- | ------ | -------- |
| DFS passes                | 1      | 2        |
| Reverse graph needed?     | No     | Yes      |
| Uses stack                | Yes    | Yes      |
| Implementation complexity | Medium | Easy     |

---

## **10. Interview Tips**

Common questions:

* Why check “low[u] == disc[u]”?
* How does stack ensure SCC correctness?
* Compare Tarjan and Kosaraju
* Identify SCCs in a hand-drawn graph
* Implement Tarjan in code

FAANG often mixes SCC questions with:

* 2-SAT
* Cycle detection
* Graph condensation

---

## **11. Practice Problems**

**LeetCode:**

* 2360 — Longest Cycle in a Graph
* 1192 — Critical Connections (conceptually similar)

**GFG:**

* Strongly Connected Components (Tarjan’s Algorithm)
* Count SCCs

**Codeforces:**

* 427C — Checkposts
* 1689C — Directed SCC based logic

---
