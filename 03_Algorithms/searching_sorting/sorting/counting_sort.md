# **Counting Sort — Theory, Intuition & Quick Reference Guide**

---

## **1. What is Counting Sort?**

Counting Sort is a **non-comparison–based sorting algorithm** used when:

* All elements are **integers**
* Values lie in a **small known range** (0 to k)

Instead of comparing elements, it **counts occurrences** of each value and reconstructs the sorted array.

---

## **2. Intuition**

If the array is:
`[4, 2, 2, 8, 3, 3, 1]`

We count how many times each value occurs:

```
Value:   1 2 3 4 5 6 7 8
Count:   1 2 2 1 0 0 0 1
```

Then reconstruct the sorted list:

```
[1, 2, 2, 3, 3, 4, 8]
```

---

## **3. Visual Diagram**

```
Input: [4, 2, 2, 8, 3, 3, 1]

1. Count array (size = max+1):

Index: 0 1 2 3 4 5 6 7 8
Count: 0 1 2 2 1 0 0 0 1

2. Prefix sum (for stable sort):

Index: 0 1 2 3 4 5 6 7 8
PSUM:  0 1 3 5 6 6 6 6 7

3. Place elements into output using PSUM (stable)

Final Output:
[1, 2, 2, 3, 3, 4, 8]
```

---

## **4. Steps of the Algorithm**

1. Find the maximum value `maxVal`.
2. Create a count array of size `maxVal+1`.
3. Count occurrences of each value.
4. Convert count array into **prefix-sum array** (for stable version).
5. Build the output array.
6. Copy output into original.

---

## **5. Pseudocode**

```
function countingSort(arr):
    maxVal = maximum(arr)
    create count[maxVal+1] initialized to 0

    for x in arr:
        count[x]++

    for i from 1 to maxVal:
        count[i] += count[i-1]

    create output array

    for i from n-1 downto 0:
        x = arr[i]
        pos = count[x] - 1
        output[pos] = x
        count[x]--

    return output
```

---

## **6. Complexity**

| Factor      | Value                            |
| ----------- | -------------------------------- |
| **Time**    | O(n + k)                         |
| **Space**   | O(k) extra                       |
| **Stable?** | Yes (if prefix sum version used) |

Where:

* n = number of elements
* k = range of values (maxVal)

---

## **7. When Counting Sort Works Best**

* Input values are within a **small integer range**
* Large n but small k (e.g., 10 million values in [0..100])
* Needed as a subroutine in **Radix Sort**

---

## **8. Variations**

* **Non-stable counting sort** (simpler, no prefix-sum)
* **Counting sort for negative numbers**
* **Counting sort by key** (used in Radix)

---

## **9. Edge Cases**

* Very large range → space becomes too big
* Floats/strings → cannot sort directly
* If stability is needed, must use prefix-sum method

---

## **10. Interview Tips**

* Mention **O(n + k)** beating O(n log n) (not comparison-based).
* Highlight its use inside **Radix Sort**.
* Stress the limitation: only works when the **range is small**.
* Know stable vs non-stable version differences.

---

## **11. Practice Problems**

### **LeetCode**

* *Maximum Gap* (bucket + counting concepts)
* *Sort Colors* (counting approach)

### **GFG**

* Counting Sort implementation
* Sort elements by frequency

### **Codeforces**

* Many frequency-based sorting tasks

---
