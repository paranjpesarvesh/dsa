#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * N-Queens Problem - Backtracking
 * Place N queens on N×N chessboard without attacking each other
 */
bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check this column on left side
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) return false;
    }
    
    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }
    
    // Check lower diagonal on left side
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }
    
    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int n) {
    if (col >= n) {
        // Print solution
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (board[i][j] ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    
    // Try placing queen in all rows
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            if (solveNQueensUtil(board, col + 1, n)) {
                return true;
            }
            board[i][col] = 0; // Backtrack
        }
    }
    
    return false;
}

void solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    
    if (!solveNQueensUtil(board, 0, n)) {
        cout << "No solution exists" << endl;
    }
}

/**
 * Subsets Problem - Backtracking
 * Generate all subsets of a given set
 */
void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result) {
    if (index == nums.size()) {
        result.push_back(current);
        return;
    }
    
    // Include current element
    current.push_back(nums[index]);
    generateSubsets(nums, index + 1, current, result);
    current.pop_back();
    
    // Exclude current element
    generateSubsets(nums, index + 1, current, result);
}

vector<vector<int>> getAllSubsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    
    generateSubsets(nums, 0, current, result);
    return result;
}

/**
 * Permutations Problem - Backtracking
 * Generate all permutations of a given set
 */
void generatePermutations(vector<int>& nums, vector<bool>& used, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            current.push_back(nums[i]);
            generatePermutations(nums, used, current, result);
            current.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> getAllPermutations(vector<int>& nums) {
    vector<vector<int>> result;
    vector<bool> used(nums.size(), false);
    vector<int> current;
    
    generatePermutations(nums, used, current, result);
    return result;
}

// Test function
void testBacktrackingAlgorithms() {
    cout << "=== N-Queens Problem ===" << endl;
    solveNQueens(4);
    
    cout << "\n=== Subsets Problem ===" << endl;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> subsets = getAllSubsets(nums);
    
    for (const auto& subset : subsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    
    cout << "\n=== Permutations Problem ===" << endl;
    vector<vector<int>> permutations = getAllPermutations(nums);
    
    for (const auto& perm : permutations) {
        cout << "{ ";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
}

int main() {
    testBacktrackingAlgorithms();
    return 0;
}