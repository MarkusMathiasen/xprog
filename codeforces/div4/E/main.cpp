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
    rep(t, 0, T) {
        ll n, m, k; cin >> n >> m >> k;
        bool n_bigger = n > m;
        if (abs(n-m) > k || k > max(n,m)) {
            printf("-1\n");
            continue;
        }
        string s = "";
        rep(i, 0, k) {
            s.push_back(n_bigger ? '0' : '1');
            if (n_bigger) n--;
            else m--;
        }
        while (n > 0 || m > 0) {
            if (n > m || (s.back() == '1' && n == m)) {
                s.push_back('0');
                n--;
            } else {
                s.push_back('1');
                m--;
            }
        }
        printf("%s\n", s.c_str());
    }
}