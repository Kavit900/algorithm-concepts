#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ss second
#define ff first
#define pb push_back
#define mp make_pair
ll n,m,p;
ll x[200100];
string s[200100];
ll ans,mx;
map<ll,bool> dp;

void go(ll cr,ll f,ll f2){
  //cout<<cr<<" "<<f<<" "<<f2<<endl;
    if(f>mx){
        mx=f;
        ans=cr;
    }
    if(dp[cr]==1)return;
    dp[cr]=1;
    int g[60]={};
    //for(int i=0;i<m;i++)g[i]=0;
    for(int i=0;i<n;i++){
      //cout<<"[AND] "<<cr<<" "<<x[i]<<" "<<(cr&x[i])<<endl;
        if((cr&x[i])!=cr)continue;
        for(int j=f2;j<m;j++){
            if(s[i][j]=='1')
                g[j]++;
        }
   }
   int y=0;
   for(int j=f2;j<m;j++){
        if(g[j]>=(n+1)/2){
           y++;
        }
   }
   //cout<<"[y] is:- "<<y<<endl;
   if(y+f<=mx)return;
   for(int j=f2;j<m;j++){
        if(g[j]>=(n+1)/2){
            go(cr+(1LL<<j),f+1,j+1);
        }
   }
}
int main(){
   //string s;
   cin>>n>>m>>p;
   for(int i=0;i<n;i++){
        cin>>s[i];
        ll o=1;
        for(int j=0;j<m;j++){
            if(s[i][j]=='1')x[i]+=o;
            o*=2;
        }
   }

   //cout<<"value of x[i] is:- "<<endl;
   for(int i=0; i<n; i++) {
     //cout<<x[i]<<endl;
   }
   go(0,0,0);
   ll o=1;
   //cout<<"[mx] is:- "<<mx<<endl;
   for(int i=0;i<m;i++){
        if((o&ans))cout<<1;
        else cout<<0;
        o*=2;
   }
   return 0;
}
