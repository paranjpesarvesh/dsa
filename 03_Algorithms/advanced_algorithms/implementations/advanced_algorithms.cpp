#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

/**
 * Ford-Fulkerson Algorithm - O(VE²)
 * Finds maximum flow in a network using augmenting paths
 */
class FordFulkerson {
public:
    int V;
    vector<vector<int>> capacity;
    vector<vector<int>> flow;

public:
    FordFulkerson(int V) : V(V) {
        capacity.resize(V, vector<int>(V, 0));
        flow.resize(V, vector<int>(V, 0));
    }
    
    void addEdge(int u, int v, int cap) {
        this->capacity[u][v] = cap;
    }
    
    bool bfs(int s, int t, vector<int>& parent) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v = 0; v < V; v++) {
                if (!visited[v] && capacity[u][v] - flow[u][v] > 0) {
                    q.push(v);
                    visited[v] = true;
                    parent[v] = u;
                }
            }
        }
        }
        
        return visited[t];
    }
    
    int maxFlow(int s, int t) {
        int max_flow = 0;
        vector<int> parent(V);
        
        while (bfs(s, t, parent)) {
            int path_flow = INT_MAX;
            
            // Find minimum residual capacity along the path
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                path_flow = min(path_flow, capacity[u][v] - flow[u][v]);
            }
            
            // Update flow along the path
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                flow[u][v] += path_flow;
                flow[v][u] -= path_flow;
            }
            
            max_flow += path_flow;
        }
        
        return max_flow;
    }
};

/**
 * Bipartite Matching using Hopcroft-Karp - O(E√V)
 * Finds maximum matching in bipartite graphs
 */
class HopcroftKarp {
    int U, V;
    vector<vector<int>> adj;
    vector<int> pairU, pairV;
    vector<int> dist;

public:
    HopcroftKarp(int U, int V) : U(U), V(V) {
        adj.resize(U);
        pairU.resize(U, -1);
        pairV.resize(V, -1);
        dist.resize(U);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    bool bfs() {
        queue<int> q;
        
        for (int u = 0; u < U; u++) {
            if (pairU[u] == -1) {
                dist[u] = 0;
                q.push(u);
            } else {
                dist[u] = INT_MAX;
            }
        }
        
        bool found = false;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : adj[u]) {
                if (pairV[v] != -1 && dist[pairV[v]] == INT_MAX) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                    found = true;
                }
            }
        }
        
        return found;
    }
    
    int maxMatching() {
        int result = 0;
        
        while (bfs()) {
            vector<int> distU(U, INT_MAX);
            queue<int> q;
            
            // Find free vertex in U
            for (int u = 0; u < U; u++) {
                if (pairU[u] == -1) {
                    distU[u] = 0;
                    q.push(u);
                }
            }
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                for (int v : adj[u]) {
                    if (pairV[v] != -1 && distU[u] < dist[pairV[v]]) {
                        distU[u] = dist[pairV[v]] + 1;
                        q.push(pairV[v]);
                    }
                }
            }
            
            // Augment matching
            for (int u = 0; u < U; u++) {
                if (pairU[u] == -1 && distU[u] != INT_MAX) {
                    for (int v : adj[u]) {
                        if (pairV[v] != -1 && distU[u] == dist[pairV[v]] + 1) {
                            pairU[u] = v;
                            pairV[v] = u;
                            result++;
                            break;
                        }
                    }
                }
            }
        }
        
        return result;
    }
};

// Test function
void testAdvancedAlgorithms() {
    cout << "=== Ford-Fulkerson Algorithm ===" << endl;
    
    FordFulkerson ff(6);
    ff.addEdge(0, 1, 16);
    ff.addEdge(0, 2, 13);
    ff.addEdge(1, 2, 10);
    ff.addEdge(1, 3, 12);
    ff.addEdge(2, 1, 4);
    ff.addEdge(2, 4, 14);
    ff.addEdge(3, 2, 9);
    ff.addEdge(3, 5, 20);
    
    cout << "Maximum flow from 0 to 5: " << ff.maxFlow(0, 5) << endl;
    
    cout << "\n=== Hopcroft-Karp Algorithm ===" << endl;
    
    HopcroftKarp hk(4, 4);
    hk.addEdge(0, 0);
    hk.addEdge(0, 1);
    hk.addEdge(1, 1);
    hk.addEdge(1, 2);
    hk.addEdge(2, 2);
    hk.addEdge(2, 3);
    hk.addEdge(3, 3);
    
    cout << "Maximum bipartite matching: " << hk.maxMatching() << endl;
}

int main() {
    testAdvancedAlgorithms();
    return 0;
}