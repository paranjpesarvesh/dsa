/*
===============================================================================
📌 Problem Statement:
Implement the Disjoint Set Union (DSU) / Union-Find data structure.

The DSU should efficiently support:
1. FIND(x): Find the representative (root) of the set containing x.
2. UNION(x, y): Merge the sets containing x and y.

Optimizations required:
- Path Compression in FIND.
- Union by Rank/Size in UNION.

===============================================================================
🔹 Explanation of Algorithm Choice:
We represent disjoint sets as a forest of trees:
- Each node has a parent pointer.
- FIND compresses paths to reduce tree height.
- UNION attaches smaller rank/size tree under larger one to keep balance.

Amortized Time Complexity:
- FIND: O(α(n))  [Inverse Ackermann Function ≈ constant in practice].
- UNION: O(α(n)).
- Essentially near O(1) for practical purposes.

Space Complexity:
- O(n) for parent and rank/size arrays.

===============================================================================
*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;  // parent[i] -> representative of set, rank[i] -> depth heuristic

public:
    // Constructor: initializes n elements, each in its own set
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i; // each node is its own parent initially
        }
    }

    // FIND with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    // UNION by rank
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;  // already in the same set

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;  // increase rank if same
        }
    }

    // Utility: check if two elements are in the same set
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

// ============================================================================
// Example Usage
// ============================================================================
int main() {
    int n = 7;
    DisjointSet dsu(n);

    // Initial unions
    dsu.unite(1, 2);
    dsu.unite(2, 3);
    dsu.unite(4, 5);
    dsu.unite(6, 7);

    cout << "Are 1 and 3 connected? " << (dsu.connected(1, 3) ? "Yes" : "No") << endl;
    cout << "Are 4 and 6 connected? " << (dsu.connected(4, 6) ? "Yes" : "No") << endl;

    // Connecting components
    dsu.unite(5, 6);
    cout << "After union(5,6), are 4 and 7 connected? "
         << (dsu.connected(4, 7) ? "Yes" : "No") << endl;

    return 0;
}

/*
===============================================================================
🔹 Variations & Notes:
- Union by Size: Instead of rank, track the size of each set and attach smaller
  to larger. Often more intuitive.
- Rollback DSU: Supports undo operations (used in offline dynamic connectivity).
- DSU on Trees / DSU with extra metadata: Extend to store additional info (e.g.,
  size of connected component, min/max, etc.).

===============================================================================
🔹 Interview Tips:
- Be able to write DSU quickly (~5 min) with both optimizations.
- Commonly used in Kruskal’s MST, cycle detection, connected components.
- Know complexity proof for path compression + rank → O(α(n)).
===============================================================================
*/

