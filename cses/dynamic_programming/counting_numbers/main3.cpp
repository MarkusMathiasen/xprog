#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll a, b;
vector<vector<ll>> dp;

ll wierd(ll x) {
	x++;
	vector<int> num;
	while (x > 0) {
		num.push_back(x%10);
		x /= 10;
	}
	ll res = 0;
	for (int i = (int)num.size()-1; i >= 0; i--) {
		int c = num[i];
		for (int j = 0; j < c; j++) {
			if (i == num.size()-1 || j != num[i+1])
				res += dp[j][i];
		}
		if (i < (int)num.size()-1 && num[i] == num[i+1])
			break;
	}
	for (int i = 0; i < (int)num.size()-1; i++)
			res += dp[0][i];
	return res;
}

int main() {
	dp.assign(11, vector<ll>(19, 0));
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 11; j++) {
			if (i == 0) {
				if (j == 10)
					dp[j][i] = 0;
				else
					dp[j][i] = 1;
				continue;
			}
			for (int k = 1; k < 10; k++)
				if (k != j)
					dp[j][i] += dp[k][i-1];
			if (j == 10)
				dp[j][i] += dp[10][i-1];
			else if (j != 0)
				dp[j][i] += dp[0][i-1];
		}
	}
	cin >> a >> b;
	cout << wierd(b) - wierd(a-1) << endl;
}
