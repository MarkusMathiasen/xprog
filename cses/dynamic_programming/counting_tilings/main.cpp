#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, m;
int mod = (int)1e9+7;
int dp[1000][(1<<10)];

bool isValid(int state, int prev) {
	bool was0 = false;
	for (int i = 0; i < n; i++) {
		bool c = state&(1 << i);
		bool p = prev&(1 << i);
		if (p) {
			if (was0)
				return false;
		}
		else if (was0) {
			if (c)
				return false;
			was0 = false;
		}
		else
			was0 = !c;
	}
	return !was0;
}

ll count(int row, int prev) {
	if (dp[row][prev] != -1)
		return dp[row][prev];
	if (row == m-1)
		return dp[row][prev] = isValid(0, prev);
	ll res = 0;
	for (int i = 0; i < (1 << n); i++) {
		if (prev&i)
			continue;
		if (isValid(i, prev)) {
			res += count(row+1, i);
		}
	}
	return dp[row][prev] = res % mod;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 1<<n; j++)
			dp[i][j] = -1;
	cout << count(0, 0) << endl;
}
