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
		ll n; cin >> n;
		vi A(n); rep(i, 0, n) cin >> A[i];
		vi B(n); rep(i, 0, n) B[A[i]-1]++;
		bool possible = true;
		rep(i, 0, n-1) {
			possible &= B[i] != 1;
			if (B[i] > 1) B[i+1] += B[i]-2;
		}
		possible &= B[n-1]%2 == 0;
		if (possible) printf("Yes\n");
		else printf("No\n");
	}
}
