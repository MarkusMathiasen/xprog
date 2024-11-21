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
	ll n, t;
	cin >> n >> t;
	vi start;
	vi end;
	rep(i, 0, n) {
		ll b, d;
		cin >> b >> d;
		ll offset = 0;
		while (offset < t) {
			if (offset + b < t) start.push_back(offset + b);
			if (offset + b + d < t) end.push_back(offset + b + d);
			offset += b + d;
		}
	}
	sort(start.begin(), start.end());
	sort(end.begin(), end.end());
	ll count = 0;
	ll m = 0;
	end.push_back(t + 1);
	ll i = 0;
	ll j = 0;
	while (start.size() > i) {
		if (start[i] < end[j]) {
			count++;
			i++;
			m = max(m, count);
		}
		else {
			count--;
			j++;
		}
	}
	printf("%lld\n", m);
}
