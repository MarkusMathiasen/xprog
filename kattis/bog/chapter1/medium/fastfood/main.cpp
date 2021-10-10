#include <bits/stdc++.h>
using namespace std;

int t;


int main() {
	scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d%d", &n, &m);
		vector<vector<int>> req(n, vector<int>());
		vector<int> cash(n, 0);
		for (int i = 0; i < n; i++) {
			int k; scanf("%d", &k);
			req[i].assign(k, 0);
			while (k--)
				scanf("%d", &req[i][k]);
			scanf("%d", &cash[i]);
		}
		vector<int> stickers(m+1, 0);
		for (int i = 1; i <= m; i++)
			scanf("%d", &stickers[i]);
		int res = 0;
		for (int i = 0; i < n; i++) {
			int am = 1e9;
			for (int stick : req[i])
				am = min(am, stickers[stick]);
			res += am*cash[i];
		}
		printf("%d\n", res);
	}
}
