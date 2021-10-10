#include <bits/stdc++.h>
using namespace std;

int w, l, n;

int main() {
	while (scanf("%d%d", &w, &l) && w != 0) {
		int tx, ty, ax, ay; tx = ty = ax = ay = 0;
		scanf("%d", &n);
		while (n--) {
			char c; int d; scanf(" %c%d", &c, &d);
			if (c == 'u') {
				ty += d;
				ay = min(ay+d, l-1);
			}
			if (c == 'd') {
				ty -= d;
				ay = max(ay-d, 0);
			}
			if (c == 'r') {
				tx += d;
				ax = min(ax+d, w-1);
			}
			if (c == 'l') {
				tx -= d;
				ax = max(ax-d, 0);
			}
		}
		printf("Robot thinks %d %d\n", tx, ty);
		printf("Actually at %d %d\n\n", ax, ay);
	}
}
