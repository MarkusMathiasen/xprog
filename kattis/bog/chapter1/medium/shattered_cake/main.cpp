#include <bits/stdc++.h>
using namespace std;

int w, n, area = 0;

int main() {
	scanf("%d%d", &w, &n);
	while (n--) {
		int a, b; scanf("%d%d", &a, &b);
		area += a*b;
	}
	printf("%d\n", area/w);
}
