// -------------------------------------------------------------------------------------------------
// Suffix Array (C++) — O(n log n) Doubling + Counting Sort, with Kasai's LCP and Pattern Search
//
// Problem / Goal
//   Build the suffix array SA of a string s (0-indexed): SA[i] is the starting index of the i-th
//   lexicographically smallest suffix. Also build the LCP array: LCP[i] = LCP(SA[i], SA[i-1]).
//   Provide a binary-search based substring finder using SA.
//
// Approach
//   - Doubling algorithm (ranks on length 2^k) with two-key radix/counting sort
//   - Initial ranks from characters (0..255) — works for general 8-bit text
//   - Kasai’s algorithm for LCP in O(n)
//   - Pattern search using two binary searches on SA in O(|P| log n)
//
// Complexity
//   - Build SA: O(n log n) time, O(n) extra space
//   - Build LCP (Kasai): O(n) time, O(n) space
//   - Substring search: O(|P| log n)
//   - Memory: O(n)
//
// Notes
//   - Works on arbitrary std::string (may contain '\0' as a character; no sentinel is required).
//   - Stable counting sort keeps overall complexity tight.
//   - For very large alphabets, compress characters first or widen initial K.
//
// Variations
//   - SA-IS (O(n)) for linear-time construction
//   - Sparse table on LCP for RMQ and LCP queries between any two suffixes in O(1)
//   - Suffix Automaton / Suffix Tree for different query profiles
// -------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

// Build suffix array in O(n log n) using doubling + counting sort
// sa[i] = starting index of i-th lexicographically smallest suffix
static vector<int> build_sa(const string& s) {
    int n = (int)s.size();
    vector<int> sa(n), rnk(n), tmp(n);

    // initial ranking by character (0..255)
    for (int i = 0; i < n; ++i) {
        sa[i] = i;
        rnk[i] = (unsigned char)s[i]; // use unsigned char to avoid negatives
    }

    // Counting sort helper for key in [0..K)
    auto counting_sort = [&](const vector<int>& in, auto key, int K) {
        vector<int> cnt(K + 1, 0), out(n);
        for (int i = 0; i < n; ++i) cnt[key(in[i])]++;
        for (int i = 1; i <= K; ++i) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i) out[--cnt[key(in[i])]] = in[i];
        return out;
    };

    // k = length of first half of key; we compare pairs (rnk[i], rnk[i+k])
    for (int k = 1; k < n; k <<= 1) {
        // Key ranges:
        //   primary key rnk[i] + 1 in [1..max(n,256)]
        //   secondary key rnk[i+k] + 1 in [0..max(n,256)] with 0 meaning "none" (out of range)
        int Kval = max(256, n) + 1;

        // First sort by secondary key
        auto key2 = [&](int i) {
            return (i + k < n ? rnk[i + k] + 1 : 0);
        };
        vector<int> sa2 = counting_sort(sa, key2, Kval);

        // Then stable sort by primary key
        auto key1 = [&](int i) {
            return rnk[i] + 1;
        };
        sa = counting_sort(sa2, key1, Kval);

        // Re-rank
        tmp[sa[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; ++i) {
            int a = sa[i], b = sa[i - 1];
            bool same = (rnk[a] == rnk[b]) &&
                        ((a + k < n ? rnk[a + k] : -1) == (b + k < n ? rnk[b + k] : -1));
            tmp[a] = same ? classes - 1 : classes++;
        }
        rnk.swap(tmp);
        if (classes == n) break; // all ranks unique
    }

    return sa;
}

// Kasai's algorithm for LCP in O(n):
// lcp[i] = LCP( suffix at sa[i], suffix at sa[i-1] ), lcp[0] = 0
static vector<int> build_lcp(const string& s, const vector<int>& sa) {
    int n = (int)s.size();
    vector<int> rank(n, 0), lcp(n, 0);
    for (int i = 0; i < n; ++i) rank[sa[i]] = i;

    int h = 0;
    for (int i = 0; i < n; ++i) {
        int r = rank[i];
        if (r == 0) { // first suffix has no previous
            h = 0;
            continue;
        }
        int j = sa[r - 1];
        // compare s[i+h] and s[j+h]
        while (i + h < n && j + h < n && s[i + h] == s[j + h]) ++h;
        lcp[r] = h;
        if (h > 0) --h; // suffix trick
    }
    return lcp;
}

// Compare pattern P with suffix s[sa[mid]..] up to P.size()
// Returns negative if suffix < P, 0 if prefix-equal and P exhausted, positive otherwise
static int cmp_suffix_pattern(const string& s, const vector<int>& sa, int mid, const string& p) {
    int i = sa[mid], n = (int)s.size(), m = (int)p.size();
    for (int k = 0; k < m && i + k < n; ++k) {
        unsigned char a = (unsigned char)s[i + k];
        unsigned char b = (unsigned char)p[k];
        if (a < b) return -1;
        if (a > b) return 1;
    }
    // If all matched up to min(m, n - i), then
    if ((int)p.size() <= n - i) return 0; // pattern fully matched (pattern <= suffix)
    return 1; // pattern longer than suffix => suffix < pattern
}

// Find range [L, R) of suffixes that start with pattern p using two binary searches.
// Returns pair(L, R); if L == R the pattern doesn't occur.
static pair<int,int> sa_find_range(const string& s, const vector<int>& sa, const string& p) {
    int n = (int)sa.size();

    // lower_bound for p
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        int c = cmp_suffix_pattern(s, sa, mid, p);
        if (c >= 0) hi = mid; else lo = mid + 1;
    }
    int L = lo;

    // upper_bound for p (using p' that is just greater than p in lexicographic order trick)
    lo = 0; hi = n;
    // We can search using comparison with p, but pivot on c > 0 (strictly greater)
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        int c = cmp_suffix_pattern(s, sa, mid, p);
        if (c > 0) hi = mid; else lo = mid + 1;
    }
    int R = lo;

    return {L, R};
}

// Convenience: find all starting indices where pattern p occurs in s (in SA order)
static vector<int> sa_find_all(const string& s, const vector<int>& sa, const string& p) {
    auto [L, R] = sa_find_range(s, sa, p);
    vector<int> out;
    for (int i = L; i < R; ++i) out.push_back(sa[i]);
    sort(out.begin(), out.end()); // return in increasing index order (optional)
    return out;
}

// -------------------------------------------------------------------------------------------------
// Example usage / simple self-test
// Input (optional):
//   None (uses internal examples). You can adapt to read from stdin if desired.
// -------------------------------------------------------------------------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example 1
    string s = "banana";
    auto sa = build_sa(s);
    auto lcp = build_lcp(s, sa);

    cout << "String: " << s << "\n";
    cout << "SA: ";
    for (int i = 0; i < (int)sa.size(); ++i) cout << sa[i] << (i + 1 == (int)sa.size() ? '\n' : ' ');
    cout << "Suffixes in SA order:\n";
    for (int idx : sa) cout << idx << ": " << s.substr(idx) << "\n";
    cout << "LCP: ";
    for (int i = 0; i < (int)lcp.size(); ++i) cout << lcp[i] << (i + 1 == (int)lcp.size() ? '\n' : ' ');

    // Pattern queries
    vector<string> queries = {"ana", "na", "nana", "x"};
    for (auto& p : queries) {
        auto occ = sa_find_all(s, sa, p);
        cout << "Occurrences of \"" << p << "\": ";
        if (occ.empty()) cout << "none\n";
        else {
            for (int i = 0; i < (int)occ.size(); ++i)
                cout << occ[i] << (i + 1 == (int)occ.size() ? '\n' : ' ');
        }
    }

    return 0;
}

/*
---------------------------------------------------------------------------------------------------
Implementation Notes (Read-Me-In-File)

1) Doubling with counting sort:
   We sort suffix indices by pairs (rnk[i], rnk[i+k]) using two stable counting sorts:
   first by secondary key (rnk[i+k]), then by primary (rnk[i]).
   Out-of-range secondary ranks map to 0; valid ranks are offset by +1 to be >= 1.
   This keeps key domain small: K = max(256, n) + 1.

2) Kasai’s LCP:
   Uses the inverse of SA (rank) to compute LCP in O(n), reusing the previous LCP minus one.

3) Pattern search:
   Two binary searches determine the lexicographic range of suffixes having prefix P.
   Extract corresponding SA indices as match positions.

4) Complexity:
   - SA: O(n log n)
   - LCP: O(n)
   - Search: O(|P| log n)
   - Space: O(n)

5) Variations:
   - For Unicode or larger alphabets, compress the alphabet first, or increase initial K.
   - For RMQ on LCP, build a sparse table for O(1) LCP queries between arbitrary suffixes.

---------------------------------------------------------------------------------------------------
*/

