#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> n;
int result = 0;
int dp[200][200];
int oddCount[201];

int main(){
	scanf("%d", &N);
	n.assign(N*2, 0);
	for (int i = 0; i < N; i++)
		scanf("%d", &n[i]);
	for (int i = 0; i < N; i++)
		n[N+i] = n[i];
	for (int i = 1; i < 301; i++)
		oddCount[i] = oddCount[i-1] + (n[i] % 2 == 1) ? 1 : 0;
	for (int i = 0; i < 3*N; i++)
		dp[i][i] = n[i] % 2 == 1;
	for (int b = 1; b < N; b++){
		for (int l = 0; l < N; l++){
			int r = l+b;
			int odds = oddCount[r+1] - oddCount[l];
			int other = min(dp[l][r-1], dp[l+1][r]);
			dp[l][r] = odds - other;
		}
	}
	int oddTotal = oddCount[N];
	for (int i = 0; i < N; i++){
		int l = i; int r = i+N-1;
		if (dp[l][r] * 2 > oddTotal) result++;
	}
	
	
	
	printf("%d\n", result);
}
