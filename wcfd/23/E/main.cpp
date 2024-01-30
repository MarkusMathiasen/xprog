#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

template<class T> T edmondsKarp(vector<unordered_map<ll, T>>& graph, ll source, ll sink) {
	assert(source != sink);
	T flow = 0;
	vi par(sz(graph)), q = par;

	for (;;) {
		fill(all(par), -1);
		par[source] = 0;
		ll ptr = 1;
		q[0] = source;

		rep(i,0,ptr) {
			ll x = q[i];
			for (auto e : graph[x]) {
				if (par[e.first] == -1 && e.second > 0) {
					par[e.first] = x;
					q[ptr++] = e.first;
					if (e.first == sink) goto out;
				}
			}
		}
		return flow;
out:
		T inc = numeric_limits<T>::max();
		for (ll y = sink; y != source; y = par[y])
			inc = min(inc, graph[par[y]][y]);

		flow += inc;
		for (ll y = sink; y != source; y = par[y]) {
			ll p = par[y];
			if ((graph[p][y] -= inc) <= 0) graph[p].erase(y);
			graph[y][p] += inc;
		}
	}
}

ll K, N, M;

vector<unordered_map<ll, ll>> graph;

void print_graph(vector<unordered_map<ll, ll>>& g) {
	rep(i, 0, sz(g)) {
		printf("%lld: ", i);
		for (auto [w,c] : g[i]) printf("(%lld, %lld), ", w, c);
		printf("\n");
	}
}

bool compute(vector<unordered_map<ll, ll>> g, ll flow) {
	rep(v, 1, sz(g)-1) {
		for (auto& [w,c] : g[v]) if (w != sz(g)-1)
			c = c >= flow;
	}
	// printf("FLOW: %lld\n", flow);
	// print_graph(g);
	// printf("-----------------------------------------------------------------\n\n\n");
	return edmondsKarp(g, 0, sz(g)-1) == K;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> K >> N >> M;
	graph.assign(2+2*K + N, unordered_map<ll, ll>());
	rep(i, 0, M) {
		ll a, b, c; cin >> a >> b >> c;
		graph[a][b] = graph[b][a] = c;
	}
	rep(i, 0, K) graph[0][i+1] = graph[i+1][0] = graph[1+2*K + N][i+K+1] = graph[i+K+1][1+2*K + N] = 1;
	ll lower = 1, upper = 1e9+1;
	while (lower < upper) {
		ll mid = (lower + upper)/2;
		if (compute(graph, mid)) lower = mid+1;
		else upper = mid;
	}
	if (lower == 1) printf("Expand brewery\n");
	else printf("%lld\n", lower-1);
}
