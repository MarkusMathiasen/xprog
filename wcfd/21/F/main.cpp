#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n;
vi A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    cin >> n;
    A.resize(n);
    rep(i, 0, n) cin >> A[i];
    sort(all(A));
    ll res = 1e9;
    rep(cols, n/2+(n&1), n+1) {
        ll h = 0;
        rep(i, 0, n-cols) h = max(h, A[i]+A[2*(n-cols)-1-i]);
        rep(i, n-cols, n) h = max(h, A[i]);
        res = min(res, h*66*cols);
    }
    printf("%lld\n", res);
}

// doubles + singles = cols
// doubles*2 + singles = n
// doubles = n-cols