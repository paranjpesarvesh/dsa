# /02_Data_Structures/advanced_structures/fenwick_tree/implementation/fenwick_tree_range_update.py
# ------------------------------------------------------------------------------------------------
# Fenwick Tree Supporting Range Updates + Point Queries (RUQ)
#
# Description:
#   Standard Fenwick Tree supports:
#       - Point updates
#       - Prefix sum queries
#   This version supports:
#       - Range updates: add value 'delta' to range [l, r]
#       - Point queries: value at index i after all applied updates
#
# Core Insight:
#   To support range updates efficiently, maintain a Fenwick Tree over the
#   difference array. When performing:
#       add l..r with delta
#   we do:
#       add(l, delta)
#       add(r+1, -delta)
#
#   Then value at index i becomes:
#       A[i] = prefix_sum(i)
#
# Why it Works:
#   Difference array D satisfies:
#       A[1] = D[1]
#       A[i] = A[i-1] + D[i]
#   Range update on A corresponds to two point updates on D.
#
# Complexity:
#   - Range update: O(log n)
#   - Point query:  O(log n)
#   - Memory:       O(n)
#
# Variations:
#   1. Range update + point query (implemented here)
#   2. Range update + range query   --> requires two Fenwick trees
#   3. Point update + range query   --> standard Fenwick tree
#
# Interview notes:
#   - Know difference array trick
#   - LSB trick: i & -i
#   - Prefix sums represent accumulated increments
# ------------------------------------------------------------------------------------------------

from typing import List


class FenwickRangeUpdate:
    """
    Fenwick Tree supporting:
        - Range updates: add delta to A[l..r]
        - Point query:  A[i]

    Internal structure:
        fenw[i] stores contributions to the difference array.

    All indices are 1-based.
    """

    def __init__(self, n: int):
        assert n >= 1, "Size must be >= 1"
        self.n = n
        self.fenw: List[int] = [0] * (n + 1)

    @staticmethod
    def _lsb(x: int) -> int:
        return x & -x

    def _add(self, i: int, delta: int) -> None:
        """Internal point update on difference structure."""
        while i <= self.n:
            self.fenw[i] += delta
            i += self._lsb(i)

    def range_add(self, l: int, r: int, delta: int) -> None:
        """
        Add delta to range A[l..r]

        Achieved by:
            D[l]     += delta
            D[r + 1] -= delta
        """
        if l > r:
            return
        self._add(l, delta)
        if r + 1 <= self.n:
            self._add(r + 1, -delta)

    def point_query(self, i: int) -> int:
        """
        Returns A[i] after all range updates applied.

        A[i] = prefix_sum(i) over difference array.
        """
        res = 0
        while i > 0:
            res += self.fenw[i]
            i -= self._lsb(i)
        return res

    # Optional 0-based convenience wrappers
    def range_add_0(self, l0: int, r0: int, delta: int) -> None:
        self.range_add(l0 + 1, r0 + 1, delta)

    def point_query_0(self, i0: int) -> int:
        return self.point_query(i0 + 1)


# ------------------------------------------------------------------------------------------------
# Self-test section (can be removed in production)
# ------------------------------------------------------------------------------------------------
if __name__ == "__main__":
    n = 10
    fru = FenwickRangeUpdate(n)
    arr = [0] * n  # naive reference for validation

    def naive_range_add(l, r, delta):
        for i in range(l - 1, r):
            arr[i] += delta

    # Perform some random range updates
    updates = [
        (1, 5, 3),
        (2, 7, -2),
        (4, 10, 1),
        (3, 3, 5),
    ]

    for (l, r, d) in updates:
        fru.range_add(l, r, d)
        naive_range_add(l, r, d)

    # Validate point queries
    for i in range(1, n + 1):
        assert fru.point_query(i) == arr[i - 1], f"Mismatch at index {i}"

    print("Fenwick Range Update tests passed.")

