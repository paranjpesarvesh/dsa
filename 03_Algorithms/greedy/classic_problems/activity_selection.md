# **Activity Selection Problem (Greedy Algorithm)**

---

## **1. Problem Definition**

You are given **N activities**, each with:

* **start time** si
* **finish time** fi

Two activities are **compatible** if they do not overlap.

### **Goal**

Select the **maximum number of non-overlapping activities**.

This is a classic greedy scheduling problem.

---

## **2. Why Greedy Works**

The key idea:

**Always pick the activity that finishes earliest**, because:

* It leaves maximum room for future activities
* Optimal substructure: remaining activities still form the same subproblem
* Greedy choice property holds

This was proven using an exchange argument.

---

## **3. Strategy (Greedy Choice)**

### **Step 1**

Sort activities by **finish time (ascending)**.

### **Step 2**

Pick the first activity (earliest finish).

### **Step 3**

For each next activity:
If its start time ≥ last selected finish time → select it.

This guarantees the optimal solution.

---

## **4. ASCII Timeline Illustration**

Activities (start–finish):
A: 1–4
B: 3–5
C: 0–6
D: 5–7
E: 8–9
F: 5–9

Sorted by finish time:
A(1–4), B(3–5), D(5–7), F(5–9), E(8–9)

Selected = A → D → E
Total = 3 activities

---

## **5. Pseudocode (No Code Block)**

sort activities by finish time

result = []
lastFinish = -inf

for each (s, f) in activities:
if s >= lastFinish:
result.append((s, f))
lastFinish = f

return result

---

## **6. Complexity**

| Step           | Complexity                      |
| -------------- | ------------------------------- |
| Sorting        | O(N log N)                      |
| Selection Loop | O(N)                            |
| **Total**      | **O(N log N)**                  |
| Space          | O(1) or O(N) for storing result |

---

## **7. Variations**

* **Weighted Activity Selection** → DP required
* **Interval Scheduling with Rooms** (interval partitioning)
* **Scheduling to minimize lateness**
* **Interval covering / stabbing problems**

---

## **8. Edge Cases**

* Activities already sorted
* Activities with same finish times
* Activities fully overlapping → only 1 picked
* Zero-length activities (start == finish)

---

## **9. Interview Tips**

FAANG loves interval problems.
Expect variations like:

* Meeting rooms
* Maximum non-overlapping intervals
* Merge intervals (related idea)
* Scheduling tasks on servers
* Scheduling lectures in classrooms

Key points interviewers check:

* Why finishing-time sorting is optimal
* Greedy-choice proof intuition
* Ability to handle intervals cleanly
* Edge cases involving equal times

---

## **10. Practice Problems**

**LeetCode:**

* 435 — Non-overlapping Intervals
* 252 — Meeting Rooms
* 253 — Meeting Rooms II
* 646 — Maximum Length of Pair Chain

**GFG:**

* Activity Selection
* Maximize non-overlapping intervals

**Codeforces:**

* 777A — scheduling intervals
* 1203G — array of activities with constraints

---
