#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m), n || m) {
		int res = 0;
		unordered_set<int> s;
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			s.insert(x);
		}
		for (int i = 0; i < m; i++) {
			int x; scanf("%d", &x);
			res += s.count(x);
		}
		printf("%d\n", res);
	}
}
