"""
Bloom Filter Implementation in Python

Problem Statement:
------------------
Implement a Bloom Filter – a space-efficient probabilistic data structure used
to test whether an element is in a set. False positives are possible, but
false negatives are not.

Use Cases:
----------
- Databases (checking cache or storage quickly)
- Web caching (checking if a URL exists)
- Networking (packet filtering, routing tables)
- Security (malware/URL blacklists)

Core Operations:
----------------
- add(item): Insert an item into the Bloom Filter.
- might_contain(item): Check if an item might be in the Bloom Filter.

Key Properties:
---------------
- False positives possible (element reported present when not).
- False negatives impossible (never misses actual inserted elements).

Complexity:
-----------
- Insertion: O(k)   [k = number of hash functions]
- Query: O(k)
- Space: O(m) bits  [m = size of bit array]
"""

import mmh3  # MurmurHash3 for multiple hash functions (fast, non-cryptographic)
from bitarray import bitarray


class BloomFilter:
    def __init__(self, size: int, num_hashes: int):
        """
        Initialize the Bloom Filter.

        :param size: Size of the bit array (m)
        :param num_hashes: Number of hash functions (k)
        """
        self.size = size
        self.num_hashes = num_hashes
        self.bit_array = bitarray(size)
        self.bit_array.setall(0)

    def _hashes(self, item: str):
        """
        Generate multiple hash values for the given item.

        Uses MurmurHash3 with different seeds to simulate multiple hash functions.

        :param item: String item to hash
        :return: Generator of hash indices
        """
        for seed in range(self.num_hashes):
            yield mmh3.hash(item, seed) % self.size

    def add(self, item: str):
        """
        Insert an item into the Bloom Filter.

        :param item: String item to insert
        """
        for index in self._hashes(item):
            self.bit_array[index] = 1

    def might_contain(self, item: str) -> bool:
        """
        Check if the item might be in the Bloom Filter.

        :param item: String item to check
        :return: True if possibly in set, False if definitely not
        """
        return all(self.bit_array[index] for index in self._hashes(item))

    def __str__(self):
        """Return the bit array as a string for debugging."""
        return self.bit_array.to01()


# Example usage
if __name__ == "__main__":
    # Bloom Filter with 1000 bits and 4 hash functions
    bf = BloomFilter(size=1000, num_hashes=4)

    # Insert some items
    bf.add("apple")
    bf.add("banana")
    bf.add("cherry")

    # Check membership
    print("apple:", bf.might_contain("apple"))   # Expected: True
    print("banana:", bf.might_contain("banana")) # Expected: True
    print("cherry:", bf.might_contain("cherry")) # Expected: True
    print("grape:", bf.might_contain("grape"))   # Expected: False (or True due to false positive)

    # Debug: Print bit array
    print("Bit Array Snapshot:", bf)


"""
Mathematical Notes:
-------------------
Optimal number of hash functions (k):
    k = (m/n) * ln(2)
False positive probability (FPP):
    FPP ≈ (1 - e^(-kn/m))^k

Where:
- m = size of bit array
- n = number of inserted elements
- k = number of hash functions

Variations:
-----------
1. Counting Bloom Filter → allows deletion using counters instead of bits.
2. Scalable Bloom Filter → grows dynamically for large datasets.
3. Partitioned Bloom Filter → divides bit array for more uniform distribution.

Interview Tip:
--------------
- Be ready to explain *why false negatives are impossible*.
- If asked about tuning, discuss how to pick `m` and `k` given `n` and desired false positive rate.
"""

