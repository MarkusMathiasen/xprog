#include <bits/stdc++.h>
using namespace std;

int n, m;
unordered_map<int, int> rain, p;
vector<int> lef, righ, st;

int query(int l, int r, int i) {
	if (l <= lef[i] && r >= righ[i])
		return st[i];
	if (l > righ[i] || r < lef[i])
		return 0;
	return max(query(l, r, i*2), query(l, r, i*2+1));
}

int main() {
	while (scanf("%d", &n), n) {
		rain.clear();
		p.clear();
		st.assign(4*n, 0);
		lef.assign(4*n, 0);
		righ.assign(4*n, 0);
		int prev = -2e9;
		for (int i = 0; i < n; i++) {
			int y, r; scanf("%d%d", &y, &r);
			rain[y] = r;
			st[n+i] = r;
			lef[n+i] = righ[n+i] = y;
			p[y] = prev == y-1 ? p[y-1] : y;
			prev = y;
		}
		for (int i = n-1; i > 0; i--) {
			st[i] = max(st[2*i], st[2*i+1]);
			lef[i] = min(lef[2*i], lef[2*i+1]);
			righ[i] = max(righ[2*i], righ[2*i+1]);
		}
		scanf("%d", &m);
		while (m--) {
			int y, x; scanf("%d%d", &y, &x);
			bool maybe = !rain[x] || !rain[y] || p[x] != p[y];
			int ry = rain[y];
			if (ry == 0)
				ry = 1e9+2;
			int rx = rain[x];
			if (rx == 0)
				rx = ry;
			int q = query(y+1, x-1, 1);
			if (q < rx && rx <= ry)
				printf(maybe ? "maybe\n" : "true\n");
			else
				printf("false\n");
		}
		printf("\n");
	}
}
