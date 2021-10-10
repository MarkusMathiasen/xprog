#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<int> tea, top;
vector<vector<int>> comb;

int main() {
	scanf("%d", &n);
	tea.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &tea[i]);
	scanf("%d", &m);
	top.assign(m, 0);
	for (int i = 0; i < m; i++)
		scanf("%d ", &top[i]);
	comb.assign(n, vector<int>());
	for (int i = 0; i < n; i++) {
		int j, d;
		scanf("%d", &j);
		while (j--) {
			scanf("%d", &d);
			comb[i].push_back(d-1);
		}
	}
	int res = 1e9;
	for (int i = 0; i < n; i++) {
		int att = 1e9;
		for (int to : comb[i])
			att = min(att, tea[i]+top[to]);
		res = min(res, att);
	}
	scanf("%d", &k);
	printf("%d\n", max(0, k/res-1));
}
