#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

vi A;
ll mod = 1e9+7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll T; cin >> T;
	while (T--) {
		ll n; cin >> n;
		A.resize(n);
		rep(i, 0, n) cin >> A[i];
		map<ll, ll> m;
		m[0] = 1;
		ll f = 0;
		rep(i, 0, n) m[f] = (3*m[f] + 2*m[A[i]^f]) % mod, f ^= A[i];
		ll res = 0;
		for (auto [k, v] : m) res = (res + v) % mod;
		printf("%lld\n", res);
	}
}
