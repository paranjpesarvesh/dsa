// String Operations Implementation (C++)
// This file includes commonly used string operations helpful for DSA practice.
//
// Operations implemented:
// 1. reverseString
// 2. isPalindrome
// 3. countFrequencies
// 4. findSubstring (Naive Search)
// 5. toLowerCase
//
// Each function is optimized for clarity and correctness.
//
// Time complexities are provided for each method.
// Variations and edge-case handling are included.

// --------------------------------------------
// 1. Reverse a string in-place
// Time Complexity: O(n)
// Space Complexity: O(1)
// --------------------------------------------
void reverseString(std::string &s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        std::swap(s[i], s[j]);
        i++;
        j--;
    }
}

// --------------------------------------------
// 2. Check if a string is palindrome
// Time Complexity: O(n)
// Space Complexity: O(1)
// --------------------------------------------
bool isPalindrome(const std::string &s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// --------------------------------------------
// 3. Count frequency of characters
// Assumes ASCII characters
// Time Complexity: O(n)
// Space Complexity: O(1) (constant-sized freq array)
// --------------------------------------------
std::vector<int> countFrequencies(const std::string &s) {
    std::vector<int> freq(256, 0);
    for (char c : s) {
        freq[(unsigned char)c]++;
    }
    return freq;
}

// --------------------------------------------
// 4. Find substring index using naive matching
// Returns index of first occurrence or -1
// Time Complexity: O(n*m)
// --------------------------------------------
int findSubstring(const std::string &text, const std::string &pattern) {
    int n = text.size();
    int m = pattern.size();

    if (m == 0) return 0;

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) j++;
        if (j == m) return i;
    }
    return -1;
}

// --------------------------------------------
// 5. Convert string to lowercase (in-place)
// Time Complexity: O(n)
// --------------------------------------------
void toLowerCase(std::string &s) {
    for (char &c : s) {
        if (c >= 'A' && c <= 'Z')
            c = c + ('a' - 'A');
    }
}

// --------------------------------------------
// BONUS: Remove whitespace from both ends (trim)
// Time Complexity: O(n)
// --------------------------------------------
std::string trim(const std::string &s) {
    int left = 0;
    while (left < s.size() && std::isspace(s[left])) left++;

    int right = s.size() - 1;
    while (right >= 0 && std::isspace(s[right])) right--;

    if (left > right) return ""; // all spaces

    return s.substr(left, right - left + 1);
}

