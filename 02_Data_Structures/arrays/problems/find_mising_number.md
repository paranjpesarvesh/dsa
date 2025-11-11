# Find Missing Number

Location: `02_Data_Structures/arrays/problems/find_missing_number.md`

---

## Problem Description

You are given an array of size `n` containing numbers from `0` to `n`, with exactly **one number missing**.
Your task is to find the missing number.

---

## Key Observations

* The array should contain values from `0` to `n`.
* Exactly one value is missing.
* No duplicates.
* Order doesn’t matter.

Example:

```
Input:  [3, 0, 1]
Output: 2
```

---

## Approaches (Compared)

### 1. Mathematical Sum Method

Total expected sum for numbers `0..n` is:

```
total = n*(n+1)/2
```

Missing number:

```
missing = total - sum(nums)
```

### 2. XOR Method (most elegant)

Key property:

```
a ^ a = 0
a ^ 0 = a
```

If you XOR all indices and all numbers, the missing one remains.

### 3. Boolean check / hash array

Mark presence of each number and check which index is unmarked.
Uses extra O(n) space, not optimal.

### 4. Sorting (avoid)

Sort and check sequentially.
O(n log n), not ideal.

---

## Step-by-Step XOR Intuition

Let array = [3,0,1], n = 3

We compute:

```
xor_all = 0 ^ 1 ^ 2 ^ 3
xor_arr = 3 ^ 0 ^ 1
missing = xor_all ^ xor_arr
```

All present numbers cancel out:

```
xor_all ^ xor_arr = 2
```

---

## Pseudocode (XOR)

```
function missing_number(nums):
    n = length(nums)
    xor_all = 0
    xor_arr = 0

    for i in 0..n:
        xor_all = xor_all ^ i

    for x in nums:
        xor_arr = xor_arr ^ x

    return xor_all ^ xor_arr
```

---

## Time and Space Complexity

| Method       | Time       | Space |
| ------------ | ---------- | ----- |
| XOR          | O(n)       | O(1)  |
| Sum          | O(n)       | O(1)  |
| Boolean mark | O(n)       | O(n)  |
| Sorting      | O(n log n) | O(1)  |

---

## Edge Cases

* Array of length 1: `[0]` → missing 1
* Missing number is 0 (e.g. `[1,2,3]`)
* Missing number is n (e.g. `[0,1,2]`)
* Large arrays: ensure no overflow (use XOR or 64-bit type)

---

## Visual Aid (XOR cancellation)

```
nums:     0  1  3
full:     0  1  2  3

cancel:   0^0, 1^1, 3^3 → cancelled
leftover: 2
```

---

## Interview Tips

* If interviewer asks: “How to avoid overflow?” → Use XOR.
* If constraints tight: prefer O(1) space.
* If multiple numbers missing → this method no longer works; must modify.
* If array large and memory limited → XOR is best choice.
* If interviewer insists on using sum → switch to 64-bit type for safety.

---

## Practice Problems

1. LeetCode 268 – Missing Number
2. Variation: Find missing number for range 1..n
3. Variation: Two numbers missing – solve using sum and sum of squares
4. Variation: Missing and duplicate number (Cyclic Sort technique)

---
