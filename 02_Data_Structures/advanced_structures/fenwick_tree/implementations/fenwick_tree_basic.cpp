// /02_Data_Structures/advanced_structures/fenwick_tree/implementation/fenwick_tree_basic.cpp
// ------------------------------------------------------------------------------------------------
// Fenwick Tree (Binary Indexed Tree) - Basic Implementation in C++
//
// Problem Description:
//   Maintain an array A[1..n] supporting:
//     - Point updates: A[i] += delta
//     - Prefix sums:   sum(1..i)
//     - Range sums:    sum(l..r) = prefix(r) - prefix(l-1)
//
// Motivation:
//   Fenwick Tree gives O(log n) time for both updates and queries
//   while using only O(n) memory.
//
// Core Idea:
//   fenw[i] stores the sum of the range (i - LSB(i) + 1) ... i
//   where LSB(i) = i & -i.
//
// Algorithm Details:
//   update(i, delta):
//       while i <= n:
//           fenw[i] += delta
//           i += LSB(i)
//
//   prefix_sum(i):
//       while i > 0:
//           res += fenw[i]
//           i -= LSB(i)
//
// Complexity:
//   - update:      O(log n)
//   - prefix_sum:  O(log n)
//   - range_sum:   O(log n)
//   - space:       O(n)
//
// Variations included:
//   - 1-based index implementation
//   - Optional O(n) build constructor
//   - Optional find-by-prefix (order-statistics) support
//
// ------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
private:
    int n;
    vector<long long> fenw;

    // Least Significant Bit
    static int lsb(int x) {
        return x & -x;
    }

public:
    // Constructor: initializes tree with zeros
    FenwickTree(int n) : n(n), fenw(n + 1, 0) {}

    // Construct from vector (O(n) build)
    FenwickTree(const vector<long long>& arr) {
        n = arr.size();
        fenw.assign(n + 1, 0);

        // copy arr to fenw as 1-based
        for (int i = 1; i <= n; i++) fenw[i] = arr[i - 1];

        // build in O(n)
        for (int i = 1; i <= n; i++) {
            int j = i + lsb(i);
            if (j <= n)
                fenw[j] += fenw[i];
        }
    }

    // Point update: A[i] += delta
    void add(int i, long long delta) {
        while (i <= n) {
            fenw[i] += delta;
            i += lsb(i);
        }
    }

    // Prefix sum: sum A[1..i]
    long long prefix_sum(int i) const {
        long long res = 0;
        while (i > 0) {
            res += fenw[i];
            i -= lsb(i);
        }
        return res;
    }

    // Range sum: sum A[l..r]
    long long range_sum(int l, int r) const {
        if (l > r) return 0;
        return prefix_sum(r) - prefix_sum(l - 1);
    }

    // Order statistics:
    // Find smallest idx such that prefix_sum(idx) >= target
    // Requires all values non-negative.
    int find_by_prefix(long long target) const {
        if (target <= 0) return 1;

        long long total = prefix_sum(n);
        if (target > total) return -1; // not found

        int idx = 0;
        int bit = 1;

        // largest power of two <= n
        while (bit << 1 <= n) bit <<= 1;

        // binary lifting using Fenwick structure
        while (bit) {
            int next_idx = idx + bit;
            if (next_idx <= n && fenw[next_idx] < target) {
                target -= fenw[next_idx];
                idx = next_idx;
            }
            bit >>= 1;
        }
        return idx + 1; // convert to smallest valid index
    }
};

// ------------------------------------------------------------------------------------------------
// Optional: Basic demonstration and internal verification
// ------------------------------------------------------------------------------------------------
int main() {
    // Basic example
    vector<long long> arr = {3, 2, -1, 6, 5, 4, -3, 3, 7, 2, 3};

    FenwickTree ft(arr);  // O(n) build

    // Test prefix sums
    for (int i = 1; i <= (int)arr.size(); i++) {
        long long naive = accumulate(arr.begin(), arr.begin() + i, 0LL);
        assert(ft.prefix_sum(i) == naive);
    }

    // Range sum tests
    assert(ft.range_sum(2, 5) == accumulate(arr.begin() + 1, arr.begin() + 5, 0LL));
    assert(ft.range_sum(1, 1) == arr[0]);
    assert(ft.range_sum(4, 4) == arr[3]);

    // Point update tests
    ft.add(3, +10);  // A[3] += 10
    arr[2] += 10;
    long long p10 = accumulate(arr.begin(), arr.begin() + 10, 0LL);
    assert(ft.prefix_sum(10) == p10);

    // Order statistics on non-negative array
    vector<long long> pos = {1, 1, 2, 3, 5, 8};
    FenwickTree ft2(pos);

    assert(ft2.find_by_prefix(1) == 1);
    assert(ft2.find_by_prefix(3) == 3); // 1+1+2
    assert(ft2.find_by_prefix(4) == 4); // 1+1+2+3
    assert(ft2.find_by_prefix(20) == 6);
    assert(ft2.find_by_prefix(21) == -1);

    cout << "Fenwick Tree basic tests passed.\n";
    return 0;
}

