#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int n, m;
vector<vector<char>> house;

int main() {
	int t = 0;
	while (scanf("%d%d", &m, &n), n && m) {
		house.assign(n, vector<char>(m, ' '));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf(" %c", &house[i][j]);
		ii pos;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (house[i][j] == '*')
					pos = ii(i, j);
		int dir; // 0 = up; 1 = right; 2 = down; 3 = left
		if (pos.first == n-1)
			dir = 0;
		else if (pos.second == 0)
			dir = 1;
		else if (pos.first == 0)
			dir = 2;
		else if (pos.second == m-1)
			dir = 3;
		else
			throw pos;
		do {
			int& x = pos.first;
			int& y = pos.second;
			char here = house[x][y];
			if (here == '\\') {
				if (dir == 0)
					dir = 3;
				else if (dir == 3)
					dir = 0;
				else if (dir == 2)
					dir = 1;
				else if (dir == 1)
					dir = 2;
			}
			else if (here == '/') {
				if (dir == 0)
					dir = 1;
				else if (dir == 1)
					dir = 0;
				else if (dir == 2)
					dir = 3;
				else if (dir == 3)
					dir = 2;
			}
			if (dir == 0)
				x--;
			else if (dir == 1)
				y++;
			else if (dir == 2)
				x++;
			else if (dir == 3)
				y--;
			else
				throw dir;
			if (x == 0 || x == n-1 || y == 0 || y == m-1)
				break;
		} while (true);
		house[pos.first][pos.second] = '&';
		printf("HOUSE %d\n", ++t);
		for (auto row : house) {
			for (auto col : row)
				printf("%c", col);
			printf("\n");
		}
	}
}
