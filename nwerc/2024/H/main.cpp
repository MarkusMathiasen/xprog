#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll query(ll c, ll r) {
	if (c == 0) return r;
	printf("? %lld %lld\n", c, r);
	fflush(stdout);
	ll x; cin >> x;
	return x;
}

void answer(ll c, ll r) {
	printf("! %lld %lld\n", c, r);
	fflush(stdout);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	ll n; cin >> n;
	ll c = query(n, 1);
	ll r = query(n-c, 1);
	answer(c, r);
}
