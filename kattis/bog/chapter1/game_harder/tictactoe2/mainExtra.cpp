#include <bits/stdc++.h>
using namespace std;

int t;
char grid[3][3];

int wins(char c) {
	int res = 0;
	for (int i = 0; i < 3; i++) {
		bool row = true;
		bool col = true;
		for (int j = 0; j < 3; j++) {
			row &= grid[i][j] == c;
			col &= grid[j][i] == c;
		}
		res += row;
		res += col;
	}
	bool dia1 = true, dia2 = true;
	for (int i = 0; i < 3; i++) {
		dia1 &= grid[i][i] == c;
		dia2 &= grid[i][2-i] == c;
	}
	res += dia1;
	res += dia2;
	return res;
}

int count(char c) {
	int res = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			res += grid[i][j] == c;
	return res;
}

bool valid() {
	int x = wins('X');
	int o = wins('O');
	int cx = count('X');
	int co = count('O');
	if (cx == co)
		return x == 0;
	if (cx-1 != co)
		return false;
	return o == 0;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				scanf(" %c", &grid[i][j]);
		printf(valid() ? "yes\n" : "no\n");
	}
	return 0;
}

void perm(int x, int y) {
	if (x == 3) {
		if (valid() && (wins('X') || wins('O'))) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++)
					printf("%c", grid[i][j]);
				printf("\n");
			}
			printf("\n");
		}
		return;
	}
	int nx = y != 2 ? x : x+1;
	int ny = y == 2 ? 0 : y+1;
	grid[x][y] = '.';
	perm(nx, ny);
	grid[x][y] = 'X';
	perm(nx, ny);
	grid[x][y] = 'O';
	perm(nx, ny);
}

int main2() {
	perm(0, 0);
	return 0;
}
