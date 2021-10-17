#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int g; scanf("%d", &g);
		set<int> res;
		for (int i = 0; i < g; i++) {
			int x; scanf("%d", &x);
			if (res.count(x))
				res.erase(x);
			else
				res.insert(x);
		}
		printf("Case #%d: %d\n", t, *res.begin());
	}
}
