# **Manacher’s Algorithm — Longest Palindromic Substring in O(n)**

---

## **1. Introduction**

**Manacher’s Algorithm** finds the **longest palindromic substring** in a string in **linear time O(n)** — the fastest known algorithm for this task.

It works by:

* Transforming the string to handle even/odd palindromes uniformly
* Maintaining a palindrome radius array
* Using previously computed palindromes to skip redundant expansions

---

## **2. Why Manacher? (Intuition)**

Normally:

* Expand around each center → **O(n²)**
* DP → **O(n²)**

Manacher reduces this by exploiting symmetry.

### **Trick: Transform the string**

Convert `"abba"` → `"^#a#b#b#a#$"`

ASCII view:

```
Original:  a   b   b   a
Modified: ^ # a # b # b # a # $
Index:     0 1 2 3 4 5 6 7 8 9 10
```

Now **every palindrome has an odd length**, simplifying logic.

---

## **3. Core Idea**

Maintain:

* `center` → center of current rightmost palindrome
* `right` → boundary of palindrome
* `P[i]` → radius of palindrome centered at i

For each index `i`:

1. Mirror position: `mirror = 2*center - i`
2. Initialize `P[i]` using mirror information if inside right boundary
3. Expand around `i` while matching
4. Update center and right if we expand beyond current right

---

## **4. Step-by-Step Algorithm Flow**

```
Transform S → T with separators (#)
Initialize P array with zeros
center = right = 0

for i from 1 to n-2:
    mirror = 2*center - i

    if i < right:
        P[i] = min(right - i, P[mirror])

    while T[i + P[i] + 1] == T[i - P[i] - 1]:
        P[i]++

    if i + P[i] > right:
        center = i
        right = i + P[i]
```

Longest palindrome length = `max(P)`
Original substring = extracted by reversing the transformation.

---

## **5. Pseudocode (Clean Template)**

```
manacher(s):
    T = transform(s)
    n = length(T)
    P = array of size n filled with 0
    center = 0
    right = 0

    for i in 1..n-2:
        mirror = 2*center - i

        if i < right:
            P[i] = min(right - i, P[mirror])

        while T[i + P[i] + 1] == T[i - P[i] - 1]:
            P[i]++

        if i + P[i] > right:
            center = i
            right = i + P[i]

    return max(P)
```

---

## **6. Example Visualization**

S = “abaaba”

After transform:

```
^ # a # b # a # a # b # a # $
            ^
            i
P[i] expands outward symmetrically
```

---

## **7. Complexity Analysis**

| Operation          | Time     | Space    |
| ------------------ | -------- | -------- |
| Transform string   | O(n)     | O(n)     |
| Calculate P array  | **O(n)** | O(n)     |
| Extract palindrome | O(n)     | —        |
| **Total**          | **O(n)** | **O(n)** |

---

## **8. Variations / Edge Cases**

* Empty string → answer = “”
* All characters same → entire string is palindrome
* Even length handled automatically by transformation
* Unicode strings require careful char handling

---

## **9. Interview Tips**

* FAANG often asks for **longest palindromic substring** → most propose expand-around-center
* If interviewer demands optimal → mention Manacher
* You should be able to:

  * Explain string transformation
  * Derive mirror logic
  * Show P-array expansion

Manacher is considered **advanced**, so clarity matters more than memorization.

---

## **10. Practice Problems**

### **LeetCode**

* **5. Longest Palindromic Substring**
* 647. Palindromic Substrings (can optimize with Manacher)

### **GFG**

* Longest Palindrome in a String
* Manacher’s Algorithm implementation

### **Codeforces**

* CF EDU Palindromes section
* String tasks involving palindromic radius arrays

---

If you want, I can also generate a **clean C++/Python implementation** for this algorithm.

