# Palindrome Concepts

### Finding Longest Palindromic substring in a string

Let our string be 's' and we store length of the string `s` in variable `m` . 

The 2-D array palinb stores the value as 1 if the substring from index i to j is palindrome else 0.

The mxb array stores the maximum length of the palindrome till index j. 

```
    for(int len = 1; len <= m; len++) {
        for(int i = 0; i <= m-len; i++) {
            int j = i + len - 1;
            if(len == 1) palinb[i][j] = 1;
            else if(len == 2) palinb[i][j] = s[i] == s[j];
            else palinb[i][j] = palinb[i+1][j-1] && s[i] == s[j];
            if(palinb[i][j]) mxb[j] = max(mxb[j], len);
            ans = max(ans, mxb[j]);
        }
    }
```

