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
    while (T--) {
        int n, m; cin >> n >> m;
        vi A(n); rep(i, 0, n) cin >> A[i];
        int b; cin >> b;
        A[0] = min(A[0], b-A[0]);
        rep(i, 1, n)
            if ((A[i-1] <= b-A[i] && b-A[i] <= A[i]) || A[i-1] > A[i])
                A[i] = b-A[i];

        bool sorted = true;
        rep(i, 0, n-1) sorted &= A[i] <= A[i+1];
        if (sorted) printf("YES\n");
        else printf("NO\n");
    }
}