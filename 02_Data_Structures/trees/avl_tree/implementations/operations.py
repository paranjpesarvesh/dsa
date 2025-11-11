# operations.py
# AVL Tree (self-balancing BST) — Python implementation
# -----------------------------------------------------
# Features:
#   - Insert, Delete, Search (contains)
#   - Inorder / Preorder traversals
#   - Rotations (LL, RR, LR, RL)
#   - Height & balance management
#
# Why AVL?
#   Strict balance guarantees O(log n) time for search/insert/delete.
#
# Complexity:
#   - Search:  O(log n)
#   - Insert:  O(log n)
#   - Delete:  O(log n)
#   - Space:   O(h) recursion stack, worst h = O(log n) for AVL
#
# Notes / Variations:
#   - For duplicate keys: below we "ignore" duplicates by default.
#     You can adapt policy: count multiplicity or store a list.
#   - Iterative implementations avoid recursion stack; APIs are identical.
#   - For order-statistics (kth/lower_bound), maintain subtree sizes.

from __future__ import annotations
from dataclasses import dataclass
from typing import Optional, Iterable, Generator

@dataclass
class Node:
    key: int
    left: Optional['Node'] = None
    right: Optional['Node'] = None
    height: int = 1  # height of node with leaf = 1

def _height(n: Optional[Node]) -> int:
    return n.height if n else 0

def _update_height(n: Node) -> None:
    n.height = max(_height(n.left), _height(n.right)) + 1

def _balance_factor(n: Optional[Node]) -> int:
    return (_height(n.left) - _height(n.right)) if n else 0

# --- Rotations ---

def _right_rotate(y: Node) -> Node:
    """
         y                      x
        / \                    / \
       x   T3    ->           T1  y
      / \                        / \
     T1 T2                      T2 T3
    """
    x = y.left
    T2 = x.right if x else None

    # Perform rotation
    x.right = y
    y.left = T2

    # Update heights (child first)
    _update_height(y)
    _update_height(x)
    return x

def _left_rotate(x: Node) -> Node:
    """
      x                          y
     / \                        / \
    T1  y        ->            x  T3
       / \                    / \
      T2 T3                  T1 T2
    """
    y = x.right
    T2 = y.left if y else None

    # Perform rotation
    y.left = x
    x.right = T2

    # Update heights (child first)
    _update_height(x)
    _update_height(y)
    return y

def _rebalance(node: Node) -> Node:
    """Recompute height and rotate if unbalanced."""
    _update_height(node)
    bf = _balance_factor(node)

    # LL Case
    if bf > 1 and _balance_factor(node.left) >= 0:
        return _right_rotate(node)

    # LR Case
    if bf > 1 and _balance_factor(node.left) < 0:
        node.left = _left_rotate(node.left)
        return _right_rotate(node)

    # RR Case
    if bf < -1 and _balance_factor(node.right) <= 0:
        return _left_rotate(node)

    # RL Case
    if bf < -1 and _balance_factor(node.right) > 0:
        node.right = _right_rotate(node.right)
        return _left_rotate(node)

    return node  # already balanced

# --- Core Operations ---

def insert(root: Optional[Node], key: int) -> Node:
    """
    Insert key into AVL tree rooted at root; returns new root.
    Duplicates policy: ignore (no insertion).
    """
    if root is None:
        return Node(key)

    if key < root.key:
        root.left = insert(root.left, key)
    elif key > root.key:
        root.right = insert(root.right, key)
    else:
        # duplicate: do nothing (or add policy here)
        return root

    return _rebalance(root)

def _min_node(n: Node) -> Node:
    """Return node with minimum key in subtree."""
    while n.left:
        n = n.left
    return n

def delete(root: Optional[Node], key: int) -> Optional[Node]:
    """
    Delete key from AVL tree rooted at root; returns new root.
    If key not present, tree is unchanged.
    """
    if root is None:
        return None

    if key < root.key:
        root.left = delete(root.left, key)
    elif key > root.key:
        root.right = delete(root.right, key)
    else:
        # Found node to delete
        if not root.left or not root.right:
            # One child or no child: replace by the existing child
            root = root.left if root.left else root.right
        else:
            # Two children: copy inorder successor then delete it
            succ = _min_node(root.right)
            root.key = succ.key
            root.right = delete(root.right, succ.key)

    if root is None:
        return None

    return _rebalance(root)

def contains(root: Optional[Node], key: int) -> bool:
    """Standard BST search."""
    cur = root
    while cur:
        if key < cur.key:
            cur = cur.left
        elif key > cur.key:
            cur = cur.right
        else:
            return True
    return False

# --- Traversals / Utilities ---

def inorder(root: Optional[Node]) -> Generator[int, None, None]:
    """Yield keys in sorted order."""
    if root:
        yield from inorder(root.left)
        yield root.key
        yield from inorder(root.right)

def preorder(root: Optional[Node]) -> Generator[int, None, None]:
    if root:
        yield root.key
        yield from preorder(root.left)
        yield from preorder(root.right)

def build_from_iterable(values: Iterable[int]) -> Optional[Node]:
    """Convenience: build AVL from any iterable of ints."""
    root: Optional[Node] = None
    for v in values:
        root = insert(root, v)
    return root

# --- Example usage (uncomment to run) ---
# if __name__ == "__main__":
#     # Build
#     root = build_from_iterable([10, 20, 30, 40, 50, 25])
#     print("Inorder:", list(inorder(root)))   # Sorted
#     print("Contains 25?", contains(root, 25))
#
#     # Delete
#     root = delete(root, 40)
#     print("After deleting 40:", list(inorder(root)))
#
#     # Structural checks (heights & balance)
#     def check_avl(n: Optional[Node]) -> bool:
#         if not n: return True
#         if abs(_balance_factor(n)) > 1: return False
#         return check_avl(n.left) and check_avl(n.right)
#     print("AVL valid?", check_avl(root))

