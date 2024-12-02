#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

vi A, B;
map<ll, ll> Bm;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);
    int x,y;
    while (cin >> x >> y) {
        A.push_back(x);
        B.push_back(y);
    }
    sort(all(A));
    sort(all(B));
    for (ll x : B) Bm[x]++;
    ll res = 0;
    rep(i, 0, sz(A)) {
        res += A[i]*Bm[A[i]];
    }
    printf("%lld\n", res);
}
