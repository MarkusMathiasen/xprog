#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

struct TwoSat {
	ll N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(ll n = 0) : N(n), gr(2*n) {}

	void either(ll f, ll j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(ll x) { either(x, x); }

	vi val, comp, z; ll time = 0;
	ll dfs(ll i) {
		ll low = val[i] = ++time, x; z.push_back(i);
		for(ll e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};


const ll MAX_N = 1000;

bitset<MAX_N> mat[MAX_N];
bitset<MAX_N> b;
ll N, M;
ll ceo;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	rep(i, 0, MAX_N) mat[i].reset();
	vector<pii> friends;
	rep(i, 0, M) {
		ll a, b; cin >> a >> b; a--; b--;
		mat[a][b] = mat[b][a] = 1;
		friends.emplace_back(a, b);
	}
	// Find CEO
	rep(i, 0, N) {
		if (mat[i].count() <= 15) {
			b.reset();
			for (ll j = mat[i]._Find_first(); j < MAX_N; j = mat[i]._Find_next(j))
				b[j] = 1, b |= mat[j];
			if ((ll)b.count() == N) {
				ceo = i;
				break;
			}
		}
		assert(i != N-1);
	}
	ll hr = mat[ceo].count();
	vector<ll> hri;
	for (ll j = mat[ceo]._Find_first(); j < MAX_N; j = mat[ceo]._Find_next(j))
		hri.push_back(j);
	rep(perm, 0, 1<<hr) {
		vi options(N, 7);
		// assign ceo to hotel 0
		options[ceo] = 1;
		// assign hr to respective hotel
		rep(h, 0, hr) {
			if (perm & (1 << h)) options[hri[h]] = 4;
			else options[hri[h]] = 2;
		}
		// limit options for employees
		for (ll hi : hri)
			for (ll j = mat[hi]._Find_first(); j < MAX_N; j = mat[hi]._Find_next(j))
				options[j] &= ~(options[hi]);
		TwoSat sat(N);
		// if contradiction in hr arrangement, continue
		rep(i, 0, N) if (options[i] == 0) goto cont;
		rep(i, 0, N) {
			if (options[i] == 1) sat.setValue(i);
			else if (options[i] == 2 || options[i] == 4) sat.setValue(~i);
			else assert(options[i] == 3 || options[i] == 5);
		}
		for (auto [a,b] : friends) {
			//if (a == ceo || mat[ceo][a] || b == ceo || mat[ceo][b]) continue;
			sat.either(~a, ~b);
			if ((options[a]&4 && options[b]&4) || (options[a]&2 && options[b]&2))
				sat.either(a, b);
		}
		if (sat.solve()) {
			rep(i, 0, N) {
				if (sat.values[i]) printf("1 ");
				else if (options[i]&2) printf("2 ");
				else {
					printf("3 ");
					assert(options[i]&4);
				}
			}
			printf("\n");
			return 0;
		}
cont:;
	}
	printf("Impossible\n");
}
