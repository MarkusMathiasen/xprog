#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a%b);
}

struct Tree {
    typedef ll T;
    static constexpr T unit = 0;
    T f(T a, T b) { return gcd(a, b); } // (any associative fn)
    vector<T> s; int n;
    Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

struct edge {
    ll to, L, A;
};

vector<vector<edge>> graph;
vi vis;
Tree st;
vector<vi> queries;
map<pii, ll> ans_map;

void dfs(ll c) {
    vis[c] = 1;
    for (int w : queries[c])
        ans_map[{c, w}] = st.query(0, w+1);
    for (edge e : graph[c]) {
        if (vis[e.to]) continue;
        st.update((int)e.L, e.A);
        dfs(e.to);
        st.update((int)e.L, 0);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    int T; cin >> T;
    rep(t, 1, T+1) {
        int N, Q; cin >> N >> Q;
        graph.assign(N, {});
        rep(i, 0, N-1) {
            ll X, Y, L, A; cin >> X >> Y >> L >> A; X--; Y--;
            graph[X].push_back({Y, L, A});
            graph[Y].push_back({X, L, A});
        }
        queries.assign(N, {});
        vector<pii> qs;
        rep(i, 0, Q) {
            int C, W; cin >> C >> W; C--;
            queries[C].push_back(W);
            qs.push_back({C, W});
        }
        vis.assign(N, 0);
        st = Tree(2e5+2, 0);
        ans_map.clear();
        dfs(0);
        printf("Case #%d:", t);
        for (auto [C, W] : qs)
            printf(" %lld", ans_map[{C, W}]);
        printf("\n");
    }
}