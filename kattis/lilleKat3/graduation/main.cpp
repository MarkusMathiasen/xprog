#include <bits/stdc++.h>

using namespace std;

int N, M, k;
map<char, vector<int>> m;
vector<vector<int>> graph;
vector<int> vis;

void dfs(int v) {
	if (vis[v])
		return;
	vis[v] = 1;
	for (int next : graph[v])
		dfs(next);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> k;
	for (int i = 0; i < N; i++) {
		string row; cin >> row;
		for (int j = 0; j < M; j++)
			m[row[j]].push_back(j);
	}
	graph.assign(M, vector<int>(0, 0));
	for (auto l2 : m) {
		vector<int> l = l2.second;
		for (int i = 1; i < (int)l.size(); i++)
			graph[l[i-1]].push_back(l[i]);
	}
	int res = 0;
	vis.assign(M, 0);
	for (int i = 0; i < M; i++) {
		if (vis[i])
			continue;
		res++;
		dfs(i);
	}
	cout << res << endl;
}
