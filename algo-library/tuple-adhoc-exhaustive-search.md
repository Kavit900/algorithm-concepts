## Problem Description

Consider the following operations on a triple of integers. In one operation, you should:

1. Choose an integer d and an arithmetic operation ― either addition or multiplication.
2. Choose a subset of elements of the triple.
3. Apply the arithmetic operation to each of the chosen elements, i.e. either add d to each of them or multiply each of them by d.
For example, if we have a triple (3,5,7), we may choose to add 3 to the first and third element, and we get (6,5,10) using one operation.

You are given an initial triple (p,q,r) and a target triple (a,b,c). Find the minimum number of operations needed to transform (p,q,r) into (a,b,c).

### Input

The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers p, q and r.
The second line contains three space-separated integers a, b and c.
Output
For each test case, print a single line containing one integer ― the minimum required number of operations.

### Constraints

1≤T≤1,000

|p|,|q|,|r|,|a|,|b|,|c|≤10^9


### Example Input

2
3 5 7
6 5 10
8 6 3
9 7 8

### Example Output

1
2

### Explanation

Example case 1: We add 3 to the first and third element of (3,5,7) to form (6,5,10).

Example case 2: We can add 1 to each element to form (9,7,4) and then multiply the third element by 2.

## Solution

### Explanation

1. First, let us notice that we can always make the initial triplet equal to the final triplet in at most 3 moves, by individually adding the difference between each ai and bi.

2. Next, let us see if we can make the initial triplet equal to the final triplet in just 1 move. This should also be easy to check. (Note that I didn’t handle this explicitly, but it’s an easy case to think about).

3. There are only a few operations (3 at most) that we need to do in the worst-case, hence exploring all possible operations should be doable with such small constraints since the depth of the recursion will be at most 3. But what all numbers can we add (or multiply?)

4. In each operation, we should try to fix at least one of the numbers correct? Hence, the set of all possible numbers we might try to add is restricted to bi - ai for i in {1,2,3}. Just 3 numbers, so quite small.

5. Let’s think about the multiplication case since it’s a bit trickier. Let us say the set mult contains all possible values for multiplication. Then, as in the case of addition, if we are motivated by the fact that atleast one of the numbers must be fixed in a multiplication, then mm should be in multis ai * m = bi for some i. (Remember, both a_i and bi can be 0, so take care).

6. Till now, all our operations had the underlying assumption that after the operation, at least one of the ai should become equal to bi.Consider the following case:

a = [2,3,4]
b = [-20,-1,18]

Using just the operations in Observation 4, the best we can do is 3 operations.
However, try this:

Multiply all the numbers with 19
Add -58 to all the numbers.
There, we only took 2 operations! But how do we get this magic number of 19?

### Algorithm

We use recursion to search exhaustively. Key points:

1. Make a list of all possible additions and multiplications and iterate over them
2. Choose a subset on which to perform that operation.
3. Perform that operation, and call the function itself with the new parameters.
4. To prune, if you see that you have already done 2 operations and still not reached equality condition, just break, since 3 operations will, in any case, be possible.

### Code

```
# v1 - v0 * x = u1 - u0 * x
# (u0 - v0) * x = u1 - v1
def eq_solve(v0, v1, u0, u1):
    den = u0 - v0
    num = u1 - v1
    if den != 0:
        return num / den
    return 1

def solve(p, q, r, a, b, c, rs):
    if p == a and q == b and r == c:
        return rs
    if rs >= 2:
        return 3
    res = 3
    adds = [a - p, b - q, c - r]
    muls = []
    if p != 0:
        muls.append(a / p)
    if q != 0:
        muls.append(b / q)
    if r != 0:
        muls.append(c / r)
    muls.append(eq_solve(p, a, q, b))
    muls.append(eq_solve(p, a, r, c))
    muls.append(eq_solve(q, b, r, c))
    msks = 2 ** 3
    for msk in xrange(msks):
        for add in adds:
            np = p
            nq = q
            nr = r
            if (msk & 1) > 0:
                np += add
            if (msk & 2) > 0:
                nq += add
            if (msk & 4) > 0:
                nr += add
            res = min(res, solve(np, nq, nr, a, b, c, rs + 1))
        for mul in muls:
            np = p
            nq = q
            nr = r
            if (msk & 1) > 0:
                np *= mul
            if (msk & 2) > 0:
                nq *= mul
            if (msk & 4) > 0:
                nr *= mul
            res = min(res, solve(np, nq, nr, a, b, c, rs + 1))
    return res



t = int(raw_input())

while t > 0:
    p, q, r = map(int, raw_input().split())
    a, b, c = map(int, raw_input().split())
    print solve(p, q, r, a, b, c, 0)
    t -= 1
```
