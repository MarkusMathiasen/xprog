#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> cave;
vector<vector<bool>> vis;

bool dfs(int x, int y, int h) {
	if (vis[x][y]) return false;
	vis[x][y] = true;
	if (x == N-1 && y == N-1) return true;
	if (x != 0 && cave[x-1][y] <= h && dfs(x-1, y, h))
		return true;
	if (x != N-1 && cave[x+1][y] <= h && dfs(x+1, y, h))
		return true;
	if (y != 0 && cave[x][y-1] <= h && dfs(x, y-1, h))
		return true;
	if (y != N-1 && cave[x][y+1] <= h && dfs(x, y+1, h))
		return true;
	return false;
}

int main() {
	cin >> N;
	cave.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> cave[i][j];

	int lower = 0;
	int upper = (int)1e8;
	while (lower < upper) {
		int middle = (upper+lower)/2;
		vis.assign(N, vector<bool>(N, false));
		if (dfs(0, 0, middle))
			upper = middle;
		else
			lower = middle+1;
	}
	cout << lower << endl;
}
