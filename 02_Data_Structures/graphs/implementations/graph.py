"""
File: graph.py
Path: dsa/02_Data_Structures/graphs/implementations/

Description:
-------------
This file contains a Python implementation of the Graph data structure
using both adjacency list and adjacency matrix representations.
It includes Depth-First Search (DFS) and Breadth-First Search (BFS)
traversals, demonstrating both recursive and iterative approaches.

Concepts Covered:
-----------------
1. Graph Representation:
    - Adjacency List
    - Adjacency Matrix
2. Graph Traversals:
    - Depth-First Search (DFS) - recursive & iterative
    - Breadth-First Search (BFS)
3. Complexity Analysis:
    - Time and space for graph operations and traversals
4. Directed and Undirected graphs support

Author: [Your Name]
Date: [Date]
"""

from collections import deque

class Graph:
    def __init__(self, vertices, directed=False):
        """
        Initializes a graph with the given number of vertices.

        Args:
            vertices (int): Number of vertices in the graph
            directed (bool): Whether the graph is directed
        """
        self.V = vertices
        self.directed = directed
        self.adj_list = [[] for _ in range(vertices)]   # adjacency list
        self.adj_matrix = [[0]*vertices for _ in range(vertices)]  # adjacency matrix

    def add_edge(self, u, v):
        """
        Adds an edge from u to v.

        Args:
            u (int): Source vertex
            v (int): Destination vertex
        """
        # Adjacency List
        self.adj_list[u].append(v)
        if not self.directed:
            self.adj_list[v].append(u)

        # Adjacency Matrix
        self.adj_matrix[u][v] = 1
        if not self.directed:
            self.adj_matrix[v][u] = 1

    def print_adj_list(self):
        """Prints the adjacency list of the graph"""
        print("Adjacency List:")
        for i, neighbors in enumerate(self.adj_list):
            print(f"{i}: {' '.join(map(str, neighbors))}")

    def print_adj_matrix(self):
        """Prints the adjacency matrix of the graph"""
        print("Adjacency Matrix:")
        for row in self.adj_matrix:
            print(' '.join(map(str, row)))

    # DFS Recursive
    def _dfs_recursive(self, v, visited):
        visited[v] = True
        print(v, end=' ')
        for neighbor in self.adj_list[v]:
            if not visited[neighbor]:
                self._dfs_recursive(neighbor, visited)

    def DFS(self, start):
        """
        Depth-First Search (DFS) traversal - recursive
        Args:
            start (int): Starting vertex
        """
        visited = [False]*self.V
        print(f"DFS Recursive from vertex {start}: ", end='')
        self._dfs_recursive(start, visited)
        print()

    # DFS Iterative
    def DFS_iterative(self, start):
        """
        Depth-First Search (DFS) traversal - iterative using stack
        Args:
            start (int): Starting vertex
        """
        visited = [False]*self.V
        stack = [start]
        print(f"DFS Iterative from vertex {start}: ", end='')

        while stack:
            u = stack.pop()
            if not visited[u]:
                print(u, end=' ')
                visited[u] = True
                # Push neighbors in reverse to mimic recursive order
                stack.extend(reversed(self.adj_list[u]))
        print()

    # BFS
    def BFS(self, start):
        """
        Breadth-First Search (BFS) traversal using queue
        Args:
            start (int): Starting vertex
        """
        visited = [False]*self.V
        queue = deque([start])
        visited[start] = True
        print(f"BFS from vertex {start}: ", end='')

        while queue:
            u = queue.popleft()
            print(u, end=' ')
            for neighbor in self.adj_list[u]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)
        print()


# Example usage
if __name__ == "__main__":
    g = Graph(5)  # Undirected graph with 5 vertices

    # Adding edges
    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    g.add_edge(2, 4)

    g.print_adj_list()
    g.print_adj_matrix()

    g.DFS(0)           # Recursive DFS
    g.DFS_iterative(0) # Iterative DFS
    g.BFS(0)           # BFS

"""
Variations / Extensions:
------------------------
- Weighted Graphs: adjacency list with (neighbor, weight) tuples
- Cycle detection using DFS recursion stack
- Topological sort using DFS post-order
- Strongly Connected Components (Kosaraju / Tarjan)

Interview Tips:
---------------
- Be fluent with adjacency list & matrix representation
- Know iterative vs recursive DFS
- BFS is preferred for shortest paths in unweighted graphs
"""

