# **Fast Fourier Transform (FFT)**

*03 → Algorithms → Mathematical Algorithms*

---

## **1. What Is FFT?**

The **Fast Fourier Transform (FFT)** is an algorithm to compute the **Discrete Fourier Transform (DFT)** in **O(n log n)** time instead of **O(n²)**.

DFT converts a sequence from:

* **time domain** → **frequency domain**

This is essential for:

* Polynomial multiplication
* Convolution
* Signal processing
* Big integer multiplication

In competitive programming, FFT is mainly used for **fast polynomial multiplication**.

---

## **2. DFT Definition (Mathematical Intuition)**

Given array A of size n:

DFT[k] = Σ (A[j] * ωₙ^(j·k)) for j=0..n−1
where:

ωₙ = e^(2πi / n)   (primitive n-th root of unity)

Naively: O(n²)

FFT reduces this by exploiting symmetry.

---

## **3. Core Idea Behind FFT (Divide & Conquer)**

Split polynomial into:

* Even-index terms
* Odd-index terms

Let:

A_even(x) = A[0] + A[2]x + A[4]x² + …
A_odd(x)  = A[1] + A[3]x + A[5]x² + …

DFT(A) = combine(DFT(A_even), DFT(A_odd))

This halves the problem size:

T(n) = 2T(n/2) + O(n)
→ **O(n log n)**

---

## **4. FFT Recurrence Visualization (ASCII)**

Array length 8:

Level 0:  A0 A1 A2 A3 A4 A5 A6 A7
↓ split
Level 1:  Even = [0,2,4,6], Odd = [1,3,5,7]
↓
Level 2:  Split again until size 1
↓
Combine bottom-up using roots of unity

This recursive structure ensures log n depth.

---

## **5. Using FFT for Polynomial Multiplication**

Given two polynomials:

P(x) = Σ aᵢ xⁱ
Q(x) = Σ bᵢ xⁱ

Their product R(x) has coefficients:

R[k] = Σ a[i] * b[k − i]

This is **convolution**.

### Steps:

1. Pad arrays to size ≥ next power of 2
2. Compute FFT(P)
3. Compute FFT(Q)
4. Multiply pointwise: F_R[i] = F_P[i] * F_Q[i]
5. Apply inverse FFT to F_R
6. Round real parts to nearest integer

Total time: **O(n log n)**

---

## **6. Pseudocode (No Code Block)**

function fft(a, invert):
n = size(a)
reorder a using bit-reversal
for len = 2 to n step *= 2:
compute root of unity wlen
for i = 0 to n step len:
w = 1
for j = 0 to len/2:
u = a[i+j]
v = a[i+j+len/2] * w
a[i+j] = u + v
a[i+j+len/2] = u - v
w *= wlen
if invert:
divide all values by n

multiply(A, B):
pad arrays
fft(A)
fft(B)
multiply pointwise
inverse fft

---

## **7. Important Variants**

* **Iterative FFT** → fastest & used in CP
* **Recursive FFT** → easier to understand
* **Number Theoretic Transform (NTT)**

  * Works modulo prime
  * Avoids floating-point precision issues
* **Bluestein FFT** → non-power-of-two sizes
* **Karatsuba & Toom-Cook** → big integer multiplication alternatives

---

## **8. Complexity Analysis**

| Operation                          | Time           |
| ---------------------------------- | -------------- |
| FFT                                | **O(n log n)** |
| Polynomial multiplication with FFT | **O(n log n)** |
| Space                              | **O(n)**       |

---

## **9. Edge Cases / Issues**

* Floating point precision errors

  * Rounding needed
  * NTT avoids this
* Must pad to power of 2
* Complex number overflow if not using long double
* Large inputs need careful normalization

---

## **10. Applications**

* Polynomial multiplication
* Big integer multiplication (up to 10⁶ digits)
* Signal filtering
* Circular convolutions
* Audio/image processing
* Calculating convolution on CF / ICPC problems

---

## **11. Interview Tips**

Though rarely asked in standard interviews, FFT may appear in:

* Senior/ICPC-style algorithm rounds
* Polynomial multiplication questions
* “Multiply two numbers with millions of digits”
* Understanding DFT/FFT basics

What interviewers check:

* That you know FFT = fast convolution
* Why O(n log n) vs O(n²)
* Role of roots of unity
* Link between FFT and polynomial operations

---

## **12. Practice Problems**

**Codeforces:**

* 598E — polynomial multiplications
* 909G — convolution
* 622F — series expansions

**AtCoder:**

* Convolution library tasks
* NTT-heavy problems

**GFG:**

* Polynomial multiplication with FFT

---

If you want, I can generate an FFT implementation template (iterative + recursive) or an NTT version for modular arithmetic.

