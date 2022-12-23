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
        vector<vector<int>> grid(R, vector<int>(C));
        rep(i, 0, R) rep(j, 0, C) cin >> grid[i][j];
        vector<vector<int>> top(R, vector<int>(C, 0));
        vector<vector<int>> left(R, vector<int>(C, 0));
        rep(i, 0, R) rep(j, 0, C) {
            if (!grid[i][j]) continue;
            if (i == 0) top[i][j] = 1;
            else top[i][j] = top[i-1][j] + 1;
            if (j == 0) left[i][j] = 1;
            else left[i][j] = left[i][j-1] + 1;
        }
        vector<vector<int>> bottom(R, vector<int>(C, 0));
        vector<vector<int>> right(R, vector<int>(C, 0));
        for (int i = R-1; i >= 0; i--) for (int j = C-1; j >= 0; j--) {
            if (!grid[i][j]) continue;
            if (i == R-1) bottom[i][j] = 1;
            else bottom[i][j] = bottom[i+1][j] + 1;
            if (j == C-1) right[i][j] = 1;
            else right[i][j] = right[i][j+1] + 1;
        }
        ll res = 0;
        rep(i, 0, R) rep(j, 0, C) {
            res += max(0, min(top[i][j]/2, left[i][j]) + min(top[i][j], left[i][j]/2) - 2);
            res += max(0, min(top[i][j]/2, right[i][j]) + min(top[i][j], right[i][j]/2) - 2);
            res += max(0, min(bottom[i][j]/2, left[i][j]) + min(bottom[i][j], left[i][j]/2) - 2);
            res += max(0, min(bottom[i][j]/2, right[i][j]) + min(bottom[i][j], right[i][j]/2) - 2);
        }
        printf("Case #%d: %lld\n", t, res);
    }
}