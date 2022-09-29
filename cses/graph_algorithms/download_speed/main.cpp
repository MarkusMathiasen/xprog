#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<vector<ll>> graph, mat;
vector<bool> vis;

long long dfs(ll v, ll thres, ll flow) {
	if (v == n-1)
		return flow;
	if (vis[v])
		return 0;
	vis[v] = true;
	for (ll u : graph[v]) {
		if (mat[v][u] < thres)
			continue;
		ll x = dfs(u, thres, min(flow, mat[v][u]));
		if (x) {
			mat[v][u] -= x;
			mat[u][v] += x;
			return x;
		}
	}
	return 0;
}

int main() {
	scanf("%d%d", &n, &m);
	graph.assign(n, vector<ll>());
	mat.assign(n, vector<ll>(n, 0));
	while (m--) {
		ll a, b, c; scanf("%lld%lld%lld", &a, &b, &c); a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
		mat[a][b] += c;
	}
	ll res = 0;
	ll thres = 1e9;
	while (thres) {
		vis.assign(n, false);
		ll x = dfs(0, thres, 1e18);
		res += x;
		if (!x)
			thres /= 2;
	}
	printf("%lld\n", res);
}
