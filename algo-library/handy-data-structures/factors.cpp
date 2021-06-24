/*
Quick way to find factors
*/

int factor[10005];
void calc_factors(int n) {
  for (int i=1; i<=n; i++) {
      for (int j=i; j<=n; j+=i) {
          factor[j]+=1;
      }
  }
}
