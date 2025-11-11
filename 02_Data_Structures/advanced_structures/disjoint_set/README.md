# Disjoint Set (Union–Find Data Structure)

The **Disjoint Set Union (DSU)** or **Union–Find** is a powerful data structure used to efficiently manage a collection of **disjoint (non-overlapping) sets** and support:

1. **Find(x)** → Determine which set element `x` belongs to.
2. **Union(x, y)** → Merge the sets containing `x` and `y`.

It is widely used in:
- Graph algorithms
- Connectivity queries
- Minimum spanning tree (Kruskal's algorithm)
- Dynamic connectivity problems

---

#  Intuition

Imagine groups of students forming friend circles.
Initially, each student is alone:

```

1   2   3   4   5

```

After some unions:

```

1 - 3 - 5
2 - 4

```

Find operation tells which circle a student belongs to.
Union merges two circles.

---

#  Core Concepts

## 1. Parent Array

We maintain an array `parent[]`, where:
`parent[x] = p` means `p` is the representative (leader) of `x`.

Initially:

```

parent[i] = i

```

ASCII diagram:

```

1 -> 1
2 -> 2
3 -> 3
...

```

---

## 2. Find Operation

Goal: return leader/representative/root of a set.

### With Path Compression (optimized)

This flattens the tree to make future queries faster.

```

find(x):
if parent[x] != x:
parent[x] = find(parent[x])
return parent[x]

```

 After compression, tree height → O(1)

---

## 3. Union Operation

Union merges two sets by connecting roots.

### Union by Rank (or size)

Attach smaller tree under larger one.

```

union(x, y):
rx = find(x)
ry = find(y)

if rx == ry: return

if rank[rx] < rank[ry]:
    parent[rx] = ry
else if rank[ry] < rank[rx]:
    parent[ry] = rx
else:
    parent[ry] = rx
    rank[rx]++
```


This ensures no long chains are formed.

---

#  Complexity

| Operation          | Complexity |
|--------------------|------------|
| Union()            | α(n) ≈ O(1) |
| Find()             | α(n) ≈ O(1) |
| Initialization     | O(n)       |

> α(n) is the **inverse Ackermann function**, which grows EXTREMELY SLOWLY.
> For all practical input sizes: **DSU is almost constant time**.

---

#  Example Visualization

### Union(1,2)

```

1      2
↓      ↓
1      2

After union:
1 -> 1
2 -> 1

```

### Union(3,4)

```

3 -> 3
4 -> 4

After union:
4 -> 3

```

### Union(2,3)

```

1
|
2
|
3
|
4

```

Path compression flattens it:

```

1
|
2  3

4

```

---

#  Real-World Applications

### 1. Kruskal's Minimum Spanning Tree
Avoids cycles efficiently.

### 2. Connected Components in Graphs
Quickly answer: “Are nodes x and y connected?”

### 3. Cycle Detection
In an undirected graph, if Find(x) == Find(y), a cycle exists.

### 4. Image Processing
Labeling connected components.

### 5. Dynamic Connectivity Problems
Social networks
Friend circles
Network clusters
Percolation theory

---

#  Pseudocode Summary

```

parent[n], rank[n]

function init(n):
for i in 1..n:
parent[i] = i
rank[i] = 0

function find(x):
if parent[x] != x:
parent[x] = find(parent[x])
return parent[x]

function union(x, y):
rx = find(x)
ry = find(y)

if rx == ry: return

if rank[rx] < rank[ry]:
    parent[rx] = ry
else if rank[ry] < rank[rx]:
    parent[ry] = rx
else:
    parent[ry] = rx
    rank[rx]++

```

---

#  Variations

## 1. Union by Size
Use subtree size instead of rank.

## 2. Rollback DSU
Supports undo operations → used in offline queries.

## 3. DSU on Trees (a.k.a. Small-To-Large Merging)
Used for subtree queries on trees.

## 4. Persistent DSU
Used in versioned connectivity problems.

---

#  Edge Cases

- Union on already connected nodes → no change
- Self-union (x = y) → no effect
- Works only for sets, not general graphs or objects unless mapped to IDs

---

#  Interview Tips

### How DSU is tested

| Company | Pattern of questions |
|---------|------------------------|
| Google  | Graph connectivity, MST |
| Amazon  | Union-Find for dynamic merging |
| Meta    | Connected components, grouping |
| Microsoft | Cycle detection, clustering |

### Be prepared to write:
 Union-Find with path compression
 Union by rank/size
 Kruskal's algorithm using DSU
 Check if graph has a cycle
 Count number of components

 Bonus: interviewers love when you mention **α(n)** complexity.

---

# Practice Problems

### Easy
- LC 547 – Number of Provinces
- LC 990 – Satisfiability of Equality Equations
- GFG – Union-Find Introduction

### Medium
- LC 684 – Redundant Connection
- LC 1584 – Min Cost to Connect All Points
- LC 1631 – Path With Minimum Effort

### Hard
- LC 839 – Similar String Groups
- LC 765 – Couples Holding Hands
- Codeforces – DSU problems in Div2 C/D/E sets
- AtCoder DSU contests

---

# Summary Table

| Feature | Explanation |
|---------|-------------|
| Fast Find/Union | Almost O(1) |
| Path Compression | Flattens tree |
| Union by Rank | Balances trees |
| Wide Applications | Graphs, MST, clustering |
| Very Practical | Common in interviews |

---

# Final ASCII Flowchart

```

```
    +----------------+
    |   union(x,y)   |
    +----------------+
            |
      +-----------+
      | find(x)   |
      +-----------+
            |
      +-----------+
      | find(y)   |
      +-----------+
            |
 +------------------------+
 | same root? return      |
 +------------------------+
            |
  +--------------------+
  | union by rank/size |
  +--------------------+
```

---
