## Problem Statement

Given a `m x n` grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.


Example 1:

```
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
```

Example 2:

```
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
```

Constraints:

```
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
```

## Algorithm

1. First thing to notice here is, we can only move either down or right, so we can create a matrix taking prefix sum from row and column and reach the bottom right cell with least amount of path.
2. This is a classic Dynamic Programming problem, we basically take prefix sum for first row and column.
3. Now, for each cell at `(i,j)`, I have two choices, either go down or go right. So while standing at `(i,j)`, I can come either from top of left.
4. So our equation would look something like this `dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]`.
5. In the last step return `dp[row-1][col-1]` cell value, where row is number of rows in the matrix and column is number of columns in the matrix.

## Code 

```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m,0));
        
        dp[0][0] = grid[0][0];
        
        // fill up the first column
        for(int i=1; i<m; i++) {
            dp[0][i] += dp[0][i-1] + grid[0][i];
        }
        
        // fill up the first row
        for(int i=1; i<n; i++) {
            dp[i][0] += dp[i-1][0] + grid[i][0];
        }
        
        // now we can start our dp process from top to bottom
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[n-1][m-1];
    }
};
```