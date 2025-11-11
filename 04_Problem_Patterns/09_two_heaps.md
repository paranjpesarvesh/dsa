# Two-Heaps Pattern

A key technique for efficiently tracking medians, balancing partitions, or maintaining two priority groups.

---

# 1. What is the Two-Heaps Pattern?

Two heaps are maintained simultaneously:

* **Max-Heap** → stores the *smaller half* of the stream/elements
* **Min-Heap** → stores the *larger half* of the stream/elements

Balancing condition:

```
| size(max_heap) - size(min_heap) | ≤ 1
```

Invariant:

```
(max_heap top) ≤ (min_heap top)
```

This ensures that the median (or any specific threshold partition) is accessible in O(1) time.

---

# 2. Why Two Heaps?

Because heaps give:

* O(log n) insertion
* O(1) extreme-value access
* Dynamic balancing
* Efficient median queries

Many sliding-window or streaming problems require constant-time median extraction. Two heaps solve that elegantly.

---

# 3. Visual Structure

```
-----------------------------
|  smaller half | larger half |
-----------------------------
   max-heap        min-heap
      ↓                ↓
   biggest         smallest
   among           among
   smaller         larger
```

Heap tops form the boundary between the two partitions.

---

# 4. Core Operations

### 1. Add a number

```
if num <= max_heap.top:
    add to max_heap
else:
    add to min_heap
```

### 2. Rebalance

```
if max_heap.size > min_heap.size + 1:
    move max_heap.top → min_heap
elif min_heap.size > max_heap.size + 1:
    move min_heap.top → max_heap
```

### 3. Get median

```
if sizes equal:
    median = (max_heap.top + min_heap.top) / 2
else:
    median = heap with larger size.top
```

---

# 5. Pseudocode Template

```
max_heap = MaxHeap()
min_heap = MinHeap()

function add(num):
    if max_heap empty OR num <= max_heap.top:
        max_heap.push(num)
    else:
        min_heap.push(num)

    balance()

function balance():
    if size(max_heap) > size(min_heap) + 1:
        min_heap.push(max_heap.pop())
    if size(min_heap) > size(max_heap) + 1:
        max_heap.push(min_heap.pop())

function get_median():
    if size(max_heap) == size(min_heap):
        return (max_heap.top + min_heap.top) / 2
    return heap_with_bigger_size.top
```

---

# 6. Complexity

| Operation      | Time     | Space |
| -------------- | -------- | ----- |
| Insert element | O(log n) | O(n)  |
| Get median     | O(1)     | O(n)  |
| Rebalance      | O(log n) | O(n)  |

---

# 7. When to Use the Two-Heaps Pattern?

### A. Stream Processing

* Running median
* Dynamic percentile tracking
* Realtime analytics

### B. Sliding Windows

Maintain median of the last k elements efficiently.

### C. Partition Problems

* Balance load
* Split elements by threshold
* Maintain two sets where max(left) ≤ min(right)

### D. Scheduling / Resource Allocation

Useful when we need priority grouping.

---

# 8. Variations

### Variation 1: With Lazy Deletion

Used for sliding window median.

### Variation 2: With Frequency Heaps

For k-frequency elements.

### Variation 3: With Custom Order

Sometimes max-heap stores larger half depending on problem constraints.

---

# 9. Common Pitfalls

* forgetting to rebalance after each insertion
* incorrect comparison when pushing the number
* mixing min/max heaps logic
* not handling empty state in median
* integer overflow when averaging two values
* sliding window removal logic often tricky

---

# 10. Interview Tips

* Explain heap invariants clearly.
* Mention that balancing occurs in O(log n).
* Sketch structure during interview.
* Stress how the median is always in one of the two roots.
* When asked about sliding window:
  show understanding of lazy deletion + valid counts.

---

# 11. Practice Problems

### LeetCode

* 295 Find Median from Data Stream
* 480 Sliding Window Median
* 857 Minimum Cost to Hire K Workers
* 1167 Minimum Cost to Connect Sticks (heap-based but related)

### GFG

* Running median
* Nearly sorted array
* Kth largest/smallest in stream

### Codeforces

* Various problems involving dynamic median / balancing partitions

---

# 12. Summary

Two heaps allow:

* Maintaining ordered halves efficiently
* Log-time insertion
* Constant-time median access
* Rebalancing ensures correctness

This pattern is fundamental for modern real-time analytics as well as frequent interview problems.

---
