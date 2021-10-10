#include <bits/stdc++.h>
using namespace std;

int h, w, n;

int main() {
	scanf("%d%d%d", &h, &w, &n);
	int layers = 0;
	int row = 0;
	for (int i = 0; i < n; i++) {
		int b; scanf("%d", &b);
		row += b;
		if (row > w)
			break;
		if (row == w)
			layers++, row = 0;
		if (layers == h) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}
