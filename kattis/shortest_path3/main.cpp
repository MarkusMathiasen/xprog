#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll, ll>
const ll high = 1e12;

int main() {
	ll n, m, q, s;
	while (scanf("%lld%lld%lld%lld", &n, &m, &q, &s), n) {
		vector<vector<ii>> graph(n, vector<ii>());
		for (ll i = 0; i < m; i++) {
			ll u, v, w; scanf("%lld%lld%lld", &u, &v, &w);
			graph[u].push_back(ii(v, w));
		}
		vector<bool> reachable(n, 0);
		queue<ll> Q; Q.push(s);
		while (!Q.empty()) {
			ll x = Q.front(); Q.pop();
			if (reachable[x])
				continue;
			reachable[x] = true;
			for (auto [v, w] : graph[x])
				Q.push(v);
		}
		vector<ll> dist(n, high);
		dist[s] = 0;
		for (ll i = 0; i < n-1; i++)
			for (ll j = 0; j < n; j++)
				if (reachable[j])
					for (auto [v, w] : graph[j]) {
						assert(-2000 <= w && w <= 2000);
						dist[v] = min(dist[v], dist[j]+w);
					}
		vector<ll> dist2(dist);
		for (ll i = 0; i < 10*n; i++)
			for (ll j = 0; j < n; j++)
				if (reachable[j])
					for (auto [v, w] : graph[j]) {
						assert(-2000 <= w && w <= 2000);
						dist2[v] = min(dist2[v], dist2[j]+w);
					}
		while (q--) {
			ll x; scanf("%lld", &x);
			if (!reachable[x]) {
				printf("Impossible\n");
				continue;
			}
			assert(dist2[x] <= dist[x]);
			if (dist2[x] < dist[x])
				printf("-Infinity\n");
			else
				printf("%lld\n", dist[x]);
		}
		printf("\n");
	}
}
