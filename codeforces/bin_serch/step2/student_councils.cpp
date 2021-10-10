#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll k, n;
vector<ll> A;

bool pos(ll guess) {
	ll sum = 0;
	for (ll x : A)
		sum += min(x, guess);
	return sum >= k*guess;
}

int main() {
	scanf("%lld%lld", &k, &n);
	A.assign(n, 0);
	for (ll i = 0; i < n; i++)
		scanf("%lld", &A[i]);
	ll low = 1;
	ll high = 1e12;
	while (low < high) {
		ll mid = (low + high) / 2;
		if (pos(mid))
			low = mid+1;
		else
			high = mid;
	}
	printf("%lld\n", low-1);
}
