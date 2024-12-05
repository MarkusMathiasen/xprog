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

void fix_cover(vi& cover, vector<vi>& g, vi& match, int A, int B) {
    vi cont(sz(g), 0);
    for (int i : cover) for (int j : g[i]) cont[j]++;
    vi can_move(sz(g), 1);
    for (int i : cover) for (int j : g[i]) can_move[i] &= cont[j] != 1 || match[j] == i;
    bool moved = false;
    for (int& i : cover) if (can_move[i]) {
        moved = true;
        i = match[i];
        break;
    }
    if (!moved) {
        cover.push_back(cover[0] < A ? A : 0);
    }
}

vi cover(vector<vi>& g, int n, int m) {
	vi match(m, -1);
	int res = dfsMatching(g, match);
	vector<bool> lfound(n, true), seen(m);
	for (int it : match) if (it != -1) lfound[it] = false;
	vi q, cover;
	rep(i,0,n) if (lfound[i]) q.push_back(i);
	while (!q.empty()) {
		int i = q.back(); q.pop_back();
		lfound[i] = 1;
		for (int e : g[i]) if (!seen[e] && match[e] != -1) {
			seen[e] = true;
			q.push_back(match[e]);
		}
	}
	rep(i,0,n) if (!lfound[i]) cover.push_back(i);
	rep(i,0,m) if (seen[i]) cover.push_back(n+i);
	int A = 0, B = 0;
    rep(i, 0, sz(cover)) if (cover[i] < n) A++; else B++;

    if (A == 1 || B == 1) return {0, n};
    rep(i, 0, n) for (int& j : g[i]) j += n; 
    rep(i, 0, m) g.push_back({});
    rep(i, 0, n) for (int j : g[i]) g[j].push_back(i);
    vi match2(n+m, -1);
    rep(i, 0, m) {match2[n+i] = match[i]; if (match[i] != -1) match2[match[i]] = n+i;}
    if (A == sz(cover)) {
        fix_cover(cover, g, match2, A, B);
    } else if (B == sz(cover)) {
        fix_cover(cover, g, match2, A, B);
    }
    assert(res >= sz(cover)-1 && res <= sz(cover));
	return cover;
}

map<string,int> ma, mb;
vector<string> va, vb;
vector<vi> g;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);
    int n; cin >> n;
    rep(i, 0, n) {
        string a, b; cin >> a >> b;
        if (!ma.count(a)) ma[a] = sz(va), va.push_back(a), g.push_back({});
        if (!mb.count(b)) mb[b] = sz(vb), vb.push_back(b);
        g[ma[a]].push_back(mb[b]);
    }
    int A = sz(va), B = sz(vb);
    vi int_res = cover(g, A, B);
    vector<string> res;
    for (int i : int_res) res.push_back(i < A ? va[i] : vb[i-A]);
    sort(all(res));
    printf("%d\n", sz(res));
    for (string s : res) printf("%s\n", s.c_str());
}
