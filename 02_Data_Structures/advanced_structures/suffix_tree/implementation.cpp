// /02_Data_Structures/advanced_structures/suffix_tree/implementation.cpp
// ----------------------------------------------------------------------------------------------------
// Ukkonen’s Algorithm — Suffix Tree Construction (C++)
//
// Description:
//   - Online suffix tree construction in O(n)
//   - Adds characters one-by-one and maintains an "active point"
//   - Uses suffix links to ensure amortized O(1) updates
//   - Supports efficient substring queries
//
// Features:
//   - Builds an implicit suffix tree with unique end marker ('$')
//   - Pattern search in O(m)
//   - Edge compression using (start, end) indices
//
// Time Complexity:
//   Build:  O(n)
//   Search: O(m)
// Space Complexity: O(n)
//
// Notes:
//   This is an educational and clear implementation, not the most memory-optimized version.
// ----------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct Node {
    map<char, Node*> next;
    int start;
    int* end;
    Node* suffixLink;

    Node(int s, int* e) : start(s), end(e), suffixLink(nullptr) {}
};

class SuffixTree {
public:
    string s;
    Node* root;

    Node* activeNode;
    int activeEdge;
    int activeLength;

    int remaining;
    int pos;

    Node* lastCreated;
    int* leafEnd;

    SuffixTree(const string& str) {
        s = str + "$"; // add terminal
        root = new Node(-1, new int(-1));

        activeNode = root;
        activeEdge = -1;
        activeLength = 0;

        remaining = 0;
        pos = -1;

        leafEnd = new int(-1);
        lastCreated = nullptr;

        build();
    }

    int edgeLength(Node* n) {
        return *(n->end) - n->start + 1;
    }

    void build() {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            extend(i);
        }
    }

    void extend(int i) {
        pos = i;
        *leafEnd = i;
        remaining++;
        lastCreated = nullptr;

        while (remaining > 0) {
            if (activeLength == 0) activeEdge = i;
            char c = s[activeEdge];

            // Rule 2: create new leaf
            if (!activeNode->next.count(c)) {
                activeNode->next[c] = new Node(i, leafEnd);

                if (lastCreated != nullptr) {
                    lastCreated->suffixLink = activeNode;
                    lastCreated = nullptr;
                }
            }
            else {
                Node* nxt = activeNode->next[c];

                if (activeLength >= edgeLength(nxt)) {
                    // walk down
                    activeLength -= edgeLength(nxt);
                    activeEdge += edgeLength(nxt);
                    activeNode = nxt;
                    continue;
                }

                // next character matches, Rule 3
                if (s[nxt->start + activeLength] == s[i]) {
                    activeLength++;

                    if (lastCreated != nullptr && activeNode != root) {
                        lastCreated->suffixLink = activeNode;
                        lastCreated = nullptr;
                    }
                    break;
                }

                // Rule 2 — split edge
                int* splitEnd = new int(nxt->start + activeLength - 1);
                Node* split = new Node(nxt->start, splitEnd);
                activeNode->next[c] = split;

                // new leaf
                split->next[s[i]] = new Node(i, leafEnd);

                // adjust old child
                nxt->start += activeLength;
                split->next[s[nxt->start]] = nxt;

                if (lastCreated != nullptr) {
                    lastCreated->suffixLink = split;
                }
                lastCreated = split;
            }

            remaining--;

            if (activeNode == root && activeLength > 0) {
                activeLength--;
                activeEdge = i - remaining + 1;
            }
            else if (activeNode != root) {
                activeNode = activeNode->suffixLink ? activeNode->suffixLink : root;
            }
        }
    }

    // Search pattern in O(m)
    bool search(const string& p) {
        Node* node = root;
        int i = 0, m = p.size();

        while (i < m) {
            char c = p[i];
            if (!node->next.count(c)) return false;
            Node* nxt = node->next[c];

            int j = nxt->start;
            while (j <= *(nxt->end) && i < m) {
                if (s[j] != p[i]) return false;
                j++;
                i++;
            }
            node = nxt;
        }
        return true;
    }

    // Debug print
    void printTree() {
        cout << "Suffix Tree:\n";
        dfsPrint(root, 0);
    }

    void dfsPrint(Node* node, int depth) {
        for (auto& kv : node->next) {
            Node* nxt = kv.second;
            cout << string(depth, ' ')
                 << s.substr(nxt->start, *(nxt->end) - nxt->start + 1)
                 << "\n";
            dfsPrint(nxt, depth + 4);
        }
    }
};


// ----------------------------------------------------------------------------------------------------
// Example usage / simple validation
// ----------------------------------------------------------------------------------------------------
int main() {
    string s = "banana";
    SuffixTree st(s);

    cout << "Suffix tree built.\n";
    st.printTree();

    vector<string> tests = {"ana", "ban", "na", "x"};
    for (auto& t : tests) {
        cout << "Search '" << t << "': " << (st.search(t) ? "YES" : "NO") << "\n";
    }

    return 0;
}

/*
----------------------------------------------------------------------------------------------------
Notes & Interview Summary:

1) Why use suffix trees?
   - Fast substring queries (O(m))
   - Enables LCS/LRS queries
   - Useful in compression and string analytics

2) Why Ukkonen’s algorithm?
   - Linear time O(n)
   - Requires suffix links and careful implicit tree mechanics

3) Edge cases:
   - Repeat characters
   - Terminal character required ('$')
   - Deep tree without suffix links becomes inefficient

4) Compare with suffix array:
   - Suffix tree: faster queries, heavier memory
   - Suffix array: slower queries (log n factor), lighter memory
----------------------------------------------------------------------------------------------------
*/

