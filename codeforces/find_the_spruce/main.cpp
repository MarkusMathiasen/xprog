#include <bits/stdc++.h>

using namespace std;

int T, n, m;

int main() {
	cin >> T;
	while (T--) {
		cin >> n >> m;
		string table[n];
		for (int i = n-1; i >= 0; i--)
			cin >> table[i];

		int dp[n][m];
		int res = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (table[i][j] == '*') {
					if (j == 0 || j == m-1 || i == 0)
						dp[i][j] = 1;
					else
						dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
					res += dp[i][j];
				}
				else
					dp[i][j] = 0;
			}
		cout << res << endl;
	}
}
