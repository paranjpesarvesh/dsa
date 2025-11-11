/*
    File: operations.cpp
    Topic: Binary Tree – Core Operations Implementation

    Includes:
    - Node definition
    - Insert (Binary Tree — not BST rules)
    - Traversals (Inorder, Preorder, Postorder, Level-order)
    - Height computation
    - Node count
    - Search (general tree search)
    - Complexity notes

    NOTE:
    This is NOT a Binary Search Tree.
    Insertions occur level-by-level (complete tree style) using a queue.

    Time Complexity:
    - Insert: O(n) worst, O(h) average
    - Traversals: O(n)
    - Height: O(n)
    - Search: O(n)
*/

#include <iostream>
#include <queue>
using namespace std;

// ============================================================================
// Node definition
// ============================================================================
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

// ============================================================================
// Insert in Binary Tree (not BST rules)
// Inserts level-by-level using BFS to find the first empty spot
// ============================================================================
Node* insert(Node* root, int v) {
    if (!root) return new Node(v);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front(); q.pop();

        if (!cur->left) {
            cur->left = new Node(v);
            return root;
        }
        q.push(cur->left);

        if (!cur->right) {
            cur->right = new Node(v);
            return root;
        }
        q.push(cur->right);
    }
    return root;
}

// ============================================================================
// Traversals
// ============================================================================

// Inorder: Left → Root → Right
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Preorder: Root → Left → Right
void preorder(Node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left → Right → Root
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Level-order (BFS)
void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->val << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

// ============================================================================
// Height of tree
// Height = max depth = longest path from root to leaf
// ============================================================================
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// ============================================================================
// Search (general binary tree search)
// ============================================================================
bool search(Node* root, int target) {
    if (!root) return false;
    if (root->val == target) return true;
    return search(root->left, target) || search(root->right, target);
}

// ============================================================================
// Count nodes
// ============================================================================
int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// ============================================================================
// Driver example (optional)
// ============================================================================
int main() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);

    cout << "Inorder: ";
    inorder(root); cout << "\n";

    cout << "Preorder: ";
    preorder(root); cout << "\n";

    cout << "Postorder: ";
    postorder(root); cout << "\n";

    cout << "Level-order: ";
    levelOrder(root); cout << "\n";

    cout << "Height: " << height(root) << "\n";

    cout << "Search 40: " << (search(root, 40) ? "Found" : "Not Found") << "\n";
    cout << "Node count: " << countNodes(root) << "\n";

    return 0;
}

