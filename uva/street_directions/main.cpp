#include <bits/stdc++.h>

using namespace std;

int n, m;
int low[1000], disc[1000];
vector<vector<int>> graph;
int visited = 0;
int taken[1000][1000];
int p[1000];
vector<pair<int, int>> s;

void dfs(int v){
	disc[v] = ++visited;
	low[v] = visited;
	for (int i = 0; i < (int)graph[v].size(); i++){
		int u = graph[v][i];
		if (u == p[v]) continue;
		if (disc[u] == -1) {
			p[u] = v;
			dfs(u);
			low[v] = min(low[v], low[u]);
		}
		else
			low[v] = min(low[v], disc[u]);
		bool art = low[u] > disc[v];
		if (!taken[v][u]){
			s.push_back(make_pair(v+1, u+1));
			if (art) s.push_back(make_pair(u+1, v+1));
		}
		taken[v][u] = taken[u][v] = 1;
	}
}

int main(){
	scanf("%d %d", &n, &m);
	int T = 0;
	while (n || m){
		T++;
		visited = 0;
		s.assign(0, pair<int, int>());
		for (int i = 0; i < 1000; i++)
			for (int j = 0; j < 1000; j++)
				taken[i][j] = 0;
		graph.assign(n, vector<int>());
		while (m--){
			int a, b; scanf("%d %d", &a, &b); a--; b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for (int i = 0; i < 1000; i++) p[i] = -10;
		for (int i = 0; i < 1000; i++) low[i] = disc[i] = -1;
		printf("%d\n\n", T);
		dfs(0);
		sort(s.begin(), s.end());
		for (int i = 0; i < (int)s.size(); i++)
			printf("%d %d\n", s[i].first, s[i].second);
		printf("#\n");
		scanf("%d %d", &n, &m);
	}
	printf("\n");
}
