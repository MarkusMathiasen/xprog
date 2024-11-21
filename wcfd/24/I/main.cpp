#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll my_turn(ll p, ll x, ll c) {
	if (x == 0 && c == 0) return 2;
	if (x == 0 && c != 0) return 0;
	bool maybe = false;
	bool yes = true;
	rep(pl, 1, min(p, x + 1)) {
		if ((c + pl + 1) % p == 0 && x - pl != 0) continue;
		ll z = my_turn(p, x - pl, (c + pl + 1) % p);
		if (z == 2) {
			maybe = true;
		}
		else if (z == 1) {
			maybe = true;
			yes = false;
		}
		else if (z == 0) yes = false;
	}
	if (yes) return 2;
	else if (maybe) return 1;
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	ll p, c;
	cin >> p >> c;
	ll x = my_turn(p, c, 1);
	if (x == 2) printf("yes\n");
	else if (x == 1) printf("maybe\n");
	else printf("no\n");


}
