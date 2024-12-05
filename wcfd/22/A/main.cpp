#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
	if (btoa[j] == -1) return 1;
	vis[j] = 1; int di = btoa[j];
	for (int e : g[di])
		if (!vis[e] && find(e, g, btoa, vis)) {
			btoa[e] = di;
			return 1;
		}
	return 0;
}
int dfsMatching(vector<vi>& g, vi& btoa) {
	vi vis;
	rep(i,0,sz(g)) {
		vis.assign(sz(btoa), 0);
		for (int j : g[i])
			if (find(j, g, btoa, vis)) {
				btoa[j] = i;
				break;
			}
	}
	return sz(btoa) - (int)count(all(btoa), -1);
}

vi seen;

bool flip(int i, vector<vi>& g, vi& match) {
    if (i == -1) return false;
    if (seen[i] == 2) return false;
    if (seen[i] == 1) return true;
    seen[i] = 1;

    for (int j : g[i])
        if (!flip(match[j], g, match)) {
            seen[i] = 2;
            return false;
        }
    return true;
}

vi get_res(vi match2, int n) {
    vi cover;
    rep(i, 0, n) if (match2[i] != -1) cover.push_back(seen[i] == 1 ? match2[i] : i);
    bool all_flipped = true;
    rep(i, 0, n) if (match2[i] != -1) all_flipped &= seen[i] == 1;
    if (all_flipped) cover.push_back(0);
    return cover;
}

vi cover(vector<vi> g, int n, int m) {
	vi match(m, -1);
	int M = dfsMatching(g, match);

    // fill out data structures
    rep(i, 0, n) for (int& j : g[i]) j += n; 
    rep(i, 0, m) g.push_back({});
    rep(i, 0, n) for (int j : g[i]) g[j].push_back(i);
    vi match2(n+m, -1);
    rep(i, 0, m) {match2[n+i] = match[i]; if (match[i] != -1) match2[match[i]] = n+i;}
    // done

    seen.assign(n+m, 0);
    vi cover;
    rep(i, 0, n) if (match2[i] == -1) assert(flip(i, g, match2));
    rep(i, 0, n) if (seen[i] == 1) {
        return get_res(match2, n);
    }
    rep(i, 0, n) {
        if (match2[i] == -1) continue;
        if (flip(i, g, match2)) {
            vi maybe = get_res(match2, n);
            if (sz(maybe) == M) return maybe;
        }
        rep(i, 0, n) if (seen[i] == 1) seen[i] = 0;
    }
    rep(i, 0, n) if (match2[i] != -1) cover.push_back(i);
    cover.push_back(n);
    return cover;
}

map<string,int> ma, mb;
vector<string> va, vb;
vector<vi> g;

int main() {
	cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    rep(i, 0, n) {
        string a, b; cin >> a >> b;
        if (!ma.count(a)) ma[a] = sz(va), va.push_back(a), g.push_back({});
        if (!mb.count(b)) mb[b] = sz(vb), vb.push_back(b);
        g[ma[a]].push_back(mb[b]);
    }
    int A = sz(va), B = sz(vb);
    vi res = cover(g, A, B);
    printf("%d\n", sz(res));
    for (int i : res) printf("%s\n", (i < A ? va[i] : vb[i-A]).c_str());
}
