# 💧 Percolation Problem using Disjoint Set (Union-Find)

---

## 📌 Introduction

The **Percolation Problem** is a classic application of **Disjoint Set (Union-Find)** in **physics, computer science, and network connectivity**.

**Definition:**
Given an $N \times N$ grid, each site can be **open** or **blocked**. The system **percolates** if there is a path of open sites connecting the **top row** to the **bottom row**.

* This models **flow of liquid through porous material**, connectivity in networks, and clustering in graphs.
* Efficient implementation uses **DSU** to dynamically track connected components.

---

## 📌 Mathematical Intuition

1. **Represent each site as a node** in a graph.
2. **Connect open sites** with edges to their open neighbors (up, down, left, right).
3. **Introduce virtual top and bottom nodes**:

   * All top-row sites connect to virtual top node.
   * All bottom-row sites connect to virtual bottom node.
4. System **percolates** if virtual top and virtual bottom nodes are in the same connected component.

---

## 📌 Step-by-Step Approach

1. **Initialize DSU** with $N^2 + 2$ nodes (extra 2 for virtual top/bottom).
2. For each **open site (i,j)**:

   * Connect it to **open neighboring sites** using `union()`.
   * If in **top row**, union with virtual top node.
   * If in **bottom row**, union with virtual bottom node.
3. **Check percolation**: `find(virtual_top) == find(virtual_bottom)`.

---

## 📌 Pseudocode

```
function percolates(grid):
    N = size of grid
    DSU dsu(N*N + 2)
    virtual_top = N*N
    virtual_bottom = N*N + 1

    for i in 0..N-1:
        for j in 0..N-1:
            if grid[i][j] is open:
                node = i*N + j

                # Connect to open neighbors
                for (dx, dy) in [(0,1),(1,0),(0,-1),(-1,0)]:
                    ni, nj = i+dx, j+dy
                    if 0 <= ni < N and 0 <= nj < N and grid[ni][nj] is open:
                        neighbor = ni*N + nj
                        dsu.union(node, neighbor)

                # Connect top and bottom rows to virtual nodes
                if i == 0: dsu.union(node, virtual_top)
                if i == N-1: dsu.union(node, virtual_bottom)

    return dsu.find(virtual_top) == dsu.find(virtual_bottom)
```

---

## 📌 Complexity Analysis

| Operation          | Complexity               |
| ------------------ | ------------------------ |
| DSU initialization | O(N²)                    |
| Union operations   | O(N² α(N²)) ≈ O(N²)      |
| Total              | **O(N²)**                |
| Space              | **O(N²)** for DSU arrays |

> `α(N)` is the **inverse Ackermann function**, practically constant.

---

## 📌 ASCII Visualization

```
Grid: 4x4 (O=open, X=blocked)

O X O X
O O X X
X O O O
X X O O

Virtual top connects to first row open cells:
[TOP]--O--O
          |
          .
Virtual bottom connects to last row open cells:
              O--O--[BOTTOM]

Check if TOP and BOTTOM are connected via open path:
TOP → O → O → O → O → BOTTOM
```

---

## 📌 Variations & Edge Cases

* **Dynamic percolation**: open sites one by one and check connectivity.
* **Weighted percolation**: assign weights to sites for probabilistic models.
* **Non-square grids**: works for MxN grids.
* **Blocked system**: no path exists → percolates = false.

---

## 📌 Interview Tips

* Frequently asked in **network connectivity**, **simulations**, and **graph algorithms** problems.
* Remember **virtual nodes trick** for top and bottom row connectivity.
* DSU optimizations (path compression + union by rank) are essential for efficiency.

---

## 📌 Practice Problems

* [GFG – Percolation Problem](https://www.geeksforgeeks.org/percolation-problem/)
* [LeetCode 200 – Number of Islands](https://leetcode.com/problems/number-of-islands/) (similar concept)
* [Project Euler 186 – Connectedness Problem](https://projecteuler.net/problem=186)

---

✅ **Summary:**
Percolation problem demonstrates how **Disjoint Set** can efficiently solve **connectivity problems on a grid**, making it a **classic application** in both competitive programming and real-world simulations.

