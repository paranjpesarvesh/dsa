#  Complexity Notation Cheatsheet

Understanding **complexity notations** is fundamental for algorithm analysis.
This cheatsheet provides **definitions, intuition, visual aids, and comparisons** for the most common asymptotic notations.

---

##  Why Do We Need Notation?

When analyzing algorithms, exact runtime (like `3n² + 2n + 7`) is **too detailed**.
We only care about how the algorithm **scales with input size $n$**.

Asymptotic notation provides a **mathematical shorthand** for growth rates.

---

##  Common Notations

### 1. **Big-O (O) — Upper Bound**

* Describes the **worst-case growth rate**.
* Ensures algorithm won’t grow faster than this rate.

**Formal Definition:**

$$
f(n) = O(g(n)) \quad \text{if} \quad \exists \, c, n_0 \, : \, f(n) \leq c \cdot g(n) \quad \forall n \geq n_0
$$

 Guarantees performance will **not exceed** this bound.

**Example:** Insertion sort = $O(n^2)$.

---

### 2. **Big-Omega (Ω) — Lower Bound**

* Describes the **best-case growth rate**.
* Algorithm always takes at least this much time.

**Formal Definition:**

$$
f(n) = \Omega(g(n)) \quad \text{if} \quad \exists \, c, n_0 \, : \, f(n) \geq c \cdot g(n) \quad \forall n \geq n_0
$$

**Example:** Insertion sort = $\Omega(n)$ (already sorted input).

---

### 3. **Big-Theta (Θ) — Tight Bound**

* Represents both **upper and lower bound**.
* Algorithm always runs at this rate (asymptotically).

**Formal Definition:**

$$
f(n) = \Theta(g(n)) \quad \iff \quad f(n) = O(g(n)) \, \wedge \, f(n) = \Omega(g(n))
$$

**Example:** Merge sort = $\Theta(n \log n)$.

---

### 4. **Little-o (o) — Strict Upper Bound**

* Growth rate is **strictly less than** another function.

$$
f(n) = o(g(n)) \quad \text{if} \quad \lim_{n \to \infty} \frac{f(n)}{g(n)} = 0
$$

**Example:**
$n = o(n^2)$ → linear grows slower than quadratic.

---

### 5. **Little-omega (ω) — Strict Lower Bound**

* Growth rate is **strictly greater than** another function.

$$
f(n) = \omega(g(n)) \quad \text{if} \quad \lim_{n \to \infty} \frac{f(n)}{g(n)} = \infty
$$

**Example:**
$n^2 = \omega(n)$.

---

##  Visual Aid: Growth Comparison

```
Growth Rates (as n → ∞):

O(1)     <   O(log n)   <   O(n)   <   O(n log n)   <   O(n^2)   <   O(2^n)   <   O(n!)
```

ASCII chart:

```
    Complexity    Growth Curve
    --------------------------------
    O(1)          constant: -----
    O(log n)      logarithmic: __/
    O(n)          linear: /
    O(n log n)    n log n: /`
    O(n^2)        quadratic: /‾
    O(2^n)        exponential: /|
    O(n!)         factorial: /||
```

---

##  Summary Table

| Notation | Meaning            | Bound Type | Example                |
| -------- | ------------------ | ---------- | ---------------------- |
| **O**    | Upper bound        | Worst-case | QuickSort = O(n²)      |
| **Ω**    | Lower bound        | Best-case  | QuickSort = Ω(n log n) |
| **Θ**    | Tight bound        | Exact rate | MergeSort = Θ(n log n) |
| **o**    | Strict upper bound | —          | n = o(n²)              |
| **ω**    | Strict lower bound | —          | n² = ω(n)              |

---

##  Interview Tips

* FAANG interviews typically ask:

  * “What’s the **worst-case complexity**?” → **Big-O**
  * “What’s the **best-case complexity**?” → **Big-Omega**
  * “What’s the **average case**?” → Usually same as expected case (often Θ).
* Be prepared to compare algorithms by growth rates.
* Common trick: Ask about difference between **O** and **Θ**.

---

##  Practice Problems

* [GFG – Asymptotic Notations](https://www.geeksforgeeks.org/analysis-of-algorithms-asymptotic-analysis/)
* [LeetCode Discuss – Time Complexity of Algorithms](https://leetcode.com/discuss/general-discussion/105039/time-complexity-of-common-leetcode-problems)
* GATE PYQs on asymptotic notations.

---

 **Key Takeaway:**
Asymptotic notations abstract away constants and lower-order terms, letting us focus on **scalability** of algorithms.

---
