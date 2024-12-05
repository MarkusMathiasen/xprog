#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

string s; ll pos, res = 0;
bool att, doing=true;

ll read_int() {
	ll res = 0, seen = 0;
	while (pos < sz(s) && isdigit(s[pos])) {
		res = res*10 + s[pos++]-'0';
		seen++;
	}
	if (seen < 1 || seen > 3) {
		att = false;
		return 0;
	}
	return res;
}

ll read_s() {
	ll res = 0;
	pos = 0;
	while (pos < sz(s)-4) {
		if (s.substr(pos, 4) == "do()") {
			doing = true;
			pos += 4;
			continue;
		}
		if (s.substr(pos, 7) == "don't()") {
			doing = false;
			pos += 7;
			continue;
		}
		if (!doing) {
			pos++;
			continue;
		}
		if (s.substr(pos, 4) != "mul(") {
			pos++;
			continue;
		}
		pos += 4;
		att = true;
		ll a = read_int();
		if (!att) continue;
		if (s[pos++] != ',') continue;
		ll b = read_int();
		if (!att) continue;
		if (s[pos++] != ')') continue;
		res += a*b;
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	while (getline(cin, s) && s != "") {
		res += read_s();
	}
	printf("%lld\n", res);
}
