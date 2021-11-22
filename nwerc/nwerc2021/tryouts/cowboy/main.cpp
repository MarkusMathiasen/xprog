#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

vector<string> board;

ii left(int row, int col) {
	int resCol = -1;
	for (int c = col-1; c >= 0; c--) {
		if (board[row][c] == '|')
			break;
		if (board[row][c] == '-')
			continue;
		resCol = c;
		break;
	}
	if (resCol == -1)
		return ii(-1, -1);
	else
		return ii(row, resCol);
}
ii right(int row, int col) {
	int resCol = -1;
	for (int c = col+1; c < 7; c++) {
		if (board[row][c] == '|')
			break;
		if (board[row][c] == '-')
			continue;
		resCol = c;
		break;
	}
	if (resCol == -1)
		return ii(-1, -1);
	else
		return ii(row, resCol);
}
ii up(int row, int col) {
	int resRow = -1;
	for (int r = row-1; r >= 0; r--) {
		if (board[r][col] == '-')
			break;
		if (board[r][col] == '|')
			continue;
		resRow = r;
		break;
	}
	if (resRow == -1)
		return ii(-1, -1);
	else
		return ii(resRow, col);
}
ii down(int row, int col) {
	int resRow = -1;
	for (int r = row+1; r < 7; r++) {
		if (board[r][col] == '-')
			break;
		if (board[r][col] == '|')
			continue;
		resRow = r;
		break;
	}
	if (resRow == -1)
		return ii(-1, -1);
	else
		return ii(resRow, col);
}

bool isLine(int row, int col) {
	if (board[row][col] != 'W')
		return false;
	ii l = left(row, col), r = right(row, col), u = up(row, col), d = down(row, col);
	bool hasLeft = l != ii(-1, -1) && board[l.first][l.second] == 'W';
	bool hasRight = r != ii(-1, -1) && board[r.first][r.second] == 'W';
	bool hasUp = u != ii(-1, -1) && board[u.first][u.second] == 'W';
	bool hasDown = d != ii(-1, -1) && board[d.first][d.second] == 'W';
	if (hasLeft && hasRight)
		return true;
	if (hasUp && hasDown)
		return true;
	if (hasLeft) {
		ii ll = left(l.first, l.second);
		if (ll != ii(-1, -1) && board[ll.first][ll.second] == 'W')
			return true;
	}
	if (hasRight) {
		ii ll = right(r.first, r.second);
		if (ll != ii(-1, -1) && board[ll.first][ll.second] == 'W')
			return true;
	}
	if (hasUp) {
		ii ll = up(u.first, u.second);
		if (ll != ii(-1, -1) && board[ll.first][ll.second] == 'W')
			return true;
	}
	if (hasDown) {
		ii ll = down(d.first, d.second);
		if (ll != ii(-1, -1) && board[ll.first][ll.second] == 'W')
			return true;
	}
	return false;
}

bool checkPos(ii newPos, int row, int col) {
	if (newPos == ii(-1, -1))
		return false;
	if (board[newPos.first][newPos.second] != '.')
		return false;
	board[row][col] = '.';
	board[newPos.first][newPos.second] = 'W';
	bool res = isLine(newPos.first, newPos.second);
	board[row][col] = 'W';
	board[newPos.first][newPos.second] = '.';
	return res;
}

int main() {
	board.assign(7, "");
	for (int i = 0; i < 7; i++)
		getline(cin, board[i]);
	bool found = false;
	for (int row = 0; row < 7; row++)
		for (int col = 0; col < 7; col++) {
			if (isLine(row, col)) {
				ii newPos = left(row, col);
				found |= checkPos(newPos, row, col);

				newPos = right(row, col);
				found |= checkPos(newPos, row, col);

				newPos = up(row, col);
				found |= checkPos(newPos, row, col);

				newPos = down(row, col);
				found |= checkPos(newPos, row, col);
			}
		}
	printf(found ? "double mill\n" : "no double mill\n");
}
