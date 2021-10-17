#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; scanf("%d%d", &n, &m);
	char dance[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &dance[i][j]);
	int res = 1;
	for (int col = 0; col < m; col++) {
		bool empty = true;
		for (int row = 0; row < n; row++)
			empty &= dance[row][col] == '_';
		res += empty;
	}
	printf("%d\n", res);
}
