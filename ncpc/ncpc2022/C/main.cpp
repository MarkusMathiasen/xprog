#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int stock = 0;
	int res = 0;
	while (n--) {
		char c; scanf(" %c", &c);
		if (c == '1') {
			res++;
			stock = 2;
		} else if (c == '0') {
			if (stock)
				stock--, res++;
		} else {
			assert(false);
		}
	}
	printf("%d\n", res);
}
