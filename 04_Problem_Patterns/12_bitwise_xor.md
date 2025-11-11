# Bitwise XOR Pattern

The **Bitwise XOR pattern** appears frequently in problems involving:

* finding unique elements
* computing parity
* subset manipulation
* prefix XOR
* range XOR
* bitmask-based state tracking

This pattern exploits the core algebraic properties of XOR.

---

# 1. XOR Properties (Foundation)

These identities are essential:

1. `a ^ a = 0`
2. `a ^ 0 = a`
3. XOR is commutative: `a ^ b = b ^ a`
4. XOR is associative: `(a ^ b) ^ c = a ^ (b ^ c)`

These directly lead to powerful simplifications.

---

# 2. Classic Use Cases

## A. Finding the Single Number (All Others Twice)

```
res = 0
for x in arr:
    res ^= x
```

Final result is the number occurring once.

Reason: duplicates cancel out.

---

## B. Two Unique Numbers (others twice)

Maintain two buckets based on a differing bit.

Steps:

1. xor all → gives `x ^ y`
2. find rightmost set bit
3. divide into groups
4. xor each group separately

---

## C. Subset/XOR Enumeration

For problems requiring exploration of XOR contribution of subsets:

Use DFS or bitmasking where XOR is accumulated.

---

## D. Prefix XOR Technique

Prefix XOR works like prefix sum.

Define:

```
px[i] = a[0] ^ a[1] ^ ... ^ a[i]
```

Then XOR of range `[l, r]`:

```
xor(l, r) = px[r] ^ px[l-1]
```

Important: XOR “subtracts” via XOR again.

---

# 3. Bitwise XOR Pattern — When to Apply

Use this pattern when:

* duplicates exist and XOR cancels them
* you need a parity indicator
* finding unique/unpaired items
* computing range XORs efficiently
* toggling bits
* dynamic XOR queries
* when state transitions depend on flipping bits

---

# 4. Step-by-Step Reasoning Pattern

### Identify:

* Is XOR cancellation helpful?
* Does grouping by bit differences help?
* Is prefix XOR useful to avoid recomputing?

### Apply:

* Use linear scan with XOR accumulator
* Use bit-by-bit partitioning
* Precompute prefix XOR array if multiple queries

### Confirm:

* XOR properties ensure correctness
* Edge cases: array empty, negative numbers, zero

---

# 5. Template Pseudocode

## Find single unique number

```
res = 0
for x in nums:
    res = res ^ x
return res
```

Time: O(n)
Space: O(1)

---

## Find range XOR using prefix XOR

```
px = array of size n
px[0] = a[0]

for i in 1 to n-1:
    px[i] = px[i-1] ^ a[i]

xor(l, r):
    if l == 0: return px[r]
    return px[r] ^ px[l-1]
```

Time: O(n) preprocessing, O(1) per query.

---

## Find two unique numbers

```
xor_all = 0
for x in nums:
    xor_all ^= x

right_bit = xor_all & (-xor_all)

a = 0
b = 0

for x in nums:
    if x & right_bit:
        a ^= x
    else:
        b ^= x
```

---

# 6. ASCII Visualization

### XOR Pair Cancellation

Array:

```
[5, 7, 5, 9, 7]
```

Flow:

```
res = 0
res ^ 5 → 5
res ^ 7 → 2
res ^ 5 → 7
res ^ 9 → 14
res ^ 7 → 9
```

Final output: **9** (the unique number)

---

# 7. Complexity

| Problem Type       | Time     | Space |
| ------------------ | -------- | ----- |
| Single number      | O(n)     | O(1)  |
| Two unique numbers | O(n)     | O(1)  |
| Prefix XOR queries | O(n + q) | O(n)  |
| Subset XOR search  | O(2^n)   | O(n)  |

---

# 8. Variations and Edge Cases

* XOR of negative numbers works (two’s complement preserved)
* Careful splitting based on sets bits
* For prefix XOR, ensure correct handling for `l = 0`
* For large XOR queries, segment tree with XOR aggregation is useful

---

# 9. Interview Tips

* Know the XOR identities intuitively
* For two-unique-number problem, explicitly mention:
  "We find the rightmost set bit to distinguish the two numbers."
* Prefix XOR is a common trick in medium-hard questions
* XOR is ideal when order doesn’t matter
* Avoid using hash maps when XOR is more efficient
* For bitmask DP problems, think of XOR as useful in toggling states
* For subset questions, understand XOR’s non-monotonic nature

---

# 10. Practice Problems

### LeetCode

* 136 Single Number
* 137 Single Number II
* 260 Single Number III
* 898 Bitwise ORs of Subarrays
* 1310 XOR Queries of a Subarray
* 1442 Count Triplets That Can Form Two Arrays of Equal XOR

### GFG

* Find the element occurring once
* XOR range queries
* Two odd occurring numbers

### Codeforces

* Prefix XOR applications in competitive coding
* XOR basis problems (advanced)

---

# Summary

The bitwise XOR pattern is powerful because:

* it removes noise (duplicates)
* it tracks parity efficiently
* it enables fast range queries
* it simplifies subset operations

Understanding XOR’s mathematical structure allows solving a wide category of problems in linear or near-linear time.
