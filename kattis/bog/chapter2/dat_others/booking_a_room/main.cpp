#include <bits/stdc++.h>
using namespace std;

int main() {
	int r, n; scanf("%d%d", &r, &n);
	if (r == n) {
		printf("too late\n");
		return 0;
	}
	vector<bool> A(r, false);
	while (n--) {
		int x; scanf("%d", &x); x--;
		A[x] = true;
	}
	for (int i = 0; i < r; i++)
		if (!A[i]) {
			printf("%d\n", i+1);
			return 0;
		}
}
