#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

struct crane {
	ll x, y, h;
};

ll isqrt(ll x) {
	ll r = sqrt(x) + 1.;
	while (r*r > x) r--;
	return r;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	ll n; cin >> n;
	vector<crane> A(n);
	rep(i, 0, n) cin >> A[i].x >> A[i].y >> A[i].h;
	rep(i, 0, n) cin >> A[i].x >> A[i].y >> A[i].h;
	rep(i, 0, n) {
		ll res = A[i].h;
		rep(j, 0, n) if (A[j].h > A[i].h) {
			res = min(res, isqrt((A[j].x-A[i].x)*(A[j].x-A[i].x) + (A[j].y-A[i].y)*(A[j].y-A[i].y)));
		}
		printf("%lld\n", res);
	}
}
