/*
Problem link:- https://leetcode.com/problems/stone-game-viii/
*/

class Solution {
public:
    int dp[2][100005];
    int dfs(vector<int>& stones, int idx, int t, int sum) {
        if(dp[t][idx] > -1e9) return dp[t][idx];
        int ans = -200000000;
        if(idx == 0) {
            sum += stones[idx];
            ++idx;
        }
        if(idx + 1 == stones.size()) {
            return stones[idx] + sum;
        }
        sum += stones[idx];
        int res = sum - dfs(stones, idx + 1, t ^ 1, sum);
        return dp[t][idx] = max(res, dfs(stones, idx + 1, t, sum));
    }
    int stoneGameVIII(vector<int>& stones) {
        for(int i = 0; i < stones.size(); i++) {
            dp[0][i] = -2e9;
            dp[1][i] = -2e9;
        }
        return dfs(stones, 0, 0, 0);
    }
};
