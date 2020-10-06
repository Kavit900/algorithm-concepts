### Problem Statement

There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that has been painted last summer should not be painted again.

A neighborhood is a maximal group of continuous houses that are painted with the same color. (For example: houses = `[1,2,2,3,3,2,1,1]`contains 5 neighborhoods  `[{1}, {2,2}, {3,3}, {2}, {1,1}])`.

Given an array houses, an `m * n` matrix `cost` and an integer `target` where:

`houses[i]`: is the color of the house `i`, `0` if the house is not painted yet.
`cost[i][j]`: is the cost of paint the house `i` with the color `j+1`.
Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods, if not possible return `-1`.

 

**Example 1:**

Input: houses = `[0,0,0,0,0]`, cost = `[[1,10],[10,1],[10,1],[1,10],[5,1]]`, `m = 5, n = 2, target = 3`
**Output:** `9`

Explanation: Paint houses of this way `[1,2,2,1,1]`
This array contains target = 3 neighborhoods, `[{1}, {2,2}, {1,1}]`.
Cost of paint all houses `(1 + 1 + 1 + 1 + 5) = 9`.

**Example 2:**

Input: houses = `[0,2,1,2,0]`, cost = `[[1,10],[10,1],[10,1],[1,10],[5,1]]`, `m = 5, n = 2, target = 3`
**Output:** `11`

Explanation: Some houses are already painted, Paint the houses of this way `[2,2,1,2,2]`
This array contains target = 3 neighborhoods, `[{2,2}, {1}, {2,2}]`. 
Cost of paint the first and last house `(10 + 1) = 11`.

**Example 3:**

Input: houses = `[0,0,0,0,0]`, cost = `[[1,10],[10,1],[1,10],[10,1],[1,10]]`, `m = 5, n = 2, target = 5`
**Output:** `5`

**Example 4:**

Input: houses = `[3,1,2,3]`, cost = `[[1,1,1],[1,1,1],[1,1,1],[1,1,1]]`, `m = 4, n = 3, target = 3`

**Output:** `-1`
Explanation: Houses are already painted with a total of 4 neighborhoods `[{3},{1},{2},{3}]` different of target = `3`.
 

Constraints:

```
m == houses.length == cost.length
n == cost[i].length
1 <= m <= 100
1 <= n <= 20
1 <= target <= m
0 <= houses[i] <= n
1 <= cost[i][j] <= 10^4
```

### Solution

1. Create a 3-D array to store minimum cost when `ith` house is colored with `jth` color and there are exactly `k` neighbourhoods till now.

2. So, the array `dp[i][j][k]` represents solution till `ith` house, when it's color is `jth` color and it has got exactly k neighbours at this point.

3. Initialize the first house, if it's already colored, `dp[1][house[0]][1] = 0`, so first house uses the past color and current neighbourhood count will be `1`, as it's the only house present at current time. If it's not already colored, then we loop through all the different colors and for `tagret = 1`, we assign the `cost[0][i-1]`.

4. Next, we will try to color each house from `i = 2 to m`, with each color `j = 1 to n` and maintain the solution for `k = 1 to target` neighbourhoods. 


5.  If `house[i]` is already colored, we cannot assign any other color to it. 
Now, if the `j` color is equal to `house[i]` color, then I just take the minimum cost from current `dp[i][j][k]` and `dp[i-1][j][k]`. 
If `j` is not equal to `house[i]` color, then we consider solutionsof k-1, as now our neighbourhood count will increase by 1 but there is no cost changes, so we take minimum of `dp[i][j][k]` and `dp[i-1][j][k-1`.

6. Now if `house[i]` is not colored, in this scenario we try to pull all `j = 1 to n` color to the house `i`. In the loop in the else part, we do the same. We consider all the solutions of coloring `i-1` house with each color `l = 1 to n`. I add `cost[i][j]` to the solution and take minimum of `dp[i — 1][l][k — 1]`. But we also check if `l == j`, if yes I have to consider the solution`dp[i — 1][l][k]` because in this case neighbourhood count wont increase.

### Java Code

```
import java.util.Arrays;

public class Solution {
    public int minCost(int[] houses, int[][] cost, int m, int n, int target) {
        int INF = (int)1e7 + 1;
        int dp[][][] = new int[m + 1][n + 1][target + 1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                Arrays.fill(dp[i][j], INF);
            }
        }
        if (houses[0] != 0) {
            dp[1][houses[0]][1] = 0;
        }
        else {
            for (int i = 1; i <= n; i++) {
                dp[1][i][1] = cost[0][i - 1];
            }
        }
        for (int i = 2; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= target; k++) {
                    if (houses[i - 1] != 0) {
                        if (j == houses[i - 1]) {
                            dp[i][houses[i - 1]][k] = Math.min(dp[i][j][k], dp[i - 1][j][k]);
                        }
                        else {
                            dp[i][houses[i - 1]][k] = Math.min(dp[i][houses[i - 1]][k], dp[i - 1][j][k - 1]);
                        }
                    }
                    else {
                        for (int l = 1; l <= n; l++) {
                            dp[i][j][k] = Math.min(dp[i][j][k], (((l == j) ? (dp[i - 1][j][k]) : (dp[i - 1][l][k - 1]))) + cost[i - 1][j - 1]);
                        }
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 1; i <= n; i++) {
            ans = Math.min(dp[m][i][target], ans);
        }
        if (ans == INF) ans = -1;
        return ans;
    }
}
```
