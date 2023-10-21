#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll LOG = 30;

ll T;
ll N, M, Q;
vector<vi> graph;
// find bridges
vi dfs_num, dfs_low;
set<pii> bridges;
ll cnt;
// find biconnected components
vi comp;
ll comps;
// Tree
vector<vi> tree_graph;
vector<vi> tree;
// neg_cycle
vi neg_cycle;
vi color;
// dist (to negative cycle)
vector<vi> dist;
// depth
vi depth;


void dfs(ll v, ll from) {
	if (dfs_num[v]) return;
	dfs_num[v] = dfs_low[v] = cnt++;
	for (ll u : graph[v]) {
		if (u == from) continue;
		dfs(u, v);
		if (dfs_low[u] > dfs_num[v]) {
			bridges.emplace(u, v);
			bridges.emplace(v, u);
		}
		dfs_low[v] = min(dfs_low[v], dfs_low[u]);
	}
}

void dfs2(ll v, ll c) {
	if (comp[v] != -1) return;
	comp[v] = c;
	for (ll u : graph[v]) {
		if (bridges.count({v, u})) continue;
		dfs2(u, c);
	}
}

ll lca(ll a, ll b) {
	ll res = 1e9;

	for (ll i = LOG-1; i >= 0; i--) {
		if (1ll<<i <= depth[a] - depth[b])
			res = min(res, dist[a][i]),
			a = tree[a][i];
		if (1ll<<i <= depth[b] - depth[a])
			res = min(res, dist[b][i]),
			b = tree[b][i];
	}
	for (ll i = LOG-1; i >= 0; i--) {
		if (tree[a][i] != tree[b][i])
			res = min(res, dist[a][i]),
			res = min(res, dist[b][i]),
			a = tree[a][i],
			b = tree[b][i];
	}
	res = min(res, dist[a][0]);
	res = min(res, dist[b][0]);
	if (a != b) res = min(res, dist[a][1]);
	assert(tree[a][0] == tree[b][0]);
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> T;
	rep(t, 1, T+1) {
		printf("Case #%lld: ", t);
		cin >> N >> M;
		graph.assign(N, {});
		rep(i, 0, M) {
			ll a, b; cin >> a >> b; a--; b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// Find bridges
		bridges.clear();
		dfs_num.assign(N, 0);
		dfs_low.assign(N, 0);
		cnt = 1;
		dfs(0, 0);
		
		// Calcualte bicomp
		comps = 0;
		comp.assign(N, -1);
		rep(i, 0, N) if (comp[i] == -1) dfs2(i, comps++);

		// Construct tree
		tree_graph.assign(comps, {});
		for (auto [a,b] : bridges) {
			tree_graph[comp[a]].push_back(comp[b]);
			tree_graph[comp[b]].push_back(comp[a]);
		}
		tree.assign(comps, vi(LOG, -1));
		tree[0][0] = 0;
		queue<ll> q;
		q.push(0);
		while (!q.empty()) {
			ll v = q.front(); q.pop();
			for (ll u : tree_graph[v])
				if (tree[u][0] == -1)
					tree[u][0] = v,
					q.push(u);
		}

		// has negative cycle
		neg_cycle.assign(comps, 0);
		color.assign(N, 0);
		rep(i, 0, N) {
			if (color[i]) continue;
			queue<pii> q;
			q.emplace(i, 1);
			while (!q.empty()) {
				auto [v,c] = q.front(); q.pop();
				if (color[v] != 0) {
					neg_cycle[comp[i]] |= color[v] != c;
					continue;
				}
				color[v] = c;
				for (ll u : graph[v]) {
					if (bridges.count({v, u})) continue;
					q.emplace(u, -c);
				}
			}
		}

		// compute dist to negative cycle
		dist.assign(comps, vi(LOG, -1));
		queue<pii> q2;
		rep(i, 0, comps) if (neg_cycle[i]) q2.emplace(i, 0);
		while (!q2.empty()) {
			auto [v,d] = q2.front(); q2.pop();
			if (dist[v][0] != -1) continue;
			dist[v][0] = d;
			for (ll u : tree_graph[v])
				q2.emplace(u, d+1);
		}

		// binary lift
		rep(i, 1, LOG) rep(v, 0, comps)
			tree[v][i] = tree[tree[v][i-1]][i-1],
			dist[v][i] = min(dist[v][i-1], dist[tree[v][i-1]][i-1]);

		// depth
		depth.assign(comps, -1);
		q2.emplace(0, 0);
		while (!q2.empty()) {
			auto [v,d] = q2.front(); q2.pop();
			if (depth[v] != -1) continue;
			depth[v] = d;
			for (ll u : tree_graph[v])
				q2.emplace(u, d+1);
		}

		// debug
		/*
		rep(i, 0, comps)
			printf("tree[%lld] = %lld\n", i, tree[i][0]);
		*/

		// Process queries
		cin >> Q;
		ll res = 0;
		while (Q--) {
			ll a, b; cin >> a >> b; a--; b--;
			if (dist[0][0] == -1) {
				res--;
				continue;
			}
			ll l = lca(comp[a], comp[b]);
			res += l;
		}
		printf("%lld\n", res);
	}
}
