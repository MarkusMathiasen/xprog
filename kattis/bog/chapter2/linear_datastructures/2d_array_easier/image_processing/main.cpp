#include <bits/stdc++.h>
using namespace std;

int main() {
	int h, w, n, m;
	scanf("%d%d%d%d", &h, &w, &n, &m);
	int image[h][w];
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			scanf("%d", &image[i][j]);
	int mat[n][m];
	for (int i = n-1; i >= 0; i--)
		for (int j = m-1; j >= 0; j--)
			scanf("%d", &mat[i][j]);
	int res[h-n+1][w-m+1];
	for (int i = 0; i < h-n+1; i++)
		for (int j = 0; j < w-m+1; j++) {
			res[i][j] = 0;
			for (int k = 0; k < n; k++)
				for (int l = 0; l < m; l++)
					res[i][j] += mat[k][l]*image[i+k][j+l];
		}
	for (int i = 0; i < h-n+1; i++) {
		for (int j = 0; j < w-m+1; j++)
			printf("%d ", res[i][j]);
		printf("\n");
	}
}
