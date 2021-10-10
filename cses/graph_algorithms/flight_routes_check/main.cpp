#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> graph, trans;

int main(){
	scanf("%d %d", &n, &m);
	graph.assign(n, vector<int>());
	trans.assign(n, vector<int>());
	while (m--){
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		graph[a].push_back(b);
		trans[b].push_back(a);
	}
	vector<bool> vis(n, 0);
	int visCount = 0;
	queue<int> Q;
	Q.push(0);
	while (!Q.empty()){
		int v = Q.front(); Q.pop();
		if (vis[v]) continue;
		vis[v] = true; visCount++;
		for (int i = 0; i < graph[v].size(); i++)
			Q.push(graph[v][i]);
	}
	if (visCount < n)
		for (int i = 0; i < n; i++)
			if (!vis[i]){
				printf("NO\n1 %d\n", i+1); return 0;
			}
	for (int i = 0; i < n; i++)
		vis[i] = 0;
	visCount = 0;
	Q.push(0);
	while (!Q.empty()){
		int v = Q.front(); Q.pop();
		if (vis[v]) continue;
		vis[v] = true; visCount++;
		for (int i = 0; i < trans[v].size(); i++)
			Q.push(trans[v][i]);
	}
	if (visCount < n)
		for (int i = 0; i < n; i++)
			if (!vis[i]){
				printf("NO\n%d 1\n", i+1); return 0;
			}
	printf("YES\n");
	
}
