#include <bits/stdc++.h>
using namespace std;

int grid[10][10];
int flashCnt = 0;

void update(int x, int y, bool inc) {
	if (x < 0 || x > 9 || y < 0 || y > 9)
		return;
	if (grid[x][y] == 0)
		return;
	grid[x][y] += inc;
	if (grid[x][y] <= 9)
		return;
	grid[x][y] = 0;
	flashCnt++;
	update(x-1, y-1, true);
	update(x, y-1, true);
	update(x+1, y-1, true);
	update(x-1, y, true);
	update(x+1, y, true);
	update(x-1, y+1, true);
	update(x, y+1, true);
	update(x+1, y+1, true);
}

int main() {
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			char c; scanf(" %c", &c);
			grid[i][j] = c-'0';
		}
	int round;
	for (round = 0; true; round++) {
		flashCnt = 0;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				grid[i][j]++;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				update(i, j, false);
		if (flashCnt == 100)
			break;
	}
	printf("%d\n", round+1);
}
