#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int n, m;
vector<int> p;
vector<vector<ii>> graph;
int c, s, e;
vector<vector<int>> dp;

int main() {
	scanf("%d%d", &n, &m);
	p.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	graph.assign(n, vector<ii>());
	while (m--) {
		int u, v, d; scanf("%d%d%d", &u, &v, &d);
		graph[u].push_back(ii(v, d));
		graph[v].push_back(ii(u, d));
	}
	int q; scanf("%d", &q);
	while (q--) {
		scanf("%d%d%d", &c, &s, &e);
		dp.assign(n, vector<int>(c+1, -1));
		priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
		pq.push({0, s, 0});
		while (!pq.empty()) {
			auto& item = pq.top();
			int r = item[0];
			int v = item[1];
			int f = item[2];
			pq.pop();
			if (dp[v][f] != -1)
				continue;
			dp[v][f] = r;
			if (f < c && dp[v][f+1] == -1)
				pq.push({r+p[v], v, f+1});
			for (auto& [w,d] : graph[v])
				if (d <= f && dp[w][f-d] == -1)
					pq.push({r, w, f-d});
		}
		if (dp[e][0] != -1)
			printf("%d\n", dp[e][0]);
		else
			printf("impossible\n");
	}
}
