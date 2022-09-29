#include <bits/stdc++.h>
using namespace std;

int n, m; 
vector<vector<int>> graph;
vector<bool> vis;
int mat[500][500];
int og[500][500];

int dfs(int v) {
	if (v == n-1)
		return true;
	if (vis[v])
		return false;
	vis[v] = true;
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
		mat[a][b] = og[a][b] = 1;
	}
	int res = 0;
	vis.assign(n, 0);
	while (dfs(0)) {
		vis.assign(n, 0);
		res++;
	}
	printf("%d\n", res);
	while (res--) {
		vector<int> route;
		int v = 0;
		while (v != n-1) {
			route.push_back(v+1);
			for (int u : graph[v])
				if (mat[v][u] < og[v][u]) {
					mat[v][u]++;
					v = u;
					break;
				}
		}
		printf("%ld\n", route.size()+1);
		for (int x : route)
			printf("%d ", x);
		printf("%d\n", n);
	}
}
