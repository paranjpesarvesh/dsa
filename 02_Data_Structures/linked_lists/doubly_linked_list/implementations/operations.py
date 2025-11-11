# Doubly Linked List Operations (Python)
# ---------------------------------------
#
# This file implements basic operations on a Doubly Linked List:
#   - Insert at front
#   - Insert at end
#   - Delete a value
#   - Traverse forward and backward
#
# Time Complexity:
#   Insert front: O(1)
#   Insert end: O(1)
#   Delete node reference: O(1)
#   Delete by value: O(n)
#   Traversal: O(n)
#
# Space Complexity: O(1) extra
#
# A DLL node has: data, prev pointer, next pointer.
#
# Practical use cases:
#   Implementing LRU cache, text editors (undo/redo), deque-like structures.


class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # Insert at the beginning
    def insert_front(self, value):
        new_node = Node(value)

        if self.head is None:
            self.head = self.tail = new_node
            return

        new_node.next = self.head
        self.head.prev = new_node
        self.head = new_node

    # Insert at the end
    def insert_end(self, value):
        new_node = Node(value)

        if self.tail is None:
            self.head = self.tail = new_node
            return

        self.tail.next = new_node
        new_node.prev = self.tail
        self.tail = new_node

    # Delete the first occurrence of value
    def delete_value(self, value):
        if self.head is None:
            return

        curr = self.head
        while curr and curr.data != value:
            curr = curr.next

        if curr is None:
            return  # not found

        # Case 1: delete head
        if curr == self.head:
            self.head = curr.next
            if self.head:
                self.head.prev = None
            else:
                self.tail = None  # list becomes empty

        # Case 2: delete tail
        elif curr == self.tail:
            self.tail = curr.prev
            self.tail.next = None

        # Case 3: delete middle node
        else:
            curr.prev.next = curr.next
            curr.next.prev = curr.prev

        del curr

    # Display list forward
    def display_forward(self):
        curr = self.head
        result = []
        while curr:
            result.append(curr.data)
            curr = curr.next
        return result

    # Display list backward
    def display_backward(self):
        curr = self.tail
        result = []
        while curr:
            result.append(curr.data)
            curr = curr.prev
        return result


# Example usage:
if __name__ == "__main__":
    dll = DoublyLinkedList()
    dll.insert_front(10)
    dll.insert_front(20)
    dll.insert_end(5)
    dll.delete_value(20)

    print("Forward:", dll.display_forward())
    print("Backward:", dll.display_backward())

