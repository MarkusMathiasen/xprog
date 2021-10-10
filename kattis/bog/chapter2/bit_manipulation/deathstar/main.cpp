#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int res = 0;
		int x;
		for (int j = 0; j < n; j++)
			scanf("%d", &x), res |= x;
		printf("%d ", res);
	}
	printf("\n");
}
