#include <bits/stdc++.h>

using namespace std;

int sum(int k, int fenw[]) {
  int s = 0;
  while(k>=1) {
    s += fenw[k];
    k -= k&-k;
  }
  return s;
}

void update(int k, int x, int n, int fenw[]) {
  while(k <= n) {
    fenw[k] += x;
    k += k&-k;
  }
}

int main()
{
  int n,q;
  cin>>n>>q;

  int a[n+1];
  int fenw[n+1] = {};

  for(int i=1; i<=n; i++) {
    cin>>a[i];
    update(i, a[i], n, fenw);
  }

  for(int i=0; i<q; i++) {
    int index,t;
    cin>>index>>t;
    if(t==1) {
      update(index, t, n, fenw);
    } else {
      int l,r;
      cin>>l>>r;
      cout<<sum(r,fenw) - sum(l,fenw)<<endl;
    }
  }
}
