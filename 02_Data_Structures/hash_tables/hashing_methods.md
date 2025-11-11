# Hashing Methods – Theory, Strategies, and Comparison

This file explains **different hashing methods**, how they work, their pros/cons, and when to use each. It is meant to give you a strong conceptual foundation for implementing and debugging hash-based structures.

---

# 1. What Is Hashing?

Hashing maps a key to an index in an array using a hash function.

Hash function:

h(key) = index

Goal:

* fast lookup
* fast insert
* fast delete

Average time: O(1)

Worst-case time: O(n)

---

# 2. Good Hash Function Characteristics

A good hash function should:

* distribute keys uniformly
* minimize collisions
* be fast to compute
* avoid clustering

Example:

For integers: h(k) = k % m
(m ideally a prime or power-of-two, depending on use-case)

---

# 3. Hashing Methods Overview

### Collision handling strategies

1. **Open Addressing**
2. **Separate Chaining**
3. **Perfect Hashing** (special case)
4. **Double Hashing**
5. **Quadratic Probing**
6. **Cuckoo Hashing**

Each has tradeoffs.

---

# 4. Separate Chaining

### Concept

Each index of the hash table stores a linked list or vector of all elements that hash to the same index.

Visual Aid:

```
table[0]:  15 -> 22 -> 37
table[1]:  EMPTY
table[2]:  5 -> 12
```

### Pros

* simple, scalable
* performance good when load factor α < 1
* deletion easy

### Cons

* memory overhead of pointers
* performance degrades if lists grow

### Complexity

* Average: O(1)
* Worst: O(n)

### Used In

* C++ std::unordered_map
* Java HashMap (with red-black trees for long chains)

---

# 5. Open Addressing

### Idea

When a collision occurs, try a different position.

Core formulas:

index = (h(key) + probe(i)) % m

Probe(i) varies with technique.

### Subtypes

#### 1. Linear Probing

probe(i) = i

Next slot:

idx, idx+1, idx+2, ...

Pros:

* cache-friendly
* simple to implement

Cons:

* primary clustering

#### 2. Quadratic Probing

probe(i) = i²

Next slot:

idx, idx+1², idx+2², ...

Fixes clustering, but may skip some slots.

#### 3. Double Hashing

probe(i) = i * h2(key)

Two hash functions:

h1(key) = key % m
h2(key) = 1 + (key % (m-1))

Pros:

* reduces clustering
* good distribution

Cons:

* more complex
* requires careful choice of h2

---

# 6. Load Factor

Load factor α = n / m

Where:

* n = number of keys
* m = capacity

Rules:

* α < 0.7 usually maintains O(1)
* too high → many collisions
* too low → wasted memory

Most hash tables resize automatically.

---

# 7. Perfect Hashing

Used when:

* keys known in advance
* static datasets

Guarantees O(1) lookup with no collisions (two-level hashing).
Used in compilers, symbol tables.

---

# 8. Cuckoo Hashing

### Idea

Two hash tables, two hash functions.

If a collision happens:

* kick the existing element out
* move it to its alternate hash location

This continues until stable.

Pros:

* constant worst-case lookup
* no chains

Cons:

* insertion may require rehashing
* complex to implement

---

# 9. Mathematical Intuition: Avoiding Clusters

Clustering happens when:

* bad hash function
* many collisions
* probing pattern causes grouping

Uniform hashing assumption:
each key independently chooses a random slot.

Expected probe length: O(1/(1-α))

So as α approaches 1:

cost → infinite

This is why resizing is crucial.

---

# 10. Choosing a Hash Method (Decision Guide)

### If memory is tight

Use **open addressing**.

### If deletions are frequent

Use **separate chaining**.

### If latency critical

Use **linear probing** (cache-friendly).

### If keys known ahead

Use **perfect hashing**.

### If want worst-case O(1)

Use **cuckoo hashing**.

---

# 11. Pseudocode (Generic Hash Insert)

Here is a generic separate-chaining insert:

```
function insert(key):
    index = hash(key)
    if table[index] does not have key:
        append key to table[index]
```

Open addressing (linear probing):

```
function insert(key):
    index = hash(key)
    while table[index] occupied:
        index = (index + 1) mod m
    table[index] = key
```

---

# 12. Interview Tips

1. Always mention load factor and resizing.
2. Know the difference between chaining and open addressing.
3. Understand primary vs secondary clustering.
4. For theoretical problems, mention uniform hashing assumption.
5. For coding interviews, focus on:

   * insert
   * search
   * delete
   * handling collisions

---

# 13. Practice Problems

### Beginner

* Implement hash table from scratch
* Find first non-repeating character
* Check if arrays are equal using hashing

### Intermediate

* Two Sum → hash map
* Subarray with sum = k
* Longest substring without repeating characters

### Advanced

* Implement LRU Cache (map + doubly linked list)
* Grouping anagrams
* Count distinct elements in sliding window

---
