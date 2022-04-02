#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> times;
vector<vector<ll>> dp(9, vector<ll>(257, -1));

ll smart(int t, int d) {
	if (d == 0)
		return 1;
	if (dp[t][d] != -1)
		return dp[t][d];
	if (t == 0)
		return dp[t][d] = smart(6, d-1) + smart(8, d-1);
	else
		return dp[t][d] = smart(t-1, d-1);
}

int main() {
	int x;
	while (scanf("%d,", &x) != EOF)
		times.push_back(x);
	long long res = 0;
	for (int x : times)
		res += smart(x, 256);
	printf("%lld\n", res);
}
