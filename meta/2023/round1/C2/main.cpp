#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T, N;
bitset<4'000'001> S;
bitset<4'000'001> S2;
bitset<4'000'001> f;

void printS() {
	rep(i, 1, N+1) printf("%d", S[i] ? 1 : 0);
	printf("\n");
}
void printS2() {
	rep(i, 1, N+1) printf("%d", S2[i] ? 1 : 0);
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
		S2.reset();
		f.reset();
		rep(i, 1, N+1) {
			char c; cin >> c;
			if (c == '1') S.flip(i), S2.flip(i);
		}
		ll Q; cin >> Q;
		ll final_res = 0, res = 0;
		rep(i, 1, N+1) if (S2[i]) {
			res++;
			f.flip(i);
			for (ll j = i; j <= N; j += i)
				S2.flip(j);
		}
		while (Q--) {
			ll x; cin >> x;
			if (f[x]) res--;
			else res++;
			f.flip(x);
			final_res += res;
		}
		printf("%lld\n", final_res);
	}
}
