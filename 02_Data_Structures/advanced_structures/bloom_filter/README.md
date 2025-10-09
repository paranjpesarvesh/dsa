## 🔹 Introduction

A **Bloom Filter** is a **probabilistic data structure** designed to test **set membership** efficiently.
It can tell if an element is **definitely not in the set** or **probably in the set** (false positives are possible, false negatives are not).

This makes Bloom Filters ideal for applications where:
- Memory efficiency is crucial.
- Small probability of error is acceptable.
- Dataset size is very large.

---

## 🔹 Real-world Applications

- **Databases**: Quickly checking if a key exists before disk lookup (e.g., Cassandra, Bigtable, HBase).
- **Web caching**: Testing if a URL is already cached.
- **Compilers**: Checking whether a variable/identifier exists in a set.
- **Networking**: Packet routing, malicious IP detection.
- **Search Engines**: Fast URL deduplication.

---

## 🔹 Core Idea

A Bloom Filter uses:
1. A **bit array** of size `m`, initially all `0`.
2. **k independent hash functions** mapping an element to `k` positions in the bit array.

**Insert(x):**
- Compute `k` hashes.
- Set those positions to `1`.

**Query(x):**
- Compute `k` hashes.
- If all bits are `1` → "probably in set".
- If any bit is `0` → "definitely not in set".

---

## 🔹 Visual Intuition

### Example with `m = 10`, `k = 3`

Insert `"dog"`:

```

Initial bit array:
\[0 0 0 0 0 0 0 0 0 0]

Hashes of "dog" → indices \[2, 5, 7]
\[0 0 1 0 0 1 0 1 0 0]

```

Insert `"cat"` (hashes → [1, 4, 7]):

```

\[0 1 1 0 1 1 0 1 0 0]

````

Query `"dog"` → check [2, 5, 7] → all `1` → probably in set.

Query `"bat"` → suppose hashes = [0, 3, 6] → one bit is `0` → definitely not in set.

---

## 🔹 Mathematical Intuition

- For a Bloom Filter storing `n` elements with `m` bits and `k` hash functions:

**False Positive Probability (FPP):**
\[
P = \left(1 - e^{-kn/m}\right)^k
\]

**Optimal `k`:**
\[
k = \frac{m}{n} \ln 2
\]

**Bit array size `m`:**
\[
m = - \frac{n \cdot \ln p}{(\ln 2)^2}
\]

where `p` is the desired false positive rate.

---

## 🔹 Algorithm (Pseudocode)

```text
function INSERT(item):
    for i in 1..k:
        position = hash_i(item) % m
        bit_array[position] = 1

function QUERY(item):
    for i in 1..k:
        position = hash_i(item) % m
        if bit_array[position] == 0:
            return "Not in set"
    return "Probably in set"
````

---

## 🔹 Complexity

| Operation | Time Complexity                | Space Complexity |
| --------- | ------------------------------ | ---------------- |
| Insert    | O(k)                           | O(m) bits        |
| Query     | O(k)                           | O(m) bits        |
| Delete    | ❌ Not supported in standard BF |                  |

* Usually, `k` is small (≈ 7–10), so operations are near **O(1)**.

---

## 🔹 Variations of Bloom Filters

1. **Counting Bloom Filter**

   * Uses counters instead of bits.
   * Supports **deletions**.

2. **Partitioned Bloom Filter**

   * Splits bit array into `k` disjoint parts.
   * Each hash maps into one partition → better uniformity.

3. **Scalable Bloom Filter**

   * Dynamically grows with dataset.
   * Maintains bounded false positive rate.

4. **Compressed Bloom Filter**

   * Stores in compressed form to save network/memory bandwidth.

---

## 🔹 Edge Cases

* Duplicate insertions → harmless (sets same bits again).
* Deletions → not possible in classic Bloom Filter (false negatives risk).
* If too many elements are inserted beyond expectation → FPP increases drastically.

---

## 🔹 Interview Tips

* Common FAANG system design interview topic:
  *"Design a membership-checking system for billions of URLs with limited memory."*

* Key talking points:

  * Why not use a HashSet? (Memory heavy).
  * Trade-off between memory and accuracy.
  * Bloom Filter → probabilistic, compact, fast.
  * Discuss variants if **deletion** or **scalability** is needed.

* GATE/Academia:
  Questions on false positive probability, optimal `k`, and expected memory usage.

---

## 🔹 Practice Problems

* [GeeksforGeeks - Introduction to Bloom Filters](https://www.geeksforgeeks.org/bloom-filters-introduction-and-python-implementation/)
* [LeetCode System Design Practice — Design Search Autocomplete](https://leetcode.com/)
* \[Design a Scalable Membership Test System — System Design Interview Prep]

---

## 🔹 Summary Table

| Feature            | Bloom Filter            |
| ------------------ | ----------------------- |
| Exact membership   | ❌ No                    |
| False negatives    | ❌ No                    |
| False positives    | ✅ Possible              |
| Space efficiency   | ✅ Very high             |
| Supports deletion  | ❌ (only in counting BF) |
| Scales dynamically | ❌ (only scalable BF)    |

---

## 🔹 Repo Subdirectory Structure

```
bloom_filter/
│── README.md                  # Theory and overview
│── basic_bloom_filter.py      # Standard Bloom Filter implementation
│── variations/
│   ├── counting_bloom_filter.md
│   ├── counting_bloom_filter.py
│   ├── partitioned_bloom_filter.md
│   ├── partitioned_bloom_filter.py
│   ├── scalable_bloom_filter.md
│   ├── scalable_bloom_filter.py
```

---
