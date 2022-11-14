#include <bits/stdc++.h>
using namespace std;

int n, f[7], p[7];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		f[x]++; p[x] = i;
	}
	for (int i = 6; i > 0; i--)
		if (f[i] == 1) {
			printf("%d\n", p[i]);
			return 0;
		}
	printf("none\n");
}
