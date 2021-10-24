#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		vector<set<ii>> graph(n, set<ii>());
		for (int i = 0; i < m; i++) {
			int a, b, c; scanf("%d%d%d", &a, &b, &c); a--; b--;
			graph[a].insert(ii(b, c));
			graph[b].insert(ii(a, c));
		}
		vector<bool> skip(n, 0);
		for (int i = 0; i < n; i++) {
			if ((int)graph[i].size() == 2) {
				skip[i] = 1;
				auto it = graph[i].begin();
				ii a = *it;
				it++;
				ii b = *it;
				graph[a.first].erase(ii(i, a.second));
				graph[b.first].erase(ii(i, b.second));
				graph[a.first].insert(ii(b.first, a.second+b.second));
				graph[b.first].insert(ii(a.first, a.second+b.second));
				m--;
			}
		}
		printf("%d\n", m);
		for (int i = 0; i < n; i++)
			if (!skip[i])
				for (auto [v,w] : graph[i])
					if (v >= i)
						printf("%d %d %d\n", i+1, v+1, w);
		printf("\n");
	}
}
