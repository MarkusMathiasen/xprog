#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		vector<int> down(n, 0);
		for (int i = 0; i < n; i++)
			scanf("%d", &down[i]);
		vector<int> res;
		int m = n+1;
		for (int i = n-1; i >= 0; i--) {
			int x = down[i];
			if (x > m)
				res.push_back(x);
			m = min(m, x);
		}
		printf("%d\n", (int)res.size());
		sort(res.begin(), res.end());
		for (int x : res)
			printf("%d\n", x);
	}
}
