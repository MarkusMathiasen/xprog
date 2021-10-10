#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int n, m, k;
vector<vector<vector<ii>>> graph;
bool used[2][500];
vector<ii> results;
queue<ii> Q;

void eraseNode(int g, int p){
	while (graph[g][p].size() > 0){
		int nxt = graph[g][p].back().first;
		graph[g][p].pop_back();
		for (int i = 0; i < (int)graph[!g][nxt].size(); i++)
			if (graph[!g][nxt][i].first == p)
				graph[!g][nxt].erase(graph[!g][nxt].begin()+i);
		if (graph[!g][nxt].size() == 1) Q.push(ii(!g, nxt));
	}
}

void flex(int g, int p){
	if (used[g][p]) return;
	used[g][p] = true;
	if (graph[g][p].size() == 0) return;
	int p2 = graph[g][p][0].first;
	used[!g][p2] = true;
	if (g == 0)
		results.push_back(ii(p, p2));
	else
		results.push_back(ii(p2, p));
	eraseNode(g, p);
	eraseNode(!g, p2);
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	graph.assign(2, vector<vector<ii>>(max(n, m), vector<ii>()));
	for (int i = 0; i < k; i++){
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		graph[0][a].push_back(ii(b, graph[1][b].size()));
		graph[1][b].push_back(ii(a, graph[0][a].size()-1));
	}
	for (int j = 0; j < 2; j++)
		for (int i = 0; i < (int)graph[j].size(); i++)
			if (graph[j][i].size() == 1)
				Q.push(ii(j, i));
	for (int i = 0; i < n; i++){
		while (!Q.empty()){
			int g = Q.front().first;
			int p = Q.front().second;
			Q.pop();
			flex(g, p);
		}
		flex(0, i);
	}
	printf("%ld\n", results.size());
	for (int i = 0; i < (int)results.size(); i++)
		printf("%d %d\n", results[i].first+1, results[i].second+1);
}
