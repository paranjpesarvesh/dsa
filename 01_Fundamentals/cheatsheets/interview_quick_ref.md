# 🚀 Interview Quick Reference (DSA)

This **quick reference guide** is designed for **last-minute interview prep**. It condenses the most important **concepts, patterns, and must-know complexities** you should recall during a FAANG/GATE interview.

---

## 🔹 1. Complexity Cheat Table

| Complexity | Name         | Examples                           |
| ---------- | ------------ | ---------------------------------- |
| O(1)       | Constant     | Hash lookup, stack push/pop        |
| O(log n)   | Logarithmic  | Binary search, BST operations      |
| O(n)       | Linear       | Array traversal, BFS/DFS           |
| O(n log n) | Linearithmic | Merge Sort, Heap Sort, QuickSort\* |
| O(n²)      | Quadratic    | Nested loops, Bubble/Insertion     |
| O(2ⁿ)      | Exponential  | Subset/recursion problems          |
| O(n!)      | Factorial    | Traveling Salesman brute force     |

---

## 🔹 2. Common Problem-Solving Patterns

### Two Pointers

* Used for **sorted arrays/strings**.
* Problems: Pair Sum, Remove Duplicates.

### Sliding Window

* Used for **subarray/substring problems**.
* Problems: Longest Substring Without Repeating Characters.

### Divide & Conquer

* Recursive split → conquer subproblems.
* Problems: Merge Sort, QuickSort, Binary Search.

### Hashing & Frequency Counter

* Used for counting, anagrams, subarray sum = k.

### Greedy

* Used when **local optimum → global optimum**.
* Problems: Interval Scheduling, Huffman Coding.

### Dynamic Programming

* Break problem into overlapping subproblems + memoize.
* Problems: Fibonacci, Knapsack, LIS, LCS.

---

## 🔹 3. Must-Know Data Structures

| Structure        | Operations (avg)         | Usage in Interviews          |
| ---------------- | ------------------------ | ---------------------------- |
| Array            | O(1) access, O(n) search | Basics everywhere            |
| HashMap/Set      | O(1) insert/search       | Frequency, subarray problems |
| Linked List      | O(1) insert, O(n) search | List manipulation            |
| Stack            | O(1) push/pop            | Parentheses matching, Undo   |
| Queue/Deque      | O(1) enqueue/dequeue     | Sliding window max           |
| Heap/PQ          | O(log n) push/pop        | Top-K, scheduling            |
| BST (balanced)   | O(log n) ops             | Ordered problems             |
| Graph (adj list) | O(V + E) traversal       | BFS, DFS, Dijkstra           |
| Trie             | O(L) insert/search       | Prefix, autocomplete         |

---

## 🔹 4. Recurrence Mastery

* **Binary Search**: T(n) = T(n/2) + O(1) → O(log n)
* **Merge Sort**: T(n) = 2T(n/2) + O(n) → O(n log n)
* **QuickSort (avg)**: T(n) = 2T(n/2) + O(n) → O(n log n)
* **DP on grids**: O(n·m) time, O(n·m) space

---

## 🔹 5. Graph Algorithms at a Glance

| Algorithm        | Complexity | Usage                     |
| ---------------- | ---------- | ------------------------- |
| BFS/DFS          | O(V+E)     | Traversal, connectivity   |
| Dijkstra (heap)  | O(E log V) | Shortest path (non-neg)   |
| Bellman-Ford     | O(VE)      | Shortest path (neg edges) |
| Floyd–Warshall   | O(V³)      | All-pairs shortest paths  |
| Kruskal (MST)    | O(E log V) | Minimum Spanning Tree     |
| Prim (heap MST)  | O(E log V) | Minimum Spanning Tree     |
| Topological Sort | O(V+E)     | Ordering DAG              |

---

## 🔹 6. Quick Interview Pseudocode Templates

### Binary Search

```cpp
int binarySearch(vector<int>& arr, int target) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
```

### BFS

```cpp
queue<int> q;
vector<bool> visited(n, false);
q.push(start); visited[start] = true;
while (!q.empty()) {
    int node = q.front(); q.pop();
    for (int neigh : adj[node]) {
        if (!visited[neigh]) {
            visited[neigh] = true;
            q.push(neigh);
        }
    }
}
```

---

## 🔹 7. Interview Tips

* **FAANG**: Focus on **patterns** (sliding window, two pointers, hashing, graphs, DP).
* **GATE**: Expect theory-heavy (recurrences, asymptotic analysis, data structure internals).
* Always **state complexity clearly** when finishing an explanation.
* For implementation rounds: **start with brute force → optimize** while speaking out loud.

---

## 🔹 8. High-Yield Practice Lists

* **LeetCode Blind 75** → Covers most interview patterns.
* **NeetCode 150** → Categorized learning path.
* **GFG Must-Do** → Topic-wise DSA essentials.
* **GATE PYQs** (Data Structures + Algorithms section).

---

