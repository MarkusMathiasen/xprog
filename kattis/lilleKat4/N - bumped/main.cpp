#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, ll>

int n, m, f, s, t;
vector<vector<ii>> graph;
vector<vector<ll>> flights;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> f >> s >> t;
	graph.assign(n, vector<ii>());
	for (int i = 0; i < m; i++) {
		ll a, b, c; cin >> a >> b >> c;
		graph[a].push_back(ii(b, c));
		graph[b].push_back(ii(a, c));
	}
	flights.assign(n, vector<ll>());
	for (int i = 0; i < f; i++) {
		ll a, b; cin >> a >> b;
		flights[a].push_back(b);
	}
	priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> Q;
	Q.push({0, s, 1});
	vector<vector<ll>> dist(n, vector<ll>(2, -1));
	while (!Q.empty()) {
		ll d = Q.top()[0];
		ll v = Q.top()[1];
		ll ticket = Q.top()[2];
		Q.pop();
		if (dist[v][ticket] != -1)
			continue;
		dist[v][ticket] = d;
		for (ii u : graph[v])
			Q.push({d + u.second, u.first, ticket});
		if (ticket) {
			for (ll u : flights[v])
				Q.push({d, u, 0});
		}
	}
	if (dist[t][0] == -1)
		cout << dist[t][1] << endl;
	else if (dist[t][1] == -1)
		cout << dist[t][0] << endl;
	else
		cout << min(dist[t][0], dist[t][1]) << endl;
}
