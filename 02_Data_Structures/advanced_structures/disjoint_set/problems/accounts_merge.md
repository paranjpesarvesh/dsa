# 🧾 Accounts Merge using Disjoint Set Union (DSU)

---

##  Problem Definition

The **Accounts Merge problem** (LeetCode 721) is a **classic application of Disjoint Set Union (DSU)** where multiple accounts belonging to the same user need to be merged.

* Each account is represented as a **name** and a list of **email addresses**.
* If two accounts share **at least one email**, they belong to the same person.
* We need to **merge these accounts** into a single one.

---

##  Why DSU Works Here?

* Each **email** can be thought of as a **node** in a graph.
* If two emails appear in the same account, they belong to the same **connected component**.
* DSU efficiently groups these connected components by merging sets of related emails.

---

##  Example

Input:

```
accounts = [
  ["John", "johnsmith@mail.com", "john00@mail.com"],
  ["John", "johnnybravo@mail.com"],
  ["John", "johnsmith@mail.com", "john_newyork@mail.com"],
  ["Mary", "mary@mail.com"]
]
```

Processing (step-by-step):

1. `"johnsmith@mail.com"` appears in **account 1** and **account 3** → merge sets.
2. `"john00@mail.com"` connects with `"johnsmith@mail.com"`.
3. `"john_newyork@mail.com"` also connects with `"johnsmith@mail.com"`.

Final Output:

```
[
  ["John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"],
  ["John", "johnnybravo@mail.com"],
  ["Mary", "mary@mail.com"]
]
```

---

##  Pseudocode

```
function accountsMerge(accounts):
    n = number of accounts
    initialize DSU(n)

    email_to_index = {}
    email_to_name = {}

    for i in range(n):
        name = accounts[i][0]
        for email in accounts[i][1:]:
            email_to_name[email] = name
            if email not in email_to_index:
                email_to_index[email] = i
            union(i, email_to_index[email])

    root_to_emails = {}
    for email, idx in email_to_index:
        root = find(idx)
        root_to_emails[root].append(email)

    result = []
    for root, emails in root_to_emails:
        result.append([email_to_name[emails[0]]] + sorted(emails))

    return result
```

---

##  Complexity Analysis

| Operation        | Complexity                                      |
| ---------------- | ----------------------------------------------- |
| Union/Find       | `O(α(N))` (almost constant)                     |
| Building mapping | `O(N * K)` where `K` = avg emails per account   |
| Sorting emails   | `O(M log M)` where `M` = total number of emails |

 Overall complexity: **`O(NK + M log M)`** with `O(M)` space.

---

##  ASCII Visualization

Accounts as email connections:

```
John
 ├── johnsmith@mail.com ── john00@mail.com
 │
 └── john_newyork@mail.com

John
 └── johnnybravo@mail.com

Mary
 └── mary@mail.com
```

Connected components → merged accounts.

---

##  Variations

* **Merging social media accounts** (e.g., multiple usernames pointing to same ID).
* **Phone number + email merging**.
* **Friend circles / groups merging** (similar to LeetCode 547).

---

##  Interview Tips

* Be ready to explain **why DSU is chosen over DFS/BFS**.

  * DSU is **faster for repeated merges**.
* Emphasize **union-find optimizations** (path compression + union by size).
* Common follow-up: *“How would you handle millions of accounts and emails efficiently?”*

---

##  Practice Problems

* [LeetCode 721 – Accounts Merge](https://leetcode.com/problems/accounts-merge/)
* [LeetCode 547 – Number of Provinces](https://leetcode.com/problems/number-of-provinces/)
* [GFG – Disjoint Set (Union-Find)](https://www.geeksforgeeks.org/union-find/)
* [Codeforces – Friends and Presents](https://codeforces.com/problemset/problem/1228/B)

---
