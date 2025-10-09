"""
===============================================================================
📌 Problem Statement:
Implement the Disjoint Set Union (DSU) / Union-Find data structure in Python.

The DSU should efficiently support:
1. find(x): Find the representative (root) of the set containing x.
2. union(x, y): Merge the sets containing x and y.

Optimizations required:
- Path Compression in find.
- Union by Rank or Size in union.

===============================================================================
🔹 Explanation of Algorithm Choice:
We represent disjoint sets as a forest of trees:
- Each node has a parent pointer.
- `find` compresses paths to reduce tree height.
- `union` attaches smaller rank/size tree under larger one to keep balance.

Amortized Time Complexity:
- FIND: O(α(n))  [Inverse Ackermann Function ≈ constant in practice].
- UNION: O(α(n)).
- Effectively near O(1) for real-world inputs.

Space Complexity:
- O(n) for parent and rank/size arrays.

===============================================================================
"""

class DisjointSet:
    def __init__(self, n: int):
        """
        Initialize DSU with n elements (1-indexed by default).
        Each element is initially its own parent.
        """
        self.parent = [i for i in range(n + 1)]
        self.rank = [0] * (n + 1)  # or could use size array instead

    def find(self, x: int) -> int:
        """
        FIND with Path Compression.
        Returns the representative/root of the set containing x.
        """
        if self.parent[x] != x:
            # Recursively compress path
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x: int, y: int) -> None:
        """
        UNION by Rank.
        Merges the sets containing x and y.
        """
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x == root_y:
            return  # already in the same set

        # Attach smaller rank tree under larger rank tree
        if self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
        elif self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1

    def connected(self, x: int, y: int) -> bool:
        """
        Check if elements x and y belong to the same set.
        """
        return self.find(x) == self.find(y)


# =============================================================================
# Example Usage
# =============================================================================
if __name__ == "__main__":
    n = 7
    dsu = DisjointSet(n)

    # Initial unions
    dsu.union(1, 2)
    dsu.union(2, 3)
    dsu.union(4, 5)
    dsu.union(6, 7)

    print("Are 1 and 3 connected?", "Yes" if dsu.connected(1, 3) else "No")
    print("Are 4 and 6 connected?", "Yes" if dsu.connected(4, 6) else "No")

    # Connecting components
    dsu.union(5, 6)
    print("After union(5,6), are 4 and 7 connected?",
          "Yes" if dsu.connected(4, 7) else "No")


"""
===============================================================================
🔹 Variations & Notes:
- Union by Size: Track set size instead of rank and attach smaller set under larger one.
- Rollback DSU: Supports undo operations (used in offline dynamic connectivity).
- DSU with Metadata: Store extra info in each set (e.g., size, min/max, sum).

===============================================================================
🔹 Interview Tips:
- DSU is a building block in Kruskal’s MST, cycle detection, connected components.
- Must know both path compression & union by rank/size → guarantees O(α(n)).
- Be prepared to extend DSU for advanced problems (e.g., bipartite checks).

===============================================================================
"""

