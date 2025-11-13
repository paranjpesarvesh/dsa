# **Tail vs Head Recursion — A Clear & Practical Guide**

---

## **1. What is Head Recursion?**

**Head recursion** is when the recursive call happens **before** any processing.

General form:

```
function f(n):
    if base:
        return
    f(n-1)          ← recursive call happens FIRST
    process(n)
```

### **Example**

```
f(3):
    f(2)
        f(1)
            f(0)
        print(1)
    print(2)
print(3)
```

### **Order of execution:**

Processing happens **on the way back** (during unwinding).

---

## **2. What is Tail Recursion?**

**Tail recursion** is when the recursive call is the **last** operation.

```
function f(n):
    if base:
        return
    process(n)
    f(n-1)          ← last statement
```

### **Key property**

No extra work after the recursive call → enables **tail-call optimization (TCO)** in some languages.

### **Example**

```
f(3):
print(3)
    f(2)
print(2)
    f(1)
print(1)
```

### **Order:**

Processing happens **on the way down**.

---

## **3. Visual Comparison**

### **Head Recursion Call Flow**

```
Call f(3)
 └── f(2)
      └── f(1)
           └── f(0)
      process(1)
 process(2)
process(3)
```

### **Tail Recursion Call Flow**

```
process(3)
 └── f(2)
      process(2)
        └── f(1)
            process(1)
```

---

## **4. Differences at a Glance**

| Feature           | Head Recursion            | Tail Recursion             |
| ----------------- | ------------------------- | -------------------------- |
| Processing timing | After recursive call      | Before recursive call      |
| Memory usage      | Higher (stack grows deep) | Lower (TCO possible)       |
| Execution order   | Reverse (unwinding)       | Forward                    |
| Use cases         | Backtracking, DFS, trees  | Simple loops, accumulators |
| Convert to loop?  | Harder                    | Very easy                  |

---

## **5. Tail Recursion vs Iteration**

Tail recursion can be transformed into a loop:

```
function tail_rec(n, acc):
    if n == 0:
        return acc
    return tail_rec(n-1, acc+n)
```

Equivalent iterative:

```
acc = 0
while n > 0:
    acc += n
    n--
return acc
```

---

## **6. Pseudocode Templates**

### **Head Recursion Template**

```
def head(n):
    if n == 0:
        return
    head(n-1)
    process(n)
```

### **Tail Recursion Template**

```
def tail(n):
    if n == 0:
        return
    process(n)
    tail(n-1)
```

### **Tail Recursion with Accumulator**

```
def tail(n, acc):
    if n == 0:
        return acc
    return tail(n-1, acc + f(n))
```

---

## **7. Time & Space Complexity**

Both forms:
**Time:** O(n)
**Space (stack):**

* Head: O(n)
* Tail: O(n) normally, but **O(1)** with TCO-enabled languages

Python **does NOT** optimize tail recursion.
C/C++/Java usually do NOT either (depends on compiler).
Functional languages like **Scala, Haskell** do.

---

## **8. When to Use What**

### **Use Head Recursion When:**

* Need natural reverse order
* Tree traversal (postorder)
* Backtracking
* Problems like:

  * Print numbers 1 to N
  * Reverse operations

### **Use Tail Recursion When:**

* Want iterative-like behavior
* Want to pass accumulated state
* Problems like:

  * Factorial with accumulator
  * Sum of digits
  * GCD

---

## **9. Interview Tips**

* Tail recursion is a favorite topic in **functional programming**, **Google**, **Meta** interviews.
* They may ask:

  * Difference between tail & head recursion
  * Convert tail recursion to loop
  * Why tail recursion avoids stack overflow
  * Identify if a recursion is tail or not
* Always analyze the last operation in the function.

---

## **10. Practice Problems**

### **LeetCode**

* 206 — Reverse Linked List (try tail-recursive)
* 231 — Power of Two (recursive thinking)
* 326 — Power of Three

### **GFG**

* Sum of digits
* Tail-recursive factorial
* Recursive print 1 to N / N to 1

### **Codeforces**

* Recursion fundamentals
* Tree DFS problems

---
