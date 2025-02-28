#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, m, k;
vector<vector<pii>> graph;
vector<ll> from_start, from_end;
vector<pair<ll, double>> paths;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> n >> m >> k;
	graph.assign(n, {});
	rep(i, 0, m) {
		ll a, b, c; cin >> a >> b >> c; a--; b--;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	// Run Dijkstra twice
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	from_start.assign(n, -1);
	pq.push({0, 0});
	while (!pq.empty()) {
		pii p = pq.top(); pq.pop();
		auto [d,v] = p;
		if (from_start[v] != -1) continue;
		from_start[v] = d;
		for (auto [u, w] : graph[v]) {
			if (from_start[u] == -1) pq.push({d+w, u});
		}
	}
	from_end.assign(n, -1);
	pq.push({0, n-1});
	while (!pq.empty()) {
		pii p = pq.top(); pq.pop();
		auto [d,v] = p;
		if (from_end[v] != -1) continue;
		from_end[v] = d;
		for (auto [u, w] : graph[v]) {
			if (from_end[u] == -1) pq.push({d+w, u});
		}
	}
	// Calculate answer
	bool saw1 = false;
	while (k--) {
		ll v; double p; cin >> v >> p; v--;
		paths.push_back({from_start[v]+from_end[v], p});
		saw1 |= p == 1;
	}
	if (!saw1) {
		printf("impossible\n");
		return 0;
	}
	sort(all(paths));
	double ans = 0;
	double prev_prob = 1;
	for (auto [d, p] : paths) {
		ans += (double)d*p*prev_prob;
		prev_prob *= 1-p;
	}
	printf("%.8lf\n", ans);
}
