#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int x; scanf("%d", &x);
		int res = 0;
		for (int i = 1e9; i > 0; i /= 10)
			res = max(res, __builtin_popcount(x/i));
		printf("%d\n", res);
	}
}
