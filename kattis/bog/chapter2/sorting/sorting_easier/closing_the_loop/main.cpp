#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n; scanf("%d", &n);
		vector<int> r, b;
		for (int i = 0; i < n; i++) {
			int l; char c; scanf("%d%c", &l, &c);
			if (c == 'R')
				r.push_back(l);
			else if (c == 'B')
				b.push_back(l);
			else
				throw c;
		}
		sort(r.rbegin(), r.rend());
		sort(b.rbegin(), b.rend());
		int res = 0;
		for (int i = 0; i < (int)min(r.size(), b.size()); i++)
			res += r[i]+b[i]-2;
		printf("Case #%d: %d\n", t, res);
	}
}
