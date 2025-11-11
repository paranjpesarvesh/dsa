// operations.cpp
// Implementation of core Segment Tree operations
//
// Supported Operations:
// 1. Build segment tree from array
// 2. Query on a range [l, r]
// 3. Update a single index (point update)
//
// Notes:
// - This is a generic sum-segment-tree implementation.
// - Tree stored in array: tree[1] is root
// - Complexity:
//     Build: O(n)
//     Query: O(log n)
//     Update: O(log n)
//
// Variations (not implemented here but possible):
// - Lazy propagation (for range updates)
// - Min/max segment tree
// - GCD segment tree
// - Iterative segment tree
// - Multi-dimensional segment trees
//
// All indexing below is 0-based for array, but tree uses 1-based indexing.
//

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;                     // original array size
    vector<long long> tree;    // segment tree array

    // Build the tree recursively
    void build(vector<long long>& arr, int idx, int left, int right) {
        if (left == right) {
            tree[idx] = arr[left];    // leaf value
            return;
        }
        int mid = (left + right) / 2;
        build(arr, 2 * idx, left, mid);
        build(arr, 2 * idx + 1, mid + 1, right);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

    // Query sum over range [l, r]
    long long query(int idx, int left, int right, int ql, int qr) {
        if (qr < left || ql > right) return 0;  // no overlap
        if (ql <= left && right <= qr) return tree[idx]; // complete overlap
        int mid = (left + right) / 2;
        long long L = query(2 * idx, left, mid, ql, qr);
        long long R = query(2 * idx + 1, mid + 1, right, ql, qr);
        return L + R;  // combine
    }

    // Update arr[pos] = val
    void update(int idx, int left, int right, int pos, long long val) {
        if (left == right) {
            tree[idx] = val;
            return;
        }
        int mid = (left + right) / 2;
        if (pos <= mid) update(2 * idx, left, mid, pos, val);
        else update(2 * idx + 1, mid + 1, right, pos, val);
        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }

public:
    // constructor
    SegmentTree(vector<long long>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }

    // range query
    long long query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    // point update
    void update(int pos, long long val) {
        update(1, 0, n - 1, pos, val);
    }
};

int main() {
    // Example usage:

    vector<long long> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    cout << "Sum of [1, 3] = " << st.query(1, 3) << "\n";  // 3+5+7=15

    st.update(1, 10); // arr[1] = 10
    cout << "After update, sum of [1, 3] = " << st.query(1, 3) << "\n"; // 10+5+7=22

    return 0;
}

