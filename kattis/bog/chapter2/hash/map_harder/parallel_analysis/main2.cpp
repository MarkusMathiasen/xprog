#include <bits/stdc++.h>
using namespace std;

int T, n;
unordered_map<int, vector<int>> graph;
unordered_map<int, int> maxWrote;
vector<int> dist;

int dfs(int v) {
	if (dist[v] != -1)
		return dist[v];
	int res = 0;
	for (int x : graph[v])
		res = max(res, dfs(x));
	return dist[v] = res+1;
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &n);
		dist.assign(n+1, -1);
		dist[0] = 0;
		maxWrote.clear();
		graph.clear();
		for (int i = 1; i <= n; i++) {
			int m; scanf("%d", &m);
			for (int j = 0; j < m-1; j++) {
				int x; scanf("%d", &x);
				graph[i].push_back(maxWrote[x]);
			}
			int x; scanf("%d", &x);
			maxWrote[x] = i;
		}
		int res = 0;
		for (int i = 0; i <= n; i++)
			res = max(res, dfs(i));
		printf("%d %d\n", t, res);
	}
}
