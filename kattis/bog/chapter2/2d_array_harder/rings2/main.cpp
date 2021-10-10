#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	grid.assign(n, "");
	for (int i = 0; i < n; i++)
		cin >> grid[i];
	int nums[n][m];
	bool vis[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			nums[i][j] = 1000, vis[i][j] = false;
	queue<tuple<int, int, int>> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] == '.')
				q.push(tuple<int, int, int>(i, j, 0));
	for (int i = 0; i < n; i++) {
		q.push(tuple<int, int, int>(i, 0, 1));
		q.push(tuple<int, int, int>(i, m-1, 1));
	}
	for (int i = 0; i < m; i++) {
		q.push(tuple<int, int, int>(0, i, 1));
		q.push(tuple<int, int, int>(n-1, i, 1));
	}
	int maxnum = 0;
	while (!q.empty()) {
		auto [x,y,d] = q.front();
		q.pop();
		if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y])
			continue;
		vis[x][y] = true;
		nums[x][y] = d;
		maxnum = max(maxnum, d);
		q.push(tuple<int, int, int>(x+1, y, d+1));
		q.push(tuple<int, int, int>(x-1, y, d+1));
		q.push(tuple<int, int, int>(x, y+1, d+1));
		q.push(tuple<int, int, int>(x, y-1, d+1));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << setfill('.') << setw(maxnum >= 10 ? 3 : 2);
			if (nums[i][j] == 0)
				cout << ".";
			else
				cout << nums[i][j];
		}
		cout << endl;
	}
}
