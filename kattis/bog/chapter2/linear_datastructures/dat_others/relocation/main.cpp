#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q; scanf("%d%d", &n, &q);
	vector<int> A(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	while (q--) {
		int cmd, a, b; scanf("%d%d%d", &cmd, &a, &b);
		if (cmd == 1)
			A[--a] = b;
		else if (cmd == 2)
			printf("%d\n", abs(A[--a]-A[--b]));
		else throw cmd;
	}
}
