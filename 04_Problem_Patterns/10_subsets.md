# Subsets Pattern

A fundamental pattern for generating combinations, subsets, power sets, and handling decision trees.

---

# 1. What is the Subsets Pattern?

The **subsets pattern** deals with problems where you must explore all possible combinations of a given set of elements.

This naturally forms a **binary decision tree**:

For each element, you have two choices:

```
include it
or
exclude it
```

This generates **2^n sets**.

---

# 2. Visual Representation

For an input array `[1, 2, 3]`, the recursion tree looks like:

```
                      []
            /                     \
          [1]                     []
       /         \             /        \
     [1,2]     [1]         [2]         []
    /     \    /   \      /    \      /    \
[1,2,3][1,2] [1,3][1]  [2,3][2] [3]   []
```

Leaves represent all subsets.

Total subsets = 2^n

---

# 3. Approaches to Generate Subsets

### A. Backtracking (most common)

```
subsets = []

function backtrack(i, curr):
    if i == n:
        add curr to subsets
        return
    # choose element
    curr.push(nums[i])
    backtrack(i+1, curr)
    curr.pop()

    # don't choose
    backtrack(i+1, curr)
```

### B. Iterative, Using Current List of Subsets

```
subsets = [[]]

for num in nums:
    new_sets = []
    for s in subsets:
        new_sets.append(s + [num])
    subsets += new_sets
```

### C. Bitmasking

Represent subset using bit pattern from `0` to `2^n - 1`.

```
for mask in (0..(1<<n)-1):
    subset = []
    for i in range(n):
        if mask & (1 << i):
            subset.append(nums[i])
```

---

# 4. Complexity

| Method       | Time       | Space                |
| ------------ | ---------- | -------------------- |
| Backtracking | O(n * 2^n) | O(n) recursion stack |
| Iterative    | O(n * 2^n) | O(2^n) output        |
| Bitmask      | O(n * 2^n) | O(1) extra           |

All produce the full power set → inherently exponential.

---

# 5. Variations

### Sorted subsets

Sort the array first.

### Handle duplicates

Use skip logic in backtracking:

```
if i > 0 and nums[i] == nums[i-1] and not taken_prev:
    continue
```

### Subsets summing to target

Add pruning conditions.

### Subsets of fixed size k

Add an additional check:

```
if len(curr) == k:
    record subset
```

---

# 6. Common Pitfalls

* forgetting to copy the current list when pushing
* not managing duplicates in sorted array
* modifying global subset reference incorrectly
* exceeding recursion depth for large input
* ignoring pruning possibilities

---

# 7. Interview Tips

* Always mention 3 approaches: recursion, iterative expansion, bitmasking
* Clarify exponential output: cannot do faster than O(2^n)
* For duplicates, interviewer expects sorted + skipping technique
* Be able to explain decision tree
* Know when pruning is allowed (e.g., subset-sum)

---

# 8. Practice Problems

### LeetCode

* 78 Subsets
* 90 Subsets II
* 39 Combination Sum
* 40 Combination Sum II
* 77 Combinations
* 494 Target Sum

### GFG

* Power set
* Subsets with duplicates
* Sum of subsets

### Codeforces

Many problems require combinatorial DFS + pruning

---

# 9. Summary

The subsets pattern is central to:

* power set generation
* combination enumeration
* backtracking-based decision making
* pruning and optimization in exponential search

It forms the basis of many advanced topics like DP over subsets, bitmask DP, and combinatorial optimization.

---
