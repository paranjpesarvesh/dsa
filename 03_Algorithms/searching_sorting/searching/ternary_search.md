# **Ternary Search — Theory, Intuition & Implementation**

---

## **1. What is Ternary Search?**

Ternary Search is a **divide-and-conquer** searching algorithm used on **unimodal functions** or **monotonic segments**, not general arrays.
It repeatedly splits the search interval into **three** parts (using two midpoints) and discards one part.

Used mainly when the function:

* strictly **increases**, then **decreases** (unimodal),
* or strictly **decreases**, then **increases**.

---

## **2. Intuition**

Imagine a mountain:

```
     /\
    /  \
   /    \
```

You want to find the peak (maximum).
Instead of checking one midpoint (binary search), ternary search checks **two** midpoints:

```
l ---- m1 ---- m2 ---- r
```

* If `f(m1) < f(m2)` → peak lies in `(m1, r)`
* If `f(m1) > f(m2)` → peak lies in `(l, m2)`

---

## **3. When to Use Ternary Search?**

### ✔ Best suited for:

* **Unimodal arrays** (find max/min)
* **Optimization problems**
* **Continuous functions** (search over real values)

### ✘ Not suited for:

* Unsorted or normally sorted arrays (use binary search)

---

## **4. Step-by-Step Working**

1. Compute two midpoints:
   `m1 = l + (r - l) / 3`
   `m2 = r - (r - l) / 3`
2. Compare `f(m1)` and `f(m2)`.
3. Narrow search to the region where the maximum/minimum must lie.
4. Repeat until the interval becomes small.

---

## **5. Visual Diagram**

```
l           m1           m2            r
|-----------|------------|-------------|

Case 1: f(m1) < f(m2) → max lies in [m1, r]

Case 2: f(m1) > f(m2) → max lies in [l, m2]
```

---

## **6. Pseudocode (Discrete)**

```
function ternarySearch(l, r):
    while r - l > 2:
        m1 = l + (r - l) / 3
        m2 = r - (r - l) / 3

        if f(m1) < f(m2):
            l = m1
        else:
            r = m2

    return index with best f(i) in [l, r]
```

---

## **7. Time & Space Complexity**

| Type  | Complexity                          |
| ----- | ----------------------------------- |
| Time  | O(log₃ n) ≈ O(log n)                |
| Space | O(1) iterative / O(log n) recursive |

---

## **8. Variations**

* **Ternary Search on real numbers** (with precision)
* **Search for minimum** instead of maximum
* **Recursive vs iterative implementations**

---

## **9. Edge Cases**

* Function must be **strictly unimodal**
* Stops working correctly if plateau/flat region exists
* Needs care to avoid infinite loops due to rounding

---

## **10. Interview Tips (FAANG/GATE)**

* Rarely asked directly but common in **optimization problems**.
* Appears in **competitive programming**.
* Know difference between **Binary Search** and **Ternary Search**:

  * Binary → ordered data
  * Ternary → unimodal data

---

## **11. Practice Problems**

### **LeetCode**

* Find Peak Element
* Peak Index in Mountain Array

### **Codeforces**

* Many ternary search optimization tasks
* Problems involving convex/unimodal functions

### **GFG**

* Maximum/Minimum of Unimodal Array

---
