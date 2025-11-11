# Stack — Theory

A **stack** is a linear data structure that follows the **LIFO (Last In, First Out)** rule.
The last element inserted is the first one removed.
Stacks are foundational in computer science and appear in many interview problems, algorithms, and system-level mechanisms.

---

## 1. What Is a Stack?

A stack maintains an ordered collection where insertion and deletion happen **only at one end**, called the **top**.

Key features:

* Order: LIFO
* Operates at one end
* Constant-time operations for push/pop/top

---

## 2. ASCII Diagram

```
         +---------+
Top -->  |    30   |
         +---------+
         |    20   |
         +---------+
Bottom-> |    10   |
         +---------+
```

---

## 3. Operations and Their Meaning

| Operation  | Description             | Time |
| ---------- | ----------------------- | ---- |
| push(x)    | Add x on top            | O(1) |
| pop()      | Remove top              | O(1) |
| top()      | Get top element         | O(1) |
| is_empty() | Check if stack is empty | O(1) |
| size()     | number of elements      | O(1) |

---

## 4. Stack Implementation Approaches

### A. Array-Based Implementation

* Uses a fixed or dynamic array
* Track the "top" index
* Extremely efficient access

```
arr = [10,20,30]
top = 2
```

### B. Linked List Based Implementation

* Top is the head of the list
* Insert/remove at head gives O(1)

```
Top -> [30]->[20]->[10]->NULL
```

---

## 5. Mathematical/Logical Intuition

Stacks model real-world LIFO structures:

* Plates in a pile
* Backtracking paths
* Undo/Redo states

### Abstract view

Let the stack be S:

* push(x): S = S ∪ {x} where x becomes the new top
* pop(): removes last inserted element

This ensures order reversal naturally.

---

## 6. When Are Stacks Used?

### System-Level

* Function call stack
* Recursion handling
* Expression parsing
* Memory allocation frames

### Algorithmic

* DFS (implicit or explicit)
* Balanced parentheses
* Next greater element (monotonic stack)
* Stock span
* Largest rectangle in histogram

---

## 7. Detailed Walkthrough of Core Operations

### Push

```
push(x):
    top = top + 1
    arr[top] = x
```

### Pop

```
pop():
    if top == -1:
        error "underflow"
    x = arr[top]
    top = top - 1
    return x
```

### Top

```
if top == -1:
    return error
return arr[top]
```

---

## 8. Edge Cases

* Underflow: popping from an empty stack
* Overflow: pushing beyond capacity (for arrays)
* Not checking empty before calling top()/pop()
* Recursive stack overflow (deep recursion)

---

## 9. Monotonic Stack Concept

A powerful variant used frequently:

### Increasing Stack

Maintains a stack where elements are sorted increasingly.

Useful for:

* Next Smaller Element
* Building efficient sliding window logic
* Histogram problem

### Decreasing Stack

Maintains decreasing order.

Used for:

* Next Greater Element
* Daily Temperatures

---

## 10. Complexity Analysis

| Operation | Time Complexity | Space |
| --------- | --------------- | ----- |
| push      | O(1)            | O(n)  |
| pop       | O(1)            | O(n)  |
| top       | O(1)            | O(n)  |
| is_empty  | O(1)            | O(n)  |
| size      | O(1)            | O(n)  |

---

## 11. Interview Patterns Using Stacks

### A. Parentheses Problems

Goal: check balance and proper nesting.

Approach: push opens, pop when matching closes.

### B. Reverse Structures

Reverse a string or linked list using stack.

### C. Expression Evaluation

* infix → postfix
* postfix → evaluation
* prefix evaluation

### D. Monotonic Stack Problems

Extremely common in FAANG interviews.

Problems:

* Largest Rectangle in Histogram
* Daily Temperatures
* Next Greater Element

---

## 12. Variations of Stack

* Two stacks to implement a queue
* Two queues to implement a stack
* Stack with min/max support in O(1)

---

## 13. Practice Problems

### LeetCode

* 20. Valid Parentheses
* 155. Min Stack
* 150. Evaluate Reverse Polish Notation
* 739. Daily Temperatures
* 496. Next Greater Element

### GeeksForGeeks

* Stock Span Problem
* Balanced Parentheses
* Next Greater Element
* Histogram Maximum Area

### Codeforces

* Bracket sequences
* Monotonic stack based contest problems

---

## 14. Tips for Interviews

* Know how to explain stack using real-world analogies
* Always talk about complexity clearly (all O(1))
* Be ready to derive a monotonic stack logic on the spot
* When debugging stack-related code:

  * check boundaries
  * ensure push/pop consistency
  * test on edge cases (empty stack, single element)

---

## Summary

A stack is a fundamental DSA concept used in both algorithm design and practical system execution.
Mastering stacks prepares you for a broad range of problems related to parsing, recursion, monotonic sequences, expression evaluation, and overall problem-solving efficiency.

