#include <bits/stdc++.h>
using namespace std;

int t;
int r, c, n;
vector<string> grid;

bool defeated(char a, char b) {
	if (a == 'R')
		return b == 'P';
	if (a == 'P')
		return b == 'S';
	return b == 'R';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> r >> c >> n;
		grid.assign(r, "");
		for (int i = 0; i < r; i++)
			cin >> grid[i];
		while (n--) {
			vector<string> ngrid = grid;
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++) {
					if (i > 0 && defeated(grid[i][j], grid[i-1][j]))
						ngrid[i][j] = grid[i-1][j];
					else if (i < r-1 && defeated(grid[i][j], grid[i+1][j]))
						ngrid[i][j] = grid[i+1][j];
					else if (j > 0 && defeated(grid[i][j], grid[i][j-1]))
						ngrid[i][j] = grid[i][j-1];
					else if (j < c-1 && defeated(grid[i][j], grid[i][j+1]))
						ngrid[i][j] = grid[i][j+1];
				}
			grid = ngrid;
		}
		for (int i = 0; i < r; i++)
			cout << grid[i] << "\n";
		cout << "\n";
	}
}
