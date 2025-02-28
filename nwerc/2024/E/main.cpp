#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll pow(ll a, ll b, ll m) {
	if (b == 0) return 1;
	ll r = pow(a, b/2, m);
	return (r*r*(b&1?a:1))%m;
}

ll n, k;
string s;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> n >> k >> s;
	string res = "";
	ll step = pow(2, k, n);
	ll p = 0;
	rep(i, 0, n) {
		res.push_back(s[p]);
		p = (p+step)%n;
	}
	printf("%s\n", res.c_str());
}
