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
        int n; cin >> n;
        vi A(n), res(n, 0);
        rep(i, 0, n) cin >> A[i];
        rep(i, 0, n) A[i]--;
        vector<unordered_set<int>> adj(n);
        rep(i, 0, n) adj[i].insert(A[i]);
        rep(i, 0, n-1) {
            int a, b; cin >> a >> b; a--; b--;
            if (adj[a].count(A[b])) res[A[b]]=1;
            else adj[a].insert(A[b]);
            if (adj[b].count(A[a])) res[A[a]]=1;
            else adj[b].insert(A[a]);
        }
        rep(i, 0, n) printf("%d", res[i]);
        printf("\n");
    }
}