# Hash Tables – Concepts, Operations, and Interview Guide

Hash tables are one of the most essential data structures for achieving **constant-time average lookup, insertion, and deletion**. They are widely used in language libraries (Python dict, C++ unordered_map, Java HashMap) and in countless interview problems.

This document provides a clear, structured guide to hashing and hash tables for interview preparation.

---

# 1. What Is a Hash Table?

A hash table stores key-value pairs and supports:

* insertion
* search
* deletion

All in average O(1) time.

### Core Idea

Use a **hash function** to map a key to an index in an array:

index = h(key)

Example:

If key = 42 and table size = 10:

h(42) = 42 % 10 = 2
Store key/value at table[2].

---

# 2. Hash Function

A good hash function must be:

* fast
* uniformly distributing keys
* deterministic
* minimizing collisions

Common choices:

* modulo hashing
* multiplication hashing
* polynomial rolling hash (for strings)

---

# 3. Collisions

When two keys map to the same index:

h(key1) == h(key2)

Collisions are unavoidable (pigeonhole principle), so we need a strategy.

Two major categories:

1. **Separate chaining**
2. **Open addressing**

---

# 4. Separate Chaining

Each array index holds a bucket (usually a linked list or vector).

Example visualization:

```
0: 21 -> 31 -> 41
1: EMPTY
2: 7
3: 15 -> 25
```

### Pros

* handles collisions well
* easy deletion
* good when load factor high

### Cons

* pointers mean extra memory
* worst-case O(n)

---

# 5. Open Addressing

Store all keys in the table itself. When collision occurs, probe for next available slot.

### Methods

#### Linear Probing

index, index+1, index+2, ...

#### Quadratic Probing

index + i²

#### Double Hashing

index + i*h2(key)

### Pros

* cache friendly
* memory efficient

### Cons

* clustering can happen
* deletion tricky

---

# 6. Load Factor

Load factor α = n / m
(n = elements, m = table size)

High α → more collisions → slower operations
Low α → more memory, faster operations

Many implementations resize when α > 0.7.

---

# 7. Time Complexity

| Operation | Average | Worst |
| --------- | ------- | ----- |
| Insert    | O(1)    | O(n)  |
| Search    | O(1)    | O(n)  |
| Delete    | O(1)    | O(n)  |

Worst case rarely happens if:

* hash function is good
* resizing is used
* distribution is uniform

---

# 8. Hashing Methods Overview

This repo includes detailed documents on:

```
hashing_methods.md
implementations/
analysis/
```

Methods include:

* chaining
* linear probing
* quadratic probing
* double hashing
* cuckoo hashing
* perfect hashing

---

# 9. Visual Overview

### Hashing Flow

```
key → hash_function → index → table[index]
```

### Collision resolution (chaining)

```
table[index]
  |
  v
[key] -> [key] -> [key]
```

### Open addressing probing path

```
index → index+1 → index+2 → ...
```

---

# 10. Interview Tips

1. Always explain **load factor** and resizing.
2. Know how to handle collisions.
3. Mention primary and secondary clustering.
4. When asked to design a hashmap:

   * array for buckets
   * linked lists or probing for collisions
   * dynamic resize logic
5. Mention hash function choice especially for strings.
6. Dictionary/Map problems rely on hashing:

   * Two Sum
   * Longest substring without repeating characters
   * Frequency counting
   * Detect duplicates

---

# 11. Practice Problems

### Beginner

* Check if an array contains duplicates
* Count frequency of each element
* First non-repeating character

### Intermediate

* Two Sum
* Largest subarray with sum zero
* Longest substring without repeating characters
* Group anagrams

### Advanced

* Implement LRU cache (hashmap + doubly linked list)
* Subarray with sum = k
* Design a consistent hashing system

---
