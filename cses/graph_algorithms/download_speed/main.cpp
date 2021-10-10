#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>
#define iii<pair<int, pair<int, int>>

int n, m;
vector<vector<ii>> graph, tree;
bool vis[500];
int speed[500];

int main(){
	scanf("%d %d", &n, &m);
	graph.assign(n, vector<ii>());
	tree.assign(n, vector<ii>());
	while (m--){
		int a, b, c; scanf("%d %d %d", &a, &b, &c); a--; b--;
		graph[a].push(ii(c, b));
	}
	priority_queue<iii> Q;
	vis[0] = true;
	for (int i = 0; i < graph[0].size(); i++)
		Q.push(iii(graph[0][i].first, ii(0, graph[0][i].second)));
	while (!Q.empty()){
		int c = Q.top().first;
		int a = Q.top().second.first;
		int b = Q.top().second.second;
		Q.pop();
		if (vis[b]) continue;
		vis[b] = true;
		tree[a].push_back(ii(c, b));
	}
	int result = 0;
	queue<int> q; q.push(0);
	speed[0] = 1000000000;
	while (!q.empty()){
		int pos = q.front(); q.pop();
		for (int i = 0; i < tree[pos].size(); i++)
		
	}
}
