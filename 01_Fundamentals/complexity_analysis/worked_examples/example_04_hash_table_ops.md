# 🗂️ Worked Example 04 – Hash Table Operations

This worked example focuses on **Hash Tables** (also known as Hash Maps/Dictionaries), their **core operations**, and how to analyze their **time complexity** under different scenarios.

---

## 🔹 Problem Statement

We want to efficiently support the following operations on a collection of key-value pairs:

1. **Insert (key, value)** → Store the pair in the table.
2. **Search (key)** → Retrieve the value for a given key.
3. **Delete (key)** → Remove the key and its associated value.

---

## 🔹 Key Concepts

* **Hash Function (h):** Maps a key `k` to an index in the table.
  Example: `h(k) = k mod m` where `m` is table size.

* **Collisions:** When two keys map to the same index.

  * **Chaining**: Use linked lists/vectors at each index.
  * **Open Addressing**: Probe for another empty slot.

---

## 🔹 Pseudocode (Chaining)

```text
function insert(table, key, value):
    index = h(key)
    append (key, value) to table[index]

function search(table, key):
    index = h(key)
    for (k, v) in table[index]:
        if k == key:
            return v
    return NOT_FOUND

function delete(table, key):
    index = h(key)
    for (k, v) in table[index]:
        if k == key:
            remove (k, v) from table[index]
            return SUCCESS
    return NOT_FOUND
```

---

## 🔹 Example

Table size = 5, hash function `h(k) = k mod 5`.

Insert keys: `[12, 22, 32, 42, 52, 17]`.

```
Index 0: [ ]
Index 1: [ ]
Index 2: [12, 22, 32, 42, 52]  <-- collision chain
Index 3: [ ]
Index 4: [17]
```

---

## 🔹 Time & Space Complexity

| Operation | Average Case | Worst Case (bad hash) |
| --------- | ------------ | --------------------- |
| Insert    | O(1)         | O(n)                  |
| Search    | O(1)         | O(n)                  |
| Delete    | O(1)         | O(n)                  |
| Space     | O(n)         | O(n)                  |

* **Average case O(1)** if load factor α = n/m is kept low (e.g., α ≤ 1).
* **Worst case O(n)** if all elements hash to the same bucket.

---

## 🔹 Variations

1. **Collision resolution strategies**

   * **Chaining (linked list, vector, BST, or even another hash table).**
   * **Open addressing (linear probing, quadratic probing, double hashing).**

2. **Dynamic resizing**

   * When load factor α grows beyond a threshold (e.g., 0.75), **rehash** into a bigger table.

---

## 🔹 ASCII Illustration (Chaining)

```
Hash Table (m = 7)
--------------------------------
Index 0 | [14, 21] → linked list
Index 1 | [ ]
Index 2 | [9]
Index 3 | [ ]
Index 4 | [28, 35]
Index 5 | [ ]
Index 6 | [42]
```

---

## 🔹 C++ Implementation (Chaining)

```cpp
// Hash Table implementation using chaining
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class HashTable {
    int size;
    vector<list<pair<int,int>>> table;

    int hash(int key) {
        return key % size;
    }

public:
    HashTable(int s) : size(s) {
        table.resize(s);
    }

    void insert(int key, int value) {
        int index = hash(key);
        table[index].push_back({key, value});
    }

    int search(int key) {
        int index = hash(key);
        for (auto& [k, v] : table[index]) {
            if (k == key) return v;
        }
        return -1; // Not found
    }

    void remove(int key) {
        int index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return;
            }
        }
    }
};
```

---

## 🔹 Python Implementation (Dictionary-like)

```python
# Hash Table with chaining using lists

class HashTable:
    def __init__(self, size=10):
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash(self, key):
        return key % self.size

    def insert(self, key, value):
        index = self._hash(key)
        self.table[index].append((key, value))

    def search(self, key):
        index = self._hash(key)
        for k, v in self.table[index]:
            if k == key:
                return v
        return None

    def delete(self, key):
        index = self._hash(key)
        for i, (k, v) in enumerate(self.table[index]):
            if k == key:
                del self.table[index][i]
                return True
        return False
```

---

## 🔹 Interview Tips

* Common in **FAANG**: Design a hash table from scratch, explain **collision resolution**.
* GATE: Analyze complexity under **load factor α**.
* Edge cases:

  * Duplicate keys → overwrite or maintain multiple values.
  * Rehashing cost (amortized O(1)).
  * Poor hash function → clustering.

---

## 🔹 Practice Problems

* [LeetCode 1 – Two Sum](https://leetcode.com/problems/two-sum/)
* [LeetCode 347 – Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)
* [GFG – Separate Chaining in Hashing](https://www.geeksforgeeks.org/separate-chaining-collision-handling-technique-in-hashing/)

---

✅ This worked example demonstrates **Insert, Search, Delete** in Hash Tables, their complexities, collision strategies, and practical usage.

---
