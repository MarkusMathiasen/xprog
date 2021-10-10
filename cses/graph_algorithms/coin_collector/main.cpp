#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, m;
vector<vector<int>> graph, trans, bigG;
int scc[100000], vis[100000];
ll sccSize[100001], roomSize[100000];
vector<int> S;
int sccCount = -1;
ll dp[100000];

ll calc_dp(int pos){
	if (dp[pos]) return dp[pos];
	ll result = 0;
	for (int i = 0; i < bigG[pos].size(); i++)
		result = max(result, calc_dp(bigG[pos][i]));
	return dp[pos] = result + sccSize[pos];
}

void dfs(int v){
	if (vis[v]) return;
	vis[v] = true;
	for (int i = 0; i < graph[v].size(); i++)
		dfs(graph[v][i]);
	S.push_back(v);
}

int main(){
	scanf("%d %d", &n, &m);
	graph.assign(n, vector<int>());
	trans.assign(n, vector<int>());
	for (int i = 0; i < n; i++)
		scanf("%lld", &roomSize[i]);
	while (m--){
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		graph[a].push_back(b);
		trans[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		dfs(i);
	for (int i = 0; i < n; i++)
		scc[i] = -1;
	for (int i = n-1; i >= 0; i--){
		int v = S[i];
		if (scc[v] != -1) continue;
		sccCount++;
		bigG.push_back(vector<int>());
		queue<int> Q; Q.push(v);
		while (!Q.empty()){
			int pos = Q.front(); Q.pop();
			if (scc[pos] == sccCount) continue;
			if (scc[pos] != -1) {bigG[scc[pos]].push_back(sccCount); continue;}
			scc[pos] = sccCount;
			sccSize[sccCount] += roomSize[pos];
			for (int j = 0; j < trans[pos].size(); j++)
				Q.push(trans[pos][j]);
		}
	}
	ll res = 0;
	for (int i = 0; i < bigG.size(); i++)
		res = max(res, calc_dp(i));
	printf("%lld\n", res);
}
