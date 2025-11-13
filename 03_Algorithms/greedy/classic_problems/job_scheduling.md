# **Job Scheduling to Maximize Profit (Greedy Algorithm)**

---

## **1. Problem Definition**

You are given **N jobs**, each with:

* **deadline** di
* **profit** pi
* Each job takes **1 unit of time**
* Only **one job** can be done at a given time slot

### **Goal**

Schedule jobs such that:

* No job misses its deadline
* Total profit is maximized

---

## **2. Why Greedy Works**

Two key ideas:

### **A. Pick jobs with highest profit first**

Because picking high-profit jobs earlier leaves room for lower profit ones later.

### **B. Schedule each job as late as possible**

To avoid occupying early slots unnecessarily.

These two rules together guarantee optimality.

---

## **3. Strategy (Greedy Choice)**

### **Step 1**

Sort jobs by **profit (descending)**.

### **Step 2**

For each job in sorted order:

* Find the **latest free slot** ≤ deadline
* If available → schedule job there
* Else → skip

Use either:

* Array of size maxDeadline
* DSU (optimized find-slot structure)

---

## **4. ASCII Timeline Example**

Jobs (deadline, profit):
A(4, 20), B(1, 10), C(1, 40), D(1, 30)

Sort by profit: C(40), D(30), A(20), B(10)

Slots: 1 2 3 4

Place C → slot 1
Place D → slot none available → skip
Place A → slot 4
Place B → slot 2

Final jobs = {C, B, A}
Total profit = **70**

---

## **5. Pseudocode (No Code Block)**

jobs.sort by profit decreasing
maxDeadline = max job.deadline
slots = array of size maxDeadline initialized -1

for job in jobs:
for t = job.deadline down to 1:
if slots[t] is empty:
slots[t] = job
break

return sum of profits in slots

---

## **6. Optimized Version (Using DSU)**

Instead of scanning backward for each job, use DSU:

* parent[t] = largest free slot ≤ t
* After occupying t → parent[t] = parent[t-1]

Time complexity reduces to O(N log N).

---

## **7. Complexity Analysis**

| Step                | Complexity         |
| ------------------- | ------------------ |
| Sorting jobs        | O(N log N)         |
| Scheduling (simple) | O(N × maxDeadline) |
| Scheduling (DSU)    | O(N log N)         |
| Space               | O(maxDeadline)     |

---

## **8. Variations**

* Job scheduling with different durations
* Job sequencing with deadlines + penalties
* Minimize lateness (EDD rule)
* Interval scheduling variants

---

## **9. Edge Cases**

* All jobs with same deadline
* Very large deadline values
* Jobs with zero profit
* Gaps in timeline (unused slots allowed)

---

## **10. Interview Tips**

FAANG often tests:

* Jobs + deadlines + profits
* Compare greedy vs DP (for duration > 1)
* Why sorting by profit is essential
* How DSU optimizes slot finding
* Trace the greedy choice manually

Key skills interviewers check:

* Sorting-based greedy reasoning
* Slot allocation
* Understanding exchange argument

---

## **11. Practice Problems**

**LeetCode:**

* 1235 — Weighted Job Scheduling (DP version)
* 630 — Course Schedule III (deadlines + scheduling)

**GFG:**

* Job Sequencing Problem
* Schedule jobs to maximize profit

**Codeforces:**

* Variants with deadlines and task selection
* Greedy scheduling optimization problems

---
