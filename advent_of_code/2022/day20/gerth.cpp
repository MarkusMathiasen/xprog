#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(long long i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
const ll mul = 811589153ll;

vector<ll> v, val;

void move_num(vector<ll>::iterator it) {
    ll num = *it;
    ll am = val[num];
    it = v.erase(it);
    ll i = (ll)(it - v.begin());
    ll idx = (i+am%sz(v) + sz(v))%sz(v);
    v.insert(v.begin()+idx, num);
}
/*
void print_list() {
    rep(i, 0, sz(v)) {
        printf("%lld ", val[v[i]]);
    }
    printf("\n");
}

vector<ll>::iterator search_near(int val, int guess_idx) {
    rep(i, 0, sz(v)/2+1) {
        int idx1 = (guess_idx+i)%sz(v);
        int idx2 = (guess_idx-i+sz(v))%sz(v);
        if (v[idx1] == val)
            return v.begin()+idx1;
        else if (v[idx2] == val)
            return v.begin()+idx2;
    }
    return v.end();
}
*/
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    ll cnt = 0, zero_cnt = -1;
    ll x; while (scanf("%lld", &x) == 1) {
        v.push_back(cnt++);
        val.push_back(x*mul);
        if (x == 0 && zero_cnt == -1) zero_cnt = cnt-1;
    }
    ll og_sz = sz(v);
    rep(j, 0, 200) rep(i, 0, og_sz)
        v.push_back(cnt++), val.push_back(val[i]);
    rep(j, 0, 10) {
        printf("Start iteration: %lld\n", j);
        rep(i, 0, sz(v)) {
            if (i % 100000 == 0)
                printf("i = %d\n", i);
            auto it = find(all(v), i);
            move_num(it);
        }
    }
    ll zero_pos = find(all(v), zero_cnt) - v.begin();
    ll res = 0;
    rep(i, 1, 3001) {
        if (i % 1000 == 0)
            printf("%lld ", val[v[(i+zero_pos)%sz(v)]]),
            res += val[v[(i+zero_pos)%sz(v)]];
    }
    printf("\n");
    printf("%lld\n", res);
}
