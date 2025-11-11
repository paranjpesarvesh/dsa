# Deque Operations Implementation (Python)
# File: /02_Data_Structures/stacks_queues/deque/implementations/operations.py
#
# Description:
# Implement a double-ended queue (deque) using a doubly linked list.
# Supports insertion and deletion from both ends in O(1).
#
# Why use this?
# Useful for sliding window problems, BFS optimizations, monotonic queues,
# caching, scheduling, and any scenario requiring efficient operations
# from both ends.
#
# Operations included:
# - push_front(x)
# - push_back(x)
# - pop_front()
# - pop_back()
# - front()
# - back()
# - is_empty()
# - size()
#
# Time Complexity: O(1) for all operations
# Space Complexity: O(n)

class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class Deque:
    def __init__(self):
        self.head = None
        self.tail = None
        self.count = 0

    def is_empty(self):
        return self.count == 0

    def size(self):
        return self.count

    def push_front(self, x):
        node = Node(x)

        if self.is_empty():
            self.head = self.tail = node
        else:
            node.next = self.head
            self.head.prev = node
            self.head = node

        self.count += 1

    def push_back(self, x):
        node = Node(x)

        if self.is_empty():
            self.head = self.tail = node
        else:
            node.prev = self.tail
            self.tail.next = node
            self.tail = node

        self.count += 1

    def pop_front(self):
        if self.is_empty():
            raise IndexError("Deque underflow")

        val = self.head.data
        temp = self.head

        if self.head == self.tail:  # single element
            self.head = self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None

        self.count -= 1
        return val

    def pop_back(self):
        if self.is_empty():
            raise IndexError("Deque underflow")

        val = self.tail.data
        temp = self.tail

        if self.head == self.tail:  # single element
            self.head = self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None

        self.count -= 1
        return val

    def front(self):
        if self.is_empty():
            raise IndexError("Deque empty")
        return self.head.data

    def back(self):
        if self.is_empty():
            raise IndexError("Deque empty")
        return self.tail.data


# Usage example (can be removed in production)
if __name__ == "__main__":
    dq = Deque()

    dq.push_front(10)
    dq.push_back(20)
    dq.push_front(5)

    print(dq.front())  # 5
    print(dq.back())   # 20

    dq.pop_front()
    dq.pop_back()

    print(dq.front())  # 10

