#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdlib>

using namespace std;

/**
 * GCD using Euclidean Algorithm - O(log min(a,b))
 * Finds greatest common divisor of two numbers
 */
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

/**
 * Extended Euclidean Algorithm - O(log min(a,b))
 * Finds x,y such that ax + by = gcd(a,b)
 */
int extendedGCD(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    
    int x1, y1;
    int gcd_val = extendedGCD(b % a, a, x1, y1);
    
    x = y1 - (b / a) * x1;
    y = x1 - (b / a) * y1;
    
    return gcd_val;
}

/**
 * Modular Exponentiation - O(log n)
 * Computes (base^exp) % mod efficiently
 */
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp >>= 1;
        base = (base * base) % mod;
    }
    
    return result;
}

/**
 * Modular Inverse using Extended Euclidean - O(log n)
 * Finds modular inverse when mod is prime
 */
long long modInverse(long long a, long long mod) {
    int x, y;
    int gcd_val = extendedGCD(a, mod, x, y);
    
    if (gcd_val != 1) {
        return -1; // Inverse doesn't exist
    }
    
    return (x % mod + mod) % mod;
}

/**
 * Sieve of Eratosthenes - O(n log log n)
 * Generates all prime numbers up to n
 */
vector<int> sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }
    }
    
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    
    return primes;
}

/**
 * Miller-Rabin Primality Test - O(k log³ n)
 * Probabilistic primality test
 */
bool isPrime(long long n, int k = 5) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    
    long long d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    
    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 4);
        long long x = modExp(a, d, n);
        
        if (x == 1 || x == n - 1 || x == n + 1) {
            return false;
        }
    }
    
    return true;
}

// Test function
void testMathematicalAlgorithms() {
    cout << "=== Mathematical Algorithms ===" << endl;
    
    cout << "GCD(48, 18): " << gcd(48, 18) << endl;
    
    int x, y;
    int gcd_val = extendedGCD(48, 18, x, y);
    cout << "Extended GCD(48, 18): gcd=" << gcd_val << ", x=" << x << ", y=" << y << endl;
    
    cout << "ModExp(2, 10, 1000): " << modExp(2, 10, 1000) << endl;
    
    cout << "ModInverse(3, 11): " << modInverse(3, 11) << endl;
    
    cout << "Primes up to 30: ";
    vector<int> primes = sieveOfEratosthenes(30);
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;
    
    cout << "Is 97 prime? " << (isPrime(97) ? "Yes" : "No") << endl;
}

int main() {
    testMathematicalAlgorithms();
    return 0;
}