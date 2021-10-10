#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
int n, m;
int dp[100000];
int mod = (int) 1e9+7;

int ways(int v){
	if (dp[v]) return dp[v];
	int result = 0;
	for (int i = 0; i < graph[v].size(); i++){
		result += ways(graph[v][i]);
		if (result >= mod) result -= mod;
	}
	return dp[v] = result;
}

int main(){
	scanf("%d %d", &n, &m);
	graph.assign(n, vector<int>());
	while (m--){
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		graph[b].push_back(a);
	}
	dp[0] = 1;
	printf("%d\n", ways(n-1));
}
