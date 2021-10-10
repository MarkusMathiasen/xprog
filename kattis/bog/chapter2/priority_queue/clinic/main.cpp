#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct que {
    ll p;
    string name;
    que(ll p, const string& name) : p(p), name(name) {}
    que() {}

    bool operator < (const que& a) const {
        if (p != a.p)
            return p < a.p;
        return name > a.name;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k; cin >> n >> k;
    set<string> left;
    priority_queue<que> pq;
    for (ll i = 0; i < n; i++) {
        ll q; cin >> q;
        if (q == 1) {
            ll t, s; string m; cin >> t >> m >> s;
            pq.push(que(s - t*k, m));
        }
        else if (q == 2) {
            ll t; cin >> t;
            if (pq.empty()) {
                printf("doctor takes a break\n");
                continue;
            }
            que nxt;
            do {
                nxt = pq.top();
                pq.pop();
            } while (!pq.empty() && left.count(nxt.name));
            if (left.count(nxt.name))
                printf("doctor takes a break\n");
            else
                printf("%s\n", nxt.name.c_str());
        }
        else if (q == 3) {
            ll t; string m; cin >> t >> m;
            left.insert(m);
        }
        else throw q;
    }
}
