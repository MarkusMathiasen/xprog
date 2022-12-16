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

vector<vector<ll>> graph(64, vector<ll>());
vector<ll> rate(64, 0);
map<state, ll> dp;
unordered_map<string, ll> m;
int cnt = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //cin.exceptions(cin.failbit);
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        string s, valve; ss >> s >> valve;
        if (!m.count(valve)) m[valve] = cnt++;
        int r; ss >> s >> s >> s;
        sscanf(s.c_str(), "rate=%d;", &r);
        rate[m[valve]] = r;
        ss >> s >> s >> s >> s;
        while (ss >> s) {
            if (s.back() == ',') s.pop_back();
            if (!m.count(s)) m[s] = cnt++;
            graph[m[valve]].push_back(m[s]);
        }
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
            break;
        ll p = dp[s];
        if (!(s.v & (1ll << s.c))) {
            ll nvis = s.v | (1ll << s.c);
            ll np = p + (26ll-s.m)*rate[s.c];
            ll nc = s.c;
            if (s.c != s.e && !(s.v & (1ll << s.e))) {
                state nxt = {nvis | (1ll << s.e), min(nc, s.e), max(nc, s.e), s.m+1};
                if (!dp.count(nxt)) q.push(nxt);
                dp[nxt] = max(dp[nxt], np+(26ll-s.m)*rate[s.e]);
            }
            for (ll ue : graph[s.e]) {
                state nxt = {nvis, min(nc, ue), max(nc, ue), s.m+1};
                if (!dp.count(nxt)) q.push(nxt);
                dp[nxt] = max(dp[nxt], np);
            }
        }
        for (ll u : graph[s.c]) {
            ll nvis = s.v;
            ll nc = u;
            ll np = p;
            if (s.c != s.e && !(s.v & (1ll << s.e))) {
                state nxt = {nvis | (1ll << s.e), min(nc, s.e), max(nc, s.e), s.m+1};
                if (!dp.count(nxt)) q.push(nxt);
                dp[nxt] = max(dp[nxt], np+(26ll-s.m)*rate[s.e]);
            }
            for (ll ue : graph[s.e]) {
                state nxt = {nvis, min(nc, ue), max(nc, ue), s.m+1};
                if (!dp.count(nxt)) q.push(nxt);
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