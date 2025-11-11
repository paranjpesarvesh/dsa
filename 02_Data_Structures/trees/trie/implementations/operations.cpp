// File: operations.cpp
// Topic: Trie (Prefix Tree) Implementation
//
// This file contains core Trie operations:
// 1. insert(word)
// 2. search(word)
// 3. startsWith(prefix)
//
// A trie efficiently stores strings for prefix queries.
// Time complexities:
//   Insert:   O(L)
//   Search:   O(L)
//   Prefix:   O(L)
// where L = length of the word.
//
// Common interview applications:
//   - Autocomplete
//   - Spell-check
//   - Word existence check
//   - Prefix-based dictionary queries

#include <bits/stdc++.h>
using namespace std;

// Trie Node structure
struct TrieNode {
    bool endOfWord;
    unordered_map<char, TrieNode*> children;

    TrieNode() {
        endOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the trie
    void insert(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children[c]) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->endOfWord = true;
    }

    // Search if a complete word exists in the trie
    bool search(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children.count(c)) return false;
            cur = cur->children[c];
        }
        return cur->endOfWord;
    }

    // Check if any word starts with the given prefix
    bool startsWith(const string& prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            if (!cur->children.count(c)) return false;
            cur = cur->children[c];
        }
        return true;
    }

    // Optional: delete word (advanced)
    bool deleteWord(const string& word) {
        return deleteHelper(root, word, 0);
    }

private:
    // Helper for deletion (removes nodes only if needed)
    bool deleteHelper(TrieNode* node, const string& word, int idx) {
        if (idx == word.size()) {
            if (!node->endOfWord) return false;
            node->endOfWord = false;
            return node->children.empty();
        }

        char c = word[idx];
        if (!node->children.count(c)) return false;

        bool shouldDelete = deleteHelper(node->children[c], word, idx + 1);

        if (shouldDelete) {
            delete node->children[c];
            node->children.erase(c);
            return !node->endOfWord && node->children.empty();
        }

        return false;
    }
};

// Example usage
int main() {
    Trie t;
    t.insert("apple");
    t.insert("app");

    cout << t.search("apple") << endl;     // 1
    cout << t.search("app") << endl;       // 1
    cout << t.search("ap") << endl;        // 0
    cout << t.startsWith("ap") << endl;    // 1

    return 0;
}
