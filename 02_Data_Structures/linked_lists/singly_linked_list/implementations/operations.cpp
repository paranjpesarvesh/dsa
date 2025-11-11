/*
    File: operations.cpp
    Topic: Singly Linked List - Core Operations
    Description:
        This file implements the essential operations for a Singly Linked List:
        - Insert at head
        - Insert at tail
        - Insert at position
        - Delete by value
        - Delete at position
        - Search
        - Traverse

    A Singly Linked List consists of nodes where each node has:
        data + pointer to next node.

    All operations below are implemented using iterative logic.

    Time Complexity Summary:
        Insert head       -> O(1)
        Insert tail       -> O(n)
        Insert at pos     -> O(n)
        Delete by value   -> O(n)
        Delete at pos     -> O(n)
        Search            -> O(n)
        Traverse          -> O(n)
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(NULL) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(NULL) {}

    // Insert at the beginning - O(1)
    void insertHead(int value) {
        Node* n = new Node(value);
        n->next = head;
        head = n;
    }

    // Insert at the end - O(n)
    void insertTail(int value) {
        Node* n = new Node(value);
        if (!head) {
            head = n;
            return;
        }
        Node* curr = head;
        while (curr->next)
            curr = curr->next;
        curr->next = n;
    }

    // Insert at specific position (0-based indexing)
    // O(n)
    void insertAtPos(int pos, int value) {
        if (pos == 0) {
            insertHead(value);
            return;
        }
        Node* curr = head;
        for (int i = 0; curr && i < pos - 1; i++)
            curr = curr->next;

        if (!curr) return; // pos > size

        Node* n = new Node(value);
        n->next = curr->next;
        curr->next = n;
    }

    // Delete first occurrence of a value - O(n)
    void deleteValue(int value) {
        if (!head) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        while (curr->next && curr->next->data != value)
            curr = curr->next;

        if (curr->next) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
        }
    }

    // Delete at given position (0-based) - O(n)
    void deleteAtPos(int pos) {
        if (!head) return;

        if (pos == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        for (int i = 0; curr && i < pos - 1; i++)
            curr = curr->next;

        if (!curr || !curr->next) return;

        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }

    // Search for a value - O(n)
    bool search(int value) {
        Node* curr = head;
        while (curr) {
            if (curr->data == value)
                return true;
            curr = curr->next;
        }
        return false;
    }

    // Traverse and print - O(n)
    void printList() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};


/*
    Variations / Extensions:
        - Reverse list (iterative)
        - Reverse list (recursive)
        - Find middle (slow/fast pointer)
        - Detect cycle (Floyd’s algorithm)
        - Merge two sorted lists
        - Remove duplicates (sorted list)

    These can be added in separate files for advanced operations.
*/


// Example usage
int main() {
    SinglyLinkedList list;
    list.insertHead(10);
    list.insertTail(20);
    list.insertTail(30);
    list.insertAtPos(1, 15);
    list.printList(); // 10 15 20 30

    list.deleteValue(20);
    list.printList(); // 10 15 30

    list.deleteAtPos(0);
    list.printList(); // 15 30

    cout << (list.search(30) ? "Found" : "Not Found") << endl;

    return 0;
}

