#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>

int X, Y;
int board[8][8];
int moves[8][8];

bool isValid(ii& cord){
	int x = cord.first; int y = cord.second;
	if (x < 0 || x > 7 || y < 0 || y > 7) return false;
	if (board[x][y]) return false;
	return true;
}

vector<iii> genMoves(ii cord){
	int x = cord.first; int y = cord.second;
	vector<iii> result;
	ii ncord;
	ncord = ii(x+2, y+1); if (isValid(ncord)) result.push_back(iii(moves[ncord.first][ncord.second], ncord));
	ncord = ii(x+2, y-1); if (isValid(ncord)) result.push_back(iii(moves[ncord.first][ncord.second], ncord));
	ncord = ii(x-2, y+1); if (isValid(ncord)) result.push_back(iii(moves[ncord.first][ncord.second], ncord));
	ncord = ii(x-2, y-1); if (isValid(ncord)) result.push_back(iii(moves[ncord.first][ncord.second], ncord));
	ncord = ii(x+1, y+2); if (isValid(ncord)) result.push_back(iii(moves[ncord.first][ncord.second], ncord));
	ncord = ii(x+1, y-2); if (isValid(ncord)) result.push_back(iii(moves[ncord.first][ncord.second], ncord));
	ncord = ii(x-1, y+2); if (isValid(ncord)) result.push_back(iii(moves[ncord.first][ncord.second], ncord));
	ncord = ii(x-1, y-2); if (isValid(ncord)) result.push_back(iii(moves[ncord.first][ncord.second], ncord));
	return result;
}

void printMoves(){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++)
			printf("%2d ", board[i][j]);
		printf("\n");
	}
}

bool hp(ii cord, int c){
	int x = cord.first; int y = cord.second;
	board[x][y] = c;
	if (c == 64) return true;
	vector<iii> ops = genMoves(cord);
	sort(ops.begin(), ops.end());
	for (int i = 0; i < (int)ops.size(); i++)
		moves[ops[i].second.first][ops[i].second.second]--;
	for (int i = 0; i < (int)ops.size(); i++)
		if (hp(ops[i].second, c+1)) return true;
	for (int i = 0; i < (int)ops.size(); i++)
		moves[ops[i].second.first][ops[i].second.second]++;
	board[x][y] = 0;
	return false;
}

int main(){
	scanf("%d %d", &X, &Y); X--; Y--;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++){
			vector<iii> ava = genMoves(ii(i, j));
			moves[i][j] = ava.size();
		}
	hp(ii(Y, X), 1);
	printMoves();
}
