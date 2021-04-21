/*
Problem is you are given n workers and n jobs, each worker can take only one job.

You are given a 2D matrix with (i,j) representing what is the minimum cost of performing all the n jobs.

Size of matrix is n x n and n is = 20.

n! solution won't work here, so we need to think of 2^n dp with bit mask solution
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

ll minCost(vector<vector<ll>> &cost) {
  int n = cost.size();
  vector<ll> dp(1<<n, INT_MAX);

  dp[0] = 0;

  for(int mask=0; mask<(1<<n); mask++) {
    int worker = count_set_bits(mask);
    for(int j=0; j<n; j++) {
      if(((mask>>j) & 1) == 1) {
        continue;
      } else {
        dp[mask | (1<<j)] = min(dp[mask | (1<<j)], dp[mask] + cost[worker][j]);
      }
    }
  }
  dp[(1<<n)-1];
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
