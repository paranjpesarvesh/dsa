#  Worked Example 03 – Merge Sort

This example demonstrates **Merge Sort**, a classic **divide-and-conquer sorting algorithm**, and analyzes its **time and space complexity** in detail.

---

##  Problem Statement

Given an array of integers, **sort it in ascending order** using Merge Sort.

Example:

```
Input: [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]
```

---

##  Step-by-Step Reasoning

1. **Divide:** Split the array into two halves.
2. **Conquer:** Recursively sort both halves.
3. **Combine:** Merge the two sorted halves into a single sorted array.

Merge Sort is **stable** (does not change relative order of equal elements) and **works well for large datasets**.

---

##  Pseudocode

```text
function mergeSort(arr):
    if length(arr) <= 1:
        return arr
    mid = length(arr) // 2
    left = mergeSort(arr[0:mid])
    right = mergeSort(arr[mid:])
    return merge(left, right)

function merge(left, right):
    result = []
    while left and right:
        if left[0] <= right[0]:
            append left[0] to result
            remove left[0]
        else:
            append right[0] to result
            remove right[0]
    append remaining elements from left and right to result
    return result
```

---

##  Implementation Templates

### C++

```cpp
// Problem: Sort an array using Merge Sort
// Complexity: O(n log n) time, O(n) space

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int t = 0; t < temp.size(); ++t)
        arr[left + t] = temp[t];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(arr, 0, arr.size() - 1);
    for (int num : arr) cout << num << " ";
    return 0;
}
```

### Python

```python
# Problem: Sort an array using Merge Sort
# Complexity: O(n log n) time, O(n) space

def merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result

def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr)//2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return merge(left, right)

arr = [38, 27, 43, 3, 9, 82, 10]
print("Sorted Array:", merge_sort(arr))
```

---

##  Complexity Analysis

| Aspect                    | Complexity                            |
| ------------------------- | ------------------------------------- |
| Time (best/worst/average) | O(n log n)                            |
| Space                     | O(n) auxiliary array                  |
| Stability                 | Stable                                |
| In-place                  | No (requires extra array for merging) |

* Recurrence Relation: `T(n) = 2T(n/2) + O(n)` → O(n log n)
* Merge operation is O(n) for each level, with log n levels in recursion tree.

---

##  Variations

1. **Bottom-up merge sort (iterative)**
2. **In-place merge sort** (complex, avoids extra memory)
3. **Merge sort for linked lists** (O(1) space)

---

##  Visual Aid

Array before sorting: `[38, 27, 43, 3, 9, 82, 10]`

```
Divide:
[38,27,43,3]        [9,82,10]
[38,27] [43,3]      [9,82] [10]
[38] [27] [43] [3]  [9] [82] [10]

Conquer (merge):
[27,38] [3,43]      [9,82] [10]
[3,27,38,43]         [9,10,82]

Final Merge:
[3,9,10,27,38,43,82]
```

---

##  Interview Tips

* FAANG interviewers often **expect O(n log n) sorting without using library functions**.
* Know **stability**, **in-place vs out-of-place**, and **divide-and-conquer principles**.
* Common follow-up: Sorting **linked lists** using merge sort.

---

##  Practice Problems

* [LeetCode 912 – Sort an Array](https://leetcode.com/problems/sort-an-array/)
* [GFG – Merge Sort](https://www.geeksforgeeks.org/merge-sort/)
* [Codeforces – Sorting challenges](https://codeforces.com/problemset)

---

 This worked example demonstrates **divide & conquer**, recursion, and **complexity analysis** using a standard sorting problem.

---
