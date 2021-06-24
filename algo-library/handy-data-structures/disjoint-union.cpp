#include <bits/stdc++.h>

using namespace std;

vector<int> par, sz;

int find_root(int x) {
  if(par[x] == x) {
    return x;
  }

  // path compression while going up
  return par[x] = find_root(par[x]);
}

void merge(int x, int y) {
  x = find_root(x);
  y = find_root(y);

  it(x == y) {
    return;
  }

  if(sz[x] > sz[y]) {
    swap(x,y);
  }

  // sz[x] <= sz[y]
  par[x] = y;
  sz[y] += sz[x];
}

int main() {

  int n,q;
  cin>>n>>q;

  par.resize(n);
  sz.resize(n,1);

  for(int i=0; i<n; i++) {
    par[i] = i;
  }

  while(q--) {
    int t,x,y;
    cin>>t>>x>>y;
    if(t) {
      if(find_root(x) == find_root(y)) {
        cout<<"YES"<<endl;
      } else {
        cout<<"NO"<<endl;
      }
    } else {
      merge(x,y);
    }
  }
  return 0;
}
