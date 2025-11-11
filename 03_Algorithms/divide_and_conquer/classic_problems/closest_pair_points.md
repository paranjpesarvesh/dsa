# Closest Pair of Points — Divide & Conquer Approach

The **Closest Pair of Points** problem is a classic divide-and-conquer algorithmic challenge.
Given *n* points on a 2D plane, find the pair with the minimum Euclidean distance.

This problem demonstrates how divide-and-conquer can reduce complexity from **O(n²)** (brute force) to **O(n log n)**.

---

## 1. Problem Definition

Given a set of points
P = { (x₁, y₁), (x₂, y₂), ..., (xₙ, yₙ) },
find the minimum distance between any two points.

Distance formula:
d(p, q) = √((xₚ − x_q)² + (yₚ − y_q)²)

---

## 2. Why is this a Divide-and-Conquer Problem?

A naive solution checks all pairs → n(n−1)/2 comparisons → O(n²).

But with divide-and-conquer:

1. Sort points by x-coordinate.
2. Recursively solve left and right halves.
3. Combine solutions by checking a narrow strip of width `2δ` around the divide.

This reduces complexity to O(n log n).

---

## 3. Step-by-Step Algorithm

### Step 1: Sort points by x-coordinate

```
sort Px by x
```

### Step 2: Divide into two halves

```
mid = n/2
Left  = Px[0..mid-1]
Right = Px[mid..n-1]
```

### Step 3: Solve recursively

```
d_left  = closest(Left)
d_right = closest(Right)

δ = min(d_left, d_right)
```

### Step 4: Form the "strip"

We gather all points whose x-coordinate is within δ of the dividing line.

```
strip = [p for p in Px if abs(p.x - mid_x) < δ]
sort strip by y
```

### Step 5: Compare each point to the next few in the strip

Key property:
In the strip, each point must only be checked against the **next 6 points** (proven geometrically).

---

## 4. Pseudocode

```
function closest_pair(P):
    sort P by x → Px
    return solve(Px)

function solve(Px):
    if |Px| <= 3:
        return brute_force_distance(Px)

    mid = |Px| / 2
    Left  = Px[0..mid-1]
    Right = Px[mid..]

    d_left  = solve(Left)
    d_right = solve(Right)

    δ = min(d_left, d_right)

    strip = points within δ of dividing line
    sort strip by y

    return min(δ, strip_closest(strip, δ))


function strip_closest(strip, δ):
    for i from 0 to len(strip)-1:
        for j from i+1 to min(i+7, len(strip)-1):
            compute dist(strip[i], strip[j])
            update best
    return best
```

---

## 5. Visual Illustration

### Divide into left and right halves

```
——————————————— midpoint ————————————————
Left half                              Right half
```

### δ-strip region

```
      |<---- δ ---->|<---- δ ---->|
------------- midpoint --------------
       points in strip only
```

Only a narrow vertical band is examined during the merge step.

---

## 6. Complexity Analysis

| Step               | Time                  |
| ------------------ | --------------------- |
| Sorting            | O(n log n)            |
| Recursive division | T(n) = 2T(n/2) + O(n) |
| Solve strip        | O(n)                  |
| Total              | O(n log n)            |

Space complexity:

* O(n) for recursion & temporary arrays.

---

## 7. Variations and Edge Cases

### Variations

* Closest pair in 3D (still O(n log n))
* Manhattan distance variant
* Dynamic closest pair (needs specialized data structure)
* Find k-th closest pair (more complex)

### Edge Cases

* Duplicate points → answer becomes 0
* Points on same vertical/horizontal line
* Very large coordinate values (watch for overflow)

---

## 8. Interview Tips

* Be ready to explain **why only next 6 points** in strip need checking.
* Diagram helps immensely. Draw it.
* Mention that brute force works for n ≤ 3.
* Stress the key insight:
  *divide halves, compute recursively, process strip efficiently.*

### Common interviewer questions:

1. Why does sorting by y in strip help?
2. Explain merge step intuition.
3. Can we solve without sorting initially?
4. What is complexity and why not O(n log² n)?

---

## 9. Practice Problems

### LeetCode

* No direct problem, but concept used in:

  * Max Points on a Line
  * K-d Tree related problems

### GFG

* Closest Pair of Points in 2D Plane

### Codeforces

* Computational geometry problems involving point distances

---
