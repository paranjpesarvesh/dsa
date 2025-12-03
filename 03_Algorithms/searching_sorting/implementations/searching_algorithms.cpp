#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Linear Search - O(n)
 * Searches for target by checking each element sequentially
 */
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

/**
 * Binary Search - O(log n)
 * Requires sorted array
 * Uses divide and conquer approach
 */
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Prevent overflow
        
        if (arr[mid] == target) {
            return mid;  // Found target
        } else if (arr[mid] < target) {
            left = mid + 1;  // Search right half
        } else {
            right = mid - 1;  // Search left half
        }
    }
    
    return -1;  // Target not found
}

/**
 * Ternary Search - O(log3 n)
 * Requires sorted array
 * Divides array into three parts
 */
int ternarySearch(const vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1;
    }
    
    // Calculate two mid points
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;
    
    if (arr[mid1] == target) {
        return mid1;
    }
    if (arr[mid2] == target) {
        return mid2;
    }
    
    // Recursively search in the appropriate third
    if (target < arr[mid1]) {
        return ternarySearch(arr, target, left, mid1 - 1);
    } else if (target > arr[mid2]) {
        return ternarySearch(arr, target, mid2 + 1, right);
    } else {
        return ternarySearch(arr, target, mid1 + 1, mid2 - 1);
    }
}

/**
 * Jump Search - O(√n)
 * Jumps by block size to find target range
 */
int jumpSearch(const vector<int>& arr, int target) {
    int n = arr.size();
    if (n == 0) return -1;
    
    int step = sqrt(n);  // Optimal block size
    int prev = 0;
    
    // Find block where target might be present
    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }
    
    // Linear search in found block
    while (arr[prev] < target) {
        prev++;
        if (prev == min(step, n)) return -1;
    }
    
    return (arr[prev] == target) ? prev : -1;
}

/**
 * Exponential Search - O(log n)
 * Useful for unbounded or infinite arrays
 */
int exponentialSearch(const vector<int>& arr, int target) {
    if (arr.empty()) return -1;
    
    // Find range where target might be present
    if (arr[0] == target) return 0;
    
    int i = 1;
    while (i < arr.size() && arr[i] <= target) {
        i *= 2;
    }
    
    // Perform binary search in found range
    return binarySearch(vector<int>(arr.begin(), arr.begin() + min(i, (int)arr.size())), target);
}

// Utility function to print array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Test function
void testSearchAlgorithms() {
    vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;
    
    cout << "Array: ";
    printArray(arr);
    cout << "Target: " << target << endl << endl;
    
    cout << "Linear Search: " << linearSearch(arr, target) << endl;
    cout << "Binary Search: " << binarySearch(arr, target) << endl;
    cout << "Ternary Search: " << ternarySearch(arr, target, 0, arr.size() - 1) << endl;
    cout << "Jump Search: " << jumpSearch(arr, target) << endl;
    cout << "Exponential Search: " << exponentialSearch(arr, target) << endl;
}

int main() {
    testSearchAlgorithms();
    return 0;
}