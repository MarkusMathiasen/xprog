#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

bool bug = false;
char board[8][8];
int a = 7, b = 0;
int dir = 0;
char c;

ii newCoord() {
	ii res;
	if (dir == 0)
		res = ii(a, b+1);
	if (dir == 1)
		res = ii(a+1, b);
	if (dir == 2)
		res = ii(a, b-1);
	if (dir == 3)
		res = ii(a-1, b);
	if (res.first < 0 || res.first > 7 || res.second < 0 || res.second > 7)
		return ii(-1, -1);
	return res;
}

int main() {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			scanf(" %c", &board[i][j]);
	board[a][b] = '.';
	while (scanf(" %c", &c) != EOF) {
		if (c == 'F') {
			int na = newCoord().first;
			int nb = newCoord().second;
			if (na == -1 || (board[na][nb] != '.' && board[na][nb] != 'D')) {
				bug = true;
				break;
			}
			a = na, b = nb;
		}
		if (c == 'R')
			dir = (dir+1)%4;
		if (c == 'L')
			dir = dir == 0 ? 3 : dir-1;
		if (c == 'X') {
			int na = newCoord().first;
			int nb = newCoord().second;
			if (na == -1 || board[na][nb] != 'I') {
				bug = true;
				break;
			}
			board[na][nb] = '.';
		}
	}
	printf(bug || board[a][b] != 'D' ? "Bug!\n" : "Diamond!\n");
}
