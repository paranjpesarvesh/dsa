##  Introduction

A **Scalable Bloom Filter (SBF)** is an extension of the classic Bloom Filter designed to handle **growing datasets** without a predefined size.

Unlike standard Bloom Filters (which require knowing the number of elements in advance and suffer increasing false positive rates as they fill up), SBFs **scale dynamically by adding new filters** while maintaining a bounded false positive probability.

---

##  Core Idea

- **Standard Bloom Filter Limitation**:
  Needs expected number of insertions `n` beforehand. If more elements are inserted, the false positive probability (FPP) grows beyond the desired threshold.

- **Scalable Bloom Filter Solution**:
  1. Maintain **multiple Bloom Filters (layers)**.
  2. Each new layer has:
     - Higher capacity (using a growth factor).
     - Tighter false positive rate (using an error tightening ratio).
  3. When the current filter becomes “full”, a new one is created.

---

##  Mathematical Intuition

- For a single Bloom Filter with:
  - `n` = expected inserts
  - `m` = number of bits
  - `k` = number of hash functions
  - Target false positive probability `p`

  Optimal choices are:
  \[
  m = -\frac{n \cdot \ln(p)}{(\ln 2)^2}, \quad
  k = \frac{m}{n} \ln 2
  \]

- In a **Scalable Bloom Filter**:
  - First filter has target error `p0`.
  - Next filters tighten error probability geometrically:
    \[
    p_i = p_0 \cdot r^i
    \]
    where `0 < r < 1` is the **tightening ratio**.

- Overall false positive probability:
  \[
  P_{total} = 1 - \prod_{i}(1 - p_i)
  \]
  which ensures bounded FPP.

---

##  Structure

```

Scalable Bloom Filter
|
\|-- Layer 0: BloomFilter(capacity = C, error = p0)
\|-- Layer 1: BloomFilter(capacity = C \* growth, error = p1 = p0 \* r)
\|-- Layer 2: BloomFilter(capacity = C \* growth^2, error = p2 = p0 \* r^2)
\|-- ...

```

ASCII Visualization:

```

+---------------------------+
\| Bloom Filter Layer 0      |  capacity = 1000, p0 = 0.01
+---------------------------+
↓ (full)
+---------------------------+
\| Bloom Filter Layer 1      |  capacity = 2000, p1 = 0.005
+---------------------------+
↓ (full)
+---------------------------+
\| Bloom Filter Layer 2      |  capacity = 4000, p2 = 0.0025
+---------------------------+

```

---

##  Algorithm (Step-by-step)

### Insert
1. Insert into the **latest layer**.
2. If it is full:
   - Create a new Bloom Filter with:
     - `capacity_new = capacity_old * growth`
     - `error_new = error_old * r`
   - Insert element into the new filter.

### Query
1. Check all layers (from newest to oldest).
2. If any filter reports "might contain", return **True**.
3. Else, return **False**.

---

##  Pseudocode

```text
function ADD(item):
    last_layer = layers[-1]
    if last_layer.is_full():
        new_capacity = last_layer.capacity * growth_factor
        new_error = last_layer.error * tightening_ratio
        new_layer = BloomFilter(new_capacity, new_error)
        layers.append(new_layer)
    layers[-1].insert(item)


function CONTAINS(item):
    for layer in reverse(layers):
        if layer.might_contain(item):
            return True
    return False
```

---

##  Complexity Analysis

| Operation | Complexity                            |
| --------- | ------------------------------------- |
| Insert    | O(k) (in newest layer)                |
| Query     | O(L \* k), where L = number of layers |
| Space     | O(Σ m\_i), sum of bits across layers  |

* Typically, `L = O(log n)` where `n` is the total number of elements.
* Thus, queries remain efficient even with millions of elements.

---

##  Variations

1. **Counting Scalable Bloom Filter**
   Allows deletions by using **counters instead of bits**.

2. **Compressed Scalable Bloom Filter**
   Stores bit arrays in compressed format to save space.

3. **Partitioned Scalable Bloom Filter**
   Splits bit array into `k` disjoint parts (reduces hash collisions).

---

##  Edge Cases

* **Empty SBF**: No filters → must initialize first filter.
* **Duplicate Inserts**: Harmless (still sets the same bits).
* **Very Large Datasets**: Too many layers may make queries slower (optimize by caching).

---

##  Interview Tips

* FAANG often asks: *"How would you design a data structure for membership testing in a growing dataset?"*
* Key discussion points:

  * Why normal Bloom Filter fails (capacity issue).
  * How Scalable Bloom Filter solves it (layered structure).
  * Complexity and trade-offs (space vs false positives).
* Common follow-up: *"How would you allow deletions?"* → Introduce **Counting Bloom Filters**.

---

##  Practice Problems

* [LeetCode 355 - Design Twitter](https://leetcode.com/problems/design-twitter/) (can use SBF-like ideas for scalable feed caching).
* [GeeksforGeeks - Introduction to Bloom Filter](https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/)
* \[Design a Scalable Membership Testing System - System Design Interviews]

---

##  Summary Table

| Feature                | Standard Bloom Filter | Scalable Bloom Filter |
| ---------------------- | --------------------- | --------------------- |
| Needs `n` in advance   |  Yes                 |  No                  |
| Fixed size             |  Yes                 |  No (grows)          |
| Supports deletions     |  No                  |  (unless counting)   |
| False Positive Control |  Increases with n    |  Bounded             |

---
