#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	unordered_map<int, int> m;
	int res = n;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		if (m.count(x))
			res = min(res, i-m[x]);
		m[x] = i;
	}
	printf("%d\n", res);
}
