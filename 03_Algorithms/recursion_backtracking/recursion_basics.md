# **Recursion Basics — Foundations & Intuition**

---

## **1. What is Recursion?**

**Recursion** is a technique where a function calls itself to solve subproblems of the original problem.

Every recursive function must satisfy two rules:

1. **Base Case** – when to stop
2. **Recursive Case** – breaking the problem into smaller subproblems

Example idea:

```
f(n) = n * f(n-1)
f(0) = 1
```

---

## **2. Why Recursion Works (Mathematical Intuition)**

Recursion mirrors **mathematical induction**:

1. **Base case** = induction base
2. **Recursive definition** = induction hypothesis

If smaller subproblems are correct, the full solution is correct.

---

## **3. How a Recursive Call Stack Works**

Each function call is pushed onto the stack:

```
Call f(3)
 └── calls f(2)
      └── calls f(1)
           └── calls f(0)
```

Stack unwinding happens when base case is reached.

ASCII visualization:

```
f(3)
  f(2)
    f(1)
      f(0)
    return
  return
return
```

---

## **4. Template for Writing Recursive Functions**

A universal pattern:

```
def solve(params):
    if base_case:
        return answer

    process current state

    recursive_result = solve(smaller_state)

    combine partial result

    return final_result
```

This pattern works for:

* Tree recursion
* Divide & Conquer
* Backtracking
* DFS
* DP (top-down memoization)

---

## **5. Classic Recursion Types**

| Type               | Description                       | Example                |
| ------------------ | --------------------------------- | ---------------------- |
| Linear recursion   | One recursive call per invocation | Factorial              |
| Multiple recursion | Multiple recursive calls          | Fibonacci              |
| Tree recursion     | Branching recursion               | Subset/perm generation |
| Tail recursion     | Work done *after* recursive call  | Tail factorial         |
| Mutual recursion   | Functions calling each other      | Even/odd detection     |

---

## **6. Base Case Design**

A base case should:

* Stop infinite recursion
* Return the simplest possible answer
* Be small enough that it doesn’t recurse further

Example:

```
if (n == 0) return 1;
```

---

## **7. Common Recursion Mistakes**

* Missing base case → infinite recursion
* Wrong recurrence relation
* Overlapping subproblems → exponential time
* Forgetting to return value from recursive call
* Expecting bottom-up behavior without proper handling

---

## **8. Time Complexity of Recursion**

Find complexity using:

**Recurrence Relations**
Examples:

* Factorial: T(n) = T(n−1) + O(1) → O(n)
* Fibonacci: T(n) = T(n−1) + T(n−2) → O(2^n)
* Merge Sort: T(n) = 2T(n/2) + O(n) → O(n log n)

---

## **9. When Should You Use Recursion?**

Use recursion if:

* Problem has **natural substructure**
* Tree or graph traversal
* Divide-and-conquer
* Generating all possibilities
* When iterative solutions are messy

Avoid recursion when:

* Depth may exceed limits
* Iterative approach is simpler
* Problem is tail-heavy and language lacks tail-call optimization

---

## **10. Interview Tips**

FAANG commonly asks recursion problems to test:

* Clarity in defining base/recursive cases
* Ability to reason about recursion depth
* Understanding stack usage
* Induction-like reasoning
* Converting recursion ↔ iteration

Typical questions:

* Factorial
* Fibonacci
* Tower of Hanoi
* Reverse linked list (recursive)
* DFS traversal
* Backtracking: subsets, permutations, N-Queens

---

## **11. Practice Problems**

### **LeetCode**

* 21 — Merge Two Sorted Lists
* 206 — Reverse Linked List (recursive version)
* 104 — Max Depth of Binary Tree
* 784 — Letter Case Permutation
* 46 — Permutations

### **GFG**

* Tower of Hanoi
* Print 1 to N using recursion
* Sum of digits

### **Codeforces**

* Basic DFS problems
* Recursively solving combinatorics Brute Force tasks

---

## **12. Recursion Cheat Sheet**

```
1. Identify smaller subproblem.
2. Define a clear base case.
3. Ensure progress toward base case.
4. Trust recursion for smaller inputs.
5. Combine results on returning.
```

---
