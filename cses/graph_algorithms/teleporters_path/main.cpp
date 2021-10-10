#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int n, m;
vector<vector<ii>> graph;
list<int> S;
int ingoing[100000];

void et(list<int>::iterator it, int pos){
	for (int i = 0; i < (int)graph[pos].size(); i++){
		if (graph[pos][i].second) continue;
		int nxt = graph[pos][i].first;
		graph[pos][i].second = 1;
		et(S.insert(it, nxt), nxt);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	graph.assign(n, vector<ii>());
	for (int i = 0; i < m; i++){
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		graph[a].push_back(ii(b, 0));
		ingoing[b]++;
	}
	bool possible = true;
	if ((int)graph[0].size() - ingoing[0] != 1) possible = false;
	if ((int)graph[n-1].size() - ingoing[n-1] != -1) possible = false;
	for (int i = 1; i < n-1; i++)
		if (graph[i].size() - ingoing[i] != 0)
			possible = false;
	et(S.insert(S.begin(), 0), 0);
	if ((int)S.size() < m+1) possible = false;
	if (!possible){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	for (list<int>::reverse_iterator it = S.rbegin(); it != S.rend(); it++)
		printf("%d ", *it+1);
	printf("\n");
}
