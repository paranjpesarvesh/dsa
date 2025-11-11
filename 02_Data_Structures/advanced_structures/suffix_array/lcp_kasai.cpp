// -------------------------------------------------------------------------------------------------
// Kasai's Algorithm — Build LCP Array in O(n)
//
// Problem
//   Given a string s (length n) and its suffix array SA (size n), build the LCP array where:
//     LCP[i] = length of the Longest Common Prefix between suffixes starting at SA[i] and SA[i-1].
//   By convention LCP[0] = 0.
//
// Why Kasai?
//   - Linear time O(n)
//   - Very simple once you have the inverse of SA (rank array)
//   - Reuses previous comparison length (the "height" trick)
//
// References (conceptually):
//   - LCP is fundamental for substring queries, number of distinct substrings, RMQ over LCP, etc.
//
// Complexity
//   - Time:  O(n)
//   - Space: O(n)
//
// Notes
//   - SA should be a permutation of [0..n-1] that sorts suffixes s[i:] lexicographically.
//   - Works on general std::string (bytes). For wide characters, adapt type accordingly.
// -------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

/**
 * Build LCP array using Kasai's algorithm.
 *
 * @param s   Input string (size n)
 * @param sa  Suffix array (size n), sa[i] is start index of i-th smallest suffix
 * @return    LCP array (size n), LCP[0] = 0
 *
 * Idea:
 *   1) Compute rank[], the inverse permutation of sa: rank[pos] = order of suffix at pos.
 *   2) Traverse positions i = 0..n-1 in text order.
 *      Let r = rank[i]. Its previous suffix in SA order is at j = sa[r-1].
 *      Compare s[i+h] with s[j+h] starting from current height h (from previous step), increment h while equal.
 *      Set lcp[r] = h, then if h > 0 decrement h by 1.
 */
vector<int> build_lcp_kasai(const string& s, const vector<int>& sa) {
    int n = (int)s.size();
    vector<int> lcp(n, 0), rank(n, 0);

    // rank[pos] = index in SA
    for (int i = 0; i < n; ++i) rank[sa[i]] = i;

    int h = 0; // current LCP height reused across adjacent ranks
    for (int i = 0; i < n; ++i) {
        int r = rank[i];
        if (r == 0) {          // smallest suffix has no previous neighbor
            h = 0;             // reset height
            continue;
        }
        int j = sa[r - 1];     // previous suffix in SA order
        // Extend h while characters match
        while (i + h < n && j + h < n && s[i + h] == s[j + h]) ++h;
        lcp[r] = h;
        if (h > 0) --h;        // suffix trick: next comparison starts with at least h-1 matches
    }
    return lcp;
}

// -------------------------------------------------------------------------------------------------
// (Optional) Minimal O(n log n) suffix array for demo/testing.
// If you already have SA in your pipeline, you can remove this section.
// -------------------------------------------------------------------------------------------------
static vector<int> build_sa_doubling(const string& s) {
    int n = (int)s.size();
    vector<int> sa(n), rnk(n), tmp(n);
    iota(sa.begin(), sa.end(), 0);
    for (int i = 0; i < n; ++i) rnk[i] = (unsigned char)s[i];

    for (int k = 1; k < n; k <<= 1) {
        auto key = [&](int i) -> pair<int,int> {
            return { rnk[i], (i + k < n ? rnk[i + k] : -1) };
        };
        stable_sort(sa.begin(), sa.end(), [&](int a, int b){
            auto ka = key(a), kb = key(b);
            return (ka.first != kb.first) ? (ka.first < kb.first) : (ka.second < kb.second);
        });
        tmp[sa[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; ++i) {
            tmp[sa[i]] = tmp[sa[i-1]] + (key(sa[i-1]) < key(sa[i]));
            classes = max(classes, tmp[sa[i]] + 1);
        }
        rnk.swap(tmp);
        if (classes == n) break;
    }
    return sa;
}

// -------------------------------------------------------------------------------------------------
// Demo / Self-check
// -------------------------------------------------------------------------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example string
    string s = "banana";
    // Build SA (for demo). In your repo, SA may be produced elsewhere.
    vector<int> sa = build_sa_doubling(s);
    vector<int> lcp = build_lcp_kasai(s, sa);

    cout << "s: " << s << "\n";
    cout << "SA: ";
    for (int i = 0; i < (int)sa.size(); ++i)
        cout << sa[i] << (i + 1 == (int)sa.size() ? '\n' : ' ');
    cout << "Suffixes in SA order:\n";
    for (int idx : sa) cout << idx << ": " << s.substr(idx) << "\n";
    cout << "LCP: ";
    for (int i = 0; i < (int)lcp.size(); ++i)
        cout << lcp[i] << (i + 1 == (int)lcp.size() ? '\n' : ' ');

    return 0;
}

/*
---------------------------------------------------------------------------------------------------
Interview Notes & Variations

1) Why LCP[0] = 0?
   There is no previous suffix for SA[0].

2) How does the "height trick" give O(n)?
   Each character position advances h by at most 1 across all iterations,
   and we decrease h by at most 1 per step. Total increments ≤ n.

3) Uses:
   - Number of distinct substrings = n*(n+1)/2 - sum(LCP)
   - Repeated substring queries (LRS)
   - LCP RMQ for LCP between any two suffixes SA[i], SA[j]

4) For arbitrary two suffixes (i, j) LCP query:
   - Precompute RMQ over LCP; LCP between suffixes at ranks r1, r2 is
     RMQ(LCP, min(r1,r2)+1 .. max(r1,r2)).

5) Complexity:
   - Kasai: O(n) time, O(n) space.
---------------------------------------------------------------------------------------------------
*/

