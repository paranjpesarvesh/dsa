# 📘 C++ Cheatsheet for DSA

This document serves as a **comprehensive C++ reference** tailored for **Data Structures and Algorithms (DSA)**. It highlights the most relevant syntax, STL usage, and patterns frequently needed in **competitive programming, FAANG interviews, and GATE preparation**.

---

## 🔹 1. Fast I/O Setup

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << "Input: " << n << "\n";
}
```

⚡ **Tip**: Always use `ios::sync_with_stdio(false);` and `cin.tie(nullptr);` in contests/interviews to avoid I/O bottlenecks.

---

## 🔹 2. Common Data Types & Limits

| Type        | Size (typical 64-bit) | Header      | Constant Examples      |
| ----------- | --------------------- | ----------- | ---------------------- |
| `int`       | 4 bytes               | `<climits>` | `INT_MIN, INT_MAX`     |
| `long long` | 8 bytes               | `<climits>` | `LLONG_MIN, LLONG_MAX` |
| `double`    | 8 bytes               | `<cfloat>`  | `DBL_MAX`              |
| `bool`      | 1 byte                | -           | `true/false`           |

---

## 🔹 3. Vectors (Dynamic Arrays)

```cpp
vector<int> v = {1, 2, 3};
v.push_back(4);       // [1, 2, 3, 4]
v.pop_back();         // [1, 2, 3]
cout << v.size();     // 3

// Iteration
for (int x : v) cout << x << " ";
```

### Useful Methods

* `v.front(), v.back()`
* `v.insert(v.begin() + i, x)`
* `v.erase(v.begin() + i)`
* `v.clear()`

---

## 🔹 4. Strings

```cpp
string s = "hello";
s += " world";                 // Concatenate
cout << s.substr(0, 5);        // "hello"
reverse(s.begin(), s.end());   // Reverse string
```

⚡ Common interview ops:

* Palindrome check
* Substring search (`find`)
* Frequency count with `unordered_map<char,int>`

---

## 🔹 5. Pairs & Tuples

```cpp
pair<int, int> p = {1, 2};
cout << p.first << " " << p.second;

tuple<int, string, double> t = {1, "DSA", 3.14};
auto [a, b, c] = t;  // Structured binding (C++17)
```

---

## 🔹 6. Sets & Maps

```cpp
set<int> s = {3, 1, 2};
s.insert(5);
if (s.count(3)) cout << "Found";

// HashMap
unordered_map<string, int> freq;
freq["apple"]++;
```

* `set` → Balanced BST → O(log n)
* `unordered_set` / `unordered_map` → Hash table → O(1) average, O(n) worst

---

## 🔹 7. Priority Queue (Heap)

```cpp
priority_queue<int> maxHeap; // Max-heap
priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap

maxHeap.push(10);
maxHeap.push(5);
cout << maxHeap.top(); // 10
```

---

## 🔹 8. Deque & Queue

```cpp
queue<int> q;
q.push(1); q.push(2);
cout << q.front();  // 1
q.pop();

deque<int> dq;
dq.push_front(10);
dq.push_back(20);
dq.pop_front();
```

---

## 🔹 9. Stack

```cpp
stack<int> st;
st.push(5);
st.push(10);
cout << st.top(); // 10
st.pop();
```

---

## 🔹 10. Algorithms (STL)

```cpp
vector<int> v = {4, 2, 1, 3};
sort(v.begin(), v.end());         // Ascending
sort(v.rbegin(), v.rend());       // Descending
reverse(v.begin(), v.end());
int idx = lower_bound(v.begin(), v.end(), 3) - v.begin();
```

* `binary_search(v.begin(), v.end(), x)`
* `accumulate(v.begin(), v.end(), 0)` (needs `<numeric>`)

---

## 🔹 11. Useful Snippets

### GCD & LCM

```cpp
int g = gcd(48, 18);     // 6
int l = lcm(48, 18);     // 144
```

### Random Numbers

```cpp
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int x = uniform_int_distribution<int>(1, 100)(rng);
```

---

## 🔹 12. Template for Competitive Coding

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        // Solve each test case
    }
}
```

---

## 🔹 Interview Tips

* 🚀 **FAANG**: Expect heavy use of `vector`, `unordered_map`, `priority_queue`.
* 📝 **GATE**: Expect questions on C++ STL complexity and memory models.
* ⚡ Be ready to discuss **why you chose STL** over manual implementation.

---

## 🔹 Practice Problems

* [LeetCode: STL Mastery](https://leetcode.com/)
* [Codeforces EDU Segment Tree Course (C++ heavy)](https://codeforces.com/edu/course/2)
* [GFG: C++ STL Tutorials](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)

---
