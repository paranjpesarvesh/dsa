# Top-K Elements Pattern

The **Top-K Elements pattern** appears in problems that require selecting:

* the **k largest** or **k smallest** elements
* the **k most frequent** elements
* the **k closest** elements
* the **kth order statistic** (like kth largest/smallest)
* streaming/top-k queries
* partial sorting without fully sorting the array

This pattern heavily relies on **heaps**, **quickselect**, and occasionally **bucket sort**.

---

# 1. Core Idea

To extract the top K elements efficiently:

* **Use min-heap** when searching for top K largest
* **Use max-heap** when searching for top K smallest
* Use **frequency maps + heaps** for top K frequent
* Use **quickselect** to reduce average time to O(n)
* Use **bucket sort** when frequency ranges are tight

---

# 2. Why Not Sort Fully?

Sorting entire array takes:

```
O(n log n)
```

But Top-K does not require full ordering.

Using a size-K heap, complexity becomes:

```
O(n log k)
```

This is significantly faster when `k << n`.

---

# 3. Step-by-Step Reasoning Pattern

### Identify:

* Do we need largest, smallest, or most frequent?
* Is k small relative to n?
* Use heap of opposite behavior:

  * Want largest? Use MIN-heap of size k
  * Want smallest? Use MAX-heap of size k

### Apply:

* Push items
* Pop if heap grows beyond size k
* Remaining heap contains the top K

### Confirm:

* Order heap result if necessary
* Handle edge cases (k=0, k>=n)

---

# 4. Visual Illustration

## Example: Top 3 largest

Array:

```
[10, 4, 5, 2, 11, 7, 9]
```

Min-heap growth:

```
10
[10, 4]   → push 4
[10, 4, 5]
pop 4? size <= 3

Insert 2
[10, 5, 2] pop 2

Insert 11
[10, 11, 5] pop 5

Insert 7
[10, 11, 7]

Insert 9
[10, 11, 9]
```

Final heap → top 3: **[11, 10, 9]**

---

# 5. Implementation Templates

---

## A. K Largest Elements (using min-heap)

```
heap = empty min-heap

for num in arr:
    push(heap, num)
    if size(heap) > k:
        pop_min(heap)

return heap
```

---

## B. K Smallest Elements (using max-heap)

```
heap = empty max-heap

for num in arr:
    push(heap, num)
    if size(heap) > k:
        pop_max(heap)

return heap
```

---

## C. Top K Frequent Elements

```
freq = hashmap

for x in nums:
    freq[x] += 1

minheap = []

for value, f in freq.items():
    push(minheap, (f, value))
    if size(minheap) > k:
        pop(minheap)

return elements in minheap
```

---

## D. Quickselect (average O(n))

Pseudo:

```
function quickselect(arr, k):
    pivot = choose random
    left = []
    right = []
    equal = []

    partition

    if k < len(left):
        return quickselect(left, k)
    elif k < len(left) + len(equal):
        return equal[0]
    else:
        return quickselect(right, k - len(left) - len(equal))
```

Produces kth largest/smallest element.

---

# 6. Complexity Comparison

| Method                | Complexity   | Notes                       |
| --------------------- | ------------ | --------------------------- |
| Sorting               | O(n log n)   | Simple but slow for small k |
| Min-heap (k largest)  | O(n log k)   | Ideal when k << n           |
| Max-heap (k smallest) | O(n log k)   | Same reasoning              |
| Quickselect           | O(n) average | Worst-case O(n²)            |
| Bucket sort (freq)    | O(n)         | Works when counts small     |

---

# 7. Variations

1. **Top K Frequent Words** (lexicographical ordering)
2. **K Closest Numbers to X**
3. **K Closest Points to Origin**
4. **Find K Pairs With Smallest Sums**
5. **Find Kth Largest Element**
6. **Stream processing** (continuously update top-k)

---

# 8. Edge Cases

* k > n → return entire array sorted
* k = 0 → return empty list
* duplicates maintained
* tie-breaking rules (frequency, value ordering)

---

# 9. Interview Tips

* Always justify min-heap vs max-heap
* Mention alternative Quickselect
* If asked about streaming → use min-heap of size k
* For frequency problems → hash map + heap
* Avoid sorting unless explicitly necessary
* Know complexity differences
* Mention that many real-world systems use heaps for top-k streaming analytics

---

# 10. Practice Problems

### LeetCode

* 215 Kth Largest Element in Array
* 347 Top K Frequent Elements
* 973 K Closest Points to Origin
* 703 Kth Largest in a Stream
* 692 Top K Frequent Words
* 658 Find K Closest Elements

### GFG

* K largest elements
* K most frequent
* K closest numbers

### Codeforces

* Problems involving maintaining K best candidates
* Sliding window + top-k operations

---

# Summary

The Top-K Elements pattern enables efficient partial selection using:

* heaps
* frequency maps
* quickselect
* bucket counting

Understanding when and how to use these tools leads to significant performance improvements in interview settings and real-world systems.

