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
	bool first = true;
	bool finished = false;
	bool first_begins = true;
	bool not_chosen = true;
	ll a = 10, b = 10;
	rep(i, 0, n) {
		if (finished) {
			printf("invalid\n");
			return 0;
		}
		ll x, y;
		cin >> x >> y;
		bool under = x <= a && y <= b;
		if (!under) {
			printf("invalid\n");
			return 0;
		}
		ll dx = a - x;
		ll dy = b - y;
		if (not_chosen) {
			if (dx > 0 && dy > 0) {
				printf("invalid\n");
				return 0;
			}
			if (dx == 0 && dy == 0) {
				first = false;
				continue;
			}
			if (dx > 0) first_begins = i % 2 != 0;
			else first_begins = i % 2 == 0;
			not_chosen = false;
		}
		if ((i % 2 == 0) != first_begins) {
			if ((dy > 0) || (first && dx >= 2) || dx >= 3) {
				printf("invalid\n");
				return 0;
			}
			first = false;
		}
		else {
			if ((dx > 0) || (first && dy >= 2) || dy >= 3) {
				printf("invalid\n");
				return 0;
			}
			first = false;
		}
		first = false;
		a = x;
		b = y;
		if (a == 0 || b == 0) finished = true;
	}
	if (finished) printf("finished\n");
	else printf("ongoing\n");
	return 0;
}
