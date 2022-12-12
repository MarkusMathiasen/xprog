#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct monkey {
    vector<ll> items;
    function<ll(ll)> op;
    ll div;
    ll if_true, if_false;
};

vector<monkey> monkeys;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    string s, s2;
    while (cin >> s >> s) {
        monkeys.push_back(monkey());
        cin >> s >> s;
        while (cin >> s) {
            bool done = true;
            if (s.back() == ',') s.pop_back(), done = false;
            monkeys.back().items.push_back(stoi(s));
            if (done) break;
        }
        cin >> s >> s >> s >> s;
        cin >> s >> s2;
        if (s == "+" && s2 == "old") {
            monkeys.back().op = [](ll x) { return x + x; };
        } else if (s == "+" && s2 != "old") {
            monkeys.back().op = [s2](ll x) { return x + stoi(s2); };
        } else if (s == "*" && s2 == "old") {
            monkeys.back().op = [](ll x) { return x * x; };
        } else if (s == "*" && s2 != "old") {
            monkeys.back().op = [s2](ll x) { return x * stoi(s2); };
        }
        cin >> s >> s >> s >> monkeys.back().div;
        cin >> s >> s >> s >> s >> s >> monkeys.back().if_true;
        cin >> s >> s >> s >> s >> s >> monkeys.back().if_false;
    }
    vector<ll> res(sz(monkeys), 0);
    ll divisor = 1;
    for (monkey& m : monkeys)
        divisor *= m.div;
    rep(i, 0, 10000) {
        rep(j, 0, sz(monkeys)) {
            res[j] += sz(monkeys[j].items);
            for (ll x : monkeys[j].items) {
                x = monkeys[j].op(x)%divisor;
                if (x%monkeys[j].div == 0) {
                    monkeys[monkeys[j].if_true].items.push_back(x);
                } else {
                    monkeys[monkeys[j].if_false].items.push_back(x);
                }
            }
            monkeys[j].items.clear();
        }
    }
    sort(all(res));
    printf("%lld\n", res[sz(res)-1]*res[sz(res)-2]);
}
