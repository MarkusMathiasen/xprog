#include <bits/stdc++.h>
using namespace std;

int n, s, d;

int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &s, &d);
		if (d > s || s%2 != d%2)
			printf("impossible\n");
		else
			printf("%d %d\n", (s+d)/2, (s-d)/2);
	}
}
