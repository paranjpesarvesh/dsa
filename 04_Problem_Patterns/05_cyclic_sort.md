# Cyclic Sort Problem Pattern

The **Cyclic Sort** is a **pattern used for solving problems involving arrays of numbers in a range**, typically from `1` to `n` or `0` to `n-1`. It is **especially useful for finding missing, duplicate, or misplaced numbers** in linear time without extra space.

---

## 1. Definition

**Cyclic Sort** rearranges the elements in an array so that **each number is at its correct index**.

- For an array containing numbers `1..n`, the correct index for number `num` is `num-1`.
- For `0..n-1`, the correct index is `num`.

**Key idea:** Swap numbers **in place** until every element is at its correct position.

---

## 2. When to Use

- **Arrays containing consecutive integers** (possibly with duplicates or missing numbers).
- **Problems asking for missing, duplicate, or misplaced numbers**.
- **Constraint:** O(n) time and O(1) extra space.

**Common scenarios:**

- Find the missing number(s)
- Find the duplicate number(s)
- Sort numbers in a given range
- Detect multiple anomalies in arrays

---

## 3. Template Approach

### Step-by-step reasoning

1. Start from index `i = 0`.
2. While `i < len(arr)`:
   - Find the **correct index** for `arr[i]`.
   - If `arr[i]` is **not at the correct index**, swap it with the element at its correct position.
   - Else, move to the next index (`i++`).
3. After the array is sorted:
   - Traverse the array to find **mismatches** or **missing/duplicate numbers**.

---

### 3.1 Pseudocode

```

function cyclicSort(arr):
i = 0
while i < length(arr):
correctIndex = arr\[i] - 1   # for 1..n array
if arr\[i] != arr\[correctIndex]:
swap(arr\[i], arr\[correctIndex])
else:
i += 1
return arr

```

**After sorting:**

- `arr[i] != i+1` → mismatch at index `i`
- Can be used to find duplicates or missing numbers

---

### 3.2 Python Implementation

```python
def cyclic_sort(arr):
    """
    Sort an array containing numbers from 1 to n using Cyclic Sort.

    Args:
        arr: List[int] - input array

    Returns:
        List[int] - sorted array
    """
    i = 0
    while i < len(arr):
        correct_index = arr[i] - 1
        if arr[i] != arr[correct_index]:
            arr[i], arr[correct_index] = arr[correct_index], arr[i]  # Swap
        else:
            i += 1
    return arr

# Example usage
arr = [3, 1, 5, 4, 2]
sorted_arr = cyclic_sort(arr)
print(sorted_arr)  # Output: [1,2,3,4,5]
```

---

## 4. Complexity Analysis

| Operation   | Time Complexity | Space Complexity |
| ----------- | --------------- | ---------------- |
| Cyclic Sort | O(n)            | O(1)             |

**Explanation:**

* Each element is swapped at most **once**.
* No extra data structures needed.
* Linear scan after sorting takes O(n).

---

## 5. Variations & Edge Cases

* **Missing number in 1..n:** After sorting, `arr[i] != i+1` → missing number is `i+1`.
* **Duplicate number:** `arr[i] != i+1` → duplicate is `arr[i]`.
* **Zero-based arrays (0..n-1):** Adjust `correct_index = arr[i]`.
* **Multiple duplicates/missing:** Requires additional handling, but pattern remains.
* **Invalid numbers:** Ensure numbers are within the expected range.

---

## 6. Visual Aid

```text
Input: [3, 1, 5, 4, 2]

Step 1: i=0, arr[0]=3, correct_index=2 → swap(0,2)
      [5,1,3,4,2]
Step 2: i=0, arr[0]=5, correct_index=4 → swap(0,4)
      [2,1,3,4,5]
Step 3: i=0, arr[0]=2, correct_index=1 → swap(0,1)
      [1,2,3,4,5]
Step 4: i=0, arr[0]=1, correct_index=0 → i++
Step 5: i=1, arr[1]=2, correct_index=1 → i++
...
Output: [1,2,3,4,5]
```

---

## 7. Interview Tips

* **Always check if elements are within range.**
* Clarify **1-based or 0-based indexing**.
* Remember: **constant space and linear time** is the key advantage.
* Excellent for **missing/duplicate number problems** on arrays.
* Often combined with **mathematical sum/formula checks** for verification.

---

## 8. Practice Problems

| Problem                    | Source                                                                   | Type                      |
| -------------------------- | ------------------------------------------------------------------------ | ------------------------- |
| Cyclic Sort Implementation | [LeetCode 75](https://leetcode.com/problems/sort-colors/)                | Sorting in-place          |
| Find the Duplicate Number  | [LeetCode 287](https://leetcode.com/problems/find-the-duplicate-number/) | Duplicate detection       |
| Missing Number             | [LeetCode 268](https://leetcode.com/problems/missing-number/)            | Find missing              |
| First Missing Positive     | [LeetCode 41](https://leetcode.com/problems/first-missing-positive/)     | Variations of cyclic sort |
| Set Mismatch               | [LeetCode 645](https://leetcode.com/problems/set-mismatch/)              | Find missing & duplicate  |

---

## 9. Key Takeaways

* **Cyclic Sort is a linear-time, in-place sorting technique** for arrays with numbers in a range.
* **Core principle:** swap numbers to their correct indices.
* **Foundation for many array-based interview problems** like missing, duplicate, and misplaced numbers.
* **Efficient**: O(n) time, O(1) space.

---

## References

* [LeetCode Patterns - Cyclic Sort](https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/)
* [GeeksforGeeks - Cyclic Sort](https://www.geeksforgeeks.org/cyclic-sort/)
* [Educative - Cyclic Sort Pattern](https://www.educative.io/courses/grokking-the-coding-interview/qV0r5Z3M0RN)

