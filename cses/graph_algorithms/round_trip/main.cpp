#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> dist;
int cnt = -1;

bool dfs(int v, int prev) {
	for (int u : graph[v]) {
		if (u == prev)
			continue;
		if (dist[u]) {
			cnt = dist[v]-dist[u]+1;
			printf("%d\n%d %d", cnt+1, u, v);
			return true;
		}
		dist[u] = dist[v]+1;
		if (dfs(u, v)) {
			if (--cnt)
				printf(" %d", v);
			return true;
		}
	}
	return false;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	graph.assign(n+1, vector<int>());
	while (m--) {
		int a, b; scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dist.assign(n+1, 0);
	for (int i = 1; i <= n; i++) {
		if (dist[i])
			continue;
		dist[i] = 1;
		if (dfs(i, 0)) {
			printf("\n");
			return 0;
		}
	}
	printf("IMPOSSIBLE\n");
}
