#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll con = 1152921504606846976;
ll mod2 = 1152921497;
ll mod = 1e9+7;

int main() {
	int n; scanf("%d", &n);
	ll x = 1;
	bool possible = true;
	for (int i = 0; i < n; i++) {
		x *= 2;
		ll b; scanf("%lld", &b);
		x -= b;
		possible &= x >= 0;
		x %= mod2*mod;
	}
	if (!possible)
		printf("error\n");
	else
		printf("%lld\n", x%mod);
	printf("%lld\n", mod2*mod);
}
