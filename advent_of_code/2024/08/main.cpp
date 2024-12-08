#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

vector<string> grid;
vector<vi> anti;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    string line;
    while (getline(cin, line) && line != "") {
        grid.push_back(line);
    }
    anti.assign(sz(grid), vi(sz(grid[0]), 0));
    rep(i, 0, sz(grid)) rep(j, 0, sz(grid[i])) rep(k, 0, sz(grid)) rep(l, 0, sz(grid[k])) {
        if (i == k && j == l) continue;
        if (grid[i][j] == '.' || grid[i][j] != grid[k][l]) continue;
        ll x = i, y = j;
        while (0 <= x && x < sz(grid) && 0 <= y && y < sz(grid[x])) {
            anti[x][y] = 1;
            x += i-k;
            y += j-l;
        }
    }
    ll res = 0;
    rep(i, 0, sz(anti)) rep(j, 0, sz(anti[i])) res += anti[i][j];
    printf("%lld\n", res);
}
