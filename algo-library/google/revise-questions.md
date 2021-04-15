## Important questions to revise - concepts

-> [308] Range Sum Query 2D - Mutable
-> [480] Sliding Window Median
-> [85] Maximal Rectangle


## 1314 - matrix block sum
-> solve this by calculating sum of continuous rows and columns and then subtract the out of boundary square submatrix

## 1277 - count squares submatrices with all ones

-> solve this using dp, the current cell is 1, then count itself as a submatrix of 1x1 and it can form a nxn submatrix with current cell as bottom right corner, so take minimum of it's neighbouring cells.

## DP Questions to revise

-> 1140 Stone Game II
-> 935 knight dialer


## What to use when deleting something from start till middle.

-> Use multiset data structure available in c++.
```
multiset<int> hitsCounter;

```

-> To delete something 

```
auto pos = hitscounter.upper_bound(timestamp-300);
hitscounter.erase(hitscounter.begin(), pos);
return hitscounter.size();
```



## OPT Process
1. 2 passport size photos (walgreens or cvs), You must submit two identical color passport-style photographs of yourself taken recently (within 30 days of filing form I-765).
2. Submit new I-20 request e-foorm through iSTART, need to pay $100 for that.
3. Copy of pages 1 & 2 of Form I-20 printed with the OPT endorsement, signed by the DSO and student on page 1.
4. Photocopy of Form I-94 (electronic Form I-94) printout or both sides of cardstock I-94 copied).
5. Photocopies of the following passport pages:
-> Passport ID pages: photo page, page with passport validity dates, including renewal page if original has expired, and pages showing amendments such as name changes, corrections, etc.
-> Most recent F-1 entry visa page (if any).

