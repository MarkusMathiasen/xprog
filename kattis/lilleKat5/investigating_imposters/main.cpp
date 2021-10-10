#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> graph; // who clears me?

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	graph.assign(n, vector<int>());
	for (int i = 0; i < n; i++) {
		int l; cin >> l;
		while (l--) {
			int x; cin >> x; x--;
			graph[x].push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		int impCount = 0;
		queue<int> Q;
		Q.push(i);
		vector<bool> vis(n, false);
		while (!Q.empty()) {
			int v = Q.front(); Q.pop();
			if (vis[v])
				continue;
			vis[v] = true;
			impCount++;
			for (int u : graph[v])
				Q.push(u);
		}
		cout << (impCount > k) << endl;
	}
}
