#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n; scanf("%lld", &n);
	set<ll> divisors;
	for (ll i = 1; i <= sqrt(n)+1; i++)
		if (n%i == 0)
			divisors.insert(i-1), divisors.insert(n/i-1);
	for (ll x : divisors)
		printf("%lld ", x);
	printf("\n");
}
