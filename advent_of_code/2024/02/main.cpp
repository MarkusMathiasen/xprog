#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

bool is_safe(vi& A) {
    rep(i, 1, sz(A)) {
        if (A[i] == A[i-1]) return false;
        if ((A[i] > A[i-1]) != (A[1] > A[0])) return false;
        if (abs(A[i]-A[i-1]) > 3) return false;
    }
    return true;
}

bool real_is_safe(vi A) {
    if (is_safe(A)) return true;
    rep(i, 0, sz(A)) {
        vi B;
        rep(j, 0, sz(A)) {
            if (j != i) B.push_back(A[j]);
        }
        if (is_safe(B))
                return true;
    }
    return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);
    string s; ll res = 0;
    while (getline(cin, s) && s != "") {
        stringstream ss(s);
        vi A; ll x;
        while (ss >> x) {
            A.push_back(x);
        }
        res += real_is_safe(A);
    }
    printf("%lld\n", res);
}
