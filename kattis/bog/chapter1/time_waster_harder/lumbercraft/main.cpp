#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

struct player {
	char name;
	int x;
	int y;
	player(char name, int x, int y) {
		this->name = name;
		this->x = x;
		this->y = y;
	}
	int tx = -1;
	int ty = -1;
	double p = 0;
};

int n, h, w;
vector<vector<char>> board;

int dist(int x1, int y1, int x2, int y2) {
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void comp(player& p, int col, int row) {
	int d1 = dist(p.x, p.y, p.tx, p.ty);
	int d2 = dist(p.x, p.y, col, row);
	if (d1 > d2 || (d1 == d2 && (col > p.tx || (col == p.tx && row < p.ty))))
		p.tx = col, p.ty = row;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (scanf("%d%d%d", &n, &h, &w), n && h && w) {
		board.assign(h, vector<char>(w, ' '));
		vector<player> players;
		for (int i = h-1; i >= 0; i--)
			for (int j = 0; j < w; j++) {
				scanf(" %c", &board[i][j]);
				if (isalpha(board[i][j]))
					players.push_back(player(board[i][j], j, i));
			}
		sort(players.begin(), players.end(), [](player a, player b) {return a.name <= b.name;});
		vector<vector<int>> chop(h, vector<int>(w, 0));
		for (int turn = 0; turn < n; turn++) {
			bool found = true;
			for (player& p : players) {
				p.tx = p.ty = 1000;
				for (int row = 0; row < h; row++)
					for (int col = 0; col < w; col++)
						if (board[row][col] == '!')
							comp(p, col, row);
				found &= p.tx != 1000 && p.ty != 1000;
			}
			if (!found)
				break;
			for (player& p : players)
				chop[p.ty][p.tx]++;
			for (player& p : players)
				p.p += 1.0 / chop[p.ty][p.tx];
			for (player& p : players)
				chop[p.ty][p.tx] = 0, board[p.ty][p.tx] = '.';
		}
		for (int i = h-1; i >= 0; i--) {
			for (int j = 0; j < w; j++)
				printf("%c", board[i][j]);
			printf("\n");
		}
		for (player& p : players)
			printf("%c %lf\n", p.name, p.p);

	}
}
