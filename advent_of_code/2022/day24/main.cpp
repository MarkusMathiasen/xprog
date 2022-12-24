#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct state {
    int t, y, x;
    bool operator<(const state& o) const {
        if (t != o.t) return t < o.t;
        if (y != o.y) return y < o.y;
        return x < o.x;
    }
};

int cycle_size, R, C;
vector<vector<int>> grid;
vector<vector<vi>> grids;


void compute_grids() {
    grids.push_back(grid);
    rep(i, 1, cycle_size) {
        vector<vi> new_grid = grids.back();
        rep(i, 1, R-1) {
            rep(j, 1, C-1) {
                new_grid[i][j] = 0;
                new_grid[i][j] += grids.back()[i == 1 ? R-2 : i-1][j] & (1 << 1);
                new_grid[i][j] += grids.back()[i == R-2 ? 1 : i+1][j] & (1 << 3);
                new_grid[i][j] += grids.back()[i][j == 1 ? C-2 : j-1] & (1 << 0);
                new_grid[i][j] += grids.back()[i][j == C-2 ? 1 : j+1] & (1 << 2);
            }
        }
        grids.push_back(new_grid);
    }
}

void print_grid(vector<vi>& grid) {
    rep(i, 0, R) {
        rep(j, 0, C) {
            if (grid[i][j] == 0) printf(".");
            else if (grid[i][j] == 1) printf(">");
            else if (grid[i][j] == 2) printf("v");
            else if (grid[i][j] == 4) printf("<");
            else if (grid[i][j] == 8) printf("^");
            else if (grid[i][j] == 16) printf("#");
            else printf("%d", __builtin_popcount(grid[i][j]));
        }
        printf("\n");
    }
    printf("\n");
}

int calc_time(pii start, pii end, int start_time) {
    map<state, int> dp;
    queue<state> q;
    q.push({start_time, start.first, start.second});
    dp[{start_time, start.first, start.second}] = 0;
    while (!q.empty()) {
        state cur = q.front(); q.pop();
        int t = cur.t, y = cur.y, x = cur.x;

        if (y-1 >= 0 && grids[(t+1)%cycle_size][y-1][x] == 0 && dp[{(t+1)%cycle_size, y-1, x}] == 0) {
            q.push({t + 1, y - 1, x});
            dp[{(t + 1) % cycle_size, y - 1, x}] = t + 1;
        }
        if (y+1 < R && grids[(t+1)%cycle_size][y+1][x] == 0 && dp[{(t+1)%cycle_size, y+1, x}] == 0) {
            q.push({t + 1, y + 1, x});
            dp[{(t + 1) % cycle_size, y + 1, x}] = t + 1;
        }
        if (grids[(t+1)%cycle_size][y][x-1] == 0 && dp[{(t+1)%cycle_size, y, x-1}] == 0) {
            q.push({t + 1, y, x - 1});
            dp[{(t + 1) % cycle_size, y, x - 1}] = t + 1;
        }
        if (grids[(t+1)%cycle_size][y][x+1] == 0 && dp[{(t+1)%cycle_size, y, x+1}] == 0) {
            q.push({t + 1, y, x + 1});
            dp[{(t + 1) % cycle_size, y, x + 1}] = t + 1;
        }
        if (grids[(t+1)%cycle_size][y][x] == 0 && dp[{(t+1)%cycle_size, y, x}] == 0) {
            q.push({t + 1, y, x});
            dp[{(t + 1) % cycle_size, y, x}] = t + 1;
        }
    }
    int res = 1e9;
    for (auto& [s,d] : dp) {
        if (s.y == end.first && s.x == end.second)
            res = min(res, d);
    }
    return res;
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    string s; while (cin >> s) {
        grid.push_back(vector<int>());
        for (char c : s) {
            if (c == '.') grid.back().push_back(0);
            else if (c == '>') grid.back().push_back(1 << 0);
            else if (c == 'v') grid.back().push_back(1 << 1);
            else if (c == '<') grid.back().push_back(1 << 2);
            else if (c == '^') grid.back().push_back(1 << 3);
            else if (c == '#') grid.back().push_back(1 << 4);
            else assert(false);
        }
    }
    R = sz(grid), C = sz(grid[0]);
    cycle_size = (R-2)*(C-2)/gcd(R-2, C-2);
    compute_grids();
    int res = calc_time({0, 1}, {R-1, C-2}, 0);
    res = calc_time({R-1, C-2}, {0, 1}, res);
    res = calc_time({0, 1}, {R-1, C-2}, res);
    printf("%d\n", res);
}
