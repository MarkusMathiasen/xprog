#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll fast_solution(ll N, ll K);
ll brute_force(ll N, ll K);

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll N, K;
	cin >> N >> K;
	printf("%lld\n", fast_solution(N, K));
	rep(n, 1, 11) rep(k, 2, 11) {
		ll fast = fast_solution(n, k);
		ll slow = brute_force(n, k);
		if (fast != slow) {
			printf("%lld %lld\n", n, k);
			printf("fast: %lld\n", fast);
			printf("slow: %lld\n", slow);
			return 0;
		}
	}
}

ll fast_solution(ll N, ll K) {
	vi length = {1}, ones = {0};
	while (length.back() < N) {
		length.push_back(length.back()*K+1);
		ones.push_back(ones.back()*K+1);
	}
	ll res = 0;
	if (K < sz(length) && N > length[K])
		return N-length[K] + ones[K];
	for (ll i = sz(length)-1; i >= 0; i--) {
		ll num = N/length[i];
		res += num*ones[i];
		N %= length[i];
	}
	return res;
}
bool repeating(string& s, ll K) {
	rep(t, 1, sz(s)/K+1) {
		bool o = true;
		rep(i, 0, t)
			rep(j, 0, K)
				if (s[sz(s)-t*K+i] != s[sz(s)-t*K+i+j*t]) {
					o = false;
					goto end;
				}
		end:
		if (o) return true;
	}
	return false;;
}

ll brute_force(ll N, ll K) {
	string s = "0";
	while (sz(s) < N)
		s.push_back(repeating(s, K) ? '1' : '0');
	ll res = 0;
	for (char c : s)
		res += c == '1';
	return res;
}
