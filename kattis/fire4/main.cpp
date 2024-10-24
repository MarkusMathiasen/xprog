#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll N, M;
vector<pii> A, B;

bool contains(pii x, ll p) {
	if (x.first < x.second) return x.first <= p && p <= x.second;
	else return p <= x.second || p >= x.first;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
	cin >> N >> M;
	A.resize(N);
	rep(i, 0, N) cin >> A[i].first >> A[i].second;
	sort(all(A), [](const pii& a, const pii& b) {
		if (a.first != b.first) return a.first < b.first;
		return a.second > b.second;
	});

	// Remove intervals contained in other intervals
	ll border = 0;
	rep(i, 0, N) if (A[i].second < A[i].first) border = max(border, A[i].second), A[i].second += M;
	ll s = 0; while (A[s].second <= border) s++;
	B.push_back(A[s]);
	rep(i, s+1, N) {
		if (A[i].second <= B.back().second) continue;
		B.push_back(A[i]);
	}
	N = sz(B);
	rep(i, 0, N) B.push_back(pii{B[i].first + M, B[i].second + M});
	// Now B is the intervals
	// Find next interval for each interval
	sort(all(B));
	vi nxt(N, -1);
	ll from = 0;
	rep(to, 1, 2*N) {
		while (B[to].first > B[from].second) {
			nxt[from++] = (to-1+N)%N;
			if (from == N) goto out;
		}
	}
out:;
	rep(i, 0, N) if (nxt[i] == i) {
		printf("-1\n");
		return 0;
	}

	// Find shortest cycle
	rep(i, 0, N) B[i].second -= B[i].second >= M ? M : 0;
	vi cycle_len(N, 0);
	queue<ll> q; q.push(0);
	while (!cycle_len[q.front()]) {
		q.push(nxt[q.back()]);
		while (sz(q) > 1 && contains(B[q.back()], B[q.front()].first)) {
			cycle_len[q.front()] = sz(q);
			q.pop();
		}
	}
	ll res = 1e9;
	rep(i, 0, N) if (cycle_len[i]) res = min(res, cycle_len[i]);
	printf("%lld\n", res);
}
