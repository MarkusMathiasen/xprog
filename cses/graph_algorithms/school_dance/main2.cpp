#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<int> graph[501];
int seen[501], partner[501];

int findPart(int p){
	seen[p] = true;
	for (int i : graph[p]){
		if (!partner[i] || (!seen[partner[i]] && findPart(partner[i]))){
			partner[i] = p;
			return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++){
		int a, b; scanf("%d %d", &a, &b);
		graph[a].push_back(b);
	}
	int count = 0;
	for (int i = 1; i <= n; i++){
		memset(seen, 0, sizeof seen);
		count += findPart(i);
	}
	printf("%d\n", count);
	for (int i = 1; i <= 500; i++)
		if (partner[i])
			printf("%d %d\n", partner[i], i);
}
