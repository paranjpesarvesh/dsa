// File: operations.cpp
// Topic: Priority Queue (Binary Heap Implementation)
// Description:
//   Implementation of a Priority Queue using a Binary Heap.
//   Supports insertion, deletion (extract), peek, and heap operations.
//
// Algorithm choice:
//   Binary Heap → O(log n) insert, O(log n) delete, O(1) peek.
//   Backed by array for cache efficiency.
//
// Complexity:
//   Insert: O(log n)
//   Extract-max/min: O(log n)
//   Peek: O(1)
//   Space: O(n)

#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> h; // heap array (0-indexed)

    // returns parent index
    int parent(int i) { return (i - 1) / 2; }

    // returns left child index
    int left(int i) { return 2 * i + 1; }

    // returns right child index
    int right(int i) { return 2 * i + 2; }

    // Heapify-up after insertion
    void heapify_up(int i) {
        while (i > 0 && h[parent(i)] < h[i]) {
            swap(h[parent(i)], h[i]);
            i = parent(i);
        }
    }

    // Heapify-down after extract
    void heapify_down(int i) {
        int n = h.size();
        while (true) {
            int l = left(i);
            int r = right(i);
            int largest = i;

            // choose larger of children
            if (l < n && h[l] > h[largest]) largest = l;
            if (r < n && h[r] > h[largest]) largest = r;

            if (largest == i) break; // heap property satisfied

            swap(h[i], h[largest]);
            i = largest;
        }
    }

public:
    bool empty() { return h.empty(); }

    int size() { return h.size(); }

    int top() {
        if (empty()) throw runtime_error("Heap is empty");
        return h[0];
    }

    // Insert element
    void push(int x) {
        h.push_back(x);
        heapify_up(h.size() - 1);
    }

    // Extract-max
    void pop() {
        if (empty()) throw runtime_error("Heap is empty");
        h[0] = h.back();
        h.pop_back();
        if (!empty()) heapify_down(0);
    }
};

// Example usage
int main() {
    PriorityQueue pq;
    pq.push(10);
    pq.push(40);
    pq.push(20);
    pq.push(5);

    cout << pq.top() << endl; // 40
    pq.pop();

    cout << pq.top() << endl; // 20
}

