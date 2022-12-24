#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

vector<vector<int>> grid;
vector<vector<bool>> vis;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	while (cin >> s && s != "") {
		vector<int> row;
		for (char c : s)
			row.push_back(c-'0');
		grid.push_back(row);
	}
	int n = grid.size();
	int m = grid[0].size();
	vector<ll> basinSize;
	vis.assign(n, vector<bool>(m, 0));
	for (int r = 0; r < n; r++)
		for (int c = 0; c < m; c++) {
			ll siz = 0;
			queue<ii> q;
			q.push(ii(r, c));
			while (!q.empty()) {
				auto [x,y] = q.front(); q.pop();
				if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 9 || vis[x][y])
					continue;
				vis[x][y] = true;
				siz++;
				q.push(ii(x-1, y));
				q.push(ii(x+1, y));
				q.push(ii(x, y-1));
				q.push(ii(x, y+1));
			}
			basinSize.push_back(siz);
		}
	sort(basinSize.begin(), basinSize.end());
	ll res = 1;
	for (int i = basinSize.size()-1; i >= (int)basinSize.size()-3; i--)
		res *= basinSize[i];
	printf("%lld\n", res);
}
