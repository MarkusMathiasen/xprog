#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>
#define ll long long

int n, m;
int vis[100000];
vector<vector<ii>> graph;

int main(){
	scanf("%d %d", &n, &m);
	graph.assign(n, vector<ii>());
	while (m--){
		int a, b, c; scanf("%d %d %d", &a, &b, &c); a--; b--;
		graph[a].push_back(ii(c, b));
		graph[b].push_back(ii(c, a));
	}
	priority_queue<ii, vector<ii>, greater<ii>> Q;
	Q.push(ii(0, 0));
	int added = 0;
	ll result = 0;
	while (!Q.empty() && added != n){
		int d = Q.top().first;
		int v = Q.top().second;
		Q.pop();
		if (vis[v]) continue;
		vis[v] = true;
		added++; result += d;
		for (int i = 0; i < graph[v].size(); i++)
			Q.push(ii(graph[v][i].first, graph[v][i].second));
	}
	if (added != n)
		printf("IMPOSSIBLE\n");
	else
		printf("%lld\n", result);
}
