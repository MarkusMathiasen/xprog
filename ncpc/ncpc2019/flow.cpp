#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> flow, p;
vector<vector<int>> kids;

int main() {
	scanf("%d", &n);
	p.assign(n, 0);
	for (int i = 1; i < n; i++)
		scanf("%d", &p[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &flow[i]);
	queue<int> q;
	for (int i = 0; i < n; i++)
		q.push(i);
	
	kids.assign(n, vector<int>());
	for (int i = 0; i < p.size(); i++)
		kids[p[i]].push_back(i);
	
	bool possible = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		int uk = -1;
		int kidsum = 0;
		for (int k : kids[v]) {
			kidsum += flow[k];
			if (flow[k] == 0)
				if (uk == -1)
					uk = k;
				else
					uk = -2;
		}
		if (uk == -2) continue;
		if (uk == -1) {
			if (flow[v] == 0) {
				flow[v] = kidsum;
				if (flow[p[v]] == 0)
					q.push(p[v]);
			}
			else if (flow[v] != kidsum)
				possible = false;
		}
		else {
			if (flow[v] != 0)
				q.push(uk);
		}
	}
	for (int i : flow)
		if (i == 0)
			possible = false;

	if (!possible)
		printf("impossible\n");
	else
		for (int i : flow)
			printf("%d\n", i);
}
