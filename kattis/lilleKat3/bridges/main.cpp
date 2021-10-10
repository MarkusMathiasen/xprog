#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int n, m;
vector<vector<ii>> graph;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	graph.assign(n, vector<ii>());
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}
	priority_queue<ii, vector<ii>, greater<ii>> Q;
	Q.emplace(0, 0);
	vector<int> dist(n, -1);
	while (!Q.empty()) {
		int v = Q.top().second;
		int d = Q.top().first;
		Q.pop();
		if (dist[v] != -1)
			continue;
		dist[v] = d;
		for (ii u : graph[v])
			Q.push({d+u.second, u.first});
	}
	cout << dist[n-1] << endl;
}
