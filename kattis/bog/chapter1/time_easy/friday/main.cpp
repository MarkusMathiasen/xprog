#include <bits/stdc++.h>
using namespace std;

int T, M, D;

int main() {
	scanf("%d", &T);
	while (scanf("%d%d", &D, &M), T--) {
		int res = 0, d = 6, days;
		while (M--) {
			scanf("%d", &days);
			res += (days >= 13 && (d+12)%7 == 4);
			d = (d+days)%7;
		}
		printf("%d\n", res);
	}
}
