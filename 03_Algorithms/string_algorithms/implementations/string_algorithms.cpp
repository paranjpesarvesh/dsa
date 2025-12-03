#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Naive String Matching - O(mn)
 * Checks pattern at each position in text
 */
vector<int> naiveSearch(string text, string pattern) {
    vector<int> positions;
    int n = text.length(), m = pattern.length();
    
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        if (j == m) {
            positions.push_back(i);
        }
    }
    
    return positions;
}

/**
 * KMP Algorithm - O(n + m)
 * Efficient pattern matching using prefix function
 */
vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    
    int len = 0, i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
            }
            i++;
        }
    }
    
    return lps;
}

vector<int> kmpSearch(string text, string pattern) {
    vector<int> positions;
    int n = text.length(), m = pattern.length();
    
    vector<int> lps = computeLPS(pattern);
    
    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            positions.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return positions;
}

/**
 * Rabin-Karp Algorithm - O(n + m) average
 * Uses rolling hash for pattern matching
 */
vector<int> rabinKarpSearch(string text, string pattern) {
    vector<int> positions;
    int n = text.length(), m = pattern.length();
    const int d = 256; // Number of characters in alphabet
    const int q = 101; // A prime number
    
    int h = 1; // Hash for pattern
    for (int i = 0; i < m; i++) {
        h = (d * h + pattern[i]) % q;
    }
    
    int t = 1; // Hash for current window in text
    for (int i = 0; i < m; i++) {
        t = (d * t + text[i]) % q;
    }
    
    for (int i = 0; i <= n - m; i++) {
        if (h == t) {
            // Check characters one by one
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == m) {
                positions.push_back(i);
            }
        }
        
        // Calculate hash for next window
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }
    
    return positions;
}

// Test function
void testStringAlgorithms() {
    string text = "ABABDABACDABABCABABAC";
    string pattern = "ABABCABAB";
    
    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl << endl;
    
    cout << "=== Naive Search ===" << endl;
    vector<int> naive = naiveSearch(text, pattern);
    cout << "Pattern found at positions: ";
    for (int pos : naive) {
        cout << pos << " ";
    }
    cout << endl;
    
    cout << "\n=== KMP Algorithm ===" << endl;
    vector<int> kmp = kmpSearch(text, pattern);
    cout << "Pattern found at positions: ";
    for (int pos : kmp) {
        cout << pos << " ";
    }
    cout << endl;
    
    cout << "\n=== Rabin-Karp Algorithm ===" << endl;
    vector<int> rk = rabinKarpSearch(text, pattern);
    cout << "Pattern found at positions: ";
    for (int pos : rk) {
        cout << pos << " ";
    }
    cout << endl;
}

int main() {
    testStringAlgorithms();
    return 0;
}