#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

int n;
vi A;
vector<vi> dp;

void solve() {
    cin >> n;
    A.resize(n);
    rep(i, 0, n) cin >> A[i];
    dp.assign(n, vi(n, -1));
    for (ll i = n-1; i >= 0; i--) rep(j, 0, n) {
        if (j <= i+1) dp[i][j] = 0;
        else {
            rep(k, i+1, j)
                dp[i][j] = max(dp[i][j], dp[i+1][k-1] + dp[k+1][j-1] + A[i]*A[j]*A[k]);
            rep(k, i, j)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j]);
        }
    }
    printf("%d\n", dp[0][n-1]);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	ll T; cin >> T;
	while (T--) {
        solve();
	}
}
