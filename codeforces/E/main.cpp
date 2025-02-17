#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, MOD = 998244353;
vi p, c;
vector<pii> A;

struct UF {
    ll n;
    vi uf, l, r, s;
    UF(ll n) : n(n) {
        uf.resize(n);
        rep(i, 0, n) uf[i] = i;
        s.assign(n, 1);
        l.resize(n); r.resize(n);
        rep(i, 0, n) l[i] = i-1, r[i] = i == n ? -1 : i+1;
    }
    ll find(ll x) {
        return uf[x] == x ? x : uf[x] = find(uf[x]);
    }
    ll get_left(ll x) {
        return l[x] == -1 ? -1 : find(l[x]);
    }
    ll get_right(ll x) {
        return r[x] == n ? n : find(r[x]);
    }
    void dec(ll x) {
        s[x]--;
        if (s[x] == 0) {
            ll lx = get_left(x), rx = get_right(x);
            if (lx == -1 && rx == n) return;
            else if (lx == -1) l[rx] = -1;
            else if (rx == n) r[lx] = n;
            else {
                if (c[lx] == c[rx]) {
                    uf[lx] = rx;
                    s[rx] += s[lx];
                    l[rx] = get_left(lx);
                    l[lx] = r[lx] = s[lx] = -2; // for debug
                }
                else {
                    l[rx] = lx;
                    r[lx] = rx;
                }
            }
        }
    }
};

void solve() {
    cin >> n;
    p.resize(n);
    c.resize(n);
    rep(i, 0, n) cin >> p[i];
    rep(i, 0, n) cin >> c[i];
    rep(i, 0, n) --p[i], --c[i];
    UF uf(n);
    rep(i, 1, n) if (c[i] == c[i-1]) {
        uf.s[i] += uf.s[i-1];
        uf.uf[i-1] = i;
        uf.l[i] = uf.l[i-1];
        uf.r[i-1] = uf.l[i-1] = uf.s[i-1] = -2; // for debug
    }
    A.clear();
    rep(i, 0, n) A.emplace_back(p[i], i);
    sort(all(A));
    ll res = 1;
    for (auto [x, i] : A) {
        ll k = uf.find(i);
        res = (res*uf.s[k])%MOD;
        uf.dec(k);
    }
    printf("%lld\n", res);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll T; cin >> T;
    while (T--) {
        solve();
    }
}