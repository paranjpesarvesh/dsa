def fibonacci_memo(n, memo={}):
    """
    Fibonacci - DP (Memoization) - O(n) time, O(n) space
    Calculates nth Fibonacci number using memoization
    """
    if n <= 1:
        return n
    if n in memo:
        return memo[n]
    
    memo[n] = fibonacci_memo(n - 1, memo) + fibonacci_memo(n - 2, memo)
    return memo[n]


def fibonacci_tab(n):
    """
    Fibonacci - DP (Tabulation) - O(n) time, O(1) space
    Calculates nth Fibonacci number using bottom-up approach
    """
    if n <= 1:
        return n
    
    prev2, prev1 = 0, 1
    
    for i in range(2, n + 1):
        current = prev1 + prev2
        prev2 = prev1
        prev1 = current
    
    return current


def knapsack_01(weights, values, W):
    """
    0/1 Knapsack - DP - O(nW) time, O(nW) space
    Maximizes value in knapsack with weight constraint
    """
    n = len(weights)
    dp = [[0] * (W + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for w in range(W + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], 
                                   values[i - 1] + dp[i - 1][w - weights[i - 1]])
            else:
                dp[i][w] = dp[i - 1][w]
    
    return dp[n][W]


def lcs(s1, s2):
    """
    Longest Common Subsequence - DP - O(mn) time, O(mn) space
    Finds LCS between two strings
    """
    m, n = len(s1), len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    
    return dp[m][n]


def edit_distance(word1, word2):
    """
    Edit Distance - DP - O(mn) time, O(mn) space
    Minimum operations to convert one string to another
    """
    m, n = len(word1), len(word2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    for i in range(m + 1):
        for j in range(n + 1):
            if i == 0:
                dp[i][j] = j
            elif j == 0:
                dp[i][j] = i
            elif word1[i - 1] == word2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])
    
    return dp[m][n]


def test_dp_algorithms():
    """Test all DP algorithms"""
    print("=== Fibonacci ===")
    print(f"Fibonacci(10) Memo: {fibonacci_memo(10)}")
    print(f"Fibonacci(10) Tab: {fibonacci_tab(10)}")
    
    print("\n=== 0/1 Knapsack ===")
    weights = [10, 20, 30]
    values = [60, 100, 120]
    W = 50
    print(f"Max value: {knapsack_01(weights, values, W)}")
    
    print("\n=== LCS ===")
    s1, s2 = "AGGTAB", "GXTXAYB"
    print(f"LCS length: {lcs(s1, s2)}")
    
    print("\n=== Edit Distance ===")
    word1, word2 = "horse", "ros"
    print(f"Edit distance: {edit_distance(word1, word2)}")


if __name__ == "__main__":
    test_dp_algorithms()