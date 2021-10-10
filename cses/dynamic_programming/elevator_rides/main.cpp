#include <bits/stdc++.h>

using namespace std;
#define ii pair<int, int>

int n, x;
vector<ii> dp; // first is number of rides, and second is minimum weight on last ride
vector<int> w;

int main() {
	cin >> n >> x;
	w.assign(n, 0);
	for (int i = 0; i < n; i++)
		scanf(" %d", &w[i]);
	dp.assign((1<<n), ii(1, 0));
	
	for (int state = 1; state < (1<<n); state++) {
		dp[state] = ii(n+1, 0);
		for (int p = 0; p < n; p++) {
			if (state&(1<<p)) {
				ii prev = dp[state^(1<<p)];
				if (prev.second+w[p] <= x)
					prev.second += w[p];
				else {
					prev.first++;
					prev.second = w[p];
				}
				dp[state] = min(dp[state], prev);
			}
		}
	}
	cout << dp[(1<<n)-1].first << endl;
}
