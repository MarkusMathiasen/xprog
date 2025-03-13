#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const int P = 10000;

ll n, p=0;
vi A, dp;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> n;
	A.resize(n);
	rep(i, 0, n) cin >> A[i];
	rep(i, 0, n) p += A[i];
	dp.assign(p+1, 0);
	dp[0] = 1;
	sort(A.rbegin(), A.rend());
	ll res = 0;
	rep(i, 0, n) for (ll j = p; j >= A[i]; j--) {
		if (j*2 <= p) dp[j] += dp[j-A[i]];
		if ((j-A[i])*2 <= p && j*2 > p) res += dp[j-A[i]];
	}
	printf("%lld\n", res);
}
