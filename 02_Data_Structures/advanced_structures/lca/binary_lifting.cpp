// /02_Data_Structures/advanced_structures/lca/binary_lifting.cpp
// --------------------------------------------------------------------------------------
// Lowest Common Ancestor (LCA) using Binary Lifting
//
// Problem Description:
//   Given a rooted tree (often 1-indexed) with N nodes,
//   we want to answer queries of the form:
//       LCA(u, v) = lowest (deepest) node that is ancestor of both u and v.
//
// Why Binary Lifting?
//   - Preprocessing: O(N log N)
//   - Each query: O(log N)
//   - Space: O(N log N)
//   - Very fast in practice, simple to implement
//
// Approach Summary:
//   1) Precompute parent[k][v] = 2^k-th ancestor of vertex v.
//   2) Store depth[v] for each node.
//   3) For LCA(u, v):
//        - Lift the deeper node up until both are at the same depth.
//        - Lift both nodes up together from highest possible jump downward.
//        - The parent of either at the point where they differ is the LCA.
//
// Assumptions:
//   - Tree vertices numbered 1..N
//   - Root is 1 (can be modified)
//   - Tree stored as adjacency list
//
// --------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 200000;      // adjust based on constraints
static const int LOG = 20;           // enough for n up to 2^20 = approx 1e6

vector<int> adj[MAXN + 1];
int parent[LOG][MAXN + 1];
int depth[MAXN + 1];
int n;                               // number of nodes

// --------------------------------------------------------------------------------------
// Depth-first search to compute depth and immediate parent (parent[0][v])
// --------------------------------------------------------------------------------------
void dfs(int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;

    for (int nxt : adj[v]) {
        if (nxt == p) continue;
        dfs(nxt, v, d + 1);
    }
}

// --------------------------------------------------------------------------------------
// Precompute parent[k][v] for all k
// parent[k][v] = 2^k-th ancestor of v
// --------------------------------------------------------------------------------------
void preprocess() {
    for (int k = 1; k < LOG; k++) {
        for (int v = 1; v <= n; v++) {
            int mid = parent[k - 1][v];
            parent[k][v] = (mid == -1 ? -1 : parent[k - 1][mid]);
        }
    }
}

// --------------------------------------------------------------------------------------
// Lift a node upwards by "dist" steps
// --------------------------------------------------------------------------------------
int lift(int v, int dist) {
    for (int k = 0; k < LOG; k++) {
        if (dist & (1 << k)) {
            v = parent[k][v];
            if (v == -1) break;
        }
    }
    return v;
}

// --------------------------------------------------------------------------------------
// Compute LCA(u, v)
// --------------------------------------------------------------------------------------
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    // 1. Lift u to same depth as v
    u = lift(u, depth[u] - depth[v]);
    if (u == v) return u;

    // 2. Lift both up from highest jump downwards
    for (int k = LOG - 1; k >= 0; k--) {
        if (parent[k][u] != parent[k][v]) {
            u = parent[k][u];
            v = parent[k][v];
        }
    }

    // 3. Now their parent is LCA
    return parent[0][u];
}

// --------------------------------------------------------------------------------------
// Example usage (remove/modify in production)
// --------------------------------------------------------------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example Input:
    // n = 7
    // Edges:
    // 1-2, 1-3, 2-4, 2-5, 3-6, 3-7
    //
    // Queries:
    // LCA(4, 5) = 2
    // LCA(4, 6) = 1
    // LCA(6, 7) = 3

    cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        depth[i] = 0;
        for (int k = 0; k < LOG; k++) parent[k][i] = -1;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Root the tree at 1 (can be changed)
    dfs(1, -1, 0);

    // Binary lifting table
    preprocess();

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }

    return 0;
}

// --------------------------------------------------------------------------------------
// Complexity:
//   Preprocessing: O(N log N)
//   Query: O(log N)
//   Memory: O(N log N)
//
// Variations:
//   - Can support dynamic trees with heavy-light decomposition
//   - Euler Tour + RMQ approach gives O(1) query time
// --------------------------------------------------------------------------------------

