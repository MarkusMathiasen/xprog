#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

bitset<250000> b;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s; cin >> s;
	bool res = true;
	rep(i, 1, sz(s)) {
		if (sz(s)%i != 0) continue;
		bool diff = false;
		string sub = s.substr(0, i);
		for (ll j = i; j < sz(s); j += i)
			diff |= s.substr(j, i) != sub;
		res &= diff;
	}
	b.reset();
	rep(i, 0, sz(s))
		b[(i+(s[i]-'0'))%sz(s)] = 1;
	res &= (ll)b.count() == sz(s);
	if (res) printf("VALID\n");
	else printf("INVALID\n");
}
