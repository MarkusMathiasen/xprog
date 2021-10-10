#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n; scanf("%lld", &n);
	ll res = 0;
	for (ll i = n-1; i >= 0; i--) {
		char c; scanf(" %c", &c);
		if (c == 'O')
			res |= (1l << i);
	}
	printf("%lld\n", res);
}
