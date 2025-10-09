"""
File: array.py
Path Context: dsa/02_Data_Structures/arrays/implementations/

Problem Statement:
-----------------
Implementation of a basic array data structure in Python with essential operations:
- Access by index
- Insertion at the end
- Deletion by index
- Searching for an element

Algorithm Choice:
-----------------
Python lists provide dynamic resizing and O(1) access by index.
This class wraps Python list functionality to illustrate array operations
and their associated complexities.

Time & Space Complexity:
------------------------
Access by index: O(1)
Insertion at end: O(1) amortized
Insertion at middle/start: O(n)
Deletion: O(n) worst case
Space: O(n) for n elements
"""

class Array:
    def __init__(self, capacity):
        """Initialize the array with a given capacity."""
        self.capacity = capacity
        self.data = [None] * capacity
        self.size = 0

    def insert(self, value):
        """Insert element at the end."""
        if self.size >= self.capacity:
            print(f"Array is full. Cannot insert {value}")
            return
        self.data[self.size] = value
        self.size += 1

    def remove_at(self, index):
        """Remove element at specified index."""
        if index < 0 or index >= self.size:
            print("Invalid index")
            return
        # Shift elements left
        for i in range(index, self.size - 1):
            self.data[i] = self.data[i + 1]
        self.data[self.size - 1] = None
        self.size -= 1

    def search(self, value):
        """Return index of value if present, else -1."""
        for i in range(self.size):
            if self.data[i] == value:
                return i
        return -1

    def get(self, index):
        """Get element at specified index."""
        if index < 0 or index >= self.size:
            print("Invalid index")
            return None
        return self.data[index]

    def print_array(self):
        """Print current array elements."""
        print("Array elements:", end=" ")
        for i in range(self.size):
            print(self.data[i], end=" ")
        print()

    def get_size(self):
        """Return current size."""
        return self.size

    def get_capacity(self):
        """Return maximum capacity."""
        return self.capacity


# Example usage
if __name__ == "__main__":
    arr = Array(5)

    # Insert elements
    arr.insert(10)
    arr.insert(20)
    arr.insert(30)
    arr.insert(40)
    arr.insert(50)

    arr.print_array()  # 10 20 30 40 50

    # Attempt to insert into full array
    arr.insert(60)

    # Delete element at index 2 (30)
    arr.remove_at(2)
    arr.print_array()  # 10 20 40 50

    # Search for element 40
    idx = arr.search(40)
    print(f"Index of 40: {idx}")

    # Access element at index 1
    print(f"Element at index 1: {arr.get(1)}")

"""
Variations:
-----------
1. Dynamic resizing can be implemented to automatically expand capacity.
2. Use Python list directly for simplified implementation.
3. Add methods for insertion at specific index or reversing array.
"""

