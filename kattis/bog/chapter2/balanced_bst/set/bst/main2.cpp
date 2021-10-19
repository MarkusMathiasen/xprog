sss#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll c = 0, n;
set<ll> bst;
vector<ll> h;

int main() {
	scanf("%lld", &n);
	h.assign(n+1, -1);
	while (n--) {
		ll x; scanf("%lld", &x);
		ll nh = 0;
		auto it = bst.upper_bound(x);
		if (it != bst.end())
			nh = max(nh, h[*it]+1);
		if (it != bst.begin()) {
			it--;
			nh = max(nh, h[*it]+1);
		}
		h[x] = nh;
		c += nh;
		printf("%lld\n", c);
		bst.insert(x);
	}
}
