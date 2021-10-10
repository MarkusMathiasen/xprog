#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int n, res = 0;
vector<vector<int>> tree;
vector<int> vis;

int dfs(int v) {
	if (vis[v]) return 0;
	vis[v] = 1;
	vector<int> routes(0, 0);
	for (int u : tree[v])
		routes.push_back(dfs(u));
	sort(routes.begin(), routes.end());
	if (routes.size() > 1) {
		int s = routes.size();
		res = max(res, routes[s-1] + routes[s-2]);
	}
	else
		res = max(res, routes.back());
	return routes.back()+1;
}

int main() {
	scanf("%d", &n);
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	tree.assign(n, vector<int>(0, 0));
	for (int i = 1; i < n; i++) {
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	vis.assign(n, 0);
	dfs(0);
	printf("%d\n", res);
}
