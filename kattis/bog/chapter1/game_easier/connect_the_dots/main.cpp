#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

vector<string> grid;
string s;

void vert(char& c) {
	if (c == '.')
		c = '|';
	if (c == '-')
		c = '+';
}
void hor(char& c) {
	if (c == '.')
		c = '-';
	if (c == '|')
		c = '+';
}


void dfs(int x, int y) {
	if (x < 0 || y < 0)
		return;
	char c = grid[x][y];
	char nxt = c+1;
	if (c == '9')
		nxt = 'a';
	if (c == 'z')
		nxt = 'A';
	for (int i = x+1; i < (int)grid.size(); i++)
		if (grid[i][y] == nxt) {
			for (int j = x+1; j < i; j++)
				vert(grid[j][y]);
			dfs(i, y);
		}
	for (int i = x-1; i >= 0; i--)
		if (grid[i][y] == nxt) {
			for (int j = x-1; j > i; j--)
				vert(grid[j][y]);
			dfs(i, y);
		}
	for (int i = y+1; i < (int)grid[x].size(); i++)
		if (grid[x][i] == nxt) {
			for (int j = y+1; j < i; j++)
				hor(grid[x][j]);
			dfs(x, i);
		}
	for (int i = y-1; i >= 0; i--)
		if (grid[x][i] == nxt) {
			for (int j = y-1; j > i; j--)
				hor(grid[x][j]);
			dfs(x, i);
		}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (getline(cin, s)) {
		grid.assign(0, "");
		while (s != "") {
			grid.push_back(s);
			getline(cin, s);
		}
		ii start(-1, -1);
		for (int i = 0; i < (int)grid.size(); i++)
			if (grid[i].find('0') != string::npos)
				start = {i, grid[i].find('0')};
		dfs(start.first, start.second);
		for (string s : grid) {
			for (char c : s)
				printf("%c", c);
			printf("\n");
		}
		printf("\n");
	}
}
