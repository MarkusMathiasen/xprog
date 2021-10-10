#include <bits/stdc++.h>
using namespace std;

char board[5][5];

bool checkPos(int x, int y) {
	if (x < 0 || y < 0 || x > 4 || y > 4)
		return true;
	return board[x][y] == '.';
}

int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf(" %c", &board[i][j]);
	bool res = true;
	int knights = 0;
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			if (board[i][j] == 'k') {
				knights++;
				res &= checkPos(i+2, j+1);
				res &= checkPos(i+2, j-1);
				res &= checkPos(i-2, j+1);
				res &= checkPos(i-2, j-1);
				res &= checkPos(i+1, j+2);
				res &= checkPos(i+1, j-2);
				res &= checkPos(i-1, j+2);
				res &= checkPos(i-1, j-2);
			}
		}
	printf(res && knights == 9 ? "valid\n" : "invalid\n");
}
