#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int unvisited = -1000000000;

struct que {
	ii p;
	int d;
	que(ii pos, int dist) {
		p = pos;
		d = dist;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w, h; cin >> w >> h;
	vector<string> grid(h, "");
	ii start = ii(-1, -1); // first = row; second = col
	for (int i = 0; i < h; i++) {
		cin >> grid[i];
		if (grid[i].find("S") != string::npos)
			start = ii(i, grid[i].find("S"));
	}
	string dirs; cin >> dirs;
	vector<vector<int>> dist(h, vector<int>(w, unvisited));
	queue<que> Q;
	Q.push(que(start, 0));
	while (!Q.empty()) {
		int d = Q.front().d;
		int x = Q.front().p.first;
		int y = Q.front().p.second;
		Q.pop();
		if (dist[x][y] != unvisited || grid[x][y] == '#')
			continue;
		dist[x][y] = d;
		Q.push(que(ii(x, y+1), d+1));
		Q.push(que(ii(x, y-1), d+1));
		Q.push(que(ii(x+1, y), d+1));
		Q.push(que(ii(x-1, y), d+1));
	}
	queue<ii> prev;
	queue<ii> nxt;
	nxt.push(start);
	vector<vector<bool>> vis(h, vector<bool>(w, 0));
	for (int i = 0; i < (int)dirs.size(); i++) {
		while (!nxt.empty()) {
			prev.push(nxt.front());
			nxt.pop();
		}
		while (!prev.empty()) {
			int x = prev.front().first;
			int y = prev.front().second;
			prev.pop();
			if (dist[x][y] < i || vis[x][y])
				continue;
			vis[x][y] = true;
			if (dirs[i] != 'N') {
				if (dist[x-1][y] >= i+1)
					nxt.push(ii(x-1, y));
			}
			if (dirs[i] != 'S') {
				if (dist[x+1][y] >= i+1)
					nxt.push(ii(x+1, y));
			}
			if (dirs[i] != 'W') {
				if (dist[x][y-1] >= i+1)
					nxt.push(ii(x, y-1));
			}
			if (dirs[i] != 'E')
				if (dist[x][y+1] >= i+1)
					nxt.push(ii(x, y+1));
		}
	}
	while (!nxt.empty()) {
		int x = nxt.front().first;
		int y = nxt.front().second;
		nxt.pop();
		grid[x][y] = '!';
	}
	for (string& s : grid)
		cout << s << "\n";
}
