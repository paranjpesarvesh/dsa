# **Greedy Algorithms – Theory & Foundations**

---

## **1. What Is a Greedy Algorithm?**

A **greedy algorithm** builds a solution step-by-step by always making the **locally optimal choice**, hoping it leads to a **globally optimal** solution.

It does NOT reconsider earlier choices.

Greedy =
*Local optimization + Structural correctness*
→ *Global optimality*

---

## **2. Two Essential Properties (Must Hold)**

A problem is solvable using greedy if and only if:

### **1. Greedy Choice Property**

Choosing the locally optimal option should be part of the globally optimal solution.

Greedy tries:
“Take the best thing now.”

### **2. Optimal Substructure**

The optimal solution to the whole problem contains optimal solutions to its subproblems.

Same concept as Dynamic Programming, but DP allows revisiting choices while greedy doesn’t.

---

## **3. Why Greedy Works (Mathematical Intuition)**

Greedy correctness is typically proven using:

### **A. Exchange Argument**

Show that any optimal solution can be transformed into the greedy solution by swapping decisions **without reducing optimality**.

### **B. Structural Proof**

Show the optimal solution retains greedy structure after removing the first chosen element.

### **C. Monotonicity**

The "best" choice does not become worse in future steps.

---

## **4. Visual Intuition (ASCII Diagram)**

Decision Sequence:

Greedy picks:
Step 1 → best local
Step 2 → best local among remaining
Step 3 → best local among remaining
...

Diagram of greedy selection:

Choices:  [ A  B  C  D  E ]
Scores :  [ 9  7  5  3  1 ]

Greedy picks: A → B → C …

DP would try all combinations, but greedy sticks to the top choice every time.

---

## **5. Common Patterns in Greedy Problems**

### **A. Interval Scheduling**

* Activity Selection
* Meeting rooms
* Maximum non-overlapping intervals

### **B. Ratio-Based Choice**

* Fractional Knapsack
* Maximize efficiency / minimize cost

### **C. Priority Queue Greedy**

* Huffman Coding
* Dijkstra’s
* A* Search

### **D. Sorting-Based Construction**

* Job Scheduling
* Min arrows to burst balloons
* Merge intervals

### **E. Merging / Minimization**

* Connect ropes with minimum cost
* Merge stones

---

## **6. Greedy Algorithm Template**

(No code block as requested)

sort items by greedy decision rule

answer = empty

for each item in sorted order:
if item is valid choice:
take item
else:
skip

return answer

Most greedy programs follow this template with a specific "valid choice" and sorting rule.

---

## **7. Complexity Overview**

Usually:

* Sorting → **O(N log N)**
* Selection → **O(N)**
* Total → **O(N log N)**

Priority queue versions → O(N log N)

Greedy is almost always faster than DP or backtracking for the same problems.

---

## **8. Variations of Greedy**

* **Pure greedy** – always optimal
* **Approximation greedy** – used when optimal is NP-hard
* **Adaptive greedy** – decisions change dynamically
* **Multi-criteria greedy** – multiple sorting rules

---

## **9. Edge Cases in Greedy**

* Multiple optimal choices → pick any
* Equal weights/ratios → tie-breaking needed
* Negative values → may break greedy correctness
* Dependencies between choices → greedy fails
* Time windows or deadlines → need scheduling strategy

---

## **10. How Greedy Is Tested in FAANG**

Interviewers expect you to:

1. Identify **when greedy works**
2. Justify greedy choice using exchange argument
3. Implement the sorting/PQ-based solution cleanly
4. Handle intervals and deadlines confidently
5. Compare greedy vs DP
6. Solve small examples manually

Classic FAANG greedy topics:

* Activity selection
* Non-overlapping intervals
* Dijkstra (priority greedy)
* Fractional knapsack
* Huffman coding
* Minimum jumps / local optimum choices

---

## **11. Practice Problems**

**LeetCode:**

* 452 — Minimum Number of Arrows
* 121 — Best Time to Buy/Sell Stock
* 135 — Candy Distribution
* 763 — Partition Labels
* 502 — IPO

**GFG:**

* Greedy set of problems
* Job Sequencing
* Fractional Knapsack

**Codeforces:**

* Typical greedy sorting tasks
* Ratio/difference-driven choices
* Scheduling with constraints

---
