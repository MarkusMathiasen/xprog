#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, k; cin >> n >> k;
	vi h(k), m(k);
	rep(i, 0, k) cin >> h[i] >> m[i];
	ll res = 1e18;
	rep(mid, 0, k) {
		ll before = 1e18, after = 1e18;
		ll h_val = h[mid];
		if (h_val >= n) before = 0;
		// TODO, consider if we only need to visit mid
		priority_queue<ll, vector<ll>, greater<ll>> pq;
		rep(i, 0, k) {
			if (i == mid) continue;
			h_val += h[i];
			pq.push(h[i]);
			while (!pq.empty() && h_val - pq.top() >= n)
				h_val -= pq.top(), pq.pop();
			if (h_val >= n) before = min(before, (ll)pq.size());
		}
		while (!pq.empty()) pq.pop();
		ll m_val = m[mid];
		if (m_val >= n) after = 0;
		rep(i, 0, k) {
			if (i == mid) continue;
			m_val += m[i];
			pq.push(m[i]);
			while (!pq.empty() && m_val - pq.top() >= n)
				m_val -= pq.top(), pq.pop();
			if (m_val >= n) after = min(after, (ll)pq.size());
		}
		res = min(res, before+after);
	}
	printf("%lld\n", res);
}
