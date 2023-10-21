#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, S, D, K;

ll can_build(ll S, ll D) {
	ll buns = 2*(S + D);
	ll cheese = S + D*2;
	return min(buns-1ll, cheese);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	rep(t, 1, T+1) {
		printf("Case #%lld: ", t);
		cin >> S >> D >> K;
		printf(can_build(S, D) >= K ? "YES\n" : "NO\n");
	}
}
