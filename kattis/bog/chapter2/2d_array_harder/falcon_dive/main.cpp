#include <bits/stdc++.h>
using namespace std;

int n, m;
char c;

int main() {
	scanf("%d %d '%c'", &n, &m, &c);
	char b1[n][m], b2[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &b1[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf(" %c", &b2[i][j]);
	char res[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i][j] = b1[i][j] == c ? b2[i][j] : b1[i][j];
	int x1, y1;
	bool found = false;
	for (int i = 0; i < n && !found; i++)
		for (int j = 0; j < m && !found; j++)
			if (b1[i][j] == c)
				x1 = i, y1 = j, found = true;
	int x2, y2;
	found = false;
	for (int i = 0; i < n && !found; i++)
		for (int j = 0; j < m && !found; j++)
			if (b2[i][j] == c)
				x2 = i, y2 = j, found = true;
	int dx = x2-x1, dy = y2 - y1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (b2[i][j] == c) {
				int x = i+dx, y = j+dy;
				if (x >= 0 && x < n && y >= 0 && y < m)
					res[x][y] = c;
			}
	for (auto& row : res) {
		for (auto& col : row)
			printf("%c", col);
		printf("\n");
	}
}
