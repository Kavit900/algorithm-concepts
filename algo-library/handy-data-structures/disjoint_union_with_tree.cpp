/*
https://codeforces.com/problemset/problem/915/F
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
struct node{int u,v,w;}e[N];
int a[N],f[N],sz[N],n;
ll ans;
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
bool operator < (const node &A,const node &B) {return A.w<B.w;}
// The main idea here is to connect edges using disjoint union set and then calculate the value of each tree
void solve()
{
  for (int i=1;i<=n;i++) f[i]=i,sz[i]=1;
  for (int i=1;i<n;i++) e[i].w=max(a[e[i].u],a[e[i].v]);
  sort(e+1,e+n);
  for (int i=1;i<n;i++)
  {
    int x=find(e[i].u),y=find(e[i].v);
    if (x==y) continue;
    ans+=(ll)e[i].w*sz[x]*sz[y];
    f[x]=y;sz[y]+=sz[x];
  }
}

int main()
{
   scanf("%d",&n);
   for (int i=1;i<=n;i++) scanf("%d",&a[i]);
   for (int i=1;i<n;i++) scanf("%d%d",&e[i].u,&e[i].v);
   solve();
   for (int i=1;i<=n;i++) a[i]=-a[i];
   solve();
   printf("%lld\n",ans);
   return 0;
}
