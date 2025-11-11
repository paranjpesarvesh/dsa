// Doubly Linked List Operations Implementation
// ---------------------------------------------
//
// This file provides basic operations on a Doubly Linked List (DLL):
// - Insert at front
// - Insert at end
// - Delete a node
// - Display forward and backward
//
// A DLL contains nodes with:
//   data, prev pointer, next pointer
//
// Time Complexity:
//   Insertion at head: O(1)
//   Insertion at tail: O(1) if tail maintained, else O(n)
//   Deletion: O(1) once node is found (search is O(n))
//   Traversal: O(n)
//
// Space Complexity: O(1) extra
//
// Variations:
//   - Use sentinel nodes to simplify edge cases
//   - Maintain both head and tail for O(1) operations at both ends
//
// Good for interview demonstration: pointer manipulation skills.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insert a node at the beginning
    void insertFront(int val) {
        Node* n = new Node(val);

        if (head == NULL) {
            head = tail = n;
            return;
        }

        n->next = head;
        head->prev = n;
        head = n;
    }

    // Insert a node at the end
    void insertEnd(int val) {
        Node* n = new Node(val);

        if (tail == NULL) {
            head = tail = n;
            return;
        }

        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    // Delete first occurrence of value
    void deleteValue(int val) {
        if (head == NULL) return;

        Node* curr = head;

        while (curr && curr->data != val) {
            curr = curr->next;
        }

        if (!curr) return; // not found

        // Case 1: deleting head
        if (curr == head) {
            head = head->next;
            if (head) head->prev = NULL;
            else tail = NULL; // list became empty
        }
        // Case 2: deleting tail
        else if (curr == tail) {
            tail = tail->prev;
            tail->next = NULL;
        }
        // Case 3: deleting middle node
        else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        delete curr;
    }

    // Display list forward
    void displayForward() {
        Node* temp = head;
        cout << "Forward: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display list backward
    void displayBackward() {
        Node* temp = tail;
        cout << "Backward: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertFront(10);
    dll.insertFront(20);
    dll.insertEnd(5);
    dll.deleteValue(20);

    dll.displayForward();
    dll.displayBackward();

    return 0;
}
