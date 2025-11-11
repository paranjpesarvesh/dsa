# Min Heap Operations Implementation (Python)
# File: /02_Data_Structures/trees/heaps/min_heap/implementations/operations.py
# ------------------------------------------------------------
#
# A Min Heap is a complete binary tree represented as an array where:
# - h[i] <= h[left(i)]
# - h[i] <= h[right(i)]
# - Root (index 0) always contains the minimum element.
#
# Supported operations:
# - insert(x)
# - extract_min()
# - get_min()
# - heapify_up()
# - heapify_down()
#
# Time Complexity:
# insert: O(log n)
# extract_min: O(log n)
# heapify/buildHeap: O(n)
# Space Complexity: O(n)
#
# Use cases:
# - Priority queues
# - Dijkstra's algorithm
# - Prim's MST
# - Anytime you need quick access to the minimum element
# ------------------------------------------------------------

class MinHeap:
    def __init__(self):
        self.h = []  # underlying array

    # -----------------------
    # Utility index functions
    # -----------------------
    def parent(self, i):
        return (i - 1) // 2

    def left(self, i):
        return 2 * i + 1

    def right(self, i):
        return 2 * i + 2

    # -----------------------
    # Heapify Up (after insert)
    # -----------------------
    def heapify_up(self, i):
        while i > 0 and self.h[self.parent(i)] > self.h[i]:
            self.h[self.parent(i)], self.h[i] = self.h[i], self.h[self.parent(i)]
            i = self.parent(i)

    # -----------------------
    # Heapify Down (after extract_min)
    # -----------------------
    def heapify_down(self, i):
        n = len(self.h)
        while True:
            l = self.left(i)
            r = self.right(i)
            smallest = i

            if l < n and self.h[l] < self.h[smallest]:
                smallest = l
            if r < n and self.h[r] < self.h[smallest]:
                smallest = r

            if smallest == i:
                break

            self.h[i], self.h[smallest] = self.h[smallest], self.h[i]
            i = smallest

    # -----------------------
    # Insert element into heap
    # -----------------------
    def insert(self, x):
        self.h.append(x)
        self.heapify_up(len(self.h) - 1)

    # -----------------------
    # Get min element
    # -----------------------
    def get_min(self):
        if not self.h:
            raise IndexError("Heap is empty")
        return self.h[0]

    # -----------------------
    # Extract min + rearrange heap
    # -----------------------
    def extract_min(self):
        if not self.h:
            raise IndexError("Heap is empty")

        root = self.h[0]
        self.h[0] = self.h[-1]
        self.h.pop()

        if self.h:
            self.heapify_down(0)

        return root

    # -----------------------
    # Print heap (level-order)
    # -----------------------
    def print_heap(self):
        print("Heap:", self.h)


# ------------------------------------------------------------
# Example usage
# ------------------------------------------------------------
if __name__ == "__main__":
    mh = MinHeap()
    mh.insert(10)
    mh.insert(4)
    mh.insert(15)
    mh.insert(1)
    mh.insert(20)

    mh.print_heap()

    print("Minimum:", mh.get_min())
    print("Extracted:", mh.extract_min())

    mh.print_heap()

