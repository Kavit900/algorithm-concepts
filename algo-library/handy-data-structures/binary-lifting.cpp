/*
problem link - https://codeforces.com/contest/1516/problem/D
solution - use binary lifting technique to find the number having prime factors same as ith position
*/
#include <bits/stdc++.h>
using namespace std;
#define MX 100000
vector<int> p[100005];
int a[100005],nex[100005],dp[20][100005];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for (int i=2;i<=MX;i++)
    {
        if (p[i].empty())
        {
            nex[i]=n+1;
            for (int j=i;j<=MX;j+=i)
            p[j].push_back(i);
        }
    }
    dp[0][n+1]=n+1;
    for (int i=n;i>0;i--)
    {
        dp[0][i]=dp[0][i+1];
        for (int j:p[a[i]])
        {
            dp[0][i]=min(dp[0][i],nex[j]);
            nex[j]=i;
        }
    }
    for (int i=1;i<20;i++)
    {
        for (int j=1;j<=n+1;j++)
        dp[i][j]=dp[i-1][dp[i-1][j]];
    }
    while (q--)
    {
        int l,r,ans=0;
        scanf("%d%d",&l,&r);
        for (int i=19;i>=0;i--)
        {
            if (dp[i][l]<=r)
            {
                ans+=(1<<i);
                l=dp[i][l];
            }
        }
        printf("%d\n",ans+1);
    }
}
