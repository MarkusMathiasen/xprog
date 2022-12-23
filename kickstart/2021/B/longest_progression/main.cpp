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
        vi A(N);
        rep(i, 0, N) cin >> A[i];
        vi pre(N, 2), suf(N, 2);
        pre[0] = 1; suf[N-1] = 1;
        rep(i, 2, N)
            if (A[i] - A[i-1] == A[i-1] - A[i-2])
                pre[i] = pre[i-1] + 1;
        for (int i = N-3; i >= 0; i--)
            if (A[i] - A[i+1] == A[i+1] - A[i+2])
                suf[i] = suf[i+1] + 1;
        int res = 0;
        rep(i, 0, N) {
            if (i > 0)
                res = max(res, pre[i-1] + 1);
            if (i < N-1)
                res = max(res, suf[i+1] + 1);
            if (i > 0 && i < N-1 && abs(A[i+1] - A[i-1])%2 == 0) {
                int val = (A[i+1] + A[i-1])/2;
                int x = 1;
                if (i > 1 && A[i-1] - A[i-2] == val-A[i-1])
                    x += pre[i-1];
                else x++;
                if (i < N-2 && A[i+2] - A[i+1] == A[i+1]-val)
                    x += suf[i+1];
                else x++;
                res = max(res, x);
            }
        }
        printf("Case #%d: %d\n", t, res);
    }
}