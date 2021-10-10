#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>
#define ll long long

int n, m, mod = 1e9+7;
vector<vector<int>> graph;
int dp[20][1048576];
int its = 0;

int main(){
	scanf("%d %d", &n, &m);
	graph.assign(n, vector<int>());
	while (m--){
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		graph[a].push_back(b);
	}
	dp[0][1] = 1;
	int visAll = 0;
	for (int i = 0; i < n; i++)
		visAll += (1 << i);
	for (int vis = 1; vis <= visAll; vis++)
		for (int pos = 0; pos < n; pos++){
			if (dp[pos][vis] == 0) continue;
			if ((vis & (1 << pos)) == 0) continue;
			for (int i = 0; i < (int)graph[pos].size(); i++){
				if (vis & (1 << graph[pos][i])) continue;
				int nxt = graph[pos][i];
				int nvis = vis | (1 << nxt);
				dp[nxt][nvis] += dp[pos][vis];
				if (dp[nxt][nvis] >= mod) dp[nxt][nvis] -= mod;
			}
		}
	printf("%d\n", dp[n-1][visAll]);
}
