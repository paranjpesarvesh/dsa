#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Fibonacci - DP (Memoization) - O(n) time, O(n) space
 * Calculates nth Fibonacci number using memoization
 */
long long fibonacciMemo(int n, vector<long long>& memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    
    memo[n] = fibonacciMemo(n - 1, memo) + fibonacciMemo(n - 2, memo);
    return memo[n];
}

/**
 * Fibonacci - DP (Tabulation) - O(n) time, O(1) space
 * Calculates nth Fibonacci number using bottom-up approach
 */
long long fibonacciTab(int n) {
    if (n <= 1) return n;
    
    long long prev2 = 0, prev1 = 1, current;
    
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    
    return current;
}

/**
 * 0/1 Knapsack - DP - O(nW) time, O(nW) space
 * Maximizes value in knapsack with weight constraint
 */
int knapsack01(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], 
                                   values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][W];
}

/**
 * Longest Common Subsequence - DP - O(mn) time, O(mn) space
 * Finds LCS between two strings
 */
int lcs(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    return dp[m][n];
}

/**
 * Edit Distance - DP - O(mn) time, O(mn) space
 * Minimum operations to convert one string to another
 */
int editDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    
    return dp[m][n];
}

// Test function
void testDPAlgorithms() {
    cout << "=== Fibonacci ===" << endl;
    vector<long long> memo(100, -1);
    cout << "Fibonacci(10) Memo: " << fibonacciMemo(10, memo) << endl;
    cout << "Fibonacci(10) Tab: " << fibonacciTab(10) << endl;
    
    cout << "\n=== 0/1 Knapsack ===" << endl;
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int W = 50;
    cout << "Max value: " << knapsack01(weights, values, W) << endl;
    
    cout << "\n=== LCS ===" << endl;
    string s1 = "AGGTAB", s2 = "GXTXAYB";
    cout << "LCS length: " << lcs(s1, s2) << endl;
    
    cout << "\n=== Edit Distance ===" << endl;
    string word1 = "horse", word2 = "ros";
    cout << "Edit distance: " << editDistance(word1, word2) << endl;
}

int main() {
    testDPAlgorithms();
    return 0;
}