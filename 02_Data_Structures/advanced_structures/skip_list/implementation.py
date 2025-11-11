# -------------------------------------------------------------------------------------------------
# Skip List (Python) — Probabilistic Ordered Map / Set
#
# Problem / Goal
#   Maintain an ordered set or map supporting:
#     - search(key)
#     - insert(key[, value])
#     - erase(key)
#   in expected O(log N) time with simple code compared to balanced BSTs.
#
# Data Structure
#   A tower of linked lists (levels). Level 0 is a full sorted list.
#   Each higher level "skips" over multiple nodes to accelerate search.
#   Node height (number of levels the node appears on) is randomized.
#
# Core Ideas
#   - Random level with geometric distribution (p = 0.5 is typical).
#   - Forward pointers: node.forward[level] points to next node on that level.
#   - Search from the top level, move right while next < key, then drop down.
#
# Complexity (Expected)
#   - Search:  O(log N)
#   - Insert:  O(log N)
#   - Erase:   O(log N)
#   - Space:   O(N)
#   Worst-case can be O(N), but occurs with exponentially small probability.
#
# Notes
#   - This implementation supports both Set-like (key only) and Map-like (key, value).
#   - Uses 1 sentinel head with maximum level pointers.
#   - Keys must be comparable (support < and ==).
#
# Variations
#   - Deterministic skip lists (maintainable levels).
#   - Concurrent skip lists (lock-free).
#   - Indexable skip list (support by-rank operations).
# -------------------------------------------------------------------------------------------------

from __future__ import annotations
from dataclasses import dataclass
from typing import Generic, Iterable, Iterator, List, Optional, Tuple, TypeVar, Callable
import random

K = TypeVar("K")
V = TypeVar("V")

@dataclass
class _Node(Generic[K, V]):
    key: K
    value: Optional[V]
    forward: List[Optional["_Node[K, V]"]]

class SkipList(Generic[K, V]):
    def __init__(
        self,
        max_level: int = 32,
        p: float = 0.5,
        key_cmp: Optional[Callable[[K, K], int]] = None
    ) -> None:
        """
        Initialize a Skip List.

        max_level: maximum height - 1 (we use levels 0..max_level-1)
        p: probability to promote a node to the next level
        key_cmp: optional comparator; if None, uses Python's natural ordering
        """
        assert max_level >= 1
        assert 0.0 < p < 1.0
        self._MAX_LEVEL = max_level
        self._P = p
        self._cmp = key_cmp or (lambda a, b: (a > b) - (a < b))
        self._level = 0  # highest current level index (0-based)
        self._size = 0

        # Sentinel head with forward pointers across all levels
        self._head: _Node[K, V] = _Node(key=None, value=None, forward=[None] * self._MAX_LEVEL)  # type: ignore

        # Seed random for reproducibility if desired (comment to keep system randomness)
        # random.seed(0)

    # ---------------------------- Internal Utilities ----------------------------

    def _random_level(self) -> int:
        """Generate a random level with geometric distribution."""
        lvl = 0
        # Promote while coin flip succeeds and we have room
        while lvl + 1 < self._MAX_LEVEL and random.random() < self._P:
            lvl += 1
        return lvl

    def _locate_predecessors(self, key: K) -> List[_Node[K, V]]:
        """
        From top level down, walk right while next.key < key.
        Return the list of 'update' predecessors at each level.
        """
        update: List[_Node[K, V]] = [self._head] * self._MAX_LEVEL
        x = self._head
        for lvl in range(self._level, -1, -1):
            nxt = x.forward[lvl]
            while nxt is not None and self._cmp(nxt.key, key) < 0:
                x = nxt
                nxt = x.forward[lvl]
            update[lvl] = x
        return update

    # ------------------------------ Core Operations -----------------------------

    def search(self, key: K) -> Optional[V]:
        """
        Return value for exact key or None if not found.
        Expected time: O(log N)
        """
        x = self._head
        for lvl in range(self._level, -1, -1):
            nxt = x.forward[lvl]
            while nxt is not None and self._cmp(nxt.key, key) < 0:
                x = nxt
                nxt = x.forward[lvl]
        x = x.forward[0]
        if x is not None and self._cmp(x.key, key) == 0:
            return x.value
        return None

    def contains(self, key: K) -> bool:
        """Set-like membership test."""
        return self.search(key) is not None

    def insert(self, key: K, value: Optional[V] = None) -> None:
        """
        Insert key (and optional value). If key exists, update its value.
        Expected time: O(log N)
        """
        update = self._locate_predecessors(key)
        x = update[0].forward[0]

        # Update existing key
        if x is not None and self._cmp(x.key, key) == 0:
            x.value = value
            return

        # Insert new node with random level
        lvl = self._random_level()
        if lvl > self._level:
            # New highest level appears; head acts as predecessor on new levels
            for i in range(self._level + 1, lvl + 1):
                update[i] = self._head
            self._level = lvl

        new_node = _Node(key=key, value=value, forward=[None] * (lvl + 1))
        for i in range(lvl + 1):
            new_node.forward[i] = update[i].forward[i]
            update[i].forward[i] = new_node

        self._size += 1

    def erase(self, key: K) -> bool:
        """
        Erase key if present. Returns True if erased, False if absent.
        Expected time: O(log N)
        """
        update = self._locate_predecessors(key)
        x = update[0].forward[0]

        if x is None or self._cmp(x.key, key) != 0:
            return False

        # Re-wire pointers from top level down
        for i in range(self._level, -1, -1):
            if update[i].forward[i] is x:
                update[i].forward[i] = x.forward[i]

        # Adjust current highest level if it became empty
        while self._level > 0 and self._head.forward[self._level] is None:
            self._level -= 1

        self._size -= 1
        return True

    # ------------------------------ Convenience API -----------------------------

    def __len__(self) -> int:
        return self._size

    def items(self) -> Iterator[Tuple[K, Optional[V]]]:
        x = self._head.forward[0]
        while x is not None:
            yield (x.key, x.value)
            x = x.forward[0]

    def keys(self) -> Iterator[K]:
        for k, _ in self.items():
            yield k

    def values(self) -> Iterator[Optional[V]]:
        for _, v in self.items():
            yield v

    def __iter__(self) -> Iterator[K]:
        return self.keys()

    def __repr__(self) -> str:
        pairs = ", ".join(f"{k}:{v}" for k, v in self.items())
        return f"SkipList([{pairs}])"

# -------------------------------------------------------------------------------------------------
# Demo / Self-check
# Run: python implementation.cpy < input  (or just execute to see simple usage)
# -------------------------------------------------------------------------------------------------
if __name__ == "__main__":
    # Basic usage as ordered set/map
    sl: SkipList[int, Optional[int]] = SkipList(max_level=16, p=0.5)

    # Insert keys (optionally with values)
    for x in [10, 20, 15, 30, 5, 25]:
        sl.insert(x, value=x*x)

    # Search tests
    assert sl.contains(15) and sl.search(15) == 225
    assert not sl.contains(99)

    # Update value
    sl.insert(20, value=-1)
    assert sl.search(20) == -1

    # Erase
    erased = sl.erase(10)
    assert erased and not sl.contains(10)

    # Ordered iteration
    ordered_keys = list(sl.keys())
    assert ordered_keys == sorted(ordered_keys)

    # Print snapshot
    print("Size:", len(sl))
    print("Items:", list(sl.items()))
    print("OK: basic Skip List tests passed.")

# -------------------------------------------------------------------------------------------------
# Complexity & Notes
#
# Expected:
#   Search / Insert / Erase: O(log N)
#   Space: O(N)
#
# Implementation Notes:
#   - _locate_predecessors gathers the last node < key at each level (update array).
#   - insert uses update[] to splice in the new node at all its levels.
#   - erase uses update[] to bypass the node at all levels, then shrinks top level if empty.
#
# Variations & Extensions:
#   - Indexable skip list: maintain span counts per level to support select(k)/rank(key).
#   - Thread-safe / lock-free variants for concurrent systems.
#   - Deterministic levels (e.g., every 2nd node promoted) for repeatability.
# -------------------------------------------------------------------------------------------------

