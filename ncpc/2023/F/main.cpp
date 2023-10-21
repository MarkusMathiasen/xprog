#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll MAX_PR = 5'000'000;
bitset<MAX_PR> isprime;
vi eratosthenesSieve(ll lim) {
	isprime.set(); isprime[0] = isprime[1] = 0;
	for (ll i = 4; i < lim; i += 2) isprime[i] = 0;
	for (ll i = 3; i*i < lim; i += 2) if (isprime[i])
		for (ll j = i*i; j < lim; j += i*2) isprime[j] = 0;
	vi pr;
	rep(i,2,lim) if (isprime[i]) pr.push_back(i);
	return pr;
}

ll n;

vector<vi> tree_graph;
vi tree, depth, val;

void calc(ll v, ll p) {
	if (val[v] != -1) return;
	calc(tree[v], p);
	val[v] = val[tree[v]]*p;
}

ll calc_k(ll v, ll p) {
	if (val[v] != -1) return val[v];
	return calc_k(tree[v], p)*p;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	vi primes = eratosthenesSieve(1000);
	cin >> n;
	tree_graph.assign(n, vi());
	rep(i, 0, n-1) {
		ll a, b; cin >> a >> b; a--; b--;
		tree_graph[a].push_back(b);
		tree_graph[b].push_back(a);
	}
	// Make tree
	tree.assign(n, -1);
	depth.assign(n, -1);
	tree[0] = depth[0] = 0;
	queue<ll> q;
	q.push(0);
	while (!q.empty()) {
		ll v = q.front(); q.pop();
		for (ll u : tree_graph[v]) {
			if (u == tree[v]) continue;
			tree[u] = v;
			depth[u] = depth[v]+1;
			q.push(u);
		}
	}
	val.assign(n, -1);
	val[0] = 1;
	ll pi = 0;
	while (true) {
		ll v = -1, k = 0;
		rep(i, 0, n) {
			if (val[i] != -1) continue;
			ll k2 = calc_k(i, primes[pi]);
			if (k2 > k) {
				k = k2;
				v = i;
			}
		}
		if (v == -1) break;
		calc(v, primes[pi++]);
	}
	rep(i, 0, n) printf("%lld ", val[i]);
	printf("\n");
}
