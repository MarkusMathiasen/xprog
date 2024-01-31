#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

struct FT {
	vector<ll> s;
	FT(ll n) : s(n) {}
	void update(ll pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(ll pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

ll n, N, res = 0;
vi A, B, to_num, doub;
map<ll, ll> to_idx;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	A.assign(n, 0);
	rep(i, 0, n) cin >> A[i];
	B.assign(all(A));
	sort(all(B));
	to_num.push_back(B[0]);
	rep(i, 1, n) if (B[i] != B[i-1]) to_num.push_back(B[i]);
	N = sz(to_num);
	rep(i, 0, N) to_idx[to_num[i]] = i;
	ll j = 0;
	doub.assign(N, N);
	rep(i, 0, N) {
		while (j < N && to_num[j] < 2*to_num[i]) j++;
		if (j == N) break;
		doub[i] = j;
	}
	FT ft1(N), ft2(N);
	for (ll x : A) {
		ll y = to_idx[x];
		res += ft2.query(N) - ft2.query(doub[y]);
		ft2.update(y, ft1.query(N) - ft1.query(doub[y]));
		ft1.update(y, 1);
	}
	printf("%lld\n", res);
}
