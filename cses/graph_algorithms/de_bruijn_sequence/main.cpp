#include <bits/stdc++.h>

using namespace std;

int n, nodes = 1;
vector<vector<int>> graph;
list<int> S;

void find(list<int>::iterator it, int pos){
	while (graph[pos].size()){
		int nxt = graph[pos][0];
		graph[pos].erase(graph[pos].begin());
		find(S.insert(it, nxt), nxt);
	}
}

int main(){
	scanf("%d", &n);
	if (n == 1){
		printf("10\n");
		return 0;
	}
	for (int i = 1; i < n; i++)
		nodes *= 2;
	graph.assign(nodes, vector<int>());
	for (int i = 0; i < nodes; i++){
		int nxt = (i << 1);
		nxt &= ~(1 << (n-1));
		graph[i].push_back(nxt);
		graph[i].push_back(nxt+1);
	}
	find(S.insert(S.begin(), 0), 0);
	for (int i = n-3; i >= 0; i--)
		printf("%d", !(!(*(--S.end()) & (1 << i))));
	for (list<int>::reverse_iterator it = S.rbegin(); it != S.rend(); it++)
		printf("%d", *it & 1);
	printf("\n");
}
