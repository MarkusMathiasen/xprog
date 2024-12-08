#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

vector<string> grid;
ll x, y, dir=0;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

bool has_cycle(ll x, ll y) {
    vector<vector<vi>> vis(sz(grid), vector<vi>(sz(grid[0]), vi(4, 0)));
    dir = 0;
    while (!vis[x][y][dir]) {
        vis[x][y][dir] = 1;
        ll nx = x + dx[dir], ny = y + dy[dir];
        if (nx < 0 || nx >= sz(grid) || ny < 0 || ny >= sz(grid[0])) {
            return false;
        } else if (grid[nx][ny] == '#') {
            dir = (dir + 1) % 4;
        } else {
            x = nx;
            y = ny;
        }
    }
    return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    string s;
    while (getline(cin, s) && s != "") {
        grid.push_back(s);
    }
    rep(i, 0, sz(grid)) rep(j, 0, sz(grid[0])) {
        if (grid[i][j] == '^') {
            x = i;
            y = j;
        }
    }
    ll res = 0;
    rep(i, 0, sz(grid)) rep(j, 0, sz(grid[0])) {
        if (grid[i][j] != '.') continue;
        grid[i][j] = '#';
        res += has_cycle(x, y);
        grid[i][j] = '.';
    }
    printf("%lld\n", res);
}
