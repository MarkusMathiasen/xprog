#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	ll n;
	cin >> n;
	vi l(n), f(n);
	rep(i, 0, n) {
		ll a, b;
		cin >> a >> b;
		ll m = 0;
		rep(j, 0, i) {
			ll ai = min(a, (ll)l[j]);
			ll aa = max(a, (ll)l[j]);
			l[j] = ai;
			a = aa;
			ll bi = min(b, (ll)f[j]);
			ll ba = max(b, (ll)f[j]);
			f[j] = bi;
			b = ba;
			m = max(m, (ll)abs(l[j] - f[j]));
		}
		l[i] = a;
		f[i] = b;
		m = max(m, (ll)abs(l[i] - f[i]));
		printf("%lld\n", m);
	}
}
