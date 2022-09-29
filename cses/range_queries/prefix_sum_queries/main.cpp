#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
	ll s = 0;
	ll ps = 0;
	ll left, right;
};

ll n, q;
vector<node> st;

void update(ll i, ll u, ll k) {
	if (st[i].left == u && st[i].right == u) {
		st[i].s = k;
		st[i].ps = max(0ll, k);
	} else if (st[i].left <= u && u <= st[i].right) {
		update(i*2, u, k);
		update(i*2+1, u, k);
		st[i].s = st[i*2].s + st[i*2+1].s;
		st[i].ps = max(st[i*2].ps, st[i*2].s + st[i*2+1].ps);
	}
}

ll sum(ll i, ll a, ll b) {
	if (st[i].left > b || st[i].right < a)
		return 0;
	else if (st[i].left >= a && st[i].right <= b)
		return st[i].s;
	return sum(i*2, a, b) + sum(i*2+1, a, b);
}

ll presum(ll i, ll a, ll b) {
	if (st[i].left > b || st[i].right < a)
		return 0ll;
	else if (st[i].left >= a && st[i].right <= b)
		return st[i].ps;
	return max(
		presum(i*2, a, b),
		sum(i*2, a, b) + presum(i*2+1, a, b)
	);
}

void init_st(ll i, ll left, ll right) {
	st[i].left = left;
	st[i].right = right;
	if (left != right) {
		init_st(i*2, left, (left+right)/2);
		init_st(i*2+1, (left+right)/2+1, right);
	}
}

int main() {
	scanf("%lld%lld", &n, &q);
	st.assign(4*n, node());
	init_st(1, 1, n);
	for (ll i = 1; i <= n; i++) {
		ll x; scanf("%lld", &x);
		update(1, i, x);
	}
	while (q--) {
		ll op, a, b; scanf("%lld%lld%lld", &op, &a, &b);
		if (op == 1)
			update(1, a, b);
		else {
			ll x = presum(1, a, b);
			printf("%lld\n", x);
		}
	}
	
}
