#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int main() {
	int n, m, q, s;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n >> m >> q >> s, n) {
		vector<vector<ii>> graph(n, vector<ii>());
		while (m--) {
			int u, v, w; cin >> u >> v >> w;
			graph[u].push_back(ii(v, w));
		}
		vector<vector<bool>> reachable(n, vector<bool>(n, 0));
		for (int i = 0; i < n; i++) {
			queue<int> Q; Q.push(i);
			while (!Q.empty()) {
				int x = Q.front(); Q.pop();
				if (reachable[i][x])
					continue;
				reachable[i][x] = true;
				for (auto [v, w] : graph[x])
					Q.push(v);
			}
		}
		vector<int> dist(n, 1000000000);
		dist[s] = 0;
		for (int i = 0; i < n-1; i++)
			for (int j = 0; j < n; j++)
				for (auto [v, w] : graph[j])
					dist[v] = min(dist[v], dist[j]+w);
		set<int> bad;
		for (int j = 0; j < n; j++)
			for (auto[v, w] : graph[j])
				if (dist[v] > dist[j]+w)
					bad.insert(j);
		while (q--) {
			int x; cin >> x;
			if (!reachable[s][x]) {
				printf("Impossible\n");
				continue;
			}
			bool inf = false;
			for (int b : bad)
				inf |= reachable[s][b] && reachable[b][x];
			if (inf)
				printf("-Infinity\n");
			else
				printf("%d\n", dist[x]);
		}
		printf("\n");
	}
}
