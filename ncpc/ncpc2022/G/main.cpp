#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> dp;
vector<double> p;

int main() {
	int k, n; scanf("%d%d", &n, &k);
	p.assign(n+1, 0);
	dp.assign(n+1, vector<double>(2*n+1, -1));
	p[0] = 2;
	for (int i = 1; i <= n; i++)
		scanf("%lf", &p[i]);
	sort(p.rbegin(), p.rend());
	for (int k = -n; k <= 0; k++)
		dp[0][n+k] = 1;
	for (int k = 1; k <= n; k++)
		dp[0][n+k] = 0;
	for (int A = 1; A <= n; A++) {
		for (int k = -n+A; k <= n; k++) {
			dp[A][n+k] = p[A]*dp[A-1][n+k-1] + (k < n ? (1-p[A])*dp[A-1][n+k+1] : 0);
		}
	}
	/*
	for (auto row : dp) {
		for (auto x : row)
			printf("%lf ", x);
		printf("\n");
	}*/
	double res = 0;
	for (int i = 0; i <= n; i++)
		res = max(res, dp[i][n+k]);
	printf("%lf\n", res);
}
