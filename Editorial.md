## Brute Force Approach

Brute forcing any number $a_i$ by summing its digits repeatedly has a time complexity of  

$$
\mathcal{O}(\log a_i)
$$  

Hence, the total time complexity is: 

$$
\mathcal{O}(n \log a_i)
$$

which is **too slow** for $n \leq 5 \times 10^6$ and $a_i \leq 10^{18}$.

---

## Observations

Let $f(x)$ be the **sum of digits** of $x$.  
Define $f^0(x) = x$, and $f^{k+1}(x) = f(f^k(x))$.  
Let $s(x)$ be the **stopping distance**, i.e., the smallest $\ell \geq 0$ such that:  
$f^{\ell}(x) = f^{\ell+1}(x)$

---

### Claim 1:  
If $f(x) = x$, then $x$ must be a 1-digit number.

#### Proof:

Let  
$x = d_0 \cdot 10^n + d_1 \cdot 10^{n-1} + \ldots + d_{n-1} \cdot 10 + d_n$  
Then,  
$f(x) = d_0 + d_1 + \ldots + d_n$  
So,  
$f(x) - x = d_0(10^n - 1) + d_1(10^{n-1} - 1) + \ldots + d_{n-1}(10 - 1)$  
Since $d_i \geq 0$ and all $(10^k - 1) > 0$, the only way for this to be zero is:  
$d_0 = d_1 = \ldots = d_{n-1} = 0$  
Thus, $x$ must be a 1-digit number.

---

### Conclusion:

If $f^\ell(x) = f^{\ell+1}(x)$, then $f^\ell(x)$ must be a 1-digit number.  
Hence for any $k \geq 0$, $f^{\ell+k}(x) = f^\ell(x)$  
So, $f^S(a_i)$ is equivalent to applying $f$ repeatedly until the result is a **single-digit number**.

---

## Definition Shortcut

Let $F(x)$ be the **digit root** of $x$, i.e., the final 1-digit result after repeatedly summing digits.  

Then the **beauty** of the array is:  
$b = \sum_{i=1}^{n} F(a_i)$

And the **cuteness** of the array is:  
$F(b) = F\left(\sum_{i=1}^{n} F(a_i)\right)$

---

## Claim 2:  
$$
F(x) = 
\begin{cases}
0 & \text{if } x = 0 \\\\
x \bmod 9 & \text{if } x \bmod 9 \ne 0 \\\\
9 & \text{if } x \bmod 9 = 0,\ x \ne 0
\end{cases}
$$

#### Proof:

Any positive integer $x = 9a + b$, where $b = x \bmod 9$.  
If $b = 0$, then $x$ is divisible by 9, so $F(x) = 9$.

Also, adding 9 to any number doesn’t change its digit root as it is equivalent to add 1 to tens place and subtract 1 from ones place:  
$F(k + 9) = F(k)$  
So by induction:  
$F(9a + b) = F(x) = F(b)$ (if $b \ne 0$), or $9$.

---

## Claim 3:

$F\left(\sum_{i=1}^{n} F(a_i)\right) = F\left(\sum_{i=1}^{n} a_i\right)$

#### Proof:

Using the identity:  
$F(F(a) + F(b)) = F(a \bmod 9 + b \bmod 9) = (a \bmod 9 + b \bmod 9) \bmod 9 = (a + b) \bmod 9 = F(a + b)$  
Note: `mod` here is mapped 1–9.   
Thus $F(F(a) + F(b)) = F(a + b)$  
By induction, this generalizes to all $n$, so:  
$F\left(\sum_{i=1}^{n} F(a_i)\right) = F\left(\sum_{i=1}^{n} a_i\right)$

---

This gives a final time complexity of 

$$
\mathcal{O}(n)
$$  

