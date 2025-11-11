# operations.py
# Circular Linked List – Core Operations in Python
#
# Supported operations:
# 1. insert_head
# 2. insert_end
# 3. delete_val
# 4. search
# 5. display
#
# A circular linked list connects the last node back to the head.
# We maintain only 'head' pointer to keep implementation simple.
#
# Time Complexity:
# insert_head: O(n) (to find last node)
# insert_end: O(n)
# delete_val: O(n)
# search: O(n)
# display: O(n)


class Node:
    def __init__(self, val):
        self.data = val
        self.next = None


class CircularLinkedList:
    def __init__(self):
        self.head = None

    def insert_head(self, val):
        new = Node(val)

        if self.head is None:
            self.head = new
            self.head.next = self.head
            return

        temp = self.head
        while temp.next != self.head:
            temp = temp.next

        new.next = self.head
        temp.next = new
        self.head = new

    def insert_end(self, val):
        new = Node(val)

        if self.head is None:
            self.head = new
            self.head.next = self.head
            return

        temp = self.head
        while temp.next != self.head:
            temp = temp.next

        temp.next = new
        new.next = self.head

    def delete_val(self, val):
        if self.head is None:
            return

        # Single node case
        if self.head.data == val and self.head.next == self.head:
            self.head = None
            return

        curr = self.head
        prev = None

        while curr.data != val:
            prev = curr
            curr = curr.next
            if curr == self.head:
                return  # not found

        # delete head
        if curr == self.head:
            tail = self.head
            while tail.next != self.head:
                tail = tail.next
            self.head = self.head.next
            tail.next = self.head
            return

        prev.next = curr.next

    def search(self, val):
        if self.head is None:
            return False

        temp = self.head
        while True:
            if temp.data == val:
                return True
            temp = temp.next
            if temp == self.head:
                break

        return False

    def display(self):
        if self.head is None:
            print("List is empty")
            return

        temp = self.head
        while True:
            print(temp.data, end=" ")
            temp = temp.next
            if temp == self.head:
                break
        print()


# Example usage
if __name__ == "__main__":
    cl = CircularLinkedList()
    cl.insert_head(3)
    cl.insert_head(2)
    cl.insert_end(4)
    cl.insert_end(5)

    cl.display()  # 2 3 4 5

    cl.delete_val(3)
    cl.display()  # 2 4 5

    print("Search 4:", cl.search(4))
    print("Search 10:", cl.search(10))

