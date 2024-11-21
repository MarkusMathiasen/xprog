#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int start;
vi ans, queries = {0, 1, 2, 3, 4, 5, 6, 57, 64, 71, 78, 85, 92, 99};

int query(int steps) {
    printf("? %d %d\n", start, steps);
    fflush(stdout);
    int res; cin >> res;
    return res;
}

void answer(int x) {
    printf("! %d\n", x);
    fflush(stdout);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    cin >> start;
    ans.push_back(start);
    rep(i, 1, sz(queries)) ans.push_back(query(queries[i]));
    rep(i, 1, sz(queries)) {
        rep(j, 0, i) if (ans[j] == ans[i]) {
            int res = query(queries[i]-queries[j]-1);
            answer(res);
            return 0;
        }
    }
    answer(ans.back());
}
