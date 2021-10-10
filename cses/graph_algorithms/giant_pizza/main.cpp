#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>
#define v vector

int n, m;
v<v<v<ii>>> graph;
v<int> onPizza;

bool choose(int pos, int op){
	if (onPizza[pos] == op) return true;
	if (onPizza[pos] != -1) return false;
	onPizza[pos] = op;
	for (int i = 0; i < graph[op][pos].size(); i++){
		int nxt = graph[op][pos][i].first;
		int nxtOp = graph[op][pos][i].second;
		if (!choose(nxt, nxtOp)){
			onPizza[pos] = -1;
			return false;
		}
	}
	return true;
}

int main(){
	scanf("%d %d", &n, &m);
	graph.assign(2, v<v<ii>>(m, v<ii>()));
	onPizza.assign(m, -1);
	while (n--){
		char c, d; int a, b; scanf(" %c %d %c %d", &c, &a, &d, &b); a--; b--;
		int o1 = (c == '+'); int o2 = (d == '+');
		graph[!o1][a].push_back(ii(b, o2));
		graph[!o2][b].push_back(ii(a, o1));
	}
	bool possible = true;
	for (int i = 0; i < m; i++)
		if (!(choose(i, 1) || choose(i, 0)))
			possible = false;
	if (!possible)
		printf("IMPOSSIBLE\n");
	else{
		for (int i = 0; i < m; i++)
			printf("%c ", (onPizza[i] == 1 ? '+' : '-'));
		printf("\n");
	}
}
