# Strassen’s Matrix Multiplication — Divide and Conquer

Matrix multiplication using the traditional algorithm takes **O(n³)** time.
Strassen’s algorithm improves this to **O(n^log₂7) ≈ O(n²·⁸¹)** using a clever divide-and-conquer strategy.

This algorithm is fundamental in theoretical computer science and competitive programming interviews.

---

# 1. Problem Statement

Given two square matrices A and B of size n×n, compute matrix C = A × B.

Traditional approach:

```
C[i][j] = Σ (A[i][k] * B[k][j]) for k=1..n
```

Time: O(n³)

Strassen reduces multiplications by treating matrices as 2×2 block matrices.

---

# 2. Key Idea

Instead of performing **8** multiplications required for block matrix multiplication, Strassen’s algorithm uses **7** cleverly chosen multiplications and **18** additions.

This yields:

T(n) = 7T(n/2) + O(n²)
→ T(n) = O(n^log₂7) ≈ O(n².⁸¹)

---

# 3. Divide-and-Conquer Breakdown

Split each matrix into four equal submatrices:

```
A = | A11 A12 |
    | A21 A22 |

B = | B11 B12 |
    | B21 B22 |
```

---

# 4. Strassen’s 7 Products

We compute:

```
P1 = (A11 + A22) * (B11 + B22)
P2 = (A21 + A22) * B11
P3 = A11 * (B12 - B22)
P4 = A22 * (B21 - B11)
P5 = (A11 + A12) * B22
P6 = (A21 - A11) * (B11 + B12)
P7 = (A12 - A22) * (B21 + B22)
```

These are the 7 multiplications.
Everything else is matrix addition/subtraction → O(n²).

---

# 5. Final Result Construction

The submatrices of C are:

```
C11 = P1 + P4 - P5 + P7
C12 = P3 + P5
C21 = P2 + P4
C22 = P1 - P2 + P3 + P6
```

---

# 6. Step-by-Step Algorithm

1. Base case:
   If matrix size is 1×1 → directly multiply.

2. Divide matrices A and B into four (n/2 × n/2) blocks.

3. Compute the 7 Strassen products (recursively).

4. Compute C11, C12, C21, C22 using Strassen’s equations.

5. Combine submatrices to build final matrix C.

---

# 7. Pseudocode

```
function strassen(A, B, n):
    if n == 1:
        return A * B

    split A into A11, A12, A21, A22
    split B into B11, B12, B21, B22

    P1 = strassen(A11 + A22, B11 + B22)
    P2 = strassen(A21 + A22, B11)
    P3 = strassen(A11, B12 - B22)
    P4 = strassen(A22, B21 - B11)
    P5 = strassen(A11 + A12, B22)
    P6 = strassen(A21 - A11, B11 + B12)
    P7 = strassen(A12 - A22, B21 + B22)

    C11 = P1 + P4 - P5 + P7
    C12 = P3 + P5
    C21 = P2 + P4
    C22 = P1 - P2 + P3 + P6

    return merge(C11, C12, C21, C22)
```

---

# 8. Visual Aid

Matrix split:

```
           ┌────────────┐
           │ A11 | A12  │
           │─────|──────│
           │ A21 | A22  │
           └────────────┘
```

Strassen replaces 8 block multiplications with 7 smart ones.

---

# 9. Complexity Analysis

Traditional multiplication:

* Time: O(n³)
* Space: O(1) extra (in-place possible)

Strassen:

* Time: O(n²·⁸¹)
* Space: O(n²) extra

However:

* For small n, Strassen may be slower due to constant factors.
* Optimal implementations switch to normal multiplication below a threshold (usually n < 64 or 32).

---

# 10. When to Use Strassen?

- Large matrices
- Theoretical algorithm analysis
- Competitions requiring fast asymptotics
- GPU/parallel implementations

Avoid when:
- n not a power of 2 (padding needed)
- matrices are small
- stability is crucial (Strassen is numerically less stable)

---

# 11. Variations

* Winograd’s variant (reduces additions)
* Recursive blocked matrix multiplication (cache-optimized)
* Coppersmith–Winograd algorithm (theoretical improvements)
* Latest record: O(n².³⁷²...) using advanced algebra

---

# 12. Interview Tips

1. Be ready to explain **why 7 multiplications instead of 8**.
2. Show the recurrence relation and solve using Master Theorem.
3. Mention real-world limitations (instability & memory).
4. Interviewers love asking when Strassen is practical.

---

# 13. Practice Problems

### LeetCode

* Matrix algorithms, though not directly Strassen.

### GFG

* "Strassen Matrix Multiplication"

### Codeforces

* Problems involving fast matrix exponentiation sometimes benefit indirectly.

---
