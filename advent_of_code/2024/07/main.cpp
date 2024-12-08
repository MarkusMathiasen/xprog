#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll my_pow(ll b, ll p) {
	if (p == 0) return 1;
	if (p == 1) return b;
	ll a = my_pow(b, p/2);
	ll res = a*a;
	if (p&1) res *= b;
	return res;
}

bool check(ll sum, vi& vals) {
	rep(i, 0, my_pow(3, sz(vals)-1)) {
		ll k = i;
		ll x = vals[0];
		rep(j, 0, sz(vals)-1) {
			if (k%3 == 2) x *= vals[j+1];
			else if (k%3 == 1) x += vals[j+1];
			else {
				ll d_count = sz(to_string(vals[j+1]));
				x = x*my_pow(10, d_count) + vals[j+1];
			}
			k /= 3;
		}
		if (x == sum) return true;
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	string line;
	ll res = 0;
	while (getline(cin, line) && line != "") {
		stringstream ss(line);
		ll sum; ss >> sum;
		char c; ss >> c;
		vi vals; ll x;
		while (ss >> x) vals.push_back(x);
		if (check(sum, vals)) res += sum;
	}
	printf("%lld\n", res);
}
