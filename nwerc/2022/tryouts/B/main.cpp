#include <bits/stdc++.h>
using namespace std;

bool dp[101][101];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			for (int k = 1; k < i; k++)
				if (!dp[k][j] && !dp[i-k][j])
					dp[i][j] = true;
			for (int k = 1; k < j; k++)
				if (!dp[i][k] && !dp[i][j-k])
					dp[i][j] = true;
		}
	}
	printf("%s\n", dp[n][m] ? "A" : "B");
}
