#include <bits/stdc++.h>
using namespace std;

bool pos = true;
int c, n, pas = 0;
int main() {
	scanf("%d%d", &c, &n);
	while (n--) {
		int l, e, w; scanf("%d%d%d", &l, &e, &w);
		if (pas - l < 0)
			pos = false;
		pas = pas + e - l;
		if (pas > c || pas < 0)
			pos = false;
		if (w > 0 && pas != c)
			pos = false;
		if (!n && w)
			pos = false;
	}
	printf(pos && !pas ? "possible\n" : "impossible\n");
}
