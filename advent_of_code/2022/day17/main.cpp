#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<int> vi;

vector<string> grid;
string shift;
int shift_idx = 0;
vector<vector<string>> rocks = {
        {
                "####"
        },{
                ".#.",
                "###",
                ".#."
        },{
                "..#",
                "..#",
                "###"
        },{
                "#",
                "#",
                "#",
                "#"
        },{
                "##",
                "##"
        }
};

void shift_left(int x, int& y, int w, int h) {
    if (y <= 0) return;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[x+i][y+j-1] == '#' && grid[x+i][y+j] == '@') {
                return;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[x+i][y+j] == '@') {
                swap(grid[x+i][y+j], grid[x+i][y+j-1]);
            }
        }
    }
    y--;
}

void shift_right(int x, int& y, int w, int h) {
    if (y+w >= 7) return;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[x+i][y+j+1] == '#' && grid[x+i][y+j] == '@') {
                return;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = w-1; j >= 0; j--) {
            if (grid[x+i][y+j] == '@') {
                swap(grid[x+i][y+j], grid[x+i][y+j+1]);
            }
        }
    }
    y++;
}

bool shift_down(int& x, int y, int w, int h) {
    if (x <= 0) return false;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[x+i-1][y+j] == '#' && grid[x+i][y+j] == '@') {
                return false;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[x+i][y+j] == '@') {
                swap(grid[x+i][y+j], grid[x+i-1][y+j]);
            }
        }
    }
    x--;
    return true;
}

void drop_rock(int r) {
    vector<string>& rock = rocks[r];
    int w = sz(rock[0]);
    int h = sz(rock);
    rep(i, 0, 3+h) grid.push_back(".......");
    int x = sz(grid)-h, y = 2;
    rep(i, 0, h) rep(j, 0, w)
        if (rock[h-1-i][j] == '#')
            grid[x+i][y+j] = '@';
    while (true) {
        if (shift[shift_idx] == '>') {
            shift_right(x, y, w, h);
        } else if (shift[shift_idx] == '<') {
            shift_left(x, y, w, h);
        }
        shift_idx = (shift_idx+1)%sz(shift);
        if (!shift_down(x, y, w, h)) break;
    }
    rep(i, 0, h) rep(j, 0, w)
        if (grid[x+i][y+j] == '@')
            grid[x+i][y+j] = '#';
    while (grid.back() == ".......")
        grid.pop_back();
}

void print_grid() {
    for (int i = sz(grid)-1; i >= 0; i--) {
        cout << grid[i] << endl;
    }
    cout << endl;
}

void comp_state(vector<string>& state) {
    rep(y, 0, min(100, sz(grid))) {
        state.push_back(grid[sz(grid)-1-y]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    cin >> shift;
    map<vector<string>, ll> rock_count;
    vector<ll> heights;
    ll height_diff;
    ll rocks_init;
    ll rock_diff;
    rep(rock, 0, 1000000000) {
        vector<string> state; comp_state(state);
        if (rock_count.count(state)) {
            height_diff = sz(grid) - heights[rock_count[state]];
            rocks_init = rock_count[state];
            rock_diff = rock - rocks_init;
            break;
        }
        rock_count[state] = rock;
        heights.push_back(sz(grid));
        drop_rock(rock % 5);
    }
    ll height_init = heights[rocks_init];
    ll large = ((1000000000000ll - rocks_init) / rock_diff)*height_diff;
    ll small = heights[rocks_init + ((1000000000000ll - rocks_init) % rock_diff)];
    printf("%lld\n", large + small);
}