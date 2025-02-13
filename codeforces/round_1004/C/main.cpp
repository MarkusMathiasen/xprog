#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

bool has7(ll x) {
	for (ll tp = 1; tp <= x; tp *= 10) {
		if ((x/tp)%10 == 7) return 1;
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	ll T; cin >> T;
	while (T--) {
		ll n; cin >> n;
		ll res = 10;
		for (ll tp = 10; tp <= (1ll<<32ll); tp *= 10) {
			ll cn = n, att = 0;
			while (!has7(cn)) {
				cn += tp-1;
				att++;
			}
			res = min(res, att);
		}
		printf("%lld\n", res);
	}
}
