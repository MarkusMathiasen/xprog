#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int n, m, d;
vector<vector<ii>> graph;
vector<int> pre;

int pos(int x) {
	pre.assign(n, -1);
	pre[0] = -2;
	queue<ii> Q;
	Q.emplace(0, 0);
	while (!Q.empty()) {
		int v = Q.front().first;
		int s = Q.front().second;
		Q.pop();
		if (v == n-1)
			return s;
		if (s == d)
			continue;
		for (ii u : graph[v])
			if (u.second <= x && pre[u.first] == -1) {
				Q.emplace(u.first, s+1);
				pre[u.first] = v;
			}
	}
	return -1;
}
void print(int v) {
	if (v != 0)
		print(pre[v]);
	printf("%d ", v+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d %d", &n, &m, &d);
	graph.assign(n, vector<ii>(0, ii(0, 0)));
	while (m--) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c); a--; b--;
		graph[a].push_back(ii(b, c));
	}
	int low = 0;
	int high = 1e9;
	while (low < high) {
		int mid = (low + high) / 2;
		if (pos(mid) != -1)
			high = mid;
		else
			low = mid+1;
	}
	int res = pos(low);
	if (res != -1) {
		printf("%d\n", res);
		print(n-1);
		printf("\n");
	}
	else
		printf("-1\n");
}
