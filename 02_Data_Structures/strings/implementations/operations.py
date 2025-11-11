# String Operations Implementation (Python)
# This module includes common string operations frequently used in DSA problems.
#
# Implemented operations:
# 1. reverse_string
# 2. is_palindrome
# 3. count_frequencies
# 4. find_substring (naive)
# 5. to_lowercase
# 6. trim_whitespace
#
# Time complexities are noted for each operation.


# --------------------------------------------
# 1. Reverse a string
# Time Complexity: O(n)
# Space Complexity: O(n) (strings immutable in Python)
# --------------------------------------------
def reverse_string(s: str) -> str:
    return s[::-1]


# --------------------------------------------
# 2. Check if a string is palindrome
# Time Complexity: O(n)
# --------------------------------------------
def is_palindrome(s: str) -> bool:
    return s == s[::-1]


# --------------------------------------------
# 3. Count character frequencies (using dict)
# Time Complexity: O(n)
# --------------------------------------------
def count_frequencies(s: str) -> dict:
    freq = {}
    for c in s:
        freq[c] = freq.get(c, 0) + 1
    return freq


# --------------------------------------------
# 4. Naive substring search
# Returns index of first occurrence or -1
# Time Complexity: O(n*m)
# --------------------------------------------
def find_substring(text: str, pattern: str) -> int:
    n, m = len(text), len(pattern)
    if m == 0:
        return 0

    for i in range(n - m + 1):
        if text[i:i+m] == pattern:
            return i
    return -1


# --------------------------------------------
# 5. Convert string to lowercase
# Time Complexity: O(n)
# --------------------------------------------
def to_lowercase(s: str) -> str:
    return s.lower()


# --------------------------------------------
# 6. Trim whitespace from both ends
# Time Complexity: O(n)
# --------------------------------------------
def trim_whitespace(s: str) -> str:
    return s.strip()


# --------------------------------------------
# BONUS: Check if two strings are anagrams
# Time Complexity: O(n)
# --------------------------------------------
def are_anagrams(a: str, b: str) -> bool:
    return sorted(a) == sorted(b)

