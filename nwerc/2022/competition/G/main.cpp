#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define rep(i, a, b) for(ll i = a; i < (b); ++i)

ll name = 1000000007;
ll len = 32;

ll print(string s) {
	printf("? %s\n", s.c_str());
	fflush(stdout);
	ll x; scanf("%lld", &x);
	return x;
}

ll step(ll recent) {
	return ((recent << 1ll) + print("right")) & ((1ll << len)-1ll);
}

int main() {
	vector<ll> his(len, 0);
	scanf("%lld", &his[0]);
	rep(i, 1ll, len)
		his[i] = print("right");
	print("flip");
	for (ll i = len-2ll; i >= 0; i--) {
		if (print("left") != his[i]) {
			printf("! %lld\n", len-1ll-i);
			return 0;
		}
	}
	rep(i, 0, len) {
		ll x = print("right");
		if (x != (0 < (name & (1 << (len-(ll)i-1ll)))))
			print("flip");
	}
	ll recent = step(name);
	ll res = 1;
	while (recent != name) {
		recent = step(recent);
		res++;
	}
	printf("! %lld\n", res);
}
