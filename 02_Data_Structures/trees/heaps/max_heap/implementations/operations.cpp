// Max Heap Operations Implementation (Array-based)
// Supports: insert, extractMax, getMax, heapify, buildHeap
// Time Complexity:
//   - insert: O(log n)
//   - extractMax: O(log n)
//   - getMax: O(1)
//   - buildHeap: O(n)
// Space Complexity: O(n)
//
// Overview:
// A Max-Heap is a complete binary tree stored in an array where:
//     parent(i) = i/2
//     left(i)  = 2*i
//     right(i) = 2*i + 1
// Heap property: parent >= children

#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<int> heap; // 1-indexed heap for simplicity

    // Heapify down (restore heap from index i downward)
    void heapifyDown(int i) {
        int n = heap.size() - 1; // ignoring index 0
        while (true) {
            int largest = i;
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left <= n && heap[left] > heap[largest]) largest = left;
            if (right <= n && heap[right] > heap[largest]) largest = right;

            if (largest == i) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

    // Heapify up (restore heap from index i upward)
    void heapifyUp(int i) {
        while (i > 1 && heap[i] > heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
            i /= 2;
        }
    }

public:
    MaxHeap() {
        heap.push_back(-1); // dummy to make heap 1-indexed
    }

    // Insert a value into heap
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // Return max element
    int getMax() {
        if (heap.size() <= 1) throw runtime_error("Heap empty");
        return heap[1];
    }

    // Extract and remove max element
    int extractMax() {
        if (heap.size() <= 1) throw runtime_error("Heap empty");
        int maxVal = heap[1];
        heap[1] = heap.back();
        heap.pop_back();
        if (heap.size() > 1) heapifyDown(1);
        return maxVal;
    }

    // Build heap from array in O(n)
    void buildHeap(const vector<int>& arr) {
        heap = { -1 }; // reset
        for (int x : arr) heap.push_back(x);
        int n = heap.size() - 1;
        for (int i = n / 2; i >= 1; i--) {
            heapifyDown(i);
        }
    }

    // Print heap level-wise
    void printHeap() {
        for (int i = 1; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

// Example usage
int main() {
    MaxHeap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(40);

    cout << "Heap: ";
    h.printHeap();

    cout << "Max: " << h.getMax() << endl;

    cout << "Extracted: " << h.extractMax() << endl;

    cout << "Heap after extraction: ";
    h.printHeap();

    return 0;
}

