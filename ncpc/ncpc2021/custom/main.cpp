#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	vector<int> W(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &W[i]);
	vector<vector<int>> graph(n, vector<int>());
	bool edge = false;
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d%d", &a, &b); a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
		if ((a == 0 && b == n-1) || (a == n-1 && b == 0))
			edge = true;
	}
	if (edge) {
		if (n == 2 && k == 1)
			printf("impossible\n");
		else if (k == 0) {
			for (int i = 0; i < n; i++)
				printf("S");
			printf("\n");
		}
		else {
			for (int i = 0; i < k-1; i++)
				printf("N");
			for (int i = 0; i < n-k; i++)
				printf("S");
			printf("N\n");
		}
		return 0;
	}
	vector<int> startEdges;
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
	pq.push({W[0], 0, 0});
	vector<int> dist(n, -1);
	while (!pq.empty()) {
		int d = pq.top()[0];
		int v = pq.top()[1];
		int prev = pq.top()[2];
		pq.pop();
		if (dist[v] == -1) {
			dist[v] = d;
			for (int nxt : graph[v])
				pq.push({d+W[nxt], nxt, v});
		}
		if (dist[v] < d)
			continue;
		if (prev == 0)
			startEdges.push_back(v);
	}
	vector<char> post(n, 'x');
	for (int x : startEdges) {
		if (!k)
			break;
		k--;
		post[x] = 'N';
	}
	for (int i = 0; i < n; i++) {
		if (post[i] != 'x') {
			assert(post[i] == 'N');
			continue;
		}
		if (k) {
			k--;
			post[i] = 'N';
		}
		else
			post[i] = 'S';
	}
	for (char c : post)
		printf("%c", c);
	printf("\n");
}
