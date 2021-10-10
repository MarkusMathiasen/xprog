#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n;
vector<vector<ll>> graph;
vector<ll> K;
vector<ll> siz;
vector<ll> tim;
vector<ll> sum;

ll calc(ll v) {
	for (ll u : graph[v])
		calc(u);
	sort(graph[v].begin(), graph[v].end(), [](ll a, ll b) {
		return tim[a] + sum[a]*siz[b] + tim[b] <
			tim[b] + sum[b]*siz[a] + tim[a];
	});
	ll res = 0;
	ll t = 1;
	for (ll u : graph[v]) {
		res += t*siz[u] + tim[u];
		t += sum[u];
	}
	res += t+K[v];
	return tim[v] = res;
}
ll getSize(ll v) {
	ll res = 1;
	for (ll kid : graph[v])
		res += getSize(kid);
	return siz[v] = res;
}
ll getSum(ll v) {
	ll res = K[v]+1;
	for (ll u : graph[v])
		res += getSum(u);
	return sum[v] = res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	graph.assign(n, vector<ll>(0, 0));
	K.assign(n, 0);
	for (ll i = 0; i < n; i++) {
		ll f; cin >> K[i] >> f;
		while (f--) {
			ll a; cin >> a; a--;
			graph[i].push_back(a);
		}
	}
	siz.assign(n, 0);
	getSize(0);
	sum.assign(n, 0);
	getSum(0);
	tim.assign(n, 0);
	ll res = calc(0);
	cout << res << endl;
}
