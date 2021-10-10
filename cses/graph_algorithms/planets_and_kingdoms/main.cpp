#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> graph, trans;
vector<int> S;
int vis[100000];
int scc[100000];

void dfs(int v){
	if (vis[v]) return;
	vis[v] = true;
	for (int i = 0; i < graph[v].size(); i++)
		dfs(graph[v][i]);
	S.push_back(v);
}

int main(){
	scanf("%d %d", &n, &m);
	graph.assign(n, vector<int>());
	trans.assign(n, vector<int>());
	while (m--){
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		graph[a].push_back(b);
		trans[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		dfs(i);
	int compCount = 0;
	for (int i = n-1; i >= 0; i--){
		int v = S[i];
		if (scc[v]) continue;
		compCount++;
		queue<int> Q;
		Q.push(v);
		while (!Q.empty()){
			int x = Q.front(); Q.pop();
			if (scc[x]) continue;
			scc[x] = compCount;
			for (int j = 0; j < trans[x].size(); j++)
				Q.push(trans[x][j]);
		}
	}
	printf("%d\n", compCount);
	for (int i = 0; i < n; i++)
		printf("%d ", scc[i]);
	printf("\n");
}
