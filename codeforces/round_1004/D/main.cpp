#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll ask(ll i, ll j) {
	printf("? %lld %lld\n", i+1, j+1);
	fflush(stdout);
	ll x; cin >> x;
	return x;
}

void answer(bool is_graph) {
	if (is_graph) printf("! A\n");
	else printf("! B\n");
	fflush(stdout);
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	ll T; cin >> T;
	while (T--) {
		ll n; cin >> n;
		vi A(n); rep(i, 0, n) cin >> A[i];
		rep(i, 0, n) A[i]--;
		set<ll> seen; for (ll x : A) seen.insert(x);
		if (sz(seen) < n) {
			rep(i, 0, n) if (!seen.count(i)) {
				bool is_graph = 0 == ask(i, (i+1)%n);
				answer(is_graph);
				break;
			}
		} else {
			ll small, big;
			rep(i, 0, n) if (A[i] == 0) small = i; else if (A[i] == n-1) big = i;
			ll a = ask(small, big);
			ll b = ask(big, small);
			if (a >= n-1 && a == b) answer(false);
			else answer(true);
		}
	}
}
