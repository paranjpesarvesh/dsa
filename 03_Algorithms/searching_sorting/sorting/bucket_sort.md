# **Bucket Sort — Theory, Intuition & Implementation Guide**

---

## **1. What is Bucket Sort?**

Bucket Sort is a **distribution-based sorting algorithm** that works by:

1. Dividing the input into several **buckets**.
2. Distributing elements into buckets based on a **hashing/indexing function**.
3. Sorting each bucket individually (usually using insertion sort).
4. Concatenating all buckets to form the final sorted array.

It is extremely efficient when data is **uniformly distributed over a known range**.

---

## **2. Intuition**

Imagine sorting marks of 10,000 students where marks range from 0 to 100.

Instead of comparing elements repeatedly (like in comparison-based sorts), we:

* Create 101 buckets (0 to 100)
* Place each mark in its respective bucket
* Concatenate → sorted!

---

## **3. Visual Diagram**

### Example: Input `[0.42, 0.32, 0.23, 0.52, 0.25, 0.47]`

```
Buckets (0 to 0.9 step 0.1):
0: [0.23, 0.25]
1: [0.32]
2: [0.42]
3:
4: [0.47]
5: [0.52]
...

After sorting each bucket:
0: [0.23, 0.25]
1: [0.32]
2: [0.42]
4: [0.47]
5: [0.52]

Concatenate:
[0.23, 0.25, 0.32, 0.42, 0.47, 0.52]
```

---

## **4. When Does Bucket Sort Work Best?**

* **Uniformly distributed input**
* **Continuous range** (floats especially)
* **Large input size**

---

## **5. Bucket Sort Algorithm (Step-by-step)**

1. Create `k` empty buckets.
2. For each element, compute its bucket index.
3. Insert the element into the bucket.
4. Sort each bucket separately (typically insertion sort).
5. Merge all buckets.

---

## **6. Pseudocode**

```
function bucketSort(arr, k):
    create k empty buckets

    for each x in arr:
        index = floor(k * x)   // assuming 0 ≤ x < 1
        add x to buckets[index]

    for each bucket:
        sort(bucket)

    result = concatenate all buckets
    return result
```

---

## **7. Complexity Analysis**

| Case                                  | Time Complexity |
| ------------------------------------- | --------------- |
| **Best**                              | O(n + k)        |
| **Average**                           | O(n + k)        |
| **Worst** (when all go to one bucket) | O(n²)           |
| **Space**                             | O(n + k)        |

---

## **8. Bucket Index Function**

Depends on the data:

* For floats in `[0,1)` → `index = floor(k*x)`
* For integers in `[min,max]` → `index = (x-min) * k / (max-min+1)`

---

## **9. Variations**

* **Bucket Sort + Insertion Sort** (most common)
* **Bucket Sort + Merge Sort**
* **Integer Bucket Sort / Counting Sort hybrid**
* **Parallel bucket sort** (for distributed systems)

---

## **10. Edge Cases**

* All values identical → single bucket heavily loaded
* Highly skewed data → loses efficiency
* Choosing too many/few buckets harms performance

---

## **11. Interview Tips**

* Emphasize that **Bucket Sort is not comparison-based**, so it can beat O(n log n).
* Mention **use-case restriction**: works only for well-distributed data.
* Often paired with **Counting Sort** and **Radix Sort** in interviews.
* Explain **why insertion sort** is used: buckets are small → O(k²) tiny.

---

## **12. Practice Problems**

### **LeetCode**

* Bucket-based:

  * *Maximum Gap*
  * *Top K Frequent Elements* (Bucket approach)

### **GFG**

* Bucket Sort implementation
* Sort float numbers in range [0,1)

### **Codeforces**

* Any problems requiring frequency buckets or range grouping

---
