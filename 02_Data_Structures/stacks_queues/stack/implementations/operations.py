# File: operations.py
# Topic: Stack (Array-based and Linked-list based implementation)
# Description:
#   A complete stack implementation demonstrating LIFO behavior.
#   Supports push, pop, top/peek, size, and is_empty operations.
#
# Algorithm Choice:
#   - Array-based stack: fast O(1) operations using Python list.
#   - Linked-list based stack: dynamic memory growth without overflow.
#
# Time Complexity:
#   Push: O(1)
#   Pop: O(1)
#   Peek: O(1)
#   is_empty: O(1)
#   size: O(1)
#
# Variations:
#   - Dynamic array expansion (handled internally by Python list)
#   - Stack implemented using two queues
#   - Stack implemented using deque (collections.deque)

# --------------------------
# ARRAY-BASED STACK
# --------------------------
class ArrayStack:
    def __init__(self):
        self.arr = []

    def push(self, x):
        self.arr.append(x)  # O(1)

    def pop(self):
        if not self.arr:
            print("Stack Underflow")
            return None
        return self.arr.pop()  # O(1)

    def top(self):
        if not self.arr:
            print("Stack Empty")
            return None
        return self.arr[-1]  # O(1)

    def is_empty(self):
        return len(self.arr) == 0

    def size(self):
        return len(self.arr)


# --------------------------
# LINKED LIST BASED STACK
# --------------------------
class Node:
    def __init__(self, val):
        self.data = val
        self.next = None


class LinkedStack:
    def __init__(self):
        self.head = None
        self.count = 0

    def push(self, x):
        new_node = Node(x)
        new_node.next = self.head
        self.head = new_node
        self.count += 1

    def pop(self):
        if not self.head:
            print("Stack Underflow")
            return None

        value = self.head.data
        self.head = self.head.next
        self.count -= 1
        return value

    def top(self):
        if not self.head:
            print("Stack Empty")
            return None
        return self.head.data

    def is_empty(self):
        return self.head is None

    def size(self):
        return self.count


# --------------------------
# DEMO (Optional)
# --------------------------
if __name__ == "__main__":
    print("ArrayStack demo:")
    s = ArrayStack()
    s.push(10)
    s.push(20)
    print("Top:", s.top())  # 20
    s.pop()
    print("Top after pop:", s.top())  # 10

    print("\nLinkedStack demo:")
    ls = LinkedStack()
    ls.push(5)
    ls.push(15)
    print("Top:", ls.top())  # 15
    ls.pop()
    print("Top after pop:", ls.top())  # 5
