#include <bits/stdc++.h>
using namespace std;
#include "OrderStatisticTree.h"

#define rep(i, a, b) for(long long i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
const ll mul = 811589153ll;
const ll L = 1e18;

vector<ll> val;
Tree<pii> t;
unordered_map<ll, ll> m;

ll reorder_cnt = 0;
void reorder_tree() {
    reorder_cnt++;
    Tree<pii> new_t;
    ll i = 0;
    for (auto [a, b]: t) {
        m[b] = -L + 2 * L / sz(t) * i++;
        new_t.insert({m[b], b});
    }
    t = new_t;
}

void move_num(ll i) {
    ll order = t.order_of_key({m[i], i});
    ll new_order = (order+val[i]%(sz(t)-1)+sz(t)-1)%(sz(t)-1);
    t.erase({m[i], i});
    auto nxt = t.find_by_order(new_order);
    assert(nxt != t.end());
    if (nxt == t.begin()) {
        m[i] = t.begin()->first - 10000;
        t.insert({m[i], i});
    } else {
        auto prv = nxt; prv--;
        if (nxt->first - prv->first < 2) {
            t.insert({m[i], i});
            reorder_tree();
            move_num(i);
        } else {
            m[i] = (prv->first + nxt->first)/2;
            t.insert({m[i], i});
        }
    }
}

void print_tree(bool extra = false) {
    for (auto [a, b] : t)
        if (extra)
            printf("(%lld, %lld) ", a, b);
        else
            printf("%lld ", val[b]);
    printf("\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    ll cnt = 0, zero_cnt = -1;
    ll x; while (scanf("%lld", &x) == 1) {
        t.insert({cnt, cnt});
        cnt++;
        val.push_back(x*mul);
        if (x == 0 && zero_cnt == -1) zero_cnt = cnt-1;
    }

    ll og_sz = sz(t);
    rep(i, 0, 200*og_sz)
        t.insert({cnt, cnt}),
        cnt++,
        val.push_back(val[i%og_sz]);

    reorder_tree();
    rep(j, 0, 10) {
        printf("Start iteration: %lld\n", j);
        rep(i, 0, sz(t))
            move_num(i);
    }

    ll res = 0;
    auto p = t.find({m[zero_cnt], zero_cnt});
    rep(i, 0, 3) {
        rep(j, 0, 1000) {
            p++;
            if (p == t.end()) p = t.begin();
        }
        printf("%lld ", val[p->second]);
        res += val[p->second];
    }
    printf("\n");
    printf("%lld\n", res);
    printf("Reorder cnt: %lld\n", reorder_cnt);
}
