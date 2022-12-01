#include <bits/stdc++.h>
using namespace std;

void topo_sort(int v, vector<vector<int>>& graph, vector<bool>& vis, vector<int>& res) {
	if (vis[v])
		return;
	vis[v] = true;
	for (int u : graph[v])
		topo_sort(u, graph, vis, res);
	res.push_back(v);
}

set<int> dist_set(vector<vector<int>>& graph) {
	int n = graph.size();
	vector<bool> vis(n, false);
	vector<int> topo;
	topo_sort(0, graph, vis, topo);
	vector<set<int>> steps(n, set<int>());
	steps[0].insert(0);
	reverse(topo.begin(), topo.end());
	for (int v : topo)
		for (int u : graph[v])
			for (int l : steps[v])
				steps[u].insert(l+1);
	return steps[n-1];
}

int main() {
	int n1, n2, m1, m2; scanf("%d%d%d%d", &n1, &n2, &m1, &m2);
	vector<vector<int>> g1(n1, vector<int>()), g2(n2, vector<int>());
	for (int i = 0; i < m1; i++) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		g1[a].push_back(b);
	}
	for (int i = 0; i < m2; i++) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		g2[a].push_back(b);
	}
	set<int> s1 = dist_set(g1);
	set<int> s2 = dist_set(g2);
	int q; scanf("%d", &q);
	while (q--) {
		bool possible = false;
		int s; scanf("%d", &s);
		set<int>::iterator i1 = s1.begin();
		set<int>::reverse_iterator i2 = s2.rbegin();
		while (!possible && i1 != s1.end() && i2 != s2.rend()) {
			if ((*i1) + (*i2) == s)
				possible = true;
			else if ((*i1) + (*i2) > s)
				i2++;
			else if ((*i1) + (*i2) < s)
				i1++;
			else
				return 0;
		}
		printf("%s\n", possible ? "Yes" : "No");
	}
}
