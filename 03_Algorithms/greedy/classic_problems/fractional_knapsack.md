# **Fractional Knapsack Problem (Greedy Algorithm)**

---

## **1. Problem Definition**

You are given:

* N items
* Each item has:

  * value vi
  * weight wi
* A knapsack with **capacity W**

Unlike 0/1 knapsack, here you may take **fractions** of an item.

### **Goal**

Maximize total value that fits inside the knapsack.

---

## **2. Why Greedy Works for Fractional Knapsack**

Key observation:

**The best strategy is to take items with the highest “value per unit weight” first.**

Sort items by:

ratio = value / weight
(higher is better)

Then greedily take items in decreasing ratio order.

This works because:

* Fractional choice avoids combinatorial constraints
* Value-per-weight ratio locally optimal → globally optimal
* Exchange argument proves correctness

---

## **3. Strategy (Greedy Choice)**

### **Step 1**

Compute value/weight ratio for each item.

### **Step 2**

Sort items by ratio (descending).

### **Step 3**

Iterate:

* If full item fits → take whole
* Else → take fraction that fits
* Stop when capacity = 0

---

## **4. ASCII Illustration**

Items:
Item A: value 60, weight 10 → ratio = 6
Item B: value 100, weight 20 → ratio = 5
Item C: value 120, weight 30 → ratio = 4

Capacity = 50

Sorted: A, B, C
Pick A (10), pick B (20), remaining capacity = 20.
Take 20/30 = 2/3 of C → value = 80.

Total = 60 + 100 + 80 = **240**

---

## **5. Pseudocode (No Code Block)**

for each item:
ratio[i] = value[i] / weight[i]

sort items by ratio decreasing

totalValue = 0
remaining = W

for each item (val, wt, ratio):
if wt <= remaining:
totalValue += val
remaining -= wt
else:
totalValue += ratio * remaining
break

return totalValue

---

## **6. Complexity**

| Step      | Complexity                              |
| --------- | --------------------------------------- |
| Sorting   | O(N log N)                              |
| Loop      | O(N)                                    |
| **Total** | **O(N log N)**                          |
| Space     | O(1) or O(N)** (depending on structure) |

---

## **7. Variations**

* 0/1 Knapsack → DP required
* Multiple knapsacks
* Maximize weight/value depending on constraints
* Integer knapsack (no fraction allowed)

---

## **8. Edge Cases**

* Items with zero weight → treat carefully (infinite ratio)
* Capacity smaller than smallest weight → take fraction of best item
* All items fit completely → sum of values
* Negative values → usually not allowed

---

## **9. Interview Tips**

Expect questions like:

* Explain why greedy works here but not in 0/1 knapsack
* Manually compute ratio and execute steps
* Handle fractional part accurately
* Compare with dynamic programming knapsack

FAANG uses this to test:

* Greedy correctness reasoning
* Sorting + simulation
* Handling decimals/precision

---

## **10. Practice Problems**

**LeetCode:**

* 1705 — Maximum Number of Eaten Apples (similar greedy structure)

**GFG:**

* Fractional Knapsack
* Greedy scheduling problems

**Codeforces:**

* Problems involving “gain per cost”
* Ratio-based greedy optimizations

---
