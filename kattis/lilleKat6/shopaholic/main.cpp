#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n; scanf("%d", &n);
	vector<ll> A(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%lld", &A[i]);
	sort(A.rbegin(), A.rend());
	ll res = 0;
	for (int i = 2; i < n; i += 3)
		res += A[i];
	printf("%lld\n", res);
}
