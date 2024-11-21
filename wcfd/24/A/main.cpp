#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool get(ll cas, ll i) {
	return (cas >> i) & 1;
}

bool is_connected(ll cas) {
	vi stack;
	ll count = 0;
	unordered_set<ll> visited;
	rep(i, 0, 24) {
		if (get(cas, i)) {
			if (stack.empty()) stack.push_back(i);
			count++;
		}
	}
	while(!stack.empty()) {
		ll cur = stack.back();
		stack.pop_back();
		if (!get(cas, cur)) continue;
		if (visited.count(cur)) continue;
		visited.insert(cur);
		if (cur % 6 > 0) stack.push_back(cur - 1);
		if (cur % 6 < 5) stack.push_back(cur + 1); 
		if (cur > 6) stack.push_back(cur - 6);
		if (cur < 18) stack.push_back(cur + 6);
	}
	return count == sz(visited);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	ll cas = 0;
	rep(i, 0, 24) {
		char c;
		cin >> c;
		if (c == 'o') cas |= (1 << i);
	}
	ll m = 24;
	ll mm = 0;
	rep(i, 0, 1 << 24) {
		if (__popcount(i) == __popcount(cas)) {
			if (is_connected(i)) {
				ll dis = __popcount(i ^ cas) / 2;
				if (dis < m) {
					m = dis;
					mm = i;
				}
			}
		}
	}
	rep(i, 0, 24) {
		if (get(mm, i)) printf("o");
		else printf(".");
		if (i % 6 == 5) printf("\n");
	}
}
