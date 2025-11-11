// /02_Data_Structures/advanced_structures/lca/implementation.cpp
// --------------------------------------------------------------------------------------
// Lowest Common Ancestor (LCA) - Binary Lifting Implementation
//
// Description:
//   Given a tree with N nodes (1-indexed), support queries:
//       LCA(u, v)
//   using preprocessing in O(N log N) and answering each query in O(log N).
//
// Why Binary Lifting?
//   - Extremely efficient
//   - Easy to implement
//   - Works for large trees
//
// Algorithm Steps:
//   1. Run DFS/BFS to compute depth[] and parent[0][v] for each node.
//   2. Build parent[k][v] = 2^k-th ancestor of v.
//   3. To find LCA(u, v):
//        a) Lift deeper node to same depth.
//        b) Lift both nodes upward until parents differ.
//        c) Return their parent.
//
// Complexity:
//   Preprocessing: O(N log N)
//   Query: O(log N)
//   Memory: O(N log N)
//
// Assumptions:
//   - Tree is undirected and connected
//   - Root is chosen as 1 (modifiable)
// --------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 200000;
static const int LOG = 20;

vector<int> adj[MAXN + 1];
int parent[LOG][MAXN + 1];
int depth[MAXN + 1];
int n;

// --------------------------------------------------------------------------------------
// DFS to compute depth and immediate parent
// --------------------------------------------------------------------------------------
void dfs(int v, int p) {
    parent[0][v] = p;
    for (int nxt : adj[v]) {
        if (nxt == p) continue;
        depth[nxt] = depth[v] + 1;
        dfs(nxt, v);
    }
}

// --------------------------------------------------------------------------------------
// Preprocess ancestors: parent[k][v] = 2^k-th ancestor
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
// Lift node u upward by dist steps
// --------------------------------------------------------------------------------------
int lift(int u, int dist) {
    for (int k = 0; k < LOG; k++) {
        if (dist & (1 << k)) {
            u = parent[k][u];
            if (u == -1) break;
        }
    }
    return u;
}

// --------------------------------------------------------------------------------------
// Compute LCA(u, v)
// --------------------------------------------------------------------------------------
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    // Step 1: bring u and v to the same depth
    u = lift(u, depth[u] - depth[v]);
    if (u == v) return u;

    // Step 2: lift both nodes upward until their parents diverge
    for (int k = LOG - 1; k >= 0; k--) {
        if (parent[k][u] != parent[k][v]) {
            u = parent[k][u];
            v = parent[k][v];
        }
    }

    // Step 3: parent is LCA
    return parent[0][u];
}

// --------------------------------------------------------------------------------------
// Driver for testing (you can modify/remove as needed)
// --------------------------------------------------------------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        depth[i] = 0;
        for (int k = 0; k < LOG; k++) parent[k][i] = -1;
    }

    // Input edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Root tree at 1
    dfs(1, -1);

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
// Complexity Summary:
//   Preprocessing: O(N log N)
//   Query: O(log N)
//   Space: O(N log N)
//
// Variations:
//   - Euler Tour + RMQ gives O(1) query time
//   - LCA with Heavy-Light Decomposition
//   - Binary lifting works for weighted trees (for distance queries)
//
// End of file
// --------------------------------------------------------------------------------------

