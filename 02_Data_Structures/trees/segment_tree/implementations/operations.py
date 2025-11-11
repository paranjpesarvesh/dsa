# operations.py
# Segment Tree Implementation (Sum Query + Point Update)
#
# Features:
# - Build segment tree from array
# - Query range sum [l, r]
# - Update index (point update)
#
# Complexity:
#   Build: O(n)
#   Query: O(log n)
#   Update: O(log n)
#
# Notes:
# - Tree stored as 1-indexed array for convenience
# - Supports large values using Python's int

class SegmentTree:
    def __init__(self, arr):
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)
        self._build(arr, 1, 0, self.n - 1)

    # Build the tree recursively
    def _build(self, arr, idx, left, right):
        if left == right:
            self.tree[idx] = arr[left]
            return
        mid = (left + right) // 2
        self._build(arr, 2 * idx, left, mid)
        self._build(arr, 2 * idx + 1, mid + 1, right)
        self.tree[idx] = self.tree[2 * idx] + self.tree[2 * idx + 1]

    # Query the sum in range [ql, qr]
    def query(self, ql, qr):
        return self._query(1, 0, self.n - 1, ql, qr)

    def _query(self, idx, left, right, ql, qr):
        if qr < left or ql > right:
            return 0
        if ql <= left and right <= qr:
            return self.tree[idx]
        mid = (left + right) // 2
        L = self._query(2 * idx, left, mid, ql, qr)
        R = self._query(2 * idx + 1, mid + 1, right, ql, qr)
        return L + R

    # Point update: set arr[pos] = val
    def update(self, pos, val):
        self._update(1, 0, self.n - 1, pos, val)

    def _update(self, idx, left, right, pos, val):
        if left == right:
            self.tree[idx] = val
            return
        mid = (left + right) // 2
        if pos <= mid:
            self._update(2 * idx, left, mid, pos, val)
        else:
            self._update(2 * idx + 1, mid + 1, right, pos, val)
        self.tree[idx] = self.tree[2 * idx] + self.tree[2 * idx + 1]


# Example usage
if __name__ == "__main__":
    arr = [1, 3, 5, 7, 9, 11]
    st = SegmentTree(arr)

    print("Sum of [1, 3]:", st.query(1, 3))  # 3+5+7 = 15

    st.update(1, 10)  # arr[1] = 10
    print("After update, sum of [1, 3]:", st.query(1, 3))  # 10+5+7 = 22
