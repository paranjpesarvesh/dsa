# **Permutations — Recursion & Backtracking**

---

## **1. Problem Definition**

Given an array/string of **N elements**, generate **all possible permutations** — i.e., all distinct orderings.

Example:
Input: `[1, 2, 3]`
Output count: `3! = 6` permutations.

---

## **2. Intuition**

A permutation is formed by:

1. Picking one element as the first position
2. Recursively permuting the remaining `N-1`
3. Continue until all positions are filled

Total permutations = **N!**

---

## **3. Key Idea — Backtracking**

At index `i`:

* Choose any element from positions `i` to `n-1`
* Swap it to position `i`
* Recurse for next index
* Swap back (undo change)

This avoids extra arrays and is very efficient.

---

## **4. Visual Understanding**

For `[1,2,3]`:

```
Start: [1,2,3]
 |
 |- Fix 1 → permute [2,3]
 |     |- Fix 2 → [1,2,3]
 |     |- Fix 3 → [1,3,2]
 |
 |- Fix 2 → permute [1,3]
 |     |- Fix 1 → [2,1,3]
 |     |- Fix 3 → [2,3,1]
 |
 |- Fix 3 → permute [1,2]
       |- Fix 1 → [3,1,2]
       |- Fix 2 → [3,2,1]
```

---

## **5. Pseudocode (Interview-Ready)**

```
permute(i):
    if i == n:
        add current array to result
        return

    for j from i to n-1:
        swap(a[i], a[j])
        permute(i + 1)
        swap(a[i], a[j])    // backtrack
```

---

## **6. Handling Duplicate Elements**

If the array has duplicates, use a **set at each level**:

```
levelUsed = empty set
for j in range(i..n-1):
    if a[j] in levelUsed:
        continue
    levelUsed.add(a[j])
    ...
```

---

## **7. Complexity Analysis**

| Metric    | Value     | Reason                                |
| --------- | --------- | ------------------------------------- |
| **Time**  | O(N × N!) | N! permutations, each printed in O(N) |
| **Space** | O(N)      | recursion depth                       |

---

## **8. Variations**

* **Permutations of string**
* **Unique permutations (LeetCode 47)**
* **Next permutation (lexicographic)**
* **k-th permutation** using factorial number system
* **Iterative permutations using STL next_permutation**

---

## **9. Edge Cases**

* Empty array → one permutation = `[]`
* Single element → `[x]`
* Duplicate values → must avoid repeated permutations

---

## **10. Interview Tips**

* This is one of the **top 3 backtracking questions** FAANG asks.
* Expect follow-ups:

  * “How to handle duplicates?”
  * “What is complexity?”
  * “Can you generate lexicographically sorted permutations?”
* GATE focuses on factorial growth and recursion tree.

---

## **11. Practice Problems**

| Platform   | Problem                                                |
| ---------- | ------------------------------------------------------ |
| LeetCode   | Permutations (#46)                                     |
| LeetCode   | Permutations II (#47)                                  |
| GFG        | Generate permutations                                  |
| Codeforces | Everything involving brute-force & lexicographic order |
| HackerRank | Backtracking challenges                                |

---
