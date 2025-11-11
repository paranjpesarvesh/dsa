# /02_Data_Structures/advanced_structures/lca/implementation.py
# --------------------------------------------------------------------------------------
# Lowest Common Ancestor (LCA) — Binary Lifting (Python)
#
# Problem:
#   Preprocess a rooted tree to answer LCA(u, v) queries efficiently.
#
# Approach:
#   Binary Lifting precomputes parent[k][v] = 2^k-th ancestor of v and depth[v].
#   To find LCA(u, v):
#     1) Lift the deeper node to the same depth.
#     2) Lift both nodes up from highest power-of-two until their parents match.
#     3) The parent is the LCA.
#
# Complexity:
#   Preprocessing: O(N log N)
#   Each LCA query: O(log N)
#   Memory: O(N log N)
#
# Notes:
#   - This implementation assumes 1-indexed nodes (1..N).
#   - Reads an undirected tree, roots it at 1 by default (can be changed).
#   - Also exposes kth_ancestor() and dist() helpers often needed in interviews.
# --------------------------------------------------------------------------------------

from typing import List
import sys
from collections import deque

sys.setrecursionlimit(1 << 25)


class LCA:
    def __init__(self, n: int, root: int = 1):
        """
        Initialize data structures but do not attach a graph yet.

        n: number of nodes (1..n)
        root: root of the tree
        """
        assert n >= 1
        self.n = n
        self.root = root
        self.LOG = max(1, (n).bit_length())  # ceil(log2(n+1))
        self.adj: List[List[int]] = [[] for _ in range(n + 1)]
        self.parent: List[List[int]] = [[-1] * (n + 1) for _ in range(self.LOG)]
        self.depth: List[int] = [0] * (n + 1)
        self._built = False

    def add_edge(self, u: int, v: int) -> None:
        """Add an undirected edge u-v."""
        self.adj[u].append(v)
        self.adj[v].append(u)

    def _build_rooting_bfs(self) -> None:
        """Root the tree at self.root; compute depth[] and parent[0][]."""
        r = self.root
        self.depth[r] = 0
        self.parent[0][r] = -1

        q = deque([r])
        visited = [False] * (self.n + 1)
        visited[r] = True

        while q:
            v = q.popleft()
            for nxt in self.adj[v]:
                if visited[nxt]:
                    continue
                visited[nxt] = True
                self.parent[0][nxt] = v
                self.depth[nxt] = self.depth[v] + 1
                q.append(nxt)

    def build(self) -> None:
        """
        Preprocess for binary lifting.
        Must be called after adding all edges.
        """
        self._build_rooting_bfs()
        # parent[k][v] = 2^k-th ancestor
        for k in range(1, self.LOG):
            up = self.parent[k]
            prev = self.parent[k - 1]
            for v in range(1, self.n + 1):
                mid = prev[v]
                up[v] = -1 if mid == -1 else prev[mid]
        self._built = True

    def _lift(self, v: int, dist: int) -> int:
        """Lift node v upward by 'dist' ancestors; returns -1 if above root."""
        for k in range(self.LOG):
            if v == -1:
                break
            if dist & (1 << k):
                v = self.parent[k][v]
        return v

    def lca(self, u: int, v: int) -> int:
        """Return LCA(u, v) in O(log N)."""
        if not self._built:
            raise RuntimeError("Call build() before queries.")

        if self.depth[u] < self.depth[v]:
            u, v = v, u

        # 1) Lift u to depth of v
        u = self._lift(u, self.depth[u] - self.depth[v])
        if u == v:
            return u

        # 2) Lift both up while parents differ
        for k in range(self.LOG - 1, -1, -1):
            pu = self.parent[k][u]
            pv = self.parent[k][v]
            if pu != pv:
                u, v = pu, pv

        # 3) Their parent is LCA
        return self.parent[0][u]

    # ------------------------ Useful helpers for interviews ------------------------

    def kth_ancestor(self, v: int, k: int) -> int:
        """
        Return the k-th ancestor of v (k >= 0), or -1 if it doesn't exist.
        kth_ancestor(v, 0) == v.
        """
        return self._lift(v, k)

    def dist(self, u: int, v: int) -> int:
        """
        Return the number of edges in the path between u and v.
        Uses depths + LCA.
        """
        w = self.lca(u, v)
        return self.depth[u] + self.depth[v] - 2 * self.depth[w]


# --------------------------------------------------------------------------------------
# Example usage / simple driver
# Input format (example):
#   n
#   n-1 lines: u v
#   q
#   q lines: u v
#
# Example:
#   7
#   1 2
#   1 3
#   2 4
#   2 5
#   3 6
#   3 7
#   3
#   4 5
#   4 6
#   6 7
#
# Output:
#   2
#   1
#   3
# --------------------------------------------------------------------------------------
if __name__ == "__main__":
    data = sys.stdin.read().strip().split()
    if data:
        it = iter(data)
        n = int(next(it))
        lca_struct = LCA(n, root=1)
        for _ in range(n - 1):
            u = int(next(it)); v = int(next(it))
            lca_struct.add_edge(u, v)
        lca_struct.build()

        q = int(next(it))
        out_lines = []
        for _ in range(q):
            u = int(next(it)); v = int(next(it))
            out_lines.append(str(lca_struct.lca(u, v)))
        sys.stdout.write("\n".join(out_lines) + "\n")

