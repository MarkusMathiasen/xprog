#include <bits/stdc++.h>
using namespace std;

int n;
int A[101], B[101];

int main() {
	memset(A, 0, sizeof A);
	memset(B, 0, sizeof B);
	scanf("%d", &n);
	for (int t = 1; t <= n; t++) {
		int a, b; scanf("%d%d", &a, &b);
		A[a]++; B[b]++;
		int AC[101], BC[101];
		for (int i = 0; i <= 100; i++)
			AC[i] = A[i], BC[i] = B[i];
		int res = 0;
		int ia = 1, ib = 100;
		while (true) {
			while (ia <= 100 && !AC[ia])
				ia++;
			if (ia > 100)
				break;
			while (ib >= 1 && !BC[ib])
				ib--;
			if (ib < 1)
				break;
			res = max(res, ia+ib);
			if (AC[ia] >= BC[ib])
				AC[ia] -= BC[ib], BC[ib] = 0;
			else
				BC[ib] -= AC[ia], AC[ia] = 0;
		}
		printf("%d\n", res);
	}
}
