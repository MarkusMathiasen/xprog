#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> tree[200000];
int subSize[200000];

int dfs(int pos){
	int result = 0;
	for (int i = 0; i < (int)tree[pos].size(); i++)
		result += dfs(tree[pos][i]);
	subSize[pos] = result;
	return result+1;
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i < n; i++){
		int boss; scanf("%d", &boss); boss--;
		tree[boss].push_back(i);
	}
	dfs(0);
	for (int i = 0; i < n; i++)
		printf("%d ", subSize[i]);
	printf("\n");
}
