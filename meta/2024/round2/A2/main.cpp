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
		if (s[i] == '0' || s[sz(s)-1-i] == '0') return false;
		if (i != 0 && s[i-1] > s[i]) return false;
		if (i != 0 && s[sz(s)-1-i] < s[sz(s)-i]) return false;
	}
	ll mid = sz(s)/2;
	if (sz(s) > 1 && (s[mid] == s[mid-1] || s[mid] == s[mid+1])) return false;
	return true;
}

ll stupid(ll A, ll B, ll M) {
	ll res = 0;
	rep(i, A, B+1) {
		if (is_peak(i) && i%M == 0)
			res++;//, printf("%lld ", i);
	}
	fflush(stdout);
	return res;
}

ll T;
vi peaks;

// void gen_peaks(ll x, ll len) {
// 	if (peaks.count(x)) return;
// 	peaks.insert(x);
// 	if (len == 17) return;
// 	ll ten = 1;
// 	rep(i, 0, len) ten *= 10;
// 	ll first = x/(ten/10), last = x%10;
// 	rep(i, 1, last+(len > 1 ? 1 : 0)) rep(j, 1, first+(len > 1 ? 1 : 0)) {
// 		gen_peaks((ten*j+x)*10 + i, len+2);
// 	}
// }

ll smart2(ll A, ll B, ll M) {
	ll res = 0;
	for (ll x : peaks) {
		if (x % M == 0 && A <= x && x <= B) res++;
	}
	return res;
}

ll smart(ll A, ll B, ll M) {
	ll res = 0;
	auto start = lower_bound(all(peaks), A);
	auto finish = upper_bound(all(peaks), B);
	for (auto it = start; it != finish; it++) {
		if (*it % M == 0) res++;
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);

	ifstream f("peak_file.txt");
	f.tie(0)->sync_with_stdio(0);
	ll x; while (f >> x) peaks.push_back(x);

	cin >> T;
	vi A(T), B(T), M(T), res(T);
	rep(i, 0, T) cin >> A[i] >> B[i] >> M[i];
	#pragma omp parallel for
	for (ll i = 0; i < T; i++) {
		res[i] = smart(A[i], B[i], M[i]);
		// if (B[i]-A[i] < 1000) {
		// 	assert(stupid(A[i], B[i], M[i]) == res[i]);
		// }
	}
	rep(t, 1, T+1) {
		printf("Case #%lld: %lld\n", t, res[t-1]);
	}
	// rep(t, 1, T+1) {
	// 	printf("Case #%lld: ", t);
	// 	ll A, B, M; cin >> A >> B >> M;
	// 	ll res = smart(A, B, M);
	// 	if (B-A < 1000) {
	// 		ll res_stupid = stupid(A, B, M);
	// 		assert(res_stupid == res);
	// 	}
	// 	printf("%lld\n", res);
	// }
	
}