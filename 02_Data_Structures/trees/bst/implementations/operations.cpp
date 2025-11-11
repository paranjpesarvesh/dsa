// Topic: Binary Search Tree (BST) — Core Operations
//
// This file provides a clean, interview-ready C++ implementation
// of essential BST operations:
//   - insert
//   - search
//   - delete
//   - min/max lookup
//   - inorder traversal
//
// The implementation maintains BST properties:
//   left subtree  < root < right subtree
//
// Time Complexity (average case):
//   Insert:  O(log n)
//   Search:  O(log n)
//   Delete:  O(log n)
// Worst case (skewed tree): O(n)
// Space: O(h) due to recursion depth
//
// Notes:
//   - Implementation is recursive (cleaner for interviews).
//   - Delete handles all cases: leaf, one-child, two-children.
//   - Inorder traversal gives sorted order.

#include <iostream>
using namespace std;

// -------------------------
// Definition of BST Node
// -------------------------
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int v) : val(v), left(NULL), right(NULL) {}
};

// -------------------------
// Insert into BST
// -------------------------
// If val < node.val  → go left
// If val > node.val  → go right
// Equal values not inserted (stable BST)
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);

    return root;
}

// -------------------------
// Search in BST
// -------------------------
bool search(Node* root, int key) {
    if (!root) return false;
    if (root->val == key) return true;

    if (key < root->val) return search(root->left, key);
    return search(root->right, key);
}

// -------------------------
// Find minimum node
// Used during deletion (successor lookup)
// -------------------------
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

// -------------------------
// Delete from BST
//
// Cases:
// 1) Node not found → return
// 2) Leaf          → delete
// 3) One child     → replace by child
// 4) Two children  → find inorder successor, replace value, delete successor
// -------------------------
Node* removeNode(Node* root, int key) {
    if (!root) return NULL;

    if (key < root->val)
        root->left = removeNode(root->left, key);

    else if (key > root->val)
        root->right = removeNode(root->right, key);

    else {
        // Case: node found

        // Case 1: no children
        if (!root->left && !root->right) {
            delete root;
            return NULL;
        }

        // Case 2: only right child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Case 3: only left child
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 4: two children
        Node* succ = findMin(root->right);
        root->val = succ->val;
        root->right = removeNode(root->right, succ->val);
    }

    return root;
}

// -------------------------
// Inorder traversal
// Produces sorted order
// -------------------------
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// -------------------------
// Example usage
// -------------------------
int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder before deletion: ";
    inorder(root);
    cout << endl;

    root = removeNode(root, 50);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not found") << endl;
}

