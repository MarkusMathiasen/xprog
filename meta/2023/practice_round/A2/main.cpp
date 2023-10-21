#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, A, B, C;

bool can_build(ll A, ll B, ll C, ll k) {
	ll S = (k+2)/2;
	ll D = max(0ll, k-S);
	S = max(0ll, S-D);
	ll a, b, sum;
	bool p1 = __builtin_smulll_overflow(S, A, &a);
	bool p2 = __builtin_smulll_overflow(D, B, &b);
	bool p3 = __builtin_saddll_overflow(a, b, &sum);
	return !p1 && !p2 && !p3 && sum <= C;
	//return S*A + D*B <= C;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	rep(t, 1, T+1) {
		cin >> A >> B >> C;
		ll res;
		if (B <= A)
			res = max(0ll, (C/B)*2-1);
		else if (A*2 <= B) {
			res = C/A;
		}
		else {
			ll low = 1, high = 1e16+5;
			while (low < high) {
				ll mid = (low+high)/2;
				if (can_build(A, B, C, mid))
					low = mid+1;
				else
					high = mid;
			}
			res = low-1;
		}
		printf("Case #%lld: %lld\n", t, res);
	}
}
