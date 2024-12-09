#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll n, m;
vector<string> grid;
vi dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    cin >> n >> m;
    grid.resize(n);
    rep(i, 0, n) cin >> grid[i];
    queue<pii> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (grid[x][y] == '.') continue;
        grid[x][y] = '.';
        rep(k, 0, 4) q.emplace(x+dx[k], y+dy[k]);
    }
    rep(i, 0, n) printf("%s\n", grid[i].c_str());
}
