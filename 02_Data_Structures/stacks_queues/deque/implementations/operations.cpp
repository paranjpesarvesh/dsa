// Deque Operations Implementation (C++)
// File: /02_Data_Structures/stacks_queues/deque/implementations/operations.cpp
//
// Description:
// Implement a double-ended queue (deque) using a doubly linked list.
// Supports insertion and deletion from both ends efficiently.
//
// Why this structure?
// A deque allows O(1) push/pop from both front and back — useful in sliding window,
// BFS optimization, caching patterns, and monotonic queue problems.
//
// Operations implemented:
// - push_front(x)
// - push_back(x)
// - pop_front()
// - pop_back()
// - front()
// - back()
// - is_empty()
// - size()
//
// Time Complexity:
// All operations: O(1)
// Space Complexity: O(n)

// Node structure for Deque
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

class Deque {
private:
    Node* head;
    Node* tail;
    int count;

public:
    // Constructor
    Deque() {
        head = tail = NULL;
        count = 0;
    }

    // Check if empty
    bool is_empty() {
        return count == 0;
    }

    // Return size
    int size() {
        return count;
    }

    // Insert at front
    void push_front(int x) {
        Node* node = new Node(x);

        if (is_empty()) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        count++;
    }

    // Insert at back
    void push_back(int x) {
        Node* node = new Node(x);

        if (is_empty()) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        count++;
    }

    // Remove from front
    int pop_front() {
        if (is_empty()) {
            cout << "Deque underflow\n";
            return -1;
        }

        int val = head->data;
        Node* temp = head;

        if (head == tail) { // only one element
            head = tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
        count--;
        return val;
    }

    // Remove from back
    int pop_back() {
        if (is_empty()) {
            cout << "Deque underflow\n";
            return -1;
        }

        int val = tail->data;
        Node* temp = tail;

        if (head == tail) { // only one element
            head = tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
        count--;
        return val;
    }

    // Get front element
    int front() {
        if (is_empty()) {
            cout << "Deque empty\n";
            return -1;
        }
        return head->data;
    }

    // Get back element
    int back() {
        if (is_empty()) {
            cout << "Deque empty\n";
            return -1;
        }
        return tail->data;
    }
};

// Example usage
int main() {
    Deque dq;

    dq.push_front(10);
    dq.push_back(20);
    dq.push_front(5);

    cout << dq.front() << endl; // 5
    cout << dq.back() << endl;  // 20

    dq.pop_front();             // removes 5
    dq.pop_back();              // removes 20

    cout << dq.front() << endl; // 10

    return 0;
}

