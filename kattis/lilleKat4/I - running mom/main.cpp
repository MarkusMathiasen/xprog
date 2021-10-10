#include <bits/stdc++.h>

using namespace std;

map<string, int> m;
int n;
vector<vector<int>> graph(1, vector<int>());
vector<int> vis;

bool cycle(int v) {
	if (vis[v] == 1)
		return true;
	if (vis[v] == 2)
		return false;
	vis[v] = 1;
	for (int u : graph[v])
		if (cycle(u))
			return true;
	vis[v] = 2;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int count = 1;
	for (int i = 0; i < n; i++) {
		string a, b; cin >> a >> b;
		if (!m[a])
			m[a] = count++, graph.push_back(vector<int>());
		if (!m[b])
			m[b] = count++, graph.push_back(vector<int>());
		graph[m[a]].push_back(m[b]);
	}
	string city;
	while (cin >> city) {
		vis.assign(count, 0);
		cout << city << " " << (cycle(m[city]) ? "safe\n" : "trapped\n");
	}
}
