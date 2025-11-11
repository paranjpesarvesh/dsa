# File: operations.py
# Topic: Red-Black Tree Operations (Python Version)
#
# This file implements:
# 1. Node structure with color
# 2. Left and right rotations
# 3. Insertion + Fix-up logic
# 4. Inorder traversal
#
# Red-Black Tree properties ensure O(log n) operations by keeping tree height balanced.
#
# Complexity:
# Insert: O(log n)
# Rotations: O(1)
# Space: O(1) auxiliary (besides nodes)


RED = 0
BLACK = 1


class Node:
    def __init__(self, val):
        self.val = val
        self.color = RED
        self.left = None
        self.right = None
        self.parent = None


class RedBlackTree:
    def __init__(self):
        self.root = None

    # Left rotate around x
    def left_rotate(self, x):
        y = x.right
        x.right = y.left
        if y.left:
            y.left.parent = x

        y.parent = x.parent
        if not x.parent:
            self.root = y
        elif x == x.parent.left:
            x.parent.left = y
        else:
            x.parent.right = y

        y.left = x
        x.parent = y

    # Right rotate around x
    def right_rotate(self, x):
        y = x.left
        x.left = y.right
        if y.right:
            y.right.parent = x

        y.parent = x.parent
        if not x.parent:
            self.root = y
        elif x == x.parent.right:
            x.parent.right = y
        else:
            x.parent.left = y

        y.right = x
        x.parent = y

    # Insert into BST then fix RBT properties
    def insert(self, val):
        z = Node(val)
        y = None
        x = self.root

        # Standard BST insert
        while x:
            y = x
            if z.val < x.val:
                x = x.left
            else:
                x = x.right

        z.parent = y

        if not y:
            self.root = z
        elif z.val < y.val:
            y.left = z
        else:
            y.right = z

        # Fix RBT violations
        self.insert_fix(z)

    def insert_fix(self, z):
        while z.parent and z.parent.color == RED:
            p = z.parent
            g = p.parent

            if p == g.left:
                u = g.right
                if u and u.color == RED:
                    p.color = BLACK
                    u.color = BLACK
                    g.color = RED
                    z = g
                else:
                    if z == p.right:
                        z = p
                        self.left_rotate(z)
                    p.color = BLACK
                    g.color = RED
                    self.right_rotate(g)

            else:
                u = g.left
                if u and u.color == RED:
                    p.color = BLACK
                    u.color = BLACK
                    g.color = RED
                    z = g
                else:
                    if z == p.left:
                        z = p
                        self.right_rotate(z)
                    p.color = BLACK
                    g.color = RED
                    self.left_rotate(g)

        self.root.color = BLACK

    def inorder(self, root):
        if not root:
            return
        self.inorder(root.left)
        print(root.val, end=" ")
        self.inorder(root.right)


# Example usage:
if __name__ == "__main__":
    rbt = RedBlackTree()
    rbt.insert(10)
    rbt.insert(20)
    rbt.insert(15)

    print("Inorder traversal:", end=" ")
    rbt.inorder(rbt.root)
    print()

