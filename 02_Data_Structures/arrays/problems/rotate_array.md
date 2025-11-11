# Rotate Array

Location: `02_Data_Structures/arrays/problems/rotate_array.md`

---

## Problem Statement

Given an array `A` of size `n` and an integer `k`, rotate the array **right** by `k` positions.

Example:

```
Input:
A = [1,2,3,4,5,6,7], k = 3

Output:
[5,6,7,1,2,3,4]
```

Rotation means elements are shifted; those that go past the end wrap around to the front.

---

## Key Insight

`k` may be greater than `n`, so always normalize:

```
k = k % n
```

---

## Approaches

### 1. Extra Space (Simplest)

Copy the last `k` elements to the front.

Pseudocode:

```
B = A[n-k : n] + A[0 : n-k]
return B
```

Time: O(n)
Space: O(n)

---

### 2. In-Place (Optimal): Reverse Technique

Rotate using three reversals:

```
1. Reverse entire array
2. Reverse first k elements
3. Reverse remaining n-k elements
```

Example:

```
Original:       1 2 3 4 5 6 7
Step 1:         7 6 5 4 3 2 1
Step 2 (k=3):   5 6 7 4 3 2 1
Step 3:         5 6 7 1 2 3 4
```

---

## Pseudocode (Reverse Approach)

```
function rotate(A, k):
    n = len(A)
    k = k % n

    reverse(A, 0, n-1)
    reverse(A, 0, k-1)
    reverse(A, k, n-1)

function reverse(A, l, r):
    while l < r:
        swap A[l], A[r]
        l += 1
        r -= 1
```

---

## Visual Aid: Reverse Sections

```
Before rotation: [1 2 3 4 5 6 7]

After full reverse:
[7 6 5 4 3 2 1]

Reverse first k elements (k=3):
[5 6 7 | 4 3 2 1]

Reverse remaining:
[5 6 7 | 1 2 3 4]
```

---

## Edge Cases

* `k = 0` → no rotation
* `n = 1` → unchanged
* `k % n = 0` → unchanged
* empty array
* negative rotations (rotate left → convert to right by `k = n - (k % n)`)

---

## Variations

1. Rotate left by k
2. Rotate linked list (LeetCode 61)
3. Rotate matrix (90° rotations)
4. Circular array problems
5. Large streaming arrays — avoid copying

---

## Interview Tips

* Always optimize `k = k % n`
* Explain the reverse method cleanly
* Mention time O(n), space O(1)
* Be ready to write code in-place
* Demonstrate dry run
* Knowing both approaches helps justify trade-offs

---

## Practice Problems

1. LeetCode 189 – Rotate Array
2. GFG – Rotate Array Left/Right
3. Rotating an Array with Extra Space Constraint
4. Circular Array Next Greater Element
5. Rotation in subarrays (advanced)

---
