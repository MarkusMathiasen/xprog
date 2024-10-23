#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

bool is_peak(ll x) {
	string s = to_string(x);
	if (sz(s)%2 != 1) return false;
	rep(i, 0, sz(s)/2+1) {
		if (s[i] == '0') return false;
		if (i != 0 && s[i-1]+1 != s[i]) return false;
		if (s[i] != s[sz(s)-i-1]) return false;
	}
	return true;
}

ll stupid(ll A, ll B, ll M) {
	ll res = 0;
	rep(i, A, B+1) {
		if (is_peak(i) && i%M == 0)
			res++;
	}
	return res;
}

ll T;
vi peaks;

void gen_peaks(ll x, ll len) {
	peaks.push_back(x);
	if (len == 17) return;
	ll ten = 1;
	rep(i, 0, len) ten *= 10;
	rep(i, 1, x%10) {
		if (i+1 == x%10)
			gen_peaks((ten*i+x)*10 + i, len+2);
	}
}

ll smart(ll A, ll B, ll M) {
	ll res = 0;
	for (ll x : peaks) {
		if (A <= x && x <= B && x%M == 0) res++;
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);

	rep(i, 1, 10) gen_peaks(i, 1);
	sort(all(peaks));

	cin >> T;
	rep(t, 1, T+1) {
		printf("Case #%lld: ", t);
		ll A, B, M; cin >> A >> B >> M;
		ll res = smart(A, B, M);
		if (B-A < 1000) {
			ll res_stupid = stupid(A, B, M);
			assert(res_stupid == res);
		}
		printf("%lld\n", res);
	}
	
}