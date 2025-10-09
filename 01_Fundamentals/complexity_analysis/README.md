# 📊 Complexity Analysis – README

---

## 🔹 Overview

Complexity analysis is the foundation of **Data Structures & Algorithms (DSA)**.
It helps us measure the **efficiency** of algorithms in terms of:

* **Time Complexity** → How running time grows with input size.
* **Space Complexity** → How much extra memory is required.

Mastering this is essential for **coding interviews, competitive programming, and theoretical CS exams (GATE, GRE, etc.)**.

---

## 🔹 Why Complexity Analysis?

* To **compare algorithms** independent of hardware/software.
* To **predict scalability** as input grows.
* To **choose optimal solutions** under memory/time constraints.

Example:

* Bubble Sort → `O(n²)`
* Merge Sort → `O(n log n)`

For large inputs, `O(n log n)` is significantly better.

---

## 🔹 Key Topics Covered

This subdirectory contains theory, worked examples, and cheatsheets for analyzing algorithm efficiency.

```
complexity_analysis/
│── README.md                # Overview (this file)
│── notation_cheatsheet.md   # Big-O, Theta, Omega notations
│── time_complexity.md       # Analyzing runtime growth
│── space_complexity.md      # Memory usage breakdown
│── recursive_analysis.md    # Recurrence relations, master theorem
│── amortized_analysis.md    # Amortized cost for operations
│── worked_examples/
│    ├── example_01_sum_of_array.md
│    ├── example_02_binary_search.md
│    ├── example_03_mergesort.md
│    ├── example_04_hash_table_ops.md
│    └── example_05_graph_traversal.md
```

---

## 🔹 Core Concepts

### 1. **Asymptotic Notation**

* **Big-O (O):** Worst-case upper bound.
* **Omega (Ω):** Best-case lower bound.
* **Theta (Θ):** Tight bound (average-case).

### 2. **Time Complexity**

* Step counting, loop analysis, recursion analysis.
* Common growth rates: `O(1)`, `O(log n)`, `O(n)`, `O(n log n)`, `O(n²)`, `O(2^n)`, `O(n!)`.

### 3. **Space Complexity**

* Memory from variables, recursion stack, auxiliary DS.

### 4. **Recursive Analysis**

* **Recurrence relations** and solving via **recursion tree** or **Master Theorem**.

### 5. **Amortized Analysis**

* Average cost over multiple operations.
* Examples: Dynamic array resizing, Union-Find with path compression.

---

## 🔹 Visual Map

```
                   +----------------------+
                   |  Complexity Analysis |
                   +----------+-----------+
                              |
     ------------------------------------------------
     |                  |                |          |
 Notation          Time Complexity   Space      Special
 (O, Θ, Ω)         Iterative + Rec.  Complexity Amortized
     |                  |                |          |
 Worked Examples -> Sum, Binary Search, MergeSort, Hash Table, Graph
```

---

## 🔹 Interview Tips

* Always mention **best, worst, and average cases**.
* Be prepared to **derive complexity step-by-step**.
* For recursion → write recurrence and solve.
* For FAANG: focus on `O(n)`, `O(n log n)` solutions.
* For GATE: expect precise derivations (recurrence solving).
* **Trick Questions:** Watch for hidden costs (I/O, hash collisions, recursion depth).

---

## 🔹 Practice Resources

* 📘 \[CLRS – Introduction to Algorithms, Ch. 2 & 3]
* [GeeksforGeeks – Analysis of Algorithms](https://www.geeksforgeeks.org/analysis-of-algorithms-set-2-asymptotic-analysis/)
* [LeetCode – Algorithm Complexity discussions](https://leetcode.com/)
* [Codeforces – Time Limit Problems](https://codeforces.com/)

---

✅ **Key Takeaway:**
Complexity analysis allows you to **predict performance before coding**, saving time and guiding optimal solutions.

---
