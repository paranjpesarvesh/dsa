# 🔄 Recursion Patterns Cheatsheet

Recursion is a **fundamental paradigm** in DSA. Many problems are simplified by **breaking them down into smaller subproblems** that mirror the original structure.
This cheatsheet highlights **recursion patterns**, their **intuitions**, **pseudocode templates**, and **common pitfalls**.

---

## 📌 1. Basic Recursive Pattern

### Idea

A recursive function typically has two components:

1. **Base Case** → Stops recursion.
2. **Recursive Case** → Breaks problem into smaller subproblems.

### Template

```text
function recurse(parameters):
    if base_condition:
        return result
    smaller_result = recurse(smaller_input)
    return combine(smaller_result, current_work)
```

### Example → Factorial

```python
def factorial(n):
    if n == 0:  # base case
        return 1
    return n * factorial(n-1)  # recursive case
```

---

## 📌 2. Tail Recursion

### Idea

Recursive call is the **last operation**.
Many languages optimize this (Tail Call Optimization), but **Python does not**.

```python
def tail_factorial(n, acc=1):
    if n == 0:
        return acc
    return tail_factorial(n-1, acc*n)
```

⚠️ In Python, prefer **iteration** for tail recursion due to recursion depth limits.

---

## 📌 3. Divide & Conquer

### Idea

Break problem into **independent subproblems**, solve recursively, then combine.

### Template

```text
function divide_and_conquer(problem):
    if problem is small:
        return trivial_solution
    left = divide_and_conquer(subproblem1)
    right = divide_and_conquer(subproblem2)
    return merge(left, right)
```

### Example → Merge Sort

```python
def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr)//2
    left = merge_sort(arr[:mid])
    right = merge_sort(arr[mid:])
    return merge(left, right)
```

---

## 📌 4. Recursion with Backtracking

### Idea

Explore **all possibilities**, undo choices (backtrack) when they fail.

### Template

```text
function backtrack(state, choices):
    if goal_reached(state):
        record_solution(state)
        return
    for choice in choices:
        make_choice(state, choice)
        backtrack(state, remaining_choices)
        undo_choice(state, choice)
```

### Example → N-Queens

```python
def solve_nqueens(board, row):
    if row == len(board):
        print(board)
        return
    for col in range(len(board)):
        if is_safe(board, row, col):
            board[row][col] = "Q"
            solve_nqueens(board, row+1)
            board[row][col] = "."
```

---

## 📌 5. Recursion with Memoization (Top-Down DP)

### Idea

Avoid recomputation by caching results.

```python
from functools import lru_cache

@lru_cache(None)
def fib(n):
    if n <= 1:
        return n
    return fib(n-1) + fib(n-2)
```

---

## 📌 6. Multiple Recursions (Tree Recursion)

### Idea

Each call spawns **multiple recursive calls** (common in trees, DP).

```python
def fib(n):
    if n <= 1:
        return n
    return fib(n-1) + fib(n-2)
```

### Tree View of `fib(4)`

```
            fib(4)
           /     \
       fib(3)    fib(2)
      /    \     /    \
   fib(2) fib(1)fib(1) fib(0)
   /    \
fib(1) fib(0)
```

---

## 📌 7. Hybrid Recursion + Iteration

Some problems require **recursive decomposition** but **iterative processing** of results.

Example → Flatten a Nested List:

```python
def flatten(lst):
    for x in lst:
        if isinstance(x, list):
            yield from flatten(x)
        else:
            yield x
```

---

## 📌 8. Complexity Analysis of Recursion

### General Method

1. Write recurrence relation.
2. Solve using **Master Theorem**, recursion tree, or expansion.

| Pattern              | Recurrence                    | Complexity |
| -------------------- | ----------------------------- | ---------- |
| Factorial            | T(n) = T(n-1) + O(1)          | O(n)       |
| Fibonacci (naïve)    | T(n) = T(n-1) + T(n-2) + O(1) | O(2^n)     |
| Fibonacci (memoized) | T(n) = T(n-1) + O(1)          | O(n)       |
| Merge Sort           | T(n) = 2T(n/2) + O(n)         | O(n log n) |

---

## 📌 9. Common Pitfalls

* ❌ Missing base case → infinite recursion, stack overflow.
* ❌ Overlapping subproblems → exponential time (fix with memoization).
* ❌ Large depth in Python → use iteration or `sys.setrecursionlimit()` carefully.

---

## 📌 10. Interview Tips

* 🚀 **FAANG** → Expect backtracking, DFS (tree/graph), recursive DP.
* 📝 **GATE** → Focus on recurrence relations & complexity analysis.
* ⚡ Always state **recurrence equation** in interviews before solving.

---

## 📌 11. Practice Problems

* **LeetCode 46** – Permutations
* **LeetCode 51** – N-Queens
* **LeetCode 22** – Generate Parentheses
* **GFG** – Rat in a Maze
* **Codeforces** – Recursive divide & conquer problems

---

