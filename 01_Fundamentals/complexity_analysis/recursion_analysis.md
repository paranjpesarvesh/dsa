#  Recursive Complexity Analysis

Recursion is one of the **most powerful problem-solving paradigms** in computer science.
But analyzing recursive functions often requires a systematic method.
This document explains **recursive complexity analysis**, step-by-step, with tools like **recurrence relations, recursion trees, and the Master Theorem**.

---

##  1. Basics of Recursive Complexity

A recursive algorithm solves a problem by breaking it into **smaller subproblems**.

### General Form

```
T(n) = a · T(n/b) + f(n)
```

* `a` = number of recursive calls
* `n/b` = size of each subproblem
* `f(n)` = cost of dividing/combining work

---

##  2. Methods of Analysis

###  Method 1: Substitution (Expansion)

* Expand recurrence step-by-step until reaching base case.
* Useful for small/simple recursions.

**Example:** Fibonacci recursion

$$
T(n) = T(n-1) + T(n-2) + O(1)
$$

Expands into an exponential tree → $O(2^n)$.

---

###  Method 2: Recursion Tree

* Draw a tree showing recursive calls.
* Each **level** = work done per recursive step.
* Summing all levels gives total cost.

**Example:** Merge Sort

$$
T(n) = 2T(n/2) + O(n)
$$

Recursion tree:

```
                n
         /               \
      n/2                n/2
   /     \             /     \
 n/4    n/4         n/4     n/4
 ... (log n levels) ...
```

At each level, total cost = `n`.
Height = `log n`.
Total cost = `n log n`.

 Complexity = **Θ(n log n)**

---

###  Method 3: Master Theorem

For recurrence:

$$
T(n) = aT(n/b) + f(n)
$$

Compare `f(n)` with $n^{\log_b a}$:

* **Case 1:** If $f(n) = O(n^{\log_b a - \epsilon})$ → $T(n) = Θ(n^{\log_b a})$
* **Case 2:** If $f(n) = Θ(n^{\log_b a})$ → $T(n) = Θ(n^{\log_b a} \log n)$
* **Case 3:** If $f(n) = Ω(n^{\log_b a + \epsilon})$ and regularity holds → $T(n) = Θ(f(n))$

---

##  3. Classic Examples

### Example 1: Binary Search

$$
T(n) = T(n/2) + O(1)
$$

* `a = 1`, `b = 2`, `f(n) = O(1)`
* $n^{\log_2 1} = n^0 = 1$
* Matches Case 2 of Master Theorem.

 **T(n) = Θ(log n)**

---

### Example 2: Merge Sort

$$
T(n) = 2T(n/2) + O(n)
$$

* `a = 2`, `b = 2`, `f(n) = n`
* $n^{\log_2 2} = n^1 = n$
* Matches Case 2.

 **T(n) = Θ(n log n)**

---

### Example 3: Tower of Hanoi

$$
T(n) = 2T(n-1) + O(1)
$$

Expand:

* $T(n) = 2T(n-1) + 1$
* \= $2(2T(n-2)+1)+1 = 4T(n-2)+3$
* \= $2^kT(n-k) + (2^k-1)$

When $k = n$:

$$
T(n) = 2^n - 1
$$

 **Exponential: Θ(2^n)**

---

##  4. Visual Aid: Common Recurrence Growth

```
Recurrence                  Complexity
------------------------------------------------
T(n) = T(n/2) + O(1)        O(log n)      (Binary Search)
T(n) = T(n-1) + O(1)        O(n)          (Linear Recursion)
T(n) = 2T(n/2) + O(n)       O(n log n)    (Merge Sort, QuickSort avg)
T(n) = T(n-1) + T(n-2)      O(2^n)        (Naive Fibonacci)
T(n) = 2T(n-1) + O(1)       O(2^n)        (Tower of Hanoi)
```

---

##  5. Edge Cases & Pitfalls

* Not all recursions fit Master Theorem (e.g., Fibonacci).
* Must check **base cases** when solving recurrences.
* Beware of hidden costs like **stack memory usage**:

  * Depth of recursion = extra **O(depth)** stack space.

---

##  6. Interview Tips

* Be ready to **write recurrence relations** for recursive code.
* Most asked recurrences:

  * Binary Search
  * Merge Sort / QuickSort
  * Fibonacci / DP vs. Recursion
  * Divide & Conquer matrix multiplication (Strassen’s)
* GATE/FAANG often test **Master Theorem cases**.
* Trick: If recursion reduces problem by constant (n-1), → Linear O(n).
  If recursion halves input (n/2), → Logarithmic O(log n).

---

##  7. Practice Problems

* [LeetCode 509 – Fibonacci Number](https://leetcode.com/problems/fibonacci-number/)
* [LeetCode 169 – Majority Element (Divide & Conquer)](https://leetcode.com/problems/majority-element/)
* [GFG – Analysis of Recursion](https://www.geeksforgeeks.org/analysis-of-recursion/)
* Solve **GATE PYQs** on recurrence relations.

---

 **Key Takeaway:**
Recursive complexity is usually solved via **recurrence relations**.
The **Master Theorem** is your go-to tool for divide-and-conquer recurrences, while **recursion trees** and **substitution** help in other cases.

---
