/*
----------------------------------------
Min Heap Operations Implementation (C++)
File: /02_Data_Structures/trees/heaps/min_heap/implementations/operations.cpp
----------------------------------------

A Min Heap is a complete binary tree where:
- Every parent node is <= its children.
- Smallest element is always at root.

This file implements:
- insert(x)
- extractMin()
- heapifyDown()
- heapifyUp()

Time Complexity:
- insert: O(log n)
- extractMin: O(log n)
- heapify/buildHeap: O(n)
Space Complexity: O(n)

Use-case:
- Priority queues
- Dijkstra, Prim
- Scheduling
*/

#include <bits/stdc++.h>
using namespace std;

class MinHeap {
private:
    vector<int> h;

    // Get parent index
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    // Maintains heap property upward after insertion
    void heapifyUp(int i) {
        while (i > 0 && h[parent(i)] > h[i]) {
            swap(h[i], h[parent(i)]);
            i = parent(i);
        }
    }

    // Maintains heap property downward after extractMin
    void heapifyDown(int i) {
        int n = h.size();
        while (true) {
            int l = left(i), r = right(i);
            int smallest = i;

            if (l < n && h[l] < h[smallest]) smallest = l;
            if (r < n && h[r] < h[smallest]) smallest = r;

            if (smallest == i) break;

            swap(h[i], h[smallest]);
            i = smallest;
        }
    }

public:
    // Insert element
    void insert(int x) {
        h.push_back(x);
        heapifyUp(h.size() - 1);
    }

    // Returns minimum element
    int getMin() {
        if (h.empty()) throw runtime_error("Heap is empty");
        return h[0];
    }

    // Extract minimum and fix heap
    int extractMin() {
        if (h.empty()) throw runtime_error("Heap is empty");

        int mn = h[0];
        h[0] = h.back();
        h.pop_back();
        if (!h.empty()) heapifyDown(0);

        return mn;
    }

    // Print heap as array (level order)
    void printHeap() {
        for (int x : h) cout << x << " ";
        cout << "\n";
    }
};

int main() {
    MinHeap mh;
    mh.insert(10);
    mh.insert(5);
    mh.insert(20);
    mh.insert(2);
    mh.insert(15);

    cout << "Heap: ";
    mh.printHeap();

    cout << "Extract Min: " << mh.extractMin() << "\n";

    cout << "Heap after extraction: ";
    mh.printHeap();

    return 0;
}

