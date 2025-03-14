#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

vi B;
ll n, m;
vector<vi> graph, dp;

ll calc(ll v, ll prev) {
	if (dp[v][prev] == -1) {
		return 1e9;
	} if (dp[v][prev] != 0) return dp[v][prev];
	dp[v][prev] = -1;
	ll res = 1, nxt = 1 - prev;
	for (ll u : graph[v]) {
		if (B[u] == nxt)
			res = max(res, 1 + calc(u, B[v]));
	}
	return dp[v][prev] = res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> n >> m;
	B.resize(n);
	rep(i, 0, n) cin >> B[i];
	graph.assign(n, vi());
	while (m--) {
		ll a, b; cin >> a >> b; a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dp.assign(n, vi(2, 0));
	ll res00 = 0, res01 = 0, res10 = 0, res11 = 0;
	rep(i, 0, n) {
		if (B[i]) {
			res01 = max(res01, calc(i, 0));
			res11 = max(res11, calc(i, 1));
		} else {
			res00 = max(res00, calc(i, 0));
			res10 = max(res10, calc(i, 1));
		}
	}
	ll res = min(min(res00, res01), min(res10, res11));
	if (res >= (ll)1e9) printf("infinity\n");
	else printf("%lld\n", res+1);
}
