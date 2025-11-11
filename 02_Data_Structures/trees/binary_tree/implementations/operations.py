"""
File: operations.py
Topic: Binary Tree — Core Operations Implementation (Python)

Includes:
- Node class
- Insert (Binary Tree — complete tree style, not BST)
- Traversals (Inorder, Preorder, Postorder, Level-order)
- Height computation
- Count nodes
- Search

NOTE:
This is not a Binary Search Tree. Insertions occur level-wise using BFS.
"""

from collections import deque


# ============================================================================
# Node definition
# ============================================================================
class Node:
    def __init__(self, v):
        self.val = v
        self.left = None
        self.right = None


# ============================================================================
# Insert node level-by-level (for a complete binary tree)
# ============================================================================
def insert(root, v):
    """
    Insert a node level-order-wise.
    Time complexity: O(n)
    """
    if root is None:
        return Node(v)

    q = deque([root])

    while q:
        cur = q.popleft()

        if cur.left is None:
            cur.left = Node(v)
            return root
        q.append(cur.left)

        if cur.right is None:
            cur.right = Node(v)
            return root
        q.append(cur.right)

    return root


# ============================================================================
# Traversals
# ============================================================================

def inorder(root):
    """
    Inorder Traversal: Left -> Root -> Right
    Time complexity: O(n)
    """
    if root is None:
        return
    inorder(root.left)
    print(root.val, end=" ")
    inorder(root.right)


def preorder(root):
    """
    Preorder Traversal: Root -> Left -> Right
    Time complexity: O(n)
    """
    if root is None:
        return
    print(root.val, end=" ")
    preorder(root.left)
    preorder(root.right)


def postorder(root):
    """
    Postorder Traversal: Left -> Right -> Root
    Time complexity: O(n)
    """
    if root is None:
        return
    postorder(root.left)
    postorder(root.right)
    print(root.val, end=" ")


def level_order(root):
    """
    Level-order Traversal (BFS)
    Time complexity: O(n)
    """
    if root is None:
        return

    q = deque([root])
    while q:
        cur = q.popleft()
        print(cur.val, end=" ")
        if cur.left:
            q.append(cur.left)
        if cur.right:
            q.append(cur.right)


# ============================================================================
# Height of binary tree
# ============================================================================
def height(root):
    """
    Height = 1 + max(left subtree height, right subtree height)
    Time complexity: O(n)
    """
    if root is None:
        return 0
    return 1 + max(height(root.left), height(root.right))


# ============================================================================
# Search in binary tree (general, not BST)
# ============================================================================
def search(root, target):
    """
    DFS search in binary tree
    Time complexity: O(n)
    """
    if root is None:
        return False
    if root.val == target:
        return True
    return search(root.left, target) or search(root.right, target)


# ============================================================================
# Count nodes
# ============================================================================
def count_nodes(root):
    """
    Count total nodes in the tree
    Time complexity: O(n)
    """
    if root is None:
        return 0
    return 1 + count_nodes(root.left) + count_nodes(root.right)


# ============================================================================
# Example usage
# ============================================================================
if __name__ == "__main__":
    root = None

    for v in [10, 20, 30, 40, 50]:
        root = insert(root, v)

    print("Inorder: ", end="")
    inorder(root)
    print()

    print("Preorder: ", end="")
    preorder(root)
    print()

    print("Postorder: ", end="")
    postorder(root)
    print()

    print("Level-order: ", end="")
    level_order(root)
    print()

    print("Height:", height(root))
    print("Search 40:", search(root, 40))
    print("Node count:", count_nodes(root))

