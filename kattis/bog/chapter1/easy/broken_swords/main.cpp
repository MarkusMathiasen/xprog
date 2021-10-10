#include <bits/stdc++.h>
using namespace std;

int n, h, v;

int main() {
	scanf("%d", &n);
	h = v = 2*n;
	while (n--) {
		int a, b, c, d; scanf("%1d%1d%1d%1d", &a, &b, &c, &d);
		v -= a+b;
		h -= c+d;
	}
	int res = min(h/2, v/2);
	printf("%d %d %d\n", res, v-2*res, h-2*res);
}
