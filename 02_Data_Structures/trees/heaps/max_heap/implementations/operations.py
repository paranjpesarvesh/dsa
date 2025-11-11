# operations.py
# -----------------------------------------------------------------------------
# Max Heap Operations (Array-based, 0-indexed)
# -----------------------------------------------------------------------------
# Problem / Description:
#   Implement a Max Heap supporting:
#     - push/insert(x)
#     - peek() -> current maximum
#     - pop()  -> extract and return maximum
#     - build_heap(iterable) in O(n)
#     - heapify(i) (internal), increase_key, replace
#     - heap_sort (non-destructive)
#
# Why a Max Heap?
#   - Complete binary tree stored in an array with the heap property:
#       A[parent(i)] >= A[i] for all i
#   - Parent/child indices (0-indexed):
#       parent(i) = (i - 1) // 2
#       left(i)   = 2*i + 1
#       right(i)  = 2*i + 2
#
# Algorithmic notes:
#   - Insertion: append at end, then "sift up" until heap property holds.
#   - Extract max: swap A[0] with A[last], pop last, then "sift down" from 0.
#   - Build heap: run sift down from last internal node down to 0 (O(n)).
#
# Complexity:
#   - push:       O(log n)
#   - pop:        O(log n)
#   - peek:       O(1)
#   - build_heap: O(n)
#   - heap_sort:  O(n log n) time, O(n) extra (non-destructive variant below)
#
# Variations:
#   - 1-indexed heap: simplifies children indices; costs one dummy slot.
#   - Python heapq wrapper for max-heap via negation (see class MaxHeapHeapq).
#
# -----------------------------------------------------------------------------

from __future__ import annotations
from typing import Generic, Iterable, List, Optional, Sequence, Tuple, TypeVar

T = TypeVar("T")


class MaxHeap(Generic[T]):
    """
    A generic 0-indexed array-based Max Heap.

    Attributes:
        a: internal dynamic array (Python list)

    Methods:
        push(x): insert x
        peek(): return max element without removing
        pop(): extract and return max element
        build_heap(iterable): build in O(n)
        replace(x): pop max and push x in a single O(log n)
        increase_key(i, new_val): set a[i]=new_val with new_val >= old (sift up)
        heap_sort(): return a sorted (descending) list; non-destructive
        __len__(): size
        __bool__(): non-emptiness
    """

    __slots__ = ("a",)

    def __init__(self, data: Optional[Iterable[T]] = None) -> None:
        self.a: List[T] = []
        if data is not None:
            self.build_heap(data)

    # ---------- index helpers ----------
    @staticmethod
    def _parent(i: int) -> int:
        return (i - 1) // 2

    @staticmethod
    def _left(i: int) -> int:
        return 2 * i + 1

    @staticmethod
    def _right(i: int) -> int:
        return 2 * i + 2

    # ---------- core heapify routines ----------
    def _sift_up(self, i: int) -> None:
        """Move a[i] upward until heap property holds."""
        a = self.a
        while i > 0:
            p = self._parent(i)
            if a[p] >= a[i]:
                break
            a[p], a[i] = a[i], a[p]
            i = p

    def _sift_down(self, i: int) -> None:
        """Move a[i] downward until heap property holds."""
        a = self.a
        n = len(a)
        while True:
            l = self._left(i)
            r = self._right(i)
            largest = i

            if l < n and a[l] > a[largest]:
                largest = l
            if r < n and a[r] > a[largest]:
                largest = r
            if largest == i:
                break
            a[i], a[largest] = a[largest], a[i]
            i = largest

    # ---------- public APIs ----------
    def push(self, x: T) -> None:
        """Insert x into heap.  Amortized O(1) push + O(log n) sift_up."""
        self.a.append(x)
        self._sift_up(len(self.a) - 1)

    def peek(self) -> T:
        """Return max element in O(1). Raises IndexError if empty."""
        if not self.a:
            raise IndexError("peek from empty heap")
        return self.a[0]

    def pop(self) -> T:
        """Extract max in O(log n). Raises IndexError if empty."""
        if not self.a:
            raise IndexError("pop from empty heap")
        a = self.a
        a[0], a[-1] = a[-1], a[0]   # move max to end
        mx = a.pop()                # remove it
        if a:
            self._sift_down(0)      # restore property
        return mx

    def build_heap(self, data: Iterable[T]) -> None:
        """Build a heap from iterable in O(n)."""
        self.a = list(data)
        # start from last internal node down to root
        for i in range((len(self.a) // 2) - 1, -1, -1):
            self._sift_down(i)

    def replace(self, x: T) -> T:
        """
        Pop max and push x in a single O(log n) operation.
        Raises IndexError if empty.
        """
        if not self.a:
            raise IndexError("replace on empty heap")
        mx = self.a[0]
        self.a[0] = x
        self._sift_down(0)
        return mx

    def increase_key(self, i: int, new_val: T) -> None:
        """
        Increase key at index i to new_val (must be >= old value), then sift up.
        O(log n). Raises ValueError if new_val < old value.
        """
        if i < 0 or i >= len(self.a):
            raise IndexError("index out of range")
        if new_val < self.a[i]:
            raise ValueError("new_val must be >= current value for increase_key")
        self.a[i] = new_val
        self._sift_up(i)

    def heap_sort(self) -> List[T]:
        """
        Return a new list with elements sorted in descending order.
        Non-destructive: O(n log n) time, O(n) extra space.
        """
        copy = MaxHeap(self.a)  # O(n) build_heap
        out: List[T] = []
        while copy:
            out.append(copy.pop())
        return out

    # ---------- dunder utilities ----------
    def __len__(self) -> int:
        return len(self.a)

    def __bool__(self) -> bool:
        return bool(self.a)

    def __repr__(self) -> str:
        return f"MaxHeap({self.a})"


# -----------------------------------------------------------------------------
# Optional: Max-Heap wrapper using Python's heapq (min-heap) via negation.
# Useful when you want to leverage a proven C-optimized implementation.
# -----------------------------------------------------------------------------
import heapq


class MaxHeapHeapq(Generic[T]):
    """
    Max-heap implemented on top of heapq (min-heap) by negating keys.

    Only supports comparable numeric-like keys (or provide your own wrapper).
    """

    __slots__ = ("h",)

    def __init__(self, data: Optional[Iterable[T]] = None) -> None:
        self.h: List[T] = []
        if data is not None:
            # store negative values to simulate max-heap
            self.h = [(-x) for x in data]  # type: ignore[operator]
            heapq.heapify(self.h)

    def push(self, x: T) -> None:
        heapq.heappush(self.h, -x)  # type: ignore[operator]

    def peek(self) -> T:
        if not self.h:
            raise IndexError("peek from empty heap")
        return -self.h[0]  # type: ignore[operator]

    def pop(self) -> T:
        if not self.h:
            raise IndexError("pop from empty heap")
        return -heapq.heappop(self.h)  # type: ignore[operator]

    def __len__(self) -> int:
        return len(self.h)

    def __bool__(self) -> bool:
        return bool(self.h)

    def __repr__(self) -> str:
        # materialize a descending snapshot (non-destructive)
        return f"MaxHeapHeapq(size={len(self.h)}, max={self.peek() if self.h else None})"


# -----------------------------------------------------------------------------
# Example usage & quick sanity checks
# -----------------------------------------------------------------------------
if __name__ == "__main__":
    # Array-based heap
    h = MaxHeap[int]([3, 10, 5, 6, 2, 8])
    # Build is O(n)
    print("Initial heap (array-based):", h)
    print("Peek:", h.peek())  # should be 10

    h.push(40)
    print("After push(40):", h.peek())  # 40

    mx = h.pop()
    print("pop() ->", mx)  # 40
    print("Heap after pop:", h)

    # Increase key demo (make element at index 3 very large)
    if len(h) > 3:
        old = h.a[3]
        h.increase_key(3, old + 100)
        print("After increase_key at index 3:", h.peek())

    print("Heap sort (desc):", h.heap_sort())

    # heapq-based variant
    hq = MaxHeapHeapq[int]([3, 10, 5, 6, 2, 8])
    print("Initial heap (heapq-based):", hq)
    hq.push(40)
    print("heapq-based peek:", hq.peek())
    print("heapq-based pop:", hq.pop())
    print("heapq-based size:", len(hq))

