#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int T; cin >> T;
    rep(t, 1, T+1) {
        int R, C; cin >> R >> C;
        vector<vector<int>> grid(R, vector<int>(C, 0));
        priority_queue<vi> pq;
        ll res = 0;
        rep(i, 0, R) rep(j, 0, C) {
            int x; cin >> x;
            pq.push({x, i, j});
            res -= x;
        }
        while (!pq.empty()) {
            int x = pq.top()[0], i = pq.top()[1], j = pq.top()[2]; pq.pop();
            if (i < 0 || i >= R || j < 0 || j >= C || grid[i][j] >= x) continue;
            res += x - grid[i][j];
            grid[i][j] = x;
            pq.push({x-1, i-1, j});
            pq.push({x-1, i+1, j});
            pq.push({x-1, i, j-1});
            pq.push({x-1, i, j+1});
        }
        printf("Case #%d: %lld\n", t, res);
    }
}