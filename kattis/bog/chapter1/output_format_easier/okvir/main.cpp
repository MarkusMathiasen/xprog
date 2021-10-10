#include <bits/stdc++.h>
using namespace std;

int main() {
	int M, N; scanf("%d%d", &M, &N);
	int U, L, R, D; scanf("%d%d%d%d", &U, &L, &R, &D);
	char A[M+U+D][N+L+R];
	for (int i = 0; i < M+U+D; i++)
		for (int j = 0; j < N+L+R; j++)
			A[i][j] = (i+j)%2 == 0 ? '#' : '.';
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			scanf(" %c", &A[i+U][j+L]);
	for (int i = 0; i < M+U+D; i++) {
		for (int j = 0; j < N+L+R; j++)
			printf("%c", A[i][j]);
		printf("\n");
	}
}
