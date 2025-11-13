# **Heap Sort — Complete Notes (Simple, Clear & Interview-Focused)**

---

## **1. What is Heap Sort?**

Heap Sort is a **comparison-based**, **in-place**, **O(n log n)** sorting algorithm that uses a **Binary Heap** (usually a Max-Heap) to repeatedly extract the maximum element and build the sorted array.

It is widely used when:

* Memory is limited (in-place)
* Worst-case guarantees are required
* Priority queue concepts overlap

---

## **2. Intuition**

### **Max-Heap Property**

For every node:

```
parent ≥ children
```

### **Idea**

1. Convert array → max-heap
2. Swap root (largest) with last element
3. Reduce heap size & heapify
4. Repeat until sorted

---

## **3. Visual Diagram**

### **Example Array**

```
[4, 1, 3, 9, 7]
```

### **Step 1: Build Max-Heap**

```
        9
      /   \
     7     3
    / \
   1   4
```

### **Step 2: Extract max & heapify repeatedly**

```
Iteration 1:  swap 9 with 4  →  [4,7,3,1,9]
Heapify → [7,4,3,1,9]

Iteration 2: swap 7 with 1  →  [1,4,3,7,9]
Heapify → [4,1,3,7,9]

Iteration 3: swap 4 with 3  →  [3,1,4,7,9]
Heapify → [3,1,4,7,9]

... until sorted
```

### **Final Output**

```
[1, 3, 4, 7, 9]
```

---

## **4. Steps Explained**

1. Build a **max-heap** from the input.
2. For i = n-1 down to 1:

   * Swap arr[0] with arr[i]
   * Heapify the reduced heap (0 to i-1)

---

## **5. Pseudocode**

```
heapSort(arr):
    n = length(arr)

    // Step 1: Build max-heap
    for i = n/2 - 1 downto 0:
        heapify(arr, n, i)

    // Step 2: Extract elements
    for i = n-1 downto 1:
        swap(arr[0], arr[i])
        heapify(arr, i, 0)

heapify(arr, heapSize, i):
    largest = i
    left  = 2*i + 1
    right = 2*i + 2

    if left < heapSize and arr[left] > arr[largest]:
        largest = left
    if right < heapSize and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        swap(arr[i], arr[largest])
        heapify(arr, heapSize, largest)
```

---

## **6. Complexity**

| Operation       | Time                |
| --------------- | ------------------- |
| Build heap      | O(n)                |
| Each extraction | O(log n)            |
| Total           | **O(n log n)**      |
| Space           | **O(1)** (in-place) |
| Stable?         | **No**              |

---

## **7. Variations**

* **Min-Heap Sort** → sorts in descending order
* **In-place Floyd heapify vs recursive heapify**
* **Heapsort as part of IntroSort (C++ std::sort)**

---

## **8. Edge Cases**

* All elements same → still O(n log n)
* Already sorted array → no best-case improvement
* Large datasets → great choice due to memory efficiency

---

## **9. Interview Tips**

* Stress that **build heap is O(n)** (common trick question)
* Heap Sort is **in-place but not stable**
* Compare with:

  * Merge Sort → stable, not in-place
  * Quick Sort → average fast, worst-case bad
  * Heap Sort → consistent worst-case guarantee

FAANG loves asking to:

* Implement heapify
* Convert array to heap
* Do k largest elements (heap-based)

---

## **10. Practice Problems**

### **LeetCode**

* Top K Frequent Elements
* Kth Largest Element
* Merge K Sorted Lists (uses heaps internally)

### **GFG**

* Heap Sort
* Convert Min-Heap to Max-Heap

### **Codeforces**

* Many problems using priority queues for greedy selection

---
