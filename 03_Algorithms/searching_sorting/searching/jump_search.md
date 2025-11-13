# **Jump Search — Theory, Intuition & Implementation**

---

## **1. What is Jump Search?**

Jump Search is a searching algorithm for **sorted arrays**, where you “jump” ahead by fixed steps instead of going element-by-element.

### **Key Idea**

Jump forward in blocks of size **√n** until you land in a block where the element may exist, then perform **linear search** inside that block.

---

## **2. Why √n Jump Size? — Mathematical Intuition**

Let:

* jump size = `m`
* number of blocks = `n/m`
* linear search inside block = `m`

Total operations:

```
Total ≈ n/m + m
```

To minimize cost, differentiate:

```
m = √n
```

Hence optimal jump = **square root of array size**.

---

## **3. Working Process (Step-by-Step)**

Assume array sorted in ascending order.

1. Start at index `0`.
2. Jump ahead by `√n` each time:

   ```
   0 → √n → 2√n → 3√n → ...
   ```
3. Stop when:

   ```
   arr[current] >= target
   ```
4. Perform **linear search** in the block:

   ```
   from (prev block start) to (current index)
   ```

---

## **4. Visual Illustration**

Array size = 16 → jump size = 4

```
Index:   0 1 2 3 | 4 5 6 7 | 8 9 10 11 | 12 13 14 15
Jump:     →4         →8          →12         →16
```

Searching for 19:

```
Check arr[4] = 12 < 19
Check arr[8] = 17 < 19
Check arr[12] = 22 >= 19 (STOP)
```

Now linear search between indices **8 to 12**.

---

## **5. Pseudocode**

```
function jumpSearch(a, x):
    n = length(a)
    step = floor(sqrt(n))
    prev = 0

    while prev < n and a[min(step, n)-1] < x:
        prev = step
        step += floor(sqrt(n))

        if prev >= n:
            return -1

    for i from prev to min(step, n)-1:
        if a[i] == x:
            return i

    return -1
```

---

## **6. Time & Space Complexity**

| Phase               | Complexity |
| ------------------- | ---------- |
| Jumping phase       | O(√n)      |
| Linear search phase | O(√n)      |
| **Total**           | **O(√n)**  |
| Space               | **O(1)**   |

---

## **7. When to Use Jump Search**

* Array is **sorted**
* Direct random access is allowed (`O(1)` indexing)
* Better than linear search, simpler than binary search
* Useful in **disk-based storage** or **large blocks of memory**

---

## **8. Variations**

* **Block Search** (jump search + hashing)
* **Jump Search with Variable Block Sizes**
* **Jump Search for Linked Lists** → skip list idea

---

## **9. Edge Cases**

* Array size = 0 → return -1
* Target < first element → return -1
* Jump exceeds array bounds → clamp to `n`
* Handle duplicates normally (returns first found)

---

## **10. Interview Tips (FAANG / GATE)**

* Mention optimal jump size = **√n**
* Emphasize **trade-off between jumps and linear search**
* They often ask:

  * Compare Jump vs Binary Search
  * Explain where Jump Search is useful (block-structured data)
  * Apply to large sorted file blocks / external storage

---

## **11. Practice Problems**

### **LeetCode (related patterns)**

* Search Insert Position
* Square Root (concept of √n)
* Sorted array search variations

### **GFG**

* Jump Search implementation
* Search in sorted array with block jumps

### **Codeforces**

* Problems involving efficient skipping or block jumping

---
