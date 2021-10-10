#include <bits/stdc++.h>

using namespace std;

int n, w;
vector<int> p, of, curr, toR;
vector<vector<int>> kids;

int main() {
	scanf("%d %d", &n, &w);
	p.assign(n+1, 0);
	of.assign(n+1, 0);
	curr.assign(n+1, 0);
	kids.assign(n+1, vector<int>());
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &p[i], &of[i], &curr[i]);
		kids[p[i]].push_back(i);
	}
	toR.assign(n+1, 0);
	toR[0] = w;
	queue<int> Q;
	for (int i = 0; i < kids[0].size(); i++)
		Q.push(kids[0][i]);
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		int diff = of[v] - curr[v];
		if (toR[p[v]] <= of[v])
			toR[v] = diff;
		else
			toR[v] = diff + (toR[p[v]] - of[v]);
		for (int i = 0; i < kids[v].size(); i++)
			Q.push(kids[v][i]);
	}
	int res = (int)2e9;
	for (int i = 0; i < n+1; i++)
		res = min(res, toR[i]);
	cout << res << endl;
}
