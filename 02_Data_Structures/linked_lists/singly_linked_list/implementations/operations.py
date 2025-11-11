# File: operations.py
# Topic: Singly Linked List - Core Operations
#
# This module implements essential operations of a Singly Linked List:
#   - Insert at head
#   - Insert at tail
#   - Insert at position
#   - Delete by value
#   - Delete at position
#   - Search
#   - Traverse (print)
#
# A singly linked list contains nodes with:
#       data + pointer to next
#
# Time Complexity Summary:
#   Insert head       -> O(1)
#   Insert tail       -> O(n)
#   Insert at pos     -> O(n)
#   Delete by value   -> O(n)
#   Delete at pos     -> O(n)
#   Search            -> O(n)
#   Traverse          -> O(n)


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class SinglyLinkedList:
    def __init__(self):
        self.head = None

    # Insert at beginning - O(1)
    def insert_head(self, value):
        n = Node(value)
        n.next = self.head
        self.head = n

    # Insert at end - O(n)
    def insert_tail(self, value):
        n = Node(value)
        if self.head is None:
            self.head = n
            return

        curr = self.head
        while curr.next:
            curr = curr.next
        curr.next = n

    # Insert at position (0-based) - O(n)
    def insert_at_pos(self, pos, value):
        if pos == 0:
            self.insert_head(value)
            return

        curr = self.head
        for _ in range(pos - 1):
            if curr is None:
                return  # position out of bounds
            curr = curr.next

        if curr is None:
            return

        n = Node(value)
        n.next = curr.next
        curr.next = n

    # Delete first occurrence of a value - O(n)
    def delete_value(self, value):
        if not self.head:
            return

        if self.head.data == value:
            self.head = self.head.next
            return

        curr = self.head
        while curr.next and curr.next.data != value:
            curr = curr.next

        if curr.next:
            curr.next = curr.next.next

    # Delete at given position (0-based) - O(n)
    def delete_at_pos(self, pos):
        if not self.head:
            return

        if pos == 0:
            self.head = self.head.next
            return

        curr = self.head
        for _ in range(pos - 1):
            if curr is None:
                return
            curr = curr.next

        if curr is None or curr.next is None:
            return

        curr.next = curr.next.next

    # Search for a value - O(n)
    def search(self, value):
        curr = self.head
        while curr:
            if curr.data == value:
                return True
            curr = curr.next
        return False

    # Traverse and print - O(n)
    def print_list(self):
        curr = self.head
        res = []
        while curr:
            res.append(str(curr.data))
            curr = curr.next
        print(" ".join(res))


# Example usage
if __name__ == "__main__":
    ll = SinglyLinkedList()
    ll.insert_head(10)
    ll.insert_tail(20)
    ll.insert_tail(30)
    ll.insert_at_pos(1, 15)
    ll.print_list()  # 10 15 20 30

    ll.delete_value(20)
    ll.print_list()  # 10 15 30

    ll.delete_at_pos(0)
    ll.print_list()  # 15 30

    print("Found" if ll.search(30) else "Not Found")

