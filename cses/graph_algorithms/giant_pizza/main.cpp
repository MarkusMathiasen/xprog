#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> graph;
vector<bool> vis;

int flip(int d) {
	return (d+m)%(2*m);
}

bool dfs(int v) {
	if (vis[flip(v)])
		return false;
	if (vis[v])
		return true;
	vis[v] = true;
	for (int u : graph[v]) {
		if (!dfs(u)) {
			vis[v] = false;
			return false;
		}
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	graph.assign(2*m, set<int>());
	for (int i = 0; i < n; i++) {
		char c1, c2; int d1, d2; scanf(" %c%d %c%d", &c1, &d1, &c2, &d2); d1--; d2--;
		d1 += c1 == '-' ? m : 0;
		d2 += c2 == '-' ? m : 0;
		graph[flip(d1)].insert(d2);
		graph[flip(d2)].insert(d1);
	}
	bool possible = true;
	vis.assign(2*m, false);
	for (int i = 0; i < m; i++) {
		if (vis[i] || vis[flip(i)])
			continue;
		if (!dfs(i) && !dfs(flip(i)))
			possible = false;
	}
	if (!possible)
		printf("IMPOSSIBLE");
	else
		for (int i = 0; i < m; i++)
			printf("%c ", vis[i] ? '+' : '-');
	printf("\n");
}
