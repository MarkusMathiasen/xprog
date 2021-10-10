#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>
#define iii pair<ii, int>

vector<vector<int>> grid;
ii start;
int ans = -1;

int main() {
	int N; scanf("%d", &N);
	grid.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			char c; scanf(" %c", &c);
			if (c == 'K')
				start.first = i, start.second = j;
			if (c == '#')
				grid[i][j] = 1;
		}
	queue<iii> Q;
	Q.push(iii(start, 0));
	while (!Q.empty()) {
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int l = Q.front().second;
		Q.pop();
		if (x >= N || y >= N || x < 0 || y < 0) continue;
		if (grid[x][y]) continue;
		grid[x][y] = 1;
		if (x == 0 && y == 0) {
			ans = l; break;
		}
		Q.push(iii(ii(x + 2, y +1), l+1));
		Q.push(iii(ii(x + 2, y -1), l+1));
		Q.push(iii(ii(x - 2, y +1), l+1));
		Q.push(iii(ii(x - 2, y -1), l+1));
		Q.push(iii(ii(x + 1, y +2), l+1));
		Q.push(iii(ii(x + 1, y -2), l+1));
		Q.push(iii(ii(x - 1, y +2), l+1));
		Q.push(iii(ii(x - 1, y -2), l+1));
	}
	printf("%d\n", ans);
}
