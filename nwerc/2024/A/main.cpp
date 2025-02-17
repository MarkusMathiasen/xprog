#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	ll n; cin >> n;
	string s; getline(cin, s);
	vector<string> A(n);
	rep(i, 0, n) getline(cin, A[i]);
	sort(all(A), [](string& a, string& b) {
		ll ia, ib;
		for (ll i = sz(a)-1; i >= 0; i--) if ('A' <= a[i] && a[i] <= 'Z') ia = i;
		for (ll i = sz(b)-1; i >= 0; i--) if ('A' <= b[i] && b[i] <= 'Z') ib = i;
		return a.substr(ia, sz(a)-ia) < b.substr(ib, sz(b)-ib);
	});
	for (string& a : A) printf("%s\n", a.c_str());
}
