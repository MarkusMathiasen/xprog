#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<pii, char> grid;
int max_y = 0, max_x, min_y, min_x;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        int x, y, prev_x, prev_y;
        string s; ss >> s;
        sscanf(s.c_str(), "%d,%d", &prev_x, &prev_y);
        max_y = max(max_y, prev_y);
        while (ss >> s >> s) {
            sscanf(s.c_str(), "%d,%d", &x, &y);
            while (prev_x != x || prev_y != y) {
                grid[{prev_x, prev_y}] = '#';
                if (prev_x < x) {
                    prev_x++;
                } else if (prev_x > x) {
                    prev_x--;
                } else if (prev_y < y) {
                    prev_y++;
                } else if (prev_y > y) {
                    prev_y--;
                }
                max_y = max(max_y, prev_y);
            }
            grid[{x, y}] = '#';
        }
    }
    max_y++;
    int res = 0;
    while (grid[{500, 0}] != '#') {
        pii sand = {500, 0};
        while (true) {
            if (sand.second == max_y) {
                grid[sand] = '#';
                res++;
                break;
            }
            else if (grid[{sand.first, sand.second + 1}] != '#') {
                sand.second++;
            } else if (grid[{sand.first - 1, sand.second+1}] != '#') {
                sand.first--; sand.second++;
            } else if (grid[{sand.first + 1, sand.second+1}] != '#') {
                sand.first++; sand.second++;
            } else {
                grid[sand] = '#';
                res++;
                break;
            }
        }
    }
    printf("%d\n", res);
}