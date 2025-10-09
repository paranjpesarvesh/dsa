# 🧩 Satisfiability of Equality Equations using Disjoint Set (Union-Find)

---

## 📌 Introduction

The **Satisfiability of Equality Equations** problem is a classic **DSU application** in **graph theory** and **constraint solving**.

**Problem Statement:**
You are given an array of strings representing **equality (`==`) or inequality (`!=`) relations** between variables:

```
["a==b", "b!=c", "c==a"]
```

Determine whether it is possible to assign values to variables so that **all equations are satisfied**.

* Variables are single lowercase letters (`a` to `z`).
* This problem is commonly seen in **competitive programming** and **interview rounds** (LeetCode, GFG).

---

## 📌 Mathematical Intuition

1. **Model variables as nodes** in a graph.
2. **Union all variables connected by `==`** equations.
3. **Check `!=` equations**: if any two variables connected by `!=` are in the same set → contradiction.

This leverages **DSU (Union-Find)** to efficiently track equivalence classes of variables.

---

## 📌 Step-by-Step Reasoning

1. **Initialize DSU** for all 26 lowercase letters.
2. **Process all `==` equations**:

   * Union the two variables.
3. **Process all `!=` equations**:

   * If `find(var1) == find(var2)`, return `False` → contradiction.
4. If no contradictions, **return True**.

---

## 📌 Pseudocode

```
function equationsPossible(equations):
    dsu = DSU(26)  # For 'a' to 'z'

    # Step 1: Process equality equations
    for eq in equations:
        if eq[1:3] == "==":
            x = ord(eq[0]) - ord('a')
            y = ord(eq[3]) - ord('a')
            dsu.union(x, y)

    # Step 2: Process inequality equations
    for eq in equations:
        if eq[1:3] == "!=":
            x = ord(eq[0]) - ord('a')
            y = ord(eq[3]) - ord('a')
            if dsu.find(x) == dsu.find(y):
                return False

    return True
```

---

## 📌 Complexity Analysis

| Operation          | Complexity                             |
| ------------------ | -------------------------------------- |
| DSU initialization | O(26) ≈ O(1)                           |
| Union operations   | O(E α(26)) ≈ O(E)                      |
| Find operations    | O(E α(26)) ≈ O(E)                      |
| **Overall**        | **O(E)** where E = number of equations |
| Space              | O(26) ≈ O(1)                           |

> `α(N)` is the **inverse Ackermann function**, practically constant.

---

## 📌 ASCII Visualization

```
Equations: ["a==b", "b==c", "a!=c"]

Union sets for ==:
a==b => {a,b}, {c}, ...
b==c => {a,b,c}, ...

Check !=:
a!=c => a and c are in same set {a,b,c} => Contradiction
```

---

## 📌 Variations & Edge Cases

* **Multiple disconnected sets:** DSU handles them naturally.
* **Self-contradictory equations:** e.g., `"a!=a"` → always false.
* **Only equality or only inequality:** handled in two-pass approach.
* **Large variable range:** map variable names to integers for DSU.

---

## 📌 Interview Tips

* Two-pass approach: **first `==`, then `!=`** is crucial.
* Efficient DSU implementation with **path compression** and **union by rank** ensures O(E) time.
* Problem often appears in **LeetCode Medium** and **competitive programming contests**.

---

## 📌 Practice Problems

* [LeetCode 990 – Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/)
* [GFG – Equations Possible](https://www.geeksforgeeks.org/check-whether-equality-expressions-possible/)
* [Codeforces – Equivalence Classes Problems](https://codeforces.com/problemset)

---

✅ **Summary:**
This problem demonstrates how **Disjoint Set (Union-Find)** can efficiently solve **equivalence and constraint satisfaction problems**, making it an essential tool in both competitive programming and real-world graph/logic applications.

