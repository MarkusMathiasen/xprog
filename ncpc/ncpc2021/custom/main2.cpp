#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<char> res;

struct que {
	int v;
	int prev;
	int d;
	que(int v, int prev, int d) : v(v), prev(prev), d(d) {}
	bool operator > (const que& a) const {
		return d > a.d;
	}
};

void color() {
	for (int i = 0; i < n; i++)
		if (res[i] != 'x')
			continue;
		else if (k)
			k--, res[i] = 'N';
		else
			res[i] = 'S';
}
void printRes() {
	for (char c : res)
		printf("%c", c);
	printf("\n");
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	res.assign(n, 'x');
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
	if (n == 2 && k == 1) {
		printf("impossible\n");
		return 0;
	}
	else if (edge) {
		if (k >= 2)
			k -= 2, res[0] = res[n-1] = 'N';
		else
			res[0] = res[n-1] = 'S';
		color();
		printRes();
		return 0;
	}
	vector<int> toEnd;
	toEnd.push_back(n-1);
	priority_queue<que, vector<que>, greater<que>> Q;
	vector<int> dist(n, -1);
	Q.push(que(0, 0, W[0]));
	while (!Q.empty()) {
		que q = Q.top(); Q.pop();
		if (dist[q.v] == -1) {
			dist[q.v] = q.d;
			for (int nxt : graph[q.v])
				Q.push(que(nxt, q.v, q.d+W[nxt]));
		}
		if (dist[q.v] == q.d && q.v == n-1)
			toEnd.push_back(q.prev);
	}
	for (int i = 0; i < (int)toEnd.size(); i++) {
		if (!k)
			break;
		k--;
		res[toEnd[i]] = 'N';
	}
	color();
	printRes();
}
