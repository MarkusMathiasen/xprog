#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool is_prime(ll x) {
    if (x%2 == 0) return x == 2;
    for (ll i = 3; i*i <= x; i += 2)
        if (x%i == 0) return false;
    return true;
}

ll my_sqrt(ll x) {
    ll l = 0, r = 1e9;
    while (l < r) {
        ll m = (l+r+1)/2;
        if (m*m <= x) l = m;
        else r = m-1;
    }
    return l;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int T; cin >> T;
    rep(t, 1, T+1) {
        ll Z; cin >> Z;
        ll p1 = my_sqrt(Z)+1;
        while (!is_prime(p1)) p1++;
        ll p2 = p1-1;
        while (!is_prime(p2)) p2--;
        ll p3 = p2-1;
        while (!is_prime(p3)) p3--;
        printf("Case #%d: %lld\n", t, p1*p2 <= Z ? p1*p2 : p2*p3);
    }
}