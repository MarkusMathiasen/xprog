#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int n; 
vector<vector<int>> graph;
vector<int> dist;
vector<bool> vis;
vector<int> res;

void dfs(int v, int d) {
	if (dist[v] != -1)
		return;
	dist[v] = d;
	for (int u : graph[v])
		dfs(u, d+1);
}

void dfs2(int v) {
	if (vis[v])
		return;
	vis[v] = true;
	res.push_back(v);
	for (int u : graph[v])
		dfs2(u);
}

int main() {
	scanf("%d", &n);
	graph.assign(n, vector<int>());
	for (int i = 0; i < n-1; i++) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int leaf = -1;
	for (int i = 0; i < n; i++)
		if (graph[i].size() == 1) {
			leaf = i;
			break;
		}
	dist.assign(n, -1);
	dfs(leaf, 0);
	int other = leaf;
	for (int i = 0; i < n; i++)
		if (dist[i] > dist[other])
			other = i;
	vector<int> dia = {other};
	while (other != leaf) {
		for (int u : graph[other])
			if (dist[u] < dist[other]) {
				other = u;
				dia.push_back(other);
				break;
			}
	}
	if ((int)dia.size() < 4) {
		printf("NO\n");
		return 0;
	}
	vis.assign(n, false);
	int mid = dia.size()/2;
	vis[dia[mid]] = true;
	res.push_back(dia[mid]);
	for (int i = 0; i < mid; i++) {
		vis[dia[i]] = true;
		res.push_back(dia[i]);
		if ((int)dia.size()-i-1 > mid) {
			vis[dia[dia.size()-1-i]] = true;
			res.push_back(dia[dia.size()-1-i]);
		}
	}
	for (int v : dia)
		for (int u : graph[v])
			if (!vis[u])
				dfs2(u);
	printf("YES\n");
	for (int x : res)
		printf("%d ", x+1);
	printf("\n");
}
