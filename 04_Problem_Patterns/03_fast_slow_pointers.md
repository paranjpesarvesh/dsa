# Fast & Slow Pointer Pattern (Tortoise and Hare)

The **Fast & Slow Pointer** pattern is a **powerful technique** for solving problems on **linked lists, arrays, and cycles**. It involves using **two pointers moving at different speeds** to detect cycles, find midpoints, or remove duplicates efficiently.

---

## 1. Definition

In the **Fast & Slow Pointer** approach:

- **Slow pointer:** Moves one step at a time.
- **Fast pointer:** Moves two steps at a time (or more depending on the problem).

**Core idea:** If there is a cycle, the fast pointer will eventually **meet the slow pointer**. For non-cyclic structures, this technique can help **locate midpoints or specific intervals**.

---

## 2. When to Use

Use **Fast & Slow Pointers** when:

- Detecting **cycles** in linked lists or arrays.
- Finding the **middle element** of a linked list.
- Detecting **repeated sequences** in numbers or arrays.
- Solving **tortoise and hare** type problems (Floyd's cycle detection).

**Common problems:**

- Linked list cycle detection.
- Finding the start of a cycle.
- Middle of the linked list.
- Happy numbers problem.

---

## 3. Types of Problems

### 3.1 Cycle Detection (Linked List)

- **Detect cycle existence:** Use two pointers.
- **Find cycle start:** Reset one pointer to head, move both one step at a time.

```

Algorithm:

1. Initialize slow = head, fast = head
2. while fast and fast.next:
   slow = slow\.next
   fast = fast.next.next
   if slow == fast:
   cycle detected
3. To find start:
   slow = head
   while slow != fast:
   slow = slow\.next
   fast = fast.next
   return slow

```

### 3.2 Middle of Linked List

- Move **fast pointer two steps** and **slow pointer one step**.
- When fast reaches the end, slow is at the middle.

```

Algorithm:

1. slow = head, fast = head
2. while fast and fast.next:
   slow = slow\.next
   fast = fast.next.next
3. return slow

````

### 3.3 Detecting Repetition in Numbers (Floyd's Algorithm)

- Use slow and fast on **functional sequences** (e.g., f(x) = sum of squares of digits).
- Detect **cycle in numbers** like Happy Number problem.

---

## 4. Mathematical Intuition

- In a cycle of length `C`, fast pointer moves 2 steps, slow pointer moves 1 step.
- After `k` steps, distance between pointers decreases by 1.
- In at most `C` steps, they **meet inside the cycle**.

---

## 5. Template Approach

### Linked List Cycle Detection

```python
def has_cycle(head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False
````

### Find Cycle Start

```python
def detect_cycle_start(head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            # cycle detected
            slow = head
            while slow != fast:
                slow = slow.next
                fast = fast.next
            return slow
    return None
```

### Find Middle of Linked List

```python
def find_middle(head):
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow
```

---

## 6. Complexity Analysis

| Problem Type              | Time Complexity | Space Complexity |
| ------------------------- | --------------- | ---------------- |
| Cycle detection           | O(n)            | O(1)             |
| Find cycle start          | O(n)            | O(1)             |
| Find middle               | O(n)            | O(1)             |
| Repeated number detection | O(n)            | O(1)             |

---

## 7. Variations & Edge Cases

* **Empty list / single node:** Handle `None` pointers.
* **Even-length list:** Decide if you want the **first or second middle**.
* **Multiple cycles (rare):** Standard approach works for first detected cycle.

---

## 8. Visual Aid

**Linked list with cycle:**

```text
1 -> 2 -> 3 -> 4 -> 5
          ^         |
          |---------|
Slow moves 1 step, Fast moves 2 steps
They meet at node 4
```

**Finding middle:**

```text
1 -> 2 -> 3 -> 4 -> 5
Slow pointer: moves one step each iteration
Fast pointer: moves two steps each iteration
Middle found when fast reaches end
```

---

## 9. Interview Tips

* Always clarify if list may be **empty or single node**.
* Ask whether **fast pointer moves 2 or k steps** (sometimes variable speed is used).
* Use **dummy nodes** if problem requires removal or manipulation.
* Draw the list to **visualize fast/slow movement**.

---

## 10. Practice Problems

| Problem               | Source                                                                   | Type                       |
| --------------------- | ------------------------------------------------------------------------ | -------------------------- |
| Linked List Cycle     | [LeetCode 141](https://leetcode.com/problems/linked-list-cycle/)         | Cycle detection            |
| Linked List Cycle II  | [LeetCode 142](https://leetcode.com/problems/linked-list-cycle-ii/)      | Find cycle start           |
| Middle of Linked List | [LeetCode 876](https://leetcode.com/problems/middle-of-the-linked-list/) | Slow/Fast pointers         |
| Happy Number          | [LeetCode 202](https://leetcode.com/problems/happy-number/)              | Cycle detection in numbers |

---

## References

* [Floyd’s Tortoise and Hare](https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_Tortoise_and_Hare)
* [GeeksforGeeks - Slow and Fast Pointers](https://www.geeksforgeeks.org/slow-and-fast-pointers-technique/)
* [LeetCode Patterns](https://leetcode.com/explore/learn/card/linked-list/)

