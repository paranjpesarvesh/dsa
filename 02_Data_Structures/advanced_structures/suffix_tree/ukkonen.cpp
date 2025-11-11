// /02_Data_Structures/advanced_structures/suffix_tree/ukkonen.cpp
// -------------------------------------------------------------------------------------------------
// Ukkonen’s Algorithm (C++) — Linear-Time Suffix Tree Construction
//
// Problem:
//   Build a compressed trie (suffix tree) for string S so that substring queries are efficient.
//   We also expose simple pattern search and "find all occurrences" helpers.
//
// Highlights of Ukkonen (online, O(n)):
//   - Extend the tree one character at a time.
//   - Maintain Active Point: (activeNode, activeEdge, activeLength).
//   - Use suffix links between internal nodes to keep amortized O(1) per extension.
//   - Represent edges by (start, end) indices into the original string; leaves share a mutable end.
//
// Operations provided in this file:
//   - Build suffix tree in O(n)
//   - Search pattern existence in O(m)
//   - Find all occurrences' starting indices (O(m + occ))
//   - Debug print of all edges
//
// Notes:
//   - We append a unique terminal '$' to S to ensure each suffix ends at a leaf.
//   - This implementation favors clarity over micro-optimizations.
//
// Complexity:
//   Build:   O(n)
//   Search:  O(m)
//   Memory:  O(n)
// -------------------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

struct Node {
    // children by first character of outgoing edge
    map<char, Node*> next;

    // edge = s[start..*end]; for root, start=-1, end points to -1
    int start;
    int* end;               // shared among leaves (mutable global end)

    Node* suffixLink;       // suffix link for Ukkonen

    Node(int s, int* e) : start(s), end(e), suffixLink(nullptr) {}
};

class SuffixTree {
public:
    explicit SuffixTree(string str) {
        s = std::move(str);
        if (s.empty() || s.back() != '$') s.push_back('$'); // ensure unique terminal

        root = new Node(-1, new int(-1));

        activeNode = root;
        activeEdge = -1;
        activeLength = 0;

        leafEnd = new int(-1);
        lastCreatedInternal = nullptr;

        remaining = 0;
        pos = -1;

        build(); // O(n)
    }

    // Check if pattern p appears in s
    bool contains(const string& p) const {
        int i = 0, m = (int)p.size();
        const Node* node = root;
        while (i < m) {
            char c = p[i];
            auto it = node->next.find(c);
            if (it == node->next.end()) return false;
            const Node* child = it->second;

            int j = child->start;
            while (j <= *child->end && i < m) {
                if (s[j] != p[i]) return false;
                ++j; ++i;
            }
            node = child;
        }
        return true;
    }

    // Find all starting positions where pattern p occurs (sorted)
    // Walk down by p; when exhausted, collect leaf starting indices under that node.
    vector<int> find_all(const string& p) const {
        int i = 0, m = (int)p.size();
        const Node* node = root;
        while (i < m) {
            char c = p[i];
            auto it = node->next.find(c);
            if (it == node->next.end()) return {};
            const Node* child = it->second;

            int j = child->start;
            while (j <= *child->end && i < m) {
                if (s[j] != p[i]) return {};
                ++j; ++i;
            }
            node = child;
        }
        vector<int> res;
        collectLeafStarts(node, res);
        sort(res.begin(), res.end());
        return res;
    }

    // Debug: print all edges
    void print_edges() const {
        cout << "Suffix Tree Edges (labels):\n";
        dfs_print(root, 0);
    }

private:
    string s;
    Node* root;

    // Ukkonen state
    Node* activeNode;
    int activeEdge;    // index in s (start char of active edge)
    int activeLength;  // how deep we are on the active edge

    int* leafEnd;               // shared end for all current-phase leaves
    Node* lastCreatedInternal;  // to connect suffix links
    int remaining;              // how many suffixes to add
    int pos;                    // last added character index

    // --- Helpers for Ukkonen ---

    inline int edge_length(const Node* n) const {
        return *(n->end) - n->start + 1;
    }

    inline char edge_char(int idx) const {
        return s[idx];
    }

    // Walk-down optimization: if activeLength is beyond current edge, descend.
    bool walk_down(Node* nxt) {
        int elen = edge_length(nxt);
        if (activeLength >= elen) {
            activeEdge += elen;
            activeLength -= elen;
            activeNode = nxt;
            return true;
        }
        return false;
    }

    void build() {
        for (int i = 0; i < (int)s.size(); ++i) extend(i);
    }

    // Core of Ukkonen: extend with s[i]
    void extend(int i) {
        *leafEnd = i;        // extend all open leaves to i
        ++remaining;         // one more suffix to add
        lastCreatedInternal = nullptr;
        pos = i;

        while (remaining > 0) {
            // If we're not on an edge, next activeEdge is current character
            if (activeLength == 0) activeEdge = i;

            char c = edge_char(activeEdge);

            // Case 1: No edge from activeNode starting with c -> create leaf
            if (!activeNode->next.count(c)) {
                activeNode->next[c] = new Node(i, leafEnd);   // new leaf

                // Suffix link for previously created internal node (if any)
                if (lastCreatedInternal != nullptr) {
                    lastCreatedInternal->suffixLink = activeNode;
                    lastCreatedInternal = nullptr;
                }
            }
            else {
                Node* nxt = activeNode->next[c];

                // If our activeLength goes beyond this edge, walk down
                if (walk_down(nxt)) continue;

                // Case 2: Next character on the edge matches s[i] -> Rule 3 (show-stopper)
                if (s[nxt->start + activeLength] == s[i]) {
                    ++activeLength;

                    if (lastCreatedInternal != nullptr && activeNode != root) {
                        lastCreatedInternal->suffixLink = activeNode;
                        lastCreatedInternal = nullptr;
                    }
                    break; // current phase ends
                }

                // Case 3: Split edge and create new internal + leaf (Rule 2)
                int* splitEnd = new int(nxt->start + activeLength - 1);
                Node* split = new Node(nxt->start, splitEnd);
                activeNode->next[c] = split;

                // New leaf for s[i]
                split->next[s[i]] = new Node(i, leafEnd);

                // Adjust old child to start from the split
                nxt->start += activeLength;
                split->next[s[nxt->start]] = nxt;

                // Suffix link connection
                if (lastCreatedInternal != nullptr) {
                    lastCreatedInternal->suffixLink = split;
                }
                lastCreatedInternal = split;
            }

            // One suffix handled
            --remaining;

            // Active point rule updates
            if (activeNode == root && activeLength > 0) {
                // Rule: if at root and we have activeLength, reduce it and shift activeEdge
                --activeLength;
                activeEdge = i - remaining + 1;
            } else if (activeNode != root) {
                // Follow suffix link if possible
                activeNode = (activeNode->suffixLink != nullptr) ? activeNode->suffixLink : root;
            }
        }
    }

    // Collect starting indices of leaves in the subtree rooted at 'node'
    void collectLeafStarts(const Node* node, vector<int>& out) const {
        if (node == nullptr) return;
        if (node->next.empty()) {
            // Leaf: starting index of suffix is (i - depth + 1). For labeled edges with end index,
            // the leaf start is (pos - path_length + 1). However, in classical Ukkonen,
            // a leaf’s start index is (suffix starting position) = node->start - path_depth_offset + 1.
            // Easier approach: compute from edge label to terminal '$':
            // For leaves, '*end' will be last index of string; the suffix start is (*end - leafDepth + 1).
            // To avoid path-depth bookkeeping, recover from path by walking to '$'.
            // Simpler: when hitting a leaf, its suffix start = s.size() - 1 - path_label_length_to_here.
            // But we don't store path length here, so use alternative:
            // In standard Ukkonen representation for leaves created at time t (pos), the suffix start is (i - remaining + 1)
            // Not directly stored; instead, we can infer by going to the left until we reach '$'.
            //
            // Practical workaround for this repo:
            //   The starting index of the suffix represented by this leaf equals node->start - pathOffset + 1.
            //   Since we do not store path offset, we can derive from the leaf edge label:
            //   a leaf ends at leafEnd (= n-1). The suffix start is (*end - pathLen + 1).
            //   pathLen can be recovered if we propagate depth; to keep code simple, we compute via DFS with depth.
            // => Therefore, this function is called from a wrapper that tracks depth. See overloaded version below.
            return; // Will never reach here; we use the depth-aware overload.
        }
        for (auto& kv : node->next) (void)kv;
    }

    void collectLeafStartsDepth(const Node* node, int pathLen, vector<int>& out) const {
        if (node->next.empty()) {
            // Leaf: suffix ends at n-1 (because of '$'), so start = (n-1) - pathLen + 1
            int n = (int)s.size();
            int startIdx = (n - 1) - pathLen + 1;
            out.push_back(startIdx);
            return;
        }
        for (const auto& kv : node->next) {
            const Node* child = kv.second;
            int elen = edge_length(child);
            collectLeafStartsDepth(child, pathLen + elen, out);
        }
    }

    void collectLeafStarts(const Node* node, vector<int>& out) const {
        // wrapper that starts with pathLen = 0 from 'node'
        if (node == nullptr) return;
        if (node == root) {
            for (const auto& kv : node->next) {
                const Node* child = kv.second;
                collectLeafStartsDepth(child, edge_length(child), out);
            }
        } else {
            // node is somewhere in the tree; collect from here
            collectLeafStartsDepth(node, 0, out);
        }
    }

    void dfs_print(const Node* node, int depth) const {
        for (const auto& kv : node->next) {
            const Node* nxt = kv.second;
            cout << string(depth, ' ')
                 << s.substr(nxt->start, *(nxt->end) - nxt->start + 1) << "\n";
            dfs_print(nxt, depth + 4);
        }
    }
};

// -------------------------------------------------------------------------------------------------
// Example usage / quick self-check
//   Input: none (uses built-in sample). Feel free to wire stdin for contests.
// -------------------------------------------------------------------------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text = "banana";
    SuffixTree st(text);

    st.print_edges();

    vector<string> queries = {"ana", "ban", "nana", "aba", "a", "banana"};
    for (const auto& q : queries) {
        cout << "contains(\"" << q << "\"): " << (st.contains(q) ? "YES" : "NO") << "\n";
        auto occ = st.find_all(q);
        cout << "occurrences: ";
        if (occ.empty()) cout << "none\n";
        else {
            for (int i = 0; i < (int)occ.size(); ++i)
                cout << occ[i] << (i + 1 == (int)occ.size() ? '\n' : ' ');
        }
    }

    return 0;
}

/*
----------------------------------------------------------------------------------------------------
Implementation Notes / Interview Cliff Notes

1) Active Point:
   - (activeNode, activeEdge, activeLength)
   - If activeLength == 0, the next extension starts on the new character itself.

2) Three classic rules (informal):
   Rule 1 (implicit extension): If next char matches, just increase activeLength (phase stops).
   Rule 2 (new leaf): If next char edge doesn’t exist, create a new leaf.
   Rule 2 split: If mismatch in the middle of an edge, split edge and insert new leaf.
   Rule 3 (show-stopper): When character matches on edge, stop current phase.

3) Suffix Links:
   - Connect internal nodes created in consecutive extensions to speed future steps.
   - If a new internal node is created this step, link the previously created internal node to it.

4) Why terminal '$'?
   - Guarantees all suffixes end at leaves and are unique; avoids suffix being a prefix of another.

5) Compare with Suffix Array:
   - Tree: O(m) query, heavier memory.
   - SA+LCP: O(m log n) pattern search, much lower memory, simpler in practice.

6) Complexity:
   - O(n) time, O(n) memory (amortized bounds rely on suffix links and careful invariants).

Variations:
   - Generalized suffix tree for multiple strings (distinct sentinels).
   - Compressed memory representations (edge hash tables, pooled nodes).
----------------------------------------------------------------------------------------------------
*/

