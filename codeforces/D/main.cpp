#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef int ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, q;
vi A, prex;
vector<vi> pre;

void solve() {
    cin >> n >> q;
    A.resize(n);
    rep(i, 0, n) cin >> A[i];
    prex.resize(n+1);
    prex[n] = 0;
    for (ll i = n-1; i >= 0; i--) prex[i] = prex[i+1] ^ A[i];
    pre.assign(30, vi(n, -1));
    rep(i, 0, 30) {
        ll last = -1;
        rep(j, 0, n) {
            if (A[j] >= 1<<i) last = j;
            pre[i][j] = last;
        }
    }
    while (q--) {
        ll p = n-1;
        ll x; cin >> x;
        while (p >= 0) {
            ll i = 31 - ((x^prex[p+1]) == 0 ? 31 : __builtin_clz(x^prex[p+1]));
            p = pre[i][p];
            if (p == -1 || A[p] > (x^prex[p+1])) break;
            p--;
        }
        printf("%d ", n-p-1);
    }
    printf("\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll T; cin >> T;
    while (T--) {
        solve();
    }
}