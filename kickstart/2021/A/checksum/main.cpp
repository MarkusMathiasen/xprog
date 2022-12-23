#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct UF {
    vi e;
    UF(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int T; cin >> T;
    rep(t, 1, T+1) {
        int N; cin >> N;
        vector<vi> edges;
        ll res = 0;
        vector<vector<int>> A(N, vector<int>(N));
        rep(i, 0, N) rep(j, 0, N)
            cin >> A[i][j];
        vector<vector<int>> B(N, vector<int>(N));
        rep(i, 0, N) rep(j, 0, N)
            cin >> B[i][j];
        rep(i, 0, N) rep(j, 0, N) {
            if (A[i][j] == -1)
                edges.push_back({B[i][j], i, N+j}),
                res += B[i][j];
        }
        sort(edges.rbegin(), edges.rend());
        UF uf(2*N);
        for (vi e : edges) {
            int x = e[0], i = e[1], j = e[2];
            if (uf.sameSet(i, j)) continue;
            res -= x;
            uf.join(i, j);
        }
        printf("Case #%d: %lld\n", t, res);
        rep(i, 0, 2*N) cin >> res;
    }
}