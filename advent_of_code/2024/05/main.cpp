#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

set<pii> rules;

bool is_valid(vi& A) {
	rep(i, 0, sz(A)) rep(j, i+1, sz(A))
		if (rules.count({A[j], A[i]}))
			return false;
	return true;
}

void fix(vi& row) {
    rep(i, 0, sz(row)) {
        rep(j, i+1, sz(row)) {
            if (rules.count({row[j], row[i]})) {
                swap(row[i], row[j]);
                i--;
                break;
            }
        }
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	string s;
	while (getline(cin, s) && s != "") {
		istringstream ss(s);
		ll a, b; char mid;
		ss >> a >> mid >> b;
		rules.insert({a,b});
	}
	ll res = 0;
	while (getline(cin, s) && s != "") {
		istringstream ss(s);
		vi row;
		while (getline(ss, s, ',')) {
			row.push_back(stoll(s));
		}
		if (!is_valid(row)) {
			fix(row);
            res += row[sz(row)/2];
		}
	}
	printf("%lld\n", res);
}
