#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

vi A, B;

bool magical(vi& A) {
	ll mex = 0;
	map<ll,ll> left, right;
	for (ll x : A) left[x]++;
	for (ll i = sz(A)-1; i >= 1; i--) {
		right[A[i]]++;
		left[A[i]]--;
		if (left[A[i]] == 0) left.erase(A[i]);
		while (right.count(mex)) mex++;
		if (mex > left.begin()->first) return 0;
	}
	return 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	ll T; cin >> T;
	while (T--) {
		ll n; cin >> n;
		A.resize(n); B.clear();
		rep(i, 0, n) cin >> A[i];
		bool zero = false;
		rep(i, 0, n) {
			if (!zero || A[i] != 0) B.push_back(A[i]);
			if (A[i] == 0) zero = true;
		}
		ll ans = sz(B);
		if (!magical(B)) ans--;
		printf("%lld\n", ans);
	}
}
