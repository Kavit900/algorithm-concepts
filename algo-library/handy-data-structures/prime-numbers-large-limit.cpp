#include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 5, MOD = 1e9 + 27;
bitset<MOD> comp;
vector<int> primes;
void solve () {
	long long z; scanf ("%lld",&z);
	long long ans = 0;
	for (int i = 0; i + 1 < (int)primes.size(); i++) {
		if ((long long)primes[i] * primes[i+1] <= z) {
			ans = (long long)primes[i] * primes[i+1];
		} else break;
	}
	printf ("%lld\n",ans);
}
int main() {
	for (int i = 2; i < MOD; i++) {
		if (!comp[i]) primes.push_back(i);
		for (int j = 0; j < (int)primes.size() && i * primes[j] < MOD; j++) {
			comp[i * primes[j]] = 1;
			if (i % primes[j] == 0) break;
		}
	}
	int t; scanf ("%d",&t);
	for (int test_case = 1; test_case <= t; test_case++) {
		printf ("Case #%d: ",test_case);
		solve();
	}
    return 0;
}
