#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
#define iti pair<list<int>::iterator, int>
#define vi vector<int>

int vis[100000];
int n, m;
vector<vector<vector<int>>> graph;
list<int> S;

int main(){
	scanf("%d %d", &n, &m);
	graph.assign(n, vector<vector<int>>());
	for (int i = 0; i < m; i++){
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		graph[a].push_back({b, 1, (int)graph[b].size()});
		graph[b].push_back({a, 1, (int)graph[a].size()-1});
	}
	bool possible = true;
	for (int i = 0; i < n; i++)
		if (graph[i].size() % 2 != 0)
			possible = false;
	stack<iti> s;
	s.push(iti(S.insert(S.begin(), 0), 0));
	while (!s.empty()){
		int pos = s.top().second;
		list<int>::iterator it = s.top().first;
		if (vis[pos] == (int)graph[pos].size()) s.pop();
		for (; vis[pos] < (int)graph[pos].size(); vis[pos]++){
			if (!graph[pos][vis[pos]][1]) continue;
			graph[pos][vis[pos]][1] = 0;
			int to = graph[pos][vis[pos]][0];
			graph[to][graph[pos][vis[pos]][2]][1] = 0;
			s.push(iti(S.insert(it, to), to));
			vis[pos]++; break;
		}
	}
	if (!possible || (int)S.size() < m+1){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	for (list<int>::iterator i = S.begin(); i != S.end(); i++)
		printf("%d ", *i+1);
	printf("\n");
}
