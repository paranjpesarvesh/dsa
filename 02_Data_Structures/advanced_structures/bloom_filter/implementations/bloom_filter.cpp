/*
 * Bloom Filter Implementation in C++
 *
 * Problem Statement:
 * ------------------
 * Implement a Bloom Filter – a probabilistic data structure used to test
 * whether an element is a member of a set.
 * False positives are possible, but false negatives are not.
 *
 * Use Case:
 * ---------
 * Common in caching, databases, networking, and security systems where
 * space efficiency and speed are more important than perfect accuracy.
 *
 * Core Operations:
 * ----------------
 * - insert(item): Add an item into the Bloom Filter.
 * - possiblyContains(item): Check if an item might be present in the set.
 *
 * Key Properties:
 * ---------------
 * - False positives possible (may say element exists when it doesn't).
 * - False negatives impossible (never misses actual inserted items).
 *
 * Complexity:
 * -----------
 * - Insertion: O(k)  [k = number of hash functions]
 * - Query: O(k)
 * - Space: O(m) bits [m = size of bit array]
 *
 * Trade-offs:
 * -----------
 * - Increasing m (bit array size) reduces false positive rate.
 * - Increasing k (number of hash functions) reduces false positives up to a point,
 *   but too many increases computation overhead.
 */

#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <functional>

class BloomFilter {
private:
    std::vector<bool> bitArray;   // Bit array for Bloom Filter
    int m;                        // Size of bit array
    int k;                        // Number of hash functions
    std::vector<std::hash<std::string>> hashFunctions;

    // Helper: Generate multiple hash values
    size_t hash(const std::string &item, int seed) const {
        std::hash<std::string> hasher;
        return (hasher(item) + seed * 0x9e3779b9) % m;
        // Mixing with seed to generate multiple hash values
    }

public:
    // Constructor
    BloomFilter(int size, int numHashes) : m(size), k(numHashes) {
        bitArray.resize(m, false);
    }

    // Insert an item into the Bloom Filter
    void insert(const std::string &item) {
        for (int i = 0; i < k; i++) {
            int index = hash(item, i);
            bitArray[index] = true;
        }
    }

    // Check if item is possibly present
    bool possiblyContains(const std::string &item) const {
        for (int i = 0; i < k; i++) {
            int index = hash(item, i);
            if (!bitArray[index]) {
                return false;  // Definitely not in set
            }
        }
        return true;  // Might be in set
    }

    // Debug: Print bit array (for visualization)
    void printBitArray() const {
        for (bool bit : bitArray) {
            std::cout << (bit ? "1" : "0");
        }
        std::cout << std::endl;
    }
};

// Driver code
int main() {
    // Example: Bloom Filter with 100 bits and 3 hash functions
    BloomFilter bf(100, 3);

    // Insert elements
    bf.insert("apple");
    bf.insert("banana");
    bf.insert("cherry");

    // Lookup tests
    std::cout << "apple: " << bf.possiblyContains("apple") << std::endl;   // Expected: 1
    std::cout << "banana: " << bf.possiblyContains("banana") << std::endl; // Expected: 1
    std::cout << "cherry: " << bf.possiblyContains("cherry") << std::endl; // Expected: 1
    std::cout << "grape: " << bf.possiblyContains("grape") << std::endl;   // Expected: maybe 0 or 1 (false positive possible)

    // Print bit array (debugging visualization)
    bf.printBitArray();

    return 0;
}

/*
 * Variations / Extensions:
 * ------------------------
 * 1. Counting Bloom Filter → allows deletion by using counters instead of bits.
 * 2. Scalable Bloom Filter → dynamically grows to handle more elements.
 * 3. Partitioned Bloom Filter → divides bit array among hash functions for better distribution.
 *
 * Interview Tip:
 * --------------
 * - If asked in FAANG/system design: explain *why Bloom Filter is space-efficient*
 *   and how false positives are handled.
 * - Mention tuning trade-offs: choose `m` and `k` based on expected n and desired false positive probability:
 *
 *   k = (m/n) * ln(2)
 *   FPP ≈ (1 - e^(-kn/m))^k
 */
