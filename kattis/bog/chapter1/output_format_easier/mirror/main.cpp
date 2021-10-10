#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int R, C; scanf("%d%d", &R, &C);
		char A[R][C];
		for (int r = 0; r < R; r++)
			for (int c = 0; c < C; c++)
				scanf(" %c", &A[r][c]);
		printf("Test %d\n", t);
		for (int r = R-1; r >= 0; r--) {
			for (int c = C-1; c >= 0; c--)
				printf("%c", A[r][c]);
			printf("\n");
		}
	}
}
