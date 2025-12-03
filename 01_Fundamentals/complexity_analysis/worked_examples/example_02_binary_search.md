#  Worked Example 02 – Binary Search

This example demonstrates the **binary search algorithm**, a classic **divide & conquer technique**, and analyzes its **time and space complexity**.

---

##  Problem Statement

Given a **sorted array** of integers, find the **index of a target value**. If the target is not present, return -1.

Example:

```
Input: arr = [1, 3, 5, 7, 9], target = 5
Output: 2
```

---

##  Step-by-Step Reasoning

1. The array is sorted → we can eliminate half the elements each time.
2. Initialize two pointers: `low = 0`, `high = n-1`.
3. Compute `mid = low + (high - low)//2`.
4. Compare `arr[mid]` with the target:

   * If equal → return `mid`.
   * If `arr[mid] < target` → search right half (`low = mid + 1`).
   * If `arr[mid] > target` → search left half (`high = mid - 1`).
5. Repeat until `low > high` → target not found.

---

##  Pseudocode

```text
function binary_search(arr, target):
    low = 0
    high = length(arr) - 1
    while low <= high:
        mid = low + (high - low) / 2
        if arr[mid] == target:
            return mid
        else if arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1
```

---

##  Implementation Templates

### C++

```cpp
// Problem: Find target in a sorted array using Binary Search
// Complexity: O(log n) time, O(1) space

#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // prevents overflow
        if (arr[mid] == target)
            return mid; // target found
        else if (arr[mid] < target)
            low = mid + 1; // search right
        else
            high = mid - 1; // search left
    }
    return -1; // target not found
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int target = 5;
    cout << "Index: " << binarySearch(arr, target) << endl;
    return 0;
}
```

### Python

```python
# Problem: Find target in a sorted array using Binary Search
# Complexity: O(log n) time, O(1) space

def binary_search(arr, target):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return -1

arr = [1, 3, 5, 7, 9]
target = 5
print("Index:", binary_search(arr, target))
```

---

##  Complexity Analysis

| Operation                 | Cost             |
| ------------------------- | ---------------- |
| Each comparison           | O(1)             |
| Number of steps           | log₂(n)          |
| **Total Time Complexity** | **O(log n)**     |
| **Space Complexity**      | O(1) (iterative) |

* Recursive version: **O(log n) space** due to call stack.

---

##  Variations

1. **Find first or last occurrence** (for duplicates)
2. **Search in rotated sorted array**
3. **Binary search on answer** (for optimization problems)
4. **Ternary search** (for unimodal functions)

---

##  Visual Aid

Example Array: `[1, 3, 5, 7, 9]`, target = 5

```
Initial: low=0, high=4
mid = 2 → arr[2] = 5 → Found
```

Recursion Tree (if using recursive version):

```
binary_search(arr, 5)
├─ mid=2 → found → return 2
```

---

##  Interview Tips

* Always mention **sorted requirement**.
* Discuss **iterative vs recursive trade-offs**:

  * Iterative: O(1) space → preferred.
  * Recursive: O(log n) space due to call stack.
* FAANG twist: Sometimes combined with **lower\_bound / upper\_bound** or **rotated arrays**.

---

##  Practice Problems

* [LeetCode 704 – Binary Search](https://leetcode.com/problems/binary-search/)
* [LeetCode 34 – Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)
* [GFG – Binary Search](https://www.geeksforgeeks.org/binary-search/)
* [Codeforces Problemset](https://codeforces.com/problemset) – look for "binary search" tag

---

 This worked example shows **how a classic problem** demonstrates the **divide & conquer paradigm** and the importance of **complexity analysis**.

---
