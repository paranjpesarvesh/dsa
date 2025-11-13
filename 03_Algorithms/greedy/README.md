# **Greedy Algorithms – Overview & Guide**

---

## **1. What Are Greedy Algorithms?**

A **greedy algorithm** builds a solution step-by-step, always choosing the option that seems **best at the moment**.

Characteristics:

* **Greedy Choice Property**
  Local optimal choice → helps reach global optimum
* **Optimal Substructure**
  Remaining subproblem must also be optimal
* Simple, fast, intuitive
* Often require **sorting** or **priority queues**

Greedy works only when these two properties hold.

---

## **2. When to Use Greedy?**

Greedy is appropriate when:

* Future decisions don’t affect the optimality of current ones
* Problem has a clearly provable optimal local choice
* Exchange argument or structural proof exists
* DP is overkill or too slow

---

## **3. Common Patterns in Greedy Algorithms**

### **A. Interval Scheduling**

* Activity Selection
* Maximum non-overlapping intervals
* Scheduling meetings

### **B. Merging / Combining**

* Huffman Coding
* Minimizing cost of merging files
* Connecting ropes with minimum cost

### **C. Sorting-based Greedy**

* Fractional Knapsack
* Job Scheduling with deadlines
* Largest number construction

### **D. Priority Queue Greedy**

* Dijkstra (conceptually greedy)
* A* heuristic search
* Huffman tree building

### **E. Ratio / Difference / Metric Based**

* Greedy based on:

  * value/weight (Knapsack)
  * profit/time (Scheduling)
  * earliest finish time (Intervals)

---

## **4. Visual Intuition (ASCII Flow)**

Problem → Check properties
↓
Has Greedy Choice Property?
↓ yes / no
If yes → Derive local optimal rule
↓
Sort or use PQ to enforce rule
↓
Build solution incrementally
↓
Verify correctness

---

## **5. Template Pseudocode for Greedy (No Code Block)**

sort or prioritize items based on rule

for each item:
if taking this item is valid:
take it
else:
skip

return result

Almost every greedy algorithm follows this outline.

---

## **6. Strengths of Greedy**

* Very fast (O(N log N) usually)
* Simple to implement
* Works extremely well for:

  * Scheduling
  * Shortest paths (with constraints)
  * Optimization on sorted structures

---

## **7. Limitations**

Greedy **does NOT always give optimal solution**, unless proven.

Fails on:

* 0/1 Knapsack
* Longest path
* Maximum coverage
* Some scheduling problems
* Set cover (needs approximation)

Always check proof before using greedy blindly.

---

## **8. Important Classic Greedy Problems**

| Category    | Problems                            |
| ----------- | ----------------------------------- |
| Intervals   | Activity Selection, Meeting Rooms   |
| Knapsack    | Fractional Knapsack                 |
| Scheduling  | Job Sequencing, Minimizing Lateness |
| Compression | Huffman Coding                      |
| MST / Graph | Prim, Kruskal                       |
| Pathfinding | Dijkstra, A*                        |
| Merging     | Connect ropes, merge stones         |

---

## **9. Interview Tips**

FAANG relies heavily on greedy reasoning:

* Derive the greedy rule — don’t guess
* Use exchange argument to justify correctness
* Handle edge cases explicitly
* Show difference between greedy and DP
* Practice explaining *why* greedy works, not just coding

They often test:

* Activity selection
* Scheduling with deadlines
* Fractional knapsack
* Huffman coding
* Dijkstra (priority-based greedy)

---

## **10. Practice Problems**

**LeetCode:**

* 406 — Queue Reconstruction
* 121 — Best Time to Buy and Sell Stock
* 452 — Minimum Arrows to Burst Balloons
* 502 — IPO

**GFG:**

* Greedy Set of Problems (topic page)
* Job Sequencing
* Fractional Knapsack

**Codeforces:**

* Typical greedy sorting + decision problems
* Tasks involving thresholds, ratios, or prioritization

---
