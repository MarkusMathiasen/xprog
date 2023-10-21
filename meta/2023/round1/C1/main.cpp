#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, N;
bitset<4'000'001> q;
bitset<4'000'001> S;

void printS() {
	rep(i, 1, N+1) printf("%d", S[i] ? 1 : 0);
	printf("\n");
}
void printQ() {
	rep(i, 1, N+1) printf("%d", q[i] ? 1 : 0);
	printf("\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> T;
	rep(t, 1, T+1) {
		printf("Case #%lld: ", t);
		cin >> N;
		S.reset();
		rep(i, 1, N+1) {
			char c; cin >> c;
			if (c == '1') S.flip(i);
		}
		ll Q; cin >> Q;
		q.reset();
		while (Q--) {
			ll x; cin >> x;
			q.flip(x);
		}
		rep(i, 1, N+1)
			if (q[i])
				for (ll j = i; j <= N; j += i)
					S.flip(j);
		ll res = 0;
		rep(i, 1, N+1) if (S[i]) {
			res++;
			for (ll j = i; j <= N; j += i)
				S.flip(j);
		}
		printf("%lld\n", res);
	}
}
