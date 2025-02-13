#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	ll T; cin >> T;
	while (T--) {
		ll x, y; cin >> x >> y;
		if (y == x+1 || (y < x && (x-y+1)%9 == 0)) printf("YES\n");
		else printf("NO\n");
	}
}
