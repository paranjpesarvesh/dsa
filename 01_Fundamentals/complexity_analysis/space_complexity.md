#  Space Complexity in Algorithms

---

##  1. What is Space Complexity?

**Space Complexity** of an algorithm is the **total memory required** by the program to execute successfully.
It includes memory for:

1. **Fixed Part** – independent of input size

   * Code instructions
   * Constants
   * Primitive variables
   * Pointers/references

2. **Variable Part** – depends on input size

   * Dynamically allocated structures (arrays, linked lists, trees, etc.)
   * Recursion stack space
   * Temporary variables

$$
\text{Space Complexity (S)} = C + P(n)
$$

* `C` → fixed part (constant)
* `P(n)` → variable part as a function of input size `n`

---

##  2. Components of Space Complexity

###  (a) Instruction Space

Memory required to store the compiled code.

* Independent of input size.

---

###  (b) Fixed Part

* Constants, simple variables, object references.
* Example: `int count = 0;`

---

###  (c) Variable Part

1. **Input storage** → Storing arrays, matrices, trees, etc.
2. **Auxiliary space** → Extra data structures used during execution.
3. **Function call stack (recursion)** → Parameters + return addresses + local variables.

---

##  3. Examples

### Example 1: Iterative Sum

```cpp
int sumArray(int arr[], int n) {
    int sum = 0; // O(1)
    for (int i = 0; i < n; i++) {
        sum += arr[i]; // O(1)
    }
    return sum;
}
```

* Space = `O(1)` (only `sum` and `i`)
* No extra data structure → **Constant space**

---

### Example 2: Recursive Factorial

```cpp
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
```

* Each call stored in recursion stack.
* Depth = `n`.
* Space = `O(n)` (stack frames).

---

### Example 3: Merge Sort

```cpp
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
```

* Uses **O(n)** temporary array for merging.
* Recursion stack depth = `O(log n)`.
* Total = `O(n + log n) ≈ O(n)`.

---

##  4. Visual Aid: Stack Growth in Recursion

```
factorial(4)
|
|-- factorial(3)
     |
     |-- factorial(2)
          |
          |-- factorial(1)
               |
               |-- factorial(0)
```

Stack depth = 5 (for `n=4`).
In general → depth = `n`.

---

##  5. Common Space Complexities

| Algorithm             | Space Complexity                 |
| --------------------- | -------------------------------- |
| Linear Search         | O(1)                             |
| Binary Search (iter.) | O(1)                             |
| Binary Search (rec.)  | O(log n)                         |
| Merge Sort            | O(n)                             |
| QuickSort (in-place)  | O(log n) (stack)                 |
| DFS (recursive)       | O(V)                             |
| BFS                   | O(V) (queue)                     |
| Dynamic Programming   | O(n) or O(n²) depending on state |

---

##  6. Trade-offs: Time vs. Space

* **Caching (DP, memoization):** Reduces time at cost of extra space.
* **In-place algorithms (QuickSort, HeapSort):** Save space but may be harder to implement.
* **Iterative vs. Recursive:** Iterative often saves stack space.

---

##  7. Edge Cases & Pitfalls

* **Stack Overflow:** Deep recursion (`n` large in factorial).
* **Memory Limit Exceeded (MLE):** Common in coding contests when arrays are too large.
* **Hidden overheads:** Object-oriented programs use extra memory for vtables, object headers.

---

##  8. Interview Tips

* Interviewers often ask **time + space complexity trade-offs**.
* Be clear about **recursion depth** (e.g., DFS on trees = height of tree).
* Show ability to **optimize auxiliary space** (e.g., DP from `O(n²)` → `O(n)`).
* GATE exams test **stack memory** in recursive functions.

---

##  9. Practice Problems

* [LeetCode 70 – Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) → Recursion vs DP space.
* [LeetCode 322 – Coin Change](https://leetcode.com/problems/coin-change/) → Bottom-up vs top-down space trade-off.
* [GFG – Merge Sort Space Analysis](https://www.geeksforgeeks.org/merge-sort/)
* [Codeforces 455A – Boredom](https://codeforces.com/problemset/problem/455/A) → Space-efficient DP.

---

 **Key Takeaway:**
Space complexity is as important as time complexity.
Mastering it requires awareness of **recursion stack, auxiliary structures, and in-place optimizations**.

---
