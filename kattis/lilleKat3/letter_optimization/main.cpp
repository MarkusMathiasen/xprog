#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int N;
vector<vector<ii>> graph;
vector<double> M;
vector<int> topo;
vector<bool> vis;
vector<double> work;

void dfs(int v) {
	if (vis[v])
		return;
	vis[v] = 1;
	for (auto u : graph[v])
		dfs(u.first);
	topo.push_back(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	graph.assign(N, vector<ii>(0, ii(0, 0)));
	M.assign(N, 0);
	for (int i = 0; i < N; i++) {
		int k;
		cin >> M[i] >> k;
		for (int j = 0; j < k; j++) {
			int b, w; cin >> b >> w; b--;
			graph[i].push_back(ii(b, w));
		}
	}
	vis.assign(N, 0);
	for (int i = 0; i < N; i++)
		dfs(i);
	work.assign(N, 0);
	vector<bool> recieved(N, false);
	for (int i = N-1; i >= 0; i--) {
		int v = topo[i];
		if (!recieved[v])
			work[v] = M[v];
		work[v] = min(work[v], M[v]);
		for (auto u : graph[v]) {
			work[u.first] += work[v]*u.second/100;
			recieved[u.first] = true;
		}
	}
	for (int i = 0; i < N; i++)
		if (work[i] + 1e-4 >= M[i] && work[i] - 1e-4 <= M[i])
			printf("%d ", i+1);
	printf("\n");
}
