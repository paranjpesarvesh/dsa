// Topic: Hash Table Implementation (Open Addressing - Linear Probing)
//
// Description:
// A hash table is a data structure that maps keys to values using a hash function.
// This implementation demonstrates open addressing with linear probing.
//
// Key ideas used:
// - Hash function: key % capacity
// - Collision resolution: linear probing (i.e., try next index)
// - Supports: insert, search, delete
//
// Time Complexity:
// Average: O(1) for insert, search, delete
// Worst-case: O(n) (when table is full or clustered)
//
// Space Complexity: O(n)
//
// Notes:
// - This is a simple educational implementation.
// - Does not handle dynamic resizing.
// - Keys assumed to be integers for simplicity.

#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<int> table;
    vector<bool> occupied;
    int capacity;

    int hashFunc(int key) {
        return key % capacity; // basic hash function
    }

public:
    HashTable(int size) {
        capacity = size;
        table.assign(capacity, -1);
        occupied.assign(capacity, false);
    }

    bool insertKey(int key) {
        int idx = hashFunc(key);
        int start = idx;

        // linear probing
        while (occupied[idx]) {
            if (table[idx] == key) return false; // duplicate key
            idx = (idx + 1) % capacity;
            if (idx == start) return false; // table full
        }

        table[idx] = key;
        occupied[idx] = true;
        return true;
    }

    bool searchKey(int key) {
        int idx = hashFunc(key);
        int start = idx;

        while (occupied[idx]) {
            if (table[idx] == key) return true;
            idx = (idx + 1) % capacity;
            if (idx == start) break;
        }
        return false;
    }

    bool deleteKey(int key) {
        int idx = hashFunc(key);
        int start = idx;

        while (occupied[idx]) {
            if (table[idx] == key) {
                table[idx] = -1;
                occupied[idx] = false;
                return true;
            }
            idx = (idx + 1) % capacity;
            if (idx == start) break;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < capacity; i++) {
            cout << i << ": ";
            if (occupied[i])
                cout << table[i];
            else
                cout << "EMPTY";
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(7);

    ht.insertKey(10);
    ht.insertKey(20);
    ht.insertKey(5);
    ht.insertKey(15);

    cout << "After Insertions:\n";
    ht.display();

    cout << "\nSearch 20: " << (ht.searchKey(20) ? "Found" : "Not Found") << endl;
    cout << "Search 99: " << (ht.searchKey(99) ? "Found" : "Not Found") << endl;

    ht.deleteKey(20);
    cout << "\nAfter Deleting 20:\n";
    ht.display();

    return 0;
}

