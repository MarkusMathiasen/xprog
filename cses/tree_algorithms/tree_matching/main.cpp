#include <bits/stdc++.h>

using namespace std;

int n, result = 0;
vector<int> tree[200000];
int seen[200000], taken[200000];

void match(int p){
	if (taken[p]) return;
	if (taken[tree[p][0]]) return;
	result++;

}

void dfs(int p){
	seen[p] = true;
	for (int i : tree[p])
		if (!seen[i])
			dfs(i);
	if (taken[p]) return;
	for (int i : tree[p]){
		if (taken[i]) continue;
		taken[i] = true; taken[p] = true;
		result++;
		break;
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i < n; i++){
		int a, b; scanf("%d %d", &a, &b); a--; b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1);
	printf("%d\n", result);
}
