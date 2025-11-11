/************************************************************
 * Queue Operations Implementation (Array-based Queue)
 *
 * Description:
 *   This file implements core queue operations using an array.
 *   The queue follows FIFO (First In First Out) order.
 *
 * Supported Operations:
 *   - enqueue(x)
 *   - dequeue()
 *   - front()
 *   - isEmpty()
 *   - isFull()
 *
 * Implementation Style:
 *   Circular array queue to achieve O(1) enqueue & dequeue.
 *
 * Time Complexity:
 *   enqueue:  O(1)
 *   dequeue:  O(1)
 *   front:    O(1)
 *
 * Space Complexity:
 *   O(n) where n is queue capacity.
 *
 ************************************************************/

#include <iostream>
using namespace std;

class Queue {
private:
    int *arr;
    int frontIdx;
    int rearIdx;
    int size;
    int capacity;

public:
    // Constructor
    Queue(int cap) {
        capacity = cap;
        arr = new int[cap];
        frontIdx = 0;
        rearIdx = 0;
        size = 0;
    }

    // Check if queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if queue is full
    bool isFull() {
        return size == capacity;
    }

    // Add element to rear
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[rearIdx] = x;
        rearIdx = (rearIdx + 1) % capacity; // circular increment
        size++;
    }

    // Remove element from front
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int val = arr[frontIdx];
        frontIdx = (frontIdx + 1) % capacity; // circular increment
        size--;
        return val;
    }

    // Return the front element
    int front() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        return arr[frontIdx];
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }
};

// Driver / Example Usage
int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.front() << endl; // Output: 10

    cout << q.dequeue() << endl; // Output: 10
    cout << q.dequeue() << endl; // Output: 20

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70); // Shows overflow

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }

    return 0;
}
