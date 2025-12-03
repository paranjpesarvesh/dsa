# 🧩 Partitioned Bloom Filter (PBF)

A **Partitioned Bloom Filter (PBF)** is a variant of the standard Bloom Filter where the bit array is divided into **k equal-sized partitions**, one for each hash function.
Instead of mapping all hash functions into the entire array, **each hash function maps into its dedicated partition**.

This design improves **cache efficiency** and **reduces correlation** between hash functions, offering more predictable false positive rates.

---

##  Motivation

* In a **standard Bloom Filter**, all `k` hash functions set bits in the same global array.

  * Some bits may be *heavily overloaded*, leading to higher correlation.
  * False positive probability analysis assumes independence, but in practice, correlation reduces accuracy.

* In a **Partitioned Bloom Filter**:

  * Each hash function is restricted to its **own partition**.
  * Reduces overlapping between hash functions.
  * Provides a tighter bound on false positives.

---

## 1. Structure

* Array of size `m` is divided into `k` partitions, each of size `m/k`.
* Each hash function `h_i` maps an element into its partition:

```
Global bit array (m = 12, k = 3 → 3 partitions of size 4):
Partition 1: [0][1][0][0]
Partition 2: [1][0][0][0]
Partition 3: [0][0][1][0]
```

* On **insertion**, one bit is set per partition.
* On **query**, one bit per partition is checked.

---

## 2. Operations

Let:

* `m` = total number of bits
* `k` = number of partitions (and hash functions)
* Partition size = `m / k`

### Insert(x)

```
for i in 0..k-1:
    pos = h_i(x) % (m/k)
    bit_array[i * (m/k) + pos] = 1
```

### Query(x)

```
for i in 0..k-1:
    pos = h_i(x) % (m/k)
    if bit_array[i * (m/k) + pos] == 0:
        return False
return True
```

---

## 3. Mathematical Intuition

### False Positive Probability (FPP)

For Partitioned Bloom Filters:

$$
\text{FPP} = \left(1 - e^{-n/m}\right)^k
$$

* Matches standard Bloom Filter in formula but **closer to real-world behavior** due to partitioning.
* Eliminates correlation issues.

### Optimal Number of Hash Functions

$$
k = \frac{m}{n} \ln 2
$$

Same as classic Bloom Filter.

---

## 4. Complexity

| Operation | Time | Space  |
| --------- | ---- | ------ |
| Insert    | O(k) | m bits |
| Query     | O(k) | m bits |

* Time per operation = proportional to number of hash functions.
* Space = identical to standard Bloom Filter.

---

## 5. Advantages

* **More predictable false positive rate**: avoids correlation bias.
* **Cache friendly**: each partition fits well into memory blocks.
* **Tight analysis**: theoretical FPP matches practice.

---

## 6. Limitations

* Still no support for deletions (unless extended to **Counting Partitioned Bloom Filter**).
* Needs balanced `m/k`. If partitioning is uneven → wasted space.

---

## 7. Visual Comparison

```
Standard Bloom Filter (m = 12, k = 3):
[1][0][1][1][0][1][1][0][0][1][0][1]
(hash functions overlap arbitrarily)

Partitioned Bloom Filter:
Partition 1: [1][0][0][1]
Partition 2: [0][1][1][0]
Partition 3: [1][0][0][0]
(each hash function restricted to its own region)
```

---

## 8. Edge Cases

* **Small m/k values** → high collision probability inside partitions.
* **Skewed hash distribution** → some partitions overloaded.
* **Wrong k** choice → suboptimal FPP.

---

## 9. Applications

* **Networking**: packet filtering, where predictable FPP is crucial.
* **Databases**: query acceleration with reliable membership testing.
* **Caching**: reduces variance in hit/miss predictions.

---

## 10. Interview Tips

* Be ready for:

  * *"Why partition Bloom Filters?"* → for more accurate FPP analysis.
  * *"What changes in formula?"* → same as classic, but with better practical fit.
  * *"Does it reduce space or time?"* → No, only improves accuracy.
* Bonus points: mention cache locality benefits.

---

## 11. Practice Problems

* **LeetCode-style**:

  * Implement Partitioned Bloom Filter and analyze false positives.
  * Compare results against standard Bloom Filter.
* **GFG/Codeforces**:

  * Design a space-efficient data structure with predictable FPP under heavy load.

---

## 12. Summary Table

| Feature                  | Standard Bloom Filter | Partitioned Bloom Filter |
| ------------------------ | --------------------- | ------------------------ |
| Bit array usage          | Global (all k share)  | Partitioned (per hash)   |
| False positives analysis | Approximate           | Accurate                 |
| Cache locality           | Lower                 | Higher                   |
| Space                    | m bits                | m bits                   |
| Delete support           |                      |  (extendable to CBF)    |

---

 **In short:** Partitioned Bloom Filters divide the bit array into equal partitions for each hash function, improving **predictability of false positives** and **cache performance**, without extra memory cost.

---
