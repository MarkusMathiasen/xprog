#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll N, M;
vector<pii> A;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> N >> M;
    A.resize(N);
    rep(i, 0, N) cin >> A[i].first >> A[i].second;
    ll res = 1e9;
	rep(i, 0, 1<<N) {
        ll nres = __builtin_popcountll(i);
        if (nres >= res) continue;
        ll seen = 0;
        rep(j, 0, N) {
            if (((1<<j)&i) == 0) continue;
            for (ll k = A[j].first; k != A[j].second; k=(k+1)%M)
                seen |= 1<<k;
        }
        if (__builtin_popcountll(seen) == M)
            res = nres;
    }
    if (res == 1e9) res = -1;
    printf("%lld\n", res);
}
