# Skip List — Theory

Skip Lists are a probabilistic alternative to balanced binary search trees.
They provide **expected O(log n)** search, insert, and delete operations
with simpler implementation and excellent average-case performance.

This file explains how skip lists work, why randomness helps, detailed intuition, pseudocode, diagrams, and interview insights.

---

# 1. What is a Skip List?

A Skip List is a layered, probabilistic structure where:

* Level 0 is a normal sorted linked list.
* Higher levels skip over multiple elements.
* Each element appears in a random number of levels.
* Higher levels have fewer nodes.

A node may have height 1, 2, 3,... depending on coin toss.

---

# 2. Visual Intuition

Imagine multiple tracks stacked vertically:

```
                 Level 3:     A-------------G--------------M
                 Level 2:     A-----C-------G-------------M
                 Level 1:     A--B--C--D--E--F--G--H--I--J--K--L--M
```

Searching begins from top-left and navigates down and right similar to binary search behavior.

---

# 3. Why Skip Lists Work

Skip lists rely on **probability** to maintain good performance.

Given probability `p=0.5`:

* About half of the nodes are promoted to level 1
* A quarter to level 2
* One-eighth to level 3
* ... and so on

Thus the expected number of levels is O(log n), and each level has geometrically fewer nodes.

This ensures each search path is expected O(log n).

---

# 4. Structure of Each Node

A node contains:

* key (mandatory)
* value (optional)
* forward pointers for levels it participates in

Node representation (ASCII):

```
     +------------------+
     | key | value | -> | level 2 next
     +------------------+
              |
              v
     +------------------+
     | key | value | -> | level 1 next
     +------------------+
              |
              v
     +------------------+
     | key | value | -> | level 0 next
     +------------------+
```

---

# 5. How Search Works

Search starts at the highest level and tries to move right.

Pseudo logic:

1. Start at head node at top level.
2. While next node exists and next.key < target:

   * move right
3. If cannot move right:

   * drop down a level
4. Repeat until level 0
5. Check current node’s next at level 0

ASCII search example:

Starting at Level 3:

```
   A ------ G -------- M
             |
             drop
                   |
```

Level 2:   A --- C --- G ------ M
|
drop
|
Level 1:   A - B - C - D - E - F - G - ...

Search time complexity = number of right and down movements = O(log n) expected.

---

# 6. Insertion Process

Steps:

1. Use the search path to find predecessor nodes at each level.
2. Generate random height `h` for new node.
3. Insert at each level from 0 to h by updating pointers.

Pseudo insertion:

```
update[] ← empty
curr ← head
for level = maxLevel → 0:
    while curr.forward[level] < key:
        curr ← curr.forward[level]
    update[level] ← curr
h ← randomLevel()
newNode ← Node(key)
for level = 0 → h:
    newNode.forward[level] ← update[level].forward[level]
    update[level].forward[level] ← newNode
```

---

# 7. Deletion Process

Deletion uses the same update array.

For each level, bypass the node:

```
for level = 0 → maxLevel:
    if update[level].forward[level] == target:
        update[level].forward[level] = target.forward[level]
```

---

# 8. Random Level Generation

Most implementations use:

function randomLevel():
level = 0
while random() < p AND level < maxLevel:
level += 1
return level

Height distribution is geometric.

Expected highest level ≈ log_{1/p}(n).

---

# 9. Complexity Analysis

| Operation | Expected Time | Worst Time | Space                       |
| --------- | ------------- | ---------- | --------------------------- |
| Search    | O(log n)      | O(n)       | O(n)                        |
| Insert    | O(log n)      | O(n)       | O(n)                        |
| Delete    | O(log n)      | O(n)       | O(n)                        |
| Memory    | -             | -          | O(n log n) forward pointers |

Worst-case occurs with extremely small probability.

---

# 10. Edge Cases

* Duplicate keys:

  * usually handled by updating value
* Very large data:

  * adjust maxLevel dynamically
* Randomness poor:

  * rare but possible worst-case
* Head node always has full height
* Linked list pointer updates must be correct across all levels

---

# 11. Variations and Extensions

1. **Indexable Skip Lists**

   * store span/width to allow O(log n) order-statistics (k-th element).
2. **Concurrent Skip Lists**

   * lock-free versions exist for high-performance systems.
3. **Deterministic Skip Lists**

   * controlled level promotion rules instead of random coin flips.
4. **Memory-optimized Skip Lists**

   * reduce pointer overhead.

---

# 12. Interview Tips

Interviewers often ask:

* Why does skip list have expected O(log n)?
* How does randomness help?
* Compare skip list to balanced BST (AVL/Red-Black):

  * skip list: probabilistic
  * BST: deterministic rotations
* Discuss space vs time tradeoff
* Explain how many levels you expect for n elements

Common follow-ups:

* How would you handle duplicates?
* Can you turn skip lists into a map or priority queue?
* What is an alternative to skip list? (Answer: balanced BST)

---

# 13. Practice Problems

### LeetCode/GFG

* Design Skip List (LC 1206)
* Implement Skip List (coding challenge)
* Implement Ordered Map
* Insert/Delete in sorted structure

### Competitive programming

* Skip lists rarely appear directly.
* Good for implementing ordered sets/maps in languages with no built-in tree maps.

---

# 14. Summary

| Concept        | Summary                                |
| -------------- | -------------------------------------- |
| Structure      | multi-level linked list                |
| Performance    | expected O(log n) operations           |
| Randomness     | balanced heights naturally             |
| Advantages     | simple, fast, practical                |
| Disadvantages  | non-worst-case guarantees, more memory |
| Best use cases | ordered sets, ordered maps             |

---
