#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

vi d1(6), d2(6), d3(6);

bool wins(vi& a, vi& b) {
	ll cnt_wins = 0, cnt_loses = 0;
	for (ll x : a) for (ll y : b) {
		cnt_wins += x > y;
		cnt_loses += x < y;
	}
	return cnt_wins >= cnt_loses && cnt_wins > 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	rep(i, 0, 6) cin >> d1[i];
	rep(i, 0, 6) cin >> d2[i];
	rep(i, 0, 6) cin >> d3[i];
	if (wins(d1, d2) && wins(d1, d3)) {
		printf("1\n");
	}
	else if (wins(d2, d1) && wins(d2, d3)) {
		printf("2\n");
	}
	else if (wins(d3, d1) && wins(d3, d2)) {
		printf("3\n");
	}
	else {
		printf("No dice\n");
	}
}
