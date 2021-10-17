#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		char grid[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf(" %c", &grid[i][j]);
		char res[m];
		for (int col = 0; col < m; col++) {
			int ones = 0;
			for (int row = 0; row < n; row++)
				ones += grid[row][col] == '1';
			res[col] = ones*2 >= n ? '1' : '0';
		}
		for (char c : res)
			printf("%c", c);
		printf("\n");
	}
}
