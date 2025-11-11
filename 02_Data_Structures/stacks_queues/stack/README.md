# Stack — Overview

A **stack** is a linear data structure that follows the **LIFO (Last In, First Out)** principle.

The last element inserted is the first one removed.

This makes stacks ideal for scenarios where order reversal or controlled backtracking is needed.

---

## 1. Characteristics

* LIFO behavior
* Supports fast O(1) operations
* Can be implemented using:

  * arrays
  * linked lists
  * two queues
  * a single queue
  * two stacks (for reverse stacks)

---

## 2. Visual Structure

### Stack Representation (Top at Right)

```
Bottom -> [10][20][30] -> Top
```

### Push operation:

```
Push 40
Bottom -> [10][20][30][40] -> Top
```

### Pop operation:

```
Pop
Bottom -> [10][20][30] -> Top
```

---

## 3. Core Operations

| Operation  | Description        | Time Complexity |
| ---------- | ------------------ | --------------- |
| push(x)    | Insert x at top    | O(1)            |
| pop()      | Remove top         | O(1)            |
| top()      | View top element   | O(1)            |
| is_empty() | Check if empty     | O(1)            |
| size()     | Number of elements | O(1)            |

---

## 4. When to Use a Stack?

Stacks are used when you need:

* Undo/Redo operations
* Function call stack (recursion)
* Parsing expressions
* Parenthesis matching
* Reversal of sequences
* Backtracking (DFS, paths)
* Evaluation of postfix/prefix expressions

---

## 5. Stack Implementation Methods

### A. Array-Based Stack

* Using dynamic arrays (list in Python, vector in C++).
* Pros:

  * Simplicity
  * Constant-time operations
* Cons:

  * Fixed size in traditional arrays (not an issue in Python/C++ STL)

### B. Linked List Based Stack

* Uses nodes connected by pointers
* Pros:

  * No size limit
* Cons:

  * Memory overhead per node

---

### ASCII Diagram (Linked List Stack)

```
Top -> [data | next] -> [data | next] -> NULL
```

---

## 6. Interview-Relevant Concepts

### A. Valid Parentheses

```
"({[]})" → valid
"([)]" → invalid
```

Use stack to match open/close types.

### B. Next Greater Element

Traverse from right → maintain decreasing stack

### C. Min-Stack

Stack supporting getMin() in O(1).

### D. Evaluate Expressions

* Infix → Postfix
* Postfix Evaluation
* Prefix Evaluation

---

## 7. Common Pitfalls

1. **Stack Underflow**

   * Trying to pop from an empty stack.
2. **Stack Overflow**

   * (Relevant in low-level languages) pushing beyond array capacity.
3. **Not handling empty stack cases**

   * Missing boundary checks.
4. **Using recursive stack incorrectly**

   * Deep recursion → stack overflow.

---

## 8. Pseudocode Template

### Push

```
push(x):
    top += 1
    arr[top] = x
```

### Pop

```
pop():
    if top == -1:
        return error
    value = arr[top]
    top -= 1
    return value
```

### Top

```
if top == -1:
    return error
return arr[top]
```

---

## 9. Complexity Analysis

| Operation | Time | Space |
| --------- | ---- | ----- |
| push      | O(1) | O(1)  |
| pop       | O(1) | O(1)  |
| top       | O(1) | O(1)  |
| is_empty  | O(1) | O(1)  |
| size      | O(1) | O(1)  |

---

## 10. Variations

* Min Stack
* Max Stack
* Two-stack queue
* Two-queue stack
* Stack using priority queue
* Online span problems (stock span)
* Largest rectangle in histogram (requires stack)

---

## 11. Interview Tips

* Stacks are extremely common in interviews
* Know how to solve:

  * Valid Parentheses
  * Next Greater Element
  * Min Stack
  * Daily Temperatures
  * Simplify Path
  * Evaluate RPN
* Be comfortable with recursion stack concepts
* Understand monotonic stack patterns (increasing/decreasing)

---

## 12. Practice Problems

### LeetCode

* 20 — Valid Parentheses
* 155 — Min Stack
* 150 — Evaluate Reverse Polish Notation
* 739 — Daily Temperatures
* 496 — Next Greater Element I
* 84 — Largest Rectangle in Histogram

### GeeksForGeeks

* Stock Span Problem
* Balanced Parentheses
* Next Greater Element
* Histogram Maximum Area

### Codeforces

* Stacks often appear in:

  * bracket sequence problems
  * monotonic stack challenges
  * greedy + stack hybrid tasks

---

## 13. Related Topics

* queues
* deques
* priority queues
* recursion
* greedy algorithms
* sliding window (sometimes uses stack for NGE)

---

## Summary

A stack is a simple yet powerful data structure essential for solving numerous interview problems. Mastering stacks equips you to handle expression evaluation, parsing, monotonic stack patterns, recursion, and backtracking problems efficiently.

