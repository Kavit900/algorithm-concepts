## Number Theory

### Modulus (%)

We can arrange numbers in a circle and then use `n` as base to perform modular arithmetic.

- for negative numbers it will go anti-clockwise
- for positive numbers it will go clockwise
- a + b = 0 (mod n) , b is inverse of a

#### What is the identity of a number is ?


6 x 1 = 6 (mod 4) , then e (identity) is 1 for number 6

#### What is multiplicative inverse for integers ?

2 x b = 1 (mod m = 5),  so b is inverse of 2 i.e b = 3.

- inverse exists if gcd(a,m) = 1.

### Prime

 - if p is prime then a ^ (p-1) = 1 (mod p)
 - a ^ -1 = a ^ (p-2) (mod p)

- phi(6) = 2  i.e number of whole numbers less than 6 for which gcd(number and 6) = 1 i.e 1,5 = phi(6) = 2.
- phi(p^2) = p^2 - p , because p, 2p, 3p.... all will be divisible by p^2, so we need to remove that
- phi(p^3) = p^3 - p^2

- so pattern is phi(p^k) = p^k - p^(k-1)

- phi(p * q) = (p-1) * (q-1) = phi(q) * phi(q) if gcd(p,q) = 1. 
