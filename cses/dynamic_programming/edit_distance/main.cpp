#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s1, s2; cin >> s1 >> s2;
	int n = s1.size(), m = s2.size();
	for (int i = 0; i <= 5000; i++)
		dp[0][i] = dp[i][0] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			dp[i][j] = min(
				dp[i-1][j-1] + (s1[i-1] != s2[j-1]),
				min(dp[i-1][j] + 1,
				dp[i][j-1] + 1)
			);
		}
	printf("%d\n", dp[n][m]);
}
