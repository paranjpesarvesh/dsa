# File: operations.py
# Topic: Trie (Prefix Tree) Operations in Python
#
# Implements core trie functions:
#   - insert(word)
#   - search(word)
#   - starts_with(prefix)
#   - delete(word) (optional advanced)
#
# Time Complexity per operation:
#   Insert: O(L)
#   Search: O(L)
#   Prefix: O(L)
# Space Complexity: O(N * alphabet_size)
# where L = length of the word and N = number of stored words.

class TrieNode:
    def __init__(self):
        self.children = {}
        self.end = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    # Insert a word into the trie
    def insert(self, word):
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                cur.children[ch] = TrieNode()
            cur = cur.children[ch]
        cur.end = True

    # Check if word exists
    def search(self, word):
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                return False
            cur = cur.children[ch]
        return cur.end

    # Check if any word begins with prefix
    def starts_with(self, prefix):
        cur = self.root
        for ch in prefix:
            if ch not in cur.children:
                return False
            cur = cur.children[ch]
        return True

    # Optional: delete a word safely
    def delete(self, word):
        return self._delete(self.root, word, 0)

    # Helper to delete nodes only when redundant
    def _delete(self, node, word, idx):
        if idx == len(word):
            if not node.end:
                return False
            node.end = False
            return len(node.children) == 0

        ch = word[idx]
        if ch not in node.children:
            return False

        should_delete = self._delete(node.children[ch], word, idx + 1)

        if should_delete:
            del node.children[ch]
            return not node.end and len(node.children) == 0

        return False


# Example usage:
if __name__ == "__main__":
    t = Trie()
    t.insert("apple")
    t.insert("app")

    print(t.search("apple"))    # True
    print(t.search("app"))      # True
    print(t.search("ap"))       # False
    print(t.starts_with("ap"))  # True

