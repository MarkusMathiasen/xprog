#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> graph[200000];
int tel[200000];
int in[200000];
vector<int> res;

void path(int v) {
	tel[v]++;
	while (tel[v] < (int)graph[v].size()) {
		path(graph[v][tel[v]]);
		tel[v]++;
	}
	res.push_back(v);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		tel[i] = -1, in[i] = 0;
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		graph[a].push_back(b);
		in[b]++;
	}
	bool possible = (in[0]+1 == (int)graph[0].size() && in[n-1]-1 == (int)graph[n-1].size());
	for (int i = 1; i < n-1; i++)
		if (in[i] != (int)graph[i].size())
			possible = false;
	if (!possible) {
		printf("IMPOSSIBLE\n");
		return 0;
	}
	path(0);
	if ((int)res.size() < m) {
		printf("IMPOSSIBLE\n");
		return 0;
	}
	for (int i = (int)res.size()-1; i >= 0; i--)
		printf("%d ", res[i]+1);
	printf("\n");
}
