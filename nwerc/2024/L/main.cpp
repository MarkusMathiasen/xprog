#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, m, x, y;
vi shelves, books;

bool check(ll art) {
	ll b = 0, s = 0, s_cnt = 0;
	while (b < m && s < n) {
		if (books[b] > shelves[s]) {
			s++;
			s_cnt = 0;
		} else {
			s_cnt++;
			b++;
			if (s_cnt == (s < art ? y : x)) {
				s_cnt = 0;
				s++;
			}
		}
	}
	return b == m;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> n >> m >> x >> y;
	shelves.resize(n);
	books.resize(m);
	rep(i, 0, n) cin >> shelves[i];
	rep(i, 0, m) cin >> books[i];
	sort(all(shelves));
	sort(all(books));
	ll lo = 0, hi = n+1;
	while (lo < hi) {
		ll mid = (lo+hi)/2;
		if (check(mid)) {
			lo = mid+1;
		} else {
			hi = mid;
		}
	}
	if (lo == 0) printf("impossible\n");
	else printf("%lld\n", lo-1);
}
