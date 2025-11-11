# /02_Data_Structures/advanced_structures/suffix_array/implementation.py
# ----------------------------------------------------------------------------------------------------
# Suffix Array + LCP Array + Pattern Search (Python)
#
# Problem / Purpose:
#   Implement:
#     - Suffix Array (SA) in O(n log n)
#     - LCP Array (Kasai algorithm) in O(n)
#     - Pattern search using binary search on SA
#
# Approach:
#   - Doubling method: ranks based on substrings of length 2^k
#   - For speed, sorting uses Python's Timsort (O(n log n))
#   - LCP computed using Kasai’s algorithm
#   - Pattern search via two binary searches (lower/upper bound)
#
# Time Complexity:
#   Build SA: O(n log n)
#   Build LCP: O(n)
#   Search pattern: O(m log n)
#
# Space Complexity: O(n)
#
# Usage:
#   s = "banana"
#   sa = build_sa(s)
#   lcp = build_lcp(s, sa)
#   positions = find_all(s, sa, "ana")
#
# Variations:
#   - SA-IS for O(n)
#   - RMQ on LCP for fast LCP queries
# ----------------------------------------------------------------------------------------------------


def build_sa(s):
    """
    Build suffix array using the doubling algorithm.

    Returns:
        sa: list[int] positions of sorted suffixes
    """
    n = len(s)
    sa = list(range(n))
    rnk = [ord(c) for c in s]  # initial rank by character
    tmp = [0] * n
    k = 1

    while k < n:
        # sort by (rank[i], rank[i+k]), using Python's sort (Timsort)
        sa.sort(key=lambda i: (rnk[i], rnk[i + k] if i + k < n else -1))

        # generate new ranks
        tmp[sa[0]] = 0
        classes = 1
        for i in range(1, n):
            prev, cur = sa[i - 1], sa[i]
            if rnk[prev] != rnk[cur] or \
               (prev + k < n and cur + k < n and rnk[prev + k] != rnk[cur + k]):
                classes += 1
            tmp[cur] = classes - 1

        rnk = tmp[:]
        if classes == n:
            break
        k <<= 1

    return sa


def build_lcp(s, sa):
    """
    Kasai's LCP algorithm
    LCP[i] = LCP(s[sa[i]], s[sa[i-1]])
    """
    n = len(s)
    rank = [0] * n
    for i, p in enumerate(sa):
        rank[p] = i

    h = 0
    lcp = [0] * n
    for i in range(n):
        r = rank[i]
        if r == 0:
            h = 0
            continue
        j = sa[r - 1]
        while i + h < n and j + h < n and s[i + h] == s[j + h]:
            h += 1
        lcp[r] = h
        if h > 0:
            h -= 1

    return lcp


def cmp_suffix_pattern(s, sa, mid, p):
    """
    Compare pattern p with suffix s[sa[mid]:]
    Returns:
        -1 if suffix < pattern
         0 if suffix starts with pattern
         1 if suffix > pattern
    """
    i = sa[mid]
    n, m = len(s), len(p)
    k = 0
    while k < m and i + k < n:
        if s[i + k] < p[k]:
            return -1
        if s[i + k] > p[k]:
            return 1
        k += 1

    if k == m:
        return 0  # prefix matched
    return -1  # suffix is shorter => suffix < pattern


def find_range(s, sa, p):
    """
    Find lexicographic range [L, R) of suffixes starting with p
    using binary search.
    """
    n = len(sa)

    # lower bound search for p
    lo, hi = 0, n
    while lo < hi:
        mid = (lo + hi) // 2
        if cmp_suffix_pattern(s, sa, mid, p) >= 0:
            hi = mid
        else:
            lo = mid + 1
    L = lo

    # upper bound search for p
    lo, hi = 0, n
    while lo < hi:
        mid = (lo + hi) // 2
        if cmp_suffix_pattern(s, sa, mid, p) > 0:
            hi = mid
        else:
            lo = mid + 1
    R = lo

    return L, R


def find_all(s, sa, p):
    """
    Return all positions in s where p occurs,
    as sorted list of indices.
    """
    L, R = find_range(s, sa, p)
    return sorted(sa[L:R])


# ----------------------------------------------------------------------------------------------------
# Example Usage
# ----------------------------------------------------------------------------------------------------

if __name__ == "__main__":
    s = "banana"
    sa = build_sa(s)
    lcp = build_lcp(s, sa)

    print("String:", s)
    print("Suffix Array:", sa)
    print("LCP:", lcp)

    queries = ["ana", "na", "ban", "x"]
    for q in queries:
        res = find_all(s, sa, q)
        print(f"Pattern '{q}' occurs at:", res)

