#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll T;
ll N, K;
vi S;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> T;
	rep(t, 1, T+1) {
		printf("Case #%lld: ", t);
		cin >> N >> K;
		S.assign(N, 0);
		rep(i, 0, N) cin >> S[i];
		ll s = S[0];
		rep(i, 0, N) s = min(s, S[i]);
		ll ans = N == 1 ? s : s + 2*(N-2)*s;
		printf(ans <= K ? "YES\n" : "NO\n");
	}
}