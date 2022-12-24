#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

set<pii> elves;

int print_elves() {
    int left = 1000000, right = -1, top = 1000000, bottom = -1;
    for (auto p : elves) {
        left = min(left, p.second);
        right = max(right, p.second);
        top = min(top, p.first);
        bottom = max(bottom, p.first);
    }
    vector<string> grid(bottom-top+1, string(right-left+1, '.'));
    for (auto p : elves) {
        grid[p.first-top][p.second-left] = '#';
    }
    /*for (auto s : grid) {
        printf("%s\n", s.c_str());
    }
    printf("\n");*/
    return (bottom-top+1)*(right-left+1) - (int)elves.size();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    int y = 0;
    string s; while (cin >> s) {
        rep(x, 0, sz(s))
            if (s[x] == '#')
                elves.insert({y, x});
        y++;
    }
    int dir = 0; // 0: up, 1: down, 2: left, 3: right
    int round = 0;
    while (++round) {
        map<pii, pii> move;
        multiset<pii> move_cnt;
        for (pii elve : elves) {
            int x = elve.second, y = elve.first;
            vector<int> dx = {-1, 0, 1, -1, 1, -1, 0, 1};
            vector<int> dy = {-1, -1, -1, 0, 0, 1, 1, 1};
            bool other = false;
            rep(i, 0, 8)
                other |= elves.count({y+dy[i], x+dx[i]});
            if (other) {
                vector<vector<int>> dx = {{-1, 0, 1}, {-1, 0, 1}, {-1, -1, -1}, {1, 1, 1}};
                vector<vector<int>> dy = {{-1, -1, -1}, {1, 1, 1}, {-1, 0, 1}, {-1, 0, 1}};
                rep(d, 0, 4) {
                    int di = (dir+d)%4;
                    bool empty = true;
                    rep(j, 0, 3)
                        empty &= !elves.count({y+dy[di][j], x+dx[di][j]});
                    if (empty) {
                        move_cnt.insert({y+dy[di][1], x+dx[di][1]});
                        move[elve] = {y+dy[di][1], x+dx[di][1]};
                        break;
                    }
                }
            }
        }
        bool moved = false;
        for (auto [from, to] : move) {
            if (move_cnt.count(to) < 2) {
                elves.erase(from);
                elves.insert(to);
                moved = true;
            }
        }
        if (!moved) break;
        dir = (dir+1)%4;
    }
    printf("%d\n", round);
}
