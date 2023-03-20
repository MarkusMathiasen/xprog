#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

vector<vector<ii>> bigG, smallG;
int mat[12][12];
int N, V, E;
vector<vector<int>> dp;

int calc(int u, int mask) {
	if (mask == 0) return mat[u][0];
	int &ans = dp[u][mask];
	if (ans != -1) return ans;
	ans = 2000000000;
	int m = mask;
	while (m) {
		int pow_v = m&(-m);
		int v = __builtin_ctz(pow_v)+1;
		ans = min(ans, mat[u][v] + calc(v, mask-pow_v));
		m -= pow_v;
	}
	return ans;
}

int main() {
	cin >> N >> V >> E;
	bigG.assign(V, vector<ii>(0, ii(0, 0)));
	for (int i = 0; i < E; i++) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		bigG[u].push_back(ii(v, w));
		bigG[v].push_back(ii(u, w));
	}
	smallG.assign(N, vector<ii>(0, ii(0, 0)));
	for (int n = 0; n < N; n++) {
		priority_queue<ii, vector<ii>, greater<ii>> Q;
		Q.push(ii(0, n));
		vector<int> dist(V, -1);
		while (!Q.empty()) {
			int d = Q.top().first;
			int v = Q.top().second;
			Q.pop();
			if (dist[v] != -1)
				continue;
			dist[v] = d;
			for (int i = 0; i < (int)bigG[v].size(); i++) {
				ii e = bigG[v][i];
				Q.push(ii(d+e.second, e.first));
			}
		}
		for (int i = 0; i < N; i++) {
			mat[i][n] = dist[i];
			mat[n][i] = dist[i];
			if (i == n)
				continue;
			smallG[n].push_back(ii(i, dist[i]));
		}
	}
	dp.assign(12, vector<int>((1 << 11), -1));
	int res = calc(0, (1 << (N-1))-1);
	cout << res << endl;
}
