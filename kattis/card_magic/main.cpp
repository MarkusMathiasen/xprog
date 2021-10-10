#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1000000009;

int main() {
	ll N, K, T; cin >> N >> K >> T;
	ll A[N+1][T+1];
	for (ll i = 0; i <= T; i++)
		A[0][i] = (i == 0);
	for (ll n = 1; n <= N; n++)
		for (ll t = 0; t <= T; t++) {
			A[n][t] = 0;
			for (ll i = 1; i <= min(K, t); i++)
				A[n][t] += A[n-1][t-i];
			A[n][t] %= mod;
		}
	printf("%lld\n", A[N][T]);
}
