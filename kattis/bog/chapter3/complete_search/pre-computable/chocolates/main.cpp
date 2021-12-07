#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int R, C;
vector<vector<bool>> board;
vector<vector<bool>> vis;

bool valid() {
	bool circle = true;
	for (int r = 1; r < R-1; r++)
		for (int c = 1; c < C-1; c++)
			circle &= board[r][c];
	for (int r = 1; r < R-1; r++)
		for (int c = 1; c < C-1; c++)
			if (!board[r][c]) {
				if (r == 1)
					circle |= !(board[0][c-1] && board[0][c] && board[0][c+1]);
				if (r == R-2)
					circle |= !(board[R-1][c-1] && board[R-1][c] && board[R-1][c+1]);
				if (c == 1)
					circle |= !(board[r-1][0] && board[r][0] && board[r+1][0]);
				if (c == C-2)
					circle |= !(board[r-1][C-1] && board[r][C-1] && board[r+1][C-1]);
			}
	queue<ii> q;
	vis.assign(R, vector<bool>(C, 0));
	for (int r = 0; r < R && q.empty(); r++)
		for (int c = 0; c < C && q.empty(); c++)
			if (board[r][c])
				q.push(ii(r, c));
	while (!q.empty()) {
		auto [r,c] = q.front(); q.pop();
		if (r < 0 || r >= R || c < 0 || c >= C)
			continue;
		if (vis[r][c] || !board[r][c])
			continue;
		vis[r][c] = true;
		q.push(ii(r-1, c));
		q.push(ii(r+1, c));
		q.push(ii(r, c-1));
		q.push(ii(r, c+1));
	}
	bool onePiece = true;
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			onePiece &= !board[r][c] || vis[r][c];
	return onePiece && circle;
}

void makeBoard(int conf) {
	for (int i = 0; i < R*C; i++)
		board[i/C][i%C] = conf & (1<<i);
}

int main() {
	scanf("%d%d", &R, &C);
	board.assign(R, vector<bool>(C, 0));
	int res = 0;
	for (int i = 1; i < (1<<R*C); i++) {
		makeBoard(i);
		res += valid();
	}
	printf("%d\n", res);
}
