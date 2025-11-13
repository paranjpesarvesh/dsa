# Catalan Numbers — A Deep Dive

The **Catalan numbers** form a famous sequence in combinatorics.
They count various recursive and structural objects such as **binary trees**, **valid parentheses**, **polygon triangulations**, and more.

---

## 1. Definition

The *n-th Catalan number* `Cₙ` is defined by the formula:

[
Cₙ = \frac{1}{n + 1} \binom{2n}{n}
]

or equivalently,

[
Cₙ = \frac{(2n)!}{(n+1)! , n!}
]

---

## 2. Intuition & Combinatorial Meaning

Catalan numbers appear in problems involving *recursive structures* or *balanced constructions*.

They count:

| Problem                                                        | Counted by |
| -------------------------------------------------------------- | ---------- |
| Number of valid parentheses strings of length 2n               | Cₙ         |
| Number of full binary trees with n+1 leaves                    | Cₙ         |
| Number of ways to triangulate a convex polygon with n+2 sides  | Cₙ         |
| Number of monotonic lattice paths below diagonal (0,0) → (n,n) | Cₙ         |
| Number of BSTs with n nodes                                    | Cₙ         |

### Example

For n = 3 (i.e., 3 pairs of parentheses):

All valid combinations are:
`((()))`, `(()())`, `(())()`, `()(())`, `()()()`

Hence, `C₃ = 5`.

---

## 3. Recursive Formula (DP Relation)

The recursive definition of Catalan numbers is:

[
C₀ = 1
]

[
Cₙ = \sum_{i=0}^{n-1} C_i * C_{n - i - 1}
]

**Intuition:**
If we think of a BST with `n` nodes, choosing one node as the root splits the remaining nodes into left and right subtrees.
If `i` nodes go to the left subtree, then `(n - i - 1)` go to the right subtree.

So, total trees for root `i` = `C_i * C_{n - i - 1}`
Summing over all roots gives `Cₙ`.

---

## 4. Pseudocode (Dynamic Programming)

```
function catalan(n):
    C = array of size (n+1)
    C[0] = 1

    for i from 1 to n:
        C[i] = 0
        for j from 0 to i-1:
            C[i] += C[j] * C[i-j-1]

    return C[n]
```

**Time Complexity:** `O(n²)`
**Space Complexity:** `O(n)`

---

## 5. Mathematical Derivation (Binomial Form)

Using combinatorial reasoning:

[
Cₙ = \frac{1}{n+1} \binom{2n}{n}
]

Derives from counting all lattice paths from `(0,0)` to `(n,n)` and subtracting those crossing the diagonal.

---

## 6. Values of Catalan Numbers

| n | Cₙ   |
| - | ---- |
| 0 | 1    |
| 1 | 1    |
| 2 | 2    |
| 3 | 5    |
| 4 | 14   |
| 5 | 42   |
| 6 | 132  |
| 7 | 429  |
| 8 | 1430 |

---

## 7. Applications

| Domain                     | Example                               |
| -------------------------- | ------------------------------------- |
| **Parentheses Matching**   | Count valid bracket expressions       |
| **Binary Search Trees**    | Number of structurally unique BSTs    |
| **Polygon Triangulations** | Number of ways to triangulate n+2-gon |
| **Lattice Paths**          | Paths under diagonal                  |
| **Mountain Ranges**        | Number of up/down sequences           |

---

## 8. Optimized Computation (Using Binomial Coefficient)

Efficient O(n) computation using:

```
C = 1
for i in 0 to n-1:
    C = C * 2*(2*i + 1) / (i + 2)
return C
```

This uses the recursive multiplicative formula derived from binomial coefficients.

---

## 9. Variations

1. **Generalized Catalan Numbers (m-ary Trees):**

[
Cₙ^{(m)} = \frac{1}{(m - 1)n + 1} \binom{mn}{n}
]

2. **Dyck Paths of Restricted Height**
3. **Motzkin Numbers (related variant)**

---

## 10. Visual Aid

**Binary Tree Structure Example (n = 3):**

```
         (root)
        /      \
     T₀        T₂
       \      /  \
       T₀   T₁  T₀
```

Each subtree combination corresponds to a Catalan structure.

---

## 11. Interview Tips

* **Always mention recursive + combinatorial definition.**
* Know **BST** and **Parentheses Matching** examples.
* Be ready to derive the formula or use DP approach.
* Mention O(n²) DP and O(n) combinatorial formula difference.
* Common in FAANG for recursion/DP conceptual understanding.

---

## 12. Practice Problems

### LeetCode

* **96. Unique Binary Search Trees**
* **22. Generate Parentheses**
* **894. All Possible Full Binary Trees**

### GFG

* Count BSTs with N keys
* Catalan Number Problem

### Codeforces

* Dyck Path Counting Variants
* Bracket Sequence Combinatorics

---

## 13. Summary

| Aspect       | Description                       |
| ------------ | --------------------------------- |
| Recurrence   | `Cₙ = Σ C_i * C_{n-i-1}`          |
| Base Case    | `C₀ = 1`                          |
| Formula      | `(2n)! / ((n+1)! * n!)`           |
| Time         | `O(n²)` (DP), `O(n)` (Formula)    |
| Space        | `O(n)`                            |
| Applications | Trees, Parentheses, Lattice Paths |

---

Catalan numbers beautifully connect **combinatorics**, **recursion**, and **dynamic programming**, making them an essential topic for both **theoretical foundations** and **interview problem-solving**.

