#include <bits/stdc++.h>

using namespace std;

map<string, int> m1;
map<int, string> m2;
int n;
vector<vector<int>> graph;
vector<bool> vis;
vector<string> res;

void dfs(int v) {
	if (vis[v])
		return;
	vis[v] = 1;
	for (int u : graph[v])
		dfs(u);
	res.push_back(m2[v]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cin >> n;
	graph.assign(n+1, vector<int>());
	int count = 1;
	for (int i = 0; i < n; i++) {
		string w; cin >> w; w.pop_back();
		if (!m1[w]) {
			m1[w] = count;
			m2[count++] = w;
		}
		string line; getline(cin, line);
		stringstream ss(line);
		string word;
		while (ss >> word) {
			if (!m1[word]) {
				m1[word] = count;
				m2[count++] = word;
			}
			graph[m1[word]].push_back(m1[w]);
		}
	}
	vis.assign(n+1, false);
	string r; cin >> r; dfs(m1[r]);
	for_each(res.rbegin(), res.rend(), [](string s) {cout << s << "\n";});
}
