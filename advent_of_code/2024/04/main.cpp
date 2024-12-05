#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

vector<string> A;

string make_string(char a, char b, char c, char d) {
    string res = "";
    res.push_back(a);
    res.push_back(b);
    res.push_back(c);
    res.push_back(d);
    return res;
}

vector<string> gen(ll i, ll j) {
    vector<string> res;
    if (i >= 3) res.push_back(make_string(A[i][j], A[i-1][j], A[i-2][j], A[i-3][j]));
    if (i <= sz(A) - 4) res.push_back(make_string(A[i][j], A[i+1][j], A[i+2][j], A[i+3][j]));
    if (j >= 3) res.push_back(make_string(A[i][j], A[i][j-1], A[i][j-2], A[i][j-3]));
    if (j <= sz(A[i]) - 4) res.push_back(make_string(A[i][j], A[i][j+1], A[i][j+2], A[i][j+3]));
    if (i >= 3 && j >= 3) res.push_back(make_string(A[i][j], A[i-1][j-1], A[i-2][j-2], A[i-3][j-3]));
    if (i <= sz(A) - 4 && j <= sz(A[i]) - 4) res.push_back(make_string(A[i][j], A[i+1][j+1], A[i+2][j+2], A[i+3][j+3]));
    if (i >= 3 && j <= sz(A[i]) - 4) res.push_back(make_string(A[i][j], A[i-1][j+1], A[i-2][j+2], A[i-3][j+3]));
    if (i <= sz(A) - 4 && j >= 3) res.push_back(make_string(A[i][j], A[i+1][j-1], A[i+2][j-2], A[i+3][j-3]));
    return res;
}

ll count(ll i, ll j) {
    if (A[i][j] != 'A') return 0;
    if (i == 0 || i == sz(A) - 1 || j == 0 || j == sz(A[i]) - 1) return 0;
    if (A[i-1][j-1] == 'M' && A[i+1][j+1] == 'S') {
        if (A[i-1][j+1] == 'M' && A[i+1][j-1] == 'S') return 1;
        if (A[i-1][j+1] == 'S' && A[i+1][j-1] == 'M') return 1;
    }
    if (A[i-1][j-1] == 'S' && A[i+1][j+1] == 'M') {
        if (A[i-1][j+1] == 'S' && A[i+1][j-1] == 'M') return 1;
        if (A[i-1][j+1] == 'M' && A[i+1][j-1] == 'S') return 1;
    }
    return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    string s;
    while (getline(cin, s) && s != "") {
        A.push_back(s);
    }
    ll res = 0;
    rep(i, 0, sz(A)) rep(j, 0, sz(A[i])) {
        res += count(i, j);
    }
    printf("%lld\n", res);
}
