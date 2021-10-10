#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> vis;
int neg = -2000000000;

int dfs(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		printf("Out\n");
		return neg;
	}
	if (vis[x][y]) {
		printf("Lost\n");
		return neg;
	}
	vis[x][y] = true;
	if (grid[x][y] == 'E')
		return dfs(x, y+1)+1;
	if (grid[x][y] == 'W')
		return dfs(x, y-1)+1;
	if (grid[x][y] == 'N')
		return dfs(x-1, y)+1;
	if (grid[x][y] == 'S')
		return dfs(x+1, y)+1;
	if (grid[x][y] == 'T')
		return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	grid.assign(n, "");
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	vis.assign(n, vector<bool>(m, false));
	int res = dfs(0, 0);
	if (res >= 0)
		cout << res << endl;
}
