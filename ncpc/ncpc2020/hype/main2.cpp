#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll a, b, c;
ll MOD = (ll)1e9+7;

int main() {
	a = b = c = 0;
	ll n; cin >> n;
	vector<ll> input(n, 0);
	for (ll i = 0; i < n; i++) {
		scanf("%lld", &input[i]);
		if (input[i] == 2)
			b++;
	}
	ll bCount = 0;
	vector<ll> left(b, 0);
	for (ll i = 0; i < n; i++) {
		if (input[i] == 1)
			a++;
		else if (input[i] == 2) {
			left[bCount] = a;
			bCount++;
		}
	}
	bCount--;
	vector<ll> right(b, 0);
	for (ll i = n-1; i >= 0; i--) {
		if (input[i] == 3)
			c++;
		else if (input[i] == 2) {
			right[bCount] = c;
			bCount--;
		}
	}
	if (n < 3 || !a || !b || !c) {
		cout << 0 << endl;
		return 0;
	}
	vector<ll> dp(b, 0);
	dp[b-1] = right[b-1];
	for (ll i = b-2; i >= 0; i--) {
		dp[i] = right[i] + dp[i+1] + (dp[i+1] - right[i+1]);
		dp[i] %= MOD;
	}
	ll res = 0;
	for (ll i = 0; i < b; i++) {
		res += dp[i] * left[i];
		res %= MOD;
	}
	cout << res << endl;
}
