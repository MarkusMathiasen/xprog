#include <bits/stdc++.h>
using namespace std;

int t;
int a1, a2, b1, b2;

bool legal(int a, int b, int x, int y) {
	for (int i = 1; i < 8; i++) {
		if (a + i == x && b + i == y ||
			a + i == x && b - i == y ||
			a - i == x && b + i == y ||
			a - i == x && b - i == y)
			return true;
	}
	return false;
}

int main() {
	cin >> t;
	char ca, cb;
	while (t--) {
		scanf(" %c %d %c %d", &ca, &a2, &cb, &b2);
		a1 = ca - 'A'+1;
		b1 = cb - 'A'+1;
		if (a1 == b1 && a2 == b2) {
			printf("0 %c %d\n", 'A'+a1-1, a2);
			continue;
		}
		if (legal(a1, a2, b1, b2)) {
			printf("1 %c %d %c %d\n", ca, a2, cb, b2);
			continue;
		}
		bool done = false;
		for (int i = 1; i <= 8 && !done; i++) {
			for (int j = 1; j <= 8 && !done; j++) {
				if (legal(a1, a2, i, j) && legal(i, j, b1, b2)) {
					done = true;
					printf("2 %c %d %c %d %c %d\n",
						ca, a2, 'A'+i-1, j, cb, b2);
				}
			}
		}
		if (!done)
			printf("Impossible\n");
	}
}

