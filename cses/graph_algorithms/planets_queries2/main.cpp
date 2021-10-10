#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int n, q;
int go[200000][21];
vector<int> transG[200000];
ii dist[200000];
int vis[200000];
map<ii, int> m;

int gogo(int v, int t) {
	for (int i = 0; i < 21; i++)
		if (t & (1 << i))
			v = go[v][i];
	return v;
}

int calc(int a, int b) {
	if (dist[a].second != dist[b].second)
		return -1;
	int ad = dist[a].first;
	int bd = dist[b].first;
	if (ad >= bd && gogo(a, ad - bd) == b)
		return ad - bd;
	if (m[ii(dist[a].second, b)])
		return m[ii(dist[a].second, b)] + ad;
	return -1;
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &go[i][0]); go[i][0]--;
		transG[go[i][0]].push_back(i);
	}
	for (int k = 1; k < 21; k++)
		for (int i = 0; i < n; i++)
			go[i][k] = go[go[i][k-1]][k-1];
	for (int i = 0; i < n; i++)
		vis[i] = 0;
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		int nxt = i;
		while (!vis[nxt]) {
			vis[nxt] = 1;
			nxt = go[nxt][0];
		}
		queue<ii> Q;
		Q.push(ii(0, nxt));
		while (!Q.empty()) {
			int d = Q.front().first;
			int v = Q.front().second;
			Q.pop();
			if (vis[v] == 2) continue;
			dist[v] = ii(d, nxt);
			vis[v] = 2;
			for (int j = 0; j < (int)transG[v].size(); j++)
				Q.push(ii(d+1, transG[v][j]));
		}
		int x = go[nxt][0];
		for (int j = 1; x != nxt; j++) {
			m[ii(nxt, x)] = j;
			x = go[x][0];
		}
	}
	while (q--) {
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		printf("%d\n", calc(a, b));
	}
}
