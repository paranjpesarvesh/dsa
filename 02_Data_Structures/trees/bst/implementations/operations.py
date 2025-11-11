# File: operations.py
# Topic: Binary Search Tree (BST) — Core Operations
#
# This file implements essential BST operations in Python:
#   - insert
#   - search
#   - delete
#   - find_min
#   - inorder traversal
#
# BST invariant:
#   left subtree  < node < right subtree
#
# Time Complexity:
#   Insert:  O(h)
#   Search:  O(h)
#   Delete:  O(h)
#   where h is tree height (log n average, n worst case)
#
# The implementation is recursive (cleaner for interviews).

class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


# -------------------------
# Insert into BST
# -------------------------
def insert(root, key):
    """Insert key into BST and return updated root."""
    if root is None:
        return Node(key)

    if key < root.val:
        root.left = insert(root.left, key)
    elif key > root.val:
        root.right = insert(root.right, key)

    return root


# -------------------------
# Search in BST
# -------------------------
def search(root, key):
    """Return True if key exists, else False."""
    if root is None:
        return False
    if root.val == key:
        return True
    if key < root.val:
        return search(root.left, key)
    return search(root.right, key)


# -------------------------
# Find minimum node
# -------------------------
def find_min(root):
    """Returns the node with minimum value in BST."""
    while root and root.left:
        root = root.left
    return root


# -------------------------
# Delete from BST
# -------------------------
def remove_node(root, key):
    """Delete key from BST and return updated root."""
    if root is None:
        return None

    if key < root.val:
        root.left = remove_node(root.left, key)

    elif key > root.val:
        root.right = remove_node(root.right, key)

    else:
        # Node found

        # Case 1: no children
        if root.left is None and root.right is None:
            return None

        # Case 2: one child
        if root.left is None:
            return root.right
        if root.right is None:
            return root.left

        # Case 3: two children
        successor = find_min(root.right)
        root.val = successor.val
        root.right = remove_node(root.right, successor.val)

    return root


# -------------------------
# Inorder traversal (sorted order)
# -------------------------
def inorder(root):
    """Prints BST in sorted order."""
    if root:
        inorder(root.left)
        print(root.val, end=" ")
        inorder(root.right)


# -------------------------
# Example usage
# -------------------------
if __name__ == "__main__":
    root = None

    for x in [50, 30, 20, 40, 70, 60, 80]:
        root = insert(root, x)

    print("Inorder before deletion:", end=" ")
    inorder(root)
    print()

    root = remove_node(root, 50)

    print("Inorder after deletion:", end=" ")
    inorder(root)
    print()

    print("Search 40:", "Found" if search(root, 40) else "Not found")

