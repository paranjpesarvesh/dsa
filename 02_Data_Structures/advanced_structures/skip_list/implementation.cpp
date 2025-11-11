// /02_Data_Structures/advanced_structures/skip_list/implementation.cpp
// --------------------------------------------------------------------------------------
// Skip List Implementation (C++)
//
// Description:
//   A Skip List is a probabilistic data structure that supports
//     - search
//     - insert
//     - delete
//   all in expected O(log N) time.
//
// Why Skip List?
//   - Simpler to implement than balanced BSTs (AVL/Red-Black Trees)
//   - Expected logarithmic performance using randomness
//   - Good teaching data structure
//
// Concept:
//   A skip list maintains multiple levels of linked lists.
//   Higher levels "skip" over many nodes, giving fast search performance.
//
//   Levels Example:
//
//     Level 3:       A ------------------------ G
//     Level 2:       A -------- C ------------- G
//     Level 1:       A --- B --- C --- D --- E --- F --- G
//
// Randomization:
//   Coin toss determines whether a node rises to higher levels.
//   Probability p = 0.5 is commonly used.
//
// --------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int value;
    vector<Node*> forward; // forward pointers for multiple levels

    Node(int val, int level)
        : value(val), forward(level + 1, nullptr) {}
};

class SkipList {
private:
    int maxLevel;
    float probability;
    Node* head;

public:
    SkipList(int maxLevel = 16, float probability = 0.5)
        : maxLevel(maxLevel), probability(probability) {
        head = new Node(-1, maxLevel); // sentinel head node
        srand(time(nullptr));
    }

    // Generate random level for new node
    int randomLevel() {
        int level = 0;
        while ((float)rand() / RAND_MAX < probability && level < maxLevel) {
            level++;
        }
        return level;
    }

    // Insert a value
    void insert(int value) {
        vector<Node*> update(maxLevel + 1, nullptr);
        Node* curr = head;

        // 1. Traverse from highest level down
        for (int lvl = maxLevel; lvl >= 0; lvl--) {
            while (curr->forward[lvl] != nullptr && curr->forward[lvl]->value < value) {
                curr = curr->forward[lvl];
            }
            update[lvl] = curr; // track where we dropped from
        }

        // 2. Insert at level 0; node might be multi-level
        int newLevel = randomLevel();
        Node* newNode = new Node(value, newLevel);

        for (int lvl = 0; lvl <= newLevel; lvl++) {
            newNode->forward[lvl] = update[lvl]->forward[lvl];
            update[lvl]->forward[lvl] = newNode;
        }
    }

    // Search for a value in skip list
    bool search(int value) {
        Node* curr = head;
        for (int lvl = maxLevel; lvl >= 0; lvl--) {
            while (curr->forward[lvl] != nullptr && curr->forward[lvl]->value < value) {
                curr = curr->forward[lvl];
            }
        }
        curr = curr->forward[0];
        return curr != nullptr && curr->value == value;
    }

    // Delete a value if exists
    void erase(int value) {
        vector<Node*> update(maxLevel + 1, nullptr);
        Node* curr = head;

        for (int lvl = maxLevel; lvl >= 0; lvl--) {
            while (curr->forward[lvl] != nullptr && curr->forward[lvl]->value < value) {
                curr = curr->forward[lvl];
            }
            update[lvl] = curr;
        }

        curr = curr->forward[0];
        if (curr == nullptr || curr->value != value) {
            return; // not found
        }

        // Remove links level by level
        for (int lvl = 0; lvl <= maxLevel; lvl++) {
            if (update[lvl]->forward[lvl] != curr) break;
            update[lvl]->forward[lvl] = curr->forward[lvl];
        }

        delete curr;
    }

    // Print list for debugging
    void display() {
        cout << "Skip List Structure (Level 0 at bottom):\n";
        for (int lvl = maxLevel; lvl >= 0; lvl--) {
            Node* curr = head->forward[lvl];
            cout << "Level " << lvl << ": ";
            while (curr != nullptr) {
                cout << curr->value << " ";
                curr = curr->forward[lvl];
            }
            cout << "\n";
        }
    }
};

// --------------------------------------------------------------------------------------
// Example usage
// --------------------------------------------------------------------------------------
int main() {
    SkipList sl(4, 0.5);

    sl.insert(10);
    sl.insert(20);
    sl.insert(15);
    sl.insert(30);

    cout << "Display skip list:\n";
    sl.display();

    cout << "Search 15: " << (sl.search(15) ? "Found" : "Not Found") << "\n";
    cout << "Search 40: " << (sl.search(40) ? "Found" : "Not Found") << "\n";

    sl.erase(20);
    cout << "After deleting 20:\n";
    sl.display();

    return 0;
}

// --------------------------------------------------------------------------------------
// Complexity Analysis:
//
// Expected:
//   Search:  O(log N)
//   Insert:  O(log N)
//   Delete:  O(log N)
//
// Worst-case:
//   O(N) for all (if randomization degenerates)
//   But probability of worst-case is extremely small.
//
// Variations:
//   - integer keys, generic template version
//   - concurrent skip list
//   - memory-optimized skip list
//
// End of file
// --------------------------------------------------------------------------------------

