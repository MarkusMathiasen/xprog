#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<vector<vector<int>>> boards;
set<int> chosen;

bool won(vector<vector<int>>& board) {
	for (vector<int>& row : board) {
		bool res = true;
		for (int x : row)
			res &= chosen.count(x);
		if (res)
			return res;
	}
	for (int col = 0; col < 5; col++) {
		bool res = true;
		for (int row = 0; row < 5; row++)
			res &= chosen.count(board[row][col]);
		if (res)
			return res;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s; cin >> s;
	stringstream ss(s);
	while (getline(ss, s, ','))
		nums.push_back(stoi(s));
	for (int i = 0; i < 100; i++) {
		vector<vector<int>> board(5, vector<int>(5, 0));
		for (int row = 0; row < 5; row++)
			for (int col = 0; col < 5; col++)
				cin >> board[row][col];
		boards.push_back(board);
	}
	vector<vector<int>> winner;
	int winnerNum = -1;
	int winnerCount = 0;
	vector<bool> hasWon(100, false);
	for (int x : nums) {
		winnerNum = x;
		chosen.insert(x);
		for (int i = 0; i < 100; i++) {
			vector<vector<int>>& board = boards[i];
			if (!hasWon[i] && won(board)) {
				winner = board;
				hasWon[i] = true;
				winnerCount++;
			}
		}
		if (winnerCount == 100)
			break;
	}
	int res = 0;
	for (auto row : winner)
		for (auto x : row)
			if (!chosen.count(x))
				res += x;
	printf("%d\n", res*winnerNum);
}
