#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

vi A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll T; cin >> T;
	while (T--) {
		ll n; cin >> n;
		A.resize(n);
		rep(i, 0, n) cin >> A[i];
		map<ll, ll> m;
		m[0] = 3;
		ll bits = 0;
	}
}
