# **Huffman Coding (Optimal Prefix-Free Compression)**

---

## **1. What Is Huffman Coding?**

Huffman Coding is a **greedy compression algorithm** used to encode characters based on their **frequency**.

Key features:

* Produces **optimal prefix-free codes**
* More frequent characters → **shorter codes**
* Less frequent characters → **longer codes**

Widely used in:

* File compression (ZIP, GZIP)
* Multimedia compression (JPEG, MP3)
* Data transmission

---

## **2. Key Concepts**

### **Prefix-Free Codes**

No code is a prefix of another → decoding is unambiguous.

### **Frequency-Based Tree**

Build a binary tree where:

* Leaf nodes = characters
* Internal nodes = sum of frequencies

---

## **3. Why Greedy?**

At each step:
Choose the **two least frequent nodes** and merge them.

This works because:

* Combining the least frequent characters minimizes added weighted-path cost
* Optimal prefix-free tree proven via greedy-choice and optimal substructure

---

## **4. Huffman Tree Construction (Step-by-Step)**

Given characters with frequencies:
A:5, B:9, C:12, D:13, E:16, F:45

### **Step 1**

Insert all frequencies into a **min-heap**.

### **Step 2**

Repeat until one node remains:

1. Extract two smallest
2. Merge them into new node = sum of their freq
3. Insert merged node back into heap

### **Step 3**

Final node = root of Huffman tree.

---

## **5. ASCII Visualization**

Example with mini data:

Characters: A(5), B(2), C(1)

Steps:

Take C(1) + B(2) → node X(3)
Take X(3) + A(5) → node Y(8)

Tree:

```
    (8)
   /   \
 A(5)  (3)
       / \
    B(2) C(1)
```

Codes:
A = 0
B = 10
C = 11

---

## **6. Generating Huffman Codes**

Traverse the tree:

* Left edge → append '0'
* Right edge → append '1'

Leaf nodes store the final binary code for each character.

---

## **7. Pseudocode (No Code Block)**

create minHeap
for each character c:
push node(freq[c], c)

while heap size > 1:
left = pop smallest
right = pop smallest
merged = new node(left.freq + right.freq)
merged.left = left
merged.right = right
push merged

root = pop heap

# generate codes

dfs(node, code):
if leaf(node):
store code
dfs(node.left, code + "0")
dfs(node.right, code + "1")

---

## **8. Complexity**

| Step                    | Complexity     |
| ----------------------- | -------------- |
| Build heap              | O(N)           |
| Extract + merge N times | O(N log N)     |
| Tree traversal          | O(N)           |
| **Total**               | **O(N log N)** |

Space: O(N)

---

## **9. Edge Cases**

* Only 1 character → assign code “0”
* Characters with equal frequencies → multiple valid trees
* Very large alphabets → heap essential
* Streaming/online Huffman → adaptive Huffman coding

---

## **10. Interview Tips**

Frequently tested because:

* Involves heap, tree, greedy strategy
* Requires understanding of prefix-free code properties
* Practical real-world compression example

Interviewers may ask you to:

* Build Huffman codes manually
* Decode a string using a Huffman tree
* Explain “why greedy is optimal”
* Write min-heap based implementation
* Compare with arithmetic coding / run-length encoding

---

## **11. Practice Problems**

**LeetCode:**

* 451 — Sort Characters by Frequency (related)
* 1642 — Furthest Building (heap practice)

**GFG:**

* Huffman Coding
* Decode Huffman encoded string

**Codeforces:**

* Problems involving cost minimization via merging (similar to Huffman)

---
