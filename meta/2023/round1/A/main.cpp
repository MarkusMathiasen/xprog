#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> T;
	rep(t, 1, T+1) {
		printf("Case #%lld: ", t);
		ll N; cin >> N;
		vi v(N, 0);
		rep(i, 0, N) cin >> v[i];
		sort(all(v));
		if (N == 5) {
			long double x1 = (v[2]+v[0])/2.0L;
			long double y1 = (v[sz(v)-1]+v[sz(v)-2])/2.0L;
			long double x2 = (v[1]+v[0])/2.0L;
			long double y2 = (v[sz(v)-1] + v[sz(v)-3])/2.0L;
			printf("%Lf\n", max(y1-x1, y2-x2));
		}
		else {
			long double x = (v[1]+v[0])/2.0L;
			long double y = (v[sz(v)-1]+v[sz(v)-2])/2.0L;
			printf("%Lf\n", y-x);
		}
	}
}
