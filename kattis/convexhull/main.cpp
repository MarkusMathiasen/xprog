#include <bits/stdc++.h>

using namespace std;
#define ii pair<int ,int>

int n;
vector<ii> cord;
vector<int> upper, lower;

void dfs(int at, bool up){
	if (at == 
	if (upper.s
}

int main(){
	scanf("%d", &n);
	while (n){
		cord.assign(n, ii());
		for (int i = 0; i < n; i++)
			scanf("%d %d", &cord[i].first, &cord[i].second);
		sort(cord.begin(), cord.end());
		upper.push_back(0);
		lower.push_back(0);
		dfs(1, true);
	}
}
