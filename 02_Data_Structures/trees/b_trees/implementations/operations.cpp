// File: operations.cpp
// Topic: B-Tree Operations (Insert, Search, Traverse)
//
// Description:
// This file implements key operations on a B-Tree:
// 1. Search
// 2. Insert
// 3. Node split
// 4. Traversal
//
// B-Tree Properties:
// - Multi-way search tree optimized for disk access
// - Every node can have multiple keys
// - All leaves at same depth
// - Keys inside node are sorted
//
// Complexity:
// Search: O(log n)
// Insert: O(log n)
// Traverse: O(n)
//
// Note: Implementation corresponds to a B-Tree of minimum degree t.
//       Each node contains between t-1 to 2t-1 keys.
//

#include <iostream>
using namespace std;

// -------------------- B-Tree Node --------------------
class BTreeNode {
public:
    int *keys;          // array of keys
    int t;              // minimum degree
    BTreeNode **child;  // array of child pointers
    int n;              // current number of keys
    bool leaf;          // is leaf?

    BTreeNode(int t, bool leaf);

    void traverse();               // print all keys
    BTreeNode* search(int k);      // search key
    void insertNonFull(int k);     // insert key in non-full node
    void splitChild(int i, BTreeNode *y); // split child
};

// -------------------- B-Tree --------------------
class BTree {
public:
    BTreeNode *root;
    int t;

    BTree(int t) {
        root = nullptr;
        this->t = t;
    }

    void traverse() {
        if (root) root->traverse();
    }

    BTreeNode* search(int k) {
        return (root == nullptr) ? nullptr : root->search(k);
    }

    void insert(int k);
};

// --------------------------------------------------------
// Node constructor
// --------------------------------------------------------
BTreeNode::BTreeNode(int t, bool leaf) {
    this->t = t;
    this->leaf = leaf;

    keys = new int[2 * t - 1];
    child = new BTreeNode*[2 * t];

    n = 0;
}

// --------------------------------------------------------
// Traversal (Inorder-like within nodes)
// --------------------------------------------------------
void BTreeNode::traverse() {
    for (int i = 0; i < n; i++) {
        if (!leaf)
            child[i]->traverse();
        cout << keys[i] << " ";
    }

    if (!leaf)
        child[n]->traverse();
}

// --------------------------------------------------------
// Search key in subtree rooted at this node
// --------------------------------------------------------
BTreeNode* BTreeNode::search(int k) {
    int i = 0;

    // find correct key position
    while (i < n && k > keys[i])
        i++;

    // if key found
    if (i < n && keys[i] == k)
        return this;

    if (leaf)
        return nullptr;

    return child[i]->search(k);
}

// --------------------------------------------------------
// Split child y at index i
// --------------------------------------------------------
void BTreeNode::splitChild(int i, BTreeNode *y) {
    BTreeNode *z = new BTreeNode(y->t, y->leaf);

    z->n = t - 1;

    // transfer last t-1 keys
    for (int j = 0; j < t - 1; j++)
        z->keys[j] = y->keys[j + t];

    // transfer children if internal node
    if (!y->leaf) {
        for (int j = 0; j < t; j++)
            z->child[j] = y->child[j + t];
    }

    y->n = t - 1;

    // shift children of current node
    for (int j = n; j >= i + 1; j--)
        child[j + 1] = child[j];

    child[i + 1] = z;

    // shift keys
    for (int j = n - 1; j >= i; j--)
        keys[j + 1] = keys[j];

    keys[i] = y->keys[t - 1];
    n++;
}

// --------------------------------------------------------
// Insert key into non-full node
// --------------------------------------------------------
void BTreeNode::insertNonFull(int k) {
    int i = n - 1;

    if (leaf) {
        // find location to insert new key
        while (i >= 0 && keys[i] > k) {
            keys[i + 1] = keys[i];
            i--;
        }

        keys[i + 1] = k;
        n++;
    } else {
        // find child to insert key
        while (i >= 0 && keys[i] > k)
            i--;

        i++;

        // if child is full, split
        if (child[i]->n == (2 * t - 1)) {
            splitChild(i, child[i]);

            if (keys[i] < k)
                i++;
        }

        child[i]->insertNonFull(k);
    }
}

// --------------------------------------------------------
// Insert key in B-tree
// --------------------------------------------------------
void BTree::insert(int k) {
    if (root == nullptr) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
        return;
    }

    if (root->n == (2 * t - 1)) {
        BTreeNode *s = new BTreeNode(t, false);
        s->child[0] = root;

        s->splitChild(0, root);

        int i = 0;
        if (s->keys[0] < k)
            i++;

        s->child[i]->insertNonFull(k);
        root = s;
    } else {
        root->insertNonFull(k);
    }
}

// --------------------------------------------------------
// Example usage (remove in production)
// --------------------------------------------------------
/*
int main() {
    BTree t(3); // degree

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);
    t.insert(30);
    t.insert(7);
    t.insert(17);

    cout << "Traversal: ";
    t.traverse();
    cout << endl;

    int key = 6;
    cout << "Search " << key << ": ";
    cout << (t.search(key) ? "Found" : "Not Found") << endl;
}
*/
