#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(long long i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
const ll mul = 811589153ll;

vector<pii> v;

void move_num(vector<pii>::iterator it) {
    pii val = *it;
    it = v.erase(it);
    ll i = (ll)(it - v.begin());
    ll idx = (i+val.first%sz(v) + sz(v))%sz(v);
    v.insert(v.begin()+idx, val);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    ll cnt = 0;
    ll x; while (scanf("%lld", &x) == 1)
        v.emplace_back(x*mul, cnt++);
    rep(j, 0, 10) {
        printf("Start iteration: %lld\n", j);
        rep(i, 0, sz(v)) {
            auto it = v.begin();
            while (it->second != i) it++;
            move_num(it);
        }
    }
    ll zero_pos;
    rep(i, 0, sz(v)) {
        if (v[i].first == 0) {
            zero_pos = i;
            break;
        }
    }
    ll res = 0;
    rep(i, 1, 3001) {
        if (i % 1000 == 0)
            printf("%lld ", v[(i+zero_pos)%sz(v)].first),
            res += v[(i+zero_pos)%sz(v)].first;
    }
    printf("\n");
    printf("%lld\n", res);
}
