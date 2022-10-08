#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

int main() {
	int n; scanf("%d", &n);
	graph.assign(n, vector<int>());
	for (int i = 0; i < n-1; i++) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int x = -1;
	for (int i = 0; i < n; i++)
		if ((int)graph[i].size() > 1)
			x = i;
	if (x == -1) {
		printf("NO\n");
		return 0;
	}
	int y = -1;
	for (int v : graph[x])
		if ((int)graph[v].size() > 1)
			y = v;
	if (y == -1) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	vector<bool> vis(n, false);
	vis[x] = true;
	vector<int> res = {x};
	queue<int> q;
	for (int v : graph[x])
		if (v != y) {
			vis[v] = true;
			res.push_back(v);
			for (int u : graph[v])
				q.push(u);
			break;
		}
	for (int u : graph[x])
		q.push(u);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		if (vis[v])
			continue;
		vis[v] = true;
		res.push_back(v);
		for (int u : graph[v])
			q.push(u);
	}
	for (int v : res)
		printf("%d ", v+1);
	printf("\n");
}
