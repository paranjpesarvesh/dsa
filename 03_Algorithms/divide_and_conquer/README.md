# Divide and Conquer — Theory, Patterns, and Applications

Divide and Conquer (D&C) is one of the most fundamental problem-solving paradigms in computer science. Most high-performance algorithms used in competitive programming, system design, and academic CS rely on D&C.

---

# 1. Definition

Divide and Conquer solves a problem by:

1. **Divide** → Break the problem into smaller subproblems.
2. **Conquer** → Solve the subproblems recursively.
3. **Combine** → Merge the subproblem solutions into the final answer.

---

# 2. Intuition

Imagine breaking the problem into pieces until each piece becomes trivial.

Classic recursion tree:

```
                 Problem(n)
               /             \
          sub(n/2)        sub(n/2)
            /   \             /   \
      sub(n/4) sub(n/4)  sub(n/4) sub(n/4)
```

Total work = sum of all levels of the recursion tree.

---

# 3. Recurrence Relations

Most D&C algorithms follow recurrence of the form:

```
T(n) = aT(n/b) + f(n)
```

Where:

* **a** = number of subproblems
* **b** = factor of division
* **f(n)** = cost to combine

### Solved using Master Theorem

Case 1:
If f(n) = O(n^(log_b a - ε)) →
T(n) = Θ(n^(log_b a))

Case 2:
If f(n) = Θ(n^(log_b a) log^k n) →
T(n) = Θ(n^(log_b a) log^(k+1) n)

Case 3:
If f(n) = Ω(n^(log_b a + ε)) →
T(n) = Θ(f(n))

---

# 4. Common Divide and Conquer Algorithms

| Algorithm                      | Technique Summary                   |
| ------------------------------ | ----------------------------------- |
| Binary Search                  | halving search space                |
| Merge Sort                     | split → sort → merge                |
| Quick Sort                     | partition around pivot              |
| Closest Pair of Points         | geometric divide & prune            |
| Strassen Matrix Multiplication | reduces multiplications from 8 to 7 |
| Karatsuba Multiplication       | multiplies large integers faster    |
| FFT (Fast Fourier Transform)   | divide signal into halves           |

---

# 5. Generic Divide-and-Conquer Template

```
function solve(problem):
    if small(problem):
        return direct_answer(problem)

    sub1, sub2 = divide(problem)
    ans1 = solve(sub1)
    ans2 = solve(sub2)
    return combine(ans1, ans2)
```

---

# 6. Visual Illustration

### Merge Sort example:

```
Array: [8 3 5 4 7 6 2 1]

               [8 3 5 4 7 6 2 1]
              /                 \
     [8 3 5 4]                   [7 6 2 1]
      /    \                      /      \
 [8 3]    [5 4]              [7 6]      [2 1]
  / \      / \                / \        / \
8   3    5   4              7   6      2   1

Merge until sorted.
```

---

# 7. Complexity Summary

| Algorithm               | Time                            | Space    |
| ----------------------- | ------------------------------- | -------- |
| Binary Search           | O(log n)                        | O(1)     |
| Merge Sort              | O(n log n)                      | O(n)     |
| Quick Sort              | O(n log n) average, O(n²) worst | O(log n) |
| Strassen Multiplication | O(n^2.807)                      | O(n^2)   |
| Closest Pair Points     | O(n log n)                      | O(n)     |

---

# 8. When to Use Divide and Conquer

Use D&C when:

* Problem naturally splits into subproblems.
* Solutions of subproblems can be combined efficiently.
* The recursive form reduces problem size significantly.
* Input size is large (D&C often improves complexity).

Avoid D&C when:

* Combining results is too expensive.
* Subproblem count increases exponentially.
* Recursion depth may cause stack overflow for large inputs.

---

# 9. Edge Cases

* Unbalanced splitting leads to degraded performance.
* Must ensure base case is reached.
* Careful with memory usage when copying subarrays.
* Stack depth for recursion-heavy D&C.

---

# 10. Interview Tips

Typical questions:

1. Write merge sort and explain recursion tree.
2. Explain how binary search works and why O(log n).
3. Convert recurrence to Master Theorem form.
4. Show partition logic for Quick Sort.
5. Discuss stability (Merge Sort stable, Quick Sort not).

Follow-up topics:

* Tail recursion
* Recursion vs iteration
* How D&C applies in DP optimization (Divide-and-Conquer DP)

---

# 11. Practice Problems

### LeetCode

* Merge Sorted Array
* Search Insert Position
* Kth Largest Element (Quickselect)
* Maximum Subarray (Kadane + divide and conquer alternative)

### GFG

* Quick Sort
* Merge Sort
* Closest Pair of Points

### Codeforces

* Range queries solved with recursive segment trees
* Problems with binary search on answer

---
