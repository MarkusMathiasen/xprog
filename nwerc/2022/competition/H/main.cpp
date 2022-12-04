#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int((x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct tree {
	int l=-1,r=-1;
	int h=0,rh;
	bool vis=false;
};

int n;
vector<vi> graph;
vector<tree> t;

void generate_tree(int v) {
	t[v].vis = true;
	for (int u : graph[v]) {
		if (t[u].vis)
			continue;
		if (t[v].l == -1)
			t[v].l = u;
		else if (t[v].r == -1)
			t[v].r = u;
		else assert(false);
		generate_tree(u);
	}
	if (t[v].r != -1)
		t[v].h = min(max(t[t[v].l].h, t[t[v].r].h)+1,min(t[t[v].l].h, t[t[v].r].h)+2);
	else if (t[v].l != -1)
		t[v].h = 1;
	else
		t[v].h = 0;
}

void compute_rh(int v) {
	int r = t[v].r, l = t[v].l;
	if (l != -1 && r != -1) {
		t[l].rh = min(min(t[l].h, t[r].h+1), t[v].rh-1);
		t[r].rh = min(min(t[r].h, t[l].h+1), t[v].rh-1);
		compute_rh(l);
		compute_rh(r);
	}
	else if (l != -1) {
		t[l].rh = min(0, t[v].rh-1);
		compute_rh(l);
	}
}

int main() {
	scanf("%d", &n);
	graph.assign(n, vi());
	rep(i, 0, n-1) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	t.assign(n, tree());
	generate_tree(0);
	t[0].rh = t[0].h;
	compute_rh(0);
	int res = 0;
	rep(i, 0, n) res += t[i].rh < 0 || !t[i].vis;
	printf("%d\n", res);
}
