#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int n, m;
int low[10000], disc[10000], p[10000];
vector<vector<int>> graph;
int num;
vector<ii> pv;

void dfs(int v){
	disc[v] = low[v] = num++;
	for (int i = 0; i < (int)graph[v].size(); i++){
		int u = graph[v][i];
		if (u == p[v]) continue;
		if (disc[u] == -1){
			p[u] = v;
			dfs(u);
			low[v] = min(low[v], low[u]);
			if (low[u] >= disc[v]) pv[v].first++;
		}
		else
			low[v] = min(low[v], disc[u]);
	}
	if (disc[p[v]] < low[v]) pv[v].first++;
}

int main(){
	scanf("%d %d", &n, &m);
	while (n || m){
		for (int i = 0; i < 10000; i++) low[i] = p[i] = disc[i] = -1;
		p[0] = 0;
		graph.assign(n, vector<int>());
		num = 0;
		pv.assign(n, ii(0, 0));
		for (int i = 0; i < n; i++)
			pv[i].second = i;
		int a, b; scanf("%d %d", &a, &b);
		while (a != -1){
			graph[a].push_back(b);
			graph[b].push_back(a);
			scanf("%d %d", &a, &b);
		}
		dfs(0);
		for (int i = 0; i < (int)pv.size(); i++)
			if (pv[i].first == 0)
				pv[i].first = 1;
		sort(pv.begin(), pv.end(), [](ii a, ii b)->bool{
				if (a.first > b.first) return true;
				if (a.first < b.first) return false;
				if (a.first < b.first) return true;
				return false;
				});
		for (int i = 0; i < m; i++)
			printf("%d %d\n", pv[i].second, pv[i].first);
		scanf("%d %d", &n, &m);
	}
}
