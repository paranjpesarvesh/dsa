#  Bloom Filter — Theory

---

##  What is a Bloom Filter?

A **Bloom Filter** is a **probabilistic data structure** designed to test whether an element is part of a set.
It guarantees **no false negatives** (if it says "not present," it is definitely not present) but allows **false positives** (it might say "present" even if it is not).

This makes it ideal when:
- Memory efficiency is critical.
- Some probability of error is tolerable.
- Speed is important.

---

##  Why Use Bloom Filters?

- Traditional structures like **HashSet / TreeSet** provide exact answers but require **O(n)** memory.
- Bloom Filters use a **bit array** + **multiple hash functions** to store set membership in **much smaller memory**.
- Widely used in **databases, distributed systems, and networking**.

---

##  Core Concepts

### Components:
1. **Bit Array (`m` bits):** Initially all `0`.
2. **Hash Functions (`k` independent functions):** Map elements to multiple positions in the bit array.

---

##  How It Works

### Insertion
- Hash the element with `k` hash functions.
- Set the corresponding positions in the bit array to `1`.

### Query
- Hash the element with the same `k` hash functions.
- If **all bits are 1** → "probably in set".
- If **any bit is 0** → "definitely not in set".

---

##  Example Walkthrough

Suppose:
- Bit array size `m = 10`
- Hash functions `k = 3`
- Insert `"dog"` and `"cat"`

**Step 1: Insert `"dog"`**
```

Initial:   \[0 0 0 0 0 0 0 0 0 0]
Hashes →   \[2, 5, 7]
After:     \[0 0 1 0 0 1 0 1 0 0]

```

**Step 2: Insert `"cat"`**
```

Hashes →   \[1, 4, 7]
After:     \[0 1 1 0 1 1 0 1 0 0]

```

**Query `"dog"`**
- Hashes → [2, 5, 7] → all 1 → probably in set.

**Query `"bat"`**
- Hashes → [0, 3, 6] → bit 0 → not in set.

---

##  ASCII Visualization

```

Bit Array (m=10):

Index:   0 1 2 3 4 5 6 7 8 9
Array:   0 1 1 0 1 1 0 1 0 0
↑   ↑   ↑
"dog" and "cat" hashes

```

---

##  Mathematical Analysis

### False Positive Probability (FPP)

If `n` elements are inserted into a Bloom Filter with:
- `m` = number of bits
- `k` = number of hash functions

Probability a bit remains `0` after `n` insertions:
\[
P(0) = \left(1 - \frac{1}{m}\right)^{kn}
\]

Probability a bit is `1`:
\[
P(1) = 1 - P(0) = 1 - \left(1 - \frac{1}{m}\right)^{kn}
\]

False Positive Probability:
\[
FPP = \left(1 - e^{-kn/m}\right)^k
\]

### Optimal Number of Hash Functions

To minimize FPP:
\[
k = \frac{m}{n} \ln 2
\]

### Required Bit Array Size

For desired FPP `p`:
\[
m = -\frac{n \ln p}{(\ln 2)^2}
\]

---

##  Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| Insert    | O(k)            | O(m) bits        |
| Query     | O(k)            | O(m) bits        |

Since `k` is usually small (~7–10), both are **effectively O(1)**.

---

##  Edge Cases

- **Overfilled filter** → too many elements cause high false positive rate.
- **Deletions not possible** in standard Bloom Filters.
- **Duplicates** → harmless (just set same bits again).

---

##  Variations

1. **Counting Bloom Filter**
   - Uses counters instead of bits → supports deletion.

2. **Partitioned Bloom Filter**
   - Divides bit array into `k` partitions. Each hash selects one partition.

3. **Scalable Bloom Filter**
   - Expands dynamically when dataset grows beyond expected size.

4. **Compressed Bloom Filter**
   - Optimized for transmission/storage in low-bandwidth environments.

---

##  Pseudocode

```text
function INSERT(item):
    for i in 1..k:
        idx = hash_i(item) % m
        bit_array[idx] = 1

function QUERY(item):
    for i in 1..k:
        idx = hash_i(item) % m
        if bit_array[idx] == 0:
            return "Not in set"
    return "Probably in set"
```

---

##  Interview Tips

* **FAANG System Design**:
  Asked in caching/distributed systems → "How to efficiently check membership with limited memory?"

* **Key discussion points**:

  * Memory vs accuracy tradeoff.
  * False positives vs false negatives.
  * Variants (Counting/Scalable) when deletion or dynamic scaling needed.

* **GATE/Academia**:
  Expect formula-based questions: false positive rate, optimal `k`, required memory size.

---

##  Practice Problems

* [GeeksforGeeks — Bloom Filter](https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/)
* [LeetCode — Design Randomized Set (similar concept)](https://leetcode.com/problems/insert-delete-getrandom-o1/)
* \[Codeforces — Data Structures + Probabilistic Problems]

---

##  Summary Table

| Feature           | Bloom Filter                     |
| ----------------- | -------------------------------- |
| Exact membership  |  No                             |
| False negatives   |  No                             |
| False positives   |  Yes                            |
| Space efficiency  |  High                           |
| Supports deletion |  Standard (only in Counting BF) |
| Scalable          |  (only Scalable BF)             |

---

 Bloom Filters are a **cornerstone of probabilistic data structures** → fast, space-efficient, and widely used in **large-scale systems**.

---
