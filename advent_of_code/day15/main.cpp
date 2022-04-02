#include <bits/stdc++.h>
using namespace std;

struct que {
	int x;
	int y;
	int d;
	const bool operator>(const que& a) const {
		return d > a.d;
	}
	que(int x, int y, int d) : x(x), y(y), d(d) {}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<vector<int>> grid;
	string s;
	int w;
	while (cin >> s) {
		w = s.size();
		grid.push_back(vector<int>());
		assert(s != "" && s != "\n");
		for (char c : s)
			grid.back().push_back(c-'0');
		for (int k = 0; k < 4; k++) 
			for (int i = 0; i < w; i++) {
				grid.back().push_back(grid.back()[w*k+i]+1);
				if (grid.back().back() == 10)
					grid.back().back() = 1;
			}
	}
	int h = grid.size();
	w = grid[0].size();
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < h; j++) {
			grid.push_back(grid[h*i+j]);
			for (int& x : grid.back()) {
				x++;
				if (x == 10)
					x = 1;
			}
		}
	h = grid.size();
	vector<vector<int>> dist(h, vector<int>(w, -1));
	priority_queue<que, vector<que>, greater<que>> pq;
	pq.push(que(0, 0, 0));
	vector<int> dx = {0, 0, -1, 1};
	vector<int> dy = {-1, 1, 0, 0};
	while (!pq.empty()) {
		que v = pq.top(); pq.pop();
		int x = v.x;
		int y = v.y;
		int d = v.d;
		if (dist[x][y] != -1)
			continue;
		dist[x][y] = d;
		for (int i = 0; i < 4; i++)
			if (x+dx[i] >= 0 && x+dx[i] < h && y+dy[i] >= 0 && y+dy[i] < w)
				pq.push(que(x+dx[i], y+dy[i], d+grid[x+dx[i]][y+dy[i]]));
	}
	printf("%d\n", dist[h-1][w-1]);
}
