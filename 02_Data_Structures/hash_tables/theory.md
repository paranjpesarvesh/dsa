# Hash Tables – Theory and Deep Understanding

Hash tables are one of the most powerful data structures in computer science. They provide **average O(1)** operations for insertion, deletion, and search, making them essential for interview problems involving frequency counting, membership testing, and fast lookups.

This document explains the core theory behind hash tables, their internal mechanics, and collision-handling approaches.

---

# 1. What Is a Hash Table?

A hash table is a data structure that maps **keys** to **values** using:

* an underlying array (bucket array)
* a hash function
* a collision-handling strategy

Basic operations:

* insert(key, value)
* search(key)
* delete(key)

Expected time: O(1)

Worst-case time: O(n)

---

# 2. Hash Function

A hash function maps a key to an index in a fixed-size array.

index = h(key)

A good hash function must be:

* deterministic
* fast to compute
* uniformly distributing keys
* low collision probability

### Example (for integers)

h(k) = k % m

Where m is table size.

### Example (for strings)

Polynomial rolling hash:

h(s) = s[0]*p^0 + s[1]*p^1 + ... + s[n-1]*p^{n-1} mod m

Common choices:

* p = 31 or 53
* m = large prime (≈ 10^9+7)

---

# 3. Collisions

Two different keys hash to same index.

h(k1) = h(k2)

Collisions are **inevitable** due to the pigeonhole principle.

Hence, hash tables need collision resolution.

---

# 4. Collision Resolution Methods

Two major families:

## 4.1 Separate Chaining

Each table index stores a linked list (or dynamic array) of all keys hashed to it.

Visual representation:

```
table[0] → 10 → 20
table[1] → 25
table[2] → EMPTY
table[3] → 18 → 42 → 66
```

Pros:

* simple
* deletion easy
* efficient when load factor < 1

Cons:

* pointer overhead
* worst-case O(n)

---

## 4.2 Open Addressing

Store keys directly in the table.
If a collision occurs, probe for another slot.

### Types of probing:

1. Linear probing
2. Quadratic probing
3. Double hashing

---

### Linear Probing

probe(i) = i

Sequence:

idx, idx+1, idx+2, ...

Advantages:

* very cache friendly
* easy implementation

Disadvantages:

* primary clustering

---

### Quadratic Probing

probe(i) = i²

Sequence:

idx, idx+1², idx+2², idx+3² ...

Pros:

* reduces clustering

Cons:

* may fail to find free slot unless load factor low

---

### Double Hashing

Two hash functions:

h1(k) = k % m
h2(k) = 1 + (k % (m-1))

Next index:

index = (h1(k) + i*h2(k)) % m

Pros:

* minimizes clustering
* good distribution

Cons:

* slightly more complex

---

# 5. Load Factor

Load factor α = n / m

Where:

* n = number of elements
* m = size of table

Effects:

* low α → fast, memory waste
* high α → many collisions, slow performance

Typical resizing strategies:

* double size when α > 0.7
* rehash all elements into new table

---

# 6. Time Complexity

| Operation | Average | Worst |
| --------- | ------- | ----- |
| insert    | O(1)    | O(n)  |
| search    | O(1)    | O(n)  |
| delete    | O(1)    | O(n)  |

Worst-case happens when:

* many collisions occur
* bad hash function
* poor probing strategy
* no resizing

---

# 7. Mathematical Intuition

Uniform hashing assumption:

Every key equally likely to map to any slot independently.

Average number of probes under open addressing:

Expected probes ≈ 1 / (1 − α)

So as α → 1:

probes → infinite

This illustrates why resizing is essential.

---

# 8. Visual Illustrations

### Structure of a hash table

```
+----------------------------+
|   |   |   |   |   |   |   |
+----------------------------+
  0   1   2   3   4   5   6
```

### Collision via chaining

```
0:  12 → 22 → 42
1:  7
2:  EMPTY
```

### Linear probing

For key=18:

```
h(18)=4
table[4] occupied
try 5
table[5] occupied
try 6
table[6] empty → insert
```

---

# 9. Common Mistakes

1. Choosing poor hash function (e.g., h(k)=k%10 for clustered keys)
2. Forgetting resizing logic
3. Implementing linear probing without wrap-around
4. Deleting incorrectly in open addressing
5. Using hash tables for sorted outputs (not appropriate)

---

# 10. Interview Tips

* Always mention load factor and resizing.
* Know collision methods clearly.
* Mention pros/cons of chaining vs open addressing.
* Understand clustering types:

  * primary clustering (linear probing)
  * secondary clustering (quadratic probing)
* Be comfortable with real-world hashmap implementation.
* Hashing is used heavily in:

  * frequency counting
  * duplicate detection
  * sliding window
  * string hashing
  * grouping problems

---

# 11. Practice Problems (Recommended)

### Easy

* Two Sum (LeetCode)
* Contains Duplicate
* First Unique Character
* Intersection of Two Arrays

### Medium

* Longest Substring Without Repeating Characters
* Subarray Sum Equals K
* Group Anagrams
* Longest Consecutive Sequence

### Hard

* LRU Cache (design)
* LFU Cache (design)
* Consistent Hashing
* Rolling Hash problems (Rabin-Karp)

---
