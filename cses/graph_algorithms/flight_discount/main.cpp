#include <bits/stdc++.h>
using namespace std;
#define N 100000
typedef long long ll;
typedef pair<ll, ll> ii;

vector<vector<ii>> graph, graphT;
vector<ll> dist, distT;

void dijkstra(vector<vector<ii>>& graph, vector<ll>& dist, int start) {
	dist.assign(graph.size(), -1);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.emplace(0, start);
	while (!pq.empty()) {
		auto [d,v] = pq.top(); pq.pop();
		if (dist[v] != -1)
			continue;
		dist[v] = d;
		for (auto [u,c] : graph[v])
			pq.emplace(d+c, u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m; cin >> n >> m;
	graph.assign(n, vector<ii>());
	graphT.assign(n, vector<ii>());
	while (m--) {
		ll a, b, c; cin >> a >> b >> c; a--; b--;
		graph[a].push_back(ii(b, c));
		graphT[b].push_back(ii(a, c));
	}
	dijkstra(graph, dist, 0);
	dijkstra(graphT, distT, n-1);
	ll res = 1e18;
	for (ll i = 0; i < n; i++) {
		if (dist[i] == -1)
			continue;
		for (auto [j,c] : graph[i]) {
			if (distT[j] == -1)
				continue;
			res = min(res, dist[i] + c/2 + distT[j]);
		}
	}
	printf("%lld\n", res);
}
