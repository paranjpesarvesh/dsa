# ⚖️ Amortized Analysis in Complexity Theory

---

## 🔹 Introduction

In **complexity analysis**, we usually compute the **worst-case running time** of an operation.
However, some operations are **occasionally expensive**, but most of the time **cheap**.

➡️ **Amortized Analysis** helps us calculate the **average cost per operation** over a **sequence of operations**, guaranteeing that the average cost is small, even if some operations are costly.

---

## 🔹 Real-Life Analogy

Imagine you buy a metro card for 30 rides at once.

* Buying the card costs **\$30 upfront**.
* Each ride after that feels **free**.

If you analyze per ride:

* Worst-case = \$30 (first ride).
* Amortized = \$1 per ride over 30 rides.

This is the essence of amortized analysis.

---

## 🔹 Formal Definition

> **Amortized Analysis**: A technique to determine the **average running time per operation** over a sequence of operations, ensuring a bound **better than the naive worst-case per operation**.

It does **not rely on probability** (unlike average-case analysis).
It is a **deterministic guarantee**.

---

## 🔹 Methods of Amortized Analysis

### 1. **Aggregate Method**

* Compute the **total cost** of $n$ operations.
* Divide by $n$.
* Example: If total cost = $O(n)$, then amortized cost = $O(1)$.

### 2. **Accounting Method**

* Assign **credits** to operations:

  * Cheap operations are charged more than they cost (store credits).
  * Expensive operations are charged less (paid from stored credits).
* Ensures every operation is covered fairly.

### 3. **Potential Method**

* Define a **potential function** $\Phi$ representing "stored energy".
* Amortized cost of an operation:

  $$
  \hat{c_i} = c_i + \Phi(D_i) - \Phi(D_{i-1})
  $$

  where:

  * $c_i$ = actual cost of $i^{th}$ operation
  * $D_i$ = data structure state after $i^{th}$ operation

---

## 🔹 Classic Examples

### Example 1: **Dynamic Array Expansion**

* Start with array size = 1.
* Double the capacity whenever full.

Operations:

* Most insertions cost **O(1)**.
* Occasionally, resizing costs **O(n)** (copy all elements).

#### Amortized Analysis (Aggregate Method)

* Total cost of $n$ insertions:

  $$
  O(1 + 2 + 4 + \dots + n) = O(2n) = O(n)
  $$
* Average per operation = $O(n) / n = O(1)$.

✅ Amortized cost per insertion = **O(1)**.

---

### Example 2: **Binary Counter Increment**

Consider a binary counter that increments by 1.
Each increment may flip multiple bits.

#### Worst Case:

* Incrementing $111...1$ → flips all bits → $O(k)$ for $k$-bit counter.

#### Amortized Analysis:

* Each bit flips at most $n/2, n/4, n/8, ...$ times in $n$ increments.
* Total flips = $O(n)$.
* Amortized cost = $O(1)$ per increment.

✅ Amortized increment = **O(1)**.

---

### Example 3: **Stack with Multipop**

* Stack supports:

  * `push(x)` → O(1)
  * `pop()` → O(1)
  * `multipop(k)` → pop up to $k$ elements

#### Worst Case:

* `multipop(n)` = O(n).

#### Amortized:

* Each element can be **pushed once** and **popped once**.
* Total across $n$ ops = O(n).
* Amortized per operation = **O(1)**.

---

## 🔹 Visual Aid

```
Dynamic Array Growth
Capacity: 1 → 2 → 4 → 8 → 16 → ...
Insertions: cheap cheap cheap EXPENSIVE resize cheap ...
Amortized: O(1) average cost
```

---

## 🔹 Complexity Summary

| Operation Type           | Worst Case | Amortized Case |
| ------------------------ | ---------- | -------------- |
| Insert in dynamic array  | O(n)       | O(1)           |
| Increment binary counter | O(log n)   | O(1)           |
| Multipop in stack        | O(n)       | O(1)           |

---

## 🔹 Interview Tips

* FAANG interviewers love **dynamic arrays** as an example.
* Always mention **amortized vs worst-case difference**.
* GATE exams test using **binary counter analysis**.
* Be careful: **Amortized ≠ Average-case** (probability is not involved).

---

## 🔹 Practice Problems

* [LeetCode 622 – Design Circular Queue](https://leetcode.com/problems/design-circular-queue/)
* [LeetCode 380 – Insert Delete GetRandom O(1)](https://leetcode.com/problems/insert-delete-getrandom-o1/)
* [GFG – Amortized Analysis of Dynamic Table](https://www.geeksforgeeks.org/analysis-of-algorithms-set-5-amortized-analysis-introduction/)

---

✅ **Key Takeaway**:
Amortized analysis allows us to **spread out expensive operations** across many cheap ones, yielding efficient **average guarantees**.

---
