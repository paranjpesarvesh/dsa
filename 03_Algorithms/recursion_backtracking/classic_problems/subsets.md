# **Subsets (Power Set) — Recursive & Backtracking Approach**

---

## **1. Problem Definition**

Given a list/array of **N elements**, generate **all possible subsets** (the *power set*).

Example:
Input: `[1, 2]`
Output:
`[], [1], [2], [1,2]`

Total subsets = **2^N**

---

## **2. Intuition**

Every element has **two choices**:

* **Include** it
* **Exclude** it

This forms a binary recursion tree of height `N`.

---

## **3. Visual Understanding**

For `[1,2,3]`:

```
                         []
                   /             \
                [1]               []
              /     \           /     \
         [1,2]     [1]        [2]      []
        /    \    /   \      /   \    /   \
 [1,2,3] [1,2] [1,3] [1] [2,3] [2] [3]  []
```

---

## **4. Approaches**

### **A. Backtracking (most used)**

At index `i`:

1. Add current subset to answer
2. Loop through remaining elements
3. Add element → recurse → remove element

---

### **B. Include–Exclude Recursion**

Clear binary choice:

* Take element
* Skip element

---

## **5. Backtracking Pseudocode**

```
backtrack(start, current):
    add current to result

    for j from start to n-1:
        current.push(a[j])
        backtrack(j + 1, current)
        current.pop()
```

---

## **6. Include–Exclude Pseudocode**

```
solve(i, current):
    if i == n:
        add current to result
        return

    // include a[i]
    current.push(a[i])
    solve(i+1, current)
    current.pop()

    // exclude a[i]
    solve(i+1, current)
```

---

## **7. Complexity Analysis**

| Metric    | Value                |
| --------- | -------------------- |
| **Time**  | O(N * 2^N)           |
| **Space** | O(N) recursion stack |

---

## **8. Handling Duplicate Elements**

For sorted array with duplicates:

* Skip choosing identical elements at same tree level

```
for j in range(start..n-1):
    if j > start and a[j] == a[j-1]:
        continue
    ...
```

This solves **Subsets II (LC 90)**.

---

## **9. Edge Cases**

* Empty list → `[[]]`
* All identical values → still follow duplicate rules

---

## **10. Interview Tips**

* FAANG asks both **subsets** and **subsets with duplicates**.
* Be ready to explain why complexity is `2^N`.
* They may ask:

  * “How to get subsets in lexicographic order?”
  * “How to convert subsets to bitmasks?”
* Important for DP, combinatorics & bit manipulation questions.

---

## **11. Practice Problems**

| Platform   | Problem                             |
| ---------- | ----------------------------------- |
| LeetCode   | Subsets (#78)                       |
| LeetCode   | Subsets II (#90)                    |
| GFG        | Power Set                           |
| Codeforces | Bitmask subset enumeration problems |

---
