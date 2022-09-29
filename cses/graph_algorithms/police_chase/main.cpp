#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> vis;
int n, m, mat[500][500];

bool dfs(int v) {
	if (v == n-1)
		return true;
	if (vis[v])
		return false;
	vis[v] = 1;
	for (int u : graph[v]) {
		if (mat[v][u] && dfs(u)) {
			mat[v][u]--;
			mat[u][v]++;
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	graph.assign(n, vector<int>());
	while (m--) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
		mat[a][b] = mat[b][a] = 1;
	}
	vis.assign(n, 0);
	int res = 0;
	while (dfs(0)) {
		res++;
		vis.assign(n, 0);
	}
	printf("%d\n", res);
	queue<int> q; q.push(0);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		if (vis[v])
			continue;
		vis[v] = true;
		for (int u : graph[v])
			if (mat[v][u])
				q.push(u);
	}
	for (int v = 0; v < n; v++)
		if (vis[v])
			for (int u : graph[v])
				if (!vis[u])
					printf("%d %d\n", v+1, u+1);
}
