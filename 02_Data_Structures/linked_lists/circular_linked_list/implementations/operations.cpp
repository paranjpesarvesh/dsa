// operations.cpp
// Circular Linked List – Core Operations Implementation
//
// This file implements basic operations on a Circular Singly Linked List:
// 1. Insert at head
// 2. Insert at end
// 3. Delete a node
// 4. Search
// 5. Display
//
// Explanation:
// A circular linked list is a linked list where the last node points back to the head.
// We maintain at minimum a pointer to 'head'. For convenience, we may also maintain 'tail'.
//
// Complexity:
// Insert at head: O(1)
// Insert at end: O(1) if tail maintained, else O(n)
// Delete: O(n)
// Search: O(n)
// Display: O(n)

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Insert node at beginning
    void insertHead(int val) {
        Node* n = new Node(val);

        if (!head) {
            head = n;
            head->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) temp = temp->next;

        // temp is last node
        n->next = head;
        temp->next = n;
        head = n;
    }

    // Insert at end
    void insertEnd(int val) {
        Node* n = new Node(val);

        if (!head) {
            head = n;
            head->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) temp = temp->next;

        temp->next = n;
        n->next = head;
    }

    // Delete a node with value
    void deleteVal(int val) {
        if (!head) return;

        // If only 1 node
        if (head->data == val && head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        // Find node
        while (curr->data != val) {
            prev = curr;
            curr = curr->next;

            if (curr == head) return; // not found
        }

        // Delete head case
        if (curr == head) {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            head = head->next;
            temp->next = head;
            delete curr;
            return;
        }

        // Delete non-head node
        prev->next = curr->next;
        delete curr;
    }

    // Search a value
    bool search(int val) {
        if (!head) return false;

        Node* temp = head;

        do {
            if (temp->data == val) return true;
            temp = temp->next;
        } while (temp != head);

        return false;
    }

    // Display list
    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << "\n";
    }
};

int main() {
    CircularLinkedList cl;
    cl.insertHead(3);
    cl.insertHead(2);
    cl.insertEnd(4);
    cl.insertEnd(5);

    cl.display(); // 2 3 4 5

    cl.deleteVal(3);
    cl.display(); // 2 4 5

    cout << (cl.search(4) ? "Found" : "Not found") << "\n";

    return 0;
}

