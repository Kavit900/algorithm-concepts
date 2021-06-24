/*
https://www.hackerearth.com/problem/algorithm/xor-tree-3-90109ceb/
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
int bit[200001][30];
int ans;
int pws[30];
void dfs(vector<int> tree[], int v, int p, int dp[], int wt[], int sz[])
{
    dp[v] = dp[p]^wt[v];
    for(int i = 0; i < 30; i++)
    {
        bit[v][i] = 0;
        if((dp[v] >> i)&1)
            bit[v][i]++;
    }
    sz[v] = 1;
    for(auto j : tree[v])
        if(j != p)
        {
            dfs(tree, j, v, dp, wt, sz);
            sz[v]+=sz[j];
            for(int i = 0; i < 30; i++)
                bit[v][i]+=bit[j][i];
        }

    for(int i = 0; i < 30; i++)
    {
        int lin_zero = 0, lin_one = 0, sqr_zero = 0, sqr_one = 0, zo = 0;
        for(auto j : tree[v])
            if(j != p)
            {
                lin_zero+=(sz[j] - bit[j][i]), lin_one+=bit[j][i];
                sqr_zero+=((sz[j] - bit[j][i])*(sz[j] - bit[j][i]));
                sqr_one+=(bit[j][i]*bit[j][i]);
                zo+=(bit[j][i]*(sz[j] - bit[j][i]));
            }
        //cout << v << " " << i << " " << lin_zero << " " << lin_one << " " << sqr_zero << " " << sqr_one << " " << zo << '\n';
        if((wt[v] >> i)&1)
            ans+=(((lin_zero*lin_zero + lin_one*lin_one - sqr_zero - sqr_one)/2)*pws[i]);
        else
            ans+=((lin_zero*lin_one - zo)*pws[i]);
        int val = dp[v]^wt[v];
        if((val >> i)&1)
            ans+=(lin_zero*pws[i]);
        else
            ans+=(lin_one*pws[i]);
        //cout << v << " " << ans << '\n';
    }
}
// sum {dp[u]^dp[v]^wt[lca]}
// assume v == lca, sum{dp[u]^dp[lca]^wt[lca]}
// assume v != lca, then 'u' and 'v' are in different subtree children of lca
signed main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	assert(1 <= t && t <= 1000);
	for(int i = 0; i < 30; i++)
	    pws[i] = (1 << i);
	while(t--)
	{
	    int n;
	    cin >> n;
	    assert(1 <= n && n <= 2e5);
	    vector<int> tree[n+1];
	    int dp[n+1] = {0};
	    int wt[n+1] = {0};
	    int sz[n+1] = {0};
	    for(int i=1;i<=n;i++)
	        cin >> wt[i];
	    int i;
	    for(i=1;i<n;i++)
	    {
	        int x, y, w;
	        cin >> x >> y;
	        tree[x].push_back(y);
	        tree[y].push_back(x);
	    }
	    ans = 0;
	    dfs(tree, 1, 0, dp, wt, sz);
	    cout << ans << '\n';
	}
}
