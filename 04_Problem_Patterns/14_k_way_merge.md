# K-Way Merge Pattern

The **K-Way Merge** pattern is used when merging elements from **K sorted lists**, streams, arrays, or files into a single sorted sequence. It is a generalization of the classic merge step of merge sort (which merges 2 sorted lists), but extended to handle **K lists efficiently**.

This pattern has wide usage in interview problems involving:

* merging K sorted lists
* merging K sorted streams
* merging K sorted arrays
* finding smallest/largest elements across K groups
* external sorting (disk-based)
* multi-way merge operations in distributed systems

---

# 1. Core Intuition

Each of the K sorted lists has its own pointer or head element. At any instant, the next smallest available item across all lists lies at one of those heads.

**Goal → always select the minimum among the K heads.**

Naive approach:

* scan all K heads each time → O(K) per selection
* total selections = N (total number of elements)
* complexity = **O(NK)** → too slow for large K

Optimized idea:

* store the K heads in a **min-heap**
* extract min in O(log K)
* push next element from same list

Total complexity becomes:

```
O(N log K)
```

---

# 2. Visual Illustration

Suppose we want to merge:

```
Array 1: [1, 4, 8]
Array 2: [2, 5]
Array 3: [3, 6, 7]
```

Min-heap contents evolve:

```
Initial heap:
(1, list1)
(2, list2)
(3, list3)
```

Process:

```
pop 1 → push 4
pop 2 → push 5
pop 3 → push 6
pop 4 → push 8
pop 5
pop 6 → push 7
pop 7
pop 8
```

Final merged output:

```
[1, 2, 3, 4, 5, 6, 7, 8]
```

---

# 3. Step-by-Step Strategy

### Step 1

Initialize min-heap with first element of each list. Heap elements store:

* value
* list index
* element index

### Step 2

While heap is not empty:

* extract min
* append to output
* push next element from the same list (if exists)

### Step 3

Return merged list

---

# 4. Pseudocode Template

```
function kWayMerge(lists):
    minheap = []

    for i in range(k):
        push(minheap, (lists[i][0], i, 0))

    result = []

    while heap not empty:
        val, list_i, idx = pop_min(minheap)
        append result, val

        if idx+1 < len(lists[list_i]):
            next_val = lists[list_i][idx+1]
            push(minheap, (next_val, list_i, idx + 1))

    return result
```

---

# 5. Complexity Analysis

### Time Complexity

```
O(N log K)
```

where:

* N = total elements across all lists
* K = number of lists

### Space Complexity

```
O(K)
```

for the heap + output list storage.

---

# 6. Variations of K-Way Merge

1. Merge K sorted linked lists
2. Merge K sorted arrays
3. Merge K sorted streams (continuous data)
4. Find K smallest pair sums
5. Find smallest range covering at least one element from each of K lists
6. Merge files in external sorting
7. Find median from K sorted lists
8. K-way merge with max-heap (for descending order)

---

# 7. Edge Cases

* K = 0 → return empty
* lists of varying lengths
* lists contain duplicates
* empty lists among inputs
* extremely large K → use multi-level merging

---

# 8. Interview Tips

* Always explain why you use a heap
* Emphasize the improvement from O(NK) to O(N log K)
* Mention memory usage and scalability
* For merging files: bring up external merge sort
* For K sorted linked lists: mention that pointers increment per extraction
* For range problems: min-heap helps track global minimum; need to track maximum separately

Common follow-up questions:

* What if lists are not sorted?
  → Sorting each first.

* What if memory is limited?
  → Use streaming/iterators.

* What if K is very large?
  → Use tournament tree optimization or batch merging.

---

# 9. Practice Problems

### LeetCode

* 23 Merge K Sorted Lists
* 632 Smallest Range Covering K Lists
* 378 Kth Smallest in a Sorted Matrix
* 373 Find K Pairs With Smallest Sums
* 786 K-th Smallest Prime Fraction

### GFG

* Merge K sorted arrays
* Find smallest range

### Codeforces

* Stream merging problems
* Priority queue based merging tasks

---

# Summary

The **K-Way Merge** pattern is the backbone of many top-level interview problems involving merging, selection, and combining data across multiple sorted sources. It relies heavily on min-heaps to achieve optimal performance and scales well for large inputs and real-world applications.

