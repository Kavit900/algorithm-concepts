/*
https://codeforces.com/contest/165/problem/E
*/

#include<bits/stdc++.h>

using namespace std;

int n,d[1000005],f[5000005];

int main(){

for(int i=0;i<(1<<2);i++){
    f[i]=-1;
}

cin>>n;

// Set valie of f[x] = x;
for(int i=0;i<n;i++) {
    cin>>d[i];
    f[d[i]]=d[i];
}

// using bit masking, find the maximum value possible for f[x] greater than x or -1, if possible at all.
for(int i=0;i<2;i++){
    for(int j=0;j<(1<<2);j++){
        if(j&(1<<i))
         {
           f[j]=max(f[j],f[j^(1<<i)]);
         }
    }
}

// Just take the xor of all bits being 1 and value of the array element
for(int i=0;i<n;i++){
    cout<<f[d[i]^((1<<2)-1)]<<" ";
}
return 0;
}
