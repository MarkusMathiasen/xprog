#include <bits/stdc++.h>
using namespace std;

bool board[5000][5000];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = false;
	bool correct = true;
	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		correct &= !board[x][y];
		for (int j = 0; j < n; j++)
			board[j][y] = board[x][j] = true;
		for (int i = 1; i <= min(x, y); i++)
			board[x-i][y-i] = true;
		for (int i = 1; x+i < n && y+i < n; i++)
			board[x+i][y+i] = true;
		for (int i = 1; x+i < n && i <= y; i++)
			board[x+i][y-i] = true;
		for (int i = 1; i <= x && y+i < n; i++)
			board[x-i][y+i] = true;
	}
	printf(correct ? "CORRECT\n" : "INCORRECT\n");
}
