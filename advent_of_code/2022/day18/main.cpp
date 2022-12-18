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
    set<vi> sides;
    set<vi> cubes;
    int max_c = 0;
    int x,y,z; while (scanf("%d,%d,%d", &x, &y, &z) != EOF) {
        cubes.insert({x,y,z});
        max_c = max(max_c, max(x, max(y, z)));
        rep(i, 0, 3)
            if (!sides.count({x, y, z, i}))
                sides.insert({x, y, z, i});
            else
                sides.erase({x, y, z, i});
        rep(i, 0, 3)
            if (!sides.count({x - (i == 0), y - (i == 1), z - (i == 2), i}))
                sides.insert({x - (i == 0), y - (i == 1), z - (i == 2), i});
            else
                sides.erase({x - (i == 0), y - (i == 1), z - (i == 2), i});
    }
    queue<vi> q;
    vector<vector<vi>> vis(max_c+2, vector<vi>(max_c+2, vi(max_c+2, 0)));
    q.push({0,0,0});
    for (vi cube : cubes) {
        vis[cube[0]][cube[1]][cube[2]] = 1;
    }
    while (!q.empty()) {
        vi cur = q.front(); q.pop();
        int x = cur[0], y = cur[1], z = cur[2];
        if (x < 0 || x > max_c+1 || y < 0 || y > max_c+1 || z < 0 || z > max_c+1) continue;
        if (vis[x][y][z]) continue;
        vis[x][y][z] = 1;
        vi dx = {-1, 1, 0, 0, 0, 0};
        vi dy = {0, 0, -1, 1, 0, 0};
        vi dz = {0, 0, 0, 0, -1, 1};
        rep(i, 0, 6) {
            q.push({x+dx[i], y+dy[i], z+dz[i]});
        }
    }
    rep(x, 0, max_c+2) {
        rep(y, 0, max_c+2) {
            rep(z, 0, max_c+2) {
                if (!vis[x][y][z]) {
                    rep(i, 0, 3)
                        sides.erase({x, y, z, i});
                    rep(i, 0, 3)
                        sides.erase({x - (i == 0), y - (i == 1), z - (i == 2), i});
                }
            }
        }
    }
    printf("%ld\n", sides.size());

}
