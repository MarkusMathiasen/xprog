#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> m;
int dp[1000001];

int main(){
	dp[1] = 1;
	while(scanf("%d", &n) != EOF){
		int M; scanf("%d", &M);
		m.assign(M, 0);
		for (int i = 0; i < M; i++)
			scanf("%d", &m[i]);
		for (int i = 2; i <= n; i++){
			bool win = false;
			for (int j = 0; j < M; j++){
				if (m[j] > i) continue;
				if (dp[i-m[j]] == 0) win = true;
			}
			dp[i] = win;
		}
		if (dp[n]) 	printf("Stan wins\n");
		else 		printf("Ollie wins\n");
	}
}
