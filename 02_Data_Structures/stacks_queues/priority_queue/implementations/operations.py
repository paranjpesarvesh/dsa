# operations.py
# Priority Queue Implementation (Binary Heap)
# Supports: push, pop, top/peek, size, empty
# Uses a max-heap by default.

# Algorithm:
# - Binary heap stored in Python list
# - Insert: append + heapify-up
# - Pop: swap root with last + remove + heapify-down
#
# Time complexity:
# push: O(log n)
# pop: O(log n)
# peek: O(1)
# space: O(n)

class PriorityQueue:
    def __init__(self):
        self.h = []  # heap array

    def _parent(self, i):
        return (i - 1) // 2

    def _left(self, i):
        return 2 * i + 1

    def _right(self, i):
        return 2 * i + 2

    def _heapify_up(self, i):
        # Move value at index i up to maintain heap property
        while i > 0 and self.h[self._parent(i)] < self.h[i]:
            self.h[self._parent(i)], self.h[i] = self.h[i], self.h[self._parent(i)]
            i = self._parent(i)

    def _heapify_down(self, i):
        # Move value at index i down to maintain heap property
        n = len(self.h)
        while True:
            l = self._left(i)
            r = self._right(i)
            largest = i

            if l < n and self.h[l] > self.h[largest]:
                largest = l
            if r < n and self.h[r] > self.h[largest]:
                largest = r

            if largest == i:
                break

            self.h[i], self.h[largest] = self.h[largest], self.h[i]
            i = largest

    def push(self, x):
        self.h.append(x)
        self._heapify_up(len(self.h) - 1)

    def pop(self):
        if self.empty():
            raise IndexError("PriorityQueue is empty")
        self.h[0], self.h[-1] = self.h[-1], self.h[0]
        self.h.pop()
        if not self.empty():
            self._heapify_down(0)

    def top(self):
        if self.empty():
            raise IndexError("PriorityQueue is empty")
        return self.h[0]

    def empty(self):
        return len(self.h) == 0

    def size(self):
        return len(self.h)


# Example usage:
if __name__ == "__main__":
    pq = PriorityQueue()
    pq.push(10)
    pq.push(30)
    pq.push(20)
    pq.push(5)

    print(pq.top())  # 30
    pq.pop()
    print(pq.top())  # 20

