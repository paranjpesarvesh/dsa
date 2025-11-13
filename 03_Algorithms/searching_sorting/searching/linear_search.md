# **Linear Search — Theory, Intuition & Implementation**

---

## **1. What is Linear Search?**

Linear Search is the simplest searching algorithm.
You sequentially check each element of the array until:

* you find the target, or
* you reach the end.

Works on **any array** — sorted or unsorted.

---

## **2. Intuition**

Think of looking for a name in an unsorted attendance sheet:

```
Check 1st → not found
Check 2nd → not found
Check 3rd → found
```

There is **no faster way** if the data is not sorted.

---

## **3. How It Works (Step-by-Step)**

1. Start from index `0`.
2. Compare each element with the target.
3. If match found → return index.
4. If you reach the end → return -1.

---

## **4. Visual Illustration**

Array:

```
[5, 2, 9, 1, 7]
```

Searching for **1**:

```
Index: 0 1 2 3 4
Value: 5 2 9 1 7

→ Compare arr[0] = 5 (no)
→ Compare arr[1] = 2 (no)
→ Compare arr[2] = 9 (no)
→ Compare arr[3] = 1 (YES) → return 3
```

---

## **5. Pseudocode**

```
function linearSearch(a, x):
    for i from 0 to length(a)-1:
        if a[i] == x:
            return i
    return -1
```

---

## **6. Time & Space Complexity**

| Case                                 | Complexity |
| ------------------------------------ | ---------- |
| Best (target at index 0)             | O(1)       |
| Worst (target not present or at end) | O(n)       |
| Average                              | O(n)       |
| Space                                | O(1)       |

---

## **7. Variations of Linear Search**

* Sentinel Linear Search (reduces boundary checks)
* Linear Search on Linked List
* Linear Search with Early Exit Condition

---

## **8. Edge Cases**

* Empty array → return -1
* Array with duplicates → return first match
* Non-existing target → return -1

---

## **9. Interview Tips (FAANG / GATE)**

* They may ask you to contrast with **Binary Search**.
* Mention that Linear Search works on **unsorted data**, Binary Search does not.
* Frequently used for:

  * Small datasets
  * Linked lists (no random access)
  * First-occurrence problems

---

## **10. Practice Problems**

### **LeetCode**

* Contains Duplicate
* Find First Occurrence

### **GFG**

* Linear Search
* Search in Unsorted Array

### **Codeforces**

* Basic implementation-based tasks

---
