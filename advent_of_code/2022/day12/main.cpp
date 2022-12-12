#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> grid;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    string s;
    while (cin >> s) {
        grid.push_back(s);
    }
    pii fin;
    vector<pii> starts;
    rep(i, 0, sz(grid)) rep(j, 0, sz(grid[0]))
        if (grid[i][j] == 'S')
            starts.push_back({i, j}), grid[i][j] = 'a';
        else if (grid[i][j] == 'a')
            starts.push_back({i, j});
        else if (grid[i][j] == 'E')
            fin = {i, j}, grid[i][j] = 'z';
    vector<vi> dist(sz(grid), vi(sz(grid[0]), -1));
    queue<vi> q;
    rep(i, 0, sz(starts))
        q.push({starts[i].first, starts[i].second, 0});
    while (!q.empty()) {
        vi cur = q.front();
        q.pop();
        if (dist[cur[0]][cur[1]] != -1)
            continue;
        dist[cur[0]][cur[1]] = cur[2];
        if (cur[0] > 0 && grid[cur[0]-1][cur[1]] - grid[cur[0]][cur[1]] <= 1)
            q.push({cur[0]-1, cur[1], cur[2]+1});
        if (cur[0] < sz(grid)-1 && grid[cur[0]+1][cur[1]] - grid[cur[0]][cur[1]] <= 1)
            q.push({cur[0]+1, cur[1], cur[2]+1});
        if (cur[1] > 0 && grid[cur[0]][cur[1]-1] - grid[cur[0]][cur[1]] <= 1)
            q.push({cur[0], cur[1]-1, cur[2]+1});
        if (cur[1] < sz(grid[0])-1 && grid[cur[0]][cur[1]+1] - grid[cur[0]][cur[1]] <= 1)
            q.push({cur[0], cur[1]+1, cur[2]+1});
    }
    cout << dist[fin.first][fin.second] << endl;
}
