#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T;
string s;

string nums = "IVXLCDM";

bool smaller(char a, char b) {
	ll ia = nums.find(a);
	ll ib = nums.find(b);
	return ia < ib;
}

ll val(char c) {
	if (c == 'I') return 1;
	if (c == 'V') return 5;
	if (c == 'X') return 10;
	if (c == 'L') return 50;
	if (c == 'C') return 100;
	if (c == 'D') return 500;
	if (c == 'M') return 1000;
	assert(false);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> s;
		vi cnt(7, 0);
		ll res = 0;
		rep(i, 0, sz(s)) {
			ll idx = nums.find(s[i]);
			rep(j, 0, idx) {
				res -= cnt[j]*val(nums[j]);
				cnt[j] = 0;
			}
			cnt[idx]++;
		}
		rep(i, 0, 7) res += cnt[i]*val(nums[i]);
		printf("%lld\n", res);
	}
}
