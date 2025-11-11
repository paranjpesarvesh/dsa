/************************************************************
 * Queue Operations Implementation (Linked List-based Queue)
 *
 * Description:
 *   This file implements core queue operations using a singly
 *   linked list. Queue follows FIFO (First In First Out).
 *
 * Supported Operations:
 *   - enqueue(x)
 *   - dequeue()
 *   - front()
 *   - isEmpty()
 *
 * Implementation Style:
 *   Linked-list queue enables dynamic size (no fixed capacity).
 *
 * Time Complexity:
 *   enqueue:  O(1)
 *   dequeue:  O(1)
 *   front:    O(1)
 *
 * Space Complexity:
 *   O(n) for n elements in the queue.
 *
 ************************************************************/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class Queue {
private:
    Node* frontPtr;
    Node* rearPtr;

public:
    Queue() {
        frontPtr = nullptr;
        rearPtr = nullptr;
    }

    bool isEmpty() {
        return frontPtr == nullptr;
    }

    // Add element at rear
    void enqueue(int x) {
        Node* newNode = new Node(x);

        if (rearPtr == nullptr) {
            frontPtr = rearPtr = newNode;
            return;
        }

        rearPtr->next = newNode;
        rearPtr = newNode;
    }

    // Remove element from front
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }

        Node* temp = frontPtr;
        int val = temp->data;

        frontPtr = frontPtr->next;
        if (frontPtr == nullptr)
            rearPtr = nullptr;

        delete temp;
        return val;
    }

    // Get front element
    int front() {
        if (isEmpty()) {
            cout << "Queue Empty\n";
            return -1;
        }
        return frontPtr->data;
    }

    // Destructor
    ~Queue() {
        while (!isEmpty())
            dequeue();
    }
};

// Example usage
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.front() << endl; // Output: 10

    cout << q.dequeue() << endl; // Output: 10
    cout << q.dequeue() << endl; // Output: 20

    q.enqueue(40);
    q.enqueue(50);

    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }

    return 0;
}

