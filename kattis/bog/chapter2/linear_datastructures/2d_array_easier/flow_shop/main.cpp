#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	int A[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &A[i][j]);
	for (int i = 1; i < n; i++)
		A[i][0] += A[i-1][0];
	for (int i = 1; i < m; i++)
		A[0][i] += A[0][i-1];
	for (int j = 1; j < m; j++)
		for (int i = 1; i < n; i++)
			A[i][j] += max(A[i-1][j], A[i][j-1]);
	for (int i = 0; i < n; i++)
		printf("%d ", A[i][m-1]);
	printf("\n");
}
