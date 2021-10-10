#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, M, K, sa, sb;
vector<vector<ll>> dag;
vector<ll> nodeGain;
vector<ll> dp;
ll u = (ll) 1e15;

ll cost(ll n) {
	if (dp[n] != u)
		return dp[n];
	if (dag[n].size() == 0)
		return dp[n] = nodeGain[n];
	ll res = -u;
	for (ll v : dag[n])
		res = max(res, cost(v));
	return dp[n] = res+nodeGain[n];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> K >> sa >> sb; sa--; sb--;
	dag.assign(N, {});
	while (M--) {
		ll a, b; cin >> a >> b; a--; b--;
		dag[a].push_back(b);
	}
	nodeGain.assign(N, 0);
	for (ll i = 0; i < N; i++) {
		string t; cin >> t;
		if (t == "PROPERTY")
			cin >> K >> K;
		else if (t == "SALARY")
			cin >> nodeGain[i];
		else {
			cin >> nodeGain[i];
			nodeGain[i] = -nodeGain[i];
		}
	}
	dp.assign(N, u);
	ll p1 = cost(sa) - nodeGain[sa];
	ll p2 = cost(sb) - nodeGain[sb];
	printf("%lld %lld\n", p1, p2);
}
