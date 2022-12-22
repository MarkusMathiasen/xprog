#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<string> grid;
int mode = 0;

vi nxt_right(int y, int x) {
    if (x == 149 && 0 <= y && y < 50)
        return {149-y+0, 99, 2};
    else if (x == 99 && 50 <= y && y < 100)
        return {49, 100+y-50, 3};
    else if (x == 99 && 100 <= y && y < 150)
        return {49-y+100, 149, 2};
    else if (x == 49 && 150 <= y && y < 200)
        return {149, 50+y-150, 3};
    else return {y, x+1, 0};
}
vi nxt_left(int y, int x) {
    if (x == 50 && 0 <= y && y < 50)
        return {149-y+0, 0, 0};
    else if (x == 50 && 50 <= y && y < 100)
        return {100, 0+y-50, 1};
    else if (x == 0 && 100 <= y && y < 150)
        return {49-y+100, 50, 0};
    else if (x == 0 && 150 <= y && y < 200)
        return {0, 50+y-150, 1};
    else return {y, x-1, 2};
}
vi nxt_up(int y, int x) {
    if (y == 100 && 0 <= x && x < 50)
        return {50+x-0, 50, 0};
    else if (y == 0 && 50 <= x && x < 100)
        return {150+x-50, 0, 0};
    else if (y == 0 && 100 <= x && x < 150)
        return {199, 0+x-100, 3};
    else return {y-1, x, 3};
}
vi nxt_down(int y, int x) {
    if (y == 199 && 0 <= x && x < 50)
        return {0, 100+x-0, 1};
    else if (y == 149 && 50 <= x && x < 100)
        return {150+x-50, 49, 2};
    else if (y == 49 && 100 <= x && x < 150)
        return {50+x-100, 99, 2};
    else return {y+1, x, 1};
}

vi nxt_right_2(int y, int x) {
    if (x == 11 && 0 <= y && y < 4)
        return {11-y+0, 15, 2};
    else if (x == 11 && 4 <= y && y < 8)
        return {8, 15-y+4, 1};
    else if (x == 15 && 8 <= y && y < 12)
        return {3-y+8, 11, 2};
    else return {y, x+1, 0};
}
vi nxt_left_2(int y, int x) {
    if (x == 8 && 0 <= y && y < 4)
        return {4, 4+y-0, 1};
    else if (x == 0 && 4 <= y && y < 8)
        return {11, 15-y+4, 3};
    else if (x == 8 && 8 <= y && y < 12)
        return {7, 7-y+8, 3};
    else return {y, x-1, 2};
}
vi nxt_up_2(int y, int x) {
    if (y == 4 && 0 <= x && x < 4)
        return {0, 11-x+0, 1};
    else if (y == 4 && 4 <= x && x < 8)
        return {0+x-4, 8, 0};
    else if (y == 0 && 8 <= x && x < 12)
        return {4, 3-x+8, 1};
    else if (y == 8 && 12 <= x && x < 16)
        return {7-x+12, 11, 2};
    else return {y-1, x, 3};
}
vi nxt_down_2(int y, int x) {
    if (y == 7 && 0 <= x && x < 4)
        return {11, 11-x+0, 3};
    else if (y == 7 && 4 <= x && x < 8)
        return {11-x+4, 8, 0};
    else if (y == 11 && 8 <= x && x < 12)
        return {7, 3-x+8, 3};
    else if (y == 11 && 12 <= x && x < 16)
        return {7-x+12, 0, 0};
    else return {y+1, x, 1};
}

vi nxt_step(int y, int x, int dir) {
    if (mode == 0) {
        if (dir == 0) return nxt_right(y, x);
        else if (dir == 1) return nxt_down(y, x);
        else if (dir == 2) return nxt_left(y, x);
        else if (dir == 3) return nxt_up(y, x);
        else assert(false);
    } else {
        if (dir == 0) return nxt_right_2(y, x);
        else if (dir == 1) return nxt_down_2(y, x);
        else if (dir == 2) return nxt_left_2(y, x);
        else if (dir == 3) return nxt_up_2(y, x);
        else assert(false);
    }
}

void print_grid(int y, int x, int dir) {
    string icon; if (dir == 0) icon = ">";
    else if (dir == 1) icon = "v";
    else if (dir == 2) icon = "<";
    else icon = "^";
    rep(i, 0, sz(grid)) {
        rep(j, 0, sz(grid[i])) {
            if (i != y || j != x) printf("%c", grid[i][j]);
            else printf("%s", icon.c_str());
        }
        printf("\n");
    }
    printf("\n\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
    string s;
    while (getline(cin, s), s != "")
        grid.push_back(s);
    int x = 50, y = 0, dir = 0;
    if (mode != 0) x = 8;
    int am; char rot;
    while (cin >> am) {
        //print_grid(y, x, dir);
        rep(i, 0, am) {
            vi nxt = nxt_step(y, x, dir);
            if (grid[nxt[0]][nxt[1]] == '.')
                y = nxt[0], x = nxt[1], dir = nxt[2];
            else {
                assert(grid[nxt[0]][nxt[1]] == '#');
                break;
            }
        }
        if (cin >> rot) {
            if (rot == 'L') dir = (dir+3)%4;
            else if (rot == 'R') dir = (dir+1)%4;
            else assert(false);
        }
    }
    printf("%d\n", 1000*(y+1) + 4*(x+1) + dir);
}
