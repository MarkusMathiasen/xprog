#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct monkey {
    ll num;
    string c1, c2;
    string op = "";
    bool vis = false;
};

map<string, monkey> tree;
map<string, bool> vis;

ll dfs(string name) {
    monkey& m = tree[name];
    if (vis[name]) return m.num;
    vis[name] = true;
    if (m.op == "") return m.num;
    else if (m.op == "+") return m.num = dfs(m.c1) + dfs(m.c2);
    else if (m.op == "*") return m.num = dfs(m.c1) * dfs(m.c2);
    else if (m.op == "-") return m.num = dfs(m.c1) - dfs(m.c2);
    else if (m.op == "/") return m.num = dfs(m.c1) / dfs(m.c2);
    else if (m.op == "=") return m.num = dfs(m.c1) == dfs(m.c2);
    else assert(false);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    string name; while (cin >> name) {
        assert(name.back() == ':');
        name.pop_back();
        monkey m;
        cin >> m.c1;
        if (isdigit(m.c1[0]))
            m.num = stoi(m.c1);
        else
            cin >> m.op >> m.c2;
        tree[name] = m;
    }
    tree["root"].op = "=";
    ll low = 0, high = 1e15;
    while (low < high) {
        ll mid = (low+high)/2;
        vis.clear();
        tree["humn"].num = mid;
        dfs("root");
        ll left = tree[tree["root"].c1].num;
        ll right = tree[tree["root"].c2].num;
        if (left > right)
            low = mid+1;
        else
            high = mid;
    }
    vis.clear();
    tree["humn"].num = low;
    assert(dfs("root"));
    printf("%lld\n", low);
}
