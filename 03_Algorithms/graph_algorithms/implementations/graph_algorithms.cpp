#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

/**
 * Graph representation using adjacency list
 */
class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  // Undirected graph
    }
    
    vector<vector<int>> getAdjList() {
        return adj;
    }
    
    int getVertices() {
        return V;
    }
};

/**
 * BFS - O(V + E)
 * Level order traversal, shortest path in unweighted graphs
 */
vector<int> bfs(Graph& graph, int start) {
    int V = graph.getVertices();
    vector<bool> visited(V, false);
    vector<int> distance(V, -1);
    queue<int> q;
    
    visited[start] = true;
    distance[start] = 0;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : graph.getAdjList()[u]) {
            if (!visited[v]) {
                visited[v] = true;
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }
    
    return distance;
}

/**
 * DFS - O(V + E)
 * Depth first traversal, can detect cycles
 */
void dfsUtil(Graph& graph, int u, vector<bool>& visited) {
    visited[u] = true;
    cout << u << " ";
    
    for (int v : graph.getAdjList()[u]) {
        if (!visited[v]) {
            dfsUtil(graph, v, visited);
        }
    }
}

void dfs(Graph& graph, int start) {
    int V = graph.getVertices();
    vector<bool> visited(V, false);
    
    cout << "DFS traversal: ";
    dfsUtil(graph, start, visited);
    cout << endl;
}

/**
 * Dijkstra's Algorithm - O((V + E) log V)
 * Shortest path in weighted graphs with non-negative weights
 */
vector<int> dijkstra(Graph& graph, vector<vector<pair<int, int>>>& weightedAdj, int start) {
    int V = graph.getVertices();
    vector<int> distance(V, INT_MAX);
    vector<bool> visited(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    distance[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;
        
        for (auto& edge : weightedAdj[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (!visited[v] && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }
    
    return distance;
}

// Test function
void testGraphAlgorithms() {
    cout << "=== Graph Traversals ===" << endl;
    
    // Create sample graph
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    
    cout << "BFS from vertex 0: ";
    vector<int> bfsDist = bfs(g, 0);
    for (int i = 0; i < bfsDist.size(); i++) {
        cout << "Vertex " << i << ": " << bfsDist[i] << endl;
    }
    
    dfs(g, 0);
    
    cout << "\n=== Dijkstra's Algorithm ===" << endl;
    
    // Weighted graph for Dijkstra
    vector<vector<pair<int, int>>> weightedAdj(6);
    weightedAdj[0] = {{1, 4}, {2, 1}};
    weightedAdj[1] = {{3, 2}};
    weightedAdj[2] = {{3, 5}};
    weightedAdj[3] = {{4, 3}};
    weightedAdj[4] = {{5, 1}};
    
    vector<int> shortestDist = dijkstra(g, weightedAdj, 0);
    cout << "Shortest distances from vertex 0:" << endl;
    for (int i = 0; i < shortestDist.size(); i++) {
        if (shortestDist[i] != INT_MAX) {
            cout << "Vertex " << i << ": " << shortestDist[i] << endl;
        } else {
            cout << "Vertex " << i << ": Unreachable" << endl;
        }
    }
}

int main() {
    testGraphAlgorithms();
    return 0;
}