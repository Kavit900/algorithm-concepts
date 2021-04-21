/*
Top Down approach

Given n number of kids and n number of chocolates and provided n x n matrix which tells whether ith kid likes jth chocolate or not
Find number of ways we can distribute chocolates between n kids

We can start from 111 where 111 represents we have distributed all chocolates among all the n kids and from there we calculate for 000
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int count_set_bits(int n) {
  int count = 0;
  while(n>0) {
    n = n&(n-1);
    count++;
  }
  return count;
}

ll countWays(vector<vector<ll>> like) {
  int n = like.size();

  vector<ll> dp(1<<n, 0);

  dp[1<<n-1] = 1;

  for(int mask=(1<<n) - 2; mask>=0; mask--) {
    int k = count_set_bits(mask);
    for(int i=0; i<n; i++) {
      if(like[k][i] && ((mask>>i) & 1) == 0) {
        dp[mask] += dp[mask | (1<<i)];
      }
    }
  }
  return dp[0];
}

int main()
{
  int n;
  cin>>n;
  vector<vector<int> > arr(n, vector<int> (n,0));
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin>>arr[i][j];
    }
  }
  cout<<minCost(arr)<<endl;
  return 0;
}
