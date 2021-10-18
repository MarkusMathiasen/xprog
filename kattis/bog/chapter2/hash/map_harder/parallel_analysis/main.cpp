#include <bits/stdc++.h>
using namespace std;

int T, n;
unordered_map<int, int> mem;

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		mem.clear();
		scanf("%d", &n);
		while (n--) {
			int m; scanf("%d", &m);
			int maxCol = 0;
			for (int i = 0; i < m-1; i++) {
				int x; scanf("%d", &x);
				maxCol = max(maxCol, mem[x]);
			}
			int x; scanf("%d", &x);
			mem[x] = maxCol+1;
		}
		int res = 0;
		for (auto [k,v] : mem)
			res = max(res, v);
		printf("%d %d\n", t, res);
	}
}
