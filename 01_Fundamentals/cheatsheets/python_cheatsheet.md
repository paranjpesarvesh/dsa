# 🐍 Python Cheatsheet for DSA

This cheatsheet is a **quick reference guide** for using Python effectively in solving **data structures, algorithms, and interview problems**. It balances **speed, readability, and practical use cases** for contests, FAANG interviews, and GATE preparation.

---

## 🔹 1. Basics

### Input/Output

```python
# Fast input (important for CP)
import sys
input = sys.stdin.readline

n = int(input())                # Single integer
arr = list(map(int, input().split()))  # List of integers

# Output
print("Result:", arr)
```

### Swapping

```python
a, b = b, a
```

### Multiple Assignment

```python
x, y, z = 1, 2, 3
```

---

## 🔹 2. Data Types & Useful Operations

| Type       | Common Ops / Tricks                            |                                     |
| ---------- | ---------------------------------------------- | ----------------------------------- |
| **List**   | append, pop, sort, slicing, list comprehension |                                     |
| **Tuple**  | Immutable, hashable (can be dict/set keys)     |                                     |
| **Set**    | union (                                        | ), intersection (&), difference (-) |
| **Dict**   | O(1) average lookup, dict.get(key, default)    |                                     |
| **String** | slicing, join, strip, find, count              |                                     |

```python
# List comprehension
squares = [x*x for x in range(10) if x % 2 == 0]

# Dictionary with default values
from collections import defaultdict
freq = defaultdict(int)
for c in "abracadabra":
    freq[c] += 1
```

---

## 🔹 3. Itertools (Patterns & Combinations)

```python
from itertools import permutations, combinations, product

# Permutations
list(permutations([1, 2, 3], 2))  # [(1,2), (1,3), (2,1), (2,3), ...]

# Combinations
list(combinations([1, 2, 3], 2))  # [(1,2), (1,3), (2,3)]

# Cartesian Product
list(product([1, 2], [3, 4]))     # [(1,3), (1,4), (2,3), (2,4)]
```

---

## 🔹 4. Math & Random

```python
import math, random

math.gcd(24, 36)        # 12
math.lcm(4, 6)          # 12
math.isqrt(10)          # 3 (integer sqrt)
pow(2, 10, 1000)        # 24 (mod exponentiation)

random.randint(1, 100)  # Random integer
```

---

## 🔹 5. Sorting & Heap

```python
arr = [("alice", 25), ("bob", 20), ("carol", 30)]
arr.sort(key=lambda x: x[1])  # Sort by age

# Heap (priority queue)
import heapq
pq = []
heapq.heappush(pq, (1, "task1"))
heapq.heappush(pq, (3, "task2"))
heapq.heappop(pq)  # (1, "task1")
```

---

## 🔹 6. Queue, Stack, Deque

```python
from collections import deque

# Stack
stack = []
stack.append(10)
stack.pop()

# Queue
queue = deque([1, 2, 3])
queue.append(4)
queue.popleft()  # FIFO

# Deque (double-ended queue)
dq = deque([1, 2, 3])
dq.appendleft(0)
dq.pop()
```

---

## 🔹 7. Searching & Bisect

```python
import bisect

arr = [1, 3, 4, 4, 6]
bisect.bisect_left(arr, 4)   # 2 (first index of 4)
bisect.bisect_right(arr, 4)  # 4 (index after last 4)
```

---

## 🔹 8. Recursion & Memoization

```python
import functools

@functools.lru_cache(None)  # Memoization decorator
def fib(n):
    if n <= 1:
        return n
    return fib(n-1) + fib(n-2)
```

---

## 🔹 9. Graph Utilities

```python
from collections import defaultdict, deque

graph = defaultdict(list)
graph[0].append(1)
graph[1].append(2)

# BFS
def bfs(start):
    visited = set([start])
    q = deque([start])
    while q:
        node = q.popleft()
        for nei in graph[node]:
            if nei not in visited:
                visited.add(nei)
                q.append(nei)
```

---

## 🔹 10. Complexity Quick Ref (Python Operations)

| Operation             | Time Complexity |
| --------------------- | --------------- |
| List append / pop end | O(1)            |
| List pop front        | O(n)            |
| Dict / Set lookup     | O(1) avg        |
| Sorting               | O(n log n)      |
| Heap push/pop         | O(log n)        |
| BFS/DFS               | O(V + E)        |

---

## 🔹 11. Interview Tips

* 🚀 **FAANG**: Focus on Python’s **dict, set, heapq, deque**—used in most patterns (sliding window, graphs, priority queues).
* 📝 **GATE**: Python isn’t the exam language, but knowing how to map concepts (recursion, DP, complexity) is useful.
* ⚡ Avoid slow constructs in contests: use `sys.stdin.readline` for fast I/O.

---

## 🔹 12. Practice Problems

* [LeetCode – Python tagged problems](https://leetcode.com/problemset/all/?language=Python)
* [HackerRank Python domain](https://www.hackerrank.com/domains/tutorials/10-days-of-python)
* [Codeforces Python Guide](https://codeforces.com/blog/entry/62393)

---
