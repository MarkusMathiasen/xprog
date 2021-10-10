#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll n, c; scanf("%lld%lld", &n, &c);
	vector<ll> A(n, 0);
	for (ll i = 0; i < n; i++)
		scanf("%lld", &A[i]);
	ll low = 0, high = 0;
	for (ll i = 0; i < n; i++) {
		ll res = max(abs(A[i]-A[low])-c*(i-low), abs(A[high]-A[i])-c*(i-high));
		printf("%lld ", max(res, (ll)0));
		if (A[low] + c*(i-low) > A[i])
			low = i;
		if (A[high] - c*(i-high) < A[i])
			high = i;
	}
	printf("\n");
}
