# 📊 Worked Example 01 – Sum of Array Elements

This example demonstrates how to analyze the **time and space complexity** of a simple array summation problem.

---

## 🔹 Problem Statement

Given an array of integers, compute the **sum of all elements**.

Example:

```
Input: [2, 4, 6, 8]
Output: 20
```

---

## 🔹 Step-by-Step Reasoning

1. We need to **visit each element** of the array exactly once.
2. At each step, we add the current element to a running sum.
3. After `n` iterations, we obtain the total sum.

---

## 🔹 Pseudocode

```text
function sumArray(arr, n):
    total = 0
    for i = 0 to n-1:
        total = total + arr[i]
    return total
```

---

## 🔹 Implementation Templates

### C++

```cpp
// Problem: Sum of Array Elements
// Approach: Simple Iteration
// Complexity: O(n) time, O(1) space

#include <iostream>
#include <vector>
using namespace std;

int sumArray(const vector<int>& arr) {
    int total = 0;
    for (int num : arr) {
        total += num; // add each element
    }
    return total;
}

int main() {
    vector<int> arr = {2, 4, 6, 8};
    cout << "Sum = " << sumArray(arr) << endl;
    return 0;
}
```

### Python

```python
# Problem: Sum of Array Elements
# Approach: Simple Iteration
# Complexity: O(n) time, O(1) space

def sum_array(arr):
    total = 0
    for num in arr:
        total += num
    return total

arr = [2, 4, 6, 8]
print("Sum =", sum_array(arr))
```

---

## 🔹 Complexity Analysis

| Operation                 | Cost                                           |
| ------------------------- | ---------------------------------------------- |
| Initialization of `total` | O(1)                                           |
| Loop over `n` elements    | O(n)                                           |
| Addition inside loop      | O(1) each                                      |
| **Total Time Complexity** | **O(n)**                                       |
| **Space Complexity**      | **O(1)** (no extra memory, aside from `total`) |

---

## 🔹 Variations

1. **Recursive Summation**

   ```python
   def recursive_sum(arr, n):
       if n == 0:
           return 0
       return recursive_sum(arr, n-1) + arr[n-1]
   ```

   * Complexity: O(n) time, O(n) space (due to recursion stack).

2. **Divide & Conquer** (useful for parallel computing)

   ```python
   def divide_and_conquer_sum(arr, l, r):
       if l == r:
           return arr[l]
       mid = (l + r) // 2
       return divide_and_conquer_sum(arr, l, mid) + divide_and_conquer_sum(arr, mid+1, r)
   ```

   * Complexity: O(n) time, O(log n) space (recursion depth).

---

## 🔹 Visual Aid

Example Array: `[2, 4, 6, 8]`

```
Step 1: total = 0
Step 2: total = 0 + 2 = 2
Step 3: total = 2 + 4 = 6
Step 4: total = 6 + 6 = 12
Step 5: total = 12 + 8 = 20
```

---

## 🔹 Interview Tips

* Be prepared to discuss **iterative vs recursive approaches**.
* Mention **tradeoffs**:

  * Iterative: O(1) space → preferred in practice.
  * Recursive: Elegant but risks stack overflow for large arrays.
* FAANG twist: Sometimes asked in **parallel computing** or **map-reduce context**.

---

## 🔹 Practice Problems

* [LeetCode 1480 – Running Sum of 1D Array](https://leetcode.com/problems/running-sum-of-1d-array/)
* [GFG – Sum of Array Elements](https://www.geeksforgeeks.org/sum-of-elements-in-an-array/)
* [Codeforces Problemset – Basic loops and sums](https://codeforces.com/problemset)

---

✅ This worked example shows how even a **basic problem** can be used to **teach complexity analysis, recursion, and variations**.

---
