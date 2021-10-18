#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		unordered_map<int, int> last;
		int lastDouble = 0, res = 0;
		for (int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			res = max(res, i-max(last[x], lastDouble));
			lastDouble = max(lastDouble, last[x]);
			last[x] = i;
		}
		printf("%d\n", res);
	}
}
