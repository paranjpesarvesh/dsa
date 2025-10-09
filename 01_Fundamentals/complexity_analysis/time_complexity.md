# ⏱️ Time Complexity in Algorithms

---

## 🔹 1. What is Time Complexity?

**Time Complexity** is a function that describes how the **running time of an algorithm grows** with respect to the size of the input `n`.

It helps us answer:
👉 *“How does the execution time scale as input grows?”*

$$
T(n) = f(n)
$$

Where:

* `T(n)` → time taken by algorithm for input size `n`.
* We care about **growth trend** rather than exact seconds.

---

## 🔹 2. Why Do We Use Asymptotic Notation?

Since actual execution time depends on hardware, compiler, and system load → we abstract it using **asymptotic notations**:

* **Big-O (O):** Upper bound (worst-case).
* **Omega (Ω):** Lower bound (best-case).
* **Theta (Θ):** Tight bound (average-case).

Example:
Binary Search → `O(log n)`, `Ω(1)`, `Θ(log n)`.

---

## 🔹 3. Step Counting Method

### Example: Sum of Array

```cpp
int sumArray(int arr[], int n) {
    int sum = 0;              // Step 1
    for (int i = 0; i < n; i++) {  // Step 2 → executes n times
        sum += arr[i];        // Step 3 → executes n times
    }
    return sum;               // Step 4
}
```

* Step 1 → 1 operation
* Step 2 → `n + 1` (last failure check)
* Step 3 → `n`
* Step 4 → 1

$$
T(n) = 2n + 3 = O(n)
$$

---

## 🔹 4. Common Time Complexities

| Complexity     | Example Algorithm              | Growth Trend          |
| -------------- | ------------------------------ | --------------------- |
| **O(1)**       | Access array element           | Constant              |
| **O(log n)**   | Binary Search, Tree search     | Slow growth           |
| **O(n)**       | Linear Search                  | Linear                |
| **O(n log n)** | Merge Sort, QuickSort (avg)    | Faster than quadratic |
| **O(n²)**      | Bubble Sort, Selection Sort    | Quadratic             |
| **O(2ⁿ)**      | Recursive Fibonacci            | Exponential           |
| **O(n!)**      | Traveling Salesman brute force | Factorial growth      |

📊 Growth visualization:

```
O(1) < O(log n) < O(n) < O(n log n) < O(n^2) < O(2^n) < O(n!)
```

---

## 🔹 5. Case Analysis

### Example: Binary Search

* **Best case:** `O(1)` → element found at mid.
* **Worst case:** `O(log n)` → keep halving until found.
* **Average case:** `O(log n)` → balanced halving.

---

## 🔹 6. Nested Loops

```cpp
for (int i = 0; i < n; i++) {       // O(n)
    for (int j = 0; j < n; j++) {   // O(n)
        // constant work
    }
}
```

$$
T(n) = O(n \times n) = O(n^2)
$$

---

## 🔹 7. Logarithmic Complexity (Intuition)

Each iteration **shrinks the problem size** by a factor (commonly 2).

* Binary Search: search space halves → `log₂n`.
* Tree height: balanced BST of `n` nodes has height ≈ `log₂n`.

---

## 🔹 8. Recurrence Relations

For recursive algorithms, we analyze time using **recurrence equations**.

### Example: Merge Sort

$$
T(n) = 2T\left(\frac{n}{2}\right) + O(n)
$$

Using **Master Theorem**:

$$
T(n) = O(n \log n)
$$

---

## 🔹 9. Visual Aid

### Growth Rate Graph (ASCII Approximation)

```
n!
|
|                      *
|                  *
|              *
|          *
|      *
|   *
| *
|________________________________ n
 O(1) O(log n) O(n) O(n log n) O(n^2) O(2^n) O(n!)
```

---

## 🔹 10. Variations & Edge Cases

* **Sparse input vs dense input** can change complexity.
* **Best-case optimizations** → e.g., Bubble Sort stops early if sorted.
* **Hidden constants** matter in practice (e.g., O(n) with huge constants may be slower than O(n log n) for small `n`).

---

## 🔹 11. Interview Tips

* Always state **best, worst, average cases**.
* Be ready to **derive complexity** by counting steps.
* For recursion: write recurrence and solve it.
* For FAANG: focus on `O(log n)`, `O(n)`, `O(n log n)` solutions.
* For GATE: expect derivations of recurrence relations and precise step counts.

---

## 🔹 12. Practice Problems

* [LeetCode 704 – Binary Search](https://leetcode.com/problems/binary-search/)
* [LeetCode 53 – Maximum Subarray (Kadane’s Algo, O(n))](https://leetcode.com/problems/maximum-subarray/)
* [GFG – Analysis of Algorithms](https://www.geeksforgeeks.org/analysis-of-algorithms-set-2-asymptotic-analysis/)
* [Codeforces – Nested Loops Problems](https://codeforces.com/)

---

✅ **Key Takeaway:**
Time complexity gives a **mathematical framework** to evaluate efficiency.
Mastering it requires **case analysis, recurrence solving, and recognizing common patterns**.

---
