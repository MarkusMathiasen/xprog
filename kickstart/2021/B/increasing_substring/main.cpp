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
        int N; cin >> N;
        string s; cin >> s;
        vi res(N, 1);
        rep(i, 1, N)
            if (s[i] > s[i-1])
                res[i] += res[i-1];
        printf("Case #%d:", t);
        for (int x : res)
            printf(" %d", x);
        printf("\n");
    }
}