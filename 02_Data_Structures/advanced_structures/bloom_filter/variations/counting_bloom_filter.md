# 🔢 Counting Bloom Filter (CBF)

A **Counting Bloom Filter (CBF)** is a **variant of the standard Bloom Filter** that supports **deletions** in addition to insertions and queries. It does this by replacing the bit array with an **array of small integer counters**.

This solves one of the major limitations of Bloom Filters: **inability to remove elements**.

---

## ✅ Motivation

* **Standard Bloom Filter**: Only supports `Insert` and `Query`. Deletion is impossible because clearing a bit might remove evidence of other elements that also mapped to that bit.
* **Counting Bloom Filter**: Replaces each bit with a counter that increments on insert and decrements on delete. A bit is considered set if its counter > 0.

---

## 1. Structure

* Instead of an array of `m` bits, we use an array of `m` **counters**.
* Each counter is usually 4–8 bits wide (to save memory).
* For each element:

  * On insertion: increment counters at positions given by `k` hash functions.
  * On deletion: decrement counters at those positions.
  * On query: check if all `k` counters > 0.

---

### ASCII Diagram

```
Classic Bloom Filter (bit array):
[0][0][1][1][0][1][0][0]

Counting Bloom Filter (counter array):
[0][1][2][1][0][1][0][0]
```

If element `X` is inserted twice, counters increase accordingly. If deleted once, counters decrease.

---

## 2. Core Operations

Let:

* `m` = total counters
* `k` = number of hash functions
* `c[]` = counter array of size `m`

### Insert(x)

For each hash function `h_i`:

```
pos = h_i(x) % m
c[pos] += 1
```

### Query(x)

For each hash function `h_i`:

```
pos = h_i(x) % m
if c[pos] == 0:
    return False
return True
```

### Delete(x)

For each hash function `h_i`:

```
pos = h_i(x) % m
if c[pos] > 0:
    c[pos] -= 1
```

---

## 3. Mathematical Analysis

### False Positives

* Similar to a standard Bloom Filter:

$$
\text{FPP} \approx \left(1 - e^{-kn/m}\right)^k
$$

* Partitioning doesn’t change the false positive probability, but **counters reduce false negatives risk from accidental clearing**.

### False Negatives

* Standard BF: *never produces false negatives*.
* Counting BF: If counters **overflow** or **decrement incorrectly**, false negatives can occur. This is the main drawback.

---

## 4. Complexity

| Operation | Time | Space              |
| --------- | ---- | ------------------ |
| Insert    | O(k) | `m * counter_size` |
| Query     | O(k) | same               |
| Delete    | O(k) | same               |

* If each counter is `b` bits wide, space = `m * b`.
* For small `b` (like 4 bits), risk of counter overflow → mitigation needed.

---

## 5. Variations

* **Bounded CBF**: Uses saturated counters (max value capped at `2^b - 1`).
* **Approximate Deletion CBF**: Uses probabilistic decrement strategies to avoid overflow.
* **Hierarchical / Decaying CBF**: Used in networking to track flows with decay over time.

---

## 6. Pseudocode

```text
function insert(x):
    for i in 0..k-1:
        pos = hash(x, i) % m
        c[pos] += 1

function query(x):
    for i in 0..k-1:
        pos = hash(x, i) % m
        if c[pos] == 0:
            return False
    return True

function delete(x):
    for i in 0..k-1:
        pos = hash(x, i) % m
        if c[pos] > 0:
            c[pos] -= 1
```

---

## 7. Edge Cases & Pitfalls

1. **Counter Overflow**:

   * If too many duplicates inserted, counters may exceed `2^b - 1`.
   * Overflow causes incorrect deletions → false negatives.

2. **Concurrent Updates**:

   * Multi-threaded inserts/deletes must use atomic increments/decrements.

3. **High Memory Overhead**:

   * CBFs require more memory than standard Bloom Filters (because of counters).

---

## 8. Real-World Applications

* **Networking**: Tracking active flows (e.g., packet filtering).
* **Databases**: Supporting deletions in cache/membership checks.
* **Security**: Intrusion detection systems (with dynamic updates).

---

## 9. Interview Tips

* Expect to be asked:

  * *“Why can’t we delete in standard Bloom Filters?”*
  * *“How does CBF solve this?”*
  * *“What new problems does it introduce?”* (overflow, false negatives).
* Be able to derive the FPP formula.
* Mention practical trade-offs: **more memory but enables deletions**.
* If asked to implement: focus on array of counters, not bits.

---

## 10. Practice Problems

* **LeetCode / GFG style**:

  1. Design a data structure supporting insert, query, and delete with space efficiency (→ implement CBF).
  2. Given `n`, `m`, and `k`, simulate false positive probability in CBF.
  3. Extend CBF to support "frequency estimation" of elements.

---

## 11. Summary Table

| Feature         | Standard Bloom Filter | Counting Bloom Filter |
| --------------- | --------------------- | --------------------- |
| Insert          | Yes                   | Yes                   |
| Query           | Yes                   | Yes                   |
| Delete          | ❌ No                  | ✅ Yes                 |
| False Positives | Yes                   | Yes                   |
| False Negatives | No                    | Possible (overflow)   |
| Space per cell  | 1 bit                 | `b` bits (counter)    |

---

🚀 **In short:** Counting Bloom Filters extend Bloom Filters to support deletions by using counters instead of bits. This enables dynamic workloads but comes with higher memory usage and risk of overflow.

---
