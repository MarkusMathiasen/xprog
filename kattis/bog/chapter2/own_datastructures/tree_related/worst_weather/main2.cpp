#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

struct node {
	int left = -2e9;
	int right = -2e9;
	int val = -2e9;
};

int n, m;
vector<node> st;
vector<int> rain;
unordered_map<int, int> toIndex;
set<int> years;
unordered_map<int, int> p;

int query(int l, int r, int i) {
	node& x = st[i];
	if (x.left > r || x.right < l)
		return 0;
	if (x.left >= l && x.right <= r)
		return x.val;
	return max(query(l, r, i*2), query(l, r, i*2+1));
}

void build(int l, int r, int i) {
	node& x = st[i];
	x.left = l;
	x.right = r;
	if (l == r)
		x.val = rain[l];
	else {
		build(l, (l+r)/2, i*2);
		build((l+r)/2+1, r, i*2+1);
		x.val = max(st[i*2].val, st[i*2+1].val);
	}
}

int main() {
	while (scanf("%d", &n), n) {
		st.assign(4*n, node());
		rain.assign(n, 0);
		toIndex.clear();
		years.clear();
		p.clear();
		int prev = -2e9;
		for (int i = 0; i < n; i++) {
			int y; scanf("%d%d", &y, &rain[i]);
			toIndex[y] = i;
			years.insert(y);
			if (prev == y-1)
				p[y] = p[y-1];
			else
				p[y] = y;
			prev = y;
		}
		build(0, n-1, 1);
		scanf("%d", &m);
		while (m--) {
			int y, x; scanf("%d%d", &y, &x);
			int ry = years.count(y) ? rain[toIndex[y]] : 1e9+5;
			int rx = years.count(x) ? rain[toIndex[x]] : ry;
			int iy, ix;
			bool maybeSkip = false;
			auto it = years.upper_bound(y);
			if (it == years.end())
				maybeSkip = true;
			else
				iy = toIndex[*it];
			it = years.lower_bound(x);
			if (it == years.begin())
				maybeSkip = true;
			else
				ix = toIndex[*(--it)];
			if (maybeSkip) {
				printf("maybe\n");
				continue;
			}
			int q = query(iy, ix, 1);
			bool maybe = x-y == !years.count(x) || !years.count(y) || p[x] != p[y];
			for (int i = y; i <= x && !maybe; i++)
				maybe |= !years.count(i);
			if (rx <= ry && q < rx)
				printf(maybe ? "maybe\n" : "true\n");
			else
				printf("false\n");
		}
		printf("\n");
	}
}
