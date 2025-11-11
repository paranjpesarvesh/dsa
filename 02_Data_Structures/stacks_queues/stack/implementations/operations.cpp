// File: operations.cpp
// Topic: Stack (Array/Linked-List Implementation)
// Description:
//   Implementation of a stack supporting push, pop, top, size, and isEmpty.
//   Includes both array-based and linked-list based stack structures.
//   Demonstrates LIFO (Last In First Out) behavior.
//
// Algorithm Choice:
//   Array-based stack gives O(1) operations with fixed capacity.
//   Linked-list stack allows dynamic growth without overflow.
//
// Complexity:
//   Time: O(1) for push/pop/top
//   Space: O(n) for n elements in the stack
//
// Variations:
//   - Dynamic array stack (auto-resizing)
//   - Stack using two queues
//   - Stack using deque

#include <iostream>
using namespace std;

// -----------------------------
// ARRAY-BASED STACK
// -----------------------------
class ArrayStack {
private:
    int *arr;
    int topIndex;
    int capacity;

public:
    ArrayStack(int cap = 1000) {
        capacity = cap;
        arr = new int[capacity];
        topIndex = -1;
    }

    void push(int x) {
        if (topIndex == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++topIndex] = x;
    }

    void pop() {
        if (topIndex == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        topIndex--;
    }

    int top() {
        if (topIndex == -1) {
            cout << "Stack Empty\n";
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return (topIndex == -1);
    }

    int size() {
        return topIndex + 1;
    }
};

// -----------------------------
// LINKED LIST BASED STACK
// -----------------------------
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedStack {
private:
    Node* head;
    int count;

public:
    LinkedStack() {
        head = NULL;
        count = 0;
    }

    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        count++;
    }

    void pop() {
        if (head == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }

    int top() {
        if (head == NULL) {
            cout << "Stack Empty\n";
            return -1;
        }
        return head->data;
    }

    bool isEmpty() {
        return head == NULL;
    }

    int size() {
        return count;
    }
};

// -----------------------------
// DRIVER CODE (FOR DEMO)
// -----------------------------
int main() {
    cout << "Array Stack demo:\n";
    ArrayStack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.top() << "\n"; // 30
    st.pop();
    cout << "Top after pop: " << st.top() << "\n"; // 20

    cout << "\nLinked Stack demo:\n";
    LinkedStack lst;
    lst.push(5);
    lst.push(15);
    lst.push(25);
    cout << "Top: " << lst.top() << "\n"; // 25
    lst.pop();
    cout << "Top after pop: " << lst.top() << "\n"; // 15

    return 0;
}

