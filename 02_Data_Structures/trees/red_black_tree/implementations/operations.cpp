// File: operations.cpp
// Topic: Red-Black Tree Operations
//
// This file contains core operations for a Red-Black Tree (RBT):
// 1. Insertion with fix-up
// 2. Left/Right rotations
//
// The primary goal of an RBT is to maintain balanced height (O(log n))
// while ensuring search, insert, and delete operations remain efficient.
//
// Red-Black Tree Rules:
// 1. Every node is either RED or BLACK
// 2. Root is always BLACK
// 3. No two consecutive RED nodes (no RED parent-child)
// 4. All NULL leaves (external nodes) are BLACK
// 5. Every path from root to a leaf has the same number of BLACK nodes
//
// This implementation includes core insert operations and balancing logic.
// Delete operation (along with fix-up) is more complex and can be added separately.

#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int val;
    Color color;
    Node *left, *right, *parent;
    Node(int v): val(v), color(RED), left(NULL), right(NULL), parent(NULL) {}
};

class RedBlackTree {
public:
    Node* root;

    RedBlackTree() { root = NULL; }

    // Utility: left rotate
    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left) y->left->parent = x;

        y->parent = x->parent;

        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    // Utility: right rotate
    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right) y->right->parent = x;

        y->parent = x->parent;

        if (!x->parent) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;

        y->right = x;
        x->parent = y;
    }

    // Insert value
    void insert(int val) {
        Node* z = new Node(val);
        Node* y = NULL;
        Node* x = root;

        // Standard BST insert
        while (x) {
            y = x;
            if (z->val < x->val) x = x->left;
            else x = x->right;
        }

        z->parent = y;

        if (!y) root = z;
        else if (z->val < y->val) y->left = z;
        else y->right = z;

        // Fix violations
        insertFix(z);
    }

    // Fix insertion violations
    void insertFix(Node* z) {
        while (z->parent && z->parent->color == RED) {
            Node* p = z->parent;
            Node* g = p->parent;

            if (p == g->left) {
                Node* u = g->right;

                if (u && u->color == RED) {
                    p->color = BLACK;
                    u->color = BLACK;
                    g->color = RED;
                    z = g;
                } else {
                    if (z == p->right) {
                        z = p;
                        leftRotate(z);
                    }
                    p->color = BLACK;
                    g->color = RED;
                    rightRotate(g);
                }

            } else {
                Node* u = g->left;

                if (u && u->color == RED) {
                    p->color = BLACK;
                    u->color = BLACK;
                    g->color = RED;
                    z = g;
                } else {
                    if (z == p->left) {
                        z = p;
                        rightRotate(z);
                    }
                    p->color = BLACK;
                    g->color = RED;
                    leftRotate(g);
                }
            }
        }
        root->color = BLACK;
    }

    // Print inorder
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
};

// Complexity Analysis:
// Rotations: O(1)
// Insert: O(log n)
// Insert Fix: O(log n) due to traversing height
// Overall: O(log n)
// Space: O(1) auxiliary apart from nodes created

int main() {
    RedBlackTree rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(15);

    cout << "Inorder traversal: ";
    rbt.inorder(rbt.root);
    cout << endl;
}

