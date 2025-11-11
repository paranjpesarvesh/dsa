# File: operations.py
# Topic: B-Tree Operations (Insert, Search, Traverse)
#
# Problem Statement:
# Implement a B-Tree (of minimum degree t) supporting:
#   1) search(key) -> bool
#   2) insert(key)
#   3) traverse() -> in-order-like print/iterate of keys
#
# Notes:
# - B-Tree is a multi-way balanced search tree optimized for block I/O.
# - Each node holds between (t-1) and (2t-1) keys (root is a special case).
# - All leaves are at the same depth.
# - Keys in a node are sorted; children pointers separate key ranges.
#
# Algorithm Choices:
# - Insertion uses top-down splitting: if a child is full, split it before descending.
# - Search is a standard node-local binary-like scan followed by descent.
# - Traversal prints keys in sorted order by recursively traversing children.
#
# Complexity:
# - Search:  O(log n)
# - Insert:  O(log n)
# - Space:   O(n)
#
# Conventions / Edge Cases:
# - Duplicate keys: this implementation IGNOREs duplicates (no multiset).
#   Change the condition in insert_non_full to allow duplicates to go to a side consistently.
# - Minimum degree t must be >= 2.

from __future__ import annotations
from typing import List, Optional, Iterable


class BTreeNode:
    """A B-Tree node."""

    def __init__(self, t: int, leaf: bool):
        assert t >= 2, "Minimum degree t must be >= 2"
        self.t = t
        self.leaf = leaf
        self.keys: List[int] = []            # sorted keys (len in [t-1, 2t-1], except root/leaves during growth)
        self.child: List[BTreeNode] = []     # children pointers (len = len(keys)+1 for internal nodes)

    # ---------- Traversal ----------
    def traverse(self) -> Iterable[int]:
        """Yield all keys in sorted order."""
        if self.leaf:
            for k in self.keys:
                yield k
        else:
            for i, k in enumerate(self.keys):
                # traverse left child i
                yield from self.child[i].traverse()
                # then yield key i
                yield k
            # final rightmost child
            yield from self.child[len(self.keys)].traverse()

    # ---------- Search ----------
    def search(self, k: int) -> Optional["BTreeNode"]:
        """Return the node containing key k, or None."""
        # find first index i s.t. keys[i] >= k (linear scan; could be binary search for micro-optimization)
        i = 0
        while i < len(self.keys) and k > self.keys[i]:
            i += 1

        if i < len(self.keys) and self.keys[i] == k:
            return self

        if self.leaf:
            return None

        return self.child[i].search(k)

    # ---------- Split ----------
    def split_child(self, i: int) -> None:
        """
        Split full child y = child[i] (which must have 2t-1 keys) into two nodes y,z
        and move median up into self.
        """
        t = self.t
        y = self.child[i]
        assert len(y.keys) == 2 * t - 1, "split_child called on non-full child"

        # New node z will store y's last t-1 keys (and children if internal)
        z = BTreeNode(t, y.leaf)
        # Keys: [0..t-2], [t-1], [t..2t-2]
        median_key = y.keys[t - 1]
        z.keys = y.keys[t:]           # last t-1
        y.keys = y.keys[:t - 1]       # first t-1

        if not y.leaf:
            z.child = y.child[t:]     # last t children
            y.child = y.child[:t]     # first t children

        # Insert z as a new child to the right of y
        self.child.insert(i + 1, z)
        # Move median key up into current node
        self.keys.insert(i, median_key)

    # ---------- Insert into Non-Full Node ----------
    def insert_non_full(self, k: int) -> None:
        """Insert key k into this node which is known to be non-full."""
        i = len(self.keys) - 1

        if self.leaf:
            # Place k into the correct position in keys (prevent duplicates)
            # Shift larger keys right, then insert
            # If you want to allow duplicates, change the strict '>' to '>=' or pick a side.
            while i >= 0 and self.keys[i] > k:
                i -= 1
            if i >= 0 and self.keys[i] == k:
                return  # ignore duplicates
            self.keys.insert(i + 1, k)
        else:
            # Find child index to descend
            while i >= 0 and self.keys[i] > k:
                i -= 1
            i += 1

            # If the child is full, split first
            if len(self.child[i].keys) == 2 * self.t - 1:
                self.split_child(i)
                # After split, decide which of the two children to descend into
                if k > self.keys[i]:
                    i += 1
                elif k == self.keys[i]:
                    return  # ignore duplicates

            self.child[i].insert_non_full(k)


class BTree:
    """B-Tree wrapper."""

    def __init__(self, t: int):
        assert t >= 2, "Minimum degree t must be >= 2"
        self.t = t
        self.root: Optional[BTreeNode] = None

    # ---------- Public API ----------
    def search(self, k: int) -> bool:
        """Return True if key k is present."""
        if self.root is None:
            return False
        return self.root.search(k) is not None

    def insert(self, k: int) -> None:
        """Insert key k into the B-Tree (ignores duplicates)."""
        if self.root is None:
            self.root = BTreeNode(self.t, True)
            self.root.keys = [k]
            return

        # If root is full, grow in height
        if len(self.root.keys) == 2 * self.t - 1:
            s = BTreeNode(self.t, False)
            s.child = [self.root]
            s.split_child(0)
            # select child to descend
            i = 0
            if k > s.keys[0]:
                i = 1
            elif k == s.keys[0]:
                self.root = s  # even if duplicate, root changed
                return

            s.child[i].insert_non_full(k)
            self.root = s
        else:
            self.root.insert_non_full(k)

    def traverse(self) -> Iterable[int]:
        """Yield keys in sorted order."""
        if self.root is None:
            return iter(())
        return self.root.traverse()


# ------------------ Example / Quick Test ------------------
# if __name__ == "__main__":
#     bt = BTree(t=3)  # min degree
#     data = [10, 20, 5, 6, 12, 30, 7, 17, 3, 2, 25]
#     for x in data:
#         bt.insert(x)
#
#     print("Traverse:", *bt.traverse())
#     for q in [6, 15, 25, 100]:
#         print(f"search({q}) ->", bt.search(q))
#
# Expected:
# Traverse: 2 3 5 6 7 10 12 17 20 25 30
# search(6) -> True
# search(15) -> False
# search(25) -> True
# search(100) -> False

