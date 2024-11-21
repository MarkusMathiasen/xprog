
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, q;
vi comp;
vector<vi> graph;
vector<pii> diag_points;
vi dists, diag = {0, 0, 0};

void read_graph() {
	graph.assign(n, vi());
	rep(i, 0, n-3) {
		int a, b; cin >> a >> b;
		a--, b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

void compute_comps() {
	comp.assign(n, -1);
	int comps = -1;
	rep(i, 0, n) {
		if (comp[i] != -1) continue;
		comp[i] = ++comps;
		queue<int> q;
		q.push(i);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : graph[u]) {
				if (comp[v] != -1) continue;
				comp[v] = comps;
				q.push(v);
			}
		}
	}
}

int compute_dist_from_node(int node, vi& dist) {
	queue<int> q;
	q.push(node);
	dist[node] = 1;
	int max_dist = 1;
	int max_dist_node = node;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : graph[u]) {
			if (dist[v] != -1) continue;
			dist[v] = dist[u] + 1;
			q.push(v);
			if (dist[v] > max_dist) {
				max_dist = dist[v];
				max_dist_node = v;
			}
		}
	}
	return max_dist_node;
}

void compute_diag_dists() {
	dists.assign(n, -1);
	vi computed(3, 0);
	rep(i, 0, n) {
		if (computed[comp[i]]) continue;
		computed[comp[i]] = 1;
		vi dist(n, -1);
		int node1 = compute_dist_from_node(i, dist);
		dist.assign(n, -1);
		int node2 = compute_dist_from_node(node1, dist);
		rep(i, 0, n) dists[i] = max(dists[i], dist[i]);
		dist.assign(n, -1);
		compute_dist_from_node(node2, dist);
		rep(i, 0, n) dists[i] = max(dists[i], dist[i]);
	}
	rep(i, 0, n) diag[comp[i]] = max(diag[comp[i]], dists[i]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n >> q;
	read_graph();
	compute_comps();
	compute_diag_dists();
	rep(i, 0, q) {
		int a, b; cin >> a >> b;
		a--, b--;
		assert(comp[a] != comp[b]);
		rep(c, 0, 3) {
			if (comp[a] != c && comp[b] != c) {
				printf("%d\n", diag[c] + dists[a] + dists[b]);
			}
		}
	}
}
