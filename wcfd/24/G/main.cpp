#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	ll n;
	cin >> n;
	vector<set<string>> v(n);
	vi gins(n);
	vi tonics(n);
	Dinic d(2202);
	rep(i, 0, n) {
		d.addEdge(i, 1000 + i, 1);
		string s;
		ll m;
		cin >> s >> m;
		rep(j, 0, m) {
			cin >> s;
			v[i].insert(s);
		}
	}
	ll g;
	cin >> g;
	rep(i, 0, g) {
		string s;
		ll m, u;
		cin >> s >> u >> m;
		vector<string> ing(m);
		rep(j, 0, m) cin >> ing[j];
		rep(k, 0, n) {
			bool all = true;
			rep(j, 0, m) if (v[k].count(ing[j])) all = false;
			if (all) d.addEdge(2000 + i, k, 1);
		}
		d.addEdge(2200, 2000 + i, u);
	}
	ll t;
	cin >> t;
	rep(i, 0, t) {
		string s;
		ll m, u;
		cin >> s >> u >> m;
		vector<string> ing(m);
		rep(j, 0, m) cin >> ing[j];
		rep(k, 0, n) {
			bool all = true;
			rep(j, 0, m) if (v[k].count(ing[j])) all = false;
			if (all) d.addEdge(1000 + k, 2100 + i, 1);
		}
		d.addEdge(2100 + i, 2201, u);
	}
	printf("%lld\n", d.calc(2200, 2201));
}
