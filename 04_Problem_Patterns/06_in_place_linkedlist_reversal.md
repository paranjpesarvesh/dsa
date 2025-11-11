# In-Place Linked List Reversal

(Problem Pattern Cheat Sheet)

This pattern appears very frequently in interviews. Many variations rely on the same core technique: **manipulating pointers without using extra space**.

This document covers the intuition, techniques, edge cases, diagrams, templates, and problem list.

---

# 1. Core Idea

In-place reversal modifies the pointers of a linked list **without allocating extra nodes or using auxiliary arrays/stacks**.

The fundamental approach uses three pointers:

```
prev = None
curr = head
next = None
```

At each step:

```
next = curr.next
curr.next = prev
prev = curr
curr = next
```

Final answer = `prev`.

---

# 2. Visual Intuition (ASCII Diagram)

Initial:

```
1 -> 2 -> 3 -> 4 -> 5 -> None
```

Iteration 1:

```
prev=None, curr=1, next=2
1 -> None
prev=1
curr=2
```

Iteration 2:

```
2 -> 1 -> None
```

Iteration 3:

```
3 -> 2 -> 1 -> None
```

Final:

```
5 -> 4 -> 3 -> 2 -> 1 -> None
```

---

# 3. Generic Template (Iterative)

```
function reverse(head):
    prev = None
    curr = head
    while curr != None:
        nxt = curr.next
        curr.next = prev
        prev = curr
        curr = nxt
    return prev
```

Time: O(n)
Space: O(1)

---

# 4. Recursive Template

```
function reverse(head):
    if head == None or head.next == None:
        return head
    newHead = reverse(head.next)
    head.next.next = head
    head.next = None
    return newHead
```

Time: O(n)
Space: O(n) due to recursion stack

---

# 5. Common Patterns Using In-place Reversal

## 1. Reverse Entire Linked List

Simple use of core method.

## 2. Reverse the First k Nodes

Useful in k-group problems.

## 3. Reverse Nodes Between Positions L and R

Steps:

1. Traverse to node at position L-1
2. Reverse sublist L→R
3. Connect back

ASCII layout:

```
head → A → ... → (L-1) → [L → ... → R] → (R+1) → ...
```

## 4. Reverse Every k Nodes (k-group reversal)

* Implement reverse for k nodes
* Recursively/iteratively apply to remaining list
* Pattern appears in top interview problems

## 5. Reverse Alternating k Nodes

Reverse k nodes, skip k nodes.

---

# 6. Detailed Example: Reverse Between L and R

Before:

```
1 → 2 → 3 → 4 → 5
      ↑       ↑
      L=2     R=4
```

After:

```
1 → 4 → 3 → 2 → 5
```

Process:

* Walk to node before L (node 1)
* Reverse sublist 2→3→4
* Connect new reversed part back

---

# 7. Edge Cases

1. **Empty list**
2. **Single node**
3. **L == R** (no changes)
4. **k == 1** (no changes)
5. **L = 1** (head changes)
6. **List < k length** (for k-group)

---

# 8. Interview Tips

1. Always explain the pointer movement step-by-step.
2. Draw diagrams while reversing pointers.
3. Mention O(1) extra space benefit.
4. Discuss recursive vs iterative trade-offs.
5. For k-group questions:
   Check list length first → avoid partial reverse errors.
6. Use dummy nodes to simplify edge cases:
   Especially for reversing sublists.

---

# 9. Pitfalls

* Losing track of nodes (not storing `next`)
* Forgetting to terminate sublists (`tail.next = nextSegment`)
* Not returning updated head
* Not handling reversed section boundaries

---

# 10. Practice Problems

### LeetCode

* 206 Reverse Linked List
* 92 Reverse Linked List II
* 25 Reverse Nodes in k-Group
* 61 Rotate List (uses similar pointer skills)
* 430 Flatten Multilevel Linked List

### GFG

* Reverse Linked List
* Reverse in groups of k

### Codeforces

* Problems involving pointer manipulations in custom structures

---

# 11. Full Pattern Template (All Variants)

```
# reverse full list
def reverse(head):

# reverse first k nodes
def reverseK(head, k):

# reverse in range [L, R]
def reverseBetween(head, L, R):

# reverse alternating k nodes
def reverseAlternateK(head, k):
```

---

# 12. Summary Sheet

* Technique relies on **three pointers**
* Reversal modifies `.next` links directly
* Merge boundaries carefully
* Use dummy nodes for easier edge-case handling
* Know iterative + recursive versions

---
