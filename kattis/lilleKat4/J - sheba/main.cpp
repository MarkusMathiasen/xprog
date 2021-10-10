#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[100][100];

void flex(int x, int y) {
	grid[x][y] = '+';
	for (int i = x-1; i <= x+1; i++)
		for (int j = y-1; j <= y+1; j++)
			if (0 <= i && i < n && 0 <= j && j < m && grid[i][j] == '#')
				flex(i, j);
	grid[x][y] = '*';
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &grid[i][j]);
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] == '#')
				flex(i, j), res++;
	printf("%d\n", res);
}
