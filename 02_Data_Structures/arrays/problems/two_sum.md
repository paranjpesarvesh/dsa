# Two Sum

Location: `02_Data_Structures/arrays/problems/two_sum.md`

---

## Problem Statement

Given an array `A` of size `n` and a target value `T`, return the **indices** of two numbers such that their sum equals `T`.

You may assume exactly one valid solution exists and the same element cannot be used twice.

Example:

```
Input:
A = [2, 7, 11, 15], T = 9

Output:
[0, 1]
```

Explanation: `A[0] + A[1] = 2 + 7 = 9`.

---

## Approaches

---

### 1. Brute Force (Check all pairs)

Try every pair `(i, j)`.

Pseudocode:

```
for i in range(0, n):
    for j in range(i+1, n):
        if A[i] + A[j] == T:
            return [i, j]
```

Time: O(n²)
Space: O(1)

Useful for understanding but not interview-efficient.

---

### 2. Optimal Approach: Hash Map

Use a hash map to store previously seen values and their indices.

Idea:

At index `i` with value `x`, check:

```
needed = T - x
```

If `needed` exists in the map, we found the pair.

Otherwise store:

```
map[x] = i
```

---

## Pseudocode (Hash Map)

```
function two_sum(A, T):
    map = {}  # value → index

    for i from 0 to n-1:
        x = A[i]
        if (T - x) in map:
            return [map[T - x], i]
        map[x] = i
```

Time: O(n)
Space: O(n)

---

## Visual Aid

Consider: A = [2,7,11,15], T = 9

```
i = 0, x = 2
map = {}
needed = 7 → not in map
insert(2 → 0)

i = 1, x = 7
map = {2: 0}
needed = 2 → found at index 0
return [0, 1]
```

---

## Edge Cases

* Duplicates: e.g., `[3,3]` with `T=6`
  Hash map handles this correctly.
* Negative numbers
* Large target sums
* Only one solution guaranteed → no ambiguous outputs

---

## Variations

1. **Two Sum II** (array sorted) → use two pointers
2. **Three Sum**
3. **Four Sum**
4. **Count pairs with given sum**
5. **Return number of valid pairs instead of indices**

---

## Interview Tips

* Always clarify whether the array is sorted
* If sorted → use two pointers
* If not sorted → hash map
* Mention complexity confidently: O(n)
* Always store index in the map, not just value
* Don’t overwrite indices unless duplicates are handled intentionally

---

## Practice Problems

1. LeetCode 1 – Two Sum
2. LeetCode 167 – Two Sum II (sorted)
3. LeetCode 15 – Three Sum
4. LeetCode 18 – Four Sum
5. Codeforces – find pairs with target sum
6. GFG – Count pairs with given sum

---
