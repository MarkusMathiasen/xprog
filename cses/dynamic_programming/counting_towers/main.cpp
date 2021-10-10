#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ii pair<ll, ll>

int t, n;
vector<ii> dp;
int mod = (int)1e9+7;

int main() {
	cin >> t;
	dp.assign(1000001, ii(1, 1));
	for (int i = 2; i < 1000001; i++) {
		dp[i].first = (dp[i-1].first*4 + dp[i-1].second)%mod;
		dp[i].second = (dp[i-1].first + dp[i-1].second*2)%mod;
	}
	while (t--) {
		cin >> n;
		cout << (dp[n].first + dp[n].second)%mod << endl;
	}
}
