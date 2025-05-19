## Sum of Digits

Professor X at IIT Kanpur gave a redemption task to students with low attendance. Student Y, who hasn't attended a single class, must complete this task to pass. Desperate, he seeks your help.

Let $f(x)$ be the **sum of digits** of an integer $x$. For example:

- $f(7) = 7$
- $f(24) = 2 + 4 = 6$

Define:

$$
f^{(k)}(x) = f(f^{(k-1)}(x))
$$

$$
f^{(0)}(x) = x.
$$

The **stopping distance** of an integer $x$, denoted as $s(x)$, is the smallest non-negative integer $\ell$ such that:

$$
f^{(\ell)}(x) = f^{(\ell+1)}(x)
$$

Given an array $a = [a_1, a_2, \dots, a_n]$, define:

- **Strength** of the array:  
  $S = \max(s(a_1), s(a_2), \dots, s(a_n))$
  
- **Beauty** of the array:  
  $b = \sum_{i=1}^{n} f^{(S)}(a_i)$

- **Cuteness** of the array:  
  Let $L = s(b)$, then the **cuteness** is $f^{(L)}(b)$.

---

### Input

- The first line contains a single integer $t$ — the number of test cases.  
  $1 \le t \le 10^4$

- Each test case contains:
  - A line containing an integer $n$ — the size of the array.  
    $1 \le n \le 5 \times 10^6$
  - A line with $n$ space-separated integers $a_1, a_2, \dots, a_n$  
    $1 \le a_i \le 10^{18}$

The sum of $n$ across all test cases does not exceed $5 \times 10^6$.

---

### Output

For each test case, output a single integer — the **cuteness** of the array.

---
