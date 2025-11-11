// operations.cpp
// Implementation of core AVL Tree operations
// Includes insertion, deletion, rotations, and height/balance calculations
// AVL tree maintains height balance: |balance_factor| ≤ 1 for all nodes
// Time Complexity: O(log n)
// Space Complexity: O(h) due to recursion

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int val;
    Node* left;
    Node* right;
    int height;

    Node(int x) : val(x), left(NULL), right(NULL), height(1) {}
};

// Utility: get height
int height(Node* n) {
    return n ? n->height : 0;
}

// Utility: get balance factor
int balanceFactor(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

// Update node height
void updateHeight(Node* n) {
    n->height = max(height(n->left), height(n->right)) + 1;
}

// Right rotation (LL Case)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotation (RR Case)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    updateHeight(x);
    updateHeight(y);

    return y;
}

// Insert operation
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);
    else
        return root; // no duplicates

    updateHeight(root);

    int bf = balanceFactor(root);

    // LL Case
    if (bf > 1 && key < root->left->val)
        return rightRotate(root);

    // RR Case
    if (bf < -1 && key > root->right->val)
        return leftRotate(root);

    // LR Case
    if (bf > 1 && key > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (bf < -1 && key < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Find minimum node
Node* minValueNode(Node* n) {
    while (n->left)
        n = n->left;
    return n;
}

// Delete operation
Node* deleteNode(Node* root, int key) {
    if (!root) return NULL;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp)
                root = NULL;
            else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }

    if (!root) return root;

    updateHeight(root);

    int bf = balanceFactor(root);

    // LL Case
    if (bf > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);

    // LR Case
    if (bf > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RR Case
    if (bf < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);

    // RL Case
    if (bf < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder traversal for verification
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Usage example (uncomment when testing)
/*
int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    inorder(root); // prints sorted elements
    cout << endl;

    root = deleteNode(root, 40);
    inorder(root);
}
*/


