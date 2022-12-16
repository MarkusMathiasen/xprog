#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct state {
    ll v, c, e, m;
    const bool operator<(const state& o) const {
        if (m != o.m)
            return m > o.m;
        else if (c != o.c)
            return c > o.c;
        else if (e != o.e)
            return e > o.e;
        else
            return v > o.v;
    }
};

vector<vector<string>> graph;
vector<ll> rate;
map<state, ll> dp;
unordered_map<string, int> m;
int cnt = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string s, valve; ss >> s >> valve;
        int r; ss >> s >> s >> s;
        sscanf(s.c_str(), "rate=%d;", &r);
        rate.push_back(r);
        ss >> s >> s >> s >> s;
        graph.push_back({});
        while (ss >> s) {
            if (s.back() == ',') s.pop_back();
            graph.back().push_back(s);
        }
        m[valve] = cnt++;
    }
    queue<state> q;
    set<state> vis;
    ll vis_init = 0;
    for (ll i = 0; i < sz(graph); i++)
        if (!rate[i])
            vis_init |= (1ll << i);
    q.push({vis_init, m["AA"], m["AA"], 1});
    ll minute = 0;
    while (!q.empty()) {
        state s = q.front(); q.pop();
        if (vis.count(s)) continue;
        vis.insert(s);
        if (s.m > minute) {
            minute = s.m;
            printf("minute = %lld\n", minute);
        }
        if (s.m == 26)
            continue;
        ll p = dp[s];
        vector<pair<state, ll>> next;
        if (!(s.v & (1ll << s.c))) {
            state nxt = {s.v | (1ll << s.c), s.c, s.e, s.m+1};
            next.emplace_back(nxt, p+(26ll-s.m)*rate[s.c]);
            /*q.push(nxt);
            dp[nxt] = max(dp[nxt], p+(26ll-s.m)*rate[s.c]);*/
        }
        for (string& u : graph[s.c]) {
            state nxt = {s.v, m[u], s.e, s.m+1};
            next.emplace_back(nxt, p);
            /*q.push(nxt);
            dp[nxt] = max(dp[nxt], p);*/
        }
        for (auto& [nxt, np] : next) {
            if (s.c != s.e && !(s.v & (1ll << s.e))) {
                nxt.v |= (1ll << s.e);
                //if (nxt.c > nxt.e) swap(nxt.c, nxt.e);
                q.push(nxt);
                dp[nxt] = max(dp[nxt], np+(26ll-s.e)*rate[s.e]);
                nxt.v ^= (1ll << s.e);
            }
            for (string& u : graph[s.e]) {
                nxt.e = m[u];
                //if (nxt.c > nxt.e) swap(nxt.c, nxt.e);
                q.push(nxt);
                dp[nxt] = max(dp[nxt], np);
            }
        }
    }
    ll res = 0;
    for (auto& [s, c] : dp) {
        res = max(res, c);
    }
    printf("%lld\n", res);
}