# /02_Data_Structures/advanced_structures/fenwick_tree/implementation/fenwick_tree_basic.py
# -----------------------------------------------------------------------------
# Fenwick Tree (Binary Indexed Tree) - Basic Implementation
#
# Problem/Goal:
#   Maintain a dynamic array A[1..n] under:
#     1) Point updates: A[i] += delta
#     2) Prefix sums:   sum(1..i)
#     3) Optional range sums: sum(l..r) = sum(1..r) - sum(1..l-1)
#
# Why Fenwick Tree:
#   - O(log n) per update and query
#   - O(n) space
#   - Simpler than Segment Tree when only sums + point updates are needed
#
# Core Idea:
#   fenw[i] stores sum over (i - LSB(i) + 1) .. i, where LSB(i) = i & -i.
#   Query walks indices downward: i -= LSB(i).
#   Update walks indices upward:  i += LSB(i).
#
# Complexity:
#   - update/add:      O(log n)
#   - prefix_sum:      O(log n)
#   - range_sum:       O(log n)
#   - build (fast):    O(n)   (using internal parent linking)
#   - memory:          O(n)
#
# Variations Included:
#   - 1-based indexing (canonical)
#   - O(n) build from iterable
#   - range_sum(l, r)
#   - find_by_prefix(k): smallest idx such that prefix_sum(idx) >= k
#   - Thin 0-based index wrappers for convenience
#
# Interview Notes:
#   - Most implementations are 1-based; convert if input is 0-based.
#   - Mention LSB trick: i & -i
#   - Compare with Segment Tree (heavier but more flexible: min/max/range updates).
# -----------------------------------------------------------------------------


from typing import Iterable, List, Optional


class FenwickTree:
    """
    Fenwick Tree (Binary Indexed Tree) for prefix sums with point updates.

    Indexing:
        Internally 1-based. Public methods expect 1 <= i <= n.
        Convenience 0-based wrappers are provided (suffix `_0`).

    Attributes
    ----------
    n : int
        Size of the array.
    fenw : List[int/float]
        Internal tree array (length n+1), 1-based.

    Example
    -------
    >>> ft = FenwickTree(5)
    >>> ft.add(1, 5)     # A[1] += 5
    >>> ft.add(3, 2)     # A[3] += 2
    >>> ft.prefix_sum(3) # sum A[1..3] = 7
    7
    >>> ft.range_sum(2, 3)  # sum A[2..3] = 2
    2
    """

    def __init__(self, n: int):
        assert n >= 1, "FenwickTree size must be >= 1"
        self.n = n
        # fenw[0] is unused to keep arithmetic cleaner
        self.fenw: List[int] = [0] * (n + 1)

    # -----------------------
    # Helpers and core ops
    # -----------------------
    @staticmethod
    def _lsb(x: int) -> int:
        """Least Significant Bit (power of two that divides x)."""
        return x & -x

    def add(self, i: int, delta: int) -> None:
        """
        Point update: A[i] += delta  (1-based index)

        Time: O(log n)
        """
        while i <= self.n:
            self.fenw[i] += delta
            i += self._lsb(i)

    def prefix_sum(self, i: int) -> int:
        """
        Query prefix sum: sum A[1..i]  (1-based index)

        Time: O(log n)
        """
        res = 0
        while i > 0:
            res += self.fenw[i]
            i -= self._lsb(i)
        return res

    def range_sum(self, l: int, r: int) -> int:
        """
        Query range sum: sum A[l..r]  (1-based index, requires l <= r)

        Time: O(log n)
        """
        if l > r:
            return 0
        return self.prefix_sum(r) - self.prefix_sum(l - 1)

    # -----------------------
    # Construction
    # -----------------------
    @classmethod
    def from_iterable(cls, arr: Iterable[int]) -> "FenwickTree":
        """
        Build Fenwick Tree from 1D iterable in O(n).

        The trick:
            For i in [1..n], let j = i + LSB(i).
            Then fenw[j] += fenw[i], if j <= n.

        Time: O(n)
        """
        data = list(arr)
        n = len(data)
        assert n >= 1, "Input iterable must be non-empty"

        ft = cls(n)
        # copy as 1-based into fenw
        for i in range(1, n + 1):
            ft.fenw[i] = data[i - 1]
        # build in O(n)
        for i in range(1, n + 1):
            j = i + cls._lsb(i)
            if j <= n:
                ft.fenw[j] += ft.fenw[i]
        return ft

    # -----------------------
    # Order-statistics helper
    # -----------------------
    def find_by_prefix(self, target: int) -> Optional[int]:
        """
        Find smallest index idx in [1..n] such that prefix_sum(idx) >= target.
        Returns None if total sum < target.

        Assumptions:
            - All values are non-negative (monotone prefix sums).
        Time: O(log n)
        """
        if target <= 0:
            return 1
        # If total sum < target -> not found
        total = self.prefix_sum(self.n)
        if target > total:
            return None

        # Binary lifting over fenwick structure.
        idx = 0
        bit = 1
        # Largest power of two <= n
        while bit << 1 <= self.n:
            bit <<= 1

        # Descend using fenwick tree's implicit binary decomposition
        while bit:
            nxt = idx + bit
            if nxt <= self.n and self.fenw[nxt] < target:
                target -= self.fenw[nxt]
                idx = nxt
            bit >>= 1
        return idx + 1  # convert to 1-based smallest index

    # -----------------------
    # 0-based convenience API
    # -----------------------
    def add_0(self, i0: int, delta: int) -> None:
        """Point update for 0-based index i0."""
        self.add(i0 + 1, delta)

    def prefix_sum_0(self, i0: int) -> int:
        """Prefix sum over A[0..i0] for 0-based index i0."""
        return self.prefix_sum(i0 + 1)

    def range_sum_0(self, l0: int, r0: int) -> int:
        """Range sum over A[l0..r0] for 0-based indices."""
        return self.range_sum(l0 + 1, r0 + 1)


# -----------------------------------------------------------------------------
# Optional: simple self-check (can be removed in production)
# -----------------------------------------------------------------------------
if __name__ == "__main__":
    # Example usage and quick correctness check

    # Build from iterable (O(n))
    arr = [3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3]
    ft = FenwickTree.from_iterable(arr)

    # Check prefix sums vs naive
    for i in range(1, len(arr) + 1):
        naive = sum(arr[:i])
        assert ft.prefix_sum(i) == naive, f"prefix mismatch at {i}"

    # Range queries
    assert ft.range_sum(2, 5) == sum(arr[1:5])
    assert ft.range_sum(1, 1) == arr[0]
    assert ft.range_sum(4, 4) == arr[3]
    assert ft.range_sum(6, 3) == 0  # l > r

    # Point updates
    ft.add(3, +10)       # A[3] += 10
    arr[2] += 10
    assert ft.prefix_sum(10) == sum(arr[:10])

    # 0-based wrappers
    ft.add_0(0, -3)      # A[0] -= 3
    arr[0] -= 3
    assert ft.prefix_sum_0(4) == sum(arr[:5])
    assert ft.range_sum_0(2, 6) == sum(arr[2:7])

    # Order-statistics (find_by_prefix)
    # ensure non-negative for monotone prefix search
    arr_nonneg = [1, 1, 2, 3, 5, 8]
    ft2 = FenwickTree.from_iterable(arr_nonneg)
    # total = 20, find first idx with prefix >= k
    assert ft2.find_by_prefix(1) == 1
    assert ft2.find_by_prefix(3) == 3  # 1+1+2
    assert ft2.find_by_prefix(4) == 4  # 1+1+2+3
    assert ft2.find_by_prefix(20) == 6
    assert ft2.find_by_prefix(21) is None

    print("FenwickTree basic tests passed.")

