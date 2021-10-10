#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	char A[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &A[i][j]);
	for (int col = 0; col < m; col++) {
		int fallTo = n-1;
		for (int row = n-1; row >= 0; row--) {
			char& c = A[row][col];
			if (c == 'a')
				c = '.', A[fallTo--][col] = 'a';
			if (c == '#')
				fallTo = row-1;
		}
	}
	for (auto& row : A) {
		for (auto& c : row)
			printf("%c", c);
		printf("\n");
	}
}
