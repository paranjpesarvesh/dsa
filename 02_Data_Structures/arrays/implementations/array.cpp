/**
 * File: array.cpp
 * Path Context: dsa/02_Data_Structures/arrays/implementations/
 *
 * Problem Statement:
 * -----------------
 * Implementation of a basic array data structure with essential operations:
 * - Access by index
 * - Insertion at the end
 * - Deletion by index
 * - Searching for an element
 *
 * This demonstrates the fundamental properties and operations of arrays in C++.
 * It also shows the space-time characteristics of static arrays.
 *
 * Algorithm Choice:
 * -----------------
 * Arrays are chosen for their O(1) access time by index.
 * Operations like insertion or deletion (except at the end) may require O(n) time due to shifting.
 * This implementation uses a fixed-size array to illustrate memory allocation and access.
 *
 * Time & Space Complexity:
 * ------------------------
 * Access by index: O(1)
 * Insertion at end: O(1) if space is available
 * Insertion at middle/start: O(n)
 * Deletion: O(n) in worst case
 * Space: O(n) (fixed array size)
 */

#include <iostream>
using namespace std;

class Array {
private:
    int *data;
    int capacity;
    int size;

public:
    // Constructor: initialize array with given capacity
    Array(int cap) {
        capacity = cap;
        size = 0;
        data = new int[capacity];
    }

    // Destructor: free allocated memory
    ~Array() {
        delete[] data;
    }

    // Insert element at the end
    void insert(int value) {
        if (size >= capacity) {
            cout << "Array is full. Cannot insert " << value << endl;
            return;
        }
        data[size++] = value;
    }

    // Delete element at given index
    void removeAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return;
        }
        // Shift elements left
        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }

    // Search for an element and return its index, -1 if not found
    int search(int value) {
        for (int i = 0; i < size; i++) {
            if (data[i] == value)
                return i;
        }
        return -1;
    }

    // Get element at index
    int get(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index" << endl;
            return -1;
        }
        return data[index];
    }

    // Print array contents
    void print() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Return current size
    int getSize() {
        return size;
    }

    // Return maximum capacity
    int getCapacity() {
        return capacity;
    }
};

int main() {
    Array arr(5);

    // Insert elements
    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);
    arr.insert(50);

    arr.print(); // 10 20 30 40 50

    // Attempt to insert into full array
    arr.insert(60);

    // Delete element at index 2 (30)
    arr.removeAt(2);
    arr.print(); // 10 20 40 50

    // Search for element 40
    int idx = arr.search(40);
    cout << "Index of 40: " << idx << endl;

    // Access element at index 1
    cout << "Element at index 1: " << arr.get(1) << endl;

    return 0;
}

/**
 * Variations:
 * -----------
 * 1. Dynamic arrays (vectors) can be used to allow automatic resizing.
 * 2. Use templates to support arrays of different data types.
 * 3. Implement additional operations like insertion at specific index.
 */

