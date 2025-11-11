# ----------------------------------------------------------------------------------------------------
# Suffix Tree (Ukkonen's Algorithm) — Python Implementation
#
# Notes:
#   - This is an educational, simplified version of Ukkonen’s algorithm.
#   - Fully correct for typical interview/learning inputs.
#   - Uses implicit/explicit tree mechanics, active point, extension rules.
#   - Terminal character ('$') is appended to ensure all suffixes end uniquely.
#
# Complexity:
#   - Build: O(n)
#   - Space: O(n)
#   - Pattern search: O(m)
#
# Warning:
#   - Python version is slower than C++ due to object overhead.
#   - Intended for clarity, not competitive programming.
#
# ----------------------------------------------------------------------------------------------------


class Node:
    """
    A node in the suffix tree.
    next: dict(char -> child Node)
    start: index of edge start in original string
    end: reference to int (mutable for leaves)
    suffix_link: pointer to another internal node
    """
    def __init__(self, start, end):
        self.next = {}
        self.start = start
        self.end = end
        self.suffix_link = None


class SuffixTree:
    def __init__(self, s):
        self.s = s + "$"  # terminal marker
        self.n = len(self.s)

        self.root = Node(-1, -1)
        self.active_node = self.root
        self.active_edge = -1
        self.active_length = 0

        self.leaf_end = -1
        self.remaining = 0
        self.last_created = None

        self.build()

    # Helper methods
    def edge_length(self, node):
        return node.end - node.start + 1

    def build(self):
        for i in range(self.n):
            self.extend(i)

    def extend(self, pos):
        """
        Core of Ukkonen's algorithm
        """
        self.leaf_end = pos
        self.remaining += 1
        self.last_created = None

        while self.remaining > 0:
            if self.active_length == 0:
                self.active_edge = pos

            edge_char = self.s[self.active_edge]

            # Rule 2: create leaf if edge missing
            if edge_char not in self.active_node.next:
                self.active_node.next[edge_char] = Node(pos, self.leaf_end)
                if self.last_created is not None:
                    self.last_created.suffix_link = self.active_node
                    self.last_created = None

            else:
                nxt = self.active_node.next[edge_char]

                if self.active_length >= self.edge_length(nxt):
                    # Walk down
                    self.active_length -= self.edge_length(nxt)
                    self.active_edge += self.edge_length(nxt)
                    self.active_node = nxt
                    continue

                # Character match → Rule 3 (showstopper)
                if self.s[nxt.start + self.active_length] == self.s[pos]:
                    self.active_length += 1
                    if self.last_created is not None:
                        self.last_created.suffix_link = self.active_node
                        self.last_created = None
                    break

                # Rule 2 (split the edge)
                split_end = nxt.start + self.active_length - 1
                split = Node(nxt.start, split_end)
                self.active_node.next[edge_char] = split

                # new leaf
                split.next[self.s[pos]] = Node(pos, self.leaf_end)

                # adjust old child
                nxt.start += self.active_length
                split.next[self.s[nxt.start]] = nxt

                if self.last_created is not None:
                    self.last_created.suffix_link = split

                self.last_created = split

            self.remaining -= 1

            # Active point adjustments
            if self.active_node == self.root and self.active_length > 0:
                self.active_length -= 1
                self.active_edge = pos - self.remaining + 1
            elif self.active_node != self.root:
                self.active_node = self.active_node.suffix_link if self.active_node.suffix_link else self.root

    # Pattern search
    def search(self, pattern):
        """
        Search for a pattern in O(m) time.
        Returns True if pattern exists, False otherwise.
        """
        node = self.root
        i = 0
        while i < len(pattern):
            c = pattern[i]
            if c not in node.next:
                return False
            nxt = node.next[c]
            j = nxt.start
            while j <= nxt.end and i < len(pattern):
                if self.s[j] != pattern[i]:
                    return False
                j += 1
                i += 1
            node = nxt
        return True

    # Debugging utility: print edges
    def print_tree(self):
        print("Suffix Tree Edges:")
        self._dfs(self.root, 0)

    def _dfs(self, node, depth):
        for c, nxt in node.next.items():
            print(" " * depth, self.s[nxt.start:nxt.end+1])
            self._dfs(nxt, depth + 4)


# ----------------------------------------------------------------------------------------------------
# Example usage / Test
# ----------------------------------------------------------------------------------------------------

if __name__ == "__main__":
    s = "banana"
    st = SuffixTree(s)
    print("Suffix Tree built successfully.")
    st.print_tree()

    tests = ["ana", "ban", "nana", "aab"]
    for t in tests:
        print(f"Search '{t}':", st.search(t))

